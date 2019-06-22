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
	
	TFile *finData = new TFile("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/crab_Bfinder_20190513_HIDoubleMuon__PsiPeri__HIRun2018A_04Apr2019_v1_1033p1_GoldenJSON_skimhltBsize_ntKp.root");
	TFile *finMC = new TFile("/export/d00/scratch/gwangjun/crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_pthatweight_hardcut.root");

	TTree * tData = (TTree*) finData->Get("Bfinder/ntKp");
	TTree * tMC = (TTree*) finMC->Get("Bfinder/ntKp");

	TH1D * PVzData = new TH1D("PVzData","PVzData",NPVz,PVzMin,PVzMax);

	TH1D * PVzMC = new TH1D("PVzMC","PVzMC",NPVz,PVzMin,PVzMax);


	tData->Project("PVzData","PVz");

	PVzData->GetXaxis()->SetTitle("PVz (mm)");
	PVzData->GetYaxis()->SetTitle("Normalized Counts");
	PVzData->SetTitle("PVz Distribution in B^{+} Data");
	PVzData->SetMarkerStyle(20);
	PVzData->SetMarkerColor(kBlack);
	PVzData->SetMarkerSize(1);

	PVzData->Sumw2();
	PVzData->Scale(1.0/PVzData->Integral());

	tMC->Project("PVzMC","PVz - 0.321904");



	PVzMC->GetXaxis()->SetTitle("PVz (mm)");
	PVzMC->GetYaxis()->SetTitle("Normalized Counts");
	PVzMC->SetTitle("PVz Distribution in B^{+} MC");
	PVzMC->SetMarkerStyle(20);
	PVzMC->SetMarkerColor(kBlack);
	PVzMC->SetMarkerSize(1);

	PVzMC->Sumw2();
	PVzMC->Scale(1.0/PVzMC->Integral());

	TString FuncData;
	TString FuncMC;

	TF1 * f1 = new TF1("f1","[0]*TMath::Exp(-[1]*(x-[2])*(x-[2]))",PVzMin,PVzMax);
	f1->SetParLimits(1,0,20);
	f1->SetParLimits(2,-5,5);

	
	PVzData->Draw("ep");
	
	PVzData->Fit(f1,"R");

	double p0Data = f1->GetParameter(0);
	double p1Data = f1->GetParameter(1);
	double p2Data = f1->GetParameter(2);


	TCanvas* c = new TCanvas("c","",600,600);
	c->cd();
	PVzData->Draw("ep");
	c->SaveAs("FitResults/PVzDataFit.png");

	FuncData = Form("%f * TMath::Exp(- %f * (PVz - %f)*(PVz - %f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));

	cout << "Funct Data = " << FuncData.Data() << endl;

	PVzMC->Fit(f1,"R");

	double p0MC = f1->GetParameter(0);
	double p1MC = f1->GetParameter(1);
	double p2MC = f1->GetParameter(2);



	FuncMC = Form("%f * TMath::Exp(- %f * (PVz - %f)*(PVz - %f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));

	cout << "Funct MC = " << FuncMC.Data() << endl;



	PVzMC->Draw("ep");
	c->SaveAs("FitResults/PVzMCFit.png");



}


