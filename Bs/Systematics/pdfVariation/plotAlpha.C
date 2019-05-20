using namespace std;
#include "uti.h"
#define nbins 7
#define nbinsMB 8
void plotAlpha()
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);
  gStyle->SetOptStat(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(0.8);

  Float_t tmp;
  Float_t ptCen[nbins],ptWid[nbins];
  Float_t ptCenMB[nbinsMB],ptWidMB[nbinsMB];

  Float_t ptmin_PPMB[nbinsMB],ptmax_PPMB[nbinsMB];
  ifstream fin_defaultnew_PPMB("outAlpha/defaultnew_PPMB.dat");  Float_t alpha_defaultnew_PPMB[nbinsMB]; Float_t alphaErr_defaultnew_PPMB[nbinsMB];
  for(int i=0;i<nbinsMB;i++)
    {
      fin_defaultnew_PPMB>>ptmin_PPMB[i];
      fin_defaultnew_PPMB>>ptmax_PPMB[i];
      fin_defaultnew_PPMB>>alpha_defaultnew_PPMB[i];
      fin_defaultnew_PPMB>>alphaErr_defaultnew_PPMB[i];
      ptCenMB[i] = (ptmin_PPMB[i]+ptmax_PPMB[i])/2.;
      ptWidMB[i] = (ptmax_PPMB[i]-ptmin_PPMB[i])/2.;
    }

  Float_t ptmin_PP[nbins],ptmax_PP[nbins];
  ifstream fin_defaultnew_PP("outAlpha/defaultnew_PP.dat");  Float_t alpha_defaultnew_PP[nbins]; Float_t alphaErr_defaultnew_PP[nbins];
  for(int i=0;i<nbins;i++)
    {
      fin_defaultnew_PP>>ptmin_PP[i];
      fin_defaultnew_PP>>ptmax_PP[i];
      fin_defaultnew_PP>>alpha_defaultnew_PP[i];
      fin_defaultnew_PP>>alphaErr_defaultnew_PP[i];
      ptCen[i] = (ptmin_PP[i]+ptmax_PP[i])/2.;
      ptWid[i] = (ptmax_PP[i]-ptmin_PP[i])/2.;
    }

  Float_t ptmin_PbPbMB[nbinsMB],ptmax_PbPbMB[nbinsMB];
  ifstream fin_defaultnew_PbPbMB("outAlpha/defaultnew_PbPbMB.dat");  Float_t alpha_defaultnew_PbPbMB[nbinsMB]; Float_t alphaErr_defaultnew_PbPbMB[nbinsMB];
  for(int i=0;i<nbinsMB;i++)
    {
      fin_defaultnew_PbPbMB>>ptmin_PbPbMB[i];
      fin_defaultnew_PbPbMB>>ptmax_PbPbMB[i];
      fin_defaultnew_PbPbMB>>alpha_defaultnew_PbPbMB[i];
      fin_defaultnew_PbPbMB>>alphaErr_defaultnew_PbPbMB[i];
    }

  Float_t ptmin_PbPb[nbins],ptmax_PbPb[nbins];
  ifstream fin_defaultnew_PbPb("outAlpha/defaultnew_PbPb.dat");  Float_t alpha_defaultnew_PbPb[nbins]; Float_t alphaErr_defaultnew_PbPb[nbins];
  for(int i=0;i<nbins;i++)
    {
      fin_defaultnew_PbPb>>ptmin_PbPb[i];
      fin_defaultnew_PbPb>>ptmax_PbPb[i];
      fin_defaultnew_PbPb>>alpha_defaultnew_PbPb[i];
      fin_defaultnew_PbPb>>alphaErr_defaultnew_PbPb[i];
    }

  TGraphErrors* gPPMB = new TGraphErrors(nbinsMB,ptCenMB,alpha_defaultnew_PPMB,ptWidMB,alphaErr_defaultnew_PPMB);
  TGraphErrors* gPP = new TGraphErrors(nbins,ptCen,alpha_defaultnew_PP,ptWid,alphaErr_defaultnew_PP);
  TGraphErrors* gPbPbMB = new TGraphErrors(nbinsMB,ptCenMB,alpha_defaultnew_PbPbMB,ptWidMB,alphaErr_defaultnew_PbPbMB);
  TGraphErrors* gPbPb = new TGraphErrors(nbins,ptCen,alpha_defaultnew_PbPb,ptWid,alphaErr_defaultnew_PbPb);
  TH2F* hempty = new TH2F("hempty","",20,0,102,10.,-1.,1.);
  hempty->GetXaxis()->SetTitle("D^{0} p_{T}(GeV/c)");
  hempty->GetYaxis()->SetTitle("(#sigma(Data)-#sigma(MC))/#sigma(MC)");
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
  TCanvas* cPP = new TCanvas("cPP","",600,600);
  hempty->Draw();
  gPPMB->Draw("psame");
  gPP->Draw("psame");
  cPP->SaveAs("plotAlpha/cAlphaPP.pdf");
  TCanvas* cPbPb = new TCanvas("cPbPb","",600,600);
  hempty->Draw();
  gPbPbMB->Draw("psame");
  gPbPb->Draw("psame");
  cPbPb->SaveAs("plotAlpha/cAlphaPbPb.pdf");

  
}

int main(int argc, char *argv[])
{
  if(argc!=1)
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
  else 
    {
      plotAlpha();
      return 0;
    }
}
