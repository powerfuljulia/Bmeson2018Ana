//Set your parameters here//

//const int NBins = 6;
//const double ptBins[NBins+1]={1,2,3,5,8,12,20};

//const int NBins = 3;
//const double ptBins[NBins+1]={7,15,20,50};
const int NBins = 1;
const double ptBins[NBins+1]={5,200};


//const int NVar = 14;
const int NVar = 26;

double width = 0.08;
double sidemin = 0.20;
double sidemax = 0.30;
double center = 5.36682;

const int Npt = 18;
double ptmin = 2;
double ptmax = 20;

const int Nalpha = 20;
double alphamin = 0;
double alphamax = 0.20;

const int NProb = 20;
double Probmin = 0;
double Probmax = 1.0;

const int NRatio = 20;
double Ratiomin = 3;
double Ratiomax = 20;

const int NBy = 20;
/*
double ppDymin = -1.0;
double ppDymax = 1.0;
double pPbDymin = ppDymin + 0.465;
double pPbDymax = ppDymax + 0.465;
*/
double Bymin = -2.4;
double Bymax = 2.4;


const int NBDTG = 30;
const double BDTGMin = 0.2;
const double BDTGMax = 0.9;


const int NBtrk1D0 = 20;
const double Btrk1D0Min = -0.3;
const double Btrk1D0Max = 0.3;

const int NBtrk2D0 = 20;
const double Btrk2D0Min = -0.3;
const double Btrk2D0Max = 0.3;

const int NBtrk1D0Err = 20;
const double Btrk1D0ErrMin = 0;
const double Btrk1D0ErrMax = 0.2;

const int NBtrk2D0Err = 20;
const double Btrk2D0ErrMin = 0;
const double Btrk2D0ErrMax = 0.2;


const int NBtrk1Pt = 20;
const double Btrk1PtMin = 0;
const double Btrk1PtMax = 8;

const int NBtrk2Pt = 20;
const double Btrk2PtMin = 0;
const double Btrk2PtMax = 8;

const int NBtrk1Eta = 20;
const double Btrk1EtaMin = -3;
const double Btrk1EtaMax = 3;

const int NBtrk2Eta = 20;
const double Btrk2EtaMin = -3;
const double Btrk2EtaMax = 3;



const int NBmu1Eta = 20;
const double Bmu1EtaMin = -2;
const double Bmu1EtaMax = 2;

const int NBmu2Eta = 20;
const double Bmu2EtaMin = -2;
const double Bmu2EtaMax = 2;

const int NBmu1Pt = 20;
const double Bmu1PtMin = 0;
const double Bmu1PtMax = 20;

const int NBmu2Pt = 20;
const double Bmu2PtMin = 0;
const double Bmu2PtMax = 20;

const int NDecayTime = 20;
const double DecayTimeMin = 0;
const double DecayTimeMax = 0.05;

const int NBmass = 50;
const double BMassMin = 5.0;
const double BMassMax = 6.0;

const int NBtrk1Dz= 20;
const double Btrk1DzMin = -0.1;
const double Btrk1DzMax = 0.1;

const int NBtrk2Dz = 20;
const double Btrk2DzMin = -0.1;
const double Btrk2DzMax = 0.1;

const int MBD0Ratio = 40;
const double BD0RatioMin = 0;
const double BD0RatioMax = 10000;

const int NBtrk1Y = 40;
const double Btrk1YMin = -3;
const double Btrk1YMax = 3;

const int NBtrk2Y = 40;
const double Btrk2YMin = -3;
const double Btrk2YMax = 3;



