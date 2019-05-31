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

	int NBMassBin = 50;
	double BMassMin = 5.0;
	double BMassMax = 6.0;

	
	double ptMin = 7.0;
	double ptMax = 15.0;
	int CentMinBin = 0;
	int CentMaxBin = 180;


	double PreCutYieldData;
	double PreCutYieldErrData;
	double PreCutYieldMC;
	double PreCutYieldErrMC;


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

	TH1D * DataPre = new TH1D("DataPre","DataPre",NBMassBin,BMassMin,BMassMax);
	TH1D * MCPre = new TH1D("MCPre","MCPre",NBMassBin,BMassMin,BMassMax);


	TH1D * halpha[Nalpha];
	TH1D * hratio[Nratio];
	TH1D * hProb[NProb];

	TH1D * halphaMC[Nalpha];
	TH1D * hratioMC[Nratio];
	TH1D * hProbMC[NProb];

	TF1 *total;
	TF1* fData;
	TF1* fMC;

	TF1* fDataPre;
	TF1* fMCPre;





	TString weightfunctionreco;
	TString cutalpha;
	TString cutalphaMC;






