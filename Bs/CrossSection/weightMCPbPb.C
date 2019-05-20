#include "uti.h"
#include "parameters.h"
#include "TLegendEntry.h"

void weightPbPbvertex(){
    TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root");
    //TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root");
	TTree *ntDkpiMC = (TTree*)fMC->Get("ntphi");
	TTree *ntSkimMC = (TTree*)fMC->Get("ntSkim");
	TTree *ntHiMC = (TTree*)fMC->Get("ntHi");
	TTree *ntHltMC = (TTree*)fMC->Get("ntHlt");
	ntDkpiMC->AddFriend(ntSkimMC);
	ntDkpiMC->AddFriend(ntHiMC);
	ntDkpiMC->AddFriend(ntHltMC);

    TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root");
    //TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged.root");
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

	TCut weighpthat="pthatweight*(0.08*exp(-0.5*((PVz-0.44)/5.12)**2))/(0.08*exp(-0.5*((PVz-3.25)/5.23)**2))";//official weighting factor: https://twiki.cern.ch/twiki/pub/CMS/HiHighPt2017/170426_ZVertexWeightForMC.pdf
	TString cut="abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3";
    TString hlt="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)";

	ntDkpiMC->Project("hpzMC","PVz",TCut(weighpthat)*TCut(cut.Data())*TCut(hlt.Data()));
	//ntDkpiData->Project("hpzData","PVz",(TCut(cut.Data())*TCut(hlt.Data())));
	ntDkpiData->Project("hpzData","PVz+0.516",(TCut(cut.Data())*TCut(hlt.Data())));// data PVz shift

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
    cRatioVtx->SaveAs("plotReweight/PVzWeightPbPb.pdf");

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

void weightPbPbFONLLpthat(int minfit=2,int maxfit=100){
	TString label;
	TString selmcgen="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0";
	TString myweightfunctiongen,myweightfunctionreco;

	TCut weighpthat="pthatweight";
	//TCut weighpthat="pthatweight * (0.675091 + 0.035578*Gpt + -0.000359*Gpt*Gpt)";

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
    TFile*infMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_candWise_BDT7to50.root");
    //TFile*infMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root");
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

    //TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2])",0, 100);
    TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]",0, 100);
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
	leg1->AddEntry(hPtFONLLOverGen,"PbPb #sqrt{s}= 5.02 TeV","");
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
	hPtFONLL->SetYTitle("FONLL_PbPb, #entries");
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
	hPtFONLLOverGen->SetYTitle("FONLL_PbPb/PYTHIA ");
	//hPtFONLLOverGen->SetMinimum(0.1);  
	//hPtFONLLOverGen->SetMaximum(10.);  
	hPtFONLLOverGen->SetMinimum(0.5);  
	hPtFONLLOverGen->SetMaximum(2.);  
	hPtFONLLOverGen->GetYaxis()->SetTitleOffset(1.2);
	hPtFONLLOverGen->GetYaxis()->CenterTitle();
	hPtFONLLOverGen->GetXaxis()->CenterTitle();
	hPtFONLLOverGen->Draw();
	canvasPtReweight->SaveAs("plotReweight/canvasPtReweightPbPb.pdf");
}

