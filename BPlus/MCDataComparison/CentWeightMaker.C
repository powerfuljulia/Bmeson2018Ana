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
#include "Centparameters.h"

//#include "his.h"
using namespace std;

using std::cout;
using std::endl;

void CentWeightMaker(TString collsyst, TString inputMC, TString Centoutfile){

	TFile * finMC = new TFile(inputMC.Data());
	TTree * tMC = (TTree * )finMC->Get("hiEvtAnalyzer/HiTree");
	int Cent;
	tMC->SetBranchAddress("hiBin",&Cent);
	double CentWeight;

	TFile * fout = new TFile(Centoutfile.Data(),"RECREATE");
	fout->cd();

	TTree* CentWeightTree = new TTree("CentWeightTree","CentWeightTree");
	CentWeightTree->Branch("CentWeight",&CentWeight,"CentWeight/D");


	for(int i = 0; i < tMC->GetEntries(); i++){
			tMC->GetEntry(i);
			CentWeight = Ncoll[Cent];
			CentWeightTree->Fill();
	}

	fout->Write();
	fout->Close();


}

int main(int argc, char *argv[])
{
	if((argc !=4))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 4)
		CentWeightMaker(argv[1],argv[2],argv[3]);
	return 0;
}


