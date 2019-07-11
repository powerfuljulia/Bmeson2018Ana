int isPbPb;
const int Nalpha = 5;
const int Nratio = 5;
const int NProb = 5;
double alpha;
double ratio;
double Prob;
double alphaini=0.02;
double ratioini=4.0;
double Probini=0.10;
double alphafin=0.12;
double ratiofin=6.0;
double Probfin=0.40;
double alphastep = (alphafin - alphaini)/Nalpha;
double ratiostep = (ratiofin - ratioini)/Nratio;
double Probstep = (Probfin - Probini)/NProb;

const int NVar = 10;

TString Var[NVar] = {"Balpha","BsvpvDistance/BsvpvDisErr","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50","abs(Btrk1Dxy1/Btrk1DxyError1)","abs(Btrk2Dxy1/Btrk2DxyError1)","abs(Btrk1Dz1/Btrk1DzError1)","abs(Btrk2Dz1/Btrk2DzError1)"}; 
TString VarXName[NVar] = {"Balpha","BsvpvDistance/BsvpvDisErr","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50","Btrk1DxySig","Btrk2DxySig","Btrk1DzSig","Btrk2DzSig"}; 
TString VarHisName[NVar] = {"Balpha","DecayLength Significance","B Vertext Probability","BDT pt at [7,15]","BDT pt at [15,20]","BDT pt at [20,50]","Leading Track 2D DCA Significance","Other Track 2D DCA Significance","Leading Track DCAz Significance","Other Track DCAz Significance"}; 
TString VarName[NVar] = {"Balpha","DecaySig","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50","Btrk1DxySig","Btrk2DxySig","Btrk1DzSig","Btrk2DzSig"}; 

TString Direction[NVar] = {"<",">",">",">",">",">",">",">",">",">"}; 
TString VarPtRange[NVar] = {"Bpt > 1","Bpt > 1","Bpt > 1","Bpt > 7 && Bpt < 15","Bpt > 15 && Bpt < 20","Bpt > 20 && Bpt < 50","Bpt > 1","Bpt > 1","Bpt > 1","Bpt > 1"}; 
TString OutSideCut[NVar] = {"Bpt < 1","Bpt < 1","Bpt < 1","Bpt < 7 || Bpt > 15","Bpt < 15 || Bpt > 20","Bpt < 20 || Bpt > 50","Bpt < 1","Bpt < 1","Bpt < 1","Bpt < 1"};

int CutValueXBin;
double VarCutMin[NVar] = {0.02,2.0,0.10,-0.20,-0.20,-0.20,0,0,0,0};
double VarCutMax[NVar] = {0.12,18.0,0.40,0.50,0.50,0.50,10,10,10,10};
int NCut[NVar] = {10,10,10,10,10,10,10,10,10,10};
double NVarStep[NVar];

double VarHisMin[NVar] = {0.00,0,0.00,-0.30,-0.30,-0.30,0,0,0,0};
double VarHisMax[NVar] = {0.12,20.0,1.00,0.70,0.70,0.70,10,10,10,10};
int VarHisN[NVar] = {100,100,100,100,100,100,100,100,100,100};




double CutValue;

TString VarCutData;
TString VarCutMC;


TString BptWeight;
TString CentWeight;
TString PVzWeight;



TH1D * ResultHis; 

int NBMassBin = 50;
double BMassMin = 5.0;
double BMassMax = 6.0;


TH1D * HisData;
TH1D * HisMC;



double ptMin = 7.0;
double ptMax = 15.0;
int CentMinBin = 0;
int CentMaxBin = 180;




double PreCutYieldData;
double PreCutYieldErrData;
double PreCutYieldMC;
double PreCutYieldErrMC;


double YieldData;
double YieldErrData;
double YieldMC;
double YieldErrMC;

double doubleratio;
double doubleratioErr;


double YieldDataAlpha;
double YieldErrDataAlpha;
double YieldMCAlpha;
double YieldErrMCAlpha;


double DataRatio;
double DataRatioErr;

double MCRatio;
double MCRatioErr;

double doubleratioalpha;
double doubleratioalphaErr;

TF1 *total;
TF1* fData;
TF1* fMC;

TF1* fDataPre;
TF1* fMCPre;






TString weightfunctionreco;
TString cutalpha;
TString cutalphaMC;






