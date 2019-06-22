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

const int NVar = 6;

TString Var[NVar] = {"Balpha","BsvpvDistance/BsvpvDisErr","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50"}; 
TString VarXName[NVar] = {"Balpha","BsvpvDistance/BsvpvDisErr","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50"}; 
TString VarHisName[NVar] = {"Balpha","DecayLength Significance","B Vertext Probability","BDT pt at [7,15]","BDT pt at [15,20]","BDT pt at [20,50]"}; 
TString VarName[NVar] = {"Balpha","DecaySig","Bchi2cl","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50"}; 

TString Direction[NVar] = {"<",">",">",">",">",">"}; 


int CutValueXBin;
double VarCutMin[NVar] = {0.02,2.0,0.10,-0.30,-0.30,-0.30};
double VarCutMax[NVar] = {0.30,14.0,0.40,0.70,0.70,0.70};
int NCut[NVar] = {10,10,10,10,10,10};
double NVarStep[NVar];


double VarHisMin[NVar] = {0.00,0,0.00,-1.0,-1.0,-1.0};
double VarHisMax[NVar] = {1.00,14.0,1.00,1.0,1.0,1.0};
int VarHisN[NVar] = {100,100,100,100,100,100};




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






