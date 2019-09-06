
#include "TAxis.h"
#include "uti.h"
#include "parameters.h"
#include "RooWorkspace.h"
#include "RooGlobalFunc.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooChebychev.h"
#include "RooPolynomial.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooPlot.h"
#include "RooFitResult.h"
#include "RooChi2Var.h"
#include "RooHist.h"
#include "RooProdPdf.h"
#include "RooAddition.h"
#include "RooProduct.h"
#include <RooBifurGauss.h>


using namespace RooFit;
using namespace std;

#define BSUBS_MASS 5.36682
#define BP_MASS 5.27915

bool drawSup = 0;

void clean0 (TH1D* h);
int    drawOpt=0;
double _ErrCor=1;

double setparam0=100.;
double setparam2=0.02;
double setparam3=0.06;
double fixparam1=BSUBS_MASS;

double minhisto=5.;
double maxhisto=6.;
int nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString seldata;
TString selmc;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;
Int_t _count=0;
RooWorkspace* inputw = new RooWorkspace();
RooWorkspace* outputw = new RooWorkspace("w");


RooFitResult *fit(TString variation, TString pdf,TString tree, TCanvas* c, TCanvas* cMC, RooDataSet* ds, RooDataSet* dsMC, RooDataHist* dh, RooDataHist* dhMC, RooRealVar* mass, RooPlot* &outframe, Double_t ptmin, Double_t ptmax, int isMC, bool isPbPb, Float_t centmin, Float_t centmax, TString npfit)
{
	cout<<"total data: "<<ds->numEntries()<<endl;
	TH1* h = dh->createHistogram("Bmass");
	h->Sumw2(kFALSE);
	h->SetBinErrorOption(TH1::kPoisson);
	h->SetMarkerSize(1.55);
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(4);
//	RooPlot* frameMC = mass->frame(5.2, 5.5);
	RooPlot* frameMC = mass->frame();
	frameMC->SetTitle("");
	//frameMC->SetXTitle("m_{B} (GeV/c^{2})");
	if(tree=="ntKp")frameMC->SetXTitle("m_{J/#psi(#mu#muK^{#pm})} (GeV/c^{2})");
	if(tree=="ntphi")frameMC->SetXTitle("m_{J/#psi(#mu#mu)#it{#phi}(KK)} (GeV/c^{2})");
	frameMC->SetYTitle("Events / (20 MeV/c^{2})");
	frameMC->GetXaxis()->CenterTitle();
	frameMC->GetYaxis()->CenterTitle();
	frameMC->GetXaxis()->SetTitleOffset(1.0);
	frameMC->GetYaxis()->SetTitleOffset(2.);
	frameMC->GetXaxis()->SetTitleSize(0.055);
	frameMC->GetYaxis()->SetTitleSize(0.035);
	frameMC->GetXaxis()->SetTitleFont(42);
	frameMC->GetYaxis()->SetTitleFont(42);
	frameMC->GetXaxis()->SetLabelFont(42);
	frameMC->GetYaxis()->SetLabelFont(42);
	frameMC->GetXaxis()->SetLabelSize(0.055);
	frameMC->GetYaxis()->SetLabelSize(0.035);
//	frameMC->GetYaxis()->SetMaxDigits(2);
	frameMC->SetStats(0);
	frameMC->GetXaxis()->SetNdivisions(-50205);
	//RooPlot* frame = (RooPlot*)frameMC->Clone();
//  (frameMC->GetXaxis())->SetRangeUser(5.0,6.0);
  //RooPlot* frame = (RooPlot*)frameMC->Clone();
  


	cMC->cd();
  double init_mean = 0;
  if(tree=="ntphi") init_mean = BSUBS_MASS;
  if(tree=="ntKp") init_mean = BP_MASS;

	RooRealVar meanMC(Form("meanMC%d_%s",_count,pdf.Data()),"",init_mean,5.,6.) ;
	RooRealVar sigma1MC(Form("sigma1MC%d_%s",_count,pdf.Data()),"",0.02,0.01,0.1) ;
	RooRealVar sigma2MC(Form("sigma2MC%d_%s",_count, pdf.Data()),"",0.06,0.01,0.1) ;
	RooRealVar sigma3MC(Form("sigma3MC%d_%s",_count, pdf.Data()),"",0.06,0.01,0.1) ;
	RooGaussian sig1MC(Form("sig1MC%d_%s",_count,pdf.Data()),"",*mass,meanMC,sigma1MC);  
	RooGaussian sig2MC(Form("sig2MC%d_%s",_count, pdf.Data()),"",*mass,meanMC,sigma2MC);  
	RooGaussian sig3MC(Form("sig3MC%d_%s",_count, pdf.Data()),"",*mass,meanMC,sigma3MC);  
	RooRealVar sig1fracMC(Form("sig1fracMC%d_%s",_count, pdf.Data()),"",0.5,0.,1.);
	RooRealVar sig2fracMC(Form("sig2fracMC%d_%s",_count, pdf.Data()),"",0.5,0.,1.);
	RooRealVar sig3fracMC(Form("sig3fracMC%d_%s",_count, pdf.Data()),"",0.5,0.,1.);
  
  RooAddPdf* sigMC;
  
  if((variation=="" && pdf=="") || variation== "background"|| (variation=="signal" && pdf=="1gauss")) sigMC = new RooAddPdf(Form("sigMC%d_%s",_count,pdf.Data()),"",RooArgList(sig1MC,sig2MC),sig1fracMC);
	if(variation=="signal" && pdf=="3gauss") sigMC = new RooAddPdf(Form("sigMC%d_%s",_count, pdf.Data()), "", RooArgList(sig1MC, sig2MC, sig3MC), RooArgList(sig1fracMC, sig2fracMC, sig3fracMC));

  RooRealVar a0MC(Form("a0MC%d",_count),"",0,0,1e6);
	RooRealVar a1MC(Form("a1MC%d",_count),"",0,-1e4,1e4);
	RooRealVar a2MC(Form("a2MC%d",_count),"",0,-1e4,1e4);
	//RooPolynomial bkgMC(Form("bkgMC%d",_count),"",*mass,RooArgSet(a0MC,a1MC,a2MC));//2nd order poly
	RooPolynomial bkgMC(Form("bkgMC%d_%s",_count, pdf.Data()),"",*mass,RooArgSet(a0MC,a1MC));//linear
	RooRealVar nsigMC(Form("nsigMC%d_%s",_count, pdf.Data()),"",1,0,1e8);
	RooRealVar nbkgMC(Form("nbkgMC%d",_count),"",0,0,1e5);
	RooAddPdf* modelMC;
  if(variation=="signal" && pdf=="1gauss") modelMC = new RooAddPdf(Form("modelMC%d_%s",_count, pdf.Data()),"",RooArgList(sig1MC),RooArgList(nsigMC));
  if((variation=="signal"&& pdf=="3gauss")||(variation==""&& pdf=="")||variation=="background") modelMC = new RooAddPdf(Form("modelMC%d_%s",_count, pdf.Data()),"",RooArgList(*sigMC),RooArgList(nsigMC));
	//RooAddPdf* modelMC = new RooAddPdf(Form("modelMC%d",_count),"",RooArgList(bkgMC,sigMC),RooArgList(nbkgMC,nsigMC));

  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;
	RooFitResult* fitResultMC = modelMC->fitTo(*dsMC,Save());
  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<dsMC->sumEntries()<<std::endl;



std::cout<<"mean_MC= "<<meanMC.getVal()<<std::endl;
std::cout<<"sigma1_MC= "<<sigma1MC.getVal()<<std::endl;
std::cout<<"sigma2_MC= "<<sigma2MC.getVal()<<std::endl;
std::cout<<"fraction1_MC= "<<sig1fracMC.getVal()<<std::endl;
std::cout<<"fraction2_MC= "<<sig2fracMC.getVal()<<std::endl;

	dsMC->plotOn(frameMC,Name(Form("dsMC_cut%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
  modelMC->plotOn(frameMC,Name(Form("bkgMC%d",_count)),Components(bkgMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineStyle(7),LineColor(4),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
  if(pdf!="1gauss"){
    modelMC->plotOn(frameMC,Name(Form("sigMC%d_%s",_count, pdf.Data())),Components(*sigMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
	  modelMC->plotOn(frameMC,Name(Form("sigFMC%d_%s",_count, pdf.Data())),Components(*sigMC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
	}
  else{
	std::cout<<"Chegou 1"<<std::endl;
    modelMC->plotOn(frameMC,Name(Form("sigMC%d_%s",_count, pdf.Data())),Components(sig1MC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
	  modelMC->plotOn(frameMC,Name(Form("sigFMC%d_%s",_count, pdf.Data())),Components(sig1MC),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
	}
	std::cout<<"Chegou 1"<<std::endl;
  
  modelMC->plotOn(frameMC,Name(Form("modelMC%d_%s",_count, pdf.Data())),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));
	//dsMC->plotOn(frameMC,Name(Form("dsMC%d",_count)),Binning(nbinsmasshisto*2),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	std::cout<<"Chegou 1"<<std::endl;
  double x_1 = 0.58;
  double x_2 = 0.95;
  double y_2 = 0.92;
  double y_1;
  double y_space = 0.04;
  double displace = 0.17;
  int nitems = 7;

  y_1 = y_2 - y_space*nitems;


  modelMC->paramOn(frameMC,Layout(x_1, x_2, y_1), Format("NEU",AutoPrecision(1)));
  frameMC->getAttText()->SetTextSize(0.02);
	frameMC->SetMaximum(nsigMC.getVal()*1.2);

//  modelMC->paramOn(frameMC, Layout());
	frameMC->Draw();
  
  cMC->RedrawAxis();
//  cMC->SetLogy();
  cMC->SaveAs("mc_afterfit_test.pdf");
//	RooPlot* frameMC = mass->frame();
  c->cd();
  RooPlot* frame = mass->frame();
  TPad *p1 = new TPad("p1","p1",0.,0.28,1.,0.99);
  // TPad *p1 = new TPad("p1","p1",0.05,0.05,0.99,0.99);
  p1->SetBorderMode(1); 
  p1->SetFrameBorderMode(0); 
  p1->SetBorderSize(2);
  p1->SetBottomMargin(0.10);
  p1->Draw(); 
  
    
  TPad *p2 = new TPad("p2","p2",0.,0.03,1.,0.24);// 0.26 
  p2->SetTopMargin(0.);    
  p2->SetBorderMode(0);
  p2->SetBorderSize(2); 
  p2->SetFrameBorderMode(0); 
  p2->SetTicks(1,1); 
//  p2->SetBottomMargin(0.2);
  p2->Draw();

	
  double mass_peak = 0;
  if(tree=="ntphi") mass_peak = BSUBS_MASS;
  if(tree=="ntKp") mass_peak = BP_MASS;

  double n_signal_initial = ds->sumEntries(TString::Format("abs(Bmass-%g)<0.05",mass_peak)) - ds->sumEntries(TString::Format("abs(Bmass-%g)<0.10&&abs(Bmass-%g)>0.05",mass_peak,mass_peak));
  if(n_signal_initial<0)
    n_signal_initial=1;

  double n_combinatorial_initial = ds->sumEntries() - n_signal_initial;
  p1->cd();
	RooRealVar mean(Form("mean%d",_count),"",meanMC.getVal(),5.,6.) ;
	RooRealVar sigma1(Form("sigma1%d",_count),"",sigma1MC.getVal(),0.01,0.1) ;
	RooRealVar sigma2(Form("sigma2%d",_count),"",sigma2MC.getVal(),0.01,0.1) ;
	RooRealVar sigma3(Form("sigma3%d",_count),"",sigma3MC.getVal(),0.01,0.1) ;
  RooGaussian sig1(Form("sig1%d",_count),"",*mass,mean,sigma1);  
  RooGaussian sig2(Form("sig2%d",_count),"",*mass,mean,sigma2);  
	RooGaussian sig3(Form("sig3%d",_count),"",*mass,mean,sigma3);  
  



	RooRealVar c1(Form("c1%d",_count),"",1.,0.,5.) ;


	//RooRealVar c2(Form("c2%d",_count),"",1.,0.,5.) ;
  RooGenericPdf sig1_gen(Form("sig1_gen%d",_count),"", Form("exp(-0.5*(((Bmass-mean%d)*(Bmass-mean%d))/((c1%d*sigma1%d)*(c1%d*sigma1%d))))",_count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean, sigma1, c1));
  RooGenericPdf sig2_gen(Form("sig2_gen%d",_count),"", Form("exp(-0.5*(((Bmass-mean%d)*(Bmass-mean%d))/((c1%d*sigma2%d)*(c1%d*sigma2%d))))", _count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean, sigma2, c1));
//  RooGenericPdf sig1(Form("sig1%d",_count),"", Form("(1/(c1%d*sigma1%d*sqrt(2*pi)))*exp(-0.5*(((Bmass-mean%d)*(Bmass-mean%d))/((c1%d*sigma1%d)*(c1%d*sigma1%d))))",_count, _count, _count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean, sigma1, c1));
 // RooGenericPdf sig2(Form("sig2%d",_count),"", Form("(1/(c1%d*sigma2%d*sqrt(2*pi)))*exp(-0.5*(((Bmass-mean%d)*(Bmass-mean%d))/((c1%d*sigma2%d)*(c1%d*sigma2%d))))", _count, _count, _count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean, sigma2, c1));
	RooRealVar sig1frac(Form("sig1frac%d",_count),"",sig1fracMC.getVal(),0.,1.);
	RooRealVar sig2frac(Form("sig2frac%d",_count),"",sig2fracMC.getVal(),0.,1.);
	RooAddPdf* sig;
  
//  if(((variation=="" && pdf=="") || variation=="background") && tree=="ntKp") sig = new RooAddPdf(Form("sig%d",_count),"",RooArgList(sig1_gen,sig2_gen),sig1frac);
  if((variation=="" && pdf=="") || variation== "background"|| (variation=="signal" && pdf=="1gauss")) sig = new RooAddPdf(Form("sig%d",_count),"",RooArgList(sig1,sig2),sig1frac);
	if(variation=="signal" && pdf=="3gauss") sig = new RooAddPdf(Form("sig%d",_count), "", RooArgList(sig1, sig2, sig3), RooArgList(sig1frac, sig2frac));
	//RooRealVar a0(Form("a0%d",_count),"a0",0.1,0.,1.);
	//RooRealVar a1(Form("a1%d",_count),"a1",0.1,0.,1.);
	//RooRealVar a2(Form("a2%d",_count),"a2",0.1,0.,1.);
	//RooChebychev bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1,a2));
    RooRealVar a0(Form("a0%d",_count),"",0.,-1e4,1e4);
  	RooRealVar a1(Form("a1%d",_count),"",0.,-1e4,1e4);
  	RooRealVar a2(Form("a2%d",_count),"",1e0,-1e4,1e4);
//	RooRealVar a3(Form("a3%d",_count),"",1e0,-1e4,1e4);
   	RooPolynomial bkg_1st(Form("bkg%d",_count),"",*mass,RooArgSet(a0));//2nd orderpoly
   	RooPolynomial bkg_2nd(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1));//2nd orderpoly
    RooPolynomial bkg_3rd(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1,a2));//2nd orderpoly
  	RooRealVar lambda(Form("lambda%d", _count), "lambda",-2., -5., 0.);
    RooExponential bkg(Form("bkg%d",_count),"",*mass,lambda);//2nd orderpoly
 // RooPolynomial bkg(Form("bkg%d",_count),"",*mass,a0);//linear
//  RooPolynomial bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1));//linear
	RooGenericPdf peakbg(Form("peakbg%d",_count),"",Form("(%s)",npfit.Data()),RooArgSet(*mass));
	RooRealVar nsig(Form("nsig%d",_count),"",n_signal_initial,0.,ds->sumEntries());
	RooRealVar nbkg(Form("nbkg%d",_count),"",n_combinatorial_initial,0.,ds->sumEntries());
//	RooRealVar nbkg(Form("nbkg%d",_count),"",n_combinatorial_initial,0.,200);
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
  std::cout<<"sumEntries: "<<ds->sumEntries()<<std::endl;
	RooRealVar npeakbg(Form("npeakbg%d",_count),"",1,0,1e5);
	RooAddPdf* model;
  if(variation=="" && pdf=="") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig,bkg),RooArgList(nsig,nbkg));
  if(npfit != "1" && variation=="" && pdf=="") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg,*sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
  if(variation=="background" && pdf=="1st") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig,bkg_1st),RooArgList(nsig,nbkg));
  std::cout<<"is it here??"<<std::cout;
  if(npfit != "1" && variation=="background" && pdf=="1st") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg_1st,*sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
  if(variation=="background" && pdf=="2nd") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig,bkg_2nd),RooArgList(nsig,nbkg));
  if(npfit != "1" && variation=="background" && pdf=="2nd") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg_2nd,*sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
  if(variation=="background" && pdf=="3rd") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig,bkg_3rd),RooArgList(nsig,nbkg));
  if(npfit != "1" && variation=="background" && pdf=="3rd") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg_3rd,*sig,peakbg),RooArgList(nbkg,nsig,npeakbg));
 
  if(variation=="signal" && pdf=="1gauss") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(sig1,bkg),RooArgList(nsig,nbkg));
  if(npfit != "1" && variation=="signal" && pdf=="1gauss") model = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg,sig1,peakbg),RooArgList(nbkg,nsig,npeakbg));
  if((variation=="signal"&& pdf=="3gauss")||(variation==""&&pdf=="")) model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig, bkg),RooArgList(nsig, nbkg));
  if(npfit!= "1" && ((variation=="signal"&&pdf=="3gauss")||(variation==""&&pdf==""))) model = new RooAddPdf(Form("model%d",_count),"",RooArgList(*sig, bkg, peakbg),RooArgList(nsig, nbkg, npeakbg));

  
