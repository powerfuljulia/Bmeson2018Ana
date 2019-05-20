#include "fitB.h"
using namespace std;
float tpadr = 0.7;
float tpadpos = 1-tpadr;

struct plotStruct{
	TString var;
	TString latex;
	TString text;
	bool dofit;
	bool setlogY;
	bool setlogX;
	int nBins;
	double arrBins[100];
	int printdecimaldigit;
};

//double inf = std::numeric_limits<double>::max();
//double inf = std::numeric_limits<double>::infinity();
double inf = 9999;
struct plotStruct plotSetting[23] = {
    {"Bpt", 						"B pt", 	       "Bpt", 		    0, 1, 0, 4, {7, 12, 15, 20, 50}, 0}, //0
    {"abs(By)", 					"B y", 		       "By", 		    0, 1, 0, 4, {0.0, 0.5, 1.0, 1.5, 2.4}, 1}, //1
    {"Btrk1Pt", 					"tk1 pt", 	       "Btrk1Pt", 	    0, 1, 0, 4, {0., 1.2, 2, 3, 30}, 0}, //2
    {"Btrk2Pt", 					"tk2 pt", 	       "Btrk2Pt", 	    0, 1, 0, 4, {0., 1.2, 2, 3, 30}, 0}, //3
    {"abs(Btrk1Eta)",				"tk1 eta",         "Btrk1Eta",      0, 1, 0, 4, {0.0, 0.4, 0.8, 1.4, 2.6}, 1}, //4
    {"abs(Btrk2Eta)",				"tk2 eta",         "Btrk2Eta",      0, 1, 0, 4, {0.0, 0.4, 0.8, 1.4, 2.6}, 1}, //5
    {"abs(Btrk1Dxy/Btrk1D0Err)", 	"normed tk1 Dxy",  "Btrk1Dxy",      0, 1, 0, 4, {0, 1.2, 4., 6, 30}, 1}, //6
    {"abs(Btrk2Dxy/Btrk1D0Err)", 	"normed tk2 Dxy",  "Btrk2Dxy",      0, 1, 0, 4, {0, 1.2, 4., 6, 30}, 1}, //7
    {"abs(Btktkmass-1.019455)", 	"|phi-PDG| mass",  "Btktkmass",     0, 1, 0, 4, {0., 0.0015, 0.003, 0.005, 0.015}, 4}, //8
    {"abs(Bmumumass-3.096916)",     "|jpsi-PDG| mass", "Bmumumass",     0, 1, 0, 4, {0, 0.01, 0.018, 0.03, 0.2}, 3}, //9
    {"BsvpvDistance/BsvpvDisErr", 	"SVPV", 	       "Bsvpv", 	    0, 1, 0, 4, {0., 10., 20., 30., 200}, 0}, //10
    {"Balpha", 						"alpha", 	       "Balpha", 	    0, 1, 0, 4, {0., 0.01, 0.02, 0.04, 0.3}, 2}, //11
    {"Bd0/Bd0Err", 					"normed d0", 	   "Bd0", 		    0, 1, 0, 4, {0.,1500,3000,6000,15000}, 0}, //12
    {"cos(Bdtheta)", 				"cos(theta)",      "cosBtheta",     0, 1, 0, 4, {0.9975,0.9995,0.9999,0.99997,1}, 5}, //13
    {"Bchi2cl", 					"fit prob", 	   "Bchi2cl", 	    0, 1, 0, 4, {0.,0.6,0.75,0.9,1}, 1}, //14
    {"Btktkpt", 					"phi pt", 	       "Btktkpt", 	    0, 1, 0, 4, {0.,2.5,4,7,40}, 0}, //15
    {"abs(Btktketa)", 				"phi eta",         "Btktketa",      0, 1, 0, 4, {0.0, 0.4, 0.8, 1.4, 2.6}, 1}, //16
    {"Bmu1pt", 						"mu1 pt", 	       "Bmu1pt", 	    0, 1, 0, 4, {0.,3.8,6,8,40}, 1}, //17
    {"Bmu1pt", 						"mu2 pt", 	       "Bmu2pt", 	    0, 1, 0, 4, {0.,3.8,6,8,40}, 1}, //18
    {"BDTStage1_pt7to15",			"BDT 7~15", 	   "BDT7to15",      0, 1, 0, 4, {0.1,0.25,0.3,0.35,1.}, 2}, //19
    {"BDTStage1_pt15to50",			"BDT 15~50", 	   "BDT15to50",     0, 1, 0, 4, {0.1,0.25,0.3,0.35,1.}, 2}, //20
    {"BDTStage1_pt7to15",			"PbPb BDT 7~15",   "PbPbBDT7to15",  0, 1, 0, 4, {-0.0,0.1,0.2,0.25,1.}, 2}, //21
    {"BDTStage1_pt15to50",			"PbPb BDT 15~50",  "PbPbBDT15to50", 0, 1, 0, 4, {-0.0,0.1,0.2,0.25,1.}, 2}, //22
};

