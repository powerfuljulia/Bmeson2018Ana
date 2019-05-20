#include "fitB.h"
using namespace std;

struct plotStruct{
    TString var;
    TString text;
    bool setlogY;
    bool setlogX;
    int nBins;
    double min;
    double max;
};

double inf = 9999;
const int nVar = 23;
struct plotStruct plotSetting[nVar] = {
    {"Bpt",                         "Bpt",          1, 0, 50, 7, 57}, //0
    {"abs(By)",                     "By",           1, 0, 50, 0.0, 2.4}, //1
    {"Btrk1Pt",                     "Btrk1Pt",      1, 1, 50, 0., 30}, //2
    {"Btrk2Pt",                     "Btrk2Pt",      1, 1, 50, 0., 30}, //3
    {"abs(Btrk1Eta)",               "Btrk1Eta",     1, 0, 50, 0.0, 2.6}, //4
    {"abs(Btrk2Eta)",               "Btrk2Eta",     1, 0, 50, 0.0, 2.6}, //5
    {"abs(Btrk1Dxy/Btrk1D0Err)",    "Btrk1Dxy",     1, 0, 50, 0, 30}, //6
    {"abs(Btrk2Dxy/Btrk1D0Err)",    "Btrk2Dxy",     1, 0, 50, 0, 30}, //7
    {"abs(Btktkmass-1.019455)",     "Btktkmass",    1, 0, 50, 0, 0.015}, //8
    {"abs(Bmumumass-3.096916)",     "Bmumumass",    1, 0, 50, 0, 0.2}, //9
    {"BsvpvDistance/BsvpvDisErr",   "Bsvpv",        1, 0, 50, 0, 200}, //10
    {"Balpha",                      "Balpha",       1, 0, 50, 0, 0.3}, //11
    {"Bd0/Bd0Err",                  "Bd0",          0, 0, 50, 0, 15000}, //12
    {"cos(Bdtheta)",                "cosBtheta",    0, 0, 50, 0.9975, 1}, //13
    {"Bchi2cl",                     "Bchi2cl",      0, 0, 50, 0, 1}, //14
    {"Btktkpt",                     "Btktkpt",      0, 0, 50, 0, 40}, //15
    {"abs(Btktketa)",               "Btktketa",     0, 0, 50, 0, 2.6}, //16
    {"Bmu1pt",                      "Bmu1pt",       0, 0, 50, 0, 40}, //17
    {"Bmu2pt",                      "Bmu2pt",       0, 0, 50, 0, 40}, //18
    {"BDTStage1_pt7to15",           "BDT7to15",     0, 0, 50, -1, 1}, //19
    {"BDTStage1_pt15to50",          "BDT15to50",    0, 0, 50, -1, 1}, //20
    {"BDTStage1_pt7to15",           "PbPbBDT7to15", 0, 0, 50, -1, 1}, //21
    {"BDTStage1_pt15to50",          "PbPbBDT15to50",0, 0, 50, -1, 1}, //22
};

int _nBins = nBins;
double *_ptBins = ptBins;
void fitCompareMC(int usePbPb = 0, TString inputmc_pp = "", TString inputmc_PbPb = "", TString varExp = "", TString trgselection_pp = "",  TString trgselection_PbPb = "", TString cut_pp = "", TString cut_PbPb = "", int isMC = 0, int vini = 1, int vend = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
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

	TString selmc_pp   = Form("%s&&%s",trgselection_pp.Data(),cut_pp.Data());
	//TString selmc_PbPb = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection_PbPb.Data(),cut_PbPb.Data(),hiBinMin,hiBinMax);
	TString selmc_PbPb   = Form("%s&&%s",trgselection_PbPb.Data(),cut_PbPb.Data());

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	TFile* inf_pp   = new TFile(inputmc_pp.Data());
	TFile* inf_PbPb = new TFile(inputmc_PbPb.Data());

	TH1D* h_pp;
	TH1D* h_PbPb;

	TTree* nt_pp;
	TTree* nt_PbPb;

	nt_pp = (TTree*)inf_pp->Get("ntphi");
	//nt_pp->AddFriend("ntHlt");
	//nt_pp->AddFriend("ntHi");
	//nt_pp->AddFriend("ntSkim");
	//nt_pp->AddFriend("BDTStage1_pt15to50");

	nt_PbPb = (TTree*)inf_PbPb->Get("ntphi");
	//nt_PbPb->AddFriend("ntHlt");
	//nt_PbPb->AddFriend("ntHi");
	//nt_PbPb->AddFriend("ntSkim");
	//nt_PbPb->AddFriend("BDTStage1_pt15to50");

	TF1 *total;
	TString outputf;
	//outputf = Form("%s",outputfile.Data());
	//TFile* outf = new TFile(outputf.Data(),"recreate");
	//outf->cd();

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
	    TLatex* tex3 = new TLatex(0.25, 0.8,"MC");
		setTex(tex1);
		setTex(tex2);
		setTex(tex3);
		tex3->SetTextSize(0.07);
		TLegend* leg; 

		for(int v = vini; v < vend; v++){
			_count++;
			if(i != 0 && v == 0) continue; // projecting Bpt only once
			h_pp   = new TH1D(Form("h_pp%d",_count),  "", plotSetting[v].nBins, plotSetting[v].min, plotSetting[v].max);
			h_PbPb = new TH1D(Form("h_PbPb%d",_count),"", plotSetting[v].nBins, plotSetting[v].min, plotSetting[v].max);
			setHist(h_pp);
            h_pp->SetXTitle(plotSetting[v].var);
			setHist(h_PbPb);
            h_PbPb->SetXTitle(plotSetting[v].var);
			h_pp->SetMarkerColor(3);
			h_pp->SetLineColor(3);
			
			if(i == 0 && v == 0){ // projecting Bpt w/o Bpt selection 
				nt_pp->Project(Form("h_pp%d",_count), plotSetting[v].var.Data(), Form("%s*(%s)", weightmc_pp.Data(), Form("%s&&Bgen==23333",selmc_pp.Data())));
				nt_PbPb->Project(Form("h_PbPb%d",_count), plotSetting[v].var.Data(), Form("%s*(%s)", weightmc_PbPb.Data(), Form("%s&&Bgen==23333",selmc_PbPb.Data())));
			}
			else{
				nt_pp->Project(Form("h_pp%d",_count), plotSetting[v].var.Data(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc_pp.Data(), Form("%s&&Bgen==23333",selmc_pp.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
				nt_PbPb->Project(Form("h_PbPb%d",_count), plotSetting[v].var.Data(), Form("%s*(%s&&%s>%f&&%s<%f)", weightmc_PbPb.Data(), Form("%s&&Bgen==23333",selmc_PbPb.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			}
			h_pp->Scale(1/h_pp->Integral());
			h_pp->SetAxisRange(0,h_pp->GetMaximum()*1.4*1.2,"Y");
			h_PbPb->Scale(1/h_PbPb->Integral());
			h_PbPb->SetAxisRange(0,h_PbPb->GetMaximum()*1.4*1.2,"Y");

			leg = myLegend(0.20,0.75,0.35,0.90);
			leg->SetTextSize(0.05);
			leg->AddEntry(h_pp,"pp MC","pl");
			leg->AddEntry(h_PbPb,"PbPb MC","pl");
			h_pp->Draw("pe");
			h_PbPb->Draw("same pe");
			leg->Draw("same");
		    tex1->Draw();
		    tex2->Draw();
		    //tex3->Draw();
	        c->SaveAs(Form("%s%s/%s_%s_%d_%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),i,plotSetting[v].text.Data()));
		}
	}  
	//outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		fitCompareMC(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
