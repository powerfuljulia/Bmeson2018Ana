#include "uti.h"


void PthatCutter()
{
	const int NPthat = 5;

	Float_t criteria[NPthat] = {5,10,15,30,50};

	TString inputfile[NPthat]={"/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_Pthat5_20181231_pt5tkpt0p7dls2_v3.root","/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_Pthat10_20181231_pt5tkpt0p7dls2_v3.root","/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_Pthat15_20181231_pt5tkpt0p7dls2_v3.root","/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_Pthat30_20181231_pt5tkpt0p7dls2_v3.root","/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_Pthat50_20181231_pt5tkpt0p7dls2_v3.root"};
	TString outputfile[NPthat]={"output/BsPthat5Redo.root","output/BsPthat10Redo.root","output/BsPthat15Redo.root","output/BsPthat30Redo.root","output/BsPthat50Redo.root"};

	for(int j=0;j < NPthat; j++){

	cout << "NOW WORKONG ON PTHAT = " << criteria[j]  << endl;
	TFile* input = new TFile(inputfile[j].Data());
	TTree* oldhlt = (TTree*) input->Get("hltanalysis/HltTree");
	TTree* oldBfi_ntKp = (TTree*) input->Get("Bfinder/ntphi");
	TTree* oldBfi_ntGen = (TTree*) input->Get("Bfinder/ntGen");
	TTree* oldski = (TTree*) input->Get("skimanalysis/HltTree");
	TTree* oldHiF = (TTree*) input->Get("HiForest/HiForestInfo");
	TTree* oldrun = (TTree*) input->Get("runAnalyzer/run");
	TTree* oldhiE = (TTree*) input->Get("hiEvtAnalyzer/HiTree");


	TFile* output = new TFile(outputfile[j].Data(),"recreate");
	TDirectory* newhlt = output->mkdir("hltanalysis","");
	TDirectory* newBfi = output->mkdir("Bfinder","");
	TDirectory* newski = output->mkdir("skimanalysis","");
	TDirectory* newHiF = output->mkdir("HiForest","");
	TDirectory* newrun = output->mkdir("runAnalyzer","");
	TDirectory* newhiE = output->mkdir("hiEvtAnalyzer","");

	newhlt->cd();
	TTree* new_hlt = oldhlt->CloneTree(0);
	newBfi->cd();
	TTree* new_Bfi_ntKp = oldBfi_ntKp->CloneTree(0);
	TTree* new_Bfi_ntGen = oldBfi_ntGen->CloneTree(0);
	newski->cd();
	TTree* new_ski = oldski->CloneTree(0);
	newHiF->cd();
	TTree* new_HiF = oldHiF->CloneTree(0);
	newrun->cd();
	TTree* new_run = oldrun->CloneTree(0);
	newhiE->cd();
	TTree* new_hiE = oldhiE->CloneTree(0);

	int n = oldhiE->GetEntries();
	float pthat;
	oldhiE->SetBranchAddress("pthat",&pthat);
	for(int i=0;i<n;i++)
	{
		if(i%1000==0) cout << "WORKING ON EVENT = " << i << endl;
		oldhlt->GetEntry(i);
		oldBfi_ntKp->GetEntry(i);
		oldBfi_ntGen->GetEntry(i);
		oldski->GetEntry(i);
		oldhiE->GetEntry(i);


		if(pthat>criteria[j]){
		newhlt->cd();
		new_hlt->Fill();
		newBfi->cd();
		new_Bfi_ntKp->Fill();
		new_Bfi_ntGen->Fill();
		newski->cd();
		new_ski->Fill();
		newhiE->cd();
		new_hiE->Fill();
		}
	}

	int m = oldHiF->GetEntries();
	for(int i=0;i<m;i++)
	{
		oldHiF->GetEntry(i);
		oldrun->GetEntry(i);

		newHiF->cd();
		new_HiF->Fill();
		newrun->cd();
		new_run->Fill();
	}

	output->Write();
	output->Close();
	
	}

}
