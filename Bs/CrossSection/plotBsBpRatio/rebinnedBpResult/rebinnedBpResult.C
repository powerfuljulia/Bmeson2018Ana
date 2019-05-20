#include "../../uti.h"
#include "../../parameters.h"
#include "TLegendEntry.h"
float BpXsecValpp[100];
float BpXsecValPbPb[100];
float BpXsecStaErrpp[100];
float BpXsecStaErrPbPb[100];
float BpXsecSysErrpp[100];
float BpXsecSysErrPbPb[100];	
float BpRaayVal[100];
float BpRaayStaErr[100];
float BpRaaySysErr[100];
float BpRaayStaErrAbs[100];
float BpRaaySysErrAbs[100];

int _nBins = nBins;
double *_ptBins = ptBins;
void rebinnedBpResult(){
    TFile* BpXsecpp = new TFile("CrossSectionPP.root");
	TH1D* BphPtSigmapp = (TH1D*)BpXsecpp->Get("hPtSigma");
	TGraphAsymmErrors* BpgaeCrossSystpp = (TGraphAsymmErrors*)BpXsecpp->Get("gaeCrossSyst");
    TFile* BpXsecPbPb = new TFile("CrossSectionPbPb.root");
	TH1D* BphPtSigmaPbPb = (TH1D*)BpXsecPbPb->Get("hPtSigma");
	TGraphAsymmErrors* BpgaeCrossSystPbPb = (TGraphAsymmErrors*)BpXsecPbPb->Get("gaeCrossSyst");

    TFile* Bpf = new TFile("outputRAA.root");
    TGraphAsymmErrors* BpgNucl = (TGraphAsymmErrors*)Bpf->Get("gNuclearModification");
    TH1D* BphNucl = (TH1D*)Bpf->Get("hNuclearModification");

	if(BphPtSigmapp->GetNbinsX() != BphPtSigmaPbPb->GetNbinsX() || BphPtSigmaPbPb->GetNbinsX() != BphNucl->GetNbinsX()){
		cout<<"Bin number inconsistent, exit."<<endl;
		return;
	}
	for(int i = 0; i < BphPtSigmapp->GetNbinsX(); i ++){
		BpXsecValpp[i] = BphPtSigmapp->GetBinContent(i+1)*BphPtSigmapp->GetBinWidth(i+1);
		BpXsecValPbPb[i] = BphPtSigmaPbPb->GetBinContent(i+1)*BphPtSigmaPbPb->GetBinWidth(i+1);
		BpXsecStaErrpp[i] =  BphPtSigmapp->GetBinError(i+1)*BphPtSigmapp->GetBinWidth(i+1);
		BpXsecStaErrPbPb[i] =  BphPtSigmaPbPb->GetBinError(i+1)*BphPtSigmaPbPb->GetBinWidth(i+1);

        double x, y;
        BpgaeCrossSystpp->GetPoint(i,x,y);
		if(y != BphPtSigmapp->GetBinContent(i+1)) cout<<"Xsec mean value different, should check"<<endl;
        BpgaeCrossSystPbPb->GetPoint(i,x,y);
		if(y != BphPtSigmaPbPb->GetBinContent(i+1)) cout<<"Xsec mean value different, should check"<<endl;
		BpXsecSysErrpp[i] = BpgaeCrossSystpp->GetErrorYhigh(i)*BphPtSigmapp->GetBinWidth(i+1);
		BpXsecSysErrPbPb[i] = BpgaeCrossSystPbPb->GetErrorYhigh(i)*BphPtSigmaPbPb->GetBinWidth(i+1);
		printf("pt: %.0f\n",BphPtSigmapp->GetBinLowEdge(i+1));
		cout<<"pp xsec: "<<BpXsecValpp[i]<<endl;
		cout<<"pp xsec Stat err(%): "<<BpXsecStaErrpp[i]/BpXsecValpp[i]*100<<endl;
		cout<<"pp xsec Syst err(%): "<<BpXsecSysErrpp[i]/BpXsecValpp[i]*100<<endl;
		cout<<"PbPb xsec: "<<BpXsecValPbPb[i]<<endl;
		cout<<"PbPb xsec Stat err(%): "<<BpXsecStaErrPbPb[i]/BpXsecValPbPb[i]*100<<endl;
		cout<<"PbPb xsec Syst err(%): "<<BpXsecSysErrPbPb[i]/BpXsecValPbPb[i]*100<<endl;
	}
	double ppErrPer = 0;
	double PbPbErrPer = 0;
	cout<<endl;
	cout<<"bin 0 ========="<<endl;
	// bin 7-15
	cout<<"pp xsec: "<<BpXsecValpp[0] + BpXsecValpp[1]<<endl;
	cout<<"PbPb xsec: "<<BpXsecValPbPb[0] + BpXsecValPbPb[1]<<endl;
	BpRaayVal[0] = ( BpXsecValPbPb[0] + BpXsecValPbPb[1] )/( BpXsecValpp[0] + BpXsecValpp[1] );
	//ppErrPer = ( BpXsecStaErrpp[0] + BpXsecStaErrpp[1] )/( BpXsecValpp[0] + BpXsecValpp[1] );
	//PbPbErrPer = ( BpXsecStaErrPbPb[0] + BpXsecStaErrPbPb[1] )/( BpXsecValPbPb[0] + BpXsecValPbPb[1] );
	ppErrPer = sqrt( pow(BpXsecStaErrpp[0],2) + pow(BpXsecStaErrpp[1],2) )/( BpXsecValpp[0] + BpXsecValpp[1] );
	PbPbErrPer = sqrt( pow(BpXsecStaErrPbPb[0],2) + pow(BpXsecStaErrPbPb[1],2) )/( BpXsecValPbPb[0] + BpXsecValPbPb[1] );
	BpRaayStaErr[0] = sqrt(pow(ppErrPer,2) + pow(PbPbErrPer,2));
	BpRaayStaErrAbs[0] = BpRaayVal[0]*BpRaayStaErr[0];
	cout<<"pp xsec Stat err(%): "<<ppErrPer*100<<endl;
	cout<<"PbPb xsec Stat err(%): "<<PbPbErrPer*100<<endl;
	ppErrPer = ( BpXsecSysErrpp[0] + BpXsecSysErrpp[1] )/( BpXsecValpp[0] + BpXsecValpp[1] );
	PbPbErrPer = ( BpXsecSysErrPbPb[0] + BpXsecSysErrPbPb[1] )/( BpXsecValPbPb[0] + BpXsecValPbPb[1] );
	BpRaaySysErr[0] = sqrt(pow(ppErrPer,2) + pow(PbPbErrPer,2));
	BpRaaySysErrAbs[0] = BpRaayVal[0]*BpRaaySysErr[0];
	cout<<"pp xsec Syst err(%): "<<ppErrPer*100<<endl;
	cout<<"PbPb xsec Syst err(%): "<<PbPbErrPer*100<<endl;
	cout<<"Raa mean: "<<BpRaayVal[0]<<endl;
	cout<<"Raa Stat err(%): "<<BpRaayStaErr[0]*100<<endl;
	cout<<"Raa Syst err(%): "<<BpRaaySysErr[0]*100<<endl;
	cout<<"Raa Stat err(abs): "<<BpRaayStaErrAbs[0]<<endl;
	cout<<"Raa Syst err(abs): "<<BpRaaySysErrAbs[0]<<endl;
	
	cout<<"bin 1 ========="<<endl;
	// bin 15-50
	cout<<"pp xsec: "<<BpXsecValpp[2] + BpXsecValpp[3] + BpXsecValpp[4]<<endl;
	cout<<"PbPb xsec: "<<BpXsecValPbPb[2] + BpXsecValPbPb[3] + BpXsecValPbPb[4]<<endl;
	BpRaayVal[1] = ( BpXsecValPbPb[2] + BpXsecValPbPb[3] + BpXsecValPbPb[4] )/( BpXsecValpp[2] + BpXsecValpp[3] + BpXsecValpp[4] );
	//ppErrPer = ( BpXsecStaErrpp[2] + BpXsecStaErrpp[3] + BpXsecStaErrpp[4] )/( BpXsecValpp[2] + BpXsecValpp[3] + BpXsecValpp[4] );
	//PbPbErrPer = ( BpXsecStaErrPbPb[2] + BpXsecStaErrPbPb[3] + BpXsecStaErrPbPb[4] )/( BpXsecValPbPb[2] + BpXsecValPbPb[3] + BpXsecValPbPb[4] );
	ppErrPer = sqrt( pow(BpXsecStaErrpp[2],2) + pow(BpXsecStaErrpp[3],2) + pow(BpXsecStaErrpp[4],2) )/( BpXsecValpp[2] + BpXsecValpp[3] + BpXsecValpp[4] );
	PbPbErrPer = sqrt( pow(BpXsecStaErrPbPb[2],2) + pow(BpXsecStaErrPbPb[3],2) + pow(BpXsecStaErrPbPb[4],2) )/( BpXsecValPbPb[2] + BpXsecValPbPb[3] + BpXsecValPbPb[4] );
	BpRaayStaErr[1] = sqrt(pow(ppErrPer,2) + pow(PbPbErrPer,2));
	BpRaayStaErrAbs[1] = BpRaayVal[1]*BpRaayStaErr[1];
	cout<<"pp xsec Stat err(%): "<<ppErrPer*100<<endl;
	cout<<"PbPb xsec Stat err(%): "<<PbPbErrPer*100<<endl;
	ppErrPer = ( BpXsecSysErrpp[2] + BpXsecSysErrpp[3] +BpXsecSysErrpp[4] )/( BpXsecValpp[2] + BpXsecValpp[3] + BpXsecValpp[4] );
	PbPbErrPer = ( BpXsecSysErrPbPb[2] + BpXsecSysErrPbPb[3] + BpXsecSysErrPbPb[4] )/( BpXsecValPbPb[2] + BpXsecValPbPb[3] + BpXsecValPbPb[4] );
	BpRaaySysErr[1] = sqrt(pow(ppErrPer,2) + pow(PbPbErrPer,2));
	BpRaaySysErrAbs[1] = BpRaayVal[1]*BpRaaySysErr[1];
	cout<<"pp xsec Syst err(%): "<<ppErrPer*100<<endl;
	cout<<"PbPb xsec Syst err(%): "<<PbPbErrPer*100<<endl;
	cout<<"Raa mean: "<<BpRaayVal[1]<<endl;
	cout<<"Raa Stat err(%): "<<BpRaayStaErr[1]*100<<endl;
	cout<<"Raa Syst err(%): "<<BpRaaySysErr[1]*100<<endl;
	cout<<"Raa Stat err(abs): "<<BpRaayStaErrAbs[1]<<endl;
	cout<<"Raa Syst err(abs): "<<BpRaaySysErrAbs[1]<<endl;

	// Save output
	TFile* outf = new TFile("outputRAA_Bp_rebinned.root","recreate");
    TH1D* hNuclearModification = new TH1D("hNuclearModification","hNuclearModification",_nBins,_ptBins);
	hNuclearModification->SetBinContent(1,BpRaayVal[0]);
	hNuclearModification->SetBinError(1,BpRaayVal[0]*BpRaayStaErr[0]);
	hNuclearModification->SetBinContent(2,BpRaayVal[1]);
	hNuclearModification->SetBinError(2,BpRaayVal[1]*BpRaayStaErr[1]);
	float binCenter[2] = {(15.+7.)/2, (50.+15.)/2};
	float binhalfWidth[2] = {(15.-7.)/2, (50.-15.)/2};
    TGraphAsymmErrors* gNuclearModification = new TGraphAsymmErrors(2, binCenter, BpRaayVal, binhalfWidth, binhalfWidth, BpRaaySysErrAbs, BpRaaySysErrAbs);
    gNuclearModification->SetName("gNuclearModification");
	hNuclearModification->Write();
	gNuclearModification->Write();
}
