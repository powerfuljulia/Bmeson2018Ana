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


void ShapeVariation(TString collsyst, TString inputdata, TString CommonCut){


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



	TH1D * HisBData[NVar];
	const int NMassBin = 5;
	TString MassCut;

	TH1D * HisBkgdData[NVar][NMassBin];



	for(int j = 0; j < NBins;j++){
		cout << "ptL = " << ptBins[j] << "  ptU = " << ptBins[j+1] << endl;

		TString ptCuts = Form("(Bpt > %f && Bpt < %f)",ptBins[j],ptBins[j+1]);



		TFile *fin = new TFile(inputdata.Data());



		TTree* nt = (TTree*) fin->Get("Bfinder/ntKp");
		nt->AddFriend("hltanalysis/HltTree");
		nt->AddFriend("hiEvtAnalyzer/HiTree");  
		nt->AddFriend("skimanalysis/HltTree");





		TCanvas *c2 = new TCanvas("c2","c2",600,600);
		c2->cd();


		TH1D * MassData = new TH1D("MassData","MassData",50,4.8,5.8);
		nt->Project("MassData","Bmass",Form("(%s) &&(%s)",CommonCut.Data(),ptCuts.Data()));
		MassData->SetMinimum(0);
		MassData->GetXaxis()->SetTitle("B^{0}_{S} mass (GeV/c)");
		MassData->GetYaxis()->SetTitle("Counts");
		MassData->SetTitle("B^{0}_{S} Invariant Mass Distribution");

		MassData->Draw();

		double YMax = MassData->GetMaximum();


		TLine *l1 = new TLine(center-sidemax,0,center-sidemax,YMax);
		l1->SetLineWidth(1);
		l1->SetLineColor(kRed);
		l1->Draw("same");

		TLine *l2 = new TLine(center-sidemin,0,center-sidemin,YMax);
		l2->SetLineWidth(1);
		l2->SetLineColor(kRed);
		l2->Draw("same");

		TLine *l3 = new TLine(center-width,0,center-width,YMax);
		l3->SetLineWidth(1);
		l3->SetLineColor(kRed);
		l3->Draw("same");

		TLine *l4 = new TLine(center+width,0,center+width,YMax);
		l4->SetLineWidth(1);
		l4->SetLineColor(kRed);
		l4->Draw("same");

		TLine *l5 = new TLine(center+sidemin,0,center+sidemin,YMax);
		l5->SetLineWidth(1);
		l5->SetLineColor(kRed);
		l5->Draw("same");

		TLine *l6 = new TLine(center+sidemax,0,center+sidemax,YMax);
		l6->SetLineWidth(1);
		l6->SetLineColor(kRed);
		l6->Draw("same");

		c2->SaveAs("Plots/Extra/MassPlot.png");


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
			HisBData[i] = new TH1D(VarBData[i].Data(),VarBData[i].Data(),Binning[i],Min[i],Max[i]);
			leg[i]= new TLegend(0.30,0.68,0.47,0.88,NULL,"brNDC");

			leg[i]->SetBorderSize(0);
			leg[i]->SetTextSize(0.04);
			leg[i]->SetTextFont(42);
			leg[i]->SetFillStyle(0);
			HisBData[i]->GetXaxis()->SetTitle(XName[i].Data());
			HisBData[i]->GetYaxis()->SetTitle(YName[i].Data());
			HisBData[i]->SetLineWidth(2);


			for(int k = 0; k < NMassBin; k++){

				cout << "k = " << k << endl;
				double MassMin = -0.28 + 0.1 * k;
				double MassMax = -0.18 + 0.1 * k;
				double MassUp =  5.27925 + MassMax;
				double MassDown =  5.27925 + MassMin;

				MassCut = Form("Bmass -  5.27925 < %.2f && Bmass -  5.27925 > %.2f ",MassMax,MassMin);

				nt->Project(VarBData[i].Data(),Var[i].Data(),Form("(%s) && (%s)",CommonCut.Data(),MassCut.Data()));

				HisBData[i]->SetTitle(Form("%s%d",HisName[i].Data(),k));
				HisBkgdData[i][k] = (TH1D *) HisBData[i]->Clone();
				HisBkgdData[i][k]->SetLineColor(k+2);
				HisBkgdData[i][k]->SetLineWidth(2);
			
				cout << "HisBkgdData[i][k] Total = " << HisBkgdData[i][k]->Integral() << endl;
				HisBkgdData[i][k]->Scale(1.0/HisBkgdData[i][k]->Integral());

				leg[i]->AddEntry(HisBkgdData[i][k],Form("Bmass < %.2f && Bmass > %.2f",MassUp,MassDown),"pl");
				if(k == 0) HisBkgdData[i][k]->Draw();
				if(k > 0) HisBkgdData[i][k]->Draw("SAME");
			}

			leg[i]->Draw("SAME");

			FileName = Form("Shape/%s_%s_%d.pdf",Name[i].Data(),collsyst.Data(),j);
			c->SaveAs(FileName.Data());

		}
	}



}

int main(int argc, char *argv[])
{
	if((argc !=4))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 4)
		ShapeVariation(argv[1],argv[2],argv[3]);
	return 0;
}


