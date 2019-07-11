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

//#include "his.h"
using namespace std;

using std::cout;
using std::endl;


void ReweightBpt(TString inputMC,TString inputFONLL){

	gStyle->SetOptStat(0); 
	TCanvas * c = new TCanvas("c","c",1800,600);
	c->Divide(3,1);
	TCut weighpthat = "(pthatweight)";
	TCut GenCut ="(TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0 && GcollisionId==0)";


	TFile *finMC = new TFile(inputMC.Data());
	TFile *finFONLL = new TFile(inputFONLL.Data());

	TTree * tMC = (TTree*) finMC->Get("Bfinder/ntGen");
	tMC->AddFriend("hltanalysis/HltTree");
	tMC->AddFriend("hiEvtAnalyzer/HiTree");  
	tMC->AddFriend("skimanalysis/HltTree");


	TH1D * GptMC = new TH1D("GptMC","GptMC",21,5,105);
	GptMC->GetYaxis()->SetTitleOffset(1.1);

	tMC->Project("GptMC","Gpt",TCut(weighpthat)*TCut(GenCut));
	GptMC->GetXaxis()->SetTitle("Gen p_{T} (GeV)");
	GptMC->GetYaxis()->SetTitle("PYTHIA, #entries ");
	GptMC->SetTitle("");
	GptMC->Sumw2();
	GptMC->Scale(1.0/GptMC->Integral());
	GptMC->SetMarkerStyle(20);
	GptMC->SetMarkerColor(kBlack);
	GptMC->SetMarkerSize(1);
	c->cd(1);
	gPad->SetLogy();
	GptMC->Draw("ep");



	TH1D * GptFONLL = (TH1D * ) finFONLL->Get("hpt");
	GptFONLL->GetYaxis()->SetTitleOffset(1.1);
	GptFONLL->GetXaxis()->SetTitle("FONLL p_{T} (GeV)");
	GptFONLL->GetYaxis()->SetTitle("FONLL_pp, #entries ");
	GptFONLL->Sumw2();
	GptFONLL->Scale(1.0/GptFONLL->Integral());
	GptFONLL->SetMarkerStyle(20);
	GptFONLL->SetMarkerColor(kBlack);
	GptFONLL->SetMarkerSize(1);
	c->cd(2);
	gPad->SetLogy();
	GptFONLL->Draw("ep");


	TH1D * BptRatio = (TH1D *) GptFONLL->Clone("BptRatio");
	BptRatio->GetYaxis()->SetTitleOffset(1.1); 
	BptRatio->Divide(GptMC);
	c->cd(3);

	TF1 * f1 = new TF1("f1","[3]*TMath::Exp(-[0]*x)+[1]/(x*x+[2]*[2])",5,105);
	f1->SetParLimits(0,0,1);
	f1->SetParLimits(1,10,100);
	f1->SetParLimits(2,0,0.01);
	f1->SetParLimits(3,0,10);


	BptRatio->Fit(f1,"R");
	BptRatio->GetXaxis()->SetTitle("B_{s}^{0} p_{T}");
	BptRatio->GetYaxis()->SetTitle("FONLL_pp/PYTHIA");
	BptRatio->SetMarkerStyle(20);
	BptRatio->SetMarkerColor(kBlack);
	BptRatio->SetMarkerSize(1);
	BptRatio->Draw("ep");

	float Chi2 =  f1->GetChisquare();
	int nDOF = f1->GetNDF();
    float nChi2 =  Chi2/nDOF;
   // float nChi2 = f->GetChisquare();
	int nDigit_chi2BakerCousins = 2;
    int nDigit_nChi2 = 2;
    nChi2 = roundToNdigit(nChi2);
    nDigit_chi2BakerCousins = 2;

	cout << "Chi2 = " <<  Chi2 << "  nChi2 = " << nChi2 << endl;

    nDigit_nChi2 = sigDigitAfterDecimal(nChi2);
    TLatex* texChi = new TLatex(0.35,0.70, Form("#chi^{2}/nDOF: %.*f/%d = %.*f", nDigit_chi2BakerCousins, Chi2, nDOF, nDigit_nChi2, nChi2));
	texChi->SetNDC();
	texChi->SetTextAlign(12);
	texChi->SetTextSize(0.04);
	texChi->SetTextFont(42);
	texChi->Draw("SAME");

	//GptFONLL->Draw("ep");
	//
	//
	TString BptReweightFunc = Form("%f*TMath::Exp(-%f*Bpt)+%f/(Bpt*Bpt+%f*%f)",f1->GetParameter(3),f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));

	cout << "Bpt Func = " << BptReweightFunc.Data() << endl;

	c->SaveAs("plotReweight/BptReweigt.png");
	c->SaveAs("plotReweight/BptReweigt.pdf");



}

int main(int argc, char *argv[])
{
	if((argc !=3))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 3)
		ReweightBpt(argv[1],argv[2]);
	return 0;
}


