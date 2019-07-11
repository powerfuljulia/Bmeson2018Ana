#include "parameters.h"

TH1F * HisSData[NVar];
	TH1F * HisBData[NVar];
	TH1F * HisYData[NVar];
	TH1F * HisSMC[NVar];
	TH1F * HisBMC[NVar];
	TH1F * HisYMC[NVar];
	TH1F * HisGMC[NVar];

TH1F * HisSData[0] =  new TH1F("pthisSData","pthisSData",Npt,ptmin,ptmax);
TH1F * 	HisBData[0] =  new TH1D("pthisBData","pthisBData",Npt,ptmin,ptmax);  
TH1F * 	HisSMC[0] =  new TH1D("pthisSMC","pthisSMC",Npt,ptmin,ptmax);
TH1F * 	HisBMC[0] =  new TH1D("pthisBMC","pthisBMC",Npt,ptmin,ptmax);
	//	 HisYMC[0] =  new TH1D("pthisYMC","pthisYMC",Npt.ptmin,ptmax);  
TH1F * 	HisGMC[0] =  new TH1D("pthisGMC","pthisGMC",Npt,ptmin,ptmax);  

TH1F * 	HisSData[1] =  new TH1F("alphahisSData","alphahisSData",Nalpha,alphamin,alphamax);
TH1F * 	HisBData[1] =  new TH1D("alphahisBData","alphahisBData",Nalpha,alphamin,alphamax);  
TH1F * 	HisSMC[1] =  new TH1D("alphahisSMC","alphahisSMC",Nalpha,alphamin,alphamax);
TH1F * 	HisBMC[1] =  new TH1D("alphahisBMC","alphahisBMC",Nalpha,alphamin,alphamin);
	//	 HisYMC[1] =  new TH1D("alphahisYMC","alphahisYMC",Nalpha.alphamin,alphamin);  
TH1F * 	HisGMC[1] =  new TH1D("alphahisGMC","alphahisGMC",Nalpha,alphamin,alphamax);  

TH1F * 	HisSData[2] =  new TH1F("ProbhisSData","ProbhisSData",NProb,Probmin,Probmax);
TH1F * 	HisBData[2] =  new TH1D("ProbhisBData","ProbhisBData",NProb,Probmin,Probmax);  
TH1F * 	HisSMC[2] =  new TH1D("ProbhisSMC","ProbhisSMC",NProb,Probmin,Probmax);
TH1F * 	HisBMC[2] =  new TH1D("ProbhisBMC","ProbhisBMC",NProb,Probmin,Probmax);  
TH1F * 	HisGMC[2] =  new TH1D("ProbhisGMC","ProbhisGMC",NProb,Probmin,Probmax);  

TH1F * 	HisSData[3] =  new TH1F("RatiohisSData","RatiohisSData",NRatio,Ratiomin,Ratiomax);
TH1F * 	HisBData[3] =  new TH1D("RatiohisBData","RatiohisBData",NRatio,Ratiomin,Ratiomax);  
TH1F * 	HisSMC[3] =  new TH1D("RatiohisSMC","RatiohisSMC",NRatio,Ratiomin,Ratiomax);
TH1F * 	HisBMC[3] =  new TH1D("RatiohisBMC","RatiohisBMC",NRatio,Ratiomin,Ratiomax);  
TH1F * 	HisGMC[3] =  new TH1D("RatiohisGMC","RatiohisGMC",NRatio,Ratiomin,Ratiomax);  



	//	TH1D * pthisY = new new TH1D("pthis","pthis",Npt.ptmin,ptmax);  

	//	TH1D * alphahisS =  new TH1D("alphahis","alphahis",Nalpha,alphamin,alphamax);
	//	TH1D * alphahisB =  new TH1D("alphahis","alphahis",Nalpha,alphamin,alphamax);  
	//	TH1D * alphahisY = new new TH1D("alphahis","alphahis",Nalpha,alphamin,alphamax);  

	//	TH1D * ProbhisS =  new TH1D("Probhis","Probhis",NProb,Probmin,Probmax);  
	//	TH1D * ProbhisB =  new TH1D("Probhis","Probhis",NProb,Probmin,Probmax); 
	//	TH1D * ProbhisY = new new TH1D("Probhis","Probhis",NProb,Probmin,Probmax); 

	//	TH1D * RatiohisS =  new TH1D("Ratiohis","Ratiohis",NRatio,Ratiomin,Ratiomax);  
	//	TH1D * RatiohisB =  new TH1D("Ratiohis","Ratiohis",NRatio,Ratiomin,Ratiomax);  
	//	TH1D * RatiohisY = new new TH1D("Ratiohis","Ratiohis",NRatio,Ratiomin,Ratiomax);  
	/*
	   HisSData[4] =  new TH1D("DyhisSData","DyhisSData",NDy,ppDymin,ppDymax);
	   HisBData[4] =  new TH1D("DyhisBData","DyhisBData",NDy,ppDymin,ppDymax);  
	   HisSMC[4] =  new TH1D("DyhisSMC","DyhisSMC",NDy,ppDymin,ppDymax);
	   HisBMC[4] =  new TH1D("DyhisBMC","DyhisBMC",NDy,ppDymin,ppDymax);  
	   HisGMC[4] =  new TH1D("DyhisGMC","DyhisGMC",NDy,ppDymin,ppDymax);  
	   */
	if(collsyst == "pp"){
TH1F * 		HisSData[4] =  new TH1F("DyhisSData","DyhisSData",NDy,ppDymin,ppDymax);
TH1F * 		HisBData[4] =  new TH1D("DyhisBData","DyhisBData",NDy,ppDymin,ppDymax);  
TH1F * 		HisSMC[4] =  new TH1D("DyhisSMC","DyhisSMC",NDy,ppDymin,ppDymax);
TH1F * 		HisBMC[4] =  new TH1D("DyhisBMC","DyhisBMC",NDy,ppDymin,ppDymax);  
TH1F * 		HisGMC[4] =  new TH1D("DyhisGMC","DyhisGMC",NDy,ppDymin,ppDymax);  
	}


	if(collsyst == "pPb"){
TH1F * 		HisSData[4] =  new TH1F("DyhisSData","DyhisSData",NDy,pPbDymin,pPbDymax);
TH1F * 		HisBData[4] =  new TH1D("DyhisBData","DyhisBData",NDy,pPbDymin,pPbDymax);  
TH1F * 		HisSMC[4] =  new TH1D("DyhisSMC","DyhisSMC",NDy,pPbDymin,pPbDymax);
TH1F * 		HisBMC[4] =  new TH1D("DyhisBMC","DyhisBMC",NDy,pPbDymin,pPbDymax);  
TH1F * 		HisGMC[4] =  new TH1D("DyhisGMC","DyhisGMC",NDy,pPbDymin,pPbDymax);  
	}


