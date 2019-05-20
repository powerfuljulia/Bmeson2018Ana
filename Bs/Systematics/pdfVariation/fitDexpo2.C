using namespace std;
#include "uti.h"
#include "parameters.h"

double setparam0=50000.;
double setparam1=5.36682;
double setparam2=0.01;
double setparam3=0.06;
double fixparam1=5.36682;
//Double_t minhisto=5.0;
//Double_t maxhisto=6.0;
//Double_t nbinsmasshisto=50;
Double_t minhisto=5.00;
Double_t maxhisto=6.00;
Double_t nbinsmasshisto=50;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;


TString collisionsystem;
TString infname;
Float_t centmin,centmax;

void fitDexpo2(TString collsyst="PbPb",TString npfit="0" , Float_t centMin=0, Float_t centMax=100, TString outputfile="outfMasshisto/mass")
{
  collisionsystem = collsyst;
  infname = outputfile;
  centmin = centMin;
  centmax = centMax;

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  TF1* fit(Float_t ptmin, Float_t ptmax, TString npfit);
  ofstream fout(Form("outYield/expo2_%s_cent_%.0f_%.0f.dat",collsyst.Data(),centmin,centmax));
  ofstream falpha(Form("outAlpha/expo2_%s_cent_%.0f_%.0f.dat",collsyst.Data(),centmin,centmax));
  for(int i=0;i<nBins;i++)
    {
      TF1* f = fit(ptBins[i],ptBins[i+1], npfit.Data());
      Float_t yield = f->Integral(minhisto,maxhisto)/binwidthmass;
      fout<<ptBins[i]<<" "<<ptBins[i+1]<<" "<<yield<<endl;
      falpha<<ptBins[i]<<" "<<ptBins[i+1]<<" "<<f->GetParameter(6)<<" "<<f->GetParError(6)<<endl;
    }
  falpha.close();
  fout.close();
}



TF1* fit(Float_t ptmin, Float_t ptmax, TString npfit)
{

		static Int_t count=0;
	count++;
  TCanvas* c = new TCanvas(Form("c_%.0f_%.0f",ptmin,ptmax),"",600,600);
  TFile* infile = new TFile(Form("%s_%s_cent_%.0f_%.0f_pt_%.0f_%.0f.root",infname.Data(),collisionsystem.Data(),centmin,centmax,ptmin,ptmax));
  TH1F* h = (TH1F*)infile->Get("h");                    h->SetName(Form("h_%.0f_%.0f",ptmin,ptmax));
  TH1F* hMCSignal = (TH1F*)infile->Get("hMCSignal");    hMCSignal->SetName(Form("hMCSignal_%.0f_%.0f",ptmin,ptmax));
//  TH1F* hMCSwapped = (TH1F*)infile->Get("hMCSwapped");  hMCSwapped->SetName(Form("hMCSwapped_%.0f_%.0f",ptmin,ptmax));
 	TString iNP = npfit;
 
//  TF1* f = new TF1(Form("f_%.0f_%.0f",ptmin,ptmax),"[0]*([7]*([9]*Gaus(x,[1],[2]*(1+[11]))/(sqrt(2*3.14159)*[2]*(1+[11]))+(1-[9])*Gaus(x,[1],[10]*(1+[11]))/(sqrt(2*3.14159)*[10]*(1+[11])))+(1-[7])*Gaus(x,[1],[8]*(1+[11]))/(sqrt(2*3.14159)*[8]*(1+[11])))+[3]+[4]*x+[5]*x*x+[6]*x*x*x", 1.7, 2.0);

	//    TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]*exp([4]*x+[5]*x*x)+[11]*("+iNP+")");
  
	TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2]*(1+[12]))/(sqrt(2*3.14159)*[2]*(1+[12]))+(1-[7])*Gaus(x,[1],[8]*(1+[12]))/(sqrt(2*3.14159)*[8]*(1+[12])))+[3]*exp([4]*x)+[5]+[11]*("+iNP+")");


	//h->Draw();
	f->SetParLimits(4,-1000,1000);
	f->SetParLimits(2,0.01,0.10);
	f->SetParLimits(8,0.01,0.10);
	f->SetParLimits(7,0,1);
	f->SetParLimits(11,0,1000);
	f->SetParLimits(9,0,1);
	f->SetParLimits(10,0.01,0.10);


	f->SetParameter(0,setparam0);
	f->SetParameter(1,setparam1);
	f->SetParameter(2,setparam2);
	f->SetParameter(8,setparam3);
	f->FixParameter(1,fixparam1);
	f->FixParameter(11,0);
	f->FixParameter(12,0);

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
	h->GetEntries();

	hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
	hMCSignal->Fit(Form("f%d",count),"L m q","",minhisto,maxhisto);

	f->FixParameter(1,f->GetParameter(1));
	f->FixParameter(2,f->GetParameter(2));
	f->FixParameter(7,f->GetParameter(7));
	f->FixParameter(8,f->GetParameter(8));
	//f->ReleaseParameter(11);
	printf("Fixed para.:\n");
	printf("%f, %f, %f\n", f->GetParameter(2), f->GetParameter(7), f->GetParameter(8));
	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	f->ReleaseParameter(1);
	f->ReleaseParameter(12);
	f->SetParLimits(12,-0.1,0.1);

	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);

	
	
	TF1 *background = new TF1(Form("background%d",count),"[0]*exp([1]*x)");
	background->SetParameter(0,f->GetParameter(3));
	background->SetParameter(1,f->GetParameter(4));
