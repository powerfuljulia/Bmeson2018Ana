#include "uti.h"
#include "parameters.h"
using namespace std;

void PtShapeSyst(TString WeightedFile, TString UnWeightedFile,  TString plotname, TString outputfile){

	TFile *Weighted = new TFile(WeightedFile.Data());
	TFile *UnWeighted = new TFile(UnWeightedFile.Data());

	TH1D * hEffWeighted = (TH1D*)  Weighted->Get("hEff");
	TH1D * hEffUnWeighted = (TH1D*)  UnWeighted->Get("hEff");
	
	TH1D * hEffRatio = (TH1D *)	hEffWeighted->Clone("hEffRatio");
	TCanvas *c = new TCanvas("c","c",600,600);
	c->cd();


	hEffRatio->Divide(hEffUnWeighted);
	hEffRatio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hEffRatio->GetYaxis()->SetTitle("p_{T} Weighted Eff/p_{T} Unweighted Eff");
	hEffRatio->GetYaxis()->SetTitleOffset(1.3);
	hEffRatio->SetTitle("");
	hEffRatio->Draw("p");



	TLine *l1 = new TLine(7.0,1,50.0,1);
	l1->SetLineStyle(2);
	l1->SetLineWidth(2);
	l1->Draw();



	c->SaveAs(plotname.Data());
	double Ratio;
	double PtShapeSyst = 0;

	for(int i = 1; i < nBins + 1; i++){
		Ratio = hEffRatio->GetBinContent(i);
		PtShapeSyst = PtShapeSyst + (1-Ratio)*(1-Ratio);
	}
	
	double PtShapeSystFinal = TMath::Sqrt(PtShapeSyst)/nBins;

	cout << "Pt Shape Systematics = " <<PtShapeSystFinal << endl; 


	TFile * fout = new TFile(outputfile.Data(),"RECREATE");
	fout->cd();
	hEffRatio->Write();
	fout->Close();

}

int main(int argc, char *argv[])
{
	if((argc !=5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 5)
		PtShapeSyst(argv[1],argv[2],argv[3],argv[4]);
	return 0;
}


