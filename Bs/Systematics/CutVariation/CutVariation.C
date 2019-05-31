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
#include "parameters.h"
#include "fitB.h"
using namespace std;

using std::cout;
using std::endl;
#endif



void CutVariation(TString collsyst, TString inputdata, TString inputMC, TString PreCut){
	gStyle->SetOptStat(0); 

	TCanvas * c = new TCanvas("c","c",600,600);
	TCanvas * cMC = new TCanvas("cMC","cMC",600,600);


	if(collsyst == "pp") weightfunctionreco="(pthatweight)*(maxDgenpt<pthat/1.2)*(0.0116437+Dgenpt*(0.0602697)+Dgenpt*Dgenpt*(-0.00226879)+Dgenpt*Dgenpt*Dgenpt*(3.91035e-05)+Dgenpt*Dgenpt*Dgenpt*Dgenpt*(-3.0699e-07)+Dgenpt*Dgenpt*Dgenpt*Dgenpt*Dgenpt*(8.73234e-10))";


	if(collsyst == "PbPb") weightfunctionreco="pthatweight";

	if(collsyst = "pp") isPbPb = 0;
	if(collsyst = "PbPb") isPbPb = 1;

	TFile *fin = new TFile(inputdata.Data());
	TFile *finMC = new TFile(inputMC.Data());


	cout << "weightfunctionreco = " << weightfunctionreco.Data() << endl;
	TTree* nt = (TTree*) fin->Get("Bfinder/ntphi");
	nt->AddFriend("hltanalysis/HltTree");
	nt->AddFriend("hiEvtAnalyzer/HiTree");
	nt->AddFriend("skimanalysis/HltTree");
	nt->AddFriend("BDT_pt_15_20");
	nt->AddFriend("BDT_pt_7_15");
	nt->AddFriend("BDT_pt_20_50");	


	TTree* ntMC = (TTree*)finMC->Get("Bfinder/ntphi");
	ntMC->AddFriend("hltanalysis/HltTree");
	ntMC->AddFriend("hiEvtAnalyzer/HiTree");
	ntMC->AddFriend("skimanalysis/HltTree");

	ntMC->AddFriend("BDT_pt_15_20");
	ntMC->AddFriend("BDT_pt_7_15");
	ntMC->AddFriend("BDT_pt_20_50");	


	TH1D * alphahis = new TH1D("alphahis","alphahis",Nalpha,alphaini-0.5*alphastep,alphafin+0.5*alphastep);
	TH1D * ratiohis = new TH1D("ratiohis","ratiohis",Nratio,ratioini-0.5*ratiostep,ratiofin+0.5*ratiostep);
	TH1D * Probhis = new TH1D("Probhis","Probhis",NProb,Probini-0.5*Probstep,Probfin+0.5*Probstep);
	TString PreCutMC = Form("%s * (%s && Bgen == 23333)",weightfunctionreco.Data(),PreCut.Data());
	ofstream out1(Form("Alpha_%s.dat",collsyst.Data()));
	ofstream out2(Form("Ratio_%s.dat",collsyst.Data()));
	ofstream out3(Form("Prob_%s.dat",collsyst.Data()));


	nt->Project("DataPre","Bmass",PreCut.Data());
	ntMC->Project("MCPre","Bmass",PreCutMC.Data());
	
	cout << "DataPre = " << DataPre->Integral() << endl;
	cout << "MCPre = " << MCPre->Integral() << endl;


	fDataPre = fit(c, cMC, DataPre, MCPre, ptMin, ptMax, 0, isPbPb, total, CentMinBin, CentMaxBin, "1");

	PreCutMC = Form("%s *  (%s && Bgen == 23333)",weightfunctionreco.Data(),PreCut.Data());
	fMCPre = fit(c, cMC, MCPre, MCPre, ptMin, ptMax, 1, isPbPb, total, CentMinBin, CentMaxBin, "1");

	PreCutYieldData = fDataPre->Integral(BMassMin,BMassMax)/binwidthmass;
	PreCutYieldErrData = fDataPre->Integral(BMassMin,BMassMax)/binwidthmass*fDataPre->GetParError(0)/fDataPre->GetParameter(0);

	PreCutYieldMC = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass;
	PreCutYieldErrMC = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass*fMCPre->GetParError(0)/fMCPre->GetParameter(0);

	//Alpha Variation//
	for(int i = 0; i < Nalpha; i++)
	{
		//		cout << "Doing Alpha i = " << i << endl; 
		alpha = alphaini + i * alphastep;
		//	cout << "alpha = " << alpha << endl;
		cutalpha = Form("(Balpha < %f) && %s",alpha,PreCut.Data());

		cutalphaMC = Form("%s *  (%s && Bgen == 23333)",weightfunctionreco.Data(),cutalpha.Data());

		halpha[i] = new TH1D(Form("halpha%d",i),Form("halpha%d",i),NBMassBin,BMassMin,BMassMax);
		halphaMC[i] = new TH1D(Form("halphaMC%d",i),Form("halphaMC%d",i),NBMassBin,BMassMin,BMassMax);	

		nt->Project("halpha%d","Bmass",cutalpha.Data());
		ntMC->Project("halphaMC%d","Bmass",cutalphaMC.Data());

		fData = fit(c, cMC, halpha[i], halphaMC[i], ptMin, ptMax, 0, isPbPb, total, CentMinBin, CentMaxBin, "1");

		fMC = fit(c, cMC, halphaMC[i], halphaMC[i], ptMin, ptMax, 1, isPbPb, total, CentMinBin, CentMaxBin, "1");



		YieldDataAlpha = fData->Integral(BMassMin,BMassMax)/binwidthmass;
		YieldErrDataAlpha = fData->Integral(BMassMin,BMassMax)/binwidthmass*fData->GetParError(0)/fData->GetParameter(0);

		YieldMCAlpha = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass;
		YieldErrMCAlpha = fMC->Integral(BMassMin,BMassMax)/binwidthmass*fMC->GetParError(0)/fMC->GetParameter(0);


		DataRatio = YieldDataAlpha/PreCutYieldData;
		DataRatioErr = DataRatio * sqrt(1/YieldDataAlpha + 1/PreCutYieldData);

		MCRatio = YieldMCAlpha/PreCutYieldMC;
		MCRatioErr = MCRatio * sqrt(1/YieldMCAlpha + 1/PreCutYieldMC);

		doubleratioalpha = DataRatio/MCRatio;
		doubleratioalphaErr = doubleratioalpha * sqrt(1/YieldDataAlpha + 1/PreCutYieldData + 1/YieldMCAlpha + 1/PreCutYieldMC);

		out1 << alpha	<<	 " & " << DataRatio << " $\\pm$ " << DataRatioErr <<  " & " << MCRatio <<  " $\\pm$ " << MCRatioErr << " & "  << doubleratioalpha << " $\\pm$ " << doubleratioalphaErr << endl;
		alphahis->Fill(i+1,doubleratioalpha);
		alphahis->SetBinError(i+1,doubleratioalphaErr);
	}
	/*
	//Ratio Variation//
	for(int i = 0; i < Nratio; i++)
	{

	//		cout << "Doing Ratio i = " << i << endl; 
	ratio = ratioini + i * ratiostep;

	//	TString cutratio = Form("Dalpha < %f && (DsvpvDistance/DsvpvDisErr) > %f && Dchi2cl > %f",alphafin,ratio,Probini);
	TString cutratio = Form("(BsvpvDistance/BsvpvDisErr) > %f && %s",ratio,PreCut.Data());
	TString cutratioMC = Form("%s * (%s && Bgen == 23333)",weightfunctionreco.Data(),cutratio.Data());

	TH1D * hratio = new TH1D("hratio","hratio",100,1.7,2.0);


	int ratioYmin = hratio->GetXaxis()->FindBin(center - width + 0.000001);
	int ratioYmax = hratio->GetXaxis()->FindBin(center + width - 0.000001);

	int ratioBminleft = hratio->GetXaxis()->FindBin(center - sidemax + 0.000001);
	int ratioBmaxleft = hratio->GetXaxis()->FindBin(center - sidemin - 0.000001);

	int ratioBminright = hratio->GetXaxis()->FindBin(center + sidemin + 0.000001);
	int ratioBmaxright = hratio->GetXaxis()->FindBin(center + sidemax - 0.000001);

	nt->Project("hratio","Bmass",PreCut.Data());


	double ratioYNoCut = hratio->Integral(ratioYmin,ratioYmax);
	double ratioBNoCut = hratio->Integral(ratioBminleft,ratioBmaxleft) +  hratio->Integral(ratioBminright,ratioBmaxright);
	double ratioSigNoCut = ratioYNoCut - ratioBNoCut*width/(sidemax - sidemin);

	nt->Project("hratio","Bmass",cutratio.Data());

	double ratioYCut = hratio->Integral(ratioYmin,ratioYmax);
	double ratioBCut =  hratio->Integral(ratioBminleft,ratioBmaxleft) +  hratio->Integral(ratioBminright,ratioBmaxright);
	double ratioSigCut = ratioYCut - ratioBCut*width/(sidemax - sidemin);

	//	cout <<" ratioYCut = " << ratioYCut << "  ratioBCut = " << ratioBCut <<  "   ratioSigCut =" << ratioSigCut << endl;

	double DataRatio = ratioSigCut/ratioSigNoCut;
	double DataRatioErr = DataRatio * sqrt(1/ratioSigNoCut + 1/ratioSigCut);




	ntMC->Project("hratio","Bmass",PreCutMC.Data());

	double ratioSigNoCutMC = hratio->Integral(ratioYmin,ratioYmax);



	ntMC->Project("hratio","Bmass",cutratioMC.Data());

	double ratioSigCutMC = hratio->Integral(ratioYmin,ratioYmax);

	double MCRatio = ratioSigCutMC/ratioSigNoCutMC;
	double MCRatioErr = MCRatio * sqrt(1/ratioSigCutMC + 1/ratioSigNoCutMC);
	double doubleratioratio = DataRatio/MCRatio;
	double doubleratioratioErr = doubleratioratio * sqrt(1/ratioSigCut + 1/ratioSigNoCut + 1/ratioSigCutMC + 1/ratioSigNoCutMC);
	ratiohis->SetBinContent(i+1,doubleratioratio);
	ratiohis->SetBinError(i+1,doubleratioratioErr);
	out2 << ratio	<<	 " & " << DataRatio << " $\\pm$ " << DataRatioErr <<  " & " << MCRatio <<  " $\\pm$ " << MCRatioErr << " & "  << doubleratioratio << " $\\pm$ " << doubleratioratioErr << endl;



	}

	//Prob Variation//
	for(int i = 0; i < NProb; i++)
	{
	//	cout << "Doing Prob i = " << i << endl; 
	Prob = Probini + i * Probstep;
	TString cutProb = Form("Bchi2cl > %f && %s",Prob,PreCut.Data());
	//TString cutProb = Form("Dalpha < %f && (DsvpvDistance/DsvpvDisErr) > %f && Dchi2cl > %f",alphafin,ratioini,Prob);
	TString cutProbMC = Form("%s * (%s && Bgen == 23333)",weightfunctionreco.Data(),cutProb.Data());

	TH1D * hProb = new TH1D("hProb","hProb",100,1.7,2.0);


	int ProbYmin = hProb->GetXaxis()->FindBin(center - width + 0.000001);
	int ProbYmax = hProb->GetXaxis()->FindBin(center + width - 0.000001);

	int ProbBminleft = hProb->GetXaxis()->FindBin(center - sidemax + 0.000001);
	int ProbBmaxleft = hProb->GetXaxis()->FindBin(center - sidemin - 0.000001);

	int ProbBminright = hProb->GetXaxis()->FindBin(center + sidemin + 0.000001);
	int ProbBmaxright = hProb->GetXaxis()->FindBin(center + sidemax - 0.000001);

	nt->Project("hProb","Bmass",PreCut.Data());


	double ProbYNoCut = hProb->Integral(ProbYmin,ProbYmax);
	double ProbBNoCut = hProb->Integral(ProbBminleft,ProbBmaxleft) +  hProb->Integral(ProbBminright,ProbBmaxright);
	double ProbSigNoCut = ProbYNoCut - ProbBNoCut*width/(sidemax - sidemin);

	nt->Project("hProb","Bmass",cutProb.Data());

	double ProbYCut = hProb->Integral(ProbYmin,ProbYmax);
	double ProbBCut =  hProb->Integral(ProbBminleft,ProbBmaxleft) +  hProb->Integral(ProbBminright,ProbBmaxright);
	double ProbSigCut = ProbYCut - ProbBCut*width/(sidemax - sidemin);

	double DataRatio = ProbSigCut/ProbSigNoCut;
	double DataRatioErr = DataRatio * sqrt(1/ProbSigCut + 1/ProbSigNoCut);


	ntMC->Project("hProb","Bmass",PreCutMC.Data());

	double ProbSigNoCutMC = hProb->Integral(ProbYmin,ProbYmax);


	ntMC->Project("hProb","Bmass",cutProbMC.Data());

	double ProbSigCutMC = hProb->Integral(ProbYmin,ProbYmax);

	double MCRatio = ProbSigCutMC/ProbSigNoCutMC;
	double MCRatioErr = MCRatio * sqrt(1/ProbSigCutMC + 1/ProbSigNoCutMC);
	double doubleratioProb = DataRatio/MCRatio;
	double doubleratioProbErr = doubleratioProb * sqrt(1/ProbSigCut + 1/ProbSigNoCut + 1/ProbSigCutMC + 1/ProbSigNoCutMC);

	//	cout << " doubleratioProb = " << doubleratioProb << endl;

	cout << "Prob = " << Prob << endl;
	cout << "DataRatioProb = " << DataRatio << "  DataRatioProb Error =  " << DataRatioErr << endl;
	cout << "MCRatioProb = " << MCRatio << "  MCRatioProb Error =  " << MCRatioErr << endl;
	cout << "doubleratioProb = " << doubleratioProb << "  doubleratioProb Error =  " <<  doubleratioProbErr << endl;


	Probhis->SetBinContent(i+1,doubleratioProb);
	Probhis->SetBinError(i+1,doubleratioProbErr);

	out3 << Prob	<<	 " & " << DataRatio << " $\\pm$ " << DataRatioErr <<  " & " << MCRatio <<  " $\\pm$ " << MCRatioErr << " & "  << doubleratioProb << " $\\pm$ " << doubleratioProbErr << endl;


}
*/




TCanvas* c1= new TCanvas("c1","",1800,800);
c1->cd();
c1->Divide(3,1);
c1->cd(1);
/*
   if(collsyst == "pp"){
   alphahis->SetMinimum(0.90);
   alphahis->SetMinimum(1.10);
   ratiohis->SetMinimum(0.95);
   ratiohis->SetMinimum(1.05);
   Probhis->SetMinimum(0.95);
   Probhis->SetMinimum(1.05);
   }
   if(collsyst == "pPb"){
   alphahis->SetMinimum(1.00);
   alphahis->SetMinimum(1.25);
   ratiohis->SetMinimum(1.00);
   ratiohis->SetMinimum(1.25);
   Probhis->SetMinimum(0.95);
   Probhis->SetMinimum(1.05);
   }
   */
alphahis->GetXaxis()->SetTitle("D alpha");
alphahis->GetYaxis()->SetTitle("Double Ratio");
alphahis->SetTitle("CutVariation - D #alpha");
alphahis->Draw("e0xp");
alphahis->SetMarkerStyle(20);
alphahis->SetMarkerSize(2);
alphahis->SetMinimum(0.90);		
alphahis->SetMaximum(1.10);

alphahis->Draw("e0xp");
c1->cd(2);
ratiohis->GetXaxis()->SetTitle("Decay Length Ratio");
ratiohis->GetYaxis()->SetTitle("Double Ratio");
ratiohis->SetTitle("CutVariation - Decay Length Ratio");
ratiohis->Draw("e0xp");
ratiohis->SetMarkerStyle(20);
ratiohis->SetMarkerSize(2);
ratiohis->SetMinimum(0.90);		
ratiohis->SetMaximum(1.10);

ratiohis->Draw("e0xp");
c1->cd(3);
Probhis->GetXaxis()->SetTitle("Vertex Probability");
Probhis->GetYaxis()->SetTitle("Double Ratio");
Probhis->SetTitle("CutVariation - Vertex Probability");
Probhis->Draw("e0xp");
Probhis->SetMarkerStyle(20);
Probhis->SetMarkerSize(2);
Probhis->Draw("e0xp");
Probhis->SetMinimum(0.90);		
Probhis->SetMaximum(1.10);

c1->SaveAs(Form("Plots/CutVariation_%s.pdf",collsyst.Data()));

}



int main(int argc, char *argv[])
{
	if((argc !=5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 5)
		CutVariation(argv[1],argv[2],argv[3],argv[4]);
	return 0;
}