double Binning[NVar] ={NBtrk1Y,NBtrk2Y,MBD0Ratio,Npt,Nalpha,NProb,NRatio,NBy,NBDTG,NBDTG,NBDTG,NBtrk1D0,NBtrk2D0,NBtrk1D0Err,NBtrk2D0Err,NBtrk1Pt,NBtrk2Pt,NBmu1Eta,NBmu2Eta,NBmu1Pt,NBmu2Pt,NBmass,NBtrk1Eta,NBtrk2Eta,NBtrk1Dz,NBtrk2Dz};
double Min[NVar]	= {Btrk1YMin,Btrk2YMin,BD0RatioMin,ptmin,alphamin,Probmin,Ratiomin,Bymin,BDTGMin,BDTGMin,BDTGMin,Btrk1D0Min,Btrk2D0Min,Btrk1D0ErrMin,Btrk2D0ErrMin,Btrk1PtMin,Btrk2PtMin,Bmu1EtaMin,Bmu2EtaMin,Bmu1PtMin,Bmu2PtMin,BMassMin,Btrk1EtaMin,Btrk2EtaMin,Btrk1DzMin,Btrk2DzMin};
//double Max[NVar]	= {ptmax,alphamax,Probmax,Ratiomax,Bymax,BDTGMax,Dtrk1D0Max,Dtrk2D0Max,Dtrk1YMax,Dtrk2YMax,DecayTimeMax,DMassMax,Dtrk1EtaMax,Dtrk2EtaMax};
double Max[NVar]	= {Btrk1YMax,Btrk2YMax,BD0RatioMax,ptmax,alphamax,Probmax,Ratiomax,Bymax,BDTGMax,BDTGMax,BDTGMax,Btrk1D0Max,Btrk2D0Max,Btrk1D0ErrMax,Btrk2D0ErrMax,Btrk1PtMax,Btrk2PtMax,Bmu1EtaMax,Bmu2EtaMax,Bmu1PtMax,Bmu2PtMax,BMassMax,Btrk1EtaMax,Btrk2EtaMax,Btrk1DzMax,Btrk2DzMax};


/*
   const int NRatio = 20;
   double Ratiomin = 0;
   double Ratiomax = 50;
   */


//double DyBin[7]={-1,-0.6,-0.3,0,0.3,0.6,1};

double MaxY[NVar] ={0.2,0.2,0.2,0.80,0.25,0.20,0.30,0.20,0.30,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15};

TString VarSData[NVar] = {"Btrk1YhisSData","Btrk2YhisSData","MBD0RatiohisSData","pthisSData","alphahisSData","ProbhisSData","RatiohisSData","ByhisSData","BDT7-15hisSData","BDT15-20hisSData","BDT20-50hisSData","Btrk1D0hisSData","Btrk2D0hisSData","Btrk1D0ErrhisSData","Btrk2D0ErrhisSData","Btrk1PthisSData","Btrk2PthisSData","Bmu1EtahisSData","Bmu2EtahisSData","Bmu1PthisSData","Bmu2PthisSData","BmassSData","Btrk1EtaSData","Btrk2EtaSData","Btrk1DzSData","Btrk2DzSData"};  

TString VarBData[NVar] = {"Btrk1YhisBData","Btrk2YhisBData","alphahisBData","ProbhisBData","RatiohisBData","ByhisBData","BDT7-15hisBData","BDT15-20hisBData","BDT20-50hisBData","Btrk1D0hisBData","Btrk2D0hisBData","Btrk1D0ErrhisBData","Btrk2D0ErrhisBData","Btrk1PthisBData","Btrk2PthisBData","Bmu1EtahisBData","Bmu2EtahisBData","Bmu1PthisBData","Bmu2PthisBData","BmassBData","Btrk1EtaBData","Btrk2EtaBData","Btrk1DzBData","Btrk2DzBData"};  


//TString VarBData[NVar] = {"pthisBData","alphahisBData","ProbhisBData","RatiohisBData","ByhisBData","BDTGhisBData","Btrk1D0hisBData","Btrk2D0hisBData","Dtrk1YhisBData","Dtrk2YhisBData","DecayTimnehisBData","DmassBData","Dtrk1EtaBData","Dtrk2EtaBData"}; 

TString VarYData[NVar] = {"Btrk1YhisYData","Btrk2YhisYData","MBD0RatiohisYData","pthisYData","alphahisYData","ProbhisYData","RatiohisYData","ByhisYData","BDT7-15hisYData","BDT15-20hisYData","BDT20-50hisYData","Btrk1D0hisYData","Btrk2D0hisYData","Btrk1D0ErrhisYData","Btrk2D0ErrhisYData","Btrk1PthisYData","Btrk2PthisYData","Bmu1EtahisYData","Bmu2EtahisYData","Bmu1PthisYData","Bmu2PthisYData","BmassYData","Btrk1EtaYData","Btrk2EtaYData","Btrk1DzYData","Btrk2DzYData"};  