void weightPbPbCentrality(){
    TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171120_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171119_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root");
    //TFile*fMC=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight.root");
	TTree *ntDkpiMC = (TTree*)fMC->Get("ntphi");
	TTree *ntSkimMC = (TTree*)fMC->Get("ntSkim");
	TTree *ntHiMC = (TTree*)fMC->Get("ntHi");
	TTree *ntHltMC = (TTree*)fMC->Get("ntHlt");
	ntDkpiMC->AddFriend(ntSkimMC);
	ntDkpiMC->AddFriend(ntHiMC);
	ntDkpiMC->AddFriend(ntHltMC);

    TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT15to50.root");
    //TFile*fData=new TFile("/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged.root");
	TTree *ntDkpiData = (TTree*)fData->Get("ntphi");
	TTree *ntSkimData = (TTree*)fData->Get("ntSkim");
	TTree *ntHiData = (TTree*)fData->Get("ntHi");
	TTree *ntHltData = (TTree*)fData->Get("ntHlt");
	ntDkpiData->AddFriend(ntSkimData);
	ntDkpiData->AddFriend(ntHiData);
	ntDkpiData->AddFriend(ntHltData);

	TH1F*hCenData=new TH1F("hCenData","hCenData",200,0,200);
	hCenData->Sumw2();
	TH1F*hCenMC=new TH1F("hCenMC","hCenMC",200,0,200);
	hCenMC->Sumw2();
	
	TCut weighpthat="pthatweight";
	//TCut weighpthat="pthatweight*(6.625124*exp(-0.093135*pow(abs(hiBin-0.500000),0.884917)))";//cross check
	TString cut="abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3";
	TString hlt="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)";

	ntDkpiMC->Project("hCenMC","hiBin",TCut(weighpthat)*TCut(cut.Data())*TCut(hlt.Data()));
	ntDkpiData->Project("hCenData","hiBin",(TCut(cut.Data())*TCut(hlt.Data())));

	hCenMC->Scale(1./hCenMC->Integral(hCenMC->FindBin(0.),hCenMC->FindBin(200)));
	hCenData->Scale(1./hCenData->Integral(hCenMC->FindBin(0.),hCenMC->FindBin(200)));

	TH2F* hempty1=new TH2F("hempty1","",50,0.,200.,10,0,0.05);  
	hempty1->GetXaxis()->CenterTitle();
	hempty1->GetYaxis()->CenterTitle();
	hempty1->GetYaxis()->SetTitle("Entries");
	hempty1->GetXaxis()->SetTitle("Centrality (HiBin)");
	hempty1->GetXaxis()->SetTitleOffset(0.9);
	hempty1->GetYaxis()->SetTitleOffset(1.3);
	hempty1->GetXaxis()->SetTitleSize(0.05);
	hempty1->GetYaxis()->SetTitleSize(0.05);
	hempty1->GetXaxis()->SetTitleFont(42);
	hempty1->GetYaxis()->SetTitleFont(42);
	hempty1->GetXaxis()->SetLabelFont(42);
	hempty1->GetYaxis()->SetLabelFont(42);
	hempty1->GetXaxis()->SetLabelSize(0.035);
	hempty1->GetYaxis()->SetLabelSize(0.035);  

	TH2F* hempty2=new TH2F("hempty2","",50,0.,200.,10,0,10);  
	hempty2->GetXaxis()->CenterTitle();
	hempty2->GetYaxis()->CenterTitle();
	hempty2->GetYaxis()->SetTitle("Ratio Data/MC");
	hempty2->GetXaxis()->SetTitle("Centrality (HiBin)");
	hempty2->GetXaxis()->SetTitleOffset(0.9);
	hempty2->GetYaxis()->SetTitleOffset(1.3);
	hempty2->GetXaxis()->SetTitleSize(0.05);
	hempty2->GetYaxis()->SetTitleSize(0.05);
	hempty2->GetXaxis()->SetTitleFont(42);
	hempty2->GetYaxis()->SetTitleFont(42);
	hempty2->GetXaxis()->SetLabelFont(42);
	hempty2->GetYaxis()->SetLabelFont(42);
	hempty2->GetXaxis()->SetLabelSize(0.035);
	hempty2->GetYaxis()->SetLabelSize(0.035);  

	TLegend *legendSigma=new TLegend(0.5100806,0.5168644,0.8084677,0.6605932,"");
	legendSigma->SetBorderSize(0);
	legendSigma->SetLineColor(0);
	legendSigma->SetFillColor(0);
	legendSigma->SetFillStyle(1001);
	legendSigma->SetTextFont(42);
	legendSigma->SetTextSize(0.045);

	TLegendEntry *ent_SigmaPP=legendSigma->AddEntry(hCenMC,"Monte Carlo.","pf");
	ent_SigmaPP->SetTextFont(42);
	ent_SigmaPP->SetLineColor(2);
	ent_SigmaPP->SetMarkerColor(2);
	ent_SigmaPP->SetTextSize(0.03);

	TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(hCenData,"Data","f");
	ent_Sigmapp->SetTextFont(42);
	ent_Sigmapp->SetLineColor(1);
	ent_Sigmapp->SetMarkerColor(1);
	ent_Sigmapp->SetTextSize(0.03);

	TCanvas*canvas=new TCanvas("canvas","canvas",1000,500);
	canvas->Divide(2,1);
	canvas->cd(1);
    gPad->SetLeftMargin(0.15);
	hempty1->Draw();
	hCenMC->SetLineColor(2);
	hCenMC->SetMarkerColor(2);
	hCenMC->Draw("same");
	hCenData->Draw("same");
	legendSigma->Draw();
	canvas->cd(2);
	TH1D*hRatio=(TH1D*)hCenData->Clone("hRatio");
	hRatio->Divide(hCenMC);
	hempty2->Draw();
	hRatio->Draw("same");

	TF1 *myfit = new TF1("myfit","[0]*exp([1]*pow(abs(x-[2]),[3]))", 0, 200);  
	myfit->SetParameter(0,10);
	myfit->SetParameter(1,-20);
	myfit->SetParameter(2,0);
	myfit->SetParameter(3,2);
	hRatio->Fit("myfit","m","",0, 200);
	hRatio->Fit("myfit","m","",0, 200);

//	test
//	TF1 *myfit = new TF1("myfit","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x+[5]*x*x*x*x*x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]+[1]*x+[2]*x*x+[3]*x*x*x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]+[1]/x+[2]/x/x+[3]/x/x/x+[4]/x/x/x/x+[5]/x/x/x/x/x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]+[1]/x+[2]/x/x+[3]/x/x/x+[4]/x/x/x/x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]+[1]/x+[2]/x/x+[3]/x/x/x", 0, 200);  
//	hRatio->Fit("myfit","L q m","",0, 200);
//	hRatio->Fit("myfit","L q m","",0, 200);
//	hRatio->Fit("myfit","L m","",0, 200);
//
//	TF1 *myfit = new TF1("myfit","[0]+[1]*x+[2]*x*x+[3]*x*x*x", 0, 200);  
//	TF1 *myfit = new TF1("myfit","([0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x*x)*(x<50)+([0]+[1]*50+[2]*50*50+[3]*50*50*50+[4]*50*50*50*50)/([5]+[6]*50+[7]*50*50+[8]*50*50*50+[9]*50*50*50*50)*([5]+[6]*x+[7]*x*x+[8]*x*x*x+[9]*x*x*x*x)*(x>=50)", 0, 200);  
//	TF1 *myfit = new TF1("myfit","([0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x*x)*(x<50)+([0]+[1]*50+[2]*50*50+[3]*50*50*50+[4]*50*50*50*50)/([5]+[6]/50+[7]/50/50+[8]/50/50/50+[9]/50/50/50/50)*([5]+[6]/x+[7]/x/x+[8]/x/x/x+[9]/x/x/x/x)*(x>=50)", 0, 200);  
//	TF1 *myfit = new TF1("myfit","[0]*exp([1]*x)", 0, 200);  
//	hRatio->Fit("myfit","m","",0, 50);
//	hRatio->Fit("myfit","m","",0, 50);
//	hRatio->Fit("myfit","m","",50, 200);
//	hRatio->Fit("myfit","m","",50, 200);
//	hRatio->Fit("myfit","m","",0, 200);
//	hRatio->Fit("myfit","m","",0, 200);
//	test

	double par0=myfit->GetParameter(0);
	double par1=myfit->GetParameter(1);
	double par2=myfit->GetParameter(2);
	double par3=myfit->GetParameter(3);
	double par4=myfit->GetParameter(4);
	double par5=myfit->GetParameter(5);
    printf("#########################\n");
	printf("(%f*exp(%f*pow(abs(hiBin-%f),%f)))\n",par0, par1, par2, par3);
//	printf("+(%f + %f*hiBin + %f*hiBin*hiBin + %f*hiBin*hiBin*hiBin + %f*hiBin*hiBin*hiBin*hiBin + %f*hiBin*hiBin*hiBin*hiBin*hiBin)\n", par0, par1, par2, par3, par4, par5);
    printf("#########################\n");
    printf("NDF: %d, chi: %f, prob: %f\n", myfit->GetNDF(), myfit->GetChisquare(), myfit->GetProb());
	canvas->SaveAs("plotReweight/CentralityWeight.pdf");
}
void weightMCPbPb(){
//	weightPbPbvertex();
	weightPbPbFONLLpthat(ptBinsReweight[0],ptBinsReweight[nBinsReweight]);
//	weightPbPbCentrality();
}
