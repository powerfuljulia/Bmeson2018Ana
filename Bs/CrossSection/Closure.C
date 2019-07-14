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

void Closure(TString collyst, TString infile, TString eff, TString oufile){
	gStyle->SetOptStat(0); 

	TFile *fin = new TFile(infile.Data());
	TFile *Eff = new TFile(eff.Data());

	TH1D* FitHis = (TH1D *) fin->Get("hPt");
	TH1D* FitEff = (TH1D *) Eff->Get("hEff");
	TH1D* MCHis = (TH1D *) fin->Get("hPtGen");


	FitHis->Sumw2();
	FitEff->Sumw2();
	MCHis->Sumw2();

	TH1D * ClosureHis = (TH1D *) FitHis->Clone("ClosureHis");
	ClosureHis->Divide(FitEff);
	ClosureHis->Divide(MCHis);


	TCanvas* c= new TCanvas("c","",600,600);
	c->cd();
	ClosureHis->Draw("ep");
	ClosureHis->SetLineColor(kBlue);
	ClosureHis->SetMarkerSize(3);
	ClosureHis->GetXaxis()->SetTitle("B_{S} p_{T} (GeV/c)");
	ClosureHis->GetYaxis()->SetTitle("Corrected Yield/GenYield");
	ClosureHis->Draw("ep");

	TFile * fout = new TFile(oufile.Data(),"RECREATE");
	fout->cd();
	ClosureHis->Write();
	c->SaveAs(Form("plotEff/Closure_%s.pdf",collyst.Data()));


}

int main(int argc, char *argv[])
{
	if((argc !=5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 5){
		Closure(argv[1],argv[2],argv[3],argv[4]);
	return 0;
}
}








