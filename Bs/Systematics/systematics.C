#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>
const int nPtBins=2;
double PtBins[nPtBins+1] = {7,15,50};
const int nPtBins750=3;
double PtBins750[nPtBins750+1] = {7,15,20,50};
// =============================================================================================================
// B meson decay
// =============================================================================================================
double BRUncertainty	= 7.57;// from PDG sqrt((0.08/1.07)^2+(0.033/5.961)^2+(0.5/48.9)^2) = 0.07566508149

// =============================================================================================================
// pp uncertainty
// =============================================================================================================
// Normalization uncertainty
double ppLumiUncertainty = 2.3;     // B+ paper
double ppTrackingEfficiency	= 4*2; // single track systematics from D* studies
double PbPbTrackingEfficiency = 6*2; // from charged particle analysis, paper
//double ppAlignment = 2.8;              // alignment systematic from pp 13 TeV analysis
//double PbPbAlignment = 2.8;            // alignment systematic from pp 13 TeV analysis
double ppAlignment = 0;
double PbPbAlignment = 0;
double ppLifetime = 0.3;               // from 13 TeV analysis
double PbPbLifetime = 0.3;             // from 13 TeV analysis
TH1D*  ppSignalExtractionSigVar;
TH1D*  ppSignalExtractionBkgVar;
TH1D*  ppMesonSelection;
TH1D*  ppTagAndProbe;
TH1D*  ppAccUnc;
TH1D*  ppPtShape;
TFile* ppMCEfffile;
TH1D* ppEff;

// =============================================================================================================
// PbPb uncertainty
// =============================================================================================================
// Normalization uncertainty
double PbPbNMBUncertainty	= 2;		// B+ paper
double TAAUncertainty0to100	= 8.9;	    // B+ paper
double TAAUncertainty0to100HI = 2.8;	// B+ paper 
double TAAUncertainty0to100LO = 3.4;	// B+ paper 
double TAAUncertainty0to10	= 1.7;		// B+ paper
TH1D*  PbPbSignalExtractionSigVar;
TH1D*  PbPbSignalExtractionBkgVar;
TH1D*  PbPbMesonSelection;				               
TH1D*  PbPbTagAndProbe;				                
TH1D*  PbPbAccUnc;
TH1D*  PbPbPtShape;
TFile* PbPbMCEfffile;
TH1D* PbPbEff;
// RAA uncertainty, for systematic that can cancel such as PDF variation
TH1D*  RAASignalExtraction;

