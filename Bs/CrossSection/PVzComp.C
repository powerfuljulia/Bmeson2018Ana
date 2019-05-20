#include <cmath>
#include <TFile.h>
#include <TString.h>
#include <TLine.h>
#include <TTree.h>
#include <TLatex.h>
#include <TGraphErrors.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"

using namespace std;



using std::cout;
using std::endl;


void PVzComp(){
	gStyle->SetOptStat(0); 

	/*
	TFile * fin1 = new TFile("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MakeBDT/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_20181231_pt5tkpt0p7dls2_v3_pthatweight_BDTMerged.root");
	TFile * fin2 = new TFile("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/Data/New/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_skimhltBsize_ntphi_NewBDTMerged.root");
	TFile * fin3 = new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root");
	TFile * fin4 = new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_candWise.root");


	TTree * t1 = (TTree *) fin1->Get("Bfinder/ntphi");
	TTree * t2 = (TTree *) fin2->Get("Bfinder/ntphi");
	TTree * t3 = (TTree *) fin3->Get("ntphi");
	TTree * t4 = (TTree *) fin4->Get("ntphi");
*/

	TFile * fin1 = new TFile("/raid5/data/gwangjun/crab_Bfinder_20190221_Pythia8_BuToJpsiK_Bpt0p0_1032_NoJSON_pthatweight_hardcut_v2.root"); //2018 PbPb MC
	TFile * fin2 = new TFile("/raid5/data/BntupleRun2018/Data/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_skimhltBsize_ntKp.root"); // 2018 PbPb Data
	TFile * fin3 = new TFile("/raid5/data/BntupleRun2018/MC/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_pthatweight_JingBDT.root");  //2015 PbPb MC
	TFile * fin4 = new TFile("/raid5/data/BntupleRun2018/Data/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderData_PbPb_20160816_bPt5jpsiPt0tkPt0p8_Bp_JingBDT.root");  // 2015 PbPb Data


	TTree * t1 = (TTree *) fin1->Get("Bfinder/ntKp");
	TTree * t2 = (TTree *) fin2->Get("Bfinder/ntKp");
	TTree * t3 = (TTree *) fin3->Get("ntKp");
	TTree * t4 = (TTree *) fin4->Get("ntKp");





	TH1D * PVz1 = new TH1D("PVz1","PVz1",100,-30,30);
	TH1D * PVz2 = new TH1D("PVz2","PVz2",100,-30,30);
	TH1D * PVz3 = new TH1D("PVz3","PVz3",100,-30,30);
	TH1D * PVz4 = new TH1D("PVz4","PVz4",100,-30,30);


	TH1D * PVx1 = new TH1D("PVx1","PVx1",300,-0.2,0.2);
	TH1D * PVx2 = new TH1D("PVx2","PVx2",300,-0.2,0.2);
	TH1D * PVx3 = new TH1D("PVx3","PVx3",300,-0.2,0.2);
	TH1D * PVx4 = new TH1D("PVx4","PVx4",300,-0.2,0.2);

	
	TH1D * PVy1 = new TH1D("PVy1","PVy1",300,-0.2,0.2);
	TH1D * PVy2 = new TH1D("PVy2","PVy2",300,-0.2,0.2);
	TH1D * PVy3 = new TH1D("PVy3","PVy3",300,-0.2,0.2);
	TH1D * PVy4 = new TH1D("PVy4","PVy4",300,-0.2,0.2);



	TH1D * BSz1 = new TH1D("BSz1","BSz1",100,-30,30);
	TH1D * BSz2 = new TH1D("BSz2","BSz2",100,-30,30);
	TH1D * BSz3 = new TH1D("BSz3","BSz3",100,-30,30);
	TH1D * BSz4 = new TH1D("BSz4","BSz4",100,-30,30);


	TH1D * BSx1 = new TH1D("BSx1","BSx1",300,-0.2,0.2);
	TH1D * BSx2 = new TH1D("BSx2","BSx2",300,-0.2,0.2);
	TH1D * BSx3 = new TH1D("BSx3","BSx3",300,-0.2,0.2);
	TH1D * BSx4 = new TH1D("BSx4","BSx4",300,-0.2,0.2);

	
	TH1D * BSy1 = new TH1D("BSy1","BSy1",300,-0.2,0.2);
	TH1D * BSy2 = new TH1D("BSy2","BSy2",300,-0.2,0.2);
	TH1D * BSy3 = new TH1D("BSy3","BSy3",300,-0.2,0.2);
	TH1D * BSy4 = new TH1D("BSy4","BSy4",300,-0.2,0.2);





	t1->Project("PVz1","PVz");
	t2->Project("PVz2","PVz");
	t3->Project("PVz3","PVz");
	t4->Project("PVz4","PVz");

	t1->Project("PVx1","PVx");
	t2->Project("PVx2","PVx");
	t3->Project("PVx3","PVx");
	t4->Project("PVx4","PVx");

	t1->Project("PVy1","PVy");
	t2->Project("PVy2","PVy");
	t3->Project("PVy3","PVy");
	t4->Project("PVy4","PVy");


	t1->Project("BSz1","BSz");
	t2->Project("BSz2","BSz");
	t3->Project("BSz3","BSz");
	t4->Project("BSz4","BSz");

	t1->Project("BSx1","BSx");
	t2->Project("BSx2","BSx");
	t3->Project("BSx3","BSx");
	t4->Project("BSx4","BSx");

	t1->Project("BSy1","BSy");
	t2->Project("BSy2","BSy");
	t3->Project("BSy3","BSy");
	t4->Project("BSy4","BSy");




	PVz1->Scale(1.0/PVz1->Integral());
	PVz2->Scale(1.0/PVz2->Integral());
	PVz3->Scale(1.0/PVz3->Integral());
	PVz4->Scale(1.0/PVz4->Integral());

	PVx1->Scale(1.0/PVx1->Integral());
	PVx2->Scale(1.0/PVx2->Integral());
	PVx3->Scale(1.0/PVx3->Integral());
	PVx4->Scale(1.0/PVx4->Integral());

	PVy1->Scale(1.0/PVy1->Integral());
	PVy2->Scale(1.0/PVy2->Integral());
	PVy3->Scale(1.0/PVy3->Integral());
	PVy4->Scale(1.0/PVy4->Integral());



	BSz1->Scale(1.0/BSz1->Integral());
	BSz2->Scale(1.0/BSz2->Integral());
	BSz3->Scale(1.0/BSz3->Integral());
	BSz4->Scale(1.0/BSz4->Integral());

	BSx1->Scale(1.0/BSx1->Integral());
	BSx2->Scale(1.0/BSx2->Integral());
	BSx3->Scale(1.0/BSx3->Integral());
	BSx4->Scale(1.0/BSx4->Integral());

	BSy1->Scale(1.0/BSy1->Integral());
	BSy2->Scale(1.0/BSy2->Integral());
	BSy3->Scale(1.0/BSy3->Integral());
	BSy4->Scale(1.0/BSy4->Integral());




	PVz1->SetLineColor(kBlack);
	PVz2->SetLineColor(kRed);
	PVz3->SetLineColor(kBlue);
	PVz4->SetLineColor(kGreen);

	
	PVx1->SetLineColor(kBlack);
	PVx2->SetLineColor(kRed);
	PVx3->SetLineColor(kBlue);
	PVx4->SetLineColor(kGreen);

	
	PVy1->SetLineColor(kBlack);
	PVy2->SetLineColor(kRed);
	PVy3->SetLineColor(kBlue);
	PVy4->SetLineColor(kGreen);


	BSz1->SetLineColor(kBlack);
	BSz2->SetLineColor(kRed);
	BSz3->SetLineColor(kBlue);
	BSz4->SetLineColor(kGreen);

	
	BSx1->SetLineColor(kBlack);
	BSx2->SetLineColor(kRed);
	BSx3->SetLineColor(kBlue);
	BSx4->SetLineColor(kGreen);

	
	BSy1->SetLineColor(kBlack);
	BSy2->SetLineColor(kRed);
	BSy3->SetLineColor(kBlue);
	BSy4->SetLineColor(kGreen);



	PVz1->GetXaxis()->SetTitle("PVz");
	PVz1->GetYaxis()->SetTitle("Counts");
	PVz1->SetTitle("Normalized PVz Distribution");

	PVx1->GetXaxis()->SetTitle("PVx");
	PVx1->GetYaxis()->SetTitle("Counts");
	PVx1->SetTitle("Normalized PVx Distribution");


	PVy1->GetXaxis()->SetTitle("PVy");
	PVy1->GetYaxis()->SetTitle("Counts");
	PVy1->SetTitle("Normalized PVy Distribution");




	BSz1->GetXaxis()->SetTitle("BSz");
	BSz1->GetYaxis()->SetTitle("Counts");
	BSz1->SetTitle("Normalized BSz Distribution");

	BSx1->GetXaxis()->SetTitle("BSx");
	BSx1->GetYaxis()->SetTitle("Counts");
	BSx1->SetTitle("Normalized BSx Distribution");


	BSy1->GetXaxis()->SetTitle("BSy");
	BSy1->GetYaxis()->SetTitle("Counts");
	BSy1->SetTitle("Normalized BSy Distribution");


	TCanvas *c = new TCanvas("c","c",600,600);
	c->cd();

	PVz1->Draw();
	PVz2->Draw("SAME");
	PVz3->Draw("SAME");
	PVz4->Draw("SAME");




	TLegend * leg = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);

	leg->AddEntry(PVz1,"2018 MC","pl");
	leg->AddEntry(PVz2,"2018 Data","pl");
	leg->AddEntry(PVz3,"2015 MC","pl");
	leg->AddEntry(PVz4,"2015 Data","pl");
	
	leg->Draw("SAME");

	c->SaveAs("PVzDis.png");



	BSz1->Draw();
	BSz2->Draw("SAME");
	BSz3->Draw("SAME");
	BSz4->Draw("SAME");



	TLegend * leg4 = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg4->SetBorderSize(0);
	leg4->SetTextSize(0.04);
	leg4->SetTextFont(42);
	leg4->SetFillStyle(0);

	leg4->AddEntry(BSz1,"2018 MC","pl");
	leg4->AddEntry(BSz2,"2018 Data","pl");
	leg4->AddEntry(BSz3,"2015 MC","pl");
	leg4->AddEntry(BSz4,"2015 Data","pl");
	
	leg4->Draw("SAME");

	c->SaveAs("BSzDis.png");



	PVx1->Draw();
	PVx2->Draw("SAME");
	PVx3->Draw("SAME");
	PVx4->Draw("SAME");

	TLegend * leg2 = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg2->SetBorderSize(0);
	leg2->SetTextSize(0.04);
	leg2->SetTextFont(42);
	leg2->SetFillStyle(0);

	leg2->AddEntry(PVx1,"2018 MC","pl");
	leg2->AddEntry(PVx2,"2018 Data","pl");
	leg2->AddEntry(PVx3,"2015 MC","pl");
	leg2->AddEntry(PVx4,"2015 Data","pl");
	
	leg2->Draw("SAME");

	c->SaveAs("PVxDis.png");



	BSx1->Draw();
	BSx2->Draw("SAME");
	BSx3->Draw("SAME");
	BSx4->Draw("SAME");

	TLegend * leg5 = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg5->SetBorderSize(0);
	leg5->SetTextSize(0.04);
	leg5->SetTextFont(42);
	leg5->SetFillStyle(0);

	leg5->AddEntry(BSx1,"2018 MC","pl");
	leg5->AddEntry(BSx2,"2018 Data","pl");
	leg5->AddEntry(BSx3,"2015 MC","pl");
	leg5->AddEntry(BSx4,"2015 Data","pl");
	
	leg5->Draw("SAME");

	c->SaveAs("BSxDis.png");




	PVy1->Draw();
	PVy2->Draw("SAME");
	PVy3->Draw("SAME");
	PVy4->Draw("SAME");

	TLegend * leg3 = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg3->SetBorderSize(0);
	leg3->SetTextSize(0.04);
	leg3->SetTextFont(42);
	leg3->SetFillStyle(0);

	leg3->AddEntry(PVy1,"2018 MC","pl");
	leg3->AddEntry(PVy2,"2018 Data","pl");
	leg3->AddEntry(PVy3,"2015 MC","pl");
	leg3->AddEntry(PVy4,"2015 Data","pl");
	
	leg3->Draw("SAME");

	c->SaveAs("PVyDis.png");


	BSy1->Draw();
	BSy2->Draw("SAME");
	BSy3->Draw("SAME");
	BSy4->Draw("SAME");

	TLegend * leg6 = new TLegend(0.20,0.68,0.37,0.88,NULL,"brNDC");
	leg6->SetBorderSize(0);
	leg6->SetTextSize(0.04);
	leg6->SetTextFont(42);
	leg6->SetFillStyle(0);

	leg6->AddEntry(BSy1,"2018 MC","pl");
	leg6->AddEntry(BSy2,"2018 Data","pl");
	leg6->AddEntry(BSy3,"2015 MC","pl");
	leg6->AddEntry(BSy4,"2015 Data","pl");
	
	leg6->Draw("SAME");

	c->SaveAs("BSyDis.png");




}


