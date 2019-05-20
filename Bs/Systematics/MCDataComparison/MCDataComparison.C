#ifndef __CINT__
#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
#include "uti.h"
#include "parameters.h"
//#include "his.h"
using namespace std;

using std::cout;
using std::endl;
#endif


void MCDataComparison(TString collsyst, TString inputdata, TString inputMC, TString SignalCut, TString SideBandCut,TString GenCut ){


	int doDebug = 1;
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetOptStat(0); 

	TString weightfunctionreco;

	//	if(collsyst == "pp") weightfunctionreco="(pthatweight)";
	if(collsyst == "pp") weightfunctionreco="(1)";


	if(collsyst == "PbPb") weightfunctionreco="(pthatweight)";

	//cout << "Signal Cut = " << SignalCut.Data() << endl;


	TH1D * HisSData[NVar];
	TH1D * HisBData[NVar];
	TH1D * HisYData[NVar];
	TH1D * HisSMC[NVar];
	TH1D * HisBMC[NVar];
	TH1D * HisYMC[NVar];
	TH1D * HisGMC[NVar];


	TH1D * YRatioYMC[NVar];
	TH1D * YRatioGMC[NVar];


	for(int j = 0; j < NBins;j++){
		cout << "ptL = " << ptBins[j] << "  ptU = " << ptBins[j+1] << endl;

		TString ptCuts = Form("(Bpt > %f && Bpt < %f)",ptBins[j],ptBins[j+1]);
		TString	SignalCutMC = Form("%s * ((%s)&&(%s))",weightfunctionreco.Data(),SignalCut.Data(),ptCuts.Data());
		TString	SideBandCutMC = Form("%s * ((%s)&&(%s))",weightfunctionreco.Data(),SideBandCut.Data(),ptCuts.Data());
		TString	GenCutMC = Form("%s * ((%s)&&(%s))",weightfunctionreco.Data(),GenCut.Data(),ptCuts.Data());

		TString SideBandCutData = Form("(%s)&&(%s)",SideBandCut.Data(),ptCuts.Data());
		TString SignalCutData = Form("(%s)&&(%s)",SignalCut.Data(),ptCuts.Data());


		cout << "GenCutMC = " << GenCutMC.Data() << endl;
		//	double Dymin = (collsyst == "pp")?ppDymin:pPbDymin;
		//	double Dymax = (collsyst == "pp")?ppDymax:pPbDymax;


		/*
		   HisSData[0] =  new TH1D("pthisSData","pthisSData",Npt,ptmin,ptmax);
		   HisBData[0] =  new TH1D("pthisBData","pthisBData",Npt,ptmin,ptmax);  
		   HisSMC[0] =  new TH1D("pthisSMC","pthisSMC",Npt,ptmin,ptmax);
		   HisBMC[0] =  new TH1D("pthisBMC","pthisBMC",Npt,ptmin,ptmax);
		//	 HisYMC[0] =  new TH1D("pthisYMC","pthisYMC",Npt.ptmin,ptmax);  
		HisGMC[0] =  new TH1D("pthisGMC","pthisGMC",Npt,ptmin,ptmax);  
		"
		HisSData[1] =  new TH1D("alphahisSData","alphahisSData",Nalpha,alphamin,alphamax);
		HisBData[1] =  new TH1D("alphahisBData","alphahisBData",Nalpha,alphamin,alphamax);  
		HisSMC[1] =  new TH1D("alphahisSMC","alphahisSMC",Nalpha,alphamin,alphamax);
		HisBMC[1] =  new TH1D("alphahisBMC","alphahisBMC",Nalpha,alphamin,alphamin);
		//	 HisYMC[1] =  new TH1D("alphahisYMC","alphahisYMC",Nalpha.alphamin,alphamin);  
		HisGMC[1] =  new TH1D("alphahisGMC","alphahisGMC",Nalpha,alphamin,alphamax);  

		HisSData[2] =  new TH1D("ProbhisSData","ProbhisSData",NProb,Probmin,Probmax);
		HisBData[2] =  new TH1D("ProbhisBData","ProbhisBData",NProb,Probmin,Probmax);  
		HisSMC[2] =  new TH1D("ProbhisSMC","ProbhisSMC",NProb,Probmin,Probmax);
		HisBMC[2] =  new TH1D("ProbhisBMC","ProbhisBMC",NProb,Probmin,Probmax);  
		HisGMC[2] =  new TH1D("ProbhisGMC","ProbhisGMC",NProb,Probmin,Probmax);  

		HisSData[3] =  new TH1D("RatiohisSData","RatiohisSData",NRatio,Ratiomin,Ratiomax);
		HisBData[3] =  new TH1D("RatiohisBData","RatiohisBData",NRatio,Ratiomin,Ratiomax);  
		HisSMC[3] =  new TH1D("RatiohisSMC","RatiohisSMC",NRatio,Ratiomin,Ratiomax);
		HisBMC[3] =  new TH1D("RatiohisBMC","RatiohisBMC",NRatio,Ratiomin,Ratiomax);  
		HisGMC[3] =  new TH1D("RatiohisGMC","RatiohisGMC",NRatio,Ratiomin,Ratiomax);  


		if(collsyst == "pp"){
		HisSData[4] =  new TH1D("DyhisSData","DyhisSData",NDy,ppDymin,ppDymax);
		HisBData[4] =  new TH1D("DyhisBData","DyhisBData",NDy,ppDymin,ppDymax);  
		HisSMC[4] =  new TH1D("DyhisSMC","DyhisSMC",NDy,ppDymin,ppDymax);
		HisBMC[4] =  new TH1D("DyhisBMC","DyhisBMC",NDy,ppDymin,ppDymax);  
		HisGMC[4] =  new TH1D("DyhisGMC","DyhisGMC",NDy,ppDymin,ppDymax);  
		}


		if(collsyst == "pPb"){
		HisSData[4] =  new TH1D("DyhisSData","DyhisSData",NDy,pPbDymin,pPbDymax);
		HisBData[4] =  new TH1D("DyhisBData","DyhisBData",NDy,pPbDymin,pPbDymax);  
		HisSMC[4] =  new TH1D("DyhisSMC","DyhisSMC",NDy,pPbDymin,pPbDymax);
		HisBMC[4] =  new TH1D("DyhisBMC","DyhisBMC",NDy,pPbDymin,pPbDymax);  
		HisGMC[4] =  new TH1D("DyhisGMC","DyhisGMC",NDy,pPbDymin,pPbDymax);  
		}
		*/
		TFile *fin = new TFile(inputdata.Data());
		TFile *finMC = new TFile(inputMC.Data());



		TTree* nt = (TTree*) fin->Get("Bfinder/ntphi");
		nt->AddFriend("hltanalysis/HltTree");
		nt->AddFriend("hiEvtAnalyzer/HiTree");  
		nt->AddFriend("skimanalysis/HltTree");
		//		nt->AddFriend("ntGen");
		nt->AddFriend("BDT_pt_7_15");
		nt->AddFriend("BDT_pt_15_20");
		nt->AddFriend("BDT_pt_20_50");

		TTree* ntMC = (TTree*)finMC->Get("Bfinder/ntphi");
		ntMC->AddFriend("hltanalysis/HltTree");
		ntMC->AddFriend("hiEvtAnalyzer/HiTree");  
		ntMC->AddFriend("skimanalysis/HltTree");
		ntMC->AddFriend("Bfinder/ntGen");
		ntMC->AddFriend("BDT_pt_7_15");
		ntMC->AddFriend("BDT_pt_15_20");
		ntMC->AddFriend("BDT_pt_20_50");




		TFile * fout = new TFile("output.root","RECREATE");
		TString FileName;
		TCanvas* c = new TCanvas("c","",600,600);
		c->cd();
		TLegend* leg[NVar];
		TLegend* legRatio[NVar];

		cout << "Total Variables = " << NVar << endl;

		for(int i = 0; i < NVar; i ++)
		{
			cout << "i = " << i  << "    START Doing Variable " << Var[i].Data() << endl;
			//HisSData[0] =  new TH1F("pthisSData","pthisSData",Npt,ptmin,ptmax);
			HisSData[i] = new TH1D(VarSData[i].Data(),VarSData[i].Data(),Binning[i],Min[i],Max[i]);
			//	HisSData[i] = new TH1D(VarSData[i].Data(),VarSData[i].Data(),6,DyBin);
			//	cout << "Binning = "  <<  Binning[i] << " Min = " << Min[i] << "  Max =" <<  Max[i] << endl;
			nt->Project(VarSData[i].Data(),Var[i].Data(),SignalCutData.Data());
			cout << "Total S = " << HisSData[i]->Integral() << endl;
			//	return;
			HisBData[i] = new TH1D(VarBData[i].Data(),VarBData[i].Data(),Binning[i],Min[i],Max[i]);
			//HisBData[i] = new TH1D(VarBData[i].Data(),VarBData[i].Data(),6,DyBin);

			nt->Project(VarBData[i].Data(),Var[i].Data(),SideBandCutData.Data());
			cout << "Total B Before = " << HisBData[i]->Integral() << endl;

			HisSData[i]->Sumw2();
			HisBData[i]->Sumw2();


			HisBData[i]->Scale(width/(sidemax-sidemin));
			cout << "Total B  After = " << HisBData[i]->Integral() << endl;
			//		cout << "Pass 1" << endl;
			//	HisSData[i]->SetLineColor(kRed);
			//		HisBData[i]->SetLineColor(kBlue);
			//HisBData[i]->Draw();
			HisSData[i]->Draw("SAME");
			//c->SaveAs(Form("DataSideBandDy%s.pdf",collsyst.Data()));

			HisYData[i] = (TH1D *) HisSData[i]->Clone(VarYData[i].Data());
			HisYData[i]->Add(HisBData[i],-1);
			cout << "Total Y = " << HisYData[i]->Integral() << endl;
			HisYData[i]->Sumw2();
			HisYData[i]->Scale(1.0/HisYData[i]->Integral());
			HisSMC[i] = new TH1D(VarSMC[i].Data(),VarSMC[i].Data(),Binning[i],Min[i],Max[i]);
			ntMC->Project(VarSMC[i].Data(),Var[i].Data(),SignalCutMC.Data());
			HisBMC[i] = new TH1D(VarBMC[i].Data(),VarBMC[i].Data(),Binning[i],Min[i],Max[i]);
			ntMC->Project(VarBMC[i].Data(),Var[i].Data(),SideBandCutMC.Data());
			//		cout << "Pass 2" << endl;
			HisSMC[i]->Sumw2();
			HisBMC[i]->Sumw2();

			HisBMC[i]->Scale(width/(sidemax-sidemin));
			HisYMC[i] = (TH1D *) HisSMC[i]->Clone(VarYMC[i].Data());
			HisYMC[i]->Add(HisBMC[i],-1);
			HisYMC[i]->Scale(1.0/HisYMC[i]->Integral());
			HisGMC[i] = new TH1D(VarGMC[i].Data(),VarGMC[i].Data(),Binning[i],Min[i],Max[i]);
			ntMC->Project(VarGMC[i].Data(),Var[i].Data(),GenCutMC.Data());
			HisGMC[i]->Sumw2();
			cout << "Total MC =" << HisYMC[i]->Integral() << endl;
			cout << "Total G = " << HisGMC[i]->Integral() << endl;

			HisGMC[i]->Scale(1.0/HisGMC[i]->Integral());
			//		cout << "Pass 3" << endl;
			HisYData[i]->GetYaxis()->SetTitleOffset(1.5);
			HisYData[i]->SetTitle(HisName[i].Data());

			HisYData[i]->SetMaximum(MaxY[i]);
			HisYData[i]->SetMarkerStyle(22);

			HisYData[i]->Draw("ep");
			HisYData[i]->SetMaximum(0.30);
			HisYData[i]->SetLineColor(kRed);
			HisYData[i]->SetMarkerSize(2);
			//	HisYMC[i]->Draw("ep");
			HisYMC[i]->SetLineColor(kBlue);
			HisYMC[i]->SetMarkerSize(2);
			//		cout << "Pass 4" << endl;
			//		HisGMC[i]->Draw("ep");
			HisGMC[i]->SetLineColor(kGreen);
			//	HisGMC[i]->SetMarkerSize(2);
			cout << "Pass 5" << endl;
			HisYData[i]->SetLineWidth(3);
			HisYMC[i]->SetLineWidth(3);
			HisGMC[i]->SetLineWidth(3);
			HisYData[i]->GetXaxis()->SetTitle(XName[i].Data());
			HisYData[i]->GetYaxis()->SetTitle(YName[i].Data());
			HisYMC[i]->GetXaxis()->SetTitle(XName[i].Data());
			HisYMC[i]->GetYaxis()->SetTitle(YName[i].Data());
			HisGMC[i]->GetXaxis()->SetTitle(XName[i].Data());
			HisGMC[i]->GetYaxis()->SetTitle(YName[i].Data());
			//HisYData[i]->Draw("ep");

			//HisGMC[i]->SetMarkerStyle(23);
			HisGMC[i]->Draw("epSAME");
			//	HisGMC[i]->SetMinimum(0);
			//	HisYMC[i]->SetMarkerStyle(24);
			HisYMC[i]->Draw("epSAME");


			//cout << " Bin Value G MC = "	<<HisGMC[i]->GetBinContent(5) << "  Bin Value Y MC = " << HisYMC[i]->GetBinContent(5) << endl;
			leg[i]= new TLegend(0.30,0.68,0.47,0.88,NULL,"brNDC");

			leg[i]->SetBorderSize(0);
			leg[i]->SetTextSize(0.04);
			leg[i]->SetTextFont(42);
			leg[i]->SetFillStyle(0);
			leg[i]->AddEntry(HisYData[i],Form("Data Sideband Sub for %.1f < Dpt <  %.1f",ptBins[j],ptBins[j+1]),"pl");
			leg[i]->AddEntry(HisYMC[i],Form("MC Sideband Sub for %.1f < Dpt < %.1f",ptBins[j],ptBins[j+1]),"pl");
			leg[i]->AddEntry(HisGMC[i],Form("MC GenMatch for  %.1f < Dpt < %.1f",ptBins[j],ptBins[j+1]),"pl");
			leg[i]->Draw("SAME");
			c->Update();
			cout <<"Name = " << Name[i].Data() << endl;
			FileName = Form("Plots/%s_%s_%d.pdf",Name[i].Data(),collsyst.Data(),j);
			c->SaveAs(FileName.Data());

			YRatioYMC[i] = (TH1D * ) HisYData[i]->Clone();
			YRatioYMC[i]->Divide(HisYMC[i]);
			YRatioGMC[i] = (TH1D * ) HisYData[i]->Clone();
			YRatioGMC[i]->Divide(HisGMC[i]);
			YRatioYMC[i]->SetTitle(Form("%s YYMCRatio",HisName[i].Data()));
			YRatioGMC[i]->SetTitle(Form("%s YGMCRatio",HisName[i].Data()));



			c->cd();

			YRatioYMC[i]->SetMarkerColor(kBlue);
			YRatioGMC[i]->SetMarkerColor(kGreen);

			YRatioYMC[i]->SetMinimum(0);
			YRatioYMC[i]->SetMaximum(10);

			YRatioYMC[i]->Draw();

			YRatioGMC[i]->Draw("SAME");

			legRatio[i]= new TLegend(0.30,0.68,0.47,0.88,NULL,"brNDC");

			legRatio[i]->SetBorderSize(0);
			legRatio[i]->SetTextSize(0.04);
			legRatio[i]->SetTextFont(42);
			legRatio[i]->SetFillStyle(0);
			legRatio[i]->AddEntry(YRatioYMC[i],Form("Data MC Side Band Ratio %.1f < Dpt <  %.1f",ptBins[j],ptBins[j+1]),"pl");
			legRatio[i]->AddEntry(YRatioGMC[i],Form("Data MC GenMatch Ratio %.1f < Dpt < %.1f",ptBins[j],ptBins[j+1]),"pl");
			legRatio[i]->Draw("SAME");


			FileName = Form("Plots/RatioPlots%s_%s_%d.pdf",Name[i].Data(),collsyst.Data(),j);
			c->SaveAs(FileName.Data());
		
			
			TCanvas* cBoth = new TCanvas("cBoth","cBoth",600,700);
			TLine* lPull = new TLine(5.0, 0, 6.0, 0);
			lPull->SetLineWidth(1);
			lPull->SetLineStyle(7);
			lPull->SetLineColor(1);

			TPad* p1 = new TPad("p1","p1",0,0.3,1,1);
			p1->SetBottomMargin(0);
			p1->Draw();
			p1->cd();
			HisYData[i]->Draw();
			HisYMC[i]->Draw("SAME");
			HisGMC[i]->Draw("SAME");
	        leg[i]->Draw("SAME");
			cBoth->cd();
			TPad* p2 = new TPad("p2","p2",0,0,1,0.3);
			p2->SetTopMargin(0);
			p2->SetBottomMargin(0.3);
			p2->Draw();
			p2->cd();

			YRatioYMC[i]->Draw();
			YRatioGMC[i]->Draw("SAME");
			legRatio[i]->Draw("SAME");
			lPull->Draw();
			cBoth->cd();
	
			FileName = Form("Plots/Pull/RatioPlotsPull%s_%s_%d.pdf",Name[i].Data(),collsyst.Data(),j);
			c->SaveAs(FileName.Data());


			fout->cd();
			HisYData[i]->Write();
			HisYMC[i]->Write();
			HisGMC[i]->Write();
			YRatioYMC[i]->Write();
			YRatioGMC[i]->Write();

			if(doDebug == 1){
				double cutLow = Min[i]+(Max[i]-Min[i])/Binning[i]*10;
				double cutHigh = Min[i]+(Max[i]-Min[i])/Binning[i]*11;
				TH1D * DebugMassY;
				TH1D * DebugMassS = new TH1D("DebugMassS","DebugMassS",50,5,6);
				TH1D * DebugMassB = new TH1D("DebugMassB","DebugMassB",50,5,6);
				TH1D * DebugMassG = new TH1D("DebugMassG","DebugMassG",50,5,6);

				cout << "cut low = " << cutLow << "  cut high = " <<  cutHigh << endl;
				ntMC->Project("DebugMassS","Bmass");
				ntMC->Project("DebugMassB","Bmass");
				cout << "Signal Region Nu Cut = " << DebugMassS->Integral() << endl;
				cout << "SidBand Region Nu Cut = " << DebugMassB->Integral() << endl;

				ntMC->Project("DebugMassS","Bmass",Form("%s && %s > %f &&  %s < %f ",SignalCutMC.Data(),Var[i].Data(),cutLow,Var[i].Data(),cutHigh));
				ntMC->Project("DebugMassB","Bmass",Form("%s && %s > %f &&  %s < %f ",SideBandCutMC.Data(),Var[i].Data(),cutLow,Var[i].Data(),cutHigh));
				ntMC->Project("DebugMassG","Bmass",Form("%s && %s > %f &&  %s < %f ",GenCutMC.Data(),Var[i].Data(),cutLow,Var[i].Data(),cutHigh));

				DebugMassB->Scale(width/(sidemax-sidemin));
				DebugMassY = (TH1D *) DebugMassS->Clone("DebugMassY");
				DebugMassY->Add(DebugMassB,-1);

				cout << "Variable = " <<  Var[i].Data() <<  "  GenMatch Total = " << DebugMassG->Integral() << "   Sideband Total =  " <<  DebugMassY->Integral() << endl;

			}


		}
	}



}

int main(int argc, char *argv[])
{
	if((argc !=7))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 7)
		MCDataComparison(argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);
	return 0;
}


