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
#include "Reweightparameters.h"

//#include "his.h"
using namespace std;

using std::cout;
using std::endl;
#endif



void Reweight(){

	TCanvas* c = new TCanvas("c","",600,600);
	c->cd();
	TFile * fout = new TFile(output.Data(),"RECREATE");


	fout->cd();
	for(int i= 0; i < NWeightUsed ;i++)
	{

		f1[i] = new TF1(Form("f1_%d",i),Function[i].Data(),RangeMin[i],RangeMax[i]);	
		f1[i]->SetParLimits(0,-20,20);
		f1[i]->SetParLimits(1,-1,1);
		f1[i]->SetParLimits(2,-3,3);
		if(i != 1) f1[i]->SetParLimits(3,-0.1,0.1);

		ofstream out(Form("Fit_%d.dat",i));
		YRatioGMC[i]= (TH1D *) fin->Get(RatioVar[i].Data());

		YRatioGMC[i]->Fit(f1[i],"R");
		cout << Form("%s Reweight Function",WeightVar[i].Data()) << endl;
		if(i == 0) Func = Form("%f + %f * %s + %f * %s ** 2 +  %f * %s ** 3",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data(),f1[i]->GetParameter(2),WeightVar[i].Data(),f1[i]->GetParameter(3),WeightVar[i].Data());
		if(i == 1) Func = Form("%f * TMath::Exp(- %f * (%s - %f)*(%s - %f))",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data(),f1[i]->GetParameter(2),WeightVar[i].Data(),f1[i]->GetParameter(2));
		if(i == 2) Func = Form("%f * TMath::Exp(-%f * %s)",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data());

		
		//		Func = Form("(%f + %f * %s + %f * %s ** 2)*TMath::Exp(-%f*(%s - %f)**2)+%f",f1->GetParameter(0),f1->GetParameter(1),WeightVar[i].Data(),f1->GetParameter(2),WeightVar[i].Data(),f1->GetParameter(3),WeightVar[i].Data(),f1->GetParameter(4),f1->GetParameter(5));


		cout << Func.Data() << endl;
		cout << "---------------------------------------------------------" << endl;

		if(i ==0 ) out<< Form("%s Reweight Function",WeightVar[i].Data())  <<" "<<   Form("%f + (%f) * %s +( %f) * %s ** 2 +  (%f) * %s ** 3",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data(),f1[i]->GetParameter(2),WeightVar[i].Data(),f1[i]->GetParameter(3),WeightVar[i].Data()) << endl;
		if(i == 1)  out<< Form("%s Reweight Function",WeightVar[i].Data())  <<" "<<   Form("%f * TMath::Exp(- %f * (%s - %f)*(%s - %f))",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data(),f1[i]->GetParameter(2),WeightVar[i].Data(),f1[i]->GetParameter(2)) << endl;
		if(i ==2 ) out<<Form("%f * TMath::Exp(-%f * %s)",f1[i]->GetParameter(0),f1[i]->GetParameter(1),WeightVar[i].Data()) << endl;

		//		out<< Form("%s Reweight Function",WeightVar[i].Data())  <<" "<<   Form("(%f + %f * %s + %f * %s ** 2)*TMath::Exp(-%f*(%s - %f)**2)+%f",f1->GetParameter(0),f1->GetParameter(1),WeightVar[i].Data(),f1->GetParameter(2),WeightVar[i].Data(),f1->GetParameter(3),WeightVar[i].Data(),f1->GetParameter(4),f1->GetParameter(5)) << endl;

		YRatioGMC[i]->SetMinimum(0);
		YRatioGMC[i]->SetMaximum(5);
		YRatioGMC[i]->Draw("ep");
		f1[i]->Draw("epSAME");
		leg[i]= new TLegend(0.55,0.63,0.72,0.88,NULL,"brNDC");
		leg[i]->SetBorderSize(0);
		leg[i]->SetTextSize(0.04);
		leg[i]->SetTextFont(42);
		leg[i]->SetFillStyle(0);
		leg[i]->AddEntry(YRatioGMC[i],Form("%s MC/Data Ratio",WeightVar[i].Data()),"pl");
		leg[i]->AddEntry(f1[i],"3rd Reweighting Fits","pl");
		leg[i]->Draw("SAME");
		leg[i]->Clear();
		c->SaveAs(Form("Plots/Weight_%s.png",WeightVar[i].Data()));

		YRatioGMC[i]->Write();

	}


}


