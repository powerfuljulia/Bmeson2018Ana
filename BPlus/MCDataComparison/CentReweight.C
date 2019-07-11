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

		//PVzWeight =	"1.055564 * TMath::Exp(-0.001720 * (Pvz + 2.375584)*(Pvz + 2.375584))";
	PVzWeight = "(0.164847 * TMath::Exp(- 0.021378 * (vz - 0.342927)*(vz - 0.342927)))/(0.159507 * TMath::Exp(- 0.019986 * (vz - 0.601387)*(vz - 0.601387)))";
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
	NCollHis->GetXaxis()->SetTitle("hiBin");
	NCollHis->GetYaxis()->SetTitle("NColl");
	NCollHis->SetTitle("NColl vs hiBin");

	TCanvas *cAll = new TCanvas("cAll","cAll",1800,600);
	cAll->Divide(3,1);


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
	c->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/CentWeight/CentDataNcoll.png");
	
	cAll->cd(1);
	CentData->Draw("ep");
	NCollHis->Draw("epSAME");
	legDataNColl->Draw("SAME");




	CentMC->SetMarkerSize(1.5);
	CentMC->SetMarkerStyle(23);
	CentMC->SetMarkerColor(kRed);


	CentData->SetTitle("Centrality Distribution Comparison Before NColl Correction");

	CentData->SetMaximum(0.1);
	CentData->SetMinimum(0.0);
	

	TCanvas *c2 = new TCanvas("c2","c2",600,600);
	c2->cd();

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

	c2->SaveAs("CentWeight/CentBeforeNColl.png");
	c2->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/CentWeight/CentBeforeNColl.png");
	CentData->SetTitle("Centrality Distribution Comparison After NColl Correction");

	cAll->cd(2);
	CentData->Draw("ep");
	CentMC->Draw("epSAME");
	leg->Draw("SAME");

	TCanvas *c3 = new TCanvas("c3","c3",600,600);
	c3->cd();

	if(Method == 0){

	NCollHis->Sumw2();
	CentMC->Multiply(NCollHis);
	CentMC->Sumw2();
	CentMC->Scale(1.0/CentMC->Integral());


	CentData->Sumw2();
	CentMC->Sumw2();




	leg2->SetBorderSize(0);
	leg2->SetTextSize(0.04);
	leg2->SetTextFont(42);
	leg2->SetFillStyle(0);
	leg2->AddEntry(CentData,"Data","pl");
	leg2->AddEntry(CentMC,"MC","pl");
	leg2->Draw("SAME");


	CentData->Draw("ep");
	CentMC->Draw("hist p SAME");
	leg2->Draw("SAME");


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

		c3->SaveAs("CentWeight/CentAfterNColl.png");
		c3->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/CentWeight/CentAfterNColl.png");

	
		cAll->cd(3);
		CentData->Draw("ep");
		CentMCNew->Draw("hist p SAME");
		leg->Draw("SAME");
	
	}

	
	cAll->SaveAs("CentWeight/CentralityWeight.pdf");
	cAll->SaveAs("/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/CrossSection/CentWeight/CentralityWeight.pdf");




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


