#include "roofitB.h"

int _nBins = nBins;
double *_ptBins = ptBins;
TTree* makeTTree(TTree* intree, TString treeTitle) 
{
	TTree* outtree = new TTree(treeTitle.Data(),treeTitle.Data());
	float mass;
	outtree->Branch("mass",&mass,"mass/F") ;
	int Bsize;
	float Bmass[20000];
	intree->SetBranchAddress("Bsize",&Bsize);
	intree->SetBranchAddress("Bmass",Bmass);
	int nentries = intree->GetEntries();
	for(int n=0; n<nentries; n++){
		intree->GetEntry(n);
		for(int b=0; b<Bsize; b++){
			mass = Bmass[b];
			outtree->Fill();
		}
	}
	return outtree ;
}
void roofitB(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString _varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
{
	collisionsystem=collsyst;
    TString varExp = _varExp;
	if(_varExp == "Bpt750"){
		_nBins = nBins750;
		_ptBins = ptBins750;
		varExp = "Bpt";
	}
	if(_varExp == "abs(By)"){
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
	gStyle->SetPadRightMargin(cRightMargin);
	gStyle->SetPadLeftMargin(cLeftMargin);
	gStyle->SetPadTopMargin(cTopMargin);
	gStyle->SetPadBottomMargin(cBottomMargin);
	gStyle->SetTitleX(.0f);

	TFile* inf = new TFile(inputdata.Data());
	TFile* infMC = new TFile(inputmc.Data());

	TH1D* h;
	TH1D* hMC;
	TH1D* hpull;

	TTree* nt = new TTree();
	TTree* ntMC = new TTree();
	TTree* ntGen = new TTree();
	TTree* skimtree = new TTree();
	TTree* skimtreeMC = new TTree();

	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("ntphi");
		ntMC = (TTree*)infMC->Get("ntphi");
		ntGen = (TTree*)infMC->Get("ntGen");
	}

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

	//RooWorkspace* w = new RooWorkspace("w");
	RooRealVar* mass = new RooRealVar("Bmass","Bmass",5,6);
	RooDataSet* ds = new RooDataSet();
	RooDataSet* dsMC = new RooDataSet();   
	RooDataHist* dh = new RooDataHist();   
	RooDataHist* dhMC = new RooDataHist();   
	RooPlot* frame = new RooPlot();
	RooHist* datahist = new RooHist();
	RooCurve* modelcurve = new RooCurve();

	weightgen = weightgen_pp;
	weightmc  = weightmc_pp;
	if(usePbPb){
		weightgen = weightgen_PbPb;
		weightmc = weightmc_PbPb;
	}

    TString _prefix = "";
    TString _isMC = "data";
    if(isMC) _isMC = "mcAsData";
    TString _isPbPb = "pp";
    if(usePbPb) _isPbPb = "PbPb";
    TString _postfix = "";
    if(weightdata!="1") _postfix = "_EFFCOR";

	for(int i=0;i<_nBins;i++)
	{
    	_count++;
		TCanvas* c= new TCanvas(Form("c%d",_count),"",600,600);
		TCanvas* cMC= new TCanvas(Form("cMC%d",_count),"",600,600);
		c->cd();
		if(fitOnSaved == 0){
			drawOpt = 1;
			// tree with selecitons applied, create RooDataSet
			if(isMC==1) skimtree = (TTree*)nt->CopyTree(Form("%s*(%s&&%s>%f&&%s<%f)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()), "skimtree");
			else        skimtree = (TTree*)nt->CopyTree(   Form("(%s&&%s>%f&&%s<%f)*(1/%s)",                seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()), "skimtree");
			skimtreeMC = (TTree*)ntMC->CopyTree(Form("%s*(%s&&%s>%f&&%s<%f)",weightmc.Data(),Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]), "skimtreeMC");
			ds = new RooDataSet(Form("ds%d",_count),"",skimtree, RooArgSet(*mass));
			dsMC = new RooDataSet(Form("dsMC%d",_count),"",skimtreeMC,RooArgSet(*mass));

			// create RooDataHist
			h = new TH1D(Form("h%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
			hMC = new TH1D(Form("hMC%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
			if(isMC==1) skimtree->Project(Form("h%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			else        skimtree->Project(Form("h%d",_count),"Bmass",   Form("(%s&&%s>%f&&%s<%f)*(1/%s)",                seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
			skimtreeMC->Project(Form("hMC%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)",weightmc.Data(),Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
			dh = new RooDataHist(Form("dh%d",_count),"",*mass,Import(*h));
			dhMC = new RooDataHist(Form("dhMC%d",_count),"",*mass,Import(*hMC));
			h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
			outputw->import(*ds);
			outputw->import(*dsMC);
			outputw->import(*dh);
			outputw->import(*dhMC);
		}
		if(fitOnSaved == 1){
			drawOpt = 1;
			inputw = (RooWorkspace*)inf->Get("w");
			ds = (RooDataSet*)inputw->data(Form("ds%d",_count));
			dsMC = (RooDataSet*)inputw->data(Form("dsMC%d",_count));
			dh = (RooDataHist*)inputw->data(Form("dh%d",_count));
			dhMC = (RooDataHist*)inputw->data(Form("dhMC%d",_count));
		}
		RooFitResult* f = fit(c, cMC, ds, dsMC, dh, dhMC, mass, frame, _ptBins[i], _ptBins[i+1], isMC, isPbPb, centmin, centmax, npfit);
		//datahist = frame->getHist("ds");
		//TGraphAsymmErrors* datagraph = static_cast<TGraphAsymmErrors*>(datahist);
		modelcurve = frame->getCurve(Form("model%d",_count));

		RooRealVar* fitYield = static_cast<RooRealVar*>(f->floatParsFinal().at(f->floatParsFinal().index(Form("nsig%d",_count))));
		double yield = fitYield->getVal();
		double yieldErr = fitYield->getError();
        printf("yield: %f, yieldErr: %f\n", yield, yieldErr);
		yieldErr = yieldErr*_ErrCor;
		if(fitOnSaved == 0){
    		TH1D* htest = new TH1D(Form("htest%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
		    TString sideband = "(abs(Bmass-5.367)>0.2&&abs(Bmass-5.367)<0.3";
	    	skimtree->Project(Form("htest%d",_count),"Bmass",Form("%s&&%s&&%s>%f&&%s<%f)*(1/%s)",sideband.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],weightdata.Data()));
	    	std::cout<<"yield bkg sideband: "<<htest->GetEntries()<<std::endl;
		}

		hPt->SetBinContent(i+1,yield/(_ptBins[i+1]-_ptBins[i]));
		hPt->SetBinError(i+1,yieldErr/(_ptBins[i+1]-_ptBins[i]));
		if(f->floatParsFinal().index(Form("nsig%d",_count)) != -1){
			RooRealVar* fitMean = static_cast<RooRealVar*>(f->floatParsFinal().at(f->floatParsFinal().index(Form("mean%d",_count))));
			hMean->SetBinContent(i+1,fitMean->getVal());
			hMean->SetBinError(i+1,fitMean->getError());  
		}

	    TLatex* tex;
	    //tex = new TLatex(0.55,0.85,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
		//if(varExp=="abs(By)") tex = new TLatex(0.55,0.85,Form("%.1f < y < %.1f",_ptBins[i],_ptBins[i+1]));
	    tex = new TLatex(0.21,0.72,Form("%.0f < p_{T} < %.0f GeV/c",_ptBins[i],_ptBins[i+1]));
		if(varExp=="abs(By)") tex = new TLatex(0.21,0.72,Form("%.1f < y < %.1f",_ptBins[i],_ptBins[i+1]));
	    tex->SetNDC();
	    tex->SetTextFont(42);
	    tex->SetTextSize(0.045);
	    tex->SetLineWidth(2);
	    tex->Draw();
	
	    //tex = new TLatex(0.75,0.80,"|y| < 2.4");
		//if(varExp=="abs(By)") tex = new TLatex(0.75,0.80,"15 < p_{T} < 50 GeV.c");
	    tex = new TLatex(0.21,0.66,"|y| < 2.4");
		if(varExp=="abs(By)") tex = new TLatex(0.21,0.66,"15 < p_{T} < 50 GeV.c");
	    tex->SetNDC();
	    tex->SetTextFont(42);
	    tex->SetTextSize(0.045);
	    tex->SetLineWidth(2);
	    tex->Draw();

	    tex = new TLatex(0.21,0.60,"Cent. 0-100%");
	    tex->SetNDC();
	    tex->SetTextFont(42);
	    tex->SetTextSize(0.045);
	    tex->SetLineWidth(2);
	    if(isPbPb) tex->Draw();

        c->SaveAs(Form("%s%s/%s_%s_%d%s.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,_postfix.Data()));
        c->SaveAs(Form("%s%s/%s_%s_%d%s.png",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,_postfix.Data()));
        c->SaveAs(Form("%s%s/%s_%s_%d%s.C",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,_postfix.Data()));
        cMC->SaveAs(Form("%s%s/%s_%s_%d%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,_postfix.Data()));
        cMC->SaveAs(Form("%s%s/%s_%s_%d%s.png",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,_postfix.Data()));
        cMC->SaveAs(Form("%s%s/%s_%s_%d%s.C",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,_postfix.Data()));

	    TH1* h = dh->createHistogram("Bmass");
	    h->GetEntries();
		h->Sumw2(kFALSE);
        h->SetBinErrorOption(TH1::kPoisson);
        TCanvas* cpull= new TCanvas(Form("cpull%d",_count),"",600,600);
        cpull->cd();
        TGraphAsymmErrors* pullgraph = new TGraphAsymmErrors();
        pullgraph->SetTitle("");
        pullgraph->SetMaximum(5);
        pullgraph->SetMinimum(-5);
        pullgraph->SetMarkerSize(1.55); pullgraph->SetMarkerStyle(20); pullgraph->SetLineColor(1); pullgraph->SetLineWidth(4);
		double x; double xfit; double y; double yfit;
        double binerr;
        for(int b = 0; b < h->GetNbinsX(); b++){
			modelcurve->GetPoint(modelcurve->findPoint(h->GetBinCenter(b+1)),xfit,yfit);
            binerr = h->GetBinContent(b+1) > yfit ? h->GetBinErrorLow(b+1) : h->GetBinErrorUp(b+1);
            pullgraph->SetPoint(b,h->GetBinCenter(b+1),(h->GetBinContent(b+1)-yfit)/binerr);
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
	outputw->Print();
	gDirectory->Add(outputw);
	outputw->Write();
	outf->Delete("ntphi;1");
	outf->Close();
}
