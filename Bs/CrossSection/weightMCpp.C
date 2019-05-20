#include "uti.h"
#include "parameters.h"


void weightPPvertex(){
    TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20171119_bPt0jpsiPt0tkPt0p5_Bs_pthatweight_BDT15to50.root");
    //TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root");
	TTree *ntDkpiMC = (TTree*)fMC->Get("ntphi");
	TTree *ntSkimMC = (TTree*)fMC->Get("ntSkim");
	TTree *ntHiMC = (TTree*)fMC->Get("ntHi");
    TTree *ntHltMC = (TTree*)fMC->Get("ntHlt");
	ntDkpiMC->AddFriend(ntSkimMC);
	ntDkpiMC->AddFriend(ntHiMC);
    ntDkpiMC->AddFriend(ntHltMC);

    TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs_BDT15to50.root");
    //TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_AddDummyHLT_HIL1DoubleMu0ForPPRef_v1.root");
	TTree *ntDkpiData = (TTree*)fData->Get("ntphi");
	TTree *ntSkimData = (TTree*)fData->Get("ntSkim");
	TTree *ntHiData = (TTree*)fData->Get("ntHi");
    TTree *ntHltData = (TTree*)fData->Get("ntHlt");
	ntDkpiData->AddFriend(ntSkimData);
	ntDkpiData->AddFriend(ntHiData);
    ntDkpiData->AddFriend(ntHltData);

	TH1F*hpzData=new TH1F("hpzData","hpzData",200,-15,15);
    hpzData->Sumw2();
	TH1F*hpzMC=new TH1F("hpzMC","hpzMC",200,-15,15);
    hpzMC->Sumw2();

    TCut weighpthat="pthatweight";
	TString cut="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter";
    TString hltMC="HLT_HIL1DoubleMu0ForPPRef_v1";
    TString hltData="HLT_HIL1DoubleMu0_v1";

	ntDkpiMC->Project("hpzMC","PVz",TCut(weighpthat)*TCut(cut.Data())*TCut(hltMC.Data()));
	//ntDkpiData->Project("hpzData","PVz",TCut(cut.Data())*TCut(hltData.Data()));
	ntDkpiData->Project("hpzData","PVz+0.516",TCut(cut.Data())*TCut(hltData.Data()));// data PVz shift

	hpzMC->Scale(1./hpzMC->Integral(hpzMC->FindBin(-15.),hpzMC->FindBin(15)));
	hpzData->Scale(1./hpzData->Integral(hpzMC->FindBin(-15.),hpzMC->FindBin(15)));

	TCanvas*cRatioVtx=new TCanvas("cRatioVtx","cRatioVtx",500,500);
	cRatioVtx->Divide(2,1);
	cRatioVtx->cd(1);
	hpzMC->SetLineColor(2);
    hpzMC->SetMarkerColor(2);
	hpzMC->Draw();
	hpzData->Draw("same");
	cRatioVtx->cd(2);
    TH1D*hRatio=(TH1D*)hpzData->Clone("hRatio");
    hRatio->Divide(hpzMC);
    hRatio->Draw();
    cRatioVtx->SaveAs("plotReweight/PVzWeightpp.pdf");

	TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]", -15, 15);  
	hRatio->Fit("myfit","","",-15,15);
	double par0=myfit->GetParameter(0);
	double par1=myfit->GetParameter(1);
	double par2=myfit->GetParameter(2);
	double par3=myfit->GetParameter(3);
	double par4=myfit->GetParameter(4);
	printf("#########################\n");
	printf("(%f + %f*PVz + %f*PVz*PVz + %f*PVz*PVz*PVz + %f*PVz*PVz*PVz*PVz)\n", par0, par1, par2, par3, par4);
	printf("#########################\n");
}