bool initialized = 0;
void initializationPP(int SysOpt=0)
{

	ppMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPP.root");
	ppEff = (TH1D*)ppMCEfffile->Get("hEff");
	ppMesonSelection = new TH1D("ppMesonSelection","",nPtBins,PtBins);
	ppSignalExtractionSigVar = new TH1D("ppSignalExtractionSigVar","",nPtBins,PtBins);
	ppSignalExtractionBkgVar = new TH1D("ppSignalExtractionBkgVar","",nPtBins,PtBins);
	ppTagAndProbe = new TH1D("ppTagAndProbe","",nPtBins,PtBins); 
	ppAccUnc = new TH1D("ppAccUnc","",nPtBins,PtBins);
	ppPtShape = new TH1D("ppPtShape","",nPtBins,PtBins);
	double selUnc_pp[2] = {15.277593, 2.628019, };
	double extUncSig_pp[2] = {2.517970, 0.694141, };
	double extUncBkg_pp[2] = {3.425758, 1.560557, };
	double tnpUnc_pp[2] = {4.411893, 3.133342, };
	double AccUnc_pp[nPtBins] = {1.702369, 1.756477, };
	double ptshape_pp[2] = {6.453736, 2.288807, };
	for(int i = 0; i < nPtBins; i++){
		ppMesonSelection->SetBinContent(i+1, selUnc_pp[i]);
		ppSignalExtractionSigVar->SetBinContent(i+1, extUncSig_pp[i]);
		ppSignalExtractionBkgVar->SetBinContent(i+1, extUncBkg_pp[i]);
		ppTagAndProbe->SetBinContent(i+1,tnpUnc_pp[i]);
		ppAccUnc->SetBinContent(i+1,AccUnc_pp[i]);
		ppPtShape->SetBinContent(i+1,ptshape_pp[i]);
	}
	if(SysOpt==1){//for Bs Bp ratio
		ppTrackingEfficiency = 4; 
		ppTagAndProbe = new TH1D("ppTagAndProbeOpt1","",nPtBins,PtBins); 
		double tnpUnc_ppOpt1[2] = {0., 0.};
		double AccUnc_ppOpt1[nPtBins] = {0., 0.};
		for(int i = 0; i < nPtBins; i++){
			ppTagAndProbe->SetBinContent(i+1,tnpUnc_ppOpt1[i]);//assume canceled
			ppAccUnc->SetBinContent(i+1,AccUnc_ppOpt1[i]);//assume canceled
		}
	}
	if(SysOpt==2){//pp 3-bin result
		ppMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPP_750.root");
		ppEff = (TH1D*)ppMCEfffile->Get("hEff");
		ppMesonSelection = new TH1D("ppMesonSelection","",nPtBins750,PtBins750);
		ppSignalExtractionSigVar = new TH1D("ppSignalExtractionSigVar","",nPtBins750,PtBins750);
		ppSignalExtractionBkgVar = new TH1D("ppSignalExtractionBkgVar","",nPtBins750,PtBins750);
		ppTagAndProbe = new TH1D("ppTagAndProbe_750","",nPtBins750,PtBins750); 
		ppAccUnc = new TH1D("ppAccUnc_750","",nPtBins750,PtBins750);
		ppPtShape = new TH1D("ppPtShape_750","",nPtBins750,PtBins750);
		double selUnc_pp_750[3] = {selUnc_pp[0], selUnc_pp[1], selUnc_pp[1],};
		double extUncSig_pp_750[3] = {extUncSig_pp[0], extUncSig_pp[1], extUncSig_pp[1], };//maybe need update 
		double extUncBkg_pp_750[3] = {extUncBkg_pp[0], extUncBkg_pp[1], extUncBkg_pp[1], };//maybe need update
		double tnpUnc_pp_750[3] = {4.411893, 3.306750, 2.955307, };
		double AccUnc_pp_750[3] = {1.702369, 1.367577, 1.689249, };
		double ptshape_pp_750[3] = {6.453736, 0.464262, 0.903425, };
		for(int i = 0; i < nPtBins750; i++){
			ppMesonSelection->SetBinContent(i+1, selUnc_pp_750[i]);
			ppSignalExtractionSigVar->SetBinContent(i+1, extUncSig_pp_750[i]);
			ppSignalExtractionBkgVar->SetBinContent(i+1, extUncBkg_pp_750[i]);
			ppTagAndProbe->SetBinContent(i+1,tnpUnc_pp_750[i]);
			ppAccUnc->SetBinContent(i+1,AccUnc_pp_750[i]);
			ppPtShape->SetBinContent(i+1,ptshape_pp_750[i]);
		}
	}
}

void initializationPbPbCent0100(int SysOpt=0)
{
	PbPbMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb.root");
	PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");
	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
	PbPbSignalExtractionSigVar = new TH1D("PbPbSignalExtractionSigVar","",nPtBins,PtBins);
	PbPbSignalExtractionBkgVar = new TH1D("PbPbSignalExtractionBkgVar","",nPtBins,PtBins);
	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBins,PtBins);
	PbPbAccUnc = new TH1D("PbPbAccUnc","",nPtBins,PtBins);
	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBins,PtBins);
	double selUnc_pbpb[2] = {18.595802, 8.551800, };
	double extUncSig_pbpb[2] = {4.201315, 3.479940, };
	double extUncBkg_pbpb[2] = {8.747003, 0.675209, };
	double tnpUnc_pbpb[2] = {5.059860, 3.776518, };
	double AccUnc_PbPb[nPtBins] = {1.662617, 1.732661, };
    double ptshape_PbPb[2] = {7.909751, 3.812999, };
	for(int i = 0; i < nPtBins; i++){
		PbPbMesonSelection->SetBinContent(i+1, selUnc_pbpb[i]);
		PbPbSignalExtractionSigVar->SetBinContent(i+1, extUncSig_pbpb[i]);
		PbPbSignalExtractionBkgVar->SetBinContent(i+1, extUncBkg_pbpb[i]);
		PbPbTagAndProbe->SetBinContent(i+1,tnpUnc_pbpb[i]);
		PbPbAccUnc->SetBinContent(i+1,AccUnc_PbPb[i]);
		PbPbPtShape->SetBinContent(i+1,ptshape_PbPb[i]);
	}
	if(SysOpt==1){// for Bs Bp ratio
		PbPbTrackingEfficiency = 6;
		PbPbTagAndProbe = new TH1D("PbPbTagAndProbeOpt1","",nPtBins,PtBins); 
		double tnpUnc_PbPbOpt1[2] = {0., 0.};
		double AccUnc_PbPbOpt1[nPtBins] = {0., 0.};
		for(int i = 0; i < nPtBins; i++){
			PbPbTagAndProbe->SetBinContent(i+1,tnpUnc_PbPbOpt1[i]);//assume canceled
			PbPbAccUnc->SetBinContent(i+1,AccUnc_PbPbOpt1[i]);//assume canceled
		}
	}
}

