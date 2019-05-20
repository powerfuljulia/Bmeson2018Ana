#include "fitB.h"

int _nBins = nBins;
double *_ptBins = ptBins;
void fitPDFSyst(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
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

	TH1D* h;
	TH1D* hMCSignal;
	TH1D* hpull;

	TTree* nt;
	TTree* ntGen;
	TTree* ntMC;

	TF1 *total;
	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

	TH1D* hPt;
	TH1D* hPtMC;
	TH1D* hPtGen;
	TH1D* hMean;
	TH1D* hSigmaGaus1;
	TH1D* hSigmaGaus2;

    TString _prefix = "";
    TString _isMC = "data";
    if(isMC) _isMC = "mc";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	// loop over different fitting function
	int variationTypes = exponentialBG+1;
	for(int i=0;i<_nBins;i++)
	{
        drawOpt = 1;
		h = (TH1D*)inf->Get(Form("h%d",i+1));
		hMCSignal = (TH1D*)inf->Get(Form("hMCSignal%d",i+1));
		h->SetBinErrorOption(TH1::kPoisson);

		float yVar[variationTypes];

		for(int fopt=0; fopt<variationTypes; fopt++){
			//_count++;
			_count = i*variationTypes+fopt+1;
			TCanvas* c= new TCanvas(Form("c%d_%d",_count),"",600,750);
			float tpadr = 0.3;
		    TPad* pFit = new TPad("pFit","",0.,tpadr,1.,1.);
			pFit->SetBottomMargin(0);
		    pFit->Draw();
	        TCanvas* cMC= new TCanvas(Form("cMC%d",_count),"",600,600);

			hPt = new TH1D(Form("hPt%d",_count),"",_nBins,_ptBins);
			hPtMC = new TH1D(Form("hPtMC%d",_count),"",_nBins,_ptBins);
			hPtGen = new TH1D(Form("hPtGen%d",_count),"",_nBins,_ptBins);
			hMean = new TH1D(Form("hMean%d",_count),"",_nBins,_ptBins);                       
			hSigmaGaus1 = new TH1D(Form("hSigmaGaus1%d",_count),"",_nBins,_ptBins); 
			hSigmaGaus2 = new TH1D(Form("hSigmaGaus2%d",_count),"",_nBins,_ptBins); 

			//TF1* f = fit(c, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit, fopt);
			TF1* f = fit(pFit, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit, fopt);

			double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
			yVar[fopt] = yield;
			double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
			printf("yield: %f, yieldErr: %f\n", yield, yieldErr);
			yieldErr = yieldErr*_ErrCor;

			hPt->SetBinContent(i+1,yield/(_ptBins[i+1]-_ptBins[i]));
			hPt->SetBinError(i+1,yieldErr/(_ptBins[i+1]-_ptBins[i]));
			hMean->SetBinContent(i+1,f->GetParameter(1));
			hMean->SetBinError(i+1,f->GetParError(1));  

			TLatex* tex;
			tex = new TLatex(0.518,0.82,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
			if(varExp=="abs(By)") tex = new TLatex(0.518,0.82,Form("%.1f < y < %.1f",_ptBins[i],_ptBins[i+1]));
			tex->SetNDC();
			tex->SetTextFont(42);
			tex->SetTextSize(0.055);
			tex->SetLineWidth(2);
			tex->Draw();

			tex = new TLatex(0.735,0.75,"|y| < 2.4");
			if(varExp=="abs(By)") tex = new TLatex(0.65,0.75,"15 < p_{T} < 50 GeV.c");
			tex->SetNDC();
			tex->SetTextFont(42);
			tex->SetTextSize(0.055);
			tex->SetLineWidth(2);
			tex->Draw();

			c->cd();
		    TPad* pRatio = new TPad("pRatio","",0.,0.,1.,tpadr);
		    pRatio->SetTopMargin(0);
		    pRatio->SetBottomMargin(0.35);//0.25
			pRatio->Draw();
			pRatio->cd();
			TGraphAsymmErrors* pullgraph = new TGraphAsymmErrors();
			pullgraph->SetTitle("");
			pullgraph->SetMaximum(5);
			pullgraph->SetMinimum(-5);
			pullgraph->SetMarkerSize(1.55); pullgraph->SetMarkerStyle(20); pullgraph->SetLineColor(1); pullgraph->SetLineWidth(4);

			TH2F* hempty = new TH2F(Form("hempty%d",_count),"", 50, 5, 6, 50, -5, 5);
		    hempty->GetXaxis()->SetTitle("m_{B} (GeV/c^{2})");
		    hempty->GetYaxis()->SetTitle("Pull");
		    hempty->GetXaxis()->CenterTitle();
		    hempty->GetYaxis()->CenterTitle();
		    hempty->GetXaxis()->SetTitleOffset(1.0);
		    hempty->GetYaxis()->SetTitleOffset(0.35);
		    hempty->GetXaxis()->SetTitleSize(0.15);
		    hempty->GetYaxis()->SetTitleSize(0.17);
		    hempty->GetXaxis()->SetTitleFont(42);
		    hempty->GetYaxis()->SetTitleFont(42);
		    hempty->GetXaxis()->SetLabelFont(42);
		    hempty->GetYaxis()->SetLabelFont(42);
		    hempty->GetXaxis()->SetLabelSize(0.14);
		    hempty->GetYaxis()->SetLabelSize(0.14);
		    hempty->SetStats(0);
		    hempty->GetXaxis()->SetNdivisions(-50205);
		    hempty->GetYaxis()->SetNdivisions(-505);
			hempty->SetTickLength(0.08);
			hempty->Draw();
		    h->GetYaxis()->SetTitleSize(0.08);
		    h->GetYaxis()->SetTitleOffset(0.8);

			double binerr;
			for(int b = 0; b < h->GetNbinsX(); b++){
				binerr = h->GetBinContent(b+1) > total->Eval(h->GetBinCenter(b+1)) ? h->GetBinErrorLow(b+1) : h->GetBinErrorUp(b+1);
				pullgraph->SetPoint(b,h->GetBinCenter(b+1),(h->GetBinContent(b+1)-total->Eval(h->GetBinCenter(b+1)))/binerr);
				//pullgraph->SetPointEYlow(b,h->GetBinErrorLow(b+1)/binerr);
				//pullgraph->SetPointEYhigh(b,h->GetBinErrorUp(b+1)/binerr);
				pullgraph->SetPointEYlow(b,1);
				pullgraph->SetPointEYhigh(b,1);
			}
			TLine* line = new TLine(5., 0., 6., 0.);
			line->SetLineStyle(9);
			line->SetLineWidth(4);
			line->SetLineColor(kGreen+1);
			line->Draw();
			pullgraph->Draw("p e same");
			c->SaveAs(Form("%s%s/%s_%s_%.0f_%.0f%s_fit%d.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_ptBins[i],_ptBins[i+1],_postfix.Data(),fopt));
	        cMC->SaveAs(Form("%s%s/%s_%s_%.0f_%.0f%s_fit%d.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_ptBins[i],_ptBins[i+1],_postfix.Data(),fopt));


			hMean->Write();
			hPt->Write();
		}  
		
		float sigVarMax = 0;
		float bkgVarMax = 0;
		FILE* outTextFile = fopen(Form("%s%s/varValues_%s_%d.txt",outplotf.Data(),_prefix.Data(),_isPbPb.Data(),i),"w");
		fprintf(outTextFile, Form("Pt range: %.0f ~ %.0f\n",_ptBins[i], _ptBins[i+1]));
		for(int fopt=0; fopt<variationTypes; fopt++){
			float varVal = abs(yVar[fopt]-yVar[0])/yVar[0]*100;
			printf("%15s,    yield: %f,    syst: %f(%)\n",variationSetting[fopt].varName.Data(), yVar[fopt], varVal);
			fprintf(outTextFile, "%15s,    yield: %f,    syst: %f(%)\n",variationSetting[fopt].varName.Data(), yVar[fopt], varVal);
			if(variationSetting[fopt].isSigVar) sigVarMax = max(sigVarMax, varVal);
			else bkgVarMax = max(bkgVarMax, varVal);
		}
		fprintf(outTextFile, Form("Max signal     variation: %f(%)\n",sigVarMax));
		fprintf(outTextFile, Form("Max background variation: %f(%)\n",bkgVarMax));

	}
	outf->Close();	
	return;

}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		fitPDFSyst(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