//	mean.setConstant();
	sigma1.setConstant();
	if(pdf!="1gauss"){
    sigma2.setConstant();
    sig1frac.setConstant();
  }
  if(variation=="signal" && pdf=="3gauss"){
    sigma3.setConstant();
    sig2frac.setConstant();  
  }
  RooFitResult* fitResult = model->fitTo(*ds,Save(), Minos() , Extended(kTRUE));
  RooAbsReal* nll = model->createNLL(*ds);
  double log_likelihood= nll->getVal();

 //  a0.setVal(0.);
 // a0.setConstant();
  ds->plotOn(frame,Name(Form("ds_cut%d",_count)),Binning(nbinsmasshisto),MarkerSize(1),MarkerStyle(20),MarkerColor(1),LineColor(1),LineWidth(4),LineColor(1));//draw an transparent hist
  //std::cout<<"GETS hERE?"<<std::endl;

	if(npfit != "1") model->plotOn(frame,Name(Form("peakbg%d",_count)),Components(peakbg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3005),FillColor(kGreen+4),LineStyle(1),LineColor(kGreen+4),LineWidth(4));
	if(npfit != "1") model->plotOn(frame,Name(Form("peakbgF%d",_count)),Components(peakbg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3005),FillColor(kGreen+4),LineStyle(1),LineColor(kGreen+4),LineWidth(4));
	model->plotOn(frame,Name(Form("bkg%d",_count)),Components(bkg),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineStyle(7),LineColor(4),LineWidth(4));
  std::cout<<"GETS hERE?"<<std::endl;
	if(pdf!="1gauss"){
    model->plotOn(frame,Name(Form("sig%d",_count)),Components(*sig),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
    std::cout<<"GETS hERE not 1gauss?"<<std::endl;
	  model->plotOn(frame,Name(Form("sigF%d",_count)),Components(*sig),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
    std::cout<<"GETS hERE not 1gauss?"<<std::endl;
  }
	else{
    model->plotOn(frame,Name(Form("sig%d",_count)),Components(sig1),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
    std::cout<<"GETS hERE else?"<<std::endl;
	  model->plotOn(frame,Name(Form("sigF%d",_count)),Components(sig1),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("F"),FillStyle(3002),FillColor(kOrange-3),LineStyle(7),LineColor(kOrange-3),LineWidth(4));
    std::cout<<"GETS hERE else?"<<std::endl;
  }
	model->plotOn(frame,Name(Form("model%d",_count)),Normalization(1.0,RooAbsReal::RelativeExpected),Precision(1e-6),DrawOption("L"),LineColor(2),LineWidth(4));

  std::cout<<"GETS hERE?"<<std::endl;
	//ds->plotOn(frame,Name(Form("ds%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));
	if(tree=="ntphi")frame->SetMaximum(nsig.getVal()*1.2);
  if(tree=="ntKp")frame->SetMaximum(nsig.getVal()*0.9);
//	frame->SetMaximum((h->GetBinContent(h->GetMaximumBin())+h->GetBinError(h->GetMaximumBin()))*1.8);
  model->paramOn(frame,Layout(0.65, x_2, y_1-0.06), Format("NEU",AutoPrecision(3)));
  frame->getAttText()->SetTextSize(0.02);
/*  frame->getAttFill()->SetFillStyle(0);
  frame->getAttLine()->SetLineWidth(0);*/
  frame->SetTitle("");
  //frameMC->SetXTitle("m_{B} (GeV/c^{2})");
  //frame->SetXTitle("m_{J/#psi(#mu#mu)#it{#phi}(KK)} (GeV/c^{2})");
  frame->SetYTitle("Events / (20 MeV/c^{2})");
//  frame->GetXaxis()->SetTitle("m_{J/#psi(#mu#amu)#it{#phi}(KK)} (GeV/c^{2})");
//  frame->SetXTitle("mass lol");
	if(tree=="ntKp")frame->SetXTitle("m_{J/#psi(#mu#mu)K^{#pm}} (GeV/c^{2})");
	if(tree=="ntphi")frame->SetXTitle("m_{J/#psi(#mu#mu)#it{#phi}(KK)} (GeV/c^{2})");
//  frame->SetXTitle("m_{J/#psi(#mu#mu)#it{#phi}(KK)} (GeV/c^{2})");
  /*pull_plot->SetTitleFont(42, "X");
  pull_plot->SetTitleOffset(1.3, "X");  
  pull_plot->SetTitleSize(0.5, "X");*/
  frame->GetXaxis()->CenterTitle();
  frame->GetYaxis()->CenterTitle();
  frame->GetXaxis()->SetTitleOffset(1.1);
  frame->GetYaxis()->SetTitleOffset(1.4);
  frame->GetXaxis()->SetTitleSize(0.04);
  frame->GetYaxis()->SetTitleSize(0.05);
 // frame->GetXaxis()->SetTitleFont(42);
  frame->GetXaxis()->SetLabelFont(42);
  frame->GetYaxis()->SetTitleFont(42);
  frame->GetYaxis()->SetLabelFont(42);
  frame->GetXaxis()->SetLabelSize(0.045);
  frame->GetYaxis()->SetLabelSize(0.05);
//  frameMC->GetYaxis()->SetMaxDigits(2);
  frame->SetStats(0);
  (frame->GetXaxis())->SetRangeUser(minhisto,maxhisto);
  frame->GetXaxis()->SetNdivisions(-50205);	
	frame->Draw();
  
  RooHist* pull_hist = frame->pullHist(Form("ds_cut%d",_count),Form("model%d",_count));
//  RooHist* pull_hist = frame->pullHist("Data","Fit");
  
  RooPlot* pull_plot = mass->frame();
  (pull_plot->GetXaxis())->SetRangeUser(minhisto,maxhisto);
  RooRealVar x("x","",1e3,0,1e6);
  x.setVal(0.);
  RooGenericPdf* line_ref = new RooGenericPdf("ref_0", "ref_0", "x", RooArgList(x));
  line_ref->plotOn(pull_plot, LineStyle(7), LineColor(13), LineWidth(2));  

  pull_plot->addPlotable(static_cast<RooPlotable*>(pull_hist),"P");
  pull_plot->SetTitle("");

  pull_plot->SetXTitle("");
  pull_plot->SetYTitle("Pull");
  pull_plot->GetYaxis()->SetTitleFont(42);  
  pull_plot->GetYaxis()->SetTitleFont(42);  
  pull_plot->GetYaxis()->SetTitleSize(0.15);
  pull_plot->GetYaxis()->SetTitleOffset(0.4);
  pull_plot->GetYaxis()->CenterTitle();

/*  pull_plot->GetYaxis()->SetLabelFont(42);

  pull_plot->GetYaxis()->SetLabelSize(0.13);
  pull_plot->GetYaxis()->SetLabelOffset(0.005);*/
/*  pull_plot->SetTitleFont(42, "Y");
  pull_plot->SetTitleOffset(1.3, "Y");  
  pull_plot->SetTitleSize(0.5, "Y");*/
  pull_plot->GetXaxis()->SetLabelFont(42);
  pull_plot->GetXaxis()->SetLabelOffset(0.01);
  //pull_plot->GetXaxis()->SetTitleSize(0.2);
  //pull_plot->GetXaxis()->SetTitleOffset(1.);
  pull_plot->GetXaxis()->SetLabelFont(42);
  pull_plot->GetXaxis()->SetLabelSize(0.15);
  //pull_plot->GetXaxis()->SetTitleFont(42);
  pull_plot->GetXaxis()->SetTickLength(0.15);
  pull_plot->GetYaxis()->SetLabelFont(42);
  pull_plot->GetYaxis()->SetLabelOffset(0.01);
  pull_plot->GetYaxis()->SetLabelSize(0.15);
//  pull_plot->GetYaxis()->SetTitleSize(0.1);
  pull_plot->GetYaxis()->SetNdivisions(305);
  pull_plot->GetXaxis()->SetNdivisions(-50205);
//  c->SaveAs("dataset_afterfit_test.pdf");
//	h->Draw("same e");
 // c->RedrawAxis();
  std::cout<<"pull done"<<std::endl;
/*
	mass->setRange("signal",5.2,5.6);
	RooAbsReal* sigIntegral = sig->createIntegral(*mass,NormSet(*mass),Range("signal"));
	double sigIntegralErr = sigIntegral->getPropagatedError(*fitResult);
	RooAbsReal* bkgIntegral = bkg.createIntegral(*mass,NormSet(*mass),Range("signal"));
	double bkgIntegralErr = bkgIntegral->getPropagatedError(*fitResult);

	cout<<"nsig: "<<nsig.getVal()<<endl;
	//cout<<"nsig: "<<model->getParameters(*mass)->getRealValue("nsig")<<endl;
	cout<<"nsig error: "<<nsig.getError()<<endl;
	cout<<"sig integral: "<<sigIntegral->getVal()<<endl;
	cout<<"sig integral error: "<<sigIntegralErr<<endl;
	cout<<"nbkg: "<<nbkg.getVal()<<endl;
	//cout<<"nbkg: "<<model->getParameters(*mass)->getRealValue("nbkg")<<endl;
	cout<<"nbkg error: "<<nbkg.getError()<<endl;
	cout<<"bkg integral: "<<bkgIntegral->getVal()<<endl;
	cout<<"bkg integral error: "<<bkgIntegralErr<<endl;*/
	//cout<<"#expected events: "<<model->expectedEvents(RooArgSet(*mass))<<endl;
	//cout<<"model integral: "<<model->getNormIntegral(RooArgSet(*mass))->getVal()<<endl;
	//fitResult->Print("v");

	//RooHist* datahist = new RooHist();
	//datahist = frame->getHist("ds");
	//TGraphAsymmErrors* datagraph = static_cast<TGraphAsymmErrors*>(datahist);
	//RooCurve* modelcurve = new RooCurve();
	//modelcurve = frame->getCurve("model");

	Double_t yield = nsig.getVal();
	Double_t yieldErr = nsig.getError();
    TH1D* fh = (TH1D*)h->Clone("fh");
	double nexpected = model->expectedEvents(RooArgSet(*mass));
    double dataArr[nbinsmasshisto]; double dataErrArr[nbinsmasshisto]; double fitArr[nbinsmasshisto];
	double val = 0;
    for(int i = 0; i < nbinsmasshisto; i++){
        dataArr[i] = h->GetBinContent(i+1);
        dataErrArr[i] = h->GetBinError(i+1);
		mass->setVal(h->GetBinCenter(i+1));
		val = model->getVal(RooArgSet(*mass))*1./nbinsmasshisto*nexpected;
        fitArr[i] = val;
        fh->SetBinContent(i+1, fitArr[i]);
        fh->SetBinError(i+1, sqrt(fitArr[i]));
    }
	 cout<<"frame->chiSquare: "<<frame->chiSquare(Form("model%d",_count),Form("ds_cut%d",_count), fitResult->floatParsFinal().getSize())<<endl;
	 cout<<"pars= "<<fitResult->floatParsFinal().getSize()<<endl;
	 cout<<"chi2: "<<frame->chiSquare(Form("model%d",_count),Form("ds%d",_count))<<endl;
	//RooChi2Var chi2_lowstat("chi2_lowstat","chi2",*model,*dh);
	//cout<<chi2_lowstat.getVal()<<endl;
    
    double chiRoo = frame->chiSquare(Form("model%d",_count),Form("ds_cut%d",_count), fitResult->floatParsFinal().getSize());
    double chi2Std = 0;
    double chi2Neyman = 0;
    double chi2Peason = 0;
    double chi2BakerCousins = 0;
    chi2Cal(dataArr, dataErrArr, fitArr, nbinsmasshisto, chi2Std, chi2Neyman, chi2Peason, chi2BakerCousins);
    printf("chi2 Standard: %f\n",chi2Std);
    printf("chi2 Neyman: %f\n",chi2Neyman);
    printf("chi2 Peason: %f\n",chi2Peason);
    printf("chi2 Baker & Cousins: %f\n",chi2BakerCousins);

	TLegend *leg = new TLegend(0.62,0.62,0.89,0.75,NULL,"brNDC"); 
    if(drawOpt == 1) {
		leg = new TLegend(0.65,0.7,0.89,0.89,NULL,"brNDC");
	}
	leg->SetBorderSize(0);
	leg->SetTextSize(0.03);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	//leg->AddEntry(frame->findObject(Form("ds%d",_count),"Data","pl");
    leg->AddEntry(h,"Data","pl");
	leg->AddEntry(frame->findObject(Form("model%d",_count)),"Fit","l");
	leg->AddEntry(frame->findObject(Form("sig%d",_count)),"Signal","f");
	//leg->AddEntry(frame->findObject(Form("bkg%d",_count)),"Combinatorial","l");
	leg->AddEntry(frame->findObject(Form("bkg%d",_count)),"Background","l");
	if(npfit != "1") leg->AddEntry(frame->findObject(Form("peakbg%d",_count)),"B #rightarrow J/#psi X","f");

	TLatex* texcms = new TLatex(0.21,0.88,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.04);
	texcms->SetLineWidth(2);
    TLatex* texpre = new TLatex(0.30,0.88,"Preliminary");
    texpre->SetNDC();
    texpre->SetTextAlign(13);
    texpre->SetTextFont(52);
    texpre->SetTextSize(0.04);
    texpre->SetLineWidth(2);
    TLatex* texsup = new TLatex(0.21,0.815,"Supplementary");
    texsup->SetNDC();
    texsup->SetTextAlign(13);
    texsup->SetTextFont(52);
    texsup->SetTextSize(0.05);
    texsup->SetLineWidth(2);
	TLatex* texB;
  if(tree=="ntphi") texB = new TLatex(0.21,0.8,"B^{0}_{s}");
  if(tree=="ntKp") texB = new TLatex(0.21,0.8,"B^{#pm}");
	if(drawSup) texB = new TLatex(0.45,0.84,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(62);
	texB->SetTextSize(0.045);
	texB->SetLineWidth(2);

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc") texCol= new TLatex(0.95,0.94, Form("28.0 pb^{-1} (%s 5.02 TeV)","pp"));
	else texCol= new TLatex(0.945,0.94, Form("1.5 nb^{-1} (%s 5.02 TeV)","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.055);
	texCol->SetTextFont(42);
	
	float posit = 0.58;
	int nDOF = nbinsmasshisto-(fitResult->floatParsFinal().getSize());
	float nChi2 = chi2BakerCousins/(nbinsmasshisto-(fitResult->floatParsFinal().getSize()));
	int nDigit_chi2BakerCousins = 2;
	int nDigit_nChi2 = 2;
	chi2BakerCousins = roundToNdigit(chi2BakerCousins);
	nChi2 = roundToNdigit(nChi2);
	nDigit_chi2BakerCousins = sigDigitAfterDecimal(chi2BakerCousins);
	nDigit_nChi2 = sigDigitAfterDecimal(nChi2);
    TLatex* texChi = new TLatex(0.65,0.64, Form("#chi^{2}/nDOF = %2f", chiRoo));
    texChi->SetNDC();
    texChi->SetTextAlign(12);
    texChi->SetTextSize(0.03);
    texChi->SetTextFont(42);

/*	double width = 0.05;
	double BmassH = BSUBS_MASS + width;
	double BmassL = BSUBS_MASS - width;
	mass->setRange("signal",BmassL,BmassH);
	bkgIntegral = bkg.createIntegral(*mass,NormSet(*mass),Range("signal"));
	bkgIntegralErr = bkgIntegral->getPropagatedError(*fitResult);	
	cout<<"bkg integral: "<<bkgIntegral->getVal()<<endl;
	cout<<"bkg integral error: "<<bkgIntegralErr<<endl;
	Double_t bkgd = nbkg.getVal();
	bkgd = bkgd*bkgIntegral->getVal();
	Double_t SB = yield/bkgd;
	int nDigit_yield = 3;
	yield = roundToNdigit(yield);
	nDigit_yield = sigDigitAfterDecimal(yield);
	int nDigit_yieldErr = 3;
	yieldErr = roundToNdigit(yieldErr, int(log10(yieldErr))+1+nDigit_yield);
	nDigit_yieldErr = sigDigitAfterDecimal(yieldErr, int(log10(yieldErr))+1+nDigit_yield);
    TLatex* texYield = new TLatex(0.58,posit-0.06,Form("Yield = %.*f#pm%.*f", nDigit_yield, yield, nDigit_yieldErr, yieldErr));
    texYield->SetNDC();
    texYield->SetTextFont(42);
    texYield->SetTextSize(0.04);
    texYield->SetLineWidth(2);*/


/*  RooRealVar mean_new(Form("mean_new%d",_count),"",meanMC.getVal(),5.,6.) ;
	RooRealVar sigma1_new(Form("sigma1_new%d",_count),"",sigma1MC.getVal(),0.01,0.1) ;
	RooRealVar sigma2_new(Form("sigma2_new%d",_count),"",sigma2MC.getVal(),0.01,0.1) ;
	RooRealVar c1_new(Form("c1_new%d",_count),"",1.,0.,5.) ;
	RooRealVar c2_new(Form("c2_new%d",_count),"",1.,0.,5.) ;
  RooGenericPdf sig1_gen_new(Form("sig1_gen_new%d",_count),"", Form("exp(-0.5*(((Bmass-mean_new%d)*(Bmass-mean_new%d))/((c1_new%d*sigma1_new%d)*(c1_new%d*sigma1_new%d))))",_count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean_new, sigma1_new, c1_new));
  RooGenericPdf sig2_gen_new(Form("sig2_gen_new%d",_count),"", Form("exp(-0.5*(((Bmass-mean_new%d)*(Bmass-mean_new%d))/((c1_new%d*sigma2_new%d)*(c1_new%d*sigma2_new%d))))", _count, _count, _count, _count, _count, _count), RooArgSet(*mass, mean_new, sigma2_new,c1_new));
	RooGaussian sig1_new(Form("sig1_new%d",_count),"",*mass,mean_new,sigma1_new);  
	RooGaussian sig2_new(Form("sig2_new%d",_count),"",*mass,mean_new,sigma2_new);  
	RooRealVar sig1frac_new(Form("sig1frac_new%d",_count),"",sig1fracMC.getVal(),0.,1.);

	RooAddPdf* sig_new;

//  if(tree=="ntKp") sig_new = new RooAddPdf(Form("sig_new%d",_count),"",RooArgList(sig1_gen_new,sig2_gen_new),sig1frac);
  if((variation=="" && pdf=="") || variation=="background") sig_new = new RooAddPdf(Form("sig_new%d",_count),"",RooArgList(sig1_new,sig2_new),sig1frac);

	//RooRealVar a0(Form("a0%d",_count),"a0",0.1,0.,1.);
	//RooRealVar a1(Form("a1%d",_count),"a1",0.1,0.,1.);
	//RooRealVar a2(Form("a2%d",_count),"a2",0.1,0.,1.);
	//RooChebychev bkg(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1,a2));
  RooRealVar lambda_new(Form("lambda_new%d",_count), "lambda",1., -5., 5.);
  RooExponential bkg_new(Form("bkg%d_new",_count),"",*mass,lambda_new);//2nd orderpoly
  RooRealVar a0_new(Form("a0_new%d",_count),"",0.,-1e4, 1e4);
	RooRealVar a1_new(Form("a1_new%d",_count),"",0.,-1e4,1e4);
	RooRealVar a2_new(Form("a2_new%d",_count),"",1e0,-1e4,1e4);
//	RooRealVar a3_new(Form("a3_new%d",_count),"",1e0,-1e4,1e4);
	RooPolynomial bkg_new_1st(Form("bkg_new%d",_count),"",*mass,a0_new);//2nd orderpoly
  RooPolynomial bkg_new_2nd(Form("bkg_new%d",_count),"",*mass,RooArgSet(a0_new, a1_new));//2nd orderpoly
  RooPolynomial bkg_new_3rd(Form("bkg_new%d",_count),"",*mass,RooArgSet(a0_new,a1_new,a2_new));//2nd orderpoly
//  RooPolynomial bkg_new(Form("bkg%d",_count),"",*mass,RooArgSet(a0,a1));//linear
	RooGenericPdf peakbg_new(Form("peakbg_new%d",_count),"",Form("(%s)",npfit.Data()),RooArgSet(*mass));
	RooRealVar nbkg_new(Form("nbkg_new%d",_count),"",1,0,1e5);
	RooRealVar npeakbg_new(Form("npeakbg_new%d",_count),"",1,0,1e5);
  RooRealVar nsig_new(Form("nsignew%d",_count),"",0,0,1e8);
  RooAddPdf* model_nosig;
  if(variation=="" && pdf=="") model_nosig  = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(bkg_new,*sig_new),RooArgList(nbkg_new,nsig_new));
  if(npfit != "1" && variation=="" && pdf=="") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(bkg_new,*sig_new,peakbg_new),RooArgList(nbkg_new,nsig_new,npeakbg_new));
  if(variation=="background" && pdf=="1st") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(*sig_new,bkg_new_1st),RooArgList(nsig_new,nbkg_new));
  std::cout<<"is it here??"<<std::cout;
  if(npfit != "1" && variation=="background" && pdf=="1st") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(bkg_new_1st,*sig_new,peakbg_new),RooArgList(nbkg_new,nsig_new,npeakbg_new));
  if(variation=="background" && pdf=="2nd") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(*sig_new,bkg_new_2nd),RooArgList(nsig_new,nbkg_new));
  if(npfit != "1" && variation=="background" && pdf=="2nd") model_nosig = new RooAddPdf(Form("model%d",_count),"",RooArgList(bkg_new_2nd,*sig_new,peakbg_new),RooArgList(nbkg_new,nsig_new,npeakbg_new));
  if(variation=="background" && pdf=="3rd") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(*sig_new,bkg_new_3rd),RooArgList(nsig_new,nbkg_new));
  if(npfit != "1" && variation=="background" && pdf=="3rd") model_nosig = new RooAddPdf(Form("modelnosig%d",_count),"",RooArgList(bkg_new_3rd,*sig_new,peakbg_new),RooArgList(nbkg_new,nsig_new,npeakbg_new));
//  mean.setConstant();
  sigma1_new.setConstant();
  sigma2_new.setConstant();
  sig1frac_new.setConstant();*/

  nsig.setVal(0.);
  nsig.setConstant();
	RooFitResult* fitResult_nosig = model->fitTo(*ds,Save());
  RooAbsReal* nll_nosig = model->createNLL(*ds);
  double log_likelihood_nosig= nll_nosig->getVal();
  double real_significance = sqrt(2*(-log_likelihood+log_likelihood_nosig));
  std::cout<<"REAL SIGNIFICANCE= "<<real_significance<<std::endl;
  std::cout<<"***********************************************************************"<<std::endl;
	//RooFitResult* fitResult = model->fitTo(*ds,Save(),Minos());
	//ds->plotOn(frame,Name(Form("ds%d",_count)),Binning(nbinsmasshisto),MarkerSize(1.55),MarkerStyle(20),LineColor(1),LineWidth(4));

	Double_t Significance =  real_significance;
//	Double_t Significance =  yield/TMath::Sqrt(bkgd+yield);
	int nDigit_Significance = 3;
	Significance = roundToNdigit(Significance);
	nDigit_Significance = sigDigitAfterDecimal(Significance);
	TLatex* texSig = new TLatex(0.65,0.67,Form("Significance = %.*f", nDigit_Significance, Significance));
	cout<<"Significance = "<<Significance<<endl;
	texSig->SetNDC();
	texSig->SetTextFont(42);
	texSig->SetTextSize(0.03);
	texSig->SetLineWidth(2);


	cMC->cd();
	leg->Draw("same");
	texcms->Draw();
  texpre->Draw("same");
	texB->Draw();
	c->cd();
  p1->cd();
  leg->Draw("same");
	texcms->Draw("");
  texpre->Draw("same");
	if(drawSup) texsup->Draw();
	texB->Draw();
	texCol->Draw();
    //if(1) {
    if(drawOpt == 1) {
		texSig->Draw("SAME");
		texChi->Draw("same");
		//texYield->Draw("SAME");
	}
  p2->cd();
  pull_plot->Draw();
  p1->cd();
	outframe = frame;
    outputw->import(*model);
	return fitResult;
}

void clean0(TH1D* h)
{
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		if(h->GetBinContent(i)==0) h->SetBinError(i,1);
	}
}

double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
    double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
    double erroronsigma=TMath::Sqrt(squarederroronsigma);
    return erroronsigma;
}
