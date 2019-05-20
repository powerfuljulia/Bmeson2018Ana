#include "fitB.h"
using namespace std;

const int nVar = 2;
string vexp[nVar] = {"Bmumumass", "Btktkmass"};
string vname[nVar] = {"Bmumumass", "Btktkmass"};
string vxaxis[nVar] = {"mumu mass (GeV)", "KK mass (GeV)"};
int vbins[nVar] = {100, 140};
float vbinmin[nVar] = {2.9, 0.98};
float vbinmax[nVar] = {3.4, 1.08};

int _nBins = nBins;
double *_ptBins = ptBins;
void plotSth(int usePbPb = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString trgselectionmc = "", TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
{
	collisionsystem=collsyst;
	if(varExp == "Bpt750"){
		_nBins = nBins750;
		_ptBins = ptBins750;
		varExp = "Bpt";
	}
	if(varExp == "abs(By)"){
		_nBins = nBinsY;
		_ptBins = ptBinsY;
	}
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
		selmc = Form("%s&&%s",trgselectionmc.Data(),cut.Data());
	}
	else
	{
		seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
		selmc = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselectionmc.Data(),cut.Data(),hiBinMin,hiBinMax);
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

	TH1D* h;
	TH1D* hMC;

	TTree* nt;
	TTree* ntMC;

	nt = (TTree*)inf->Get("ntphi");
	//nt->AddFriend("ntHlt");
	//nt->AddFriend("ntHi");
	//nt->AddFriend("ntSkim");
	//nt->AddFriend("BDTStage1_pt15to50");

	ntMC = (TTree*)infMC->Get("ntphi");
	//ntMC->AddFriend("ntHlt");
	//ntMC->AddFriend("ntHi");
	//ntMC->AddFriend("ntSkim");
	//ntMC->AddFriend("BDTStage1_pt15to50");

	TF1 *total;
	TString outputf;
	//outputf = Form("%s",outputfile.Data());
	//TFile* outf = new TFile(outputf.Data(),"recreate");
	//outf->cd();

	weightgen = weightgen_pp;
	weightmc  = weightmc_pp;
	if(usePbPb){
		weightgen = weightgen_PbPb;
		weightmc = weightmc_PbPb;
	}

    TString _prefix = "";
    TString _isMC = "data";
    if(isMC) _isMC = "mc";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	for(int i=0;i<_nBins;i++)
	{
		TCanvas* c= new TCanvas(Form("c%d",i),"",600,600);
	    TLatex* tex1 = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
	    TLatex* tex2 = new TLatex(0.735,0.75,"|y| < 2.4");
	    TLatex* tex3 = new TLatex(0.25, 0.8,"Data");
	    TLatex* tex4 = new TLatex(0.25, 0.8,"MC");
	    TLatex* tex5 = new TLatex(0.25, 0.7,(usePbPb)? "PbPb" : "pp");
		setTex(tex1);
		setTex(tex2);
		setTex(tex3);
		setTex(tex4);
		setTex(tex5);
		tex3->SetTextSize(0.07);

		for(int v = 0; v < nVar; v++){
    		_count++;
			h   = new TH1D(Form("h%d",_count),  "", vbins[v], vbinmin[v], vbinmax[v]);
			hMC = new TH1D(Form("hMC%d",_count),"", vbins[v], vbinmin[v], vbinmax[v]);
			setHist(h);
		    h->SetXTitle(vxaxis[v].c_str());
			setHist(hMC);
		    hMC->SetXTitle(vxaxis[v].c_str());
			nt->Project(Form("h%d",_count),     vexp[v].c_str(), Form("(%s&&%s>%f&&%s<%f)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			ntMC->Project(Form("hMC%d",_count), vexp[v].c_str(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc.Data(), Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
			hMC->Scale(1/hMC->Integral());
			hMC->SetAxisRange(0,hMC->GetMaximum()*1.4*1.2,"Y");
	    	TLatex* tex;

			h->Draw("pe");
		    tex1->Draw();
		    tex2->Draw();
		    tex3->Draw();
		    tex5->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"data",_isPbPb.Data(),vname[v].c_str()));

			hMC->Draw("pe");
		    tex1->Draw();
		    tex2->Draw();
		    tex4->Draw();
		    tex5->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_0_%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),vname[v].c_str()));
		}
	}  
	//outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		plotSth(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
