#include <iostream>
#include "branchStruct.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <TGraphAsymmErrors.h>
#include <TMath.h>
using namespace std;

bool ispp = 0;
TString inputmc;
void SkimBntuple(){
	string label = "";
	if(ispp){
		label = "pp"; 
		//inputmc = "/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_pp_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt0jpsiPt0tkPt0p5_Bp_pthatweight_JingBDT.root";
    inputmc = "/data/BmesonMCPbPb/loop_Bs0_pthat5_bstojpsiphi_pp.root";
	}
	else{
		label = "PbPb";
		//inputmc = "/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_pthatweight_JingBDT.root";
	//inputmc = "/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/PthatService/output/BsPthat10Redo.root";
	inputmc="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data-New/MC_Bs_PbPb_TMVA_BDT_PbPb.root";
	}
    TFile* infMC = new TFile(inputmc.Data());
    TTree* ntphi = (TTree*)infMC->Get("Bfinder/ntphi");
    TTree* ntHlt = (TTree*)infMC->Get("hltanalysis/HltTree");
    TTree* ntSkim = (TTree*)infMC->Get("skimanalysis/HltTree");
    TTree* ntHi = (TTree*)infMC->Get("hiEvtAnalyzer/HiTree");
 //   TTree* mvaTree = (TTree*)infMC->Get("mvaTree");
    TTree* ntGen = (TTree*)infMC->Get("Bfinder/ntGen");
//	ntKp->AddFriend("ntSkim");
//	ntKp->AddFriend("ntHlt");
//	ntKp->AddFriend("ntGen");
//	ntKp->AddFriend("mvaTree");
	ntphi->AddFriend("skimanalysis/HltTree");
	ntphi->AddFriend("hltanalysis/HltTree");
	ntphi->AddFriend("Bfinder/ntGen");
	ntphi->AddFriend("hiEvtAnalyzer/HiTree");
//	ntphi->AddFriend("mvaTree");
	setAddressTree(ntphi, ntHlt, ntSkim, ntHi, ntGen, ispp);
	int nevents_total = ntphi->GetEntries();
cout << " Total = " << nevents_total << endl;
	TFile *fOut= new TFile(Form("results_%s.root", label.c_str()), "recreate"); 
	TTree* ExclBAna  = new TTree("ExclBAna","Skim Bntuple");
	double pt, y, weight;
	bool passAcc;
	double wAll = 0;
	double wPass = 0;
	ExclBAna->Branch("pt",&pt,"pt/D");
	ExclBAna->Branch("y",&y,"y/D");
	ExclBAna->Branch("weight",&weight,"weight/D");
	ExclBAna->Branch("passAcc",&passAcc,"passAcc/O");

    for(int entry=0; entry<nevents_total; entry++){
    	ntphi->GetEntry(entry);
    	ntHlt->GetEntry(entry);
    	ntSkim->GetEntry(entry);
    	ntHi->GetEntry(entry);
    //mvaTree->GetEntry(entry);
    	ntGen->GetEntry(entry);
		//cout << pthatweight << endl;
		for(int g=0; g<Gsize; g++){
//		cout << "Gy = " << Gy[g] << endl;
	//	cout << "GisSignal = " << GisSignal[g] << endl;
		//	if(TMath::Abs(Gy[g])<2.4&&abs(GpdgId[g])==521&&GisSignal[g]==1&&Gpt[g]>=7&&Gpt[g]<=50)
		if(TMath::Abs(Gy[g])<2.4&&abs(GpdgId[g])==531&&GisSignal[g]>0&&Gpt[g]>=5&&Gpt[g]<=50){
				pt = Gpt[g];
				y = Gy[g];
				weight = 0;
				passAcc = 0;
				if(ispp){
				//weight = pthatweight*(pow(10,-0.094152+0.008102*Gpt[g]+Gpt[g]*Gpt[g]*0.000171+Gpt[g]*Gpt[g]*Gpt[g]*-0.000005+Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*-0.000000+Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*0.000000));
				weight = 1;
				} 
				else{
				//weight = pthatweight*(pow(10,-0.107832+0.010248*Gpt[g]+Gpt[g]*Gpt[g]*0.000079+Gpt[g]*Gpt[g]*Gpt[g]*-0.000003+Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*-0.000000+Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*Gpt[g]*0.000000));
				//weight = 1;
				weight = pthatweight*(0.474599*TMath::Exp(-0.001406*Gpt[g])+38.036016/(Gpt[g]*Gpt[g]+0.000330*0.000330));
				}		
				wAll += weight;

				//	if( TMath::Abs(Gy[g])<2.4 && abs(GpdgId[g])==531 && GisSignal[g]>0 && ((TMath::Abs(Gmu1eta[g])<1.2 && Gmu1pt[g]>3.5) || (TMath::Abs(Gmu1eta[g])>1.2 && TMath::Abs(Gmu1eta[g])<2.1 && Gmu1pt[g]>(5.77-1.8*TMath::Abs(Gmu1eta[g]))) || (TMath::Abs(Gmu1eta[g])>2.1 && TMath::Abs(Gmu1eta[g])<2.4 && Gmu1pt[g]>1.8)) && ((TMath::Abs(Gmu2eta[g])<1.2 && Gmu2pt[g]>3.5) || (TMath::Abs(Gmu2eta[g])>1.2 && TMath::Abs(Gmu2eta[g])<2.1 && Gmu2pt[g]>(5.77-1.8*TMath::Abs(Gmu2eta[g]))) || (TMath::Abs(Gmu2eta[g])>2.1 && TMath::Abs(Gmu2eta[g])<2.4 && Gmu2pt[g]>1.8)) && Gtk1pt[g]>0.7 && Gtk2pt[g]>0.7 && TMath::Abs(Gtk1eta[g])<2.4 && TMath::Abs(Gtk2eta[g])<2.4)
if(TMath::Abs(Gy[g])<2.4 && abs(GpdgId[g])==531 && GisSignal[g]>0 && ((TMath::Abs(Gmu1eta[g])<1.2 && Gmu1pt[g]>3.5) || (TMath::Abs(Gmu1eta[g])>1.2 && TMath::Abs(Gmu1eta[g])<2.1 && Gmu1pt[g]>(5.77-1.8*TMath::Abs(Gmu1eta[g]))) || (TMath::Abs(Gmu1eta[g])>2.1 && TMath::Abs(Gmu1eta[g])<2.4 && Gmu1pt[g]>1.8)) && ((TMath::Abs(Gmu2eta[g])<1.2 && Gmu2pt[g]>3.5) || (TMath::Abs(Gmu2eta[g])>1.2 && TMath::Abs(Gmu2eta[g])<2.1 && Gmu2pt[g]>(5.77-1.8*TMath::Abs(Gmu2eta[g]))) || (TMath::Abs(Gmu2eta[g])>2.1 && TMath::Abs(Gmu2eta[g])<2.4 && Gmu2pt[g]>1.8)) && Gtk1pt[g]>1.5 && Gtk2pt[g]>1.5 && TMath::Abs(Gtk1eta[g])<2.4 && TMath::Abs(Gtk2eta[g])<2.4)
					{
					passAcc = 1;
					wPass += weight;
					}
				ExclBAna->Fill();
			}
		}//Gsize loop
	}//Evt loop
	cout<<"wAll: "<<wAll<<endl;
	cout<<"wPass: "<<wPass<<endl;
    fOut->Write();
    fOut->Close();
}
