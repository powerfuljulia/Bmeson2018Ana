#include "fitB.h"
using namespace std;

int _nBins = nBins;
double *_ptBins = ptBins;
//const int npnBins=1;
//double npptBins[npnBins+1] = {0,100};
//_nBins = npnBins;
//_ptBins = npptBins;

void fitPrompt(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100., TString BDTcut = "", TString inputmvafs = "")
{

	collisionsystem=collsyst;
	if(collisionsystem=="ppInc"||collisionsystem=="PbPbInc"){
		_nBins = nBinsInc;
		_ptBins = ptBinsInc;
	}

	hiBinMin = centmin*2;
	hiBinMax = centmax*2;
	centMin = centmin;
	centMax = centmax;

	if (!(usePbPb==1||usePbPb==0)) std::cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, you are using a non valid isPbPb option"<<std::endl;
	bool isPbPb=(bool)(usePbPb);

	if(!isPbPb)
	{
		seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
		selmc = Form("%s",cut.Data());
		selmcgen = Form("%s",cutmcgen.Data());
	}
	else
	{
		seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
		selmc = Form("%s&&hiBin>=%f&&hiBin<=%f",cut.Data(),hiBinMin,hiBinMax);
		selmcgen = Form("%s&&hiBin>=%f&&hiBin<=%f",cutmcgen.Data(),hiBinMin,hiBinMax);
	}

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

    TFile* inf = new TFile(inputdata.Data());
	TFile* infMC = new TFile(inputmc.Data());

	std::vector<std::string> mvafiles;
	split2(inputmvafs.Data(), mvafiles, ';');
	TFile* infbdt1 = new TFile(mvafiles[0].c_str());
	TFile* infbdt2 = new TFile(mvafiles[1].c_str());
	//cout<<inputdata<<endl;
	//cout<<mvafiles[0]<<endl;
	//cout<<mvafiles[1]<<endl;
	//return;

	TH1D* h;
	TH1D* hMCSignal;

	TTree* nt;
	TTree* ntbdt1;
	TTree* ntbdt2;
	TTree* ntGen;
	TTree* ntMC;

	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("ntphi");
		nt->AddFriend("ntHlt");
		nt->AddFriend("ntHi");
		nt->AddFriend("ntSkim");
		
		ntbdt1 = (TTree*)infbdt1->Get("BDTStage1_pt7to15");
		ntbdt2 = (TTree*)infbdt2->Get("BDTStage1_pt15to50");
		nt->AddFriend(ntbdt1);
		nt->AddFriend(ntbdt2);
	
		//ntGen = (TTree*)infMC->Get("ntGen");
		//ntGen->AddFriend("ntHlt");
		//ntGen->AddFriend("ntHi");
	
		ntMC = (TTree*)infMC->Get("ntphi");
		//ntMC->AddFriend("ntHlt");
		//ntMC->AddFriend("ntHi");
		//ntMC->AddFriend("ntSkim");
		//ntMC->AddFriend("BDTStage1_pt15to50");
		//ntMC->AddFriend(ntGen);
	}

	TF1 *total;
	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

	TH1D* hPt = new TH1D("hPt","",_nBins,_ptBins);
	TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
	TH1D* hPtGen = new TH1D("hPtGen","",_nBins,_ptBins);
	TH1D* hMean = new TH1D("hMean","",_nBins,_ptBins);                       
	TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",_nBins,_ptBins); 
	TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",_nBins,_ptBins); 

	weightgen = weightgen_pp;
	weightmc  = weightmc_pp;
	if(usePbPb){
		weightgen = weightgen_PbPb;
		weightmc = weightmc_PbPb;
	}

    TString _prefix = "";
    if(fitOnSaved) _prefix = "OnSaved";
    TString _isMC = "data";
    if(isMC) _isMC = "mc";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	for(int i=0;i<_nBins;i++)
	{
    	_count++;
		TCanvas* c= new TCanvas(Form("c%d",_count),"",600,600);
        TCanvas* cMC= new TCanvas(Form("cMC%d",_count),"",600,600);
		if(fitOnSaved == 0){
			drawOpt = 0;
			h = new TH1D(Form("h%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
			hMCSignal = new TH1D(Form("hMCSignal%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
    		if(isMC==1) nt->Project(Form("h%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
		    else        nt->Project(Form("h%d",_count),"Bmass",   Form("(%s&&%s>%f&&%s<%f)*(1/%s)",                seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			ntMC->Project(Form("hMCSignal%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)",weightmc.Data(),Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
		}
		//TF1* f = fit(c, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit);
        TF1* f = fit(c, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit, onlyBG);

		double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
		double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
        printf("yield: %f, yieldErr: %f\n", yield, yieldErr);
		yieldErr = yieldErr*_ErrCor;

		hPt->SetBinContent(i+1,yield/(_ptBins[i+1]-_ptBins[i]));
		hPt->SetBinError(i+1,yieldErr/(_ptBins[i+1]-_ptBins[i]));
		hMean->SetBinContent(i+1,f->GetParameter(1));
		hMean->SetBinError(i+1,f->GetParError(1));  

	    TLatex* tex;
	    tex = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
	    tex->SetNDC();
	    tex->SetTextFont(42);
	    tex->SetTextSize(0.055);
	    tex->SetLineWidth(2);
	    tex->Draw();
	
	    tex = new TLatex(0.735,0.75,"|y| < 2.4");
	    tex->SetNDC();
	    tex->SetTextFont(42);
	    tex->SetTextSize(0.055);
	    tex->SetLineWidth(2);
	    tex->Draw();

        c->SaveAs(Form("%s%s/%s_%s_%.0f_%.0f%s_%s.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_ptBins[i],_ptBins[i+1],_postfix.Data(),BDTcut.Data()));
	}  
	return;
}

int main(int argc, char *argv[])
{
	if(argc==21)
	{
		fitPrompt(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]), argv[19], argv[20]);
		return 0;
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
}