void initializationRAA(int SysOpt=0)
{
}

void initializationPbPbCent010(int SysOpt=0)
{
}

void initialization(double centL=0,double centH=100,int SysOpt=0){
	initializationPP(SysOpt);
	initializationRAA(SysOpt);
	if (centL==0&&centH==10) initializationPbPbCent0100(SysOpt);
	else initializationPbPbCent0100(SysOpt);
	initialized=1;
}

// =============================================================================================================
// RAA systematics
// =============================================================================================================
float normalizationUncertaintyForRAA(bool TAAhi = 1, double centL=0,double centH=100)
{
	double sys = 0;
	sys+=ppLumiUncertainty*ppLumiUncertainty;
	sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
	if (centL==0&&centH==10) {
		// 0-10%
		sys+=TAAUncertainty0to10*TAAUncertainty0to10;
	} 
	else {
		// 0-100%a
		if(TAAhi == 1)
			sys+=TAAUncertainty0to100LO*TAAUncertainty0to100LO;
		if(TAAhi == 0)
			sys+=TAAUncertainty0to100HI*TAAUncertainty0to100HI;
	}
	return sqrt(sys);
}

float systematicsForRAA(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	if (stage==1) return sqrt(sys);

	sys+= PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt))*
		PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt));
	sys+= PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt))*
		PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt));
	sys+= ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt))*
		ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt));
	sys+= ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt))*
		ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsForRAA_Correlated(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt))*
		PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt));
	sys+= PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt))*
		PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt));
	sys+= ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt))*
		ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt));
	sys+= ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt))*
		ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt));

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsForRAA_UnCorrelated(double pt, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);

	double sys=0;

	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for pp
// =============================================================================================================
float normalizationUncertaintyForPP()
{
	return sqrt((BRUncertainty*BRUncertainty)+(ppLumiUncertainty*ppLumiUncertainty));
}

float systematicsPP(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(0, 100, SysOpt);
	double sys=0;

	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	if (stage==1) return sqrt(sys);

	sys+= ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt))* 
		ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt));
	sys+= ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt))* 
		ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	return sqrt(sys);
}

float systematicsPP_Correlated(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(0, 100, SysOpt);
	double sys=0;
	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt))* 
		ppSignalExtractionSigVar->GetBinContent(ppSignalExtractionSigVar->FindBin(pt));
	sys+= ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt))* 
		ppSignalExtractionBkgVar->GetBinContent(ppSignalExtractionBkgVar->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));

	return sqrt(sys);
}

float systematicsPP_UnCorrelated(double pt, double HLT=0, int stage=0, int SysOpt=0)
{
	if (!initialized) initialization(0, 100, SysOpt);
	double sys=0;
	if (pt < PtBins[0]) return 0;
	if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= ppPtShape->GetBinContent(ppPtShape->FindBin(pt))*
		ppPtShape->GetBinContent(ppPtShape->FindBin(pt));
	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for PbPb
// =============================================================================================================
float normalizationUncertaintyForPbPb(bool TAAhi=1, double centL=0,double centH=100)
{
	double sys = ((BRUncertainty*BRUncertainty)+(PbPbNMBUncertainty*PbPbNMBUncertainty));
	if (centL==0&&centH==10) {
		// 0-10%
		sys+=TAAUncertainty0to10*TAAUncertainty0to10;
	} else {
		// 0-100%
		if(TAAhi == 1)
			sys+=TAAUncertainty0to100HI*TAAUncertainty0to100HI;
		if(TAAhi == 0)
			sys+=TAAUncertainty0to100LO*TAAUncertainty0to100LO;
	}   
	return sqrt(sys);
}

float systematicsPbPb(double pt, bool TAAhi = 1, double centL=0,double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);
	double sys=0;
    if (pt < PtBins[0]) return 0;
    if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;
    if (stage==1) return sqrt(sys);

	sys+= PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt))* 
		PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt));
	sys+= PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt))* 
		PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt));

    if (stage==2) return sqrt(sys);

	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;
    if (stage==3) return sqrt(sys);

	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));
	return sqrt(sys);
}

