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

	TCanvas *cResults = new TCanvas("cResults","cResults",600,600);


	if(collsyst == "pp") weightfunctionreco="(pthatweight)*(maxDgenpt<pthat/1.2)*(0.0116437+Dgenpt*(0.0602697)+Dgenpt*Dgenpt*(-0.00226879)+Dgenpt*Dgenpt*Dgenpt*(3.91035e-05)+Dgenpt*Dgenpt*Dgenpt*Dgenpt*(-3.0699e-07)+Dgenpt*Dgenpt*Dgenpt*Dgenpt*Dgenpt*(8.73234e-10))";


	if(collsyst == "PbPb")
	{
		//BptWeight="0.475953*TMath::Exp(-0.001731*Bpt)+38.069448/(Bpt*Bpt+0.001237*0.001237)";
		BptWeight="0.474599*TMath::Exp(-0.001406*Bpt)+38.036016/(Bpt*Bpt+0.000330*0.000330)";
		CentWeight = "CentWeight";
		//PVzWeight = "TMath::Exp(0.057104 + -0.020908 * PVz + -0.001864 * PVz * PVz)";
		//PVzWeight =	"(0.162740 * TMath::Exp(- 0.020823 * (PVz - 0.428205)*(PVz - 0.428205)))/(0.159489 * TMath::Exp(- 0.019979 * (PVz - 0.594276)*(PVz - 0.594276)))";
		PVzWeight="(0.164847 * TMath::Exp(- 0.021378 * (PVz - 0.342927)*(PVz - 0.342927)))/(0.159507 * TMath::Exp(- 0.019986 * (PVz - 0.601387)*(PVz - 0.601387)))";
	}

	if(collsyst == "pp") isPbPb = 0;
	if(collsyst == "PbPb") isPbPb = 1;

	TFile *fin = new TFile(inputdata.Data());
	TFile *finMC = new TFile(inputMC.Data());



	TTree* nt = (TTree*) fin->Get("Bfinder/ntphi");
	nt->AddFriend("hltanalysis/HltTree");
	nt->AddFriend("hiEvtAnalyzer/HiTree");
	nt->AddFriend("skimanalysis/HltTree");
