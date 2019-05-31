//Set your Reweighting parameters here//

	const int NWeightVar = 3;
	const int NWeightUsed = 3;
	int RangeMin[NWeightVar] ={0,-18,0};
	int RangeMax[NWeightVar] ={75,18,200};

	TString Func;
	TString Function[NWeightVar] = {"[0]+[1]*x+[2]*x*x+[3]*x*x*x","[0]*TMath::Exp(-[1]*(x-[2])*(x-[2]))","[0]*TMath::Exp(-[1]*x)"};
	TString WeightVar[NWeightVar] = {"Bpt","PVz","hiBin"};
	TString output = "RewightedFit.root";
	TString RatioVar[NWeightVar]= {"pthisGMCRatio","PVzhisGRatioMC","CentGMCRatio"};


	TString input = "output.root";
	TFile *fin = new TFile(input.Data());

	TH1D * YRatioGMC[NWeightVar];


	TF1 *f1[NWeightVar];

	//int j;
//	TF1 *f1 = new TF1("f1","([0]+[1]*x+[2]*x*x)*TMath::Exp(-[3]*(x-[4])*(x-[4]))+[5]");

	TLegend* leg[NWeightUsed];





