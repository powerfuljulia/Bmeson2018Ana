#include "uti.h"
#include "parameters.h"
#include "TLegendEntry.h"
#include "../Systematics/systematics.C"
#include "theoryPrediction/drawTheory.h"
#include "theoryPrediction/drawTheory_Bs.h"
#include "theoryPrediction/B_RpA/DrawBRpAFONLL.h"
#include "theoryPrediction/B_RpA/DrawBRpA.h"
#include "theoryPrediction/ChargedHad/RpPb_Final_20161207.h"
#include "theoryPrediction/Dmeson/Draw_DRAA.h" //PAS
#include "theoryPrediction/Dmeson/canvasRAA_0_100_20161207.h" //new
#include "theoryPrediction/NonPromptJpsi/nonPrompt_276raa_20170201.h"
#include "theoryPrediction/B_RAA/canvasRAAPbPb_0_100.C"

bool drawB = 1;
bool BSepSys = 0;

// better draw the following all together
bool drawChHad = 0;
bool drawDRAA = 0;
bool drawBpRAA = 0;
bool drawJpsi = 0;

bool drawBpRpA = 0;

bool drawThm = 0;
bool drawSup = 0;

int onlyBs = drawB + drawBpRAA + drawChHad + drawDRAA + drawJpsi + drawBpRpA;

float TAABarWid = 1.;
float *GlobSystPos;
float GlobSystPosNormScale[6] = {0, 2, 4, 6, 8, 10};
float GlobSystPosLogScale[6] = {0, 0.9, 2., 3.5, 5., 7};
int GlobSystPosCounter = 0;
float legendTextSize = 0.07;