//	nt->AddFriend("BDT_pt_15_20");
//	nt->AddFriend("BDT_pt_7_15");
//	nt->AddFriend("BDT_pt_20_50");	
	nt->AddFriend("BDT");	


	TTree* ntMC = (TTree*)finMC->Get("Bfinder/ntphi");
	ntMC->AddFriend("hltanalysis/HltTree");
	ntMC->AddFriend("hiEvtAnalyzer/HiTree");
	ntMC->AddFriend("skimanalysis/HltTree");

	/*
	ntMC->AddFriend("BDT_pt_15_20");
	ntMC->AddFriend("BDT_pt_7_15");
	ntMC->AddFriend("BDT_pt_20_50");	
	*/
	ntMC->AddFriend("BDT");	
	ntMC->AddFriend("CentWeightTree");	


	TH1D * alphahis = new TH1D("alphahis","alphahis",Nalpha,alphaini-0.5*alphastep,alphafin+0.5*alphastep);
	TH1D * ratiohis = new TH1D("ratiohis","ratiohis",Nratio,ratioini-0.5*ratiostep,ratiofin+0.5*ratiostep);
	TH1D * Probhis = new TH1D("Probhis","Probhis",NProb,Probini-0.5*Probstep,Probfin+0.5*Probstep);
	
	
	
	TString PreCutMC = Form("(%s && Bgen == 23333)",PreCut.Data());


	ofstream out1(Form("Alpha_%s.dat",collsyst.Data()));
	ofstream out2(Form("Ratio_%s.dat",collsyst.Data()));
	ofstream out3(Form("Prob_%s.dat",collsyst.Data()));

	TH1D * DataPre = new TH1D("DataPre","DataPre",NBMassBin,BMassMin,BMassMax);


	nt->Project("DataPre","Bmass",PreCut.Data());



	TH1D * MCPre = new TH1D("MCPre","MCPre",NBMassBin,BMassMin,BMassMax);

	ntMC->Project("MCPre","Bmass",(TCut(BptWeight.Data())*TCut(CentWeight.Data())*TCut(PVzWeight.Data())*TCut(weightfunctionreco.Data()))*(TCut(PreCutMC.Data())));

	cout << "DataPre = " << DataPre->Integral() << endl;
	cout << "MCPre = " << MCPre->Integral() << endl;

	TFile * CutVarOut = new TFile("CutVarOut.root","RECREATE");
	CutVarOut->cd();
	fDataPre = fit(c, cMC, DataPre, MCPre, ptMin, ptMax, 0, isPbPb, total, CentMinBin, CentMaxBin, "1");

	PreCutMC = Form("%s *  (%s && Bgen == 23333)",weightfunctionreco.Data(),PreCut.Data());
	fMCPre = fit(c, cMC, MCPre, MCPre, ptMin, ptMax, 1, isPbPb, total, CentMinBin, CentMaxBin, "1");

	PreCutYieldData = fDataPre->Integral(BMassMin,BMassMax)/binwidthmass;
	PreCutYieldErrData = fDataPre->Integral(BMassMin,BMassMax)/binwidthmass*fDataPre->GetParError(0)/fDataPre->GetParameter(0);

	PreCutYieldMC = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass;
	PreCutYieldErrMC = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass*fMCPre->GetParError(0)/fMCPre->GetParameter(0);



	cout << "PreCutYieldData = " << PreCutYieldData << "   PreCutYieldMC  = " << PreCutYieldMC << endl;
	//Alpha Variation//

	for(int j = 0; j < NVar; j++){

		ResultHis = new TH1D(Form("%s",VarHisName[j].Data()),Form("%s",VarHisName[j].Data()),VarHisN[j],VarHisMin[j],VarHisMax[j]);
		ResultHis->GetXaxis()->SetTitle(Form("%s ",VarXName[j].Data()));
		ResultHis->GetYaxis()->SetTitle("Yield Double Ratio");
		ResultHis->GetYaxis()->SetTitle(Form("%s Cut Variation",VarXName[j].Data()));
		NVarStep[j] = (VarCutMax[j] - VarCutMin[j])/NCut[j];

		for(int i = 0; i < NCut[j]; i++)
		{

			cout << "Now Working on " << Var[j].Data() << "  i = " << i <<  "  CutValue = " << CutValue << endl;

			CutValue = VarCutMin[j] + i * 	NVarStep[j];
			VarCutData = Form("(%s %s %f) && (%s)",Var[j].Data(),Direction[j].Data(),CutValue,PreCut.Data());

			cout << "VarCutData = " << VarCutData.Data() << endl;

			VarCutMC = Form("((%s) && Bgen == 23333)",VarCutData.Data());

			cout << "VarCutMC = " << VarCutMC.Data() << endl;


			HisData = new TH1D(Form("%s_%d_DataHis",VarName[j].Data(),i),Form("%s_%d_DataHis",VarName[j].Data(),i),NBMassBin,BMassMin,BMassMax);
			HisMC = new TH1D(Form("%s_%d_MCHis",VarName[j].Data(),i),Form("%s_%d_MCHis",Var[j].Data(),i),NBMassBin,BMassMin,BMassMax);	



			nt->Project(Form("%s_%d_DataHis",VarName[j].Data(),i),"Bmass",VarCutData.Data());
			ntMC->Project(Form("%s_%d_MCHis",VarName[j].Data(),i),"Bmass",(TCut(BptWeight.Data())*TCut(CentWeight.Data())*TCut(PVzWeight.Data())*TCut(weightfunctionreco.Data()))*(TCut(VarCutMC.Data())));
	


			cout << "Data Integral " << HisData->Integral() << endl;
			cout << "MC Integral " << HisMC->Integral() << endl;

			fData = fit(c, cMC, HisData, HisMC, ptMin, ptMax, 0, isPbPb, total, CentMinBin, CentMaxBin, "1");

			fMC = fit(c, cMC, HisMC, HisMC, ptMin, ptMax, 1, isPbPb, total, CentMinBin, CentMaxBin, "1");


			YieldData = fData->Integral(BMassMin,BMassMax)/binwidthmass;
			YieldErrData = fData->Integral(BMassMin,BMassMax)/binwidthmass*fData->GetParError(0)/fData->GetParameter(0);

			YieldMC = fMCPre->Integral(BMassMin,BMassMax)/binwidthmass;
			YieldErrMC = fMC->Integral(BMassMin,BMassMax)/binwidthmass*fMC->GetParError(0)/fMC->GetParameter(0);


			DataRatio = YieldData/PreCutYieldData;
			DataRatioErr = DataRatio * sqrt(1/YieldData + 1/PreCutYieldData);

			MCRatio = YieldMC/PreCutYieldMC;
			MCRatioErr = MCRatio * sqrt(1/YieldMC + 1/PreCutYieldMC);

			doubleratio = DataRatio/MCRatio;
			doubleratioErr = doubleratio * sqrt(1/YieldData + 1/PreCutYieldData + 1/YieldErrMC + 1/PreCutYieldMC);


			cout << "DataRatio = " << DataRatio << "  MCRatio = " << MCRatio << endl;


			cout << "YieldData = " << YieldData << "  PreCutYieldData = " << PreCutYieldData << " YieldMC =  " << YieldMC << endl;

			if(YieldData > 0 && YieldMC > 0){
			cout << "doubleratio = " << doubleratio << "  doubleratioErr = " << doubleratioErr << endl;
			out1 << alpha	<<	 " & " << DataRatio << " $\\pm$ " << DataRatioErr <<  " & " << MCRatio <<  " $\\pm$ " << MCRatioErr << " & "  << doubleratio << " $\\pm$ " << doubleratioErr << endl;
		
			CutValueXBin = ResultHis->GetXaxis()->FindBin(CutValue);
			
			ResultHis->SetBinContent(CutValueXBin,doubleratio);
			ResultHis->SetBinError(CutValueXBin,doubleratioErr);
			}
		}
		cResults->cd();
		ResultHis->SetMarkerStyle(20);
		ResultHis->SetMarkerColor(kBlack);
		ResultHis->SetMarkerSize(2);
		ResultHis->Draw("ep");
		cResults->SaveAs(Form("Plots/CutVar%s.png",VarName[j].Data()));
	}


	CutVarOut->Close();
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


