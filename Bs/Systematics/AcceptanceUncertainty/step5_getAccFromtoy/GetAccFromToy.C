#include <iostream>
#include <cmath>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TNtuple.h>
#include <TMath.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TAxis.h>
#include <TLorentzVector.h>
#include <TLorentzRotation.h>


//const int nBins = 5;
//double ptBins[nBins+1] = {7,10,15,20,30,50};

const int nBins = 4;
double ptBins[nBins+1] = {5,10.,15.,20.,60};
double Rat[nBins];
double RatErr[nBins];
const int nBinsy=4;
double yBins[nBinsy+1] = {0.0, 0.5, 1.0, 1.5, 2.4};
double Ratylab[nBinsy];
double RatErrylab[nBinsy];

bool ispp = 0;
string label;
bool ispt = 1;
string var;

TH1D *hAccCompBin[nBins];
TH1D *hAccYCompBin[nBinsy];
TH1D *hDen1TriPtBin = new TH1D(Form("hDen1TriPtBin"),"",nBins,ptBins);
TH1D *hDen1TriYBin = new TH1D(Form("hDen1TriYBin"),"",nBinsy,yBins);
TH1D *hNum1TriPtBin = new TH1D(Form("hNum1TriPtBin"),"",nBins,ptBins);
TH1D *hNum1TriYBin = new TH1D(Form("hNum1TriYBin"),"",nBinsy,yBins);
TH1D *hAcc1TriPtBin = new TH1D(Form("hAcc1TriPtBin"),"",nBins,ptBins);
TH1D *hAcc1TriYBin = new TH1D(Form("hAcc1TriYBin"),"",nBinsy,yBins);


