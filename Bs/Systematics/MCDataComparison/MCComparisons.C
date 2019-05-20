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
using namespace std;

using std::cout;
using std::endl;
#endif



void MCComparisons(TString ppEff, TString pPbEff, TString outname, TString outfile)
{



TFile *finppMC = new TFile(ppEff.Data());
TFile *finpPbMC = new TFile(pPbEff.Data());

cout << "Pass " << endl;

TH1D * hppMC = (TH1D*) finppMC->Get("hEff");
TH1D * hpPbMC = (TH1D*) finpPbMC->Get("hEff");

hppMC->Sumw2();
hpPbMC->Sumw2();

TH1D * Ratio = (TH1D *) hppMC->Clone();

Ratio->Sumw2();

Ratio->Divide(hpPbMC);

TCanvas *c = new TCanvas("c","c",600,600);
c->cd();

Ratio->GetYaxis()->SetTitle("pp Eff/pPb Eff");
Ratio->SetTitle("pp MC Eff - pPb MC Eff Ratio with pPb cuts");

Ratio->Draw();

c->SaveAs(outname.Data());

TFile *fout = new TFile(outfile.Data(),"RECREATE");

fout->cd();

Ratio->Write();

fout->Close();

}



int main(int argc, char *argv[])
{
	if((argc !=5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 5){
		MCComparisons(argv[1],argv[2],argv[3],argv[4]);
		return 0;
	}
}



