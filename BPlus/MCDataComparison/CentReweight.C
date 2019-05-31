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
#include "Centparameters.h"

//#include "his.h"
using namespace std;

using std::cout;
using std::endl;




void CentReweight(TString collsyst, TString inputdata, TString inputMC, int doweight){
	
	int Method = 1;

	gStyle->SetOptStat(0); 

	TFile * fin = new TFile(inputdata.Data());
	TFile * finMC = new TFile(inputMC.Data());


	TTree * t = (TTree * )fin->Get("hiEvtAnalyzer/HiTree");
	TTree * tMC = (TTree * )finMC->Get("hiEvtAnalyzer/HiTree");




	//t->AddFriend("Bfinder/ntKp");
	//tMC->AddFriend("Bfinder/ntKp");


	TString PVzWeight;
	TString Pthatweight;
	
	if(collsyst == "pp") Pthatweight="(1)";


	if(collsyst == "PbPb") Pthatweight="(pthatweight)";




	if(doweight == 0){
			

		Pthatweight = "1";
	
	}


	if(doweight == 1){

		PVzWeight =	"1.055564 * TMath::Exp(-0.001720 * (vz + 2.375584)*(vz + 2.375584))";
	}


	TH1D * CentMC = new TH1D("CentMC","CentMC",nbins,0,nbins);
	CentMC->GetXaxis()->SetTitle("hiBin");
	CentMC->GetYaxis()->SetTitle("Normalized Counts");
	CentMC->SetTitle("Centrality Distribution");


	TH1D * CentData = new TH1D("CentData","CentData",nbins,0,nbins);
	CentData->GetXaxis()->SetTitle("hiBin");
	CentData->GetYaxis()->SetTitle("Normalized Counts");
	CentData->SetTitle("Centrality Distribution");

	TH1D * NCollHis = new TH1D("NCollHis","NCollHis",nbins,0,nbins);
	CentMC->GetXaxis()->SetTitle("hiBin");
	CentMC->GetYaxis()->SetTitle("NColl");
	CentMC->SetTitle("NColl vs hiBin");


	for(int i = 0; i < nbins; i ++){

		NCollHis->SetBinContent(i+1,Ncoll[i]);

	}
	
	TCanvas *c = new TCanvas("c","c",600,600);
	c->cd();
	NCollHis->Draw();
	c->SaveAs("CentWeight/NColl.png");


	t->Project("CentData","hiBin");
	tMC->Project("CentMC","hiBin",TCut(PVzWeight.Data())*TCut(Pthatweight.Data()));
	
	CentData->Sumw2();
	CentData->Scale(1.0/CentData->Integral());


	CentMC->Sumw2();
	CentMC->Scale(1.0/CentMC->Integral());

	CentData->SetMarkerSize(1.5);
	CentData->SetMarkerStyle(22);
	CentData->SetMarkerColor(kBlue);


	CentData->Sumw2();
	CentData->SetTitle("Centrality Distribution Comparison Data -  NColl");	
	CentData->Draw("ep");

	NCollHis->SetMarkerSize(1.5);
	NCollHis->SetMarkerStyle(23);
	NCollHis->SetMarkerColor(kGreen);

	NCollHis->Sumw2();
	NCollHis->Scale(1.0/NCollHis->Integral());
	NCollHis->Sumw2();	
	NCollHis->Draw("epSAME");


	legDataNColl->SetBorderSize(0);
	legDataNColl->SetTextSize(0.04);
	legDataNColl->SetTextFont(42);
	legDataNColl->SetFillStyle(0);
	legDataNColl->AddEntry(CentData,"Data","pl");
	legDataNColl->AddEntry(NCollHis,"NColl","pl");
	legDataNColl->Draw("SAME");

	c->SaveAs("CentWeight/CentDataNcoll.png");




	CentMC->SetMarkerSize(1.5);
	CentMC->SetMarkerStyle(23);
	CentMC->SetMarkerColor(kRed);


	CentData->SetTitle("Centrality Distribution Comparison Before NColl Correction");

	CentData->SetMaximum(0.1);
	CentData->SetMinimum(0.0);

	CentMC->Sumw2();
	CentData->Sumw2();
	CentData->Draw("ep");
	CentMC->Draw("epSAME");

	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(CentData,"Data","pl");
	leg->AddEntry(CentMC,"MC","pl");
	leg->Draw("SAME");

	c->SaveAs("CentWeight/CentBeforeNColl.png");
	CentData->SetTitle("Centrality Distribution Comparison After NColl Correction");


	if(Method == 0){

	NCollHis->Sumw2();
	CentMC->Multiply(NCollHis);
	CentMC->Sumw2();
	CentMC->Scale(1.0/CentMC->Integral());


	CentData->Sumw2();
	CentMC->Sumw2();

	CentData->Draw("ep");
	CentMC->Draw("hist p SAME");
	leg->Draw("SAME");

	c->SaveAs("CentWeight/CentAfterNColl.png");
	}



	if(Method == 1){
		TH1D * CentMCNew = new TH1D("CentMCNew","CentMCNew",nbins,0,nbins);
		CentMCNew->GetXaxis()->SetTitle("hiBin");
		CentMCNew->GetYaxis()->SetTitle("Normalized Counts");
		CentMCNew->SetTitle("Centrality Distribution");

		int Cent;
		tMC->SetBranchAddress("hiBin",&Cent);

		for(int i = 0; i < tMC->GetEntries(); i++){
			tMC->GetEntry(i);
			CentMCNew->Fill(Cent,Ncoll[Cent]);
		}

		CentMCNew->Sumw2();
		CentMCNew->Scale(1.0/CentMCNew->Integral());

		CentMCNew->SetMarkerSize(1.5);
		CentMCNew->SetMarkerStyle(23);
		CentMCNew->SetMarkerColor(kRed);

	
		CentData->Draw("ep");
		CentMCNew->Sumw2();	
		CentMCNew->Draw("epSAME");

		leg->Draw("SAME");
		c->SaveAs("CentWeight/CentAfterNColl2.png");
	}


}


int main(int argc, char *argv[])
{
	if((argc !=5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 5)
		CentReweight(argv[1],argv[2],argv[3],atoi(argv[4]));
	return 0;
}


