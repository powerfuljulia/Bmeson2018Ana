#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "drawTheory_Bs.h"
using namespace std;
void plotTheory_BsBpRatio()
{
	const int n = 1000;
	Int_t nbin=0;
	Float_t temp;
	Float_t aCx[n],aCy[n],aCyl[n],aCyh[n];
	Float_t bCx[n],bCy[n],bCyl[n],bCyh[n];
	// TAMU
	ifstream getdata_tamu("../theoryPrediction/theorypre_Bs/TAMU_20180509.txt");
	ifstream getdata_tamu_Bplus("../theoryPrediction/theorypre_Bs/TAMU_Bplus_20180509.txt");
	if(!getdata_tamu.is_open() || !getdata_tamu_Bplus.is_open()) {
		cout<<"Opening the file fails: TAMU"<<endl;
		return;
	}
	nbin=0;
	while(!getdata_tamu.eof())
	{
		getdata_tamu>>aCx[nbin]>>aCy[nbin];
		getdata_tamu_Bplus>>bCx[nbin]>>bCy[nbin];
		nbin++;
	}
	Float_t* aTAMUB5TeVx = new Float_t[nbin];
	Float_t* aTAMUB5TeVxe = new Float_t[nbin];
	Float_t* aTAMUB5TeVy = new Float_t[nbin];
	Float_t* aTAMUB5TeVye = new Float_t[nbin];
	for(int i=0;i<nbin;i++)
	{
		aTAMUB5TeVx[i] = aCx[i];
		aTAMUB5TeVxe[i] = 0;
		aTAMUB5TeVy[i] = aCy[i]/bCy[i];
		aTAMUB5TeVye[i] = 0.;
	}
	TGraphErrors* gTAMUB5TeV = new TGraphErrors(nbin, aTAMUB5TeVx, aTAMUB5TeVy, aTAMUB5TeVxe, aTAMUB5TeVye);
	gTAMUB5TeV->SetName("gTAMUB5TeV");
	gTAMUB5TeV->SetLineColor(colorTAMU_Bs);
	gTAMUB5TeV->SetFillColor(colorTAMU_Bs);
	gTAMUB5TeV->SetFillStyle(styleTAMU_Bs);
	gTAMUB5TeV->SetLineWidth(4);
	//gTAMUB5TeV->Draw("3 same");
	gTAMUB5TeV->Draw("L same");

	// CUJET
	nbin = 0;
	for(int i = 0; i < 200; i ++){
		aCx[i] = -100+i;
		aCy[i]= 1;
		nbin++;
	}
	Float_t* aCUJETB5TeVx = new Float_t[nbin];
	Float_t* aCUJETB5TeVxe = new Float_t[nbin];
	Float_t* aCUJETB5TeVy = new Float_t[nbin];
	Float_t* aCUJETB5TeVye = new Float_t[nbin];
	for(int i=0;i<nbin;i++)
	{
		aCUJETB5TeVx[i] = aCx[i];
		aCUJETB5TeVxe[i] = 0;
		aCUJETB5TeVy[i] = aCy[i];
		aCUJETB5TeVye[i] = 0.;
	}
	TGraphErrors* gCUJETB5TeV = new TGraphErrors(nbin, aCUJETB5TeVx, aCUJETB5TeVy, aCUJETB5TeVxe, aCUJETB5TeVye);
	gCUJETB5TeV->SetName("gCUJETB5TeV");
	gCUJETB5TeV->SetLineWidth(4);
	gStyle->SetHatchesLineWidth(3);
	gCUJETB5TeV->SetLineColor(colorCUJET_Bs);
	gCUJETB5TeV->SetFillColor(colorCUJET_Bs);
	gCUJETB5TeV->SetFillColorAlpha(colorCUJET_Bs, 0.5);
	gCUJETB5TeV->SetFillStyle(styleCUJET_Bs);
	gCUJETB5TeV->Draw("L same");
}
