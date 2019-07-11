#include "uti.h"
#include "parameters.h"
using namespace std;
#define BSUBS_MASS 5.36682

void clean0 (TH1D* h);
int    drawOpt=0;
double _ErrCor=1;

double setparam0=50000.;
double setparam1=BSUBS_MASS;
double setparam2=0.01;
double setparam3=0.06;
double fixparam1=BSUBS_MASS;

double minhisto=5.0;
double maxhisto=6.0;
int nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString seldata;
TString selmc;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;
static Int_t _count=0;
enum variationType{
	doubleGaus,
	singleGaus,
	tripleGaus,
	decreaseWidth,
	increaseWidth,
	floatMean,
	secondOrdBG,
	thirdOrdBG,
	exponentialBG,
	onlyBG,
	variationSize
};
struct variationStruct{
    TString varName; bool isSigVar;
};
struct variationStruct variationSetting[variationSize] = {
	{"doubleGaus", 1},
	{"singleGaus", 1},
	{"tripleGaus", 1},
	{"decreaseWidth", 1},
	{"increaseWidth", 1},
	{"floatMean", 1},
	{"secondOrdBG", 0},
	{"thirdOrdBG", 0},
	{"exponentialBG", 0},
	{"onlyBG", 0},
};
template <class T>
//TF1 *fit(TCanvas* c, TCanvas* cMC, TH1D* h, TH1D* hMCSignal, Double_t ptmin, Double_t ptmax, int isMC, bool isPbPb, TF1* &total,Float_t centmin, Float_t centmax, TString npfit, int funcOpt = 0)
TF1 *fit(T* c, TCanvas* cMC, TH1D* h, TH1D* hMCSignal, Double_t ptmin, Double_t ptmax, int isMC, bool isPbPb, TF1* &total,Float_t centmin, Float_t centmax, TString npfit, int funcOpt = 0)
{
	cout<<"total data: "<<h->GetEntries()<<endl;
	TString iNP = npfit;
    TString funcform = "";
	TString sigfunc;
	int FitFunc = 0;
	TString FitMethod;
	if(FitFunc == 0) FitMethod = "Double";
	if(FitFunc == 1) FitMethod = "Triple";

	//TString sigfunc = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*([9]*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8])+(1-[9])*Gaus(x,[1],[10])/(sqrt(2*3.14159)*[10])))";
	//TString sigfunc = "[0]*([7]*exp(-0.5*((x-[1])/[2])^2)/(sqrt(2*3.14159)*[2])+(1-[7])*exp(-0.5*((x-[1])/[8])^2)/(sqrt(2*3.14159)*[8]))";
	//TString bkgfunc = "[3]+[4]*x+[5]*x*x";
	//TString bkgfunc = "[3]+[4]*x";
	//TString sigfunc = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*([9]*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8])+(1-[9])*Gaus(x,[1],[10])/(sqrt(2*3.14159)*[10])))";
	TString bkgfunc = "[3]+[4]*x+[5]*x*x+[6]*x*x*x";
	if(funcOpt == singleGaus) sigfunc = "[0]*(Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2]))";//single Gaussian
	if(funcOpt == tripleGaus) sigfunc = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*([9]*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8])+(1-[9])*Gaus(x,[1],[10])/(sqrt(2*3.14159)*[10])))";//triple Gaussian
	if(funcOpt == decreaseWidth || funcOpt == increaseWidth) sigfunc = "[0]*([7]*Gaus(x,[1],[2]*(1+[12]))/(sqrt(2*3.14159)*[2]*(1+[12]))+(1-[7])*Gaus(x,[1],[8]*(1+[12]))/(sqrt(2*3.14159)*[8]*(1+[12])))";// increase width or decrease width
	if(funcOpt == secondOrdBG) bkgfunc = "[3]+[4]*x+[5]*x*x";//2nd order background
	if(funcOpt == thirdOrdBG) bkgfunc =  "[3]+[4]*x+[5]*x*x+[6]*x*x*x";//3rd order background
	if(funcOpt == exponentialBG) bkgfunc = "[3]*exp(-[4]*x)";//exponential background

	if(FitFunc == 0) sigfunc = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))";
	if(FitFunc == 1) sigfunc = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*([9]*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8])+(1-[9])*Gaus(x,[1],[10])/(sqrt(2*3.14159)*[10])))";


	funcform = sigfunc + "+" + bkgfunc;
	if(funcOpt == onlyBG) funcform = bkgfunc;//consider only background, for prompt fit
	if(npfit != "1") funcform = funcform + "+[11]*(" + iNP + ")";

	TF1 *f = new TF1(Form("f%d",_count),funcform.Data());
	f->SetNpx(5000);
	f->SetLineWidth(4);
	f->SetRange(minhisto,maxhisto);
	//clean0(h);

	/*
	if(weightdata != "1"){
		int maxb = h->GetMaximumBin();
		double _max = h->GetBinContent(maxb);
		double _maxE = h->GetBinError(maxb);
		_ErrCor = (_maxE/_max)/(1/sqrt(_max));
		f->SetParLimits(0,0,1e5);
		f->SetParLimits(4,-1e5,1e5);
		f->SetParLimits(11,0,1e4);
	}
	*/
	//signal setting
	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(8,setparam3);
	f->SetParameter(10,setparam3);
	f->SetParameter(12,0);
	f->SetParLimits(2,0.01,0.3);
	f->SetParLimits(8,0.01,1.0);
	f->SetParLimits(10,0.01,0.3);
	//signal fraction
	f->SetParLimits(7,0,1);
	f->SetParLimits(9,0,1);
	//remove background for MC fitting
	f->FixParameter(3,0);
	f->FixParameter(4,0);
	f->FixParameter(5,0);
	f->FixParameter(6,0);
	f->FixParameter(11,0);

	f->FixParameter(1,fixparam1);
	hMCSignal->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);

	
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"L m","",minhisto,maxhisto);
	
	/*
	hMCSignal->Fit(Form("f%d",_count),"M","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"M","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"M","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",_count),"M","",minhisto,maxhisto);
	*/
	cMC->cd();
	hMCSignal->SetMarkerSize(1.55);
	hMCSignal->SetMarkerStyle(20);
	hMCSignal->SetLineColor(1);
	hMCSignal->SetLineWidth(4);
	hMCSignal->SetStats(0);
	hMCSignal->GetXaxis()->SetNdivisions(-50205);
	hMCSignal->Draw("e");
	c->cd();

	f->ReleaseParameter(3);
	f->ReleaseParameter(4);
	f->SetParLimits(4,-0.7,-0.4);
	f->ReleaseParameter(5);
	f->ReleaseParameter(6);
	//some custome setting for PDF syst
	//if(funcOpt == linearBG) f->SetParLimits(4,0,1e3);
	if(funcOpt == exponentialBG) f->SetParLimits(4,0,5);
	f->ReleaseParameter(11);
	f->SetParLimits(11,0,1000);
	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(7,f->GetParameter(7));
	f->FixParameter(8,f->GetParameter(8));
	f->FixParameter(9,f->GetParameter(9));
	f->FixParameter(10,f->GetParameter(10));
	f->FixParameter(12,f->GetParameter(12));
	float relativeWidth = f->GetParameter(12);
	float relativeWidthErr = f->GetParError(12);
	h->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"q","",minhisto,maxhisto);
	if(funcOpt != floatMean) f->ReleaseParameter(1); 
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	if(funcOpt == decreaseWidth) {f->FixParameter(12,relativeWidth-relativeWidthErr); cout<<"width change: "<<relativeWidthErr/relativeWidth<<endl;}
	if(funcOpt == increaseWidth) {f->FixParameter(12,relativeWidth+relativeWidthErr);}
	if(funcOpt == decreaseWidth || funcOpt == increaseWidth){
		h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
		h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
		h->Fit(Form("f%d",_count),"L q","",minhisto,maxhisto);
	}
	TFitResultPtr fitResult = h->Fit(Form("f%d",_count),"L m s","",minhisto,maxhisto);
	
	TString Tag = "Data";
	if(isMC == 1) Tag = "MC";

	ofstream fout(Form("FitInfo_%s_%s_pt_%d.dat",FitMethod.Data(),Tag.Data(),_count));
	fout << "Parameter Number" << "     " << "Fit Value" << "     " << "Fit Error" << endl;
	fout << 0 << "     " <<  f->GetParameter(0) << "     " << f->GetParError(0) << endl;
	fout << 1 << "     " << f->GetParameter(1) << "     " << f->GetParError(1) << endl;
	fout << 2 << "     "<<  f->GetParameter(2) << "     " << f->GetParError(2) << endl;
	fout << 7 << "     "<<  f->GetParameter(7) << "     " << f->GetParError(7) << endl;
	fout << 8 << "     " << f->GetParameter(8) << "     " << f->GetParError(8) << endl;
	fout << 9 << "     " << f->GetParameter(9) << "     " << f->GetParError(9) << endl;
	fout << 10 << "     " << f->GetParameter(10) << "     " << f->GetParError(10) << endl;
	fout << 12 << "     " << f->GetParameter(12) << "     " << f->GetParError(12) << endl;



	TF1 *mass = new TF1(Form("fmass%d",_count),Form("%s",sigfunc.Data()));
	mass->SetParameter(0,f->GetParameter(0));
	mass->SetParameter(1,f->GetParameter(1));
	mass->SetParameter(2,f->GetParameter(2));
	mass->SetParameter(7,f->GetParameter(7));
	mass->SetParameter(8,f->GetParameter(8));
	mass->SetParameter(9,f->GetParameter(9));
	mass->SetParameter(10,f->GetParameter(10));
	mass->SetParameter(12,f->GetParameter(12));
	



	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(7,f->GetParError(7));
	mass->SetParError(8,f->GetParError(8));
	mass->SetParError(9,f->GetParError(9));
	mass->SetParError(10,f->GetParError(10));
	mass->SetParError(12,f->GetParError(12));
	mass->SetRange(minhisto,maxhisto);
	//mass->SetRange(5.16,5.40);
	mass->SetFillColor(kOrange-3);
	mass->SetLineColor(kOrange-3);
	mass->SetFillStyle(3002);
	mass->SetLineWidth(4);
	mass->SetLineStyle(7);

	TF1 *background = new TF1(Form("background%d",_count),Form("%s",bkgfunc.Data()));
	background->SetParameter(3,f->GetParameter(3));
	background->SetParameter(4,f->GetParameter(4));
	background->SetParameter(5,f->GetParameter(5));
	background->SetParameter(6,f->GetParameter(6));
	background->SetRange(minhisto,maxhisto);
	background->SetLineColor(4);
	background->SetLineStyle(7);
	background->SetLineWidth(4);

	TF1 *Bkpi = new TF1(Form("fBkpi%d",_count),"[0]*("+iNP+")");
	Bkpi->SetParameter(0,f->GetParameter(11));
	Bkpi->SetRange(minhisto,maxhisto);
	Bkpi->SetLineStyle(1);
	Bkpi->SetFillStyle(3005);
	Bkpi->SetLineColor(kGreen+4);
	Bkpi->SetFillColor(kGreen+4);
	Bkpi->SetLineWidth(4);

	//h->SetXTitle("m_{B} (GeV/c^{2})");
    h->SetXTitle("m_{J/#psi(#mu#mu)#phi(KK)} (GeV/c^{2})");
	h->SetYTitle("Events / (20 MeV/c^{2})");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->GetXaxis()->SetTitleOffset(1.0);
	h->GetYaxis()->SetTitleOffset(1.4);
	h->GetXaxis()->SetTitleSize(0.055);
	h->GetYaxis()->SetTitleSize(0.055);
	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);
	h->GetXaxis()->SetLabelFont(42);
	h->GetYaxis()->SetLabelFont(42);
	h->GetXaxis()->SetLabelSize(0.055);
	h->GetYaxis()->SetLabelSize(0.055);
	h->SetMarkerSize(1.55);
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(4);
	h->SetStats(0);
	h->GetXaxis()->SetNdivisions(-50205);
	//h->SetMaximum((h->GetBinContent(h->GetMaximumBin())+h->GetBinError(h->GetMaximumBin()))*1.4);
	h->SetMaximum((h->GetBinContent(h->GetMaximumBin())+h->GetBinError(h->GetMaximumBin()))*1.8);
	c->cd();
	h->Draw("e");
	if(npfit != "1"){
		//Bkpi->SetRange(5.00,5.60);
		Bkpi->Draw("same");
	}
	background->Draw("same");   
	mass->Draw("same");
	f->Draw("same");
	c->RedrawAxis();

	//accessing fir results
	//https://root.cern.ch/root/html/ROOT__Fit__FitResult.html
	//TFitResultPtr fr = h->Fit(Form("f%d",_count),"L m s e","",minhisto,maxhisto);
	//Int_t fitStatus = fr;
	//printf("fit result status: %d\n", fitStatus);
	//printf("Central val: %f\n", fr->GetParams()[0]);
	//printf("HESSE err: %f (%.2f%)\n" , fr->GetErrors()[0], fr->GetErrors()[0]/fr->GetParams()[0]*100);
	//printf("Minos err: %f (%.2f%), %f (%.2f%)\n", fr->LowerError(0), -fr->LowerError(0)/fr->GetParams()[0]*100, fr->UpperError(0), fr->UpperError(0)/fr->GetParams()[0]*100);
	//printf("diff in %: (%.2f%), (%.2f%)\n", -fr->LowerError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100, fr->UpperError(0)/fr->GetParams()[0]*100-fr->GetErrors()[0]/fr->GetParams()[0]*100);

	//print out chi2 calculations
	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);

	cout << "yield inside = " << yield << endl;
	cout << "yieldErr inside = " << yieldErr << endl;

	cout << "Gauss 1 Peak = " <<  mass->GetParameter(0) * mass->GetParameter(7) << endl;
	cout << "Gauss 1 Width = " <<  mass->GetParameter(2)  << endl;
	cout << "Gauss 2 Peak = " <<  mass->GetParameter(0) * (1 - mass->GetParameter(7)) * mass->GetParameter(9) << endl;
	cout << "Gauss 2 Width = " <<  mass->GetParameter(2)  << endl;
	cout << "Gauss 3 Peak = " <<  mass->GetParameter(0) * (1 - mass->GetParameter(7)) *(1 - mass->GetParameter(9)) << endl;
	cout << "Gauss 3 Width = " <<  mass->GetParameter(10)  << endl;


	TH1D* fh = (TH1D*)h->Clone("fh");
	double dataArr[nbinsmasshisto]; double dataErrArr[nbinsmasshisto]; double fitArr[nbinsmasshisto]; 
	for(int i = 0; i < nbinsmasshisto; i++){
		dataArr[i] = h->GetBinContent(i+1);
		dataErrArr[i] = h->GetBinError(i+1);
		fitArr[i] = f->Eval(h->GetBinCenter(i+1));
		fh->SetBinContent(i+1, fitArr[i]);
		fh->SetBinError(i+1, sqrt(fitArr[i]));
	}
	printf("f->GetNDF: %d, f->GetChisquare: %f\n", f->GetNDF(), f->GetChisquare());
	printf("h->Chisquare(f): %f, h->Chisquare(f,'L'): %f \n", h->Chisquare(f), h->Chisquare(f,"L"));
	printf("h->Chi2Test(fh): %f\n", h->Chi2Test(fh, "UU CHI2"));
	printf("2*fitResult->MinFcnValue(): %f\n", 2*fitResult->MinFcnValue());
	printf("f->GetProb: %f, TMath::Prob: %f\n", f->GetProb(), TMath::Prob(f->GetChisquare(), f->GetNDF()));
    double chi2Std = 0;
    double chi2Neyman = 0;
    double chi2Peason = 0;
    double chi2BakerCousins = 0;
	chi2Cal(dataArr, dataErrArr, fitArr, nbinsmasshisto, chi2Std, chi2Neyman, chi2Peason, chi2BakerCousins);
    printf("chi2 Standard: %f\n",chi2Std);
    printf("chi2 Neyman: %f\n",chi2Neyman);
    printf("chi2 Peason: %f\n",chi2Peason);
    printf("chi2 Baker & Cousins: %f\n",chi2BakerCousins);

    TLegend *leg = new TLegend(0.525,0.40,0.85,0.75,NULL,"brNDC");
    if(drawOpt == 1) {
        leg = new TLegend(0.525,0.57,0.85,0.80,NULL,"brNDC");
    }
	leg->SetBorderSize(0);
	leg->SetTextSize(0.055);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Data","pl");
	leg->AddEntry(f,"Fit","l");
	if(funcOpt != onlyBG) leg->AddEntry(mass,"Signal","f");
	leg->AddEntry(background,"Combinatorial","l");
	if(npfit != "1") leg->AddEntry(Bkpi,"B #rightarrow J/#psi X","f");
	leg->Draw("same");

	TLatex* texcms = new TLatex(0.22,0.87,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.075);
	texcms->SetLineWidth(2);
	//texcms->Draw();

	TLatex* texB = new TLatex(0.225,0.74,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(42);
	texB->SetTextSize(0.055);
	texB->SetLineWidth(2);
	//texB->Draw();

	// preliminary setting
	texcms = new TLatex(0.21,0.88,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
    //TLatex* texpre = new TLatex(0.21,0.83,"Preliminary");
    TLatex* texpre = new TLatex(0.21,0.83,"Supplementary");
    texpre->SetNDC();
    texpre->SetTextAlign(13);
    texpre->SetTextFont(52);
    texpre->SetTextSize(0.035);
    texpre->SetLineWidth(2);
    //texpre->Draw();
	texB = new TLatex(0.225,0.68,"B^{0}_{s}");
	texB->SetNDC();
	texB->SetTextFont(62);
	texB->SetTextSize(0.07);
	texB->SetLineWidth(2);
	texB->Draw();
	// preliminary setting

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP"||collisionsystem=="ppInc"||collisionsystem=="PbPbInc") texCol= new TLatex(0.95,0.94, Form("28.0 pb^{-1} (%s 5.02 TeV)","pp"));
	else texCol= new TLatex(0.945,0.94, Form("1.5 nb^{-1} (%s 5.02 TeV)","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.055);
	texCol->SetTextFont(42);
	texCol->Draw();

	float Chi2 =  f->GetChisquare();
	int nDOF = f->GetNDF();
    float nChi2 =  f->GetChisquare()/f->GetNDF();
   // float nChi2 = f->GetChisquare();
	int nDigit_chi2BakerCousins = 2;
    int nDigit_nChi2 = 2;
    chi2BakerCousins = roundToNdigit(chi2BakerCousins);
    nChi2 = roundToNdigit(nChi2);
    nDigit_chi2BakerCousins = sigDigitAfterDecimal(chi2BakerCousins);
	
	cout << "Chi2 = " <<  Chi2 << "  nChi2 = " << nChi2 << endl;

    nDigit_nChi2 = sigDigitAfterDecimal(nChi2);
    TLatex* texChi = new TLatex(0.55,0.50, Form("#chi^{2}/nDOF: %.*f/%d = %.*f", nDigit_chi2BakerCousins, Chi2, nDOF, nDigit_nChi2, nChi2));
	texChi->SetNDC();
	texChi->SetTextAlign(12);
	texChi->SetTextSize(0.04);
	texChi->SetTextFont(42);

	double width = 0.05;
	double BmassH = BSUBS_MASS + width;
	double BmassL = BSUBS_MASS - width;
	Double_t bkgd = background->Integral(BmassL,BmassH)/binwidthmass;
	cout<<"BG in signal region: "<<bkgd<<endl;
	Double_t SB = yield/bkgd;
    Double_t Significance =  yield/TMath::Sqrt(bkgd+yield);
    int nDigit_Significance = 6;
    Significance = roundToNdigit(Significance);
    nDigit_Significance = sigDigitAfterDecimal(Significance);
    TLatex* texSig = new TLatex(0.55,0.54,Form("Significance = %.*f", nDigit_Significance, Significance));
    cout<<"Significance = "<<Significance<<endl;
	texSig->SetNDC();
	texSig->SetTextFont(42);
	texSig->SetTextSize(0.04);
	texSig->SetLineWidth(2);

//    int nDigit_yield = 6;
 //   yield = roundToNdigit(yield);
//    nDigit_yield = sigDigitAfterDecimal(yield);
 //   TLatex* texYield = new TLatex(0.55,0.44,Form("Yield = %.*f", nDigit_yield, yield));

	TLatex* texYield = new TLatex(0.55,0.44,Form("Yield = %f", yield));
	texYield->SetNDC();
	texYield->SetTextFont(42);
	texYield->SetTextSize(0.04);
	texYield->SetLineWidth(2);

//	int nDigit_yieldErr = 6;
//	yieldErr = roundToNdigit(yieldErr);
//    nDigit_yieldErr = sigDigitAfterDecimal(yieldErr);
	//TLatex* texYieldErr = new TLatex(0.55,0.34,Form("YieldErr = %.*f", nDigit_yieldErr, yieldErr));
	TLatex* texYieldErr = new TLatex(0.55,0.34,Form("YieldErr = %f", yieldErr));
	texYieldErr->SetNDC();
	texYieldErr->SetTextFont(42);
	texYieldErr->SetTextSize(0.04);
	texYieldErr->SetLineWidth(2);


	TF1* t = (TF1*)h->GetFunction(Form("f%d",_count))->Clone();
	h->GetFunction(Form("f%d",_count))->Delete();
	t->Draw("same");
	h->Draw("e same");
    //if(1) {
    if(drawOpt == 1) {
        texChi->Draw();
        texSig->Draw("SAME");
        texYield->Draw("SAME");
		texYieldErr->Draw("SAME");
    }
	f->Write();
	h->Write();
	hMCSignal->Write();

	total=f;
	return mass;
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
