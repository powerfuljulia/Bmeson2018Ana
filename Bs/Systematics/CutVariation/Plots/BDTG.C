#include "../../includes/uti.h"
#include "../header.h"
#define MAX_XB       100000

void BDTG(TString inputname, TString outputname,
		Float_t ptmin, Float_t ptmax, TString mvatype)
{
	void makeoutput(TString infname, TString ofname, TString treename);
	makeoutput(inputname,Form("%s.root",outputname.Data()),Form("%s_pt_%.0f_%.0f",mvatype.Data(),ptmin,ptmax));
}

void makeoutput(TString infname, TString ofname, TString treename)
{
	TFile* inf = new TFile(infname);
	TTree* t = (TTree*)inf->Get("ntDkpi");
	//	t->AddFriend("mvaTree");


	Int_t           Dsize;
	Float_t         Dchi2cl[MAX_XB];   //[Bsize]
	Float_t         DsvpvDistance[MAX_XB];   //[Bsize]
	Float_t         DsvpvDisErr[MAX_XB];   //[Bsize]
	Float_t         Dalpha[MAX_XB];   //[Bsize]   
	// Double_t        MVA[MAX_XB];   //[Bsize]   
	//Double_t        MVA[MAX_XB]; 
	Float_t         Dtrk1thetastar[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1dedx[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2dedx[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1P[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2P[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1Pt[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2Pt[MAX_XB];   //[Bsize]   
	Float_t         Dd0[MAX_XB];   //[Bsize]   
	Float_t         Dd0Err[MAX_XB];   //[Bsize]   
	Float_t         Dphi[MAX_XB];   //[Bsize]   
	Float_t         Dchi2ndf[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1Y[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2Y[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1Phi[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2Phi[MAX_XB];   //[Bsize]   
	Float_t         Dtrk1D0[MAX_XB];   //[Bsize]   
	Float_t         Dtrk2D0[MAX_XB];   //[Bsize]   


	t->SetBranchAddress("Dsize", &Dsize);
	t->SetBranchAddress("Dalpha", Dalpha);
	t->SetBranchAddress("Dchi2cl", Dchi2cl);
	t->SetBranchAddress("DsvpvDistance", DsvpvDistance);
	t->SetBranchAddress("DsvpvDisErr", DsvpvDisErr);
	//  t->SetBranchAddress("MVA", MVA);
	t->SetBranchAddress("Dtrk1thetastar", Dtrk1thetastar);
	t->SetBranchAddress("Dtrk1dedx", Dtrk1dedx);
	t->SetBranchAddress("Dtrk2dedx", Dtrk2dedx);
	t->SetBranchAddress("Dtrk1P", Dtrk1P);
	t->SetBranchAddress("Dtrk2P", Dtrk2P);
	t->SetBranchAddress("Dtrk1Pt", Dtrk1Pt);
	t->SetBranchAddress("Dtrk2Pt", Dtrk2Pt);
	t->SetBranchAddress("Dd0", Dd0);
	t->SetBranchAddress("Dd0Err", Dd0Err);
	t->SetBranchAddress("Dphi", Dphi);
	t->SetBranchAddress("Dchi2ndf", Dchi2ndf);
	t->SetBranchAddress("Dtrk1Y", Dtrk1Y);
	t->SetBranchAddress("Dtrk2Y", Dtrk2Y);
	t->SetBranchAddress("Dtrk1Phi", Dtrk1Phi);
	t->SetBranchAddress("Dtrk2Phi", Dtrk2Phi);
	t->SetBranchAddress("Dtrk1D0", Dtrk1D0);
	t->SetBranchAddress("Dtrk2D0", Dtrk2D0);

	std::vector<std::string> theInputVars;
	//  std::string a1 = "Dalpha";
	std::string a1 = "DsvpvDistance/DsvpvDisErr";
	std::string a2 = "Dchi2cl";

	//  std::string a4 = "MVA";
	std::string a3 = "DsvpvDistance*TMath::Sin(Dalpha)";
	//	std::string a3 = "DsvpvDistance*TMath::Sin(Dalpha)";

	std::string a4 = "TMath::Cos(Dtrk1thetastar)";

	std::string a5 = "Dtrk1dedx";
	std::string a6 = "Dtrk2dedx";
	std::string a7 = "Dtrk1P";
	std::string a8 = "Dtrk2P";
	std::string a9 = "Dtrk1Pt";
	std::string a10 = "Dtrk2Pt";
	std::string a11 = "Dd0";
	std::string a12 = "Dd0Err";
	std::string a13 = "Dphi";
	std::string a14 = "Dchi2ndf";
	std::string a15 = "Dtrk1Y";
	std::string a16 = "Dtrk2Y";
	std::string a17 = "Dtrk1Phi";
	std::string a18 = "Dtrk2Phi";
	std::string a19 = "Dtrk1D0";
	std::string a20 = "Dtrk2D0";


	theInputVars.push_back(a1);
	theInputVars.push_back(a2);
	theInputVars.push_back(a3);
	theInputVars.push_back(a4);
	theInputVars.push_back(a5);
	theInputVars.push_back(a6);
	theInputVars.push_back(a7);
	theInputVars.push_back(a8);
	theInputVars.push_back(a9);
	theInputVars.push_back(a10);

	theInputVars.push_back(a11);
	theInputVars.push_back(a12);
	theInputVars.push_back(a13);
	theInputVars.push_back(a14);
	theInputVars.push_back(a15);
	theInputVars.push_back(a16);
	theInputVars.push_back(a17);
	theInputVars.push_back(a18);
	theInputVars.push_back(a19);
	theInputVars.push_back(a20);

	std::vector<double> inputValues;
	ReadBDTG mva(theInputVars);

	TFile* outf = new TFile(ofname,"recreate");
	TTree* mvaTree = new TTree(Form("%s",treename.Data()),"BDTG");

	double BDTG[MAX_XB];
	mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
	mvaTree->Branch(Form("%s",treename.Data()),BDTG,Form("%s[Dsize]/D",treename.Data()));
	std::cout<<std::endl;
	std::cout<<"  Input file: "<<infname<<std::endl;
	std::cout<<"  Calculating MVA values ..."<<std::endl;
	for(int i=0;i<t->GetEntries();i++)
	{
		if(i%10000==0) std::cout<<std::setiosflags(std::ios::left)<<"  [ \033[1;36m"<<std::setw(10)<<i<<"\033[0m"<<" / "<<std::setw(10)<<t->GetEntries()<<" ] "<<"\033[1;36m"<<Form("%.0f",100.*i/t->GetEntries())<<"%\033[0m"<<"\r"<<std::flush;
		t->GetEntry(i);
		for(int j=0;j<Dsize;j++)
		{
			inputValues.clear();
			//    inputValues.push_back(Dalpha[j]);
			inputValues.push_back(DsvpvDistance[j]/DsvpvDisErr[j]);
			inputValues.push_back(Dchi2cl[j]);
			//		  inputValues.push_back(MVA[j]);
			inputValues.push_back(DsvpvDistance[j]*TMath::Sin(Dalpha[j]));
			inputValues.push_back(TMath::Cos(Dtrk1thetastar[j]));
			inputValues.push_back(Dtrk1dedx[j]);
			inputValues.push_back(Dtrk2dedx[j]);
			inputValues.push_back(Dtrk1P[j]);
			inputValues.push_back(Dtrk2P[j]);
			inputValues.push_back(Dtrk1Pt[j]);
			inputValues.push_back(Dtrk2Pt[j]);
			inputValues.push_back(Dd0[j]);
			inputValues.push_back(Dd0Err[j]);
			inputValues.push_back(Dphi[j]);
			inputValues.push_back(Dchi2ndf[j]);
			inputValues.push_back(Dtrk1Y[j]);
			inputValues.push_back(Dtrk2Y[j]);
			inputValues.push_back(Dtrk1Phi[j]);
			inputValues.push_back(Dtrk2Phi[j]);
			inputValues.push_back(Dtrk1D0[j]);
			inputValues.push_back(Dtrk2D0[j]);

			BDTG[j] = mva.GetMvaValue(inputValues);      
		}
		mvaTree->Fill();
	}
	std::cout<<std::endl<<"  Processed "<<"\033[1;31m"<<t->GetEntries()<<"\033[0m event(s)."<<std::endl;
	outf->cd();
	outf->Write();
	outf->Close();
}

int main(int argc, char* argv[])
{
	if(argc==6)
	{
		BDTG(argv[1],argv[2],atof(argv[3]),atof(argv[4]),argv[5]);
		return 0;
	}
	else
	{
		std::cout<<"  Error: invalid argument number - BDT()"<<std::endl;
		return 1;
	}
}
