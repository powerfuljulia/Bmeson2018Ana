#include <TF1.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>
#include "../parameters.h"
#include "iostream"
using namespace std;

void printMCstatErr(){
TFile* ppMCEfffile = new TFile("../ROOTfiles/MCstudiesPP.root");
TH1D* ppEff = (TH1D*)ppMCEfffile->Get("hEff");
TFile* ppMCEfffile_750 = new TFile("../ROOTfiles/MCstudiesPP_750.root");
TH1D* ppEff_750 = (TH1D*)ppMCEfffile_750->Get("hEff");
TFile* PbPbMCEfffile = new TFile("../ROOTfiles/MCstudiesPbPb.root");
TH1D* PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");
printf("MC stat.");
for(int i=0;i<nBins;i++){
	printf(" & %.3f", ppEff->GetBinError(ppEff->FindBin(ptBins[i]))/ppEff->GetBinContent(ppEff->FindBin(ptBins[i]))*100);
}
printf(" \\\\ \n");
printf("MC stat.");
for(int i=0;i<nBins750;i++){
	printf(" & %.3f", ppEff_750->GetBinError(ppEff_750->FindBin(ptBins750[i]))/ppEff_750->GetBinContent(ppEff_750->FindBin(ptBins750[i]))*100);
}
printf(" \\\\ \n");
printf("MC stat.");
for(int i=0;i<nBins;i++){
	printf(" & %.3f", PbPbEff->GetBinError(PbPbEff->FindBin(ptBins[i]))/PbPbEff->GetBinContent(PbPbEff->FindBin(ptBins[i]))*100);
}
printf(" \\\\ \n");
}