float systematicsPbPb_Correlated(double pt, bool TAAhi = 1, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);
	double sys=0;
    if (pt < PtBins[0]) return 0;
    if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt))* 
		PbPbSignalExtractionSigVar->GetBinContent(PbPbSignalExtractionSigVar->FindBin(pt));
	sys+= PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt))* 
		PbPbSignalExtractionBkgVar->GetBinContent(PbPbSignalExtractionBkgVar->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsPbPb_UnCorrelated(double pt, bool TAAhi = 1, double centL=0, double centH=100, double HLT=0, int stage=0, int SysOpt=0)
{
	initialization(centL,centH,SysOpt);
	double sys=0;
    if (pt < PtBins[0]) return 0;
    if (pt >= PtBins[nPtBins]) pt = PtBins[nPtBins]-0.1;

	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;
	sys+= PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
		PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));
	return sqrt(sys);
}

// =============================================================================================================
// Drawer
// =============================================================================================================
void drawSys(double x1,double y1, double x2,double y2, int color = 1)
{
	TLine *l1 = new TLine(x1,y1/100.,x2,y2/100.);
	TLine *l2 = new TLine(x1,-y1/100.,x2,-y2/100.);
	l1->SetLineWidth(2);
	l2->SetLineWidth(2);
	l1->SetLineColor(color);
	l2->SetLineColor(color);
	l1->Draw();
	l2->Draw();
}

// =============================================================================================================
// Plot systematics for RAA
// =============================================================================================================
void plotSystematicsRAA(double centL=0,double centH=100)
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-1.,1.);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B_{s} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6,normalizationUncertaintyForRAA(centL,centH), 6.5,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForRAA(centL,centH),2);

	drawSys(PtBins[0],0, PtBins[0],systematicsForRAA(PtBins[0],centL,centH,0,0),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsForRAA(PtBins[nPtBins],centL,centH,0,0),1);

	for (double i=PtBins[0];i<=PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsForRAA(i,centL,centH,0,0), i+0.1,systematicsForRAA(i+0.1,centL,centH,0,0),1);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))-(systematicsForRAA(i,centL,centH,0,1)*systematicsForRAA(i,centL,centH,0,1))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))-(systematicsForRAA(i+0.1,centL,centH,0,1)*systematicsForRAA(i+0.1,centL,centH,0,1))),4);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))-(systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))-(systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,0)*systematicsForRAA(i,centL,centH,0,0))-(systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,0)*systematicsForRAA(i+0.1,centL,centH,0,0))-(systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);
	TH1D *h7 = new TH1D("h7","",100,0,1);
	h7->SetLineWidth(2); h7->SetLineColor(kYellow);

	TLatex* texlumi = new TLatex(0.19,0.936,"28.0 pb^{-1} (5.02 TeV pp) + 351 #mub^{-1} (5.02 TeV PbPb)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.036);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B_{s} R_{AA}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TString texper="%";
	TLatex * tlatexeff2 = new TLatex(0.5268456,0.7678883,Form("Centrality %.0f-%.0f%s",centL,centH,texper.Data()));//0.2612903,0.8425793
	tlatexeff2->SetNDC();
	tlatexeff2->SetTextColor(1);
	tlatexeff2->SetTextFont(42);
	tlatexeff2->SetTextSize(0.045);
	tlatexeff2->SetLineWidth(2);
	//tlatexeff2->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (N_{MB}, Lumi)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();
	canvas->SaveAs("SystematicSummaryRAA.pdf");
	canvas->SaveAs("SystematicSummaryRAA.png");
}