int _nBins;
double *_ptBins;
using namespace std;
void fitVariables(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString varExp = "", TString trgselection = "",  TString trgselectionmc = "", TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100., int vartype = 1)
{
	varExp = plotSetting[vartype].var;
	_nBins = plotSetting[vartype].nBins;
	_ptBins = plotSetting[vartype].arrBins;
	collisionsystem=collsyst;
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

	TTree* nt;
	TTree* ntGen;
	TTree* ntMC;

	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("ntphi");
		//nt->AddFriend("ntHlt");
		//nt->AddFriend("ntHi");
		//nt->AddFriend("ntSkim");
		//nt->AddFriend("BDTStage1_pt15to50");
	
		ntGen = (TTree*)infMC->Get("ntGen");
		//ntGen->AddFriend("ntHlt");
		//ntGen->AddFriend("ntHi");
	
		ntMC = (TTree*)infMC->Get("ntphi");
		//ntMC->AddFriend("ntHlt");
		//ntMC->AddFriend("ntHi");
		//ntMC->AddFriend("ntSkim");
		//ntMC->AddFriend("BDTStage1_pt15to50");
		//ntMC->AddFriend(ntGen);
	}

	TF1 *total;
	TString outputf;
	outputf = Form("plotFitsComp/%s_VarCompare_pp.root",plotSetting[vartype].text.Data());
	TFile* outf = new TFile(outputf.Data(),"recreate");
	outf->cd();

	TH1D* hPt = new TH1D("hPt","",_nBins,_ptBins);
	TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
	TH1D* hMean = new TH1D("hMean","",_nBins,_ptBins);                       
	TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",_nBins,_ptBins); 
	TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",_nBins,_ptBins); 
	
	weightmc  = weightmc_pp;
	weightmc += Form("*((Bpt>7&&Bpt<15)*%f + (Bpt>15&&Bpt<20)*%f + (Bpt>20&&Bpt<50)*%f)",sf_pp_750[0],sf_pp_750[1],sf_pp_750[2]);
	if(usePbPb){
		weightmc = weightmc_PbPb;
	}
	//weightmc += Form("*%s",weightBtk1eta.Data());
	//weightmc += Form("*%s",weightBtk2eta.Data());

	TString _isMC = "data";
	if(isMC) _isMC = "mc";
	TString _isPbPb = "pp";
	if(usePbPb) _isPbPb = "PbPb";
    TString _prefix = "";
	if(fitOnSaved) _prefix = "OnSaved";
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
		int ndigit = plotSetting[vartype].printdecimaldigit;
        tex = new TLatex(0.4,0.85,Form("%*.*f < %s < %*.*f",6-ndigit,ndigit,_ptBins[i],plotSetting[vartype].latex.Data(),6-ndigit,ndigit,_ptBins[i+1]));
        tex->SetNDC();
        tex->SetTextFont(42);
