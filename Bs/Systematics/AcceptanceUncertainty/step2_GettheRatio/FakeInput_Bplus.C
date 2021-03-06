//### Code to calculate the acceptance systematics
//### Code for step 2 - Get the Ratio
//### Author : Hyunchul Kim, Gian Innocenti Michele
//### hyunchul.kim@cern.ch March 11 2017 Cleaned
using namespace std;
#include <iostream>
#include <TF1.h>
#include <TH1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>

// set pt bins (same for analysis binning)
//const int nBins = 5;
//double ptBins[nBins+1] = {7.,10.,15.,20.,30,50};

//const int nBins=3;
//double ptBins[nBins+1] = {7,15,20,50};


const int nBins=4;
double ptBins[nBins+1] = {5,10,15,20,50};


//const int nBins = 4;
//double ptBins[nBins+1] = {5,10.,15.,20.,60};


// set y bins (same for analysis binning)
//const int nBinsy = 5;
//double yBins[nBinsy+1] = {-2.4,-1.465,-0.465,0.535,1.470,2.4};


const int nBinsy=4;
double yBins[nBinsy+1] = {0.0, 0.5, 1.0, 1.5, 2.4};

//double yCMBins[nBinsy+1] = {1.935,1.0,0.0,-1.0,-1.935,-2.865};

// pp or PbPb
bool ispp = 0;
string label;

