#include "../uti.h"
TString fname= "../ROOTfiles/MCstudiesPP.root";
//TString fname= "../ROOTfiles/MCstudiesPbPb.root";
void getMCeffErr(){
	TFile* f = new TFile(fname);
	TH1D* heff = (TH1D*)f->Get("hEff");
	for(int i = 0; i < heff->GetNbinsX(); i++){
		printf("%f %f %f\n",heff->GetBinContent(i+1),heff->GetBinError(i+1),heff->GetBinError(i+1)/heff->GetBinContent(i+1));
	}
}