//    background->SetParameter(2,f->GetParameter(5));
	background->SetLineColor(4);
	background->SetRange(minhisto,maxhisto);
	//background->SetLineStyle(2);//PAS
	background->SetLineStyle(7);//paper
	//background->SetLineWidth(5);
	background->SetLineWidth(9);

	TF1 *Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
	Bkpi->SetParameter(0,f->GetParameter(11));
	Bkpi->SetRange(minhisto,maxhisto);
	Bkpi->SetLineStyle(1);
	//Bkpi->SetFillStyle(3004);//PAS
	Bkpi->SetFillStyle(3005);//paper
	//Bkpi->SetLineColor(kGreen+1);//PAS
	//Bkpi->SetFillColor(kGreen+1);//PAS
	Bkpi->SetLineColor(kGreen+4);//paper
	Bkpi->SetFillColor(kGreen+4);//paper
	//Bkpi->SetLineWidth(5);
	Bkpi->SetLineWidth(9);

   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2]*(1+[5]))/(sqrt(2*3.14159)*[2]*(1+[5]))+(1-[3])*Gaus(x,[1],[4]*(1+[5]))/(sqrt(2*3.14159)*[4]*(1+[5])))");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8),f->GetParameter(12));
	mass->SetParError(0,f->GetParError(0));
	mass->SetParError(1,f->GetParError(1));
	mass->SetParError(2,f->GetParError(2));
	mass->SetParError(3,f->GetParError(7));
	mass->SetParError(4,f->GetParError(8));




	//mass->SetLineColor(2);//PAS
	//mass->SetFillColor(2);//PAS
	mass->SetFillColor(kOrange-3);//paper
	mass->SetLineColor(kOrange-3);//paper
	//mass->SetFillStyle(3004);//PAS
	mass->SetFillStyle(3002);//paper
	//mass->SetLineWidth(5);
	mass->SetLineWidth(9);
	//mass->SetLineStyle(2);//PAS
	mass->SetLineStyle(7);//paper

	//h->SetXTitle("m_{#mu#muK} (GeV/c^{2})");
	h->SetXTitle("m_{B} (GeV/c^{2})");
	h->SetYTitle("Events / (20 MeV/c^{2})");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
	//h->GetXaxis()->SetTitleOffset(1.3);
	//h->GetYaxis()->SetTitleOffset(1.8);
	h->GetXaxis()->SetTitleOffset(0.9);
	h->GetYaxis()->SetTitleOffset(1.3);
	//h->GetXaxis()->SetLabelOffset(0.007);
	//h->GetYaxis()->SetLabelOffset(0.007);
	//h->GetXaxis()->SetTitleSize(0.045);
	//h->GetYaxis()->SetTitleSize(0.045);
	h->GetXaxis()->SetTitleSize(0.07);
	h->GetYaxis()->SetTitleSize(0.07);
	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);
	h->GetXaxis()->SetLabelFont(42);
	h->GetYaxis()->SetLabelFont(42);
	//h->GetXaxis()->SetLabelSize(0.04);
	//h->GetYaxis()->SetLabelSize(0.04);
	h->GetXaxis()->SetLabelSize(0.06);
	h->GetYaxis()->SetLabelSize(0.06);
	//h->SetMarkerSize(1.0);
	h->SetMarkerSize(1.55);
	h->SetMarkerStyle(20);
	h->SetLineColor(1);
	h->SetLineWidth(5);
	h->SetStats(0);
	h->GetXaxis()->SetNdivisions(-50205);
	h->Draw("e");
	Bkpi->SetRange(5.00,5.60);
	Bkpi->Draw("same");
	background->Draw("same");   
	//mass->SetRange(5.16,5.40);
	mass->Draw("same");
	f->Draw("same");
	c->RedrawAxis();

	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);  
  std::cout<<"YIELD="<<yield<<std::endl;

  TLegend* leg = new TLegend(0.65,0.58,0.82,0.88,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillStyle(0);
  leg->AddEntry(h,"Data","pl");
  leg->AddEntry(f,"Fit","l");
  leg->AddEntry(mass,"B_{s} Signal","f");
 // leg->AddEntry(massSwap,"K-#pi swapped","f");
  leg->AddEntry(background,"Combinatorial","l");
  leg->Draw("same");

  TLatex* texCms = new TLatex(0.18,0.93, "#scale[1.25]{CMS} Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(12);
  texCms->SetTextSize(0.04);
  texCms->SetTextFont(42);
  texCms->Draw();

  TLatex* texCol = new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV",collisionsystem.Data()));
  texCol->SetNDC();
  texCol->SetTextAlign(32);
  texCol->SetTextSize(0.04);
  texCol->SetTextFont(42);
  texCol->Draw();

  TLatex* texPt = new TLatex(0.22,0.78,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
  texPt->SetNDC();
  texPt->SetTextFont(42);
  texPt->SetTextSize(0.04);
  texPt->SetLineWidth(2);
  texPt->Draw();

  TLatex* texY = new TLatex(0.22,0.83,"|y| < 2.4");
  texY->SetNDC();
  texY->SetTextFont(42);
  texY->SetTextSize(0.04);
  texY->SetLineWidth(2);
  texY->Draw();

  TLatex* texYield = new TLatex(0.22,0.73,Form("N_{D} = %.0f #pm %.0f",yield,yieldErr));
  texYield->SetNDC();
  texYield->SetTextFont(42);
  texYield->SetTextSize(0.04);
  texYield->SetLineWidth(2);
  texYield->Draw();

  c->SaveAs(Form("plotFits/DMass_expo2_%s_cent_%.0f_%.0f_pt_%.0f_%.0f.pdf",collisionsystem.Data(),centmin,centmax,ptmin,ptmax));

  TCanvas* cPull = new TCanvas(Form("cPull_%.0f_%.0f",ptmin,ptmax),"",600,700);
  TH1F* hPull = (TH1F*)h->Clone("hPull");
  for(int i=0;i<h->GetNbinsX();i++)
    {
      Float_t nfit = f->Integral(h->GetBinLowEdge(i+1),h->GetBinLowEdge(i+1)+h->GetBinWidth(i+1))/h->GetBinWidth(i+1);
      if(h->GetBinError(i+1)==0)
        {
          hPull->SetBinContent(i+1,0.);
        }
      else hPull->SetBinContent(i+1,(h->GetBinContent(i+1)-nfit)/h->GetBinError(i+1));
      hPull->SetBinError(i+1,0);
    }
  hPull->SetMinimum(-4.);
  hPull->SetMaximum(4.);
  hPull->SetYTitle("Pull");
  hPull->GetXaxis()->SetTitleOffset(1.);
  hPull->GetYaxis()->SetTitleOffset(0.65);
  hPull->GetXaxis()->SetLabelOffset(0.007);
  hPull->GetYaxis()->SetLabelOffset(0.007);
  hPull->GetXaxis()->SetTitleSize(0.12);
  hPull->GetYaxis()->SetTitleSize(0.12);
  hPull->GetXaxis()->SetLabelSize(0.1);
  hPull->GetYaxis()->SetLabelSize(0.1);
  hPull->GetYaxis()->SetNdivisions(504);
  TLine* lPull = new TLine(5.0, 0, 6.0, 0);
  lPull->SetLineWidth(1);
  lPull->SetLineStyle(7);
  lPull->SetLineColor(1);
  TPad* pFit = new TPad("pFit","",0,0.3,1,1);
  pFit->SetBottomMargin(0);
  pFit->Draw();
  pFit->cd();
  h->Draw("e");
  background->Draw("same");   
  mass->Draw("same");
// massSwap->Draw("same");
  f->Draw("same");
  leg->Draw("same");
  texCms->Draw();
  texCol->Draw();
  texPt->Draw();
  texY->Draw();
  texYield->Draw();
  cPull->cd();
  TPad* pPull = new TPad("pPull","",0,0,1,0.3);
  pPull->SetTopMargin(0);
  pPull->SetBottomMargin(0.3);
  pPull->Draw();
  pPull->cd();
  hPull->Draw("p");
  lPull->Draw();
  cPull->cd();
  cPull->SaveAs(Form("plotFits/DMass_expo2_%s_cent_%.0f_%.0f_pt_%.0f_%.0f_Pull.pdf",collisionsystem.Data(),centmin,centmax,ptmin,ptmax));
  
  return mass;
}

int main(int argc, char *argv[])
{
  if(argc==5)
    {
      fitDexpo2(argv[1],argv[2],atof(argv[3]),atof(argv[4]));
      return 0;
    }
  else if(argc==3)
    {
      fitDexpo2(argv[1],argv[2]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

