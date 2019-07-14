#include <stdio.h>
#include <math.h>
#include <TTree.h>
#include <TH1.h>
#include <TROOT.h>
#include <TFile.h>
#include <TF1.h>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
double gaussianRandom(double average, double stdev);
void getfit();

// pp or PbPb
bool ispp = 0;
string label;

//const int nBins = 5;
//double ptBins[nBins+1] = {7,10,15,20,30,50};


//const int nBins = 4;
//double ptBins[nBins+1] = {5,10.,15.,20.,60};

//const int nBins = 3;
//double ptBins[nBins+1] = {7,15.,20.,50};

const int nBins = 4;
double ptBins[nBins+1] = {5,10.,15.,20.,50};


double Rat[nBins];
double RatErr[nBins];
double RatToy[5];
double a1, a2;

TH1D* hfit;
TH1D* htest;
TF1* flinear;
TTree* ditTree;

void step3RunMCtoy_gaus_ptvar_20141031() {
    if(ispp) label = "pp";
    else label = "PbPb";

	TFile* fIn = new TFile(Form("../step2_GettheRatio/FunctionsReweighting_Bs_%s.root", label.c_str()),"read");
	TH1D*hReweightDataOverMC_Pt=(TH1D*)fIn->Get("hReweightDataOverMC_Pt");
	TFile* fOut = new TFile(Form("gaus_try10k_ptvar_%s.root", label.c_str()),"RECREATE");

	hfit = new TH1D("hfit","",nBins,ptBins);
	htest = new TH1D("htest","",200,0.00,2.00);
	flinear = new TF1("flinear","[0]*x + [1]/x**5",5.0,50.0);

	for (int i=0;i<nBins;i++) {
		Rat[i]=hReweightDataOverMC_Pt->GetBinContent(i+1);
		RatErr[i]=hReweightDataOverMC_Pt->GetBinError(i+1);
		std::cout << "i = " << i << "   Rat = " << Rat[i] << "  , " << "  RatErr =  " << RatErr[i] << std::endl;
	}

	ditTree = new TTree("ditTree","Test tree");
	ditTree->Branch("a1",&a1,"a1/D");
	ditTree->Branch("a2",&a2,"a2/D");

	srand((unsigned int)time(NULL));
	cout << "Start MC" << endl;
	for (int i = 0; i < 100000; i++){
//	cout << "i = " << i << endl;
		hfit->Clear();
		for (int count=0;count<nBins;count++) {
		//	cout << "count = " << count << endl;
			RatToy[count]=gaussianRandom(Rat[count],RatErr[count]);
			printf("%.17f\n", RatToy[count]);
			hfit->SetBinContent(count+1,RatToy[count]);
			if (count==0) htest->Fill(RatToy[count]);
		}
		getfit();
	}
	fOut->Write();
	fOut->Close();
}


double gaussianRandom(double average, double stdev) {
	double v1, v2, s, temp;

	do {

	//double RAND_MAX = 100;
		v1 =  2 * ((double) rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		v2 =  2 * ((double) rand()  / RAND_MAX) - 1;      // -1.0 ~ 1.0 까지의 값
		s = v1 * v1 + v2 * v2;
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;

	} while (s >= 1 || s == 0);
	cout << "s Before  = " << s << endl; 
	s = sqrt( (-2 * log(s)) / s );
	cout << "s After  = " << s << endl; 
	temp = v1*s;
	temp = (stdev*temp)+average;
	return temp;
}

void getfit() {
	hfit->Fit("flinear");
	a1=flinear->GetParameter(0);
	a2=flinear->GetParameter(1);
	ditTree->Fill();
	return;
}