void weightPPFONLLpthat(int minfit=2,int maxfit=100){
	TString label;
	TString selmcgen="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0";
	TString myweightfunctiongen,myweightfunctionreco;

	TCut weighpthat="pthatweight";
	//TCut weighpthat="pthatweight * (0.675236 + 0.035587*Gpt + -0.000358*Gpt*Gpt)";

	gStyle->SetOptTitle(1);
	//gStyle->SetOptStat(111111);
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(0);
	gStyle->SetEndErrorSize(0);
	gStyle->SetMarkerStyle(20);

	gStyle->SetStatX(0.9);
	gStyle->SetStatY(0.9);
	gStyle->SetStatW(0.30);
	gStyle->SetStatH(0.04);
	gStyle->SetStatFontSize(0.03); 
    TFile*infMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_candWise_BDT7to50.root");
    //TFile*infMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root");
	TTree* ntGen = (TTree*)infMC->Get("ntGen");
	TTree *ntHiMC = (TTree*)infMC->Get("ntHi");
	ntGen->AddFriend(ntHiMC);

	TH1D* hPtGen = new TH1D("hPtGen","",nBinsReweight,ptBinsReweight);
	ntGen->Project("hPtGen","Gpt",(TCut(weighpthat)*TCut(selmcgen.Data())));
	divideBinWidth(hPtGen);

	TString fonll="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4_reweightBin.root";
	TFile* filePPReference = new TFile(fonll.Data());  
	TGraphAsymmErrors* gaeBplusReference = (TGraphAsymmErrors*)filePPReference->Get("gaeSigmaBplus");

	TH1D* hPtFONLL = new TH1D("hPtFONLL","",nBinsReweight,ptBinsReweight);
	double x,y;
	for(int i=0;i<nBinsReweight;i++){
		gaeBplusReference->GetPoint(i,x,y);
		hPtFONLL->SetBinContent(i+1,y);
	}

	TH1D* hPtFONLLOverGen=(TH1D*)hPtFONLL->Clone("hPtFONLLOverGen");

	hPtFONLL->Sumw2();
	hPtGen->Sumw2();
	hPtFONLLOverGen->Sumw2();
	hPtFONLL->Scale(1/hPtFONLL->Integral());
	hPtGen->Scale(1/hPtGen->Integral());
	hPtFONLLOverGen->Scale(1/hPtFONLLOverGen->Integral());
	hPtFONLLOverGen->Divide(hPtGen);

	TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]",0, 100);  
	//TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2])",0, 100);  
	//TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2]+x*x*x*[3])",0, 100);  
	//TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4])",0, 100);  
	//TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]+x*x*x*x*x*[5])",0, 100);  

	TCanvas*c1=new TCanvas("c1","c1",1000.,600.);
	c1->cd();
	gPad->SetLogy();
	gStyle->SetOptStat(111111111);
	hPtFONLLOverGen->Fit("myfit","m q","",minfit,maxfit);
	hPtFONLLOverGen->Fit("myfit","L m","",minfit,maxfit);
    printf("NDF: %d, chi: %f, prob: %f\n", myfit->GetNDF(), myfit->GetChisquare(), myfit->GetProb());
	TLegend* leg0 = myLegend(0.13,0.83,0.40,0.89);
	leg0->AddEntry(hPtFONLLOverGen,"Pythia8 MC_2015 B_{s}","");
	leg0->Draw();
	TLegend* leg1 = myLegend(0.15,0.75,0.40,0.88);
	leg1->AddEntry(hPtFONLLOverGen,"pp #sqrt{s}= 5.02 TeV","");
	leg1->Draw();

	double par0=myfit->GetParameter(0);
	double par1=myfit->GetParameter(1);
	double par2=myfit->GetParameter(2);
	double par3=myfit->GetParameter(3);
	double par4=myfit->GetParameter(4);
	double par5=myfit->GetParameter(5);
	//double par6=myfit->GetParameter(6);

	printf("#########################\n");
	printf("(%f + %f*Gpt + %f*Gpt*Gpt)\n", par0, par1, par2);
	printf("(%f + %f*Bgenpt + %f*Bgenpt*Bgenpt)\n", par0, par1, par2);
	//printf("(pow(10, %f + %f*Gpt + %f*Gpt*Gpt + %f*Gpt*Gpt*Gpt))\n", par0, par1, par2, par3);
	//printf("(pow(10, %f + %f*Bgenpt + %f*Bgenpt*Bgenpt + %f*Bgenpt*Bgenpt*Bgenpt))\n", par0, par1, par2, par3);
	printf("#########################\n");

	TCanvas*canvasPtReweight=new TCanvas("canvasPtReweight","canvasPtReweight_PbPb_MC_Bs",1253.,494.); 
	canvasPtReweight->Divide(3,1);
	canvasPtReweight->cd(1);
	gPad->SetLogy();
	gPad->SetLeftMargin(0.20);
	hPtGen->SetXTitle("Gen p_{T}(GeV)");
	hPtGen->SetYTitle("PYTHIA, #entries");
	hPtGen->SetMinimum(1e-6);  
	hPtGen->SetMaximum(1e1);  
	hPtGen->GetYaxis()->SetTitleOffset(1.3);
	hPtGen->Draw();
	canvasPtReweight->cd(2);
	gPad->SetLogy();
	gPad->SetLeftMargin(0.15);
	hPtFONLL->SetXTitle("FONLL p_{T}(GeV)");
	hPtFONLL->SetYTitle("FONLL_pp, #entries");
	hPtFONLL->SetMinimum(1e-6);  
	hPtFONLL->SetMaximum(1e1);  
	hPtFONLL->GetYaxis()->SetTitleOffset(1.3);
	hPtFONLL->GetYaxis()->CenterTitle();
	hPtFONLL->GetXaxis()->CenterTitle();
	hPtFONLL->Draw();
	canvasPtReweight->cd(3);
	//gPad->SetLogy();
	gPad->SetLeftMargin(0.15);
	hPtFONLLOverGen->SetXTitle("Gen p_{T}(GeV)");
	hPtFONLLOverGen->SetYTitle("FONLL_pp/PYTHIA ");
	//hPtFONLLOverGen->SetMinimum(0.1);  
	//hPtFONLLOverGen->SetMaximum(10.);  
	hPtFONLLOverGen->SetMinimum(0.5);  
	hPtFONLLOverGen->SetMaximum(2.);  
	hPtFONLLOverGen->GetYaxis()->SetTitleOffset(1.2);
	hPtFONLLOverGen->GetYaxis()->CenterTitle();
	hPtFONLLOverGen->GetXaxis()->CenterTitle();
	hPtFONLLOverGen->Draw();
	canvasPtReweight->SaveAs("plotReweight/canvasPtReweightPP.pdf");
}

void weightMCpp(){
//	weightPPvertex();
	weightPPFONLLpthat(ptBinsReweight[0],ptBinsReweight[nBinsReweight]);
}

