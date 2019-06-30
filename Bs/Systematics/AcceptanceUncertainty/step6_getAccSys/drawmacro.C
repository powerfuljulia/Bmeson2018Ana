#include <iostream>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TLegend.h>
#include <TPaveStats.h>
#include <TPad.h>
#include <TStyle.h>
#include <TLine.h>
#include <TROOT.h>
#include <algorithm>    // std::max
using namespace std;

void GetMinMaxMean(TH1D* hs, double& aMean, double& aMin, double& aMax);

const int nBins = 3;
double ptbin[nBins+1] = {7,15,20,50};
double Rat[nBins];
double RatErr[nBins];
const int nBinsy=4;
double ybin[nBinsy+1] = {0.0, 0.5, 1.0, 1.5, 2.4};
double Ratylab[nBinsy];
double RatErrylab[nBinsy];

bool ispp = 0;
string label;

void drawmacro() {

	if(ispp) label = "pp";
	else label = "PbPb";

	//gROOT->Macro("rootlogon.C+");
	gStyle->SetCanvasDefW(800);
	gStyle->SetCanvasDefH(800);
	gStyle->SetOptStat(0);
	TFile *fratio_gaus_ptdep = new TFile(Form("../step3_MCtoy/gaus_try10k_ptvar_%s.root", label.c_str()));
	TFile *fratio_gaus_ydep = new TFile(Form("../step3_MCtoy/gaus_try10k_yvar_%s.root", label.c_str()));
	TFile *inf = new TFile(Form("../step4_SkimBntuple/results_%s.root", label.c_str()));
	TFile* facc_gaus_ptdep=new TFile(Form("../step5_getAccFromtoy/AccVar_ptvar_%s.root", label.c_str()));
	TFile* facc_gaus_ydep=new TFile(Form("../step5_getAccFromtoy/AccVar_yvar_%s.root", label.c_str()));
	TFile* fout=new TFile(Form("AccSys_Bplus_%s.root",label.c_str()),"RECREATE");

	TTree* tr11=(TTree*)fratio_gaus_ptdep->Get("ditTree");
	TTree* tr21=(TTree*)fratio_gaus_ydep->Get("ditTree");

	TH1D* htest11=(TH1D*)fratio_gaus_ptdep->Get("htest");
	TH1D* htest21=(TH1D*)fratio_gaus_ydep->Get("htest");

	double a1_gaus,a2_gaus;
	double ay1_gaus,ay2_gaus;

	tr11->SetBranchAddress("a1", &a1_gaus);
	tr11->SetBranchAddress("a2", &a2_gaus);
	tr21->SetBranchAddress("ay1", &ay1_gaus);
	tr21->SetBranchAddress("ay2", &ay2_gaus);

	TTree *ExclBAna = (TTree*)inf->Get("ExclBAna");
	TH1D *hPtProject = new TH1D(Form("hPtProject"),"",nBins,ptbin);
	TH1D *hPtProjectPass = new TH1D(Form("hPtProjectPass"),"",nBins,ptbin);
	TH1D *hPtProjectAcc = new TH1D(Form("hPtProjectAcc"),"",nBins,ptbin);
	TH1D *hyProject = new TH1D(Form("hyProject"),"",nBinsy,ybin);
	TH1D *hyProjectPass = new TH1D(Form("hyProjectPass"),"",nBinsy,ybin);
	TH1D *hyProjectAcc = new TH1D(Form("hyProjectAcc"),"",nBinsy,ybin);


	TH1D* hf11pt[nBins];
	TH1D* hf21pt[nBins];
	TH1D* hf11y[nBinsy];
	TH1D* hf21y[nBinsy];

	TH1D* hpullf11pt[nBins];
	TH1D* hpullf21pt[nBins];
	TH1D* hpullf11y[nBinsy];
	TH1D* hpullf21y[nBinsy];

	TH1D* ha1gaus=new TH1D("ha1gaus",";[0] ([0]p_{T}+[1]);Entries",200,-0.04,0.06);
	TH1D* ha2gaus=new TH1D("ha2gaus",";[1] ([0]p_{T}+[1]);Entries",260,0.1,1.4);
	TH1D* hay1gaus=new TH1D("hay1gaus",";[0] ([0](y+0.465)^{2}+[1]);Entries",200,-0.15,0.25);
	TH1D* hay2gaus=new TH1D("hay2gaus",";[1] ([0](y+0.465)^{2}+[1]);Entries",250,0.6,1.1);

	ExclBAna->Project("hPtProject", "pt", "weight");
	ExclBAna->Project("hPtProjectPass", "pt", "weight*passAcc");
	ExclBAna->Project("hyProject", "abs(y)", "weight");
	ExclBAna->Project("hyProjectPass", "abs(y)", "weight*passAcc");
	hPtProjectAcc->Divide(hPtProjectPass, hPtProject, 1, 1, "B");
	hyProjectAcc->Divide(hyProjectPass, hyProject, 1, 1, "B");
	double avghpt[nBins];
	double avghy[nBinsy];
	for(int i = 0; i < nBins; i++){
		avghpt[i] = hPtProjectAcc->GetBinContent(i+1);
	}
	for(int i = 0; i < nBinsy; i++){
		avghy[i] = hyProjectAcc->GetBinContent(i+1);
	}
	//double avghpt[5]={0.2458,0.4240,0.5134,0.6468,0.7215};
	//double avghy[5]={0.3395,0.3186,0.2486,0.3189,0.3422};


	for (int i=0;i<nBins;i++) {
		TH1D* res11pt = (TH1D*)facc_gaus_ptdep->Get(Form("hAccCompBin%i",i+1));
		TH1D* res21pt = (TH1D*)facc_gaus_ydep->Get(Form("hAccCompBin%i",i+1));
		hf11pt[i]=(TH1D*)res11pt->Clone(Form("hf11pt_%i",i+1));
		hf21pt[i]=(TH1D*)res21pt->Clone(Form("hf21pt_%i",i+1));

		double avg11=hf11pt[i]->GetMean();
		double sig11=hf11pt[i]->GetRMS(); 
		double avg21=hf21pt[i]->GetMean();
		double sig21=hf21pt[i]->GetRMS(); 

		double avgh=avghpt[i]; 
		std::cout << avg11 << " " << sig11 << std::endl;
		hpullf11pt[i]=new TH1D(Form("hpullf11pt_%i",i+1),Form("Pull distribution in (%.0f#leqp_{T}<%.0f) (GeV/c);pull;Entries",ptbin[i],ptbin[i+1]),1000,((avgh-0.0500-avg11)/sig11),((avgh+0.0500-avg11)/sig11));
		hpullf21pt[i]=new TH1D(Form("hpullf21pt_%i",i+1),Form("Pull distribution in (%.0f#leqp_{T}<%.0f) (GeV/c);pull;Entries",ptbin[i],ptbin[i+1]),1000,((avgh-0.0500-avg21)/sig21),((avgh+0.0500-avg21)/sig21));


		cout << "Pass Here 1 " << endl;

		for (int j=0;j<1000;j++) {
			hpullf11pt[i]->SetBinContent(j+1,hf11pt[i]->GetBinContent(j+1));
			hpullf21pt[i]->SetBinContent(j+1,hf21pt[i]->GetBinContent(j+1));
		}
	}

	for (int i=0;i<nBinsy;i++) {
		TH1D* res11y = (TH1D*)facc_gaus_ptdep->Get(Form("hAccYCompBin%i",i+1));
		TH1D* res21y = (TH1D*)facc_gaus_ydep->Get(Form("hAccYCompBin%i",i+1));
		hf11y[i]=(TH1D*)res11y->Clone(Form("hf11y_%i",i+1));
		hf21y[i]=(TH1D*)res21y->Clone(Form("hf21y_%i",i+1));
		double avg11=hf11y[i]->GetMean();
		double sig11=hf11y[i]->GetRMS(); 
		double avg21=hf21y[i]->GetMean();
		double sig21=hf21y[i]->GetRMS(); 


		cout << "Pass Here 2 " << endl;


		double avgh=avghy[i]; 
		//	std::cout << avg21 << " " << sig21 << std::endl;
		hpullf11y[i]=new TH1D(Form("hpullf11y_%i",i+1),Form("Pull distribution in (%1.3f#leqy_{lab}<%1.3f);pull;Entries",ybin[i],ybin[i+1]),1000,((avgh-0.0500-avg11)/sig11),((avgh+0.0500-avg11)/sig11));
		hpullf21y[i]=new TH1D(Form("hpullf21y_%i",i+1),Form("Pull distribution in (%1.3f#leqy_{lab}<%1.3f);pull;Entries",ybin[i],ybin[i+1]),1000,((avgh-0.0500-avg21)/sig21),((avgh+0.0500-avg21)/sig21));

		cout << "Pass Here 3 " << endl;


		for (int j=0;j<hf11y[i]->GetNbinsX();j++) {
			hpullf11y[i]->SetBinContent(j+1,hf11y[i]->GetBinContent(j+1));
			hpullf21y[i]->SetBinContent(j+1,hf21y[i]->GetBinContent(j+1));
		}
	}

	cout << "Pass 4" << endl;
	//gStyle->SetOptStat(1110);
	TCanvas* c1=new TCanvas("c1","c1",600,600);
	c1->cd();
	for (int i=0;i<nBins;i++){
		cout << "i before crash = " << i << endl; 
		


		double maxuser = hpullf11pt[i]->GetMaximum();
		hpullf11pt[i]->GetYaxis()->SetRangeUser(0.0,1.2*maxuser);
		hpullf11pt[i]->GetXaxis()->SetRangeUser(-10.0,10.0);
		//hpullf11pt[i]->SetAxisRange(-10.0,10.0,"X");


		cout << "pass 1 before crash = " << endl; 


		hpullf11pt[i]->SetLineColor(kRed+2);
		//hpullf12pt[i]->SetLineColor(kOrange+7);
		//		hpullf21pt[i]->SetLineColor(kBlue);
		//hpullf22pt[i]->SetLineColor(kTeal+3);
		hpullf11pt[i]->Draw();

		/*

		gPad->Update();
		TPaveStats* p11 = (TPaveStats*)hpullf11pt[i]->FindObject("stats");
		p11->SetX1NDC(0.70);
		p11->SetY1NDC(0.75);
		p11->SetX2NDC(0.90);
		p11->SetY2NDC(0.90);
		p11->SetTextColor(kRed+2);
		cout << "pass 2 before crash = " << endl; 

		 hpullf12pt[i]->Draw();
		   gPad->Update();
		   TPaveStats* p12 = (TPaveStats*)hpullf12pt[i]->FindObject("stats");
		   p12->SetX1NDC(0.70);
		   p12->SetY1NDC(0.60);
		   p12->SetX2NDC(0.90);
		   p12->SetY2NDC(0.75);
		   p12->SetTextColor(kOrange+7);
		   */
		//		hpullf21pt[i]->Draw();
		//gPad->Update();
		//		TPaveStats* p21 = (TPaveStats*)hpullf21pt[i]->FindObject("stats");
		/*
		   p21->SetX1NDC(0.70);
		   p21->SetY1NDC(0.45);
		   p21->SetX2NDC(0.90);
		   p21->SetY2NDC(0.60);
		   p21->SetTextColor(kBlue);
		   */
		/*
		   hpullf22pt[i]->Draw();
		   gPad->Update();
		   TPaveStats* p22 = (TPaveStats*)hpullf22pt[i]->FindObject("stats");
		   p22->SetX1NDC(0.70);
		   p22->SetY1NDC(0.30);
		   p22->SetX2NDC(0.90);
		   p22->SetY2NDC(0.45);
		   p22->SetTextColor(kTeal+3);
		   */
		//TLegend* leg1 = new TLegend(0.12,0.7,0.4,0.88);
		TLegend* leg1 = new TLegend(0.15,0.80,0.48,0.93);

		cout << "pass 3 before crash = " << endl; 

		leg1->AddEntry(hpullf11pt[i],"p_{T} variation with gaussian","l");
		//		leg1->AddEntry(hpullf21pt[i],"y variation with gaussian","l");
		leg1->SetFillColor(0);
		leg1->SetBorderSize(0);


		hpullf11pt[i]->Draw("");
		//		hpullf21pt[i]->Draw("same");
	//	p11->Draw("same");
		//	p21->Draw("same");
		leg1->Draw("same");
		cout << "pass 4 before crash = " << endl; 


		c1->SaveAs(Form("Bplus_ptdep_%i_%s.pdf",i,label.c_str()));
	}

	cout << "Pass nBins" << endl;
	TCanvas *c = new TCanvas("c","c",600,600);
	c->cd();
	for (int i=0;i<nBinsy;i++){
		cout << "Pass - 1" << endl;	
		//double maxuser = shpullf11y[i]->GetMaximum();
		double maxuser=hpullf11y[i]->GetMaximum();
		hpullf11y[i]->GetYaxis()->SetRangeUser(0.0,1.2*maxuser);
		//hpullf11y[i]->GetYaxis()->SetRangeUser(0.0,5000.0);
		//hpullf11y[i]->GetXaxis()->SetRangeUser(-10.0,10.0);
		hpullf11y[i]->SetAxisRange(-10.0,10.0,"X");
		cout << "Pass 0" << endl;		

		hpullf11y[i]->SetLineColor(kRed+2);
		hpullf21y[i]->SetLineColor(kBlue);
		hpullf11y[i]->Draw();
		/*
		gPad->Update();
		TPaveStats* p11 = (TPaveStats*)hpullf11y[i]->FindObject("stats");
		p11->SetX1NDC(0.70);
		p11->SetY1NDC(0.75);
		p11->SetX2NDC(0.90);
		p11->SetY2NDC(0.90);
		p11->SetTextColor(kRed+2);

		hpullf21y[i]->Draw();
		gPad->Update();
		TPaveStats* p21 = (TPaveStats*)hpullf21y[i]->FindObject("stats");
		p21->SetX1NDC(0.70);
		p21->SetY1NDC(0.45);
		p21->SetX2NDC(0.90);
		p21->SetY2NDC(0.60);
		p21->SetTextColor(kBlue);
		*/
		//TLegend* leg1 = new TLegend(0.12,0.7,0.4,0.88);
		TLegend* leg1 = new TLegend(0.15,0.80,0.48,0.93);

		leg1->AddEntry(hpullf11y[i],"p_{T} variation with gaussian","l");
		leg1->AddEntry(hpullf21y[i],"y variation with gaussian","l");
		leg1->SetFillColor(0);
		leg1->SetBorderSize(0);

		cout << "Pass 1" << endl;

		hpullf11y[i]->Draw("");
		hpullf21y[i]->Draw("same");
	//	p11->Draw("same");
		cout << "Pass 2" << endl;
	//	p21->Draw("same");
		leg1->Draw("same");
		cout << "Pass 3" << endl;
		c->SaveAs(Form("Bplus_ydep_%i_%s.pdf",i,label.c_str()));
		cout << "Pass 4" << endl;
	}

	cout << "Finish Prerequisite" << endl;
	TCanvas *c2 = new TCanvas("c2","c2",600,600);

	for (int i=0;i<nBins;i++){
		printf("pt bins %d\n", i);
		double aMean1, aMin1, aMax1;
		double aMean2, aMin2, aMax2;
		GetMinMaxMean(hf11pt[i], aMean1, aMin1, aMax1);
		GetMinMaxMean(hf21pt[i], aMean2, aMin2, aMax2);
		double unc1 = max(fabs(aMean1-avghpt[i]), max(fabs(aMin1-avghpt[i]), fabs(aMax1-avghpt[i])));
		double unc2 = max(fabs(aMean2-avghpt[i]), max(fabs(aMin2-avghpt[i]), fabs(aMax2-avghpt[i])));
		printf("avg: %f, pt var unc: %f, y var unc: %f, final: %f\n", avghpt[i], unc1, unc2, 100*max(unc1, unc2));

		hf11pt[i]->Scale(1.0/hf11pt[i]->Integral());
		hf21pt[i]->Scale(1.0/hf21pt[i]->Integral());




		double maxuser = std::max(hf11pt[i]->GetMaximum(),hf21pt[i]->GetMaximum());

		/*
		   double maxuser;
		   double maxuser1 = hf11pt[i]->GetMaximum();
		   double maxuser2 = hf21pt[i]->GetMaximum();
		   if(maxuser2 > maxuser1) maxuser = maxuser2;
		   if(maxuser1 > maxuser2) maxuser = maxuser1;
		   */
		hf11pt[i]->GetYaxis()->SetRangeUser(0.0,1.4*maxuser);
		if(i == 0){
		hf11pt[i]->GetXaxis()->SetRangeUser(hf11pt[i]->GetMean()-0.05,hf11pt[i]->GetMean()+0.05);
		hf21pt[i]->GetXaxis()->SetRangeUser(hf11pt[i]->GetMean()-0.05,hf11pt[i]->GetMean()+0.05);
		}
		if(i == 1){
		hf11pt[i]->GetXaxis()->SetRangeUser(0,0.3);
		hf21pt[i]->GetXaxis()->SetRangeUser(0,0.3);
		}
		if(i == 2){
		hf11pt[i]->GetXaxis()->SetRangeUser(0.4,0.65);
		hf21pt[i]->GetXaxis()->SetRangeUser(0.4,0.65);
		}


		hf11pt[i]->SetTitle("Acceptance variation");
		hf11pt[i]->GetXaxis()->SetTitle(Form("Acceptance in %.0f#leqp_{T}<%.0f (GeV/c)",ptbin[i],ptbin[i+1]));

		hf11pt[i]->GetYaxis()->SetTitle("Normalized Entries");
		hf11pt[i]->GetYaxis()->SetTitleOffset(1.4);

		hf11pt[i]->SetLineColor(kRed+2);
		hf21pt[i]->SetLineColor(kBlue);
		hf11pt[i]->Draw();
	
		/*
		gPad->Update();
		TPaveStats* p11 = (TPaveStats*)hf11pt[i]->FindObject("stats");
		p11->SetX1NDC(0.70);
		p11->SetY1NDC(0.75);
		p11->SetX2NDC(0.90);
		p11->SetY2NDC(0.90);
		p11->SetTextColor(kRed+2);

		hf21pt[i]->Draw();
		gPad->Update();
		//	TPaveStats* p21 = (TPaveStats*)hf21pt[i]->FindObject("stats");
		
		   p21->SetX1NDC(0.70);
		   p21->SetY1NDC(0.45);
		   p21->SetX2NDC(0.90);
		   p21->SetY2NDC(0.60);
		   p21->SetTextColor(kBlue);
		   */
		TLegend* leg1 = new TLegend(0.12,0.7,0.4,0.88);
		//		TLegend* leg1 = new TLegend(0.15,0.80,0.48,0.93);

		leg1->AddEntry(hf11pt[i],"p_{T} variation with gaussian","l");
		leg1->AddEntry(hf21pt[i],"y variation with gaussian","l");
		leg1->SetFillColor(0);
		leg1->SetBorderSize(0);

		TLine* ptline = new TLine(avghpt[i],0,avghpt[i],1.2*maxuser);

		hf11pt[i]->Draw("");
		hf21pt[i]->Draw("same");
	//	p11->Draw("same");
		//p21->Draw("same");
		leg1->Draw("same");
		ptline->Draw("same");

		c2->SaveAs(Form("Bplus_accvar_ptdep_%i_%s.pdf",i,label.c_str()));
	}
	/*
	   for (int i=0;i<nBinsy;i++){
	   printf("y bins %d\n", i);
	   double maxuser = std::max(hf11y[i]->GetMaximum(),hf21y[i]->GetMaximum());
	   hf11y[i]->GetYaxis()->SetRangeUser(0.0,1.2*maxuser);
	   hf11y[i]->GetXaxis()->SetRangeUser(hf11y[i]->GetMean()-0.05,hf11y[i]->GetMean()+0.05);
	   hf11y[i]->SetTitle("Acceptance variation");
	   hf11y[i]->GetXaxis()->SetTitle(Form("Acceptance in %1.3f#leqy_{lab}<%1.3f (GeV/c)",ybin[i],ybin[i+1]));
	   hf11y[i]->GetYaxis()->SetTitle("Entries");

	   hf11y[i]->SetLineColor(kRed+2);
	   hf21y[i]->SetLineColor(kBlue);
	   hf11y[i]->Draw();
	   gPad->Update();
	   TPaveStats* p11 = (TPaveStats*)hf11y[i]->FindObject("stats");
	   p11->SetX1NDC(0.70);
	   p11->SetY1NDC(0.75);
	   p11->SetX2NDC(0.90);
	   p11->SetY2NDC(0.90);
	   p11->SetTextColor(kRed+2);

	   hf21y[i]->Draw();
	   gPad->Update();
	   TPaveStats* p21 = (TPaveStats*)hf21y[i]->FindObject("stats");
	   p21->SetX1NDC(0.70);
	   p21->SetY1NDC(0.45);
	   p21->SetX2NDC(0.90);
	   p21->SetY2NDC(0.60);
	   p21->SetTextColor(kBlue);

//TLegend* leg1 = new TLegend(0.12,0.7,0.4,0.88);
TLegend* leg1 = new TLegend(0.15,0.80,0.48,0.93);

double aMean1, aMin1, aMax1;
double aMean2, aMin2, aMax2;
GetMinMaxMean(hf11y[i], aMean1, aMin1, aMax1);
GetMinMaxMean(hf21y[i], aMean2, aMin2, aMax2);
double unc1 = max(fabs(aMean1-avghy[i]), max(fabs(aMin1-avghy[i]), fabs(aMax1-avghy[i])));
double unc2 = max(fabs(aMean2-avghy[i]), max(fabs(aMin2-avghy[i]), fabs(aMax2-avghy[i])));
printf("avg: %f, pt var unc: %f, y var unc: %f, final: %f\n", avghy[i], unc1, unc2, 100*max(unc1, unc2));

leg1->AddEntry(hf11y[i],"p_{T} variation with gaussian","l");
leg1->AddEntry(hf21y[i],"y variation with gaussian","l");
leg1->SetFillColor(0);
leg1->SetBorderSize(0);

TLine* yline = new TLine(avghy[i],0,avghy[i],1.2*maxuser);

TCanvas* c1=new TCanvas("c1","");
hf11y[i]->Draw("");
hf21y[i]->Draw("same");
p11->Draw("same");
p21->Draw("same");
leg1->Draw("same");
yline->Draw("same");

c1->SaveAs(Form("Bplus_accvar_ydep_%i_%s.pdf",i,label.c_str()));
}
*/

cout << "Pass All 3 Bins" << endl;
for(int i=0;i<tr11->GetEntries();i++){
	tr11->GetEntry(i);
	ha1gaus->Fill(a1_gaus);
	ha2gaus->Fill(a2_gaus);
}
/*
   for(int i=0;i<tr21->GetEntries();i++){
   tr21->GetEntry(i);
   hay1gaus->Fill(ay1_gaus);
   hay2gaus->Fill(ay2_gaus);
   }
   */

TCanvas *c3 = new TCanvas("c3","c3",600,600);

double maxusera1, maxusera2, maxuseray1, maxuseray2;
maxusera1 = std::max(ha1gaus->GetMaximum(),ha1gaus->GetMaximum());
ha1gaus->GetYaxis()->SetRangeUser(0.0,1.2*maxusera1);
maxusera2 = std::max(ha2gaus->GetMaximum(),ha2gaus->GetMaximum());
ha2gaus->GetYaxis()->SetRangeUser(0.0,1.2*maxusera2);
maxuseray1 = std::max(hay1gaus->GetMaximum(),hay1gaus->GetMaximum());
hay1gaus->GetYaxis()->SetRangeUser(0.0,1.2*maxuseray1);
maxuseray2 = std::max(hay2gaus->GetMaximum(),hay2gaus->GetMaximum());
hay2gaus->GetYaxis()->SetRangeUser(0.0,1.2*maxuseray2);

ha1gaus->Draw();
gPad->Update();
TPaveStats* pa1g = (TPaveStats*)ha1gaus->FindObject("stats");
pa1g->SetX1NDC(0.70);
pa1g->SetY1NDC(0.75);
pa1g->SetX2NDC(0.90);
pa1g->SetY2NDC(0.90);
pa1g->SetTextColor(kRed+2);


TLegend* leg1 = new TLegend(0.15,0.80,0.48,0.93);
leg1->AddEntry(ha1gaus,"p_{T} variation with gaussian","l");
leg1->SetFillColor(0);
leg1->SetBorderSize(0);

ha1gaus->SetLineColor(kRed+2);
ha1gaus->Draw("");
leg1->Draw("same");
c1->SaveAs(Form("Bplus_ha1comp_%s.pdf",label.c_str()));

leg1->Clear();
leg1->AddEntry(ha2gaus,"p_{T} variation with gaussian","l");

ha2gaus->Draw();
gPad->Update();
TPaveStats* pa2g = (TPaveStats*)ha2gaus->FindObject("stats");
pa2g->SetX1NDC(0.70);
pa2g->SetY1NDC(0.75);
pa2g->SetX2NDC(0.90);
pa2g->SetY2NDC(0.90);
pa2g->SetTextColor(kRed+2);

ha2gaus->SetLineColor(kRed+2);
ha2gaus->Draw("");
leg1->Draw("same");
c3->SaveAs(Form("Bplus_ha2comp_%s.pdf",label.c_str()));

leg1->Clear();
leg1->AddEntry(hay1gaus,"y variation with gaussian","l");

hay1gaus->Draw();

gPad->Update();
TPaveStats* pay1g = (TPaveStats*)hay1gaus->FindObject("stats");
pay1g->SetX1NDC(0.70);
pay1g->SetY1NDC(0.75);
pay1g->SetX2NDC(0.90);
pay1g->SetY2NDC(0.90);
pay1g->SetTextColor(kBlue);

hay1gaus->SetLineColor(kBlue);
hay1gaus->Draw("");
leg1->Draw("same");
c3->SaveAs(Form("Bplus_hay1comp_%s.pdf",label.c_str()));

leg1->Clear();
leg1->AddEntry(hay2gaus,"y variation with gaussian","l");

hay2gaus->Draw();

gPad->Update();
TPaveStats* pay2g = (TPaveStats*)hay2gaus->FindObject("stats");
pay2g->SetX1NDC(0.70);
pay2g->SetY1NDC(0.75);
pay2g->SetX2NDC(0.90);
pay2g->SetY2NDC(0.90);
pay2g->SetTextColor(kBlue);

hay2gaus->SetLineColor(kBlue);
hay2gaus->Draw("");
leg1->Draw("same");
c3->SaveAs(Form("Bplus_hay2comp_%s.pdf",label.c_str()));

//////////////////////
leg1->Clear();
leg1->AddEntry(htest11,"p_{T} variation with gaussian","l");

maxusera1 = std::max(htest11->GetMaximum(),htest11->GetMaximum());
htest11->GetYaxis()->SetRangeUser(0.0,1.2*maxusera1);
//maxuseray1 = std::max(htest21->GetMaximum(),htest21->GetMaximum());
//	htest21->GetYaxis()->SetRangeUser(0.0,1.2*maxuseray1);

htest11->Draw();

gPad->Update();
TPaveStats* pht11 = (TPaveStats*)htest11->FindObject("stats");
pht11->SetX1NDC(0.70);
pht11->SetY1NDC(0.75);
pht11->SetX2NDC(0.90);
pht11->SetY2NDC(0.90);
pht11->SetTextColor(kRed+2);

htest11->SetLineColor(kRed+2);
htest11->Draw("");
leg1->Draw("same");
c3->SaveAs(Form("Bplus_ratioptbin1_%s.pdf",label.c_str()));

leg1->Clear();
//	leg1->AddEntry(htest21,"y variation with gaussian","l");

//	htest21->Draw();

gPad->Update();
//	TPaveStats* pht21 = (TPaveStats*)htest21->FindObject("stats");
/*
   pht21->SetX1NDC(0.70);
   pht21->SetY1NDC(0.75);
   pht21->SetX2NDC(0.90);
   pht21->SetY2NDC(0.90);
   pht21->SetTextColor(kBlue);

   htest21->SetLineColor(kBlue);
   htest21->Draw("");
   */
leg1->Draw("same");
c3->SaveAs(Form("Bplus_ratioybin1_%s.pdf",label.c_str()));

fout->Write();
fout->Close();

}

void GetMinMaxMean(TH1D* hs, double& aMean, double& aMin, double& aMax){
	int hsbin=hs->GetNbinsX();
	bool isFillMin=false;
	bool isFillMax=false;
	double MinVal,MaxVal;
	for (int k=1;k<hsbin+1;k++){
		if (!isFillMin && (hs->GetBinContent(k))!=0) {isFillMin=true;MinVal=hs->GetBinLowEdge(k);}
		if (k<hsbin && hs->GetBinContent(k)!=0 && (hs->GetBinContent(k+1)==0 || isFillMax)) {isFillMax=true;MaxVal=hs->GetBinLowEdge(k)+hs->GetBinWidth(k);}    
	}
	std::cout << "MinVal : " << MinVal << " , Mean : " << hs->GetMean() << " , MaxVal : " << MaxVal << std::endl;
	aMean = hs->GetMean();
	aMin = MinVal;
	aMax = MaxVal;
}

