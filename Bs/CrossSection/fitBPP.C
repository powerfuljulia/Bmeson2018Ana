#include "fitB.h"

int _nBins = nBins;
double *_ptBins = ptBins;
void fitBPP(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
{
	collisionsystem=collsyst;
	if(varExp == "Bpt1050"){
		_nBins = nBins1050;
		_ptBins = ptBins1050;
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

	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("ntphi");
		nt->AddFriend("ntHlt");
		nt->AddFriend("ntHi");
		nt->AddFriend("ntSkim");
		nt->AddFriend("BDTStage1_pt15to50");
	
		ntGen = (TTree*)infMC->Get("ntGen");
		ntGen->AddFriend("ntHlt");
		ntGen->AddFriend("ntHi");
	
		ntMC = (TTree*)infMC->Get("ntphi");
		ntMC->AddFriend("ntHlt");
		ntMC->AddFriend("ntHi");
		ntMC->AddFriend("ntSkim");
		ntMC->AddFriend("BDTStage1_pt15to50");
		ntMC->AddFriend(ntGen);
	}

	TF1 *total;
	TString outputf;
	outputf = Form("%s",outputfile.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

	TH1D* hPt = new TH1D("hPt","",_nBins,_ptBins);
	TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
	TH1D* hPtGen = new TH1D("hPtGen","",_nBins,_ptBins);
	TH1D* hMean = new TH1D("hMean","",_nBins,_ptBins);                       
	TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",_nBins,_ptBins); 
	TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",_nBins,_ptBins); 

    weightgen = "pthatweight*(pow(10, -0.365511 + 0.030289*Gpt + -0.000691*Gpt*Gpt + 0.000005*Gpt*Gpt*Gpt))";
    weightmc  = "HLT_HIL1DoubleMu0ForPPRef_v1*pthatweight*(pow(10, -0.365511 + 0.030289*Bgenpt + -0.000691*Bgenpt*Bgenpt + 0.000005*Bgenpt*Bgenpt*Bgenpt))";
	if(usePbPb){
		weightgen = "pthatweight*(pow(10, -0.244653 + 0.016404*Gpt + -0.000199*Gpt*Gpt + 0.000000*Gpt*Gpt*Gpt))";
		weightmc = "(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)*pthatweight*(pow(10, -0.244653 + 0.016404*Bgenpt + -0.000199*Bgenpt*Bgenpt + 0.000000*Bgenpt*Bgenpt*Bgenpt))*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";
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
    	_count++;
		TCanvas* c= new TCanvas(Form("c%d",_count),"",600,600);
        TCanvas* cMC= new TCanvas(Form("cMC%d",_count),"",600,600);
		if(fitOnSaved == 0){
			drawOpt = 1;
			h = new TH1D(Form("h%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
			hMCSignal = new TH1D(Form("hMCSignal%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
    		if(isMC==1) nt->Project(Form("h%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
		    else        nt->Project(Form("h%d",_count),"Bmass",   Form("(%s&&%s>%f&&%s<%f)*(1/%s)",                seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			ntMC->Project(Form("hMCSignal%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)",weightmc.Data(),Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
		}
		if(fitOnSaved == 1){
			h = (TH1D*)inf->Get(Form("h%d",_count));
			hMCSignal = (TH1D*)inf->Get(Form("hMCSignal%d",_count));
		}
	    h->SetBinErrorOption(TH1::kPoisson);
		TF1* f = fit(c, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit);

		double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
		double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
        printf("yield: %f, yieldErr: %f\n", yield, yieldErr);
		yieldErr = yieldErr*_ErrCor;
		if(fitOnSaved == 0){
    		TH1D* htest = new TH1D(Form("htest%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
		    TString sideband = "(abs(Bmass-5.367)>0.2&&abs(Bmass-5.367)<0.3";
	    	nt->Project(Form("htest%d",_count),"Bmass",Form("%s&&%s&&%s>%f&&%s<%f)*(1/%s)",sideband.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
	    	std::cout<<"yield bkg sideband: "<<htest->GetEntries()<<std::endl;
		}

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

        c->SaveAs(Form("%s%s/%s_%s_%d%s.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,_postfix.Data()));
        cMC->SaveAs(Form("%s%s/%s_%s_%d%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,_postfix.Data()));

        TCanvas* cpull= new TCanvas(Form("cpull%d",_count),"",600,600);
        cpull->cd();
        TGraphAsymmErrors* pullgraph = new TGraphAsymmErrors();
        pullgraph->SetTitle("");
		pullgraph->SetMaximum(5);
		pullgraph->SetMinimum(-5);
		pullgraph->SetMarkerSize(1.55); pullgraph->SetMarkerStyle(20); pullgraph->SetLineColor(1); pullgraph->SetLineWidth(4);
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
		pullgraph->Draw();
        cpull->SaveAs(Form("%s%s/%s_%s_%d%s_pull.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,_postfix.Data()));
	}  

	hMean->Write();
	hPt->Write();
	if(fitOnSaved == 1){
		outf->Close();	
		return;
	}

	ntMC->Project("hPtMC",varExp.Data(),TCut(weightmc)*(TCut(selmc.Data())&&"(Bgen==23333)"));
	divideBinWidth(hPtMC);
	ntGen->Project("hPtGen","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
	divideBinWidth(hPtGen);

	TCanvas* cPt =  new TCanvas("cPt","",600,600);
	cPt->SetLogy();
	hPt->SetXTitle("B_{s} p_{T} (GeV/c)");
	hPt->SetYTitle("Uncorrected dN(B_{s})/dp_{T}");
	hPt->Draw();
	if(isMC==1)
	{
		hPtMC->Draw("same hist");
		TLegend* legPt = myLegend(0.55,0.80,0.90,0.94);
		legPt->AddEntry(hPt,"Signal extraction","pl");
		legPt->AddEntry(hPtMC,"Matched reco","lf");
		legPt->Draw("same");  
	}
	hPtMC->Sumw2();
	TH1D* hEff = (TH1D*)hPtMC->Clone("hEff");
	hEff->SetTitle(";B_{s} p_{T} (GeV/c);Efficiency");
	hEff->Sumw2();
	hEff->Divide(hPtGen);
	TCanvas* cEff = new TCanvas("cEff","",600,600);
	hEff->Draw();

	TH1D* hPtCor = (TH1D*)hPt->Clone("hPtCor");
	hPtCor->SetTitle(";B_{s} p_{T} (GeV/c);Corrected dN(B_{s})/dp_{T}");
	hPtCor->Divide(hEff);
	TCanvas* cPtCor=  new TCanvas("cCorResult","",600,600);
	cPtCor->SetLogy();
	hPtCor->Draw();
	if(isMC==1)
	{
		hPtGen->Draw("same hist");
		TLegend* legPtCor = myLegend(0.55,0.80,0.90,0.94);
		legPtCor->AddEntry(hPtCor,"Corrected signal","pl");
		legPtCor->AddEntry(hPtGen,"Generated B_{s}","lf");
		legPtCor->Draw("same");  
	}

	TH1D* hPtSigma= (TH1D*)hPtCor->Clone("hPtSigma");
	hPtSigma->SetTitle(";B_{s} p_{T} (GeV/c);d#sigma(B_{s})/dp_{T} (pb/GeV)");
	hPtSigma->Scale(1./(2*luminosity*BRchain));
	TCanvas* cPtSigma=  new TCanvas("cPtSigma","",600,600);
	cPtSigma->SetLogy();
	hPtSigma->Draw();

	hPtMC->Write();
	hPtGen->Write();
	hEff->Write();
	hPtCor->Write();
	hPtSigma->Write();
	outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==19)
	{
		fitBPP(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
