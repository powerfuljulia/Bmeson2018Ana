#include "../uti.h"
#include "../parameters.h"
#include "TLegendEntry.h"
#include "../theoryPrediction/drawTheory_BsBpRatio.h"
double xVal[100];
double xErr[100];
double BpyVal[100];
double BpyStaErr[100];
double BpySysErr[100];
double BsyVal[100];
double BsyStaErr[100];
double BsySysErr[100];
double raaRatio[100];
double raaRatioStaErr[100];
double raaRatioSysErr[100];
using namespace std;

int _nBins = nBins;
double *_ptBins = ptBins;
float legendTextSize = 0.07;
bool drawThm = 0;
bool drawSup = 1;
void plotBsBpRatio(){

    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    gStyle->SetEndErrorSize(0);
    gStyle->SetMarkerStyle(20);
    gStyle->SetPadRightMargin(cRightMargin);
    gStyle->SetPadLeftMargin(cLeftMargin);
    gStyle->SetPadTopMargin(cTopMargin);
    gStyle->SetPadBottomMargin(cBottomMargin);

	//TFile* Bpf = new TFile("outputRAA_Bp.root");
	TFile* Bpf = new TFile("rebinnedBpResult/outputRAA_Bp_rebinned.root");
	TGraphAsymmErrors* BpgNucl = (TGraphAsymmErrors*)Bpf->Get("gNuclearModification");
	TH1D* BphNucl = (TH1D*)Bpf->Get("hNuclearModification");
	TFile* Bsf = new TFile("outputRAA_Bs.root");
	TGraphAsymmErrors* BsgNucl = (TGraphAsymmErrors*)Bsf->Get("gNuclearModification");
	TH1D* BshNucl = (TH1D*)Bsf->Get("hNuclearModification");
	int _nBins = BphNucl->GetNbinsX();
	for(int i = 0; i < _nBins; i ++){
		double x, y;
		BpgNucl->GetPoint(i,x,y);
		xVal[i] = x;
		BpyVal[i] = y;
		BpyStaErr[i] = BphNucl->GetBinError(i+1)/BpyVal[i];
		BpySysErr[i] = BpgNucl->GetErrorYhigh(i)/BpyVal[i];
		xErr[i] = BpgNucl->GetErrorXhigh(i);
		BsgNucl->GetPoint(i,x,y);
		BsyVal[i] = y;
		BsyStaErr[i] = BshNucl->GetBinError(i+1)/BsyVal[i];
		BsySysErr[i] = BsgNucl->GetErrorYhigh(i)/BsyVal[i];	
		raaRatio[i] = BsyVal[i]/BpyVal[i];
		//raaRatioStaErr[i] = sqrt(BpyStaErr[i]/BpyVal[i]*BpyStaErr[i]/BpyVal[i] + BsyStaErr[i]/BsyVal[i]*BsyStaErr[i]/BsyVal[i])*raaRatio[i];
		//raaRatioSysErr[i] = sqrt(BpySysErr[i]/BpyVal[i]*BpySysErr[i]/BpyVal[i] + BsySysErr[i]/BsyVal[i]*BsySysErr[i]/BsyVal[i])*raaRatio[i];
		raaRatioStaErr[i] = sqrt(BpyStaErr[i]*BpyStaErr[i] + BsyStaErr[i]*BsyStaErr[i])*raaRatio[i];
		raaRatioSysErr[i] = sqrt(BpySysErr[i]*BpySysErr[i] + BsySysErr[i]*BsySysErr[i])*raaRatio[i];
	}
    TCanvas*canvasRAA=new TCanvas("canvasRAA","canvasRAA",600,600);
    canvasRAA->cd();

    TH2F* hemptyEff=new TH2F("hemptyEff","",50,_ptBins[0]-10,_ptBins[_nBins]+10,10.,0,7.5);
    hemptyEff->GetXaxis()->CenterTitle();
    hemptyEff->GetYaxis()->CenterTitle();
    //hemptyEff->GetYaxis()->SetTitle("B^{0}_{s} R_{AA} / B^{+} R_{AA}");
    hemptyEff->GetYaxis()->SetTitle("R_{AA}^{B^{0}_{s}} / R_{AA}^{B^{+}}");
    hemptyEff->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    hemptyEff->GetXaxis()->SetTitleOffset(1.0);
    hemptyEff->GetYaxis()->SetTitleOffset(1.4);
    hemptyEff->GetXaxis()->SetTitleSize(0.055);
    hemptyEff->GetYaxis()->SetTitleSize(0.055);
    hemptyEff->GetXaxis()->SetTitleFont(42);
    hemptyEff->GetYaxis()->SetTitleFont(42);
    hemptyEff->GetXaxis()->SetLabelFont(42);
    hemptyEff->GetYaxis()->SetLabelFont(42);
    hemptyEff->GetXaxis()->SetLabelSize(0.048);
    hemptyEff->GetYaxis()->SetLabelSize(0.048);
    hemptyEff->Draw();

    TGraphAsymmErrors* gRAAratio = new TGraphAsymmErrors(_nBins,xVal,raaRatio,xErr,xErr,raaRatioSysErr,raaRatioSysErr);
    gRAAratio->SetFillColor(BsBoxColor);
    gRAAratio->SetFillColorAlpha(BsBoxColor, 0.5);
    gRAAratio->SetLineWidth(0);
    gRAAratio->SetLineColor(0);
    gRAAratio->SetMarkerColor(BsPointColor);
    gRAAratio->SetMarkerStyle(33);
    gRAAratio->SetMarkerSize(2.2);

	TH1D* hRAAratio = new TH1D("hRAAratio","",_nBins,_ptBins);
	for(int i = 0; i < _nBins; i++){
		hRAAratio->SetBinContent(i+1,raaRatio[i]);
		hRAAratio->SetBinError(i+1,raaRatioStaErr[i]);
	}
    hRAAratio->SetLineWidth(3);
    hRAAratio->SetLineColor(BsPointColor);
    hRAAratio->SetMarkerColor(BsPointColor);
    hRAAratio->SetMarkerStyle(33);
    hRAAratio->SetMarkerSize(2.2);

	TLegend *legendSigma=new TLegend(0.55,0.75,0.95,0.88,"");
	if(drawThm) legendSigma=new TLegend(0.55,0.55,0.95,0.88,"");
    legendSigma->SetBorderSize(0);
    legendSigma->SetLineColor(0);
    legendSigma->SetFillColor(0);
    legendSigma->SetFillStyle(1001);
    legendSigma->SetTextFont(42);
    legendSigma->SetTextSize(0.04);

	TLegendEntry *ent_B;
	//ent_B = legendSigma->AddEntry(gRAAratio,"B^{0}_{s}/B^{+} R_{AA} ratio","pf");
	ent_B = legendSigma->AddEntry(gRAAratio,"R_{AA}^{B^{0}_{s}} / R_{AA}^{B^{+}}","pf");
	ent_B->SetTextFont(42);
	ent_B->SetLineColor(4);
	ent_B->SetMarkerColor(4);
	ent_B->SetTextSize(0.065);

    TLine *line = new TLine(_ptBins[0]-10,1,_ptBins[_nBins]+10,1);
    line->SetLineStyle(2);
    line->SetLineWidth(2);
    line->Draw();

    TLatex* texlumi = new TLatex(0.96,0.95,"28 pb^{-1} (pp) + 351 #mub^{-1} (PbPb) 5.02 TeV");
    texlumi->SetNDC();
    texlumi->SetTextAlign(32);
    texlumi->SetTextFont(42);
    texlumi->SetTextSize(0.05);
    texlumi->SetLineWidth(2);
    texlumi->Draw();

    TLatex* texB = new TLatex(0.75,0.56,"B^{0}_{s}");
    texB->SetNDC();
    texB->SetTextFont(62);
    texB->SetTextSize(0.07);
    texB->SetLineWidth(2);
    //texB->Draw();

    TLatex *texY = new TLatex(0.21,0.74,"|y| < 2.4");
    texY->SetNDC();
    texY->SetTextFont(42);
    texY->SetTextSize(0.05);
    texY->SetLineWidth(2);
    texY->Draw();

    TLatex* texcms = new TLatex(0.21,0.88,"CMS");
    texcms->SetNDC();
    texcms->SetTextAlign(13);
    texcms->SetTextFont(62);//61
    texcms->SetTextSize(0.06);
    texcms->SetLineWidth(2);
    texcms->Draw();

    TLatex* texcent = new TLatex(0.62,0.18,"Cent. 0-100%");
    texcent->SetNDC();
    texcent->SetTextFont(42);
    texcent->SetTextSize(0.05);
    texcent->SetLineWidth(2);
    texcent->Draw();

    TLatex* texsup = new TLatex(0.21,0.83,"Supplementary");
    texsup->SetNDC();
    texsup->SetTextAlign(13);
    texsup->SetTextFont(52);
    texsup->SetTextSize(0.05);
    texsup->SetLineWidth(2);
    if(drawSup) texsup->Draw();

    TLatex* texpre = new TLatex(0.21,0.83,"Preliminary");
    texpre->SetNDC();
    texpre->SetTextAlign(13);
    texpre->SetTextFont(52);
    texpre->SetTextSize(0.035);
    texpre->SetLineWidth(2);
    //texpre->Draw();

	TString AddOn = "";
    if(drawThm){
		plotTheory_BsBpRatio();
        TGraphAsymmErrors* gThmDummy1 = new TGraphAsymmErrors();
        TGraphAsymmErrors* gThmDummy2 = new TGraphAsymmErrors();
        gThmDummy1->SetLineColor(colorTAMU_Bs);
        gThmDummy2->SetLineColor(colorCUJET_Bs);
        gThmDummy2->SetFillColorAlpha(colorCUJET_Bs,0.5);
        gThmDummy1->SetFillStyle(styleTAMU_Bs);
        gThmDummy2->SetFillStyle(styleCUJET_Bs);
        gThmDummy1->SetLineWidth(8.);
        gThmDummy2->SetLineWidth(8.);
        TLegendEntry *ent_thm1 = legendSigma->AddEntry(gThmDummy1,"TAMU","l");
        TLegendEntry *ent_thm2 = legendSigma->AddEntry(gThmDummy2,"CUJET3.0","l");
        ent_thm1->SetTextSize(legendTextSize);
        ent_thm2->SetTextSize(legendTextSize);
        AddOn = AddOn += "_ThmRAA";
    }
    legendSigma->Draw();
	gRAAratio->Draw("5same");
	hRAAratio->Draw("same p");
	canvasRAA->SaveAs(Form("BsBpRatio%s.pdf",AddOn.Data()));
	canvasRAA->SaveAs(Form("BsBpRatio%s.png",AddOn.Data()));
	canvasRAA->SaveAs(Form("BsBpRatio%s.C",AddOn.Data()));

    float combinedchi2 = 0;
	for(int i = 0; i < _nBins; i ++){
		cout<<"=========="<<endl;
		cout<<"xVal: "<<xVal[i]<<endl;
		cout<<"xErr: "<<xErr[i]<<endl;
		cout<<"BpyVal: "<<BpyVal[i]<<endl;
		cout<<"BpyStaErr(%): "<<BpyStaErr[i]*100<<endl;
		cout<<"BpySysErr(%): "<<BpySysErr[i]*100<<endl;
		cout<<"BsyVal: "<<BsyVal[i]<<endl;
		cout<<"BsyStaErr(%): "<<BsyStaErr[i]*100<<endl;
		cout<<"BsySysErr(%): "<<BsySysErr[i]*100<<endl;
		cout<<"raaRatio: "<<raaRatio[i]<<endl;
		cout<<"raaRatioStaErr(%): "<<raaRatioStaErr[i]/raaRatio[i]*100<<endl;
		cout<<"raaRatioSysErr(%): "<<raaRatioSysErr[i]/raaRatio[i]*100<<endl;
		cout<<"raaRatioStaErr(absolute): "<<raaRatioStaErr[i]<<endl;
		cout<<"raaRatioSysErr(absolute): "<<raaRatioSysErr[i]<<endl;
		cout<<"p val (stat error): "<<calPval(raaRatio[i]-1,raaRatioStaErr[i])<<endl;
		cout<<"p val (syst error): "<<calPval(raaRatio[i]-1,raaRatioSysErr[i])<<endl;
		cout<<"p val (comb error): "<<calPval(raaRatio[i]-1,sqrt(raaRatioStaErr[i]*raaRatioStaErr[i]+raaRatioSysErr[i]*raaRatioSysErr[i]))<<endl;
		float chi2 = 0;
		chi2 += (raaRatio[i]-1)*(raaRatio[i]-1)/(raaRatioStaErr[i]*raaRatioStaErr[i]+raaRatioSysErr[i]*raaRatioSysErr[i]);
		cout<<"chi2 val: "<<chi2<<endl;
		combinedchi2 += chi2;
	}
    cout<<"p val combined (comb error): "<<TMath::Prob(combinedchi2, _nBins)<<endl;
    
	
}