//TString VarYData[NVar] = {"pthisYData","alphahisYData","ProbhisYData","RatiohisYData","ByhisYData","BDTGhisYData","Btrk1D0hisYData","Btrk2D0hisYData","Dtrk1YhisYData","Dtrk2YhisYData","DecayTimnehisYData","DmassYData","Dtrk1EtaYData","Dtrk2EtaYData"};  

TString VarSMC[NVar] = {"Btrk1YhisSMC","Btrk2YhisSMC","MBD0RatiohisSMC","pthisSMC","alphahisSMC","ProbhisSMC","RatiohisSMC","ByhisSMC","BDT7-15hisSMC","BDT15-20hisSMC","BDT20-50hisSMC","Btrk1D0hisSMC","Btrk2D0hisSMC","Btrk1D0ErrhisSMC","Btrk2D0ErrhisSMC","Btrk1PthisSMC","Btrk2PthisSMC","Bmu1EtahisSMC","Bmu2EtahisSMC","Bmu1PthisSMC","Bmu2PthisSMC","BmassSMC","Btrk1EtaSMC","Btrk2EtaSMC","Btrk1DzSMC","Btrk2DzSMC"};

TString VarBMC[NVar] = {"Btrk1YhisBMC","Btrk2YhisBMC","MBD0RatiohisBMC","pthisBMC","alphahisBMC","ProbhisBMC","RatiohisBMC","ByhisBMC","BDT7-15hisBMC","BDT15-20hisBMC","BDT20-50hisBMC","Btrk1D0hisBMC","Btrk2D0hisBMC","Btrk1D0ErrhisBMC","Btrk2D0ErrhisBMC","Btrk1PthisBMC","Btrk2PthisBMC","Bmu1EtahisBMC","Bmu2EtahisBMC","Bmu1PthisBMC","Bmu2PthisBMC","BmassBMC","Btrk1EtaBMC","Btrk2EtaBMC","Btrk1DzBMC","Btrk2DzBMC"};
TString VarYMC[NVar] = {"Btrk1YhisYMC","Btrk2YhisYMC","MBD0RatiohisYMC","pthisYMC","alphahisYMC","ProbhisYMC","RatiohisYMC","ByhisYMC","BDT7-15hisYMC","BDT15-20hisYMC","BDT20-50hisYMC","Btrk1D0hisYMC","Btrk2D0hisYMC","Btrk1D0ErrhisYMC","Btrk2D0ErrhisYMC","Btrk1PthisYMC","Btrk2PthisYMC","Bmu1EtahisYMC","Bmu2EtahisYMC","Bmu1PthisYMC","Bmu2PthisYMC","BmassYMC","Btrk1EtaYMC","Btrk2EtaYMC","Btrk1DzYMC","Btrk2DzYMC"};
TString VarGMC[NVar] = {"Btrk1YhisGMC","Btrk2YhisGMC","MBD0RatiohisGMC","pthisGMC","alphahisGMC","ProbhisGMC","RatiohisGMC","ByhisGMC","BDT7-15hisGMC","BDT15-20hisGMC","BDT20-50hisGMC","Btrk1D0hisGMC","Btrk2D0hisGMC","Btrk1D0ErrhisGMC","Btrk2D0ErrhisGMC","Btrk1PthisGMC","Btrk2PthisGMC","Bmu1EtahisGMC","Bmu2EtahisGMC","Bmu1PthisGMC","Bmu2PthisGMC","BmassGMC","Btrk1EtaGMC","Btrk2EtaGMC","Btrk1DzGMC","Btrk2DzGMC"};