void GetAccFromToy(){
    if(ispp) label = "pp";
    else label = "PbPb";
    if(ispt) var = "pt";
    else var = "y";

    TFile *ratiofile = new TFile(Form("../step3_MCtoy/gaus_try10k_%svar_%s.root", var.c_str(), label.c_str()));
    TTree *anar = (TTree*)ratiofile->Get("ditTree");
    double a1,a2;
	if(ispt){
	    anar->SetBranchAddress("a1", &a1);
    	anar->SetBranchAddress("a2", &a2);
	}
	else{
	    anar->SetBranchAddress("ay1", &a1);
    	anar->SetBranchAddress("ay2", &a2);
	}


	TFile *inf = new TFile(Form("../step4_SkimBntuple/results_%s.root", label.c_str()));
	TTree *ExclBAna = (TTree*)inf->Get("ExclBAna");
	double pt, y, weight;
	bool passAcc;
    ExclBAna->SetBranchAddress("pt", &pt);
    ExclBAna->SetBranchAddress("y", &y);
    ExclBAna->SetBranchAddress("weight", &weight);
    ExclBAna->SetBranchAddress("passAcc", &passAcc);
	TH1D *hPtProject = new TH1D(Form("hPtProject"),"",nBins,ptBins);
	TH1D *hPtProjectPass = new TH1D(Form("hPtProjectPass"),"",nBins,ptBins);
	TH1D *hPtProjectAcc = new TH1D(Form("hPtProjectAcc"),"",nBins,ptBins);
	TH1D *hyProject = new TH1D(Form("hyProject"),"",nBinsy,yBins);
	TH1D *hyProjectPass = new TH1D(Form("hyProjectPass"),"",nBinsy,yBins);
	TH1D *hyProjectAcc = new TH1D(Form("hyProjectAcc"),"",nBinsy,yBins);
	ExclBAna->Project("hPtProject", "pt", "weight");
	ExclBAna->Project("hPtProjectPass", "pt", "weight*passAcc");
	ExclBAna->Project("hyProject", "abs(y)", "weight");
	ExclBAna->Project("hyProjectPass", "abs(y)", "weight*passAcc");
	hPtProjectAcc->Divide(hPtProjectPass, hPtProject, 1, 1, "B");
	hyProjectAcc->Divide(hyProjectPass, hyProject, 1, 1, "B");
	cout<<hPtProject->Integral()<<endl;
	cout<<hPtProjectPass->Integral()<<endl;
	cout<<hPtProjectAcc->GetBinContent(1)<<endl;;
	cout<<hyProject->Integral()<<endl;
	cout<<hyProjectPass->Integral()<<endl;
	cout<<hyProjectAcc->GetBinContent(1)<<endl;;

    TFile* fnominal = new TFile(Form("../step2_GettheRatio/FunctionsReweighting_Bs_%s.root", label.c_str()),"read");
    TH1D*hReweightDataOverMC_Pt=(TH1D*)fnominal->Get("hReweightDataOverMC_Pt");
    TH1D*hReweightDataOverMC_y=(TH1D*)fnominal->Get("hReweightDataOverMC_y");

    TFile *outfile = new TFile(Form("AccVar_%svar_%s.root",var.c_str(), label.c_str()),"RECREATE");
	for(int i = 0; i < nBins; i++){ 
        Rat[i]=hReweightDataOverMC_Pt->GetBinContent(i+1);
        RatErr[i]=hReweightDataOverMC_Pt->GetBinError(i+1);
        std::cout << Rat[i] << " , " << RatErr[i] << std::endl;
		hAccCompBin[i] = new TH1D(Form("hAccCompBin%d",i+1),"",1000,hPtProjectAcc->GetBinContent(i+1)*0.3,hPtProjectAcc->GetBinContent(i+1)*3.0);
	}
	for(int i = 0; i < nBinsy; i++){ 
        Ratylab[i]=hReweightDataOverMC_Pt->GetBinContent(i+1);
        RatErrylab[i]=hReweightDataOverMC_Pt->GetBinError(i+1);
        std::cout << Ratylab[i] << " , " << RatErrylab[i] << std::endl;
		hAccYCompBin[i] = new TH1D(Form("hAccYCompBin%d",i+1),"",1000,hyProjectAcc->GetBinContent(i+1)*0.8,hyProjectAcc->GetBinContent(i+1)*1.2);
	}

	int nvar = anar->GetEntries();
	int ncand = ExclBAna->GetEntries();
	double ratio = 0;
	double totweight = 0;
double wAll = 0;
	double wPass = 0;
std::cout << "nvar  = " << nvar << std::endl;
    for(int vari=0;vari<nvar;vari++) {

	if(vari%100==0)std::cout << vari <<std::endl;
		//    for(int vari=0;vari<1000;vari++) {
//    for(int vari=0;vari<1;vari++) {
		anar->GetEntry(vari);
		hDen1TriPtBin->Reset();
		hDen1TriYBin->Reset();
		hNum1TriPtBin->Reset();
		hNum1TriYBin->Reset();
		for(int candi = 0; candi < ncand; candi++){
			ExclBAna->GetEntry(candi);			
			if(var == "pt"){
				ratio = a1*pt+a2;
			}
			else{
				ratio = a1*pow(y,2)+a2;
			}
			totweight = weight*ratio;
		//cout<<ratio<<endl;
			//totweight = weight;
			wAll += weight;
            hDen1TriPtBin->Fill(pt,totweight);
            hDen1TriYBin->Fill(y,totweight);
			if(passAcc){
				wPass += weight;
            	hNum1TriPtBin->Fill(pt,totweight);
	            hNum1TriYBin->Fill(y,totweight);
			}
		}//cand loop

		//cout<<"wAll: "<<wAll<<endl;
		//cout<<"wPass: "<<wPass<<endl;
		//cout<<hDen1TriPtBin->Integral()<<endl;
		//cout<<hNum1TriPtBin->Integral()<<endl;

    	hAcc1TriPtBin->Divide(hNum1TriPtBin,hDen1TriPtBin,1,1,"B");
	    hAcc1TriYBin->Divide(hNum1TriYBin,hDen1TriYBin,1,1,"B");
		for(int i = 0; i < nBins; i++){ hAccCompBin[i]->Fill(hAcc1TriPtBin->GetBinContent(i+1));}
	    for(int i = 0; i < nBinsy; i++){ hAccYCompBin[i]->Fill(hAcc1TriYBin->GetBinContent(i+1));}
	}//var loop
	outfile->cd();
	for(int i = 0; i < nBins; i++){ hAccCompBin[i]->Write();}
	for(int i = 0; i < nBinsy; i++){ hAccYCompBin[i]->Write();}
	hDen1TriPtBin->Write(); 
	hDen1TriYBin ->Write();
	hNum1TriPtBin->Write();
	hNum1TriYBin ->Write();
	hAcc1TriPtBin->Write();
	hAcc1TriYBin ->Write();
}
