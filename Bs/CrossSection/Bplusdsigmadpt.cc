#include "TH1F.h"
#include "TH2F.h"
#include "TLatex.h"
#include <cmath>
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TCanvas.h"
#include <fstream>
#include <iostream>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include "parameters.h"
using namespace std;
int _nBins = nBins;
double *_ptBins = ptBins;

void Bplusdsigmadpt(TString inputFONLLdat = "pp_Bplus_5p03TeV_y2p4", 
	 TString outputFONLL = "fonllOutput_pp_Bplus_5p03TeV_y2p4.root",
	 TString label = "pp",
     int binOpt = 0
){

	if(binOpt == 1){
		_nBins = nBinsReweight;
		_ptBins = ptBinsReweight;	
	}
	if(binOpt == 2){
		_nBins = nBins750;
		_ptBins = ptBins750;	
	}

	double norm=0.103;           //FF of B->Bs, PDG 2016
	gROOT->SetStyle("Plain");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	ifstream getdata(Form("fo_%s.dat",inputFONLLdat.Data()));

	if(!getdata.is_open())
	{
		cout<<"Opening the file fails"<<endl;
	}

	float central[BIN_NUM];
	float min_all[BIN_NUM],max_all[BIN_NUM],min_sc[BIN_NUM],max_sc[BIN_NUM],min_mass[BIN_NUM],max_mass[BIN_NUM],min_pdf[BIN_NUM],max_pdf[BIN_NUM];
	int i;
	float tem;
	for(i=0;i<BIN_NUM;i++)
	{
		getdata>>tem;
		getdata>>central[i];
		getdata>>min_all[i];
		getdata>>max_all[i];
		getdata>>min_sc[i];
		getdata>>max_sc[i];
		getdata>>min_mass[i];
		getdata>>max_mass[i];
		getdata>>min_pdf[i];
		getdata>>max_pdf[i];
	}

	TH1F* hpt = new TH1F("hpt","",BIN_NUM,HMIN,HMAX);
	TH1F* hminall = new TH1F("hminall","",BIN_NUM,HMIN,HMAX);
	TH1F* hmaxall = new TH1F("hmaxall","",BIN_NUM,HMIN,HMAX);
	TH1F* hminsc = new TH1F("hminsc","",BIN_NUM,HMIN,HMAX);
	TH1F* hmaxsc = new TH1F("hmaxsc","",BIN_NUM,HMIN,HMAX);
	TH1F* hminmass = new TH1F("hminmass","",BIN_NUM,HMIN,HMAX);
	TH1F* hmaxmass = new TH1F("hmaxmass","",BIN_NUM,HMIN,HMAX);
	TH1F* hminpdf = new TH1F("hminpdf","",BIN_NUM,HMIN,HMAX);
	TH1F* hmaxpdf = new TH1F("hmaxpdf","",BIN_NUM,HMIN,HMAX);

	for(i=0;i<BIN_NUM;i++)
	{
		hpt->SetBinContent(i+1,central[i]);
		hminall->SetBinContent(i+1,min_all[i]);
		hmaxall->SetBinContent(i+1,max_all[i]);
		hminsc->SetBinContent(i+1,min_sc[i]);
		hmaxsc->SetBinContent(i+1,max_sc[i]);
		hminmass->SetBinContent(i+1,min_mass[i]);
		hmaxmass->SetBinContent(i+1,max_mass[i]);
		hminpdf->SetBinContent(i+1,min_pdf[i]);
		hmaxpdf->SetBinContent(i+1,max_pdf[i]);
	}
	//Rebin Edge

	TH1F* hpt_rebin = (TH1F*)hpt->Rebin(_nBins,"hpt_rebin",_ptBins);
	TH1F* hminall_rebin = (TH1F*)hminsc->Rebin(_nBins,"hminall_rebin",_ptBins);
	TH1F* hmaxall_rebin = (TH1F*)hmaxsc->Rebin(_nBins,"hmaxall_rebin",_ptBins);
	TH1F* hminsc_rebin = (TH1F*)hminsc->Rebin(_nBins,"hminsc_rebin",_ptBins);
	TH1F* hmaxsc_rebin = (TH1F*)hmaxsc->Rebin(_nBins,"hmaxsc_rebin",_ptBins);
	TH1F* hminmass_rebin = (TH1F*)hminmass->Rebin(_nBins,"hminmass_rebin",_ptBins);
	TH1F* hmaxmass_rebin = (TH1F*)hmaxmass->Rebin(_nBins,"hmaxmass_rebin",_ptBins);
	TH1F* hminpdf_rebin = (TH1F*)hminpdf->Rebin(_nBins,"hminpdf_rebin",_ptBins);
	TH1F* hmaxpdf_rebin = (TH1F*)hmaxpdf->Rebin(_nBins,"hmaxpdf_rebin",_ptBins);

	double asigma[_nBins],aminall[_nBins],amaxall[_nBins],aminsc[_nBins],amaxsc[_nBins],aminmass[_nBins],amaxmass[_nBins],aminpdf[_nBins],amaxpdf[_nBins],aerrorl[_nBins],aerrorh[_nBins]; 

	//bin middle
	double apt[_nBins];
	//bin half width
	double aptl[_nBins];
	//number of every rebined bin
	double bin_num[_nBins];


	for (int ibin=0; ibin<_nBins; ibin++){
		apt[ibin]=(_ptBins[ibin+1]+_ptBins[ibin])/2.;
		aptl[ibin] = (_ptBins[ibin+1]-_ptBins[ibin])/2;
		bin_num[ibin]=aptl[ibin]/binsize*2;
	}

	int j;

	for(j=0;j<_nBins;j++)
	{

		tem = hpt_rebin->GetBinContent(j+1);
		asigma[j] = tem/bin_num[j];

		tem = hminall_rebin->GetBinContent(j+1);
		aminall[j] = tem/bin_num[j];

		tem = hmaxall_rebin->GetBinContent(j+1);
		amaxall[j] = tem/bin_num[j];

		tem = hminsc_rebin->GetBinContent(j+1);
		aminsc[j] = tem/bin_num[j];

		tem = hmaxsc_rebin->GetBinContent(j+1);
		amaxsc[j] = tem/bin_num[j];

		tem = hminmass_rebin->GetBinContent(j+1);
		aminmass[j] = tem/bin_num[j];

		tem = hmaxmass_rebin->GetBinContent(j+1);
		amaxmass[j] = tem/bin_num[j];

		tem = hminpdf_rebin->GetBinContent(j+1);
		aminpdf[j] = tem/bin_num[j];

		tem = hmaxpdf_rebin->GetBinContent(j+1);
		amaxpdf[j] = tem/bin_num[j];

		aerrorl[j] = asigma[j]-aminall[j];//all,sc,mass,pdf
		aerrorh[j] = amaxall[j]-asigma[j];//all,sc,mass,pdf
	}

	cout<<endl;

	TGraphAsymmErrors* gaeSigma = new TGraphAsymmErrors(_nBins, apt, asigma, aptl, aptl, aerrorl, aerrorh);
	gaeSigma->SetFillColor(2);
	gaeSigma->SetFillStyle(3001);

	TGraphAsymmErrors* gaeSigmaBplus=(TGraphAsymmErrors*)gaeSigma->Clone();
	gaeSigmaBplus->SetName("gaeSigmaBplus");
	gaeSigmaBplus->SetFillColor(2);
	gaeSigmaBplus->SetFillStyle(3001); 
	gaeSigmaBplus->SetTitle(";p_{T}(GeV/c);d#sigma/dp_{T} (B_{s}) (pb GeV-1c)");

	for (int i=0;i<gaeSigmaBplus->GetN();i++){
		gaeSigmaBplus->GetY()[i] *= norm;
		gaeSigmaBplus->SetPointEYhigh(i,gaeSigmaBplus->GetErrorYhigh(i)*norm);
		gaeSigmaBplus->SetPointEYlow(i,gaeSigmaBplus->GetErrorYlow(i)*norm); 
	}

	TCanvas* cr = new TCanvas("cr","cr",600,500);
	cr->SetLogy();
	TH2F* hempty=new TH2F("hempty","",10,0,100.,10.,10.,5000000000);  
	hempty->GetXaxis()->SetTitle("p_{t} (GeV/c)");
	hempty->GetYaxis()->SetTitle("d#sigma(B)/dp_{T}(pb GeV-1c)");
	hempty->GetXaxis()->SetTitleOffset(1.);
	hempty->GetYaxis()->SetTitleOffset(.9);
	hempty->GetXaxis()->SetTitleSize(0.045);
	hempty->GetYaxis()->SetTitleSize(0.045);
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.04);
	hempty->GetYaxis()->SetLabelSize(0.04);  
	hempty->Draw();
	hminall->SetLineColor(4);
	hmaxall->SetLineColor(4);
	hpt->SetLineColor(4);
	hminall->Draw("same");
	hmaxall->Draw("same");
	hpt->Draw("same");
	gaeSigma->SetLineWidth(3);
	gaeSigma->Draw("psame");
	gaeSigmaBplus->SetLineWidth(3);
	gaeSigmaBplus->SetLineColor(2);
	gaeSigmaBplus->Draw("psame");

	TLatex * tlatex=new TLatex(0.18,0.85,"pp collisions from FONLL, |y|<2.4");
	tlatex->SetNDC();
	tlatex->SetTextColor(1);
	tlatex->SetTextFont(42);
	tlatex->SetTextSize(0.04);
	tlatex->Draw();

	TLatex * tlatextotunc=new TLatex(0.18,0.80,"Total syst uncertainties shown");
	tlatextotunc->SetNDC();
	tlatextotunc->SetTextColor(1);
	tlatextotunc->SetTextFont(42);
	tlatextotunc->SetTextSize(0.04);
	tlatextotunc->Draw();

	TLatex * tlatexD0=new TLatex(0.2,0.7,"B_{s},|y|<2.4, BR unc not shown");
	tlatexD0->SetNDC();
	tlatexD0->SetTextColor(1);
	tlatexD0->SetTextFont(42);
	tlatexD0->SetTextSize(0.05);
	tlatexD0->Draw();

	TLatex * tlatextemp=new TLatex(0.2,0.75,"");
	tlatextemp->SetNDC();
	tlatextemp->SetTextColor(1);
	tlatextemp->SetTextFont(42);
	tlatextemp->SetTextSize(0.05);
	tlatextemp->Draw();

	TLegend* leg=new TLegend(0.4,0.5,0.89,0.6);
	leg->SetFillColor(0);
	TLegendEntry* ent_gaeSigma=leg->AddEntry(gaeSigma,"Frag.Fraction=1.0 (pure FONLL)","PL");
	ent_gaeSigma->SetTextColor(gaeSigma->GetMarkerColor());
	TLegendEntry* ent_gaeSigmaBplus=leg->AddEntry(gaeSigmaBplus,"Multiplied by Frag. Fraction=0.103","PL");
	ent_gaeSigmaBplus->SetTextColor(gaeSigmaBplus->GetMarkerColor());
	leg->Draw();

	gaeSigma->SetName("gaeSigma");
	gaeSigmaBplus->SetName("gaeSigmaBplus");
	if(binOpt == 1){
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s_reweightBin.pdf",inputFONLLdat.Data(),label.Data()));
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s_reweightBin.eps",inputFONLLdat.Data(),label.Data()));
	}
	else if(binOpt == 2){
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s_750.pdf",inputFONLLdat.Data(),label.Data()));
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s_750.eps",inputFONLLdat.Data(),label.Data()));
	}
	else{
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s.pdf",inputFONLLdat.Data(),label.Data()));
		cr->SaveAs(Form("plotFONLL/canvas_%s_%s.eps",inputFONLLdat.Data(),label.Data()));
	}

	TFile*foutput=new TFile(outputFONLL.Data(),"recreate");
	foutput->cd();
	gaeSigma->Write();
	gaeSigmaBplus->Write();
	hpt->Write();
	hminall->Write();
	hmaxall->Write();
}


int main(int argc, char *argv[])
{
	if((argc != 4 && argc != 5))
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}

	if(argc == 4)
		Bplusdsigmadpt(argv[1],argv[2],argv[3]);
	if(argc == 5)
		Bplusdsigmadpt(argv[1],argv[2],argv[3],atoi(argv[4]));
	return 0;
}