void adjustLegend(TLegend* l);
void NuclearModificationFactor(TString inputPP="ROOTfiles/CrossSectionPP.root", TString inputPbPb="ROOTfiles/CrossSectionPbPb.root",TString label="PbPb",TString outputfile="RAAfile.root", TString outplotf = "", int binOpt=0, Float_t centMin=0., Float_t centMax=100.)
{
	//float pti = ptBins[0]-5.;
	float pti = 2.;
	float pte = ptBins[nBins]+5.;
	GlobSystPos = GlobSystPosNormScale;
	if(drawChHad){
		pti = 0.5;
		pte = 600.;
		legendTextSize = 0.035;
	}
	if(drawThm){
        //pte = 110.;
		legendTextSize = 0.06;
	}

	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	gStyle->SetEndErrorSize(0);
	gStyle->SetMarkerStyle(20);
	gStyle->SetPadRightMargin(cRightMargin);
	gStyle->SetPadLeftMargin(cLeftMargin);
	gStyle->SetPadTopMargin(cTopMargin);
	gStyle->SetPadBottomMargin(cBottomMargin);

	TFile *fpp=new TFile(inputPP.Data());
	TFile *fPbPb=new TFile(inputPbPb.Data());

	TH1D*hSigmaPPStat=(TH1D*)fpp->Get("hPtSigma");
	hSigmaPPStat->SetName("hSigmaPPStat");
	TH1D*hNuclearModification=(TH1D*)fPbPb->Get("hPtSigma");
	hNuclearModification->SetName("hNuclearModification");
	hNuclearModification->Divide(hSigmaPPStat);
	hNuclearModification->SetMaximum(2.5);
	
	double apt[nBins];
	//bin half width
	double aptl[nBins];
	//"half" of bin half width
	double haptl[nBins];
	//number of every rebined bin
	double bin_num[nBins];

	for (int ibin=0; ibin<nBins; ibin++){
		apt[ibin]=(ptBins[ibin+1]+ptBins[ibin])/2.;
		aptl[ibin] = (ptBins[ibin+1]-ptBins[ibin])/2;
		haptl[ibin] = aptl[ibin]/1.4;
		bin_num[ibin]=aptl[ibin]/binsize*2;
	}

	Double_t xr[nBins], yr[nBins], xrlow[nBins], yrlow[nBins],xrhigh[nBins],yrhigh[nBins];
	Double_t yrcor[nBins], yruncor[nBins];
	for(int i=0;i<nBins;i++)
	{
		yr[i] = hNuclearModification->GetBinContent(i+1);
		double systematic=0;
		double systematic_cor=0;
		double systematic_uncor=0;
		systematic=0.01*systematicsForRAA(hNuclearModification->GetBinCenter(i+1),centMin,centMax,0.,0.,binOpt);
		systematic_cor=0.01*systematicsForRAA_Correlated(hNuclearModification->GetBinCenter(i+1),centMin,centMax,0.,0.,binOpt);
		systematic_uncor=0.01*systematicsForRAA_UnCorrelated(hNuclearModification->GetBinCenter(i+1),centMin,centMax,0.,0.,binOpt);
		//printf("Sys, bin %d = %f \n", i, systematic);
		//double systematic=0.;
		yrlow[i] = hNuclearModification->GetBinContent(i+1)*systematic;
		yrhigh[i] =hNuclearModification->GetBinContent(i+1)*systematic;
		yrcor[i] = hNuclearModification->GetBinContent(i+1)*systematic_cor;
		yruncor[i] = hNuclearModification->GetBinContent(i+1)*systematic_uncor;

		double raamean = hNuclearModification->GetBinContent(i+1);
		printf("RAA mean: %f \n", raamean);
		printf("Stat: %f %f(%)\n", hNuclearModification->GetBinError(i+1), hNuclearModification->GetBinError(i+1)/raamean);
		printf("Sys tot: %f %f(%)\n",yrlow[i], yrlow[i]/raamean);
		printf("Sys corr: %f %f(%)\n",yrcor[i], yrcor[i]/raamean);
		printf("Sys uncorr: %f %f(%)\n",yruncor[i], yruncor[i]/raamean);
		double totsyst = sqrt( pow(hNuclearModification->GetBinError(i+1)/raamean,2) + pow(yrlow[0]/raamean,2) );
		printf("Tot uncert: %f(%)\n", totsyst);
		double nsigma = (1-raamean)/(raamean*totsyst);
		printf("N sigma: %f\n", nsigma);
	}

	//how many 

	TGraphAsymmErrors* gNuclearModification = new TGraphAsymmErrors(nBins,apt,yr,aptl,aptl,yrlow,yrhigh);
	gNuclearModification->SetName("gNuclearModification");
	TGraphAsymmErrors* gNuclearModification_UnCor = new TGraphAsymmErrors(nBins,apt,yr,haptl,haptl,yruncor,yruncor);
	gNuclearModification_UnCor->SetName("gNuclearModification_UnCor");
	TGraphAsymmErrors* gNuclearModification_Cor = new TGraphAsymmErrors(nBins,apt,yr,aptl,aptl,yrcor,yrcor);
	gNuclearModification_Cor->SetName("gNuclearModification_Cor");

	TCanvas*canvasRAA=new TCanvas("canvasRAA","canvasRAA",600,600);
	canvasRAA->cd();
	if(drawChHad) {
		canvasRAA->SetLogx();
		GlobSystPos = GlobSystPosLogScale;
		TAABarWid = 0.12;
	}

	//TH2F* hemptyEff=new TH2F("hemptyEff","",50,pti,pte,10.,0,1.55);  
	TH2F* hemptyEff=new TH2F("hemptyEff","",50,pti,pte,10.,0,2.5);  
	if(drawChHad) hemptyEff=new TH2F("hemptyEff","",50,pti,pte,10.,0,4);  
	hemptyEff->GetXaxis()->CenterTitle();
	hemptyEff->GetYaxis()->CenterTitle();
	hemptyEff->GetYaxis()->SetTitle("R_{AA}");
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
	hemptyEff->SetMaximum(2);
	hemptyEff->SetMinimum(0.);
	hemptyEff->Draw();

	TLine *line = new TLine(pti,1,pte,1);
	line->SetLineStyle(2);
	line->SetLineWidth(2);
	line->Draw();

	gNuclearModification->SetFillColor(BsBoxColor);
	gNuclearModification->SetFillColorAlpha(BsBoxColor, 0.5);
	gNuclearModification->SetLineWidth(0);
	gNuclearModification->SetMarkerSize(1.2);
	gNuclearModification->SetMarkerStyle(33);
	gNuclearModification->SetLineColor(0);
	gNuclearModification->SetMarkerColor(BsPointColor);

	gNuclearModification_UnCor->SetFillColor(BsBoxColor);
	gNuclearModification_UnCor->SetFillColorAlpha(BsBoxColor, 0.5);
	gNuclearModification_UnCor->SetLineWidth(0);
	gNuclearModification_UnCor->SetMarkerSize(1.2);
	gNuclearModification_UnCor->SetMarkerStyle(33);
	gNuclearModification_UnCor->SetLineColor(0);
	gNuclearModification_UnCor->SetMarkerColor(BsPointColor);

	gNuclearModification_Cor->SetLineColor(1);
	gNuclearModification_Cor->SetLineWidth(3);
	gNuclearModification_Cor->SetFillColor(0);
	gNuclearModification_Cor->SetFillColorAlpha(0, 0.01);

	hNuclearModification->SetLineWidth(3);
	hNuclearModification->SetLineColor(BsPointColor);
	hNuclearModification->SetMarkerColor(BsPointColor);
	hNuclearModification->SetMarkerStyle(33);
	hNuclearModification->SetMarkerSize(2.2);
	
	TLatex* texlumi = new TLatex(0.96,0.95,"28 pb^{-1} (pp) +  1.5 nb^{-1} (PbPb) 5.02 TeV");
	texlumi->SetNDC();
    texlumi->SetTextAlign(32);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.05);
	texlumi->SetLineWidth(2);
	texlumi->Draw();

	//TLatex * tlatexeff2=new TLatex(0.40,0.595,"Centrality 0-100%");
	//tlatexeff2->SetNDC();
	//tlatexeff2->SetTextColor(1);
	//tlatexeff2->SetTextFont(42);
	//tlatexeff2->SetTextSize(0.050);
	//tlatexeff2->Draw();

	TLatex* texB = new TLatex(0.75,0.56,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(62);
	texB->SetTextSize(0.07);
	texB->SetLineWidth(2);
	//texB->Draw();

	TLatex *texY = new TLatex(0.21,0.79,"|y| < 2.4");
	if(drawDRAA) texY = new TLatex(0.21,0.79,"|y| < 2.4");
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

    TLatex* texsup = new TLatex(0.35,0.877,"Supplementary");
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

	//TLegend *legendSigma=new TLegend(0.50,0.66,0.95,0.88,"");
    TLegend *legendSigma=new TLegend(0.6,0.6,0.9,0.88);
	if(drawSup) legendSigma=new TLegend(0.7,0.67,0.95,0.88,"");
	if(drawDRAA) legendSigma=new TLegend(0.35,0.55,0.95,0.88,"");
	adjustLegend(legendSigma);

	//TLegendEntry *ent_SigmaPP=legendSigma->AddEntry(hNuclearModification,"R_{AA} stat. unc.","pf");
	//ent_SigmaPP->SetTextFont(42);
	//ent_SigmaPP->SetLineColor(1);
	//ent_SigmaPP->SetMarkerColor(1);
	//ent_SigmaPP->SetTextSize(0.045);

	//TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(gNuclearModification,"R_{AA} syst.","f");
	//ent_Sigmapp->SetTextFont(42);
	//ent_Sigmapp->SetLineColor(5);
	//ent_Sigmapp->SetMarkerColor(1);
	//ent_Sigmapp->SetTextSize(0.045);

	TLatex* texSystnorm = new TLatex(0.23,0.70,"Global uncert.");
	if(drawDRAA) texSystnorm = new TLatex(0.22,0.70,"Global uncert.");
	texSystnorm->SetNDC();
	texSystnorm->SetTextColor(1);
	texSystnorm->SetTextFont(42);
	texSystnorm->SetTextSize(0.04);
	texSystnorm->SetLineWidth(2);
	//texSystnorm->Draw();

	Float_t systnormhi;
	Float_t systnormlo;
	Float_t systnorm;
	TBox* bSystnorm = new TBox();
	TBox* otherSystnorm = new TBox();
	// Draw charge hadron
	if(drawChHad){
		//RAA_0_100();
		RpPb_Final_20161207();
		TGraphAsymmErrors* gChHadDummy = new TGraphAsymmErrors();
		gChHadDummy->SetFillColor(TColor::GetColor("#ffcc00"));
		gChHadDummy->SetLineColor(0);
		TLegendEntry *ent_ChHad = legendSigma->AddEntry(gChHadDummy,"charged hadrons |y| < 1.0","pf");
		ent_ChHad->SetTextFont(42);
		ent_ChHad->SetLineColor(4);
		ent_ChHad->SetMarkerColor(4);
		ent_ChHad->SetTextSize(legendTextSize);
		systnorm = sqrt(0.089*0.089+0.023*0.023);
		otherSystnorm = new TBox(TAABarWid*GlobSystPos[GlobSystPosCounter],1-systnorm,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1+systnorm); 
		GlobSystPosCounter++;
		otherSystnorm->SetLineColor(TColor::GetColor("#ffcc00"));
		otherSystnorm->SetFillColor(TColor::GetColor("#ffcc00"));
		otherSystnorm->Draw();
	}

	// Draw D Raa
	if(drawDRAA){
		TGraphAsymmErrors* gDNuclearModification = new TGraphAsymmErrors();
		Draw_DRAA(canvasRAA, gDNuclearModification);
		//canvasRAA_0_100_20161207(canvasRAA, gDNuclearModification);
		gDNuclearModification->SetFillColor(kGreen-9);
		gDNuclearModification->SetFillColorAlpha(kGreen-9, 0.5);
		gDNuclearModification->SetMarkerStyle(21);
		gDNuclearModification->SetMarkerColor(kGreen+3);
		TLegendEntry *ent_Dhighpt = legendSigma->AddEntry(gDNuclearModification,"D^{0} |y| < 1.0","pf");
		ent_Dhighpt->SetTextFont(42);
		ent_Dhighpt->SetMarkerColor(4);
		ent_Dhighpt->SetTextSize(legendTextSize);
		systnormhi = normalizationUncertaintyForRAA(1)*1.e-2;
		systnormlo = normalizationUncertaintyForRAA(0)*1.e-2;
		otherSystnorm = new TBox(pti+TAABarWid*GlobSystPos[GlobSystPosCounter],1-systnormlo,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1+systnormhi);
		GlobSystPosCounter++;
		otherSystnorm->SetLineColor(kGreen-9);
		otherSystnorm->SetFillColor(kGreen-9);
		otherSystnorm->SetFillColorAlpha(kGreen-9, 0.5);
		otherSystnorm->Draw();
	}

	// Draw Bs legend
	TLegendEntry *ent_B;
	TLegendEntry *ent_uncCor;
	TLegendEntry *ent_uncUncor;
	TLegendEntry *ent_unc;
	TLegendEntry *ent_uncGlo;
	if(drawB) {
		systnormhi = normalizationUncertaintyForRAA(1)*1.e-2;
		systnormlo = normalizationUncertaintyForRAA(0)*1.e-2;
		printf("Global uncertainty: hi = %f, low = %f\n",systnormhi, systnormlo);
		bSystnorm = new TBox(pti+TAABarWid*GlobSystPos[GlobSystPosCounter],1-systnormlo,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1+systnormhi);
		bSystnorm->SetLineColor(16);
		bSystnorm->SetFillColor(16);
		if(onlyBs!=1){
			bSystnorm = new TBox(pti+TAABarWid*GlobSystPos[GlobSystPosCounter],1-systnormlo,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1+systnormhi);
			//Color_t boxcolor = BsBoxColor
			Color_t boxcolor = 14;
			bSystnorm->SetLineColor(boxcolor);
			bSystnorm->SetFillColor(boxcolor);
			bSystnorm->SetFillColorAlpha(boxcolor, 0.5);
		}
		GlobSystPosCounter++;
		//if(drawB) bSystnorm->Draw(); //Draw at the very end to avoid being covered by other stuff
		if(onlyBs==1) ent_B = legendSigma->AddEntry(gNuclearModification_UnCor,"B^{0}_{s}","p");
		else ent_B = legendSigma->AddEntry(gNuclearModification_UnCor,"B^{0}_{s}","pf");
		ent_B->SetTextFont(42);
		ent_B->SetLineColor(4);
		ent_B->SetMarkerColor(4);
		ent_B->SetTextSize(legendTextSize);
		if(onlyBs==1){
			if(BSepSys){
				ent_uncCor = legendSigma->AddEntry(gNuclearModification_Cor,"Correlated syst. uncert.","f");
				ent_uncCor->SetTextFont(42);
				ent_uncCor->SetLineColor(4);
				ent_uncCor->SetMarkerColor(4);
				ent_uncCor->SetTextSize(0.06);

				ent_uncUncor = legendSigma->AddEntry(gNuclearModification_UnCor,"Uncorrelated syst. uncert.","f");
				ent_uncUncor->SetTextFont(42);
				ent_uncUncor->SetLineColor(4);
				ent_uncUncor->SetMarkerColor(4);
				ent_uncUncor->SetTextSize(0.06);
			}
			else{
				ent_unc = legendSigma->AddEntry(gNuclearModification,"Syst. uncert.","f");
				ent_unc->SetTextFont(42);
				ent_unc->SetLineColor(4);
				ent_unc->SetMarkerColor(4);
				ent_unc->SetTextSize(0.06);
			}
			TBox* dummybox = new TBox();
			dummybox->SetFillColor(16);
			dummybox->SetLineColor(16);
			dummybox->SetLineWidth(0);
			//ent_uncGlo = legendSigma->AddEntry(dummybox,"T_{AA} + L_{pp} uncert.","f");
			if(onlyBs) ent_uncGlo = legendSigma->AddEntry(dummybox,"Global uncert.","f");
			ent_uncGlo->SetTextFont(42);
			ent_uncGlo->SetTextSize(0.06);
			//TMathText mt;
			//mt.SetTextAlign(23);
			//mt.SetTextSize(0.06);
			//mt.DrawMathText(0.80,0.80,"\\delta");
		}
	}

	// Draw B+ RAA
	if(drawBpRAA){
		TGraphAsymmErrors* gBpNuclearModification = new TGraphAsymmErrors();
		canvasRAAPbPb_0_100(canvasRAA, gBpNuclearModification);
		gBpNuclearModification->SetFillColor(kAzure+7);
		gBpNuclearModification->SetFillColorAlpha(kAzure+7, 0.5);
		gBpNuclearModification->SetMarkerStyle(21);
		gBpNuclearModification->SetMarkerColor(kAzure-1);
		gBpNuclearModification->SetLineColor(0);
		TLegendEntry *ent_BpRAA = legendSigma->AddEntry(gBpNuclearModification,"B^{+}","pf");
		ent_BpRAA->SetTextFont(42);
		ent_BpRAA->SetLineColor(4);
		ent_BpRAA->SetMarkerColor(4);
		ent_BpRAA->SetTextSize(legendTextSize);
		otherSystnorm = new TBox(pti+TAABarWid*GlobSystPos[GlobSystPosCounter],1-systnormlo,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1+systnormhi);
		GlobSystPosCounter++;
		otherSystnorm->SetLineColor(kAzure+7);
		otherSystnorm->SetFillColor(kAzure+7);
		otherSystnorm->SetFillColorAlpha(kAzure+7, 0.5);
		//otherSystnorm->Draw();
	}

	// Draw B+ RpA
	TLegendEntry *ent_BpA;
	if(drawBpRpA){
		TGraphAsymmErrors* gBpADummy = new TGraphAsymmErrors();
		gBpADummy->SetFillColor(5);
		gBpADummy->SetMarkerStyle(21);
		ent_BpA = legendSigma->AddEntry(gBpADummy,"B^{+} R_{pA} (5.02 TeV)","pf");
	}

	// Draw np jpsi 2.76 
	if(drawJpsi){
		//expBeautyCMS_20161208();
		expBeautyCMS_20170201();
		TGraphAsymmErrors* gJpsiDummy = new TGraphAsymmErrors();
		gJpsiDummy->SetFillColor(925);
		gJpsiDummy->SetMarkerColor(kGray+3);
		gJpsiDummy->SetMarkerStyle(34);
		gJpsiDummy->SetMarkerSize(1.5);
		gJpsiDummy->SetFillColor(kGray+2);
		gJpsiDummy->SetFillColorAlpha(kGray+2, 0.5);
		gJpsiDummy->SetLineColor(0);
		TLegendEntry *ent_ChHad = legendSigma->AddEntry(gJpsiDummy,"nonprompt J/#psi 1.6 < |y| < 2.4 (2.76 TeV)","pf");
		ent_ChHad->SetTextSize(legendTextSize);
		TGraphAsymmErrors* gJpsiDummy2 = new TGraphAsymmErrors();
		gJpsiDummy2->SetFillColor(924);
		gJpsiDummy2->SetMarkerColor(kGray+3);
		gJpsiDummy2->SetMarkerStyle(29);
		gJpsiDummy2->SetMarkerSize(1.5);
		gJpsiDummy2->SetFillColor(kGray+2);
		gJpsiDummy2->SetFillColorAlpha(kGray+2, 0.5);
		gJpsiDummy2->SetLineColor(0);
		TLegendEntry *ent_ChHad2 = legendSigma->AddEntry(gJpsiDummy2,"nonprompt J/#psi |y| < 2.4 (2.76 TeV)","pf");
		ent_ChHad2->SetTextSize(legendTextSize);
		systnorm = 0.075;
		otherSystnorm = new TBox(pti+TAABarWid*GlobSystPos[GlobSystPosCounter],0.9249388,pti+TAABarWid*GlobSystPos[GlobSystPosCounter+1],1.075061);
		GlobSystPosCounter++;
		otherSystnorm->SetLineColor(kGray+2);
		otherSystnorm->SetFillColor(kGray+2);
		otherSystnorm->SetFillColorAlpha(kGray+2, 0.5);
		otherSystnorm->Draw();
	}

	if(drawBpRpA){
		//DrawBRpAFONLL();
		DrawBRpA();
	}

	// Draw Theories
	if(drawThm){
		plotTheory_Bs();
		TGraphAsymmErrors* gThmDummy1 = new TGraphAsymmErrors();
		TGraphAsymmErrors* gThmDummy2 = new TGraphAsymmErrors();
		gThmDummy1->SetLineColor(colorTAMU_Bs);
		gThmDummy2->SetLineColor(0);
		gThmDummy2->SetFillColorAlpha(colorCUJET_Bs,0.5);
		gThmDummy1->SetFillStyle(styleTAMU_Bs);
		gThmDummy2->SetFillStyle(styleCUJET_Bs);
		gThmDummy1->SetLineWidth(8.);
		gThmDummy2->SetLineWidth(8.);
		TLegendEntry *ent_thm1 = legendSigma->AddEntry(gThmDummy1,"TAMU","l");
		TLegendEntry *ent_thm2 = legendSigma->AddEntry(gThmDummy2,"CUJET3.0","f");
		ent_thm1->SetTextSize(legendTextSize);
		ent_thm2->SetTextSize(legendTextSize);
	}

	legendSigma->Draw();

	// Draw Bs at the end for it to come on top of everything else
	if(drawB){
		if(BSepSys){
			gNuclearModification_UnCor->Draw("5same");
			gNuclearModification_Cor->Draw("5same");
		}
		else gNuclearModification->Draw("5same");
	}

	// Draw each thing again at the very end
	if(drawChHad){
		RpPb_Final_20161207(1);
	}
	if(drawDRAA){
		TGraphAsymmErrors* gDNuclearModification = new TGraphAsymmErrors();
		Draw_DRAA(canvasRAA, gDNuclearModification, 1);
	}
	if(drawBpRAA){
		TGraphAsymmErrors* gBpNuclearModification = new TGraphAsymmErrors();
		canvasRAAPbPb_0_100(canvasRAA, gBpNuclearModification, 1);
	}
	if(drawJpsi){
		expBeautyCMS_20170201(1);
	} 
	if(drawB){
		hNuclearModification->Draw("same p");
	}
	if(drawB){
		hNuclearModification->Draw("same");
		bSystnorm->Draw();
	}

	canvasRAA->Update();
	canvasRAA->RedrawAxis();

	TString AddOn = "";
	if(BSepSys){
		AddOn = AddOn += "_SepUnc";
	}
	if(!drawB){
		AddOn = AddOn += "_NoB";
	}
	if(drawChHad){
		AddOn = AddOn += "_ChHadRAA";
	}
	if(drawDRAA){
		AddOn = AddOn += "_DRAA";
	}
	if(drawBpRAA){
		AddOn = AddOn += "_BpRAA";
	}
	if(drawJpsi){
		AddOn = AddOn += "_NPJpsiRAA";
	}
	if(drawThm){
		AddOn = AddOn += "_ThmRAA";
	}
	if(drawBpRpA){
		AddOn = AddOn += "_BpRpA";
	}


	canvasRAA->SaveAs(Form("%s/canvasRAA%s_%.0f_%.0f%s.pdf",outplotf.Data(),label.Data(),centMin,centMax,AddOn.Data()));
	canvasRAA->SaveAs(Form("%s/canvasRAA%s_%.0f_%.0f%s.png",outplotf.Data(),label.Data(),centMin,centMax,AddOn.Data()));
	canvasRAA->SaveAs(Form("%s/canvasRAA%s_%.0f_%.0f%s.eps",outplotf.Data(),label.Data(),centMin,centMax,AddOn.Data()));
	canvasRAA->SaveAs(Form("%s/canvasRAA%s_%.0f_%.0f%s.C",  outplotf.Data(),label.Data(),centMin,centMax,AddOn.Data()));
	TFile *fRAA=new TFile(outputfile.Data(),"recreate");
	fRAA->cd();
	gNuclearModification->Write();
	gNuclearModification_UnCor->Write();
	gNuclearModification_Cor->Write();
	hNuclearModification->Write();

}


int main(int argc, char *argv[])
{
	if(argc==9)
	{
		NuclearModificationFactor(argv[1], argv[2], argv[3], argv[4], argv[5], atoi(argv[6]), atof(argv[7]), atof(argv[8]));
		return 0;
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
}