//        tex->SetTextSize(0.035);
        tex->SetTextSize(0.045);
        tex->SetLineWidth(2);
        tex->Draw();

        //c->SaveAs(Form("plotFitsComp%s/%s_%s_%s_%.0f_%.0f%s.pdf",_prefix.Data(),plotSetting[vartype].text.Data(),_isMC.Data(),_isPbPb.Data(),_ptBins[i],_ptBins[i+1],_postfix.Data()));
        c->SaveAs(Form("plotFitsComp%s/%s_%s_%s_%d%s.pdf",_prefix.Data(),plotSetting[vartype].text.Data(),_isMC.Data(),_isPbPb.Data(),i+1,_postfix.Data()));
        cMC->SaveAs(Form("plotFitsComp%s/%s_%s_%s_%d%s.pdf",_prefix.Data(),plotSetting[vartype].text.Data(),"mc",_isPbPb.Data(),i+1,_postfix.Data()));
	}  

    gStyle->SetOptStat(0);
	hPtMC->Sumw2();
	ntMC->Project("hPtMC",varExp.Data(),TCut(weightmc)*(TCut(selmc.Data())&&"(Bgen==23333)"));
	divideBinWidth(hPtMC);

	hPt->Scale(1/hPt->Integral(1,hPt->GetNbinsX()));
	hPtMC->Scale(1/hPtMC->Integral(1,hPt->GetNbinsX()));
    hPt->SetMarkerStyle(21);
    hPt->SetMarkerSize(1.0);
    hPt->SetLineWidth(1);
    hPt->SetLineColor(kBlack);
    hPtMC->SetFillColor(kPink+6);
    hPtMC->SetLineWidth(0);
    hPtMC->SetLineColor(kBlack);

	TCanvas* cPt =  new TCanvas("cPt","",600,600);
	cPt->SetLogy(plotSetting[vartype].setlogY);
	cPt->SetLogx(plotSetting[vartype].setlogX);
    TPad* pad = new TPad("pad","",0.,tpadpos,1.,1.);
	pad->SetLogy(plotSetting[vartype].setlogY);
	pad->SetLogx(plotSetting[vartype].setlogX);
    pad->SetFillColor(0);
    pad->SetBorderMode(0);
    pad->SetBorderSize(2);
    pad->SetLeftMargin(0.1451613);
    pad->SetRightMargin(0.05443548);
    pad->SetTopMargin(0.08474576*tpadr);
    pad->SetBottomMargin(0);
    pad->Draw();
    pad->cd();
	hPt->SetXTitle(Form("%s",varExp.Data()));
	hPt->SetYTitle("Normalized");
    hPtMC->SetXTitle(Form("%s", plotSetting[vartype].text.Data()));
    hPtMC->SetYTitle(Form("Normalized entries/bin width"));
    hPtMC->GetXaxis()->CenterTitle();
    hPtMC->GetYaxis()->CenterTitle();
    hPtMC->GetXaxis()->SetTitleOffset(1.0);
    hPtMC->GetYaxis()->SetTitleOffset(1.0);
    hPtMC->GetXaxis()->SetTitleSize(0.055);
    hPtMC->GetYaxis()->SetTitleSize(0.055);
    hPtMC->GetXaxis()->SetTitleFont(42);
    hPtMC->GetYaxis()->SetTitleFont(42);
    hPtMC->GetXaxis()->SetLabelFont(42);
    hPtMC->GetYaxis()->SetLabelFont(42);
	if(plotSetting[vartype].setlogY) hPtMC->SetMinimum(min(hPtMC->GetMinimum(),hPt->GetMinimum())*0.1);
	hPtMC->Draw("hist");
//	hPtMC->Draw("same pe");
	hPt->Draw("same");
	TLegend* legPt = myLegend(0.75,0.75,0.90,0.90);
	legPt->AddEntry(hPt,"Data","pl");
	legPt->AddEntry(hPtMC,"MC","lf");
	legPt->Draw("same");  

	cPt->cd();
    TPad* pRatio = new TPad("pRatio","",0.,0.,1.,tpadpos);
	TH1D* hRatio = (TH1D*)hPt->Clone("hRatio");
    hRatio->SetXTitle(Form("%s", plotSetting[vartype].text.Data()));
    hRatio->SetYTitle(Form("Data/MC"));
    hRatio->GetXaxis()->CenterTitle();
    hRatio->GetYaxis()->CenterTitle();
    hRatio->GetXaxis()->SetTitleOffset(1.0);
    hRatio->GetYaxis()->SetTitleOffset(0.4);
    hRatio->GetXaxis()->SetTitleSize(0.12);
    hRatio->GetYaxis()->SetTitleSize(0.12);
    hRatio->GetXaxis()->SetLabelSize(0.12);
    hRatio->GetYaxis()->SetLabelSize(0.09);
    hRatio->GetXaxis()->SetTitleFont(42);
    hRatio->GetYaxis()->SetTitleFont(42);
    hRatio->GetXaxis()->SetLabelFont(42);
    hRatio->GetYaxis()->SetLabelFont(42);

    pRatio->SetLeftMargin(0.1451613);
    pRatio->SetRightMargin(0.05443548);
    pRatio->SetTopMargin(0);
    pRatio->SetBottomMargin(0.30);//0.25
	pRatio->Draw();
	pRatio->cd();
	hRatio->Divide(hPtMC);
	if(plotSetting[vartype].dofit){
		TF1* f = new TF1("f","[0]+[1]*x+[2]*x*x");
		//TF1* f = new TF1("f","[0]+[1]*x");
		hRatio->Fit("f","L");
		f->Print();
	}
	hRatio->Draw();
	TLine* line = new TLine(_ptBins[0], 1., _ptBins[_nBins], 1.);
	line->SetLineStyle(9);
	line->SetLineWidth(0);
	line->SetLineColor(4);
	line->Draw();

    cPt->SaveAs(Form("plotFitsComp%s/%s_%s_%s_compare%s.pdf",_prefix.Data(),plotSetting[vartype].text.Data(),_isMC.Data(),_isPbPb.Data(),_postfix.Data()));

	hMean->Write();
	hPt->Write();
	hPtMC->Write();
	outf->Close();
}

int main(int argc, char *argv[])
{
	if(argc==20)
	{
        fitVariables(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], atoi(argv[10]), atof(argv[11]), atoi(argv[12]), argv[13], argv[14], argv[15], atoi(argv[65]), atof(argv[17]), atof(argv[18]), atoi(argv[19]));
		return 0;
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
}
