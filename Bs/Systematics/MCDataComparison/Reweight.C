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



void Reweight(TString input,TString output){


	TFile *fin = new TFile(input.Data());

	TH1D * YRatioYMC[NVar];
	TH1D * YRatioGMC[NVar];
	

	TF1 *f1 = new TF1("f1","[0]+[1]*x+[2]*x*x+[3]*x*x*x");
	//int j;
	TString Func;
	TLegend* leg[2];
	f1->SetParLimits(0,-5,5);
	f1->SetParLimits(1,-1,1);
	f1->SetParLimits(2,-0.1,0.1);
	f1->SetParLimits(3,-0.05,0.05);
	TCanvas* c = new TCanvas("c","",1200,1200);
	c->cd();
	c->Divide(2,2);
	TFile * fout = new TFile(output.Data(),"RECREATE");


	fout->cd();
	for(int i= 0; i < 2 ;i++)
	{
		/*
		   HisYDatapp[i] = (TH1D *) fin->Get(VarGMCpp[i].Data());
		   HisYDatapPb[i] = (TH1D *) fin->Get(VarGMCpPb[i].Data());
		   HisGMCpp[i] = (TH1D *) fin->Get(VarGMCpp[i].Data());
		   HisGMCpPb[i] = (TH1D *) fin->Get(VarGMCpPb[i].Data());

		

		//	ppppDataRatio[i]->Sumw2();
		ppppDataRatio[i] = (TH1D * ) HisYDatapp[i]->Clone(ppppRatioName[i].Data()); 
		ppppDataRatio[i]->Sumw2();
		HisGMCpp[i]->Sumw2();
		ppppDataRatio[i]->Divide(HisGMCpp[i]);


		//		pppPbDataRatio[i]->Sumw2();
		pppPbDataRatio[i] = (TH1D * ) HisYDatapp[i]->Clone(pppPbRatioName[i].Data()); 
		pppPbDataRatio[i]->Sumw2();
		HisGMCpPb[i]->Sumw2();
		pppPbDataRatio[i]->Divide(HisGMCpPb[i]);

		//		pPbppDataRatio[i]->Sumw2();
		pPbppDataRatio[i] = (TH1D * ) HisYDatapPb[i]->Clone(pPbppRatioName[i].Data()); 
		pPbppDataRatio[i]->Sumw2();
		HisGMCpp[i]->Sumw2();
		pPbppDataRatio[i]->Divide(HisGMCpp[i]);

		//		pPbpPbDataRatio[i]->Sumw2();
		pPbpPbDataRatio[i] = (TH1D * ) HisYDatapPb[i]->Clone(pPbpPbRatioName[i].Data()); 
		pPbpPbDataRatio[i]->Sumw2();
		HisGMCpPb[i]->Sumw2();
		pPbpPbDataRatio[i]->Divide(HisGMCpPb[i]);
		*/
		ofstream out(Form("Fit_%d.dat",i));
		ppppDataRatio[i]= (TH1D *) fin->Get(ppppRatioName[i].Data());
		pppPbDataRatio[i] = (TH1D *) fin->Get(pppPbRatioName[i].Data());
		pPbppDataRatio[i] = (TH1D *) fin->Get(pPbppRatioName[i].Data());
		pPbpPbDataRatio[i] = (TH1D *) fin->Get(pPbpPbRatioName[i].Data());

		ppppDataRatio[i]->Fit(f1);
		cout << "pp-pp Reweight Function" << endl;
		Func = Form("%f + %f * %s + %f * %s ** 2 +  %f * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data());
		cout << Func.Data() << endl;
		cout << "---------------------------------------------------------" << endl;

		out<< Form("pp-pp %s Reweight Function",Var[i].Data())  <<" "<<   Form("%f + (%f) * %s +( %f) * %s ** 2 +  (%f) * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data()) << endl;

		ppppDataRatio[i]->SetMinimum(0);
		ppppDataRatio[i]->SetMaximum(2);
		ppppDataRatio[i]->Draw("ep");
		f1->Draw("epSAME");
		leg[i]= new TLegend(0.55,0.63,0.72,0.88,NULL,"brNDC");
		leg[i]->SetBorderSize(0);
		leg[i]->SetTextSize(0.04);
		leg[i]->SetTextFont(42);
		leg[i]->SetFillStyle(0);
		leg[i]->AddEntry(ppppDataRatio[i],"pp MC/pp Data Ratio","pl");
		leg[i]->AddEntry(f1,"3rd Reweighting Fits","pl");
		leg[i]->Draw("SAME");
		leg[i]->Clear();
		c->SaveAs(Form("Plots/ppppRatio_%s.pdf",Var[i].Data()));

		pppPbDataRatio[i]->Fit(f1);
		cout << "pp-pPb Reweight Function" << endl;
		Func = Form("%f + %f * %s + %f * %s ** 2 +  %f * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data());
		cout << Func.Data() << endl;
		cout << "---------------------------------------------------------" << endl;
		out<< Form("pp-pPb %s Reweight Function",Var[i].Data())  <<" "<<  Form("%f + (%f) * %s +(%f) * %s ** 2 +  (%f) * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data()) << endl;

		pppPbDataRatio[i]->SetMinimum(0);
		pppPbDataRatio[i]->SetMaximum(2);
		pppPbDataRatio[i]->Draw("ep");
		f1->Draw("epSAME");
		leg[i]= new TLegend(0.55,0.63,0.72,0.88,NULL,"brNDC");
		leg[i]->SetBorderSize(0);
		leg[i]->SetTextSize(0.04);
		leg[i]->SetTextFont(42);
		leg[i]->SetFillStyle(0);
		leg[i]->AddEntry(pppPbDataRatio[i],"pp MC/pPb Data Ratio","pl");
		leg[i]->AddEntry(f1,"3rd Reweighting Fits","pl");
		leg[i]->Draw("SAME");
		leg[i]->Clear();
		c->SaveAs(Form("Plots/pppPbRatio_%s.pdf",Var[i].Data()));




		pPbppDataRatio[i]->Fit(f1);
		cout << "pPb-pp Reweight Function" << endl;
		Func = Form("%f + %f * %s + %f * %s ** 2 +  %f * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data());
		cout << Func.Data() << endl;
		cout << "---------------------------------------------------------" << endl;
		out<< Form("pPb-pp %s Reweight Function",Var[i].Data())  <<" "<<  Form("%f + (%f) * %s + (%f) * %s ** 2 + ( %f) * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data()) << endl;

		pPbppDataRatio[i]->SetMinimum(0);
		pPbppDataRatio[i]->SetMaximum(2);
		pPbppDataRatio[i]->Draw("ep");
		f1->Draw("epSAME");
		leg[i]= new TLegend(0.55,0.63,0.72,0.88,NULL,"brNDC");
		leg[i]->SetBorderSize(0);
		leg[i]->SetTextSize(0.04);
		leg[i]->SetTextFont(42);
		leg[i]->SetFillStyle(0);
		leg[i]->AddEntry(pPbppDataRatio[i],"pPb MC/pp Data Ratio","pl");
		leg[i]->AddEntry(f1,"3rd Reweighting Fits","pl");
		leg[i]->Draw("SAME");
		leg[i]->Clear();
		c->SaveAs(Form("Plots/pPbppRatio_%s.pdf",Var[i].Data()));




		pPbpPbDataRatio[i]->Fit(f1);
		cout << "pPb-pPb Reweight Function" << endl;
		Func = Form("%f + %f * %s + %f * %s ** 2 +  %f * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data());
		cout << Func.Data() << endl;
		cout << "---------------------------------------------------------" << endl;
		out<< Form("pPb-pPb %s Reweight Function",Var[i].Data())  <<" "<<   Form("%f + (%f) * %s + (%f) * %s ** 2 + ( %f) * %s ** 3",f1->GetParameter(0),f1->GetParameter(1),Var[i].Data(),f1->GetParameter(2),Var[i].Data(),f1->GetParameter(3),Var[i].Data()) << endl;

		pPbpPbDataRatio[i]->SetMinimum(0);
		pPbpPbDataRatio[i]->SetMaximum(2);
		pPbpPbDataRatio[i]->Draw("ep");
		f1->Draw("epSAME");
		leg[i]= new TLegend(0.55,0.63,0.72,0.88,NULL,"brNDC");
		leg[i]->SetBorderSize(0);
		leg[i]->SetTextSize(0.04);
		leg[i]->SetTextFont(42);
		leg[i]->SetFillStyle(0);
		leg[i]->AddEntry(pPbpPbDataRatio[i],"pPb MC/pPb Data Ratio","pl");
		leg[i]->AddEntry(f1,"3rd Reweighting Fits","pl");
		leg[i]->Draw("SAME");
		leg[i]->Clear();
		c->SaveAs(Form("Plots/pPbpPbRatio_%s.pdf",Var[i].Data()));

		ppppDataRatio[i]->Write();
		pppPbDataRatio[i]->Write();
		pPbppDataRatio[i]->Write();
		pPbpPbDataRatio[i]->Write();
		//out->Close();
	}


}

int main(int argc, char* argv[])
{
	if(argc==3)
	{
		Reweight(argv[1],argv[2]);
		return 0;
	}
	else
	{
		cout<<"  Error: invalid arguments number."<<endl;
		return 1;
	}
}
