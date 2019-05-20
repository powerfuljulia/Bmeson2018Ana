#include "TFile.h"
#include "TH1.h"
#include "iostream"
using namespace std;
void printNumbers(TH1D* hEff, TH1D* hEffVar);
void getPtShapeSyst(){
	cout<<"=== pp result ==="<<endl;	
	TFile* fEff = new TFile("../ROOTfiles/MCstudiesPP.root");
	TFile* fEffVar = new TFile("MCstudiesPP.root");
	TH1D* hEff = (TH1D*)fEff->Get("hEff");
	TH1D* hEffVar = (TH1D*)fEffVar->Get("hEff");
	printNumbers(hEff, hEffVar);

	cout<<"=== PbPb result ==="<<endl;	
	fEff = new TFile("../ROOTfiles/MCstudiesPbPb.root");
	fEffVar = new TFile("MCstudiesPbPb.root");
	hEff = (TH1D*)fEff->Get("hEff");
	hEffVar = (TH1D*)fEffVar->Get("hEff");
	printNumbers(hEff, hEffVar);

	cout<<"=== pp 3-bin result ==="<<endl;	
	fEff = new TFile("../ROOTfiles/MCstudiesPP_750.root");
	fEffVar = new TFile("MCstudiesPP_750.root");
	hEff = (TH1D*)fEff->Get("hEff");
	hEffVar = (TH1D*)fEffVar->Get("hEff");
	printNumbers(hEff, hEffVar);
	
}
void printNumbers(TH1D* hEff, TH1D* hEffVar){
	for(int i = 0 ; i < hEff->GetNbinsX(); i++){
		float d4 = hEff->GetBinContent(i+1);
		float d4Var = hEffVar->GetBinContent(i+1);
		printf("pt bin %d\n", i);
		printf("eff: %f, eff varied: %f, syst.: %f\n", d4, d4Var, fabs(d4-d4Var)/d4*100);
	}
}
