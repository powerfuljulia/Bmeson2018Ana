#include "fitB.h"

int _nBins = nBins;
double *_ptBins = ptBins;
void fitB(int usePbPb = 0, int fitOnSaved = 0, TString inputdata = "", TString inputmc = "", TString _varExp = "", TString trgselection = "",  TString cut = "", TString cutmcgen = "", int isMC = 0, Double_t luminosity = 1., int doweight = 0, TString collsyst = "", TString outputfile = "", TString outplotf = "", TString npfit = "", int doDataCor = 0, Float_t centmin = 0., Float_t centmax = 100.)
{
	collisionsystem=collsyst;
	TString varExp = _varExp;
	if(_varExp == "Bpt750"){
		_nBins = nBins750;
		_ptBins = ptBins750;
		varExp = "Bpt";
	}
	if(_varExp == "Bpt750_acc"){
		_nBins = nBins750_acc;
		_ptBins = ptBins750_acc;
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
	TH1D* hMCSignal;
	TH1D* hpull;

	TTree* nt;
	TTree* ntMC;
	TTree* ntGen;

	cout << "Pass 1" << endl;
	if(fitOnSaved == 0){
		nt = (TTree*)inf->Get("Bfinder/ntphi");
		nt->AddFriend("hltanalysis/HltTree");
		nt->AddFriend("hiEvtAnalyzer/HiTree");
		nt->AddFriend("skimanalysis/HltTree");
		nt->AddFriend("BDT_pt_15_20");
		nt->AddFriend("BDT_pt_7_15");
		nt->AddFriend("BDT_pt_5_7");
		nt->AddFriend("BDT_pt_20_50");	
	
		/*
		   ntGen = (TTree*)infMC->Get("ntGen");
		   ntGen->AddFriend("ntHlt");
		   ntGen->AddFriend("ntHi");

		   cout << "Pass 2" << endl;

		   ntMC = (TTree*)infMC->Get("ntphi");


		   ntMC->AddFriend("ntHlt");
		   ntMC->AddFriend("ntHi");
		   ntMC->AddFriend("ntSkim");
		   ntMC->AddFriend("mvaTree");
		   ntMC->AddFriend("ntGen");
		   */
		ntGen = (TTree*)infMC->Get("Bfinder/ntGen");
		ntGen->AddFriend("hltanalysis/HltTree");
		ntGen->AddFriend("hiEvtAnalyzer/HiTree");


		ntMC = (TTree*)infMC->Get("Bfinder/ntphi");
		ntMC->AddFriend("hltanalysis/HltTree");
		ntMC->AddFriend("hiEvtAnalyzer/HiTree");
		ntMC->AddFriend("skimanalysis/HltTree");
		ntMC->AddFriend("BDT_pt_15_20");
		ntMC->AddFriend("BDT_pt_7_15");
		ntMC->AddFriend("BDT_pt_5_7");
		ntMC->AddFriend("BDT_pt_20_50");	

		ntMC->AddFriend("Bfinder/ntGen");
	}

	cout << "Pass 3" << endl;

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

	weightgen = weightgen_pp;
	weightmc  = weightmc_pp;
	if(usePbPb){
		weightgen = weightgen_PbPb;
		//weightmc = weightmc_PbPb;
		weightmc = "pthatweight";
	}

	TString _prefix = "";
	TString _isMC = "data";
	if(isMC) _isMC = "mcAsData";
	TString _isPbPb = "pp";
	if(usePbPb) _isPbPb = "PbPb";
	TString _postfix = "";
	if(weightdata!="1") _postfix = "_EFFCOR";
	/*
	   const int NCentBin = 2;
	   int CentMinBin[NCentBin] ={0,60};
	   int CentMaxBin[NCentBin] ={60,200};
	   */
	const int NCentBin = 1;
	int CentMinBin[NCentBin] ={0};
	int CentMaxBin[NCentBin] ={201};

	cout << "Pass 4" << endl;

	int doPhi = 1;
	int doStat = 1;
	for(int i=0;i<_nBins;i++)
	{
		_count++;
		for(int j = 0; j < NCentBin; j++){		
			TCanvas* c= new TCanvas(Form("c%d",_count),"",600,600);
			TCanvas* cMC= new TCanvas(Form("cMC%d",_count),"",600,600);
			if(fitOnSaved == 0){
				drawOpt = 1;
				h = new TH1D(Form("h%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
				hMCSignal = new TH1D(Form("hMCSignal%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
				cout << "Pass 4.5" << endl;
				if(isMC==1) ntMC->Project(Form("h%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));

				else        nt->Project(Form("h%d",_count),"Bmass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
				cout << "Pass 4.7" << endl;
				//	ntMC->Project(Form("hMCSignal%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)",weightmc.Data(),Form("%s&&Bgen==23333",selmc.Data()),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1]));
				if(doStat == 1){
				TH1D * hMCSignalStat = new TH1D(Form("hMCSignalStat%d",_count),"",nbinsmasshisto,minhisto,maxhisto);
					ntMC->Project(Form("hMCSignalStat%d",_count),"Bmass",Form("%s*((Btrk1Pt > 1 && Btrk2Pt > 1 && Bchi2cl > 0.05 && BsvpvDistance/BsvpvDisErr > 2 && Bpt > 5 && abs(Btrk1Eta-0.0) < 2.4  && abs(Btrk2Eta-0.0) < 2.4)&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)",weightmc.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
				cout << "pt = " << _ptBins[i] << "    Statistics = " << 	hMCSignalStat->Integral() << endl;
				}
				ntMC->Project(Form("hMCSignal%d",_count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)",weightmc.Data(),seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));

				

				cout << "Pass 4.8" << endl;
				h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
		
				if(doPhi == 1){
					/*
					   TCanvas *cPhi = new TCanvas("cPhi","cPhi",600,600);
					   cPhi->cd();

					   TH1D * hPhi1 = new TH1D(Form("hPhi1%d",_count),"",60,0.30,0.60);
					   TH1D * hPhi2 = new TH1D(Form("hPhi2%d",_count),"",60,0.70,1.00);
					   TH1D * hPhi3 = new TH1D(Form("hPhi3%d",_count),"",60,0.70,1.00);
					   TH1D * hBPhi1 = new TH1D(Form("hBPhi1%d",_count),"",nbinsmasshisto,4.5,5.5);
					   TH1D * hBPhi2 = new TH1D(Form("hBPhi2%d",_count),"",nbinsmasshisto,4.5,5.5);
					   TH1D * hBPhi3 = new TH1D(Form("hBPhi3%d",_count),"",nbinsmasshisto,4.5,5.5);

					   nt->AddFriend("Recalculated");
					   nt->Project(Form("hPhi1%d",_count),"PiPiMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
					   nt->Project(Form("hPhi2%d",_count),"PiKMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
					   nt->Project(Form("hPhi3%d",_count),"KPiMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));

					   nt->Project(Form("hBPhi1%d",_count),"PiPiBMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
					   nt->Project(Form("hBPhi2%d",_count),"PiKBMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));
					   nt->Project(Form("hBPhi3%d",_count),"KPiBMass",   Form("(%s&&%s>%f&&%s<%f && hiBin < %d && hiBin > %d)*(1/%s)", seldata.Data(),varExp.Data(),_ptBins[i],varExp.Data(),_ptBins[i+1],CentMaxBin[j],CentMinBin[j],weightdata.Data()));


					   hPhi1->SetAxisRange(0,hPhi1->GetMaximum()*1.4*2.0,"Y");
					   hPhi1->GetXaxis()->SetTitle("PiPi Mass (GeV)");
					   hPhi1->GetYaxis()->SetTitle("Counts");
					   hPhi1->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/Phi_PiPi_%d_%d.pdf",i,j));

					   hPhi2->SetAxisRange(0,hPhi2->GetMaximum()*1.4*2.0,"Y");
					   hPhi2->GetXaxis()->SetTitle("PiK Mass (GeV)");
					   hPhi2->GetYaxis()->SetTitle("Counts");
					   hPhi2->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/Phi_PiK_%d_%d.pdf",i,j));

					   hPhi3->SetAxisRange(0,hPhi3->GetMaximum()*1.4*2.0,"Y");
					   hPhi3->GetXaxis()->SetTitle("KPi Mass (GeV)");
					   hPhi3->GetYaxis()->SetTitle("Counts");
					   hPhi3->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/Phi_KPi_%d_%d.pdf",i,j));

					   hBPhi1->SetAxisRange(0,hBPhi1->GetMaximum()*1.4*2.0,"Y");
					   hBPhi1->GetXaxis()->SetTitle("PiPi J/Psi Mass (GeV)");
					   hBPhi1->GetYaxis()->SetTitle("Counts");
					   hBPhi1->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/BMass_PiPi_%d_%d.pdf",i,j));

					   hBPhi2->SetAxisRange(0,hBPhi2->GetMaximum()*1.4*2.0,"Y");
					   hBPhi2->GetXaxis()->SetTitle("PiK J/Psi Mass (GeV)");
					   hBPhi2->GetYaxis()->SetTitle("Counts");
					   hBPhi2->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/BMass_PiK_%d_%d.pdf",i,j));

					   hBPhi3->SetAxisRange(0,hBPhi3->GetMaximum()*1.4*2.0,"Y");
					   hBPhi3->GetXaxis()->SetTitle("KPi J/Psi Mass (GeV)");
					   hBPhi3->GetYaxis()->SetTitle("Counts");
					   hBPhi3->Draw("ep");
					   cPhi->SaveAs(Form("plotPhi/BMass_KPi_%d_%d.pdf",i,j));
					   */
					gStyle->SetOptFit(0);
					gStyle->SetOptStat(0);
					TH1D * hBSizeData = new TH1D("hBSizeData","hBSizeData",100,0,6000);
					TH1D * hBSizeMC = new TH1D("hBSizeMC","hBSizeMC",100,0,6000);


					nt->Project("hBSizeData","Bsize",   Form("(%s)*(1/%s)", seldata.Data(),weightdata.Data()));
					ntMC->Project("hBSizeMC", "Bsize",   Form("%s*(%s)*(1/%s)",weightmc.Data(),seldata.Data(),weightdata.Data()));
					hBSizeMC->SetLineColor(kRed);
					hBSizeMC->SetLineWidth(2);
					hBSizeData->SetLineColor(kBlue);
					hBSizeData->SetLineWidth(2);
					hBSizeMC->SetTitle("BSize Distribution for Data vs MC");
					hBSizeMC->GetXaxis()->SetTitle("BSize");
					hBSizeMC->GetYaxis()->SetTitle("Normalized Counts");
					TCanvas * cBSize = new TCanvas("cBSize","cBSize",600,600);
					cBSize->cd();
					cBSize->SetLogy();
					hBSizeMC->Scale(1.0/hBSizeMC->Integral());
					hBSizeMC->Draw();
					hBSizeData->Scale(1.0/hBSizeData->Integral());
					hBSizeData->Draw("SAME");
					TLegend* legBSize = myLegend(0.55,0.60,0.90,0.74);
					legBSize->AddEntry(hBSizeMC,"MC","l");
					legBSize->AddEntry(hBSizeData,"Data","l");
					legBSize->Draw("same");  
					cBSize->SaveAs("Data-MCBSize.png");
				}

			}
			if(fitOnSaved == 1){
				drawOpt = 1;
				h = (TH1D*)inf->Get(Form("h%d",_count));
				hMCSignal = (TH1D*)inf->Get(Form("hMCSignal%d",_count));
			}
			h->SetBinErrorOption(TH1::kPoisson);
			//TF1* f = fit(c, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, centmin, centmax, npfit);
			TF1* f = fit(c, cMC, h, hMCSignal, _ptBins[i], _ptBins[i+1], isMC, isPbPb, total, CentMinBin[j], CentMaxBin[j], npfit);

			cout << "Pass 5" << endl;

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
			cout << "Pass 6" << endl;

			hPt->SetBinContent(i+1,yield/(_ptBins[i+1]-_ptBins[i]));
			hPt->SetBinError(i+1,yieldErr/(_ptBins[i+1]-_ptBins[i]));
			hMean->SetBinContent(i+1,f->GetParameter(1));
			hMean->SetBinError(i+1,f->GetParError(1));  

			TLatex* tex;
			tex = new TLatex(0.35,0.85,Form("%.0f < p_{T} < %.0f GeV/c, %d < Cent < %d ",_ptBins[i],_ptBins[i+1],CentMinBin[j]/2,CentMaxBin[j]/2));
			if(varExp=="abs(By)") tex = new TLatex(0.55,0.85,Form("%.1f < y < %.1f",_ptBins[i],_ptBins[i+1]));
			tex->SetNDC();
			tex->SetTextFont(42);
			tex->SetTextSize(0.045);
			tex->SetLineWidth(2);
			tex->Draw();

			tex = new TLatex(0.75,0.80,"|y| < 2.4");
			if(varExp=="abs(By)") tex = new TLatex(0.75,0.80,"7 < p_{T} < 50 GeV.c");
			tex->SetNDC();
			tex->SetTextFont(42);
			tex->SetTextSize(0.045);
			tex->SetLineWidth(2);
			tex->Draw();

			c->SaveAs(Form("%s%s/%s_%s_%d_%d%s.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,j,_postfix.Data()));
			c->SaveAs(Form("%s%s/%s_%s_%d_%d%s.png",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,j,_postfix.Data()));
			c->SaveAs(Form("%s%s/%s_%s_%d_%d%s.C",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,j,_postfix.Data()));
			cMC->SaveAs(Form("%s%s/%s_%s_%d_%d%s.pdf",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,j,_postfix.Data()));
			cMC->SaveAs(Form("%s%s/%s_%s_%d_%d%s.png",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,j,_postfix.Data()));
			cMC->SaveAs(Form("%s%s/%s_%s_%d_%d%s.C",outplotf.Data(),_prefix.Data(),"mc",_isPbPb.Data(),_count,j,_postfix.Data()));
			cout << "Pass 7" << endl;

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
			cpull->SaveAs(Form("%s%s/%s_%s_%d_%d%s_pull.pdf",outplotf.Data(),_prefix.Data(),_isMC.Data(),_isPbPb.Data(),_count,j,_postfix.Data()));
		}
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
		//fitB(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], atoi(argv[10]), atof(argv[11]), atoi(argv[12]), argv[13], argv[14], argv[15], argv[16], atoi(argv[17]), atof(argv[18]), atof(argv[19]));
		fitB(atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], atoi(argv[9]), atof(argv[10]), atoi(argv[11]), argv[12], argv[13], argv[14], argv[15], atoi(argv[16]), atof(argv[17]), atof(argv[18]));

	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
	return 0;
}