void FakeInput_Bplus(){

	if(ispp) label = "pp";
	else label = "PbPb";
	// call the root files including raw yield from data and MC (for pt and y binning)
	TFile *foutDataPt;
	TFile *foutDatay;
	TFile *foutMCPt;
	TFile *foutMCy;

	if(ispp == 1){
		foutDataPt = new TFile("../../Inputfileforreweighting/hPtSpectrumBplusPP.root","read");
		foutDatay    = new TFile("../../Inputfileforreweighting/hPtSpectrumBplusPP_Y.root","read");
		foutMCPt     = new TFile("../../Inputfileforreweighting/MCstudiesPP.root","read");
		foutMCy      = new TFile("../../Inputfileforreweighting/MCstudiesPP_Y.root","read");
	}
	if(ispp==0){
		foutDataPt   = new TFile("../../Inputfileforreweighting/hPtSpectrumBplusPbPb.root","read");
		foutDatay    = new TFile("../../Inputfileforreweighting/hPtSpectrumBplusPbPb_Y.root","read");
		foutMCPt     = new TFile("../../Inputfileforreweighting/MCstudiesPbPb.root","read");
		foutMCy      = new TFile("../../Inputfileforreweighting/MCstudiesPbPb_Y.root","read");
	}

	// call the histogram of raw yied from each file
	TH1D*hPtMC   = (TH1D*)foutMCPt->Get("hPtMC");
	TH1D*hPtData = (TH1D*)foutDataPt->Get("hPt");
	TH1D*hyMC        = (TH1D*)foutMCy->Get("hPtMC");
	TH1D*hyData  = (TH1D*)foutDatay->Get("hPt");

	// should be apply sumw2
	hPtMC->Sumw2();
	hPtData->Sumw2();
	hyMC->Sumw2();
	hyData->Sumw2();

	// set the name of each histogram, because originally all the histogram's name was "hPt"
	hPtMC->SetName("hPtMC");
	hPtData->SetName("hPtData");
	hyMC->SetName("hyMC");
	hyData->SetName("hyData");

	// For the comparison, we scaled each histogram by the integral of each histogram
	hPtMC->Scale(1./hPtMC->Integral());
	hPtData->Scale(1./hPtData->Integral());
	hyMC->Scale(1./hyMC->Integral());
	hyData->Scale(1./hyData->Integral());

	/*
	// Check the state
	cout<<"QUI"<<hPtMC->Integral()<<endl;
	cout<<"QUI"<<hPtData->Integral()<<endl;
	cout<<"QUI"<<hyMC->Integral()<<endl;
	cout<<"QUI"<<hyData->Integral()<<endl;
	*/



	// call the histogram with same structure of "hPtData(hyData)", by clone it
	TH1D*hReweightDataOverMC_Pt=(TH1D*)hPtData->Clone("hReweightDataOverMC_Pt");
	TH1D*hReweightDataOverMC_y=(TH1D*)hyData->Clone("hReweightDataOverMC_y");



	// Get the ratio of raw yield (Data/MC)
	hReweightDataOverMC_Pt->Divide(hPtData,hPtMC,1,1,"B");
	cout << "Pass pT" << endl;
	hReweightDataOverMC_y->Divide(hyData,hyMC,1,1,"B");
	cout << "Pass y" << endl;

	// Prove whether input file is right or not in one canvas, if remove line 65-71, values of stat box in plots is changed because of unknown problem
	TCanvas*c=new TCanvas("c","c",800,500);
	c->Divide(2,2);
	c->cd(1);hPtData->Draw();
	c->cd(2);hPtMC->Draw();
	c->cd(3);hyData->Draw();
	c->cd(4);hyMC->Draw();
	c->SaveAs(Form("prova_Bs_%s.pdf", label.c_str()));

	// call the output file and save the histograms until now
	TFile*fout=new TFile(Form("InputFilesMCData_Bs_%s.root",label.c_str()),"recreate");
	fout->cd();
	hPtData->Write();
	hPtMC->Write();
	hyData->Write();
	hyMC->Write();
	hReweightDataOverMC_Pt->Write();
	hReweightDataOverMC_y->Write();
	fout->Close();

	std::cout << "### Data/MC ratio is saved in root file. ###" << std::endl;

	////////////////////////////////////////////////////////////////////////////////

	// call the resulted file from last step
	TFile* fin = new TFile(Form("InputFilesMCData_Bs_%s.root", label.c_str()),"read");

	// call the saved histogram (raw yield from Data and MC and Data/MC ratio)
	hPtData=(TH1D*)fin->Get("hPtData");
	hPtMC=(TH1D*)fin->Get("hPtMC");
	hyData=(TH1D*)fin->Get("hyData");
	hyMC=(TH1D*)fin->Get("hyMC");
	hReweightDataOverMC_Pt=(TH1D*)fin->Get("hReweightDataOverMC_Pt");
	hReweightDataOverMC_y=(TH1D*)fin->Get("hReweightDataOverMC_y");

	// set the fitting function for pt and y ratio
	TF1 *fRfitft_Bpluspt = new TF1("fRfitft_Bpluspt","[0]*x + [1]/x**5",5,50.0);//Bplus, pt dependence
	fRfitft_Bpluspt->SetParLimits(2,1,3);
	//TF1 *fRfitft_Bsy = new TF1("fRfitft_Bsy","[0]*pow((x-0.0),2)+[1]",-2.865,1.935);
	TF1 *fRfitft_Bsy = new TF1("fRfitft_Bsy","[0] +[1] *x + [2] *x *x",0.0,2.4);//Bplus, y dependence
	fRfitft_Bsy->SetParLimits(0,0.2,0.9);
	fRfitft_Bsy->SetParLimits(2,-5,0);

	// call histogram for parameter fit
	TH1D* hParafitft_Bpluspt = new TH1D("hParafitft_Bpluspt","",2,0,2);
	TH1D* hParafitft_Bsy  = new TH1D("hParafitft_Bsy","",3,0,3);

	TCanvas* canvas11 = new TCanvas("canvas11","",600,600);
	canvas11->cd();

	TLegend* leg11 = new TLegend(0.20,0.70,0.45,0.85);
	leg11->AddEntry(hPtData,"Data","lep");
	leg11->AddEntry(hPtMC,"MC","f");
	leg11->SetFillColor(kWhite);
	leg11->SetBorderSize(0);

	TPaveText* pt11 = new TPaveText(0.22,0.62,0.27,0.67,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");

	hPtMC->GetYaxis()->SetTitle("Proportion of uncorrected B_{s} dN/dp_{T} (Data/MC)");
	hPtMC->SetMinimum(0);
	hPtMC->SetMaximum(0);
	hPtMC->SetFillColor(kPink+6);
	//hPtMC->SetFillStyle(3004);
	hPtMC->SetLineWidth(1);
	hPtMC->SetLineColor(kBlack);
	hPtMC->Draw("H");
	hPtData->SetMarkerStyle(21);
	hPtData->SetMarkerSize(1.0);
	hPtData->SetLineWidth(1);
	hPtData->SetLineColor(kBlack);
	hPtData->Draw("samepe");
	leg11->Draw();
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_CompNormUncorYield_Bs_%s.pdf", label.c_str()));

	hReweightDataOverMC_Pt->SetMinimum(0.0);
	hReweightDataOverMC_Pt->SetMaximum(6);
	hReweightDataOverMC_Pt->Draw("p");
	hReweightDataOverMC_Pt->SetMarkerStyle(20);
	hReweightDataOverMC_Pt->SetMarkerSize(1.5);
	hReweightDataOverMC_Pt->SetLineWidth(1.0);
	hReweightDataOverMC_Pt->SetLineColor(kBlack);
	hReweightDataOverMC_Pt->GetYaxis()->SetTitle("Ratio of uncorrected B_{s} dN/dp_{T} (Data/MC)");

	fRfitft_Bpluspt->SetLineColor(kRed);
	fRfitft_Bpluspt->SetLineWidth(2.0);
	std::cout << "##### Fit with fRfitft_Bpluspt \"[0] * x + [1]/x \" #############" << std::string(20,'#') << std::endl; 
	hReweightDataOverMC_Pt->Fit("fRfitft_Bpluspt"); 
	std::cout << std::string(76,'#') << std::endl;
	hParafitft_Bpluspt->SetBinContent(1,fRfitft_Bpluspt->GetParameter(0));
	hParafitft_Bpluspt->SetBinContent(2,fRfitft_Bpluspt->GetParameter(1));



	pt11->Clear();
	pt11 = new TPaveText(0.22,0.80,0.27,0.85,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_RatioNormUncorYield_Bs_%s.pdf", label.c_str()));

	for (int i=0;i<5;i++) {
		std::cout << i << ": " << hReweightDataOverMC_Pt->GetBinContent(i+1) << " , " << hReweightDataOverMC_Pt->GetBinError(i+1) << std::endl;
	}

	leg11->Clear();
	leg11->AddEntry(hyData,"Data","lep");
	leg11->AddEntry(hyMC,"MC","f");
	leg11->SetFillColor(kWhite);
	leg11->SetBorderSize(0);

	pt11->Clear();
	pt11->AddText("B_{s}");

	hyMC->GetYaxis()->SetTitle("Proportion of uncorrected B_{s} dN/dy_{CM} (Data/MC)");
	hyMC->SetMinimum(0);
	hyMC->SetMaximum(0);
	hyMC->SetFillColor(kPink+6);
	//hyMC->SetFillStyle(3004);
	hyMC->SetLineWidth(1);
	hyMC->SetLineColor(kBlack);
	hyMC->Draw("H");
	hyData->SetMarkerStyle(21);
	hyData->SetMarkerSize(1.0);
	hyData->SetLineWidth(1);
	hyData->SetLineColor(kBlack);
	hyData->Draw("samepe");
	leg11->Draw();
	pt11->Clear();
	pt11 = new TPaveText(0.22,0.62,0.27,0.67,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B^{0}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_CompNormUncorYield_Bsy_%s.pdf", label.c_str()));

	hReweightDataOverMC_y->SetMinimum(0.6);
	hReweightDataOverMC_y->SetMaximum(1.8);
	hReweightDataOverMC_y->Draw("p");
	hReweightDataOverMC_y->SetMarkerStyle(20);
	hReweightDataOverMC_y->SetMarkerSize(1.5);
	hReweightDataOverMC_y->SetLineWidth(1.0);
	hReweightDataOverMC_y->SetLineColor(kBlack);
	hReweightDataOverMC_y->GetYaxis()->SetTitle("Ratio of uncorrected B_{s} dN/dy_{CM} (Data/MC)");

	fRfitft_Bsy->SetLineColor(kRed);
	fRfitft_Bsy->SetLineWidth(2.0);
	std::cout << "##### Fit with fRfitft_Bsy  \"[0] + [1] * x + [2] * x * x \" ######" << std::string(20,'#') << std::endl; 
	hReweightDataOverMC_y->Fit("fRfitft_Bsy"); 
	std::cout << std::string(76,'#') << std::endl;
	hParafitft_Bsy->SetBinContent(1,fRfitft_Bsy->GetParameter(0));
	hParafitft_Bsy->SetBinContent(2,fRfitft_Bsy->GetParameter(1));
	hParafitft_Bsy->SetBinContent(3,fRfitft_Bsy->GetParameter(2));

	pt11->Clear();
	pt11 = new TPaveText(0.22,0.80,0.27,0.85,"NDC");
	pt11->SetFillColor(0);
	pt11->SetTextSize(0.05);
	pt11->SetBorderSize(0);
	pt11->AddText("B_{s}");
	pt11->Draw();
	canvas11->SaveAs(Form("AccSys_RatioNormUncorYield_Bsy_%s.pdf", label.c_str()));

	for (int i=0;i<5;i++) {
		std::cout << i << ": " << hReweightDataOverMC_y->GetBinContent(i+1) << " , " << hReweightDataOverMC_y->GetBinError(i+1) << std::endl;
	}

	/*
	// Prove pt dependence results in one canvas

	double p0,p1,p2,p3;
	TF1 *fRexpoPt2 = new TF1("fRexpoPt2","(TMath::Exp([0]-x*[1]))/(TMath::Exp([2]-x*[3]))",10.0,60.0);

	TF1 *fexpoPtData = new TF1("fexpoPtData","TMath::Exp([0]-x*[1])",10.0,60.0);
	TF1 *fexpoPtMC = new TF1("fexpoPtMC","TMath::Exp([0]-x*[1])",10.0,60.0);
	TF1 *fRexpoPt = new TF1("fRexpoPt","(TMath::Exp([0]-x*[1]))/(TMath::Exp([2]-x*[3]))",10.0,60.0);

	TCanvas* canvas = new TCanvas("canvas","canvas",900,300);
	canvas->Divide(3,1);

	canvas->cd(1);
	hPtData->SetMinimum(0);
	hPtData->SetMaximum(1);
	hPtData->Draw("p");
	hPtData->SetMarkerStyle(22);
	hPtData->SetMarkerSize(0.5);
	//fexpoPtData->SetParameter(1.19402,1.44347e-01);
	hPtData->Fit("fexpoPtData");
	p0=fexpoPtData->GetParameter(0);
	p1=fexpoPtData->GetParameter(1);

	canvas->cd(2);
	hPtMC->SetMinimum(0);
	hPtMC->SetMaximum(1);
	hPtMC->Draw("p");
	hPtMC->SetMarkerStyle(22);
	hPtMC->SetMarkerSize(0.5);
	hPtMC->Fit("fexpoPtMC");
	p2=fexpoPtMC->GetParameter(0);
	p3=fexpoPtMC->GetParameter(1);

	canvas->cd(3);
	hReweightDataOverMC_Pt->SetMinimum(0.6);
	hReweightDataOverMC_Pt->SetMaximum(1.8);
	hReweightDataOverMC_Pt->Draw("p");
	hReweightDataOverMC_Pt->SetMarkerStyle(22);
	hReweightDataOverMC_Pt->SetMarkerSize(0.5);
	fRexpoPt->SetParameters(p0,p1,p2,p3);
	fRexpoPt->SetLineColor(kBlue);
	fRexpoPt->Draw("same");
	fRexpoPt2->SetParameters(p0,p1,p2,p3);
	hReweightDataOverMC_Pt->Fit("fRexpoPt2");
	fRexpoPt2->SetLineColor(kRed);
	fRexpoPt2->Draw("same");
	fRfitft_Bpluspt->SetLineColor(kGreen);
	hReweightDataOverMC_Pt->Fit("fRfitft_Bpluspt"); 
	canvas->SaveAs("FitstoRatioDataMC_Bplus.pdf");

	// Prove y dependence results in one canvas

	TCanvas*canvas2 = new TCanvas("canvas2","canvas2",900,300);
	canvas2->Divide(3,1);

	canvas2->cd(1);

	hyData->SetMinimum(0);
	hyData->SetMaximum(1);
	hyData->Draw("p");
	hyData->SetMarkerStyle(22);
	hyData->SetMarkerSize(0.5);

	canvas2->cd(2);

	hyMC->SetMinimum(0);
	hyMC->SetMaximum(1);
	hyMC->Draw("p");
	hyMC->SetMarkerStyle(22);
	hyMC->SetMarkerSize(0.5);

	canvas2->cd(3);

	hReweightDataOverMC_y->SetMinimum(0.6);
	hReweightDataOverMC_y->SetMaximum(1.8);
	hReweightDataOverMC_y->Draw("p");
	hReweightDataOverMC_y->SetMarkerStyle(22);
	hReweightDataOverMC_y->SetMarkerSize(0.5);

	TF1 *fRy2 = new TF1("fRy2","[0]*pow((x-[2]),2)+[1]",-2.865,1.935);
	fRfitft_Bsy->SetLineColor(kBlue);
	hReweightDataOverMC_y->Fit("fRfitft_Bsy");
	fRy2->SetLineColor(kRed);
	hReweightDataOverMC_y->Fit("fRy2");
	//fRfitft_Bsy->Draw("same");
	fRy2->Draw("same");

	canvas2->SaveAs("FitstoRatioDataMC_Bsy.pdf");
	*/
		////////////////////////////////////////////////////////////////////////////////////////

		TFile* fout2 = new TFile(Form("FunctionsReweighting_Bs_%s.root", label.c_str()),"recreate");
	fout2->cd();
	hPtData->Write();
	hPtMC->Write();
	hReweightDataOverMC_Pt->Write();
	hyData->Write();
	hyMC->Write();
	hReweightDataOverMC_y->Write();
	fRfitft_Bsy->Write();
	fRfitft_Bpluspt->Write();
	hParafitft_Bpluspt->Write();
	hParafitft_Bsy->Write();
	/*
	   fexpoPtData->Write();
	   fexpoPtMC->Write();
	   fRexpoPt->Write();
	   */
	fout2->Close();
}
