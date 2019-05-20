//const int nBins=4;
//double ptBins[nBins+1] = {5.,10.,15.,20.,60.};

const int nBins=3;
double ptBins[nBins+1] = {7.,15,20,50.};


//const int nBins=20;
//double ptBins[nBins+1] = {0,5.,10.,15.,20.,25,30,35,40,45,50,55,60.,65,70,75,80,85,90,95,100};

//const int nBins=30;
//double ptBins[nBins+1] = {0,2,4,6.,8,10.,12,14.,16,18,20.,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50.,52,54,56,58,60};


const int nBinsInc=3;
double ptBinsInc[nBinsInc+1] = {7.,15,20,50.};

const int nBinsFine=43;
double ptBinsFine[nBinsFine+1] = {7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50.};

const int nBinsY=4;
double ptBinsY[nBinsY+1] = {0.0, 0.5, 1.0, 1.5, 2.4};

const int nBinsCent=4;
double ptBinsCent[nBinsCent+1] = {0.*2,10*2.,30.*2,50.*2,100*2};
double TAA[nBinsCent] = {23.22, 11.51, 3.819, 0.4395};
double npart[nBinsCent] = {358.8, 226.7, 109.2, 21.87};
//https://twiki.cern.ch/twiki/pub/CMS/HiCentrality2016/AN-15-080_temp_20160802.pdf
//https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideHeavyIonCentrality?rev=100#Ncoll_Npart_5_TeV
//https://twiki.cern.ch/twiki/pub/CMS/HI2015DailyMeetings/Ncoll_Npart_04Dec2015.pdf

const int nBinsReweight=4;
double ptBinsReweight[nBinsReweight+1]={5.,10.,15.,20.,60};
//const int nBinsReweight=20;
//double ptBinsReweight[nBins+1] = {0,5.,10.,15.,20.,25,30,35,40,45,50,55,60.,65,70,75,80,85,90,95,100};

//const int nBinsReweight=30;
//double ptBinsReweight[nBins+1] = {0,2,4,6.,8,10.,12,14.,16,18,20.,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50.,52,54,56,58,60};

const int BIN_NUM= 1196;
const int HMIN=1;
const int HMAX=300;

const double binsize=((double)(HMAX)-(double)(HMIN))/(double)(BIN_NUM);
Double_t BRchain=3.118974e-5; //Bs->JpsiPhi = 0.107%, Jpsi->mumu = 5.961%, Phi->KK = 48.9%



