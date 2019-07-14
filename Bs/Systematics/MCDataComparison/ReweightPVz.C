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


void ReweightPVz(){

	gStyle->SetOptStat(0); 
	
	TFile *finData = new TFile("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data-Official/Data_Bs_PbPb_TMVA_BDT_PbPb.root");
	TFile *finMC = new TFile("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data-Official/MC_Bs_PbPb_TMVA_BDT_PbPb.root");



	TTree * tData = (TTree*) finData->Get("Bfinder/ntphi");
	TTree * tMC = (TTree*) finMC->Get("Bfinder/ntphi");




	TH1D * PVzData = new TH1D("PVzData","PVzData",NPVz,PVzMin,PVzMax);

	TH1D * PVzMC = new TH1D("PVzMC","PVzMC",NPVz,PVzMin,PVzMax);


	tData->Project("PVzData","PVz");

	PVzData->GetXaxis()->SetTitle("PVz (mm)");
	PVzData->GetYaxis()->SetTitle("Normalized Counts");
	PVzData->SetTitle("PVz Distribution in B_{s} Data");
	PVzData->SetMarkerStyle(20);
	PVzData->SetMarkerColor(kBlack);
	PVzData->SetMarkerSize(1);

	PVzData->Sumw2();
	PVzData->Scale(1.0/PVzData->Integral());

	tMC->Project("PVzMC","PVz - 0.321904");



	PVzMC->GetXaxis()->SetTitle("PVz (mm)");
	PVzMC->GetYaxis()->SetTitle("Normalized Counts");
	PVzMC->SetTitle("PVz Distribution in B_{S}^{0} MC");
	PVzMC->SetMarkerStyle(20);
	PVzMC->SetMarkerColor(kBlack);
	PVzMC->SetMarkerSize(1);

	PVzMC->Sumw2();
	PVzMC->Scale(1.0/PVzMC->Integral());

	TString FuncData;
	TString FuncMC;

	TF1 * f1 = new TF1("f1","[0]*TMath::Exp(-[1]*(x-[2])*(x-[2]))",PVzMin,PVzMax);
	f1->SetParLimits(1,0,1);
	f1->SetParLimits(2,0,10);

	
	PVzData->Draw("ep");
	
	PVzData->Fit(f1,"R");

	double p0Data = f1->GetParameter(0);
	double p1Data = f1->GetParameter(1);
	double p2Data = f1->GetParameter(2);


	TCanvas* c = new TCanvas("c","",600,600);
	c->cd();
	PVzData->Draw("ep");
	c->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzDataFit.png");
	c->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzDataFit.pdf");

	FuncData = Form("%f * TMath::Exp(- %f * (PVz - %f)*(PVz - %f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));

	cout << "Funct Data = " << FuncData.Data() << endl;

	PVzMC->Fit(f1,"R");

	double p0MC = f1->GetParameter(0);
	double p1MC = f1->GetParameter(1);
	double p2MC = f1->GetParameter(2);



	FuncMC = Form("%f * TMath::Exp(- %f * (PVz - %f)*(PVz - %f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));

	cout << "Funct MC = " << FuncMC.Data() << endl;



	PVzMC->Draw("ep");
	c->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzMCFit.png");
	c->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzMCFit.pdf");


	TCanvas *cAll = new TCanvas("cAll","cAll",1200,600);
	cAll->Divide(2,1);
	cAll->cd(1);
	PVzData->Draw("ep");

	cAll->cd(2);
	PVzMC->Draw("ep");
	cAll->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzBoth.png");
	cAll->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/PVzFitResults/PVzBoth.pdf");






}