// =============================================================================================================
// Plot systematics for cross section
// =============================================================================================================
void plotSystematicsPP()
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-1.,1.);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B_{s} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForPP(),2);
	drawSys(6,normalizationUncertaintyForPP(), 6.5,normalizationUncertaintyForPP(),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForPP(),2);

	drawSys(PtBins[0],0, PtBins[0],systematicsPP(PtBins[0]),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsPP(PtBins[nPtBins]),1);

	for (double i=PtBins[0];i<PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsPP(i,0,0), i+0.1,systematicsPP(i+0.1,0,0),1);
		drawSys(i,sqrt((systematicsPP(i,0,2)*systematicsPP(i,0,2))-(systematicsPP(i,0,1)*systematicsPP(i,0,1))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))-(systematicsPP(i+0.1,0,1)*systematicsPP(i+0.1,0,1))),4);
		drawSys(i,sqrt((systematicsPP(i,0,3)*systematicsPP(i,0,3))-(systematicsPP(i,0,2)*systematicsPP(i,0,2))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))-(systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsPP(i,0,0)*systematicsPP(i,0,0))-(systematicsPP(i,0,3)*systematicsPP(i,0,3))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,0)*systematicsPP(i+0.1,0,0))-(systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);

	TLatex* texlumi = new TLatex(0.35,0.936,"28.0 pb^{-1} (5.02 TeV pp)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.045);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B_{s} d#sigma / dp_{T}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (Lumi + BR)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();

	canvas->SaveAs("SystematicSummaryPP.pdf");
	canvas->SaveAs("SystematicSummaryPP.png");
}
void plotSystematicsPbPb()
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-1.,1.);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B_{s} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForPbPb(),2);
	drawSys(6,normalizationUncertaintyForPbPb(), 6.5,normalizationUncertaintyForPbPb(),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForPbPb(),2);

	drawSys(PtBins[0],0, PtBins[0],systematicsPbPb(PtBins[0],1,0,100),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsPbPb(PtBins[nPtBins],1,0,100),1);

	for (double i=PtBins[0];i<PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsPbPb(i,1,0,100,0,0), i+0.1,systematicsPbPb(i,1,0,100+0.1,0,0),1);
		drawSys(i,sqrt((systematicsPbPb(i,1,0,100,0,2)*systematicsPbPb(i,1,0,100,0,2))-(systematicsPbPb(i,1,0,100,0,1)*systematicsPbPb(i,1,0,100,0,1))),
				i+0.1,sqrt((systematicsPbPb(i+0.1,1,0,100,0,2)*systematicsPbPb(i+0.1,1,0,100,0,2))-(systematicsPbPb(i+0.1,1,0,100,0,1)*systematicsPbPb(i+0.1,1,0,100,0,1))),4);
		drawSys(i,sqrt((systematicsPbPb(i,1,0,100,0,3)*systematicsPbPb(i,1,0,100,0,3))-(systematicsPbPb(i,1,0,100,0,2)*systematicsPbPb(i,1,0,100,0,2))),
				i+0.1,sqrt((systematicsPbPb(i+0.1,1,0,100,0,3)*systematicsPbPb(i+0.1,1,0,100,0,3))-(systematicsPbPb(i+0.1,1,0,100,0,2)*systematicsPbPb(i+0.1,1,0,100,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsPbPb(i,1,0,100,0,0)*systematicsPbPb(i,1,0,100,0,0))-(systematicsPbPb(i,1,0,100,0,3)*systematicsPbPb(i,1,0,100,0,3))),
				i+0.1,sqrt((systematicsPbPb(i+0.1,1,0,100,0,0)*systematicsPbPb(i+0.1,1,0,100,0,0))-(systematicsPbPb(i+0.1,1,0,100,0,3)*systematicsPbPb(i+0.1,1,0,100,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);

	TLatex* texlumi = new TLatex(0.35,0.936,"351 #mub^{-1} (5.02 TeV PbPb)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.045);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B_{s} d#sigma / dp_{T}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (N_{MB} + BR)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();

	canvas->SaveAs("SystematicSummaryPbPb.pdf");
	canvas->SaveAs("SystematicSummaryPbPb.png");
}

void plotNormalisationUnc(){
	std::cout<<"normalisation uncertainty RAA 0-100="<<normalizationUncertaintyForRAA(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty RAA 0-10="<<normalizationUncertaintyForRAA(0,10)<<std::endl;
	std::cout<<"normalisation uncertainty pp="<<normalizationUncertaintyForPP()<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-100="<<normalizationUncertaintyForPbPb(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-10="<<normalizationUncertaintyForPbPb(0,10)<<std::endl;
}