/*
TString VarBMC[NVar] = {"pthisBMC","alphahisBMC","ProbhisBMC","RatiohisBMC","DyhisBMC","BDTGhisBMC","Dtrk1D0hisBMC","Dtrk2D0hisBMC","Dtrk1YhisBMC","Dtrk2YhisBMC","DecayTimehisBMC","DmassBMC","Dtrk1EtaBMC","Dtrk2EtaBMC"};
TString VarYMC[NVar] = {"pthisYMC","alphahisYMC","ProbhisYMC","RatiohisYMC","DyhisYMC","BDTGhisYMC","Dtrk1D0hisYMC","Dtrk2D0hisYMC","Dtrk1YhisYMC","Dtrk2YhisYMC","DecayTimehisYMC","DmassYMC","Dtrk1EtaYMC","Dtrk2EtaYMC"};  
TString VarGMC[NVar] = {"pthisGMC","alphahisGMC","ProbhisGMC","RatiohisGMC","DyhisGMC","BDTGhisGMC","Dtrk1D0hisGMC","Dtrk2D0hisGMC","Dtrk1YhisGMC","Dtrk2YhisGMC","DecayTimehisGMC","DmassGMC","Dtrk1EtaGMC","Dtrk2EtaGMC"};  
*/



TString Var[NVar] = {"Btrk1Y","Btrk2Y","Bd0/Bd0Err","Bpt","Balpha","Bchi2cl","BsvpvDistance/BsvpvDisErr","By","BDT_pt_7_15","BDT_pt_15_20","BDT_pt_20_50","Btrk1D0","Btrk2D0", "Btrk1D0Err", "Btrk2D0Err", "Btrk1Pt", "Btrk2Pt","Bmu1eta","Bmu2eta","Bmu1pt","Bmu2pt","Bmass","Btrk1Eta","Btrk2Eta","Btrk1Dz","Btrk2Dz"};  

TString Name[NVar] = {"Btrk1Y","Btrk2Y","2DDecayLRatio","Bpt","Balpha","Bchi2cl","Ratio","By","BDT_7_15","BDT_15_20","BDT_20_50","Btrk1D0","Btrk2D0","Btrk1D0Err","Btrk2D0Err","Btrk1Pt","Btrk2Pt","Bmu1Eta","Bmu2Eta","Bmu1Pt","Bmu2Pt","Bmass","Btrk1Eta","Btrk2Eta","Btrk1Dz","Btrk2Dz"};  
TString XName[NVar] = {"Btrk1Y","Btrk2Y","2DDecayLRatio","Bpt (GeV/c)","Balpha","Bchi2cl","Ratio","By","BDT_7_15","BDT_15_20","BDT_20_50","Btrk1D0","Btrk2D0","Btrk1D0Err","Btrk2D0Err","Btrk1Pt","Btrk2Pt","Bmu1Eta","Bmu2Eta","Bmu1Pt","Bmu2Pt","Bmass (GeV/c)","Btrk1Eta","Btrk2Eta","Btrk1Dz","Btrk2Dz"};  
TString YName[NVar] = {"Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts","Normalized Counts"};  


TString HisName[NVar] = {"Normalized B Track 1 Rapidity Distribution","Normalized B Track 1 Rapidity Distribution","Normalized 2D Decay Length Ratio Distribution","Normalized Bpt Distribution","Normalized Balpha Distribution","Normalized Vertex Probability Distribution","Normalized Decay Length Ratio Distribution","Normalized By Distribution","Normalized BDT_7_15 Distribution","Normalized BDT_15_20 Distribution","Normalized BDT_20_50 Distribution","Normalized Btrk1D0 Distribution","Normalized Btrk2D0 Distribution","Normalized Btrk1D0Err Distribution","Normalized Btrk2D0Err Distribution","Normalized Btrk1Pt Distribution","Normalized Btrk2Pt Distribution","Normalized Bmu1Eta Distribution","Normalized Bmu2Eta Distribution","Normalized Bmu1Pt Distribution","Normalized Bmu2Pt Distribution","Normalized D Invariant Mass Distribution","Normalized Btrk1Eta Distribution","Normalized Btrk2Eta Distribution","Normalized Btrk1Dz Distribution","Normalized Btrk2Dz Distribution"};  




