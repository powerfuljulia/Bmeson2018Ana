void canvasSigmaBplusRatiopp()
{
//=========Macro generated from canvas: cSigma/
//=========  (Thu Sep 27 11:46:45 2018) by ROOT version6.02/13
   TCanvas *cSigma = new TCanvas("cSigma", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cSigma->SetHighLightColor(2);
   cSigma->Range(-1.989924,-0.2917772,25.49622,2.212202);
   cSigma->SetFillColor(0);
   cSigma->SetBorderMode(0);
   cSigma->SetBorderSize(2);
   cSigma->SetLogy();
   cSigma->SetLeftMargin(0.18);
   cSigma->SetRightMargin(0.043);
   cSigma->SetBottomMargin(0.145);
   cSigma->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pSigma
   TPad *pSigma = new TPad("pSigma", "",0,0.3,1,1);
   pSigma->Draw();
   pSigma->cd();
   pSigma->Range(-10.27799,3,57.93308,7.666667);
   pSigma->SetFillColor(0);
   pSigma->SetBorderMode(0);
   pSigma->SetBorderSize(2);
   pSigma->SetLogy();
   pSigma->SetLeftMargin(0.18);
   pSigma->SetRightMargin(0.043);
   pSigma->SetTopMargin(0.1428571);
   pSigma->SetBottomMargin(0);
   pSigma->SetFrameBorderMode(0);
   pSigma->SetFrameBorderMode(0);
   
   TH2F *hemptySigma1 = new TH2F("hemptySigma1","",50,2,55,10,1000,1e+07);
   hemptySigma1->SetMinimum(0);
   hemptySigma1->SetMaximum(2);
   hemptySigma1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptySigma1->SetLineColor(ci);
   hemptySigma1->SetMarkerStyle(20);
   hemptySigma1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptySigma1->GetXaxis()->CenterTitle(true);
   hemptySigma1->GetXaxis()->SetLabelFont(42);
   hemptySigma1->GetXaxis()->SetLabelSize(0.06857143);
   hemptySigma1->GetXaxis()->SetTitleSize(0.07857143);
   hemptySigma1->GetXaxis()->SetTitleFont(42);
   hemptySigma1->GetYaxis()->SetTitle("#frac{d#sigma_{pp}}{dp_{T}} ( pb GeV^{-1}c)");
   hemptySigma1->GetYaxis()->CenterTitle(true);
   hemptySigma1->GetYaxis()->SetLabelFont(42);
   hemptySigma1->GetYaxis()->SetLabelSize(0.06857143);
   hemptySigma1->GetYaxis()->SetTitleSize(0.07142857);
   hemptySigma1->GetYaxis()->SetTitleOffset(1.015);
   hemptySigma1->GetYaxis()->SetTitleFont(42);
   hemptySigma1->GetZaxis()->SetLabelFont(42);
   hemptySigma1->GetZaxis()->SetLabelSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleFont(42);
   hemptySigma1->Draw("");
   
   Double_t gaeSigmaBplus_fx3001[3] = {
   11,
   17.5,
   35};
   Double_t gaeSigmaBplus_fy3001[3] = {
   305288.6,
   46248.03,
   4541.038};
   Double_t gaeSigmaBplus_felx3001[3] = {
   4,
   2.5,
   15};
   Double_t gaeSigmaBplus_fely3001[3] = {
   73145.42,
   9567.207,
   805.5888};
   Double_t gaeSigmaBplus_fehx3001[3] = {
   4,
   2.5,
   15};
   Double_t gaeSigmaBplus_fehy3001[3] = {
   117173.9,
   14056.72,
   1092.571};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3,gaeSigmaBplus_fx3001,gaeSigmaBplus_fy3001,gaeSigmaBplus_felx3001,gaeSigmaBplus_fehx3001,gaeSigmaBplus_fely3001,gaeSigmaBplus_fehy3001);
   grae->SetName("gaeSigmaBplus");
   grae->SetTitle(";p_{T}(GeV/c);d#sigma/dp_{T} (B_{s}) (pb GeV-1c)");

   ci = TColor::GetColor("#ffcc00");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(3);
   
   TH1F *Graph_gaeSigmaBplus3001 = new TH1F("Graph_gaeSigmaBplus3001","",100,2.7,54.3);
   Graph_gaeSigmaBplus3001->SetMinimum(3361.904);
   Graph_gaeSigmaBplus3001->SetMaximum(464335.2);
   Graph_gaeSigmaBplus3001->SetDirectory(0);
   Graph_gaeSigmaBplus3001->SetStats(0);
   Graph_gaeSigmaBplus3001->GetXaxis()->SetTitle("p_{T}(GeV/c)");
   Graph_gaeSigmaBplus3001->GetYaxis()->SetTitle("d#sigma/dp_{T} (B_{s}) (pb GeV-1c)");
   grae->SetHistogram(Graph_gaeSigmaBplus3001);
   
   grae->Draw("5");
   Double_t xAxis1[4] = {7, 15, 20, 50}; 
   
   TH1D *hPtSigma2 = new TH1D("hPtSigma2","",3, xAxis1);
   hPtSigma2->SetBinContent(1,316468.6);
   hPtSigma2->SetBinContent(2,34128.12);
   hPtSigma2->SetBinContent(3,3833.178);
   hPtSigma2->SetBinError(1,36647.64);
   hPtSigma2->SetBinError(2,6250.474);
   hPtSigma2->SetBinError(3,667.9997);
   hPtSigma2->SetEntries(90.86056);
   hPtSigma2->SetLineStyle(0);
   hPtSigma2->SetLineWidth(2);
   hPtSigma2->SetMarkerStyle(20);
   hPtSigma2->SetMarkerSize(1.2);
   hPtSigma2->GetXaxis()->SetLabelFont(42);
   hPtSigma2->GetXaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetXaxis()->SetLabelSize(0.05);
   hPtSigma2->GetXaxis()->SetTitleSize(0.06);
   hPtSigma2->GetXaxis()->SetTitleOffset(0.9);
   hPtSigma2->GetXaxis()->SetTitleFont(42);
   hPtSigma2->GetYaxis()->SetLabelFont(42);
   hPtSigma2->GetYaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetYaxis()->SetLabelSize(0.05);
   hPtSigma2->GetYaxis()->SetTitleSize(0.06);
   hPtSigma2->GetYaxis()->SetTitleOffset(1.05);
   hPtSigma2->GetYaxis()->SetTitleFont(42);
   hPtSigma2->GetZaxis()->SetLabelFont(42);
   hPtSigma2->GetZaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetZaxis()->SetLabelSize(0.05);
   hPtSigma2->GetZaxis()->SetTitleSize(0.06);
   hPtSigma2->GetZaxis()->SetTitleFont(42);
   hPtSigma2->Draw("epsame");
   
   Double_t gaeCrossSyst_fx3002[3] = {
   11,
   17.5,
   35};
   Double_t gaeCrossSyst_fy3002[3] = {
   316468.6,
   34128.12,
   3833.178};
   Double_t gaeCrossSyst_felx3002[3] = {
   4,
   2.5,
   15};
   Double_t gaeCrossSyst_fely3002[3] = {
   61706.28,
   3192.588,
   356.7152};
   Double_t gaeCrossSyst_fehx3002[3] = {
   4,
   2.5,
   15};
   Double_t gaeCrossSyst_fehy3002[3] = {
   61706.28,
   3192.588,
   356.7152};
   grae = new TGraphAsymmErrors(3,gaeCrossSyst_fx3002,gaeCrossSyst_fy3002,gaeCrossSyst_felx3002,gaeCrossSyst_fehx3002,gaeCrossSyst_fely3002,gaeCrossSyst_fehy3002);
   grae->SetName("gaeCrossSyst");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.142857);
   
   TH1F *Graph_gaeCrossSyst3002 = new TH1F("Graph_gaeCrossSyst3002","Graph",100,2.7,54.3);
   Graph_gaeCrossSyst3002->SetMinimum(3128.816);
   Graph_gaeCrossSyst3002->SetMaximum(415644.7);
   Graph_gaeCrossSyst3002->SetDirectory(0);
   Graph_gaeCrossSyst3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gaeCrossSyst3002->SetLineColor(ci);
   Graph_gaeCrossSyst3002->SetMarkerStyle(20);
   Graph_gaeCrossSyst3002->GetXaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3002->GetXaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3002->GetXaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3002->GetXaxis()->SetTitleFont(42);
   Graph_gaeCrossSyst3002->GetYaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3002->GetYaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3002->GetYaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3002->GetYaxis()->SetTitleFont(42);
   Graph_gaeCrossSyst3002->GetZaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3002->GetZaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3002->GetZaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gaeCrossSyst3002);
   
   grae->Draw("5");
   TLatex *   tex = new TLatex(0.21,0.8285714,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.08571429);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.95,0.9142857,"28.0 pb^{-1} (pp 5.02 TeV)");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetTextSize(0.07857143);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.21,0.6857143,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07142857);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.85,0.7428571,"B^{0}_{s}");
tex->SetNDC();
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.52,0.5,0.89,0.8285714,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.07857143);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("hPtSigma","Data","pf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("gaeSigmaBplus","FONLL","f");

   ci = TColor::GetColor("#ffcc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
      tex = new TLatex(0.53,0.42,"Global uncertainty");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07142857);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.3428571,"#pm7.9%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.07142857);
   tex->SetLineWidth(2);
   tex->Draw();
   pSigma->Modified();
   cSigma->cd();
  
// ------------>Primitives in pad: pRatio
   TPad *pRatio = new TPad("pRatio", "",0,0,1,0.3);
   pRatio->Draw();
   pRatio->cd();
   pRatio->Range(-10.27799,-1.296774,57.93308,1.8);
   pRatio->SetFillColor(0);
   pRatio->SetBorderMode(0);
   pRatio->SetBorderSize(2);
   pRatio->SetLeftMargin(0.18);
   pRatio->SetRightMargin(0.043);
   pRatio->SetTopMargin(0);
   pRatio->SetBottomMargin(0.4833333);
   pRatio->SetFrameBorderMode(0);
   pRatio->SetFrameBorderMode(0);
   
   TH2F *hemptyRatio3 = new TH2F("hemptyRatio3","",50,2,55,10,0.2,1.8);
   hemptyRatio3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyRatio3->SetLineColor(ci);
   hemptyRatio3->SetMarkerStyle(20);
   hemptyRatio3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyRatio3->GetXaxis()->CenterTitle(true);
   hemptyRatio3->GetXaxis()->SetLabelFont(42);
   hemptyRatio3->GetXaxis()->SetLabelSize(0.16);
   hemptyRatio3->GetXaxis()->SetTitleSize(0.1833333);
   hemptyRatio3->GetXaxis()->SetTickLength(0.09999999);
   hemptyRatio3->GetXaxis()->SetTitleFont(42);
   hemptyRatio3->GetYaxis()->SetTitle("#frac{Data}{FONLL}");
   hemptyRatio3->GetYaxis()->SetNdivisions(505);
   hemptyRatio3->GetYaxis()->SetLabelFont(42);
   hemptyRatio3->GetYaxis()->SetLabelSize(0.16);
   hemptyRatio3->GetYaxis()->SetTitleSize(0.1833333);
   hemptyRatio3->GetYaxis()->SetTitleOffset(0.42);
   hemptyRatio3->GetYaxis()->SetTitleFont(42);
   hemptyRatio3->GetZaxis()->SetLabelFont(42);
   hemptyRatio3->GetZaxis()->SetLabelSize(0.035);
   hemptyRatio3->GetZaxis()->SetTitleSize(0.035);
   hemptyRatio3->GetZaxis()->SetTitleFont(42);
   hemptyRatio3->Draw("");
   TLine *line = new TLine(2,1,55,1);
   line->SetLineStyle(2);
   line->Draw();
   
   Double_t gaeRatioCrossFONLLunity_fx3003[3] = {
   11,
   17.5,
   35};
   Double_t gaeRatioCrossFONLLunity_fy3003[3] = {
   1,
   1,
   1};
   Double_t gaeRatioCrossFONLLunity_felx3003[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLunity_fely3003[3] = {
   0.2395944,
   0.2068673,
   0.1774019};
   Double_t gaeRatioCrossFONLLunity_fehx3003[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLunity_fehy3003[3] = {
   0.3838137,
   0.303942,
   0.2405995};
   grae = new TGraphAsymmErrors(3,gaeRatioCrossFONLLunity_fx3003,gaeRatioCrossFONLLunity_fy3003,gaeRatioCrossFONLLunity_felx3003,gaeRatioCrossFONLLunity_fehx3003,gaeRatioCrossFONLLunity_fely3003,gaeRatioCrossFONLLunity_fehy3003);
   grae->SetName("gaeRatioCrossFONLLunity");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#ffcc00");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_gaeRatioCrossFONLLunity3003 = new TH1F("Graph_gaeRatioCrossFONLLunity3003","Graph",100,2.7,54.3);
   Graph_gaeRatioCrossFONLLunity3003->SetMinimum(0.6980648);
   Graph_gaeRatioCrossFONLLunity3003->SetMaximum(1.446154);
   Graph_gaeRatioCrossFONLLunity3003->SetDirectory(0);
   Graph_gaeRatioCrossFONLLunity3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gaeRatioCrossFONLLunity3003->SetLineColor(ci);
   Graph_gaeRatioCrossFONLLunity3003->SetMarkerStyle(20);
   Graph_gaeRatioCrossFONLLunity3003->GetXaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLunity3003->GetXaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetXaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetXaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLunity3003->GetYaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLunity3003->GetYaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetYaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetYaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLunity3003->GetZaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLunity3003->GetZaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetZaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLunity3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gaeRatioCrossFONLLunity3003);
   
   grae->Draw("5");
   
   Double_t gaeRatioCrossFONLLstat_fx3004[3] = {
   11,
   17.5,
   35};
   Double_t gaeRatioCrossFONLLstat_fy3004[3] = {
   1.036621,
   0.7379368,
   0.8441193};
   Double_t gaeRatioCrossFONLLstat_felx3004[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLstat_fely3004[3] = {
   0.1200426,
   0.1351511,
   0.1471029};
   Double_t gaeRatioCrossFONLLstat_fehx3004[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLstat_fehy3004[3] = {
   0.1200426,
   0.1351511,
   0.1471029};
   grae = new TGraphAsymmErrors(3,gaeRatioCrossFONLLstat_fx3004,gaeRatioCrossFONLLstat_fy3004,gaeRatioCrossFONLLstat_felx3004,gaeRatioCrossFONLLstat_fehx3004,gaeRatioCrossFONLLstat_fely3004,gaeRatioCrossFONLLstat_fehy3004);
   grae->SetName("gaeRatioCrossFONLLstat");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.142857);
   
   TH1F *Graph_gaeRatioCrossFONLLstat3004 = new TH1F("Graph_gaeRatioCrossFONLLstat3004","Graph",100,2.7,54.3);
   Graph_gaeRatioCrossFONLLstat3004->SetMinimum(0.5473979);
   Graph_gaeRatioCrossFONLLstat3004->SetMaximum(1.212052);
   Graph_gaeRatioCrossFONLLstat3004->SetDirectory(0);
   Graph_gaeRatioCrossFONLLstat3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gaeRatioCrossFONLLstat3004->SetLineColor(ci);
   Graph_gaeRatioCrossFONLLstat3004->SetMarkerStyle(20);
   Graph_gaeRatioCrossFONLLstat3004->GetXaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLstat3004->GetXaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetXaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetXaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLstat3004->GetYaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLstat3004->GetYaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetYaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetYaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLstat3004->GetZaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLstat3004->GetZaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetZaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLstat3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gaeRatioCrossFONLLstat3004);
   
   grae->Draw("ep");
   
   Double_t gaeRatioCrossFONLLsyst_fx3005[3] = {
   11,
   17.5,
   35};
   Double_t gaeRatioCrossFONLLsyst_fy3005[3] = {
   1.036621,
   0.7379368,
   0.8441193};
   Double_t gaeRatioCrossFONLLsyst_felx3005[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLsyst_fely3005[3] = {
   0.2021244,
   0.06903187,
   0.07855367};
   Double_t gaeRatioCrossFONLLsyst_fehx3005[3] = {
   4,
   2.5,
   15};
   Double_t gaeRatioCrossFONLLsyst_fehy3005[3] = {
   0.2021244,
   0.06903187,
   0.07855367};
   grae = new TGraphAsymmErrors(3,gaeRatioCrossFONLLsyst_fx3005,gaeRatioCrossFONLLsyst_fy3005,gaeRatioCrossFONLLsyst_felx3005,gaeRatioCrossFONLLsyst_fehx3005,gaeRatioCrossFONLLsyst_fely3005,gaeRatioCrossFONLLsyst_fehy3005);
   grae->SetName("gaeRatioCrossFONLLsyst");
   grae->SetTitle("Graph");
   grae->SetFillColor(5);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_gaeRatioCrossFONLLsyst3005 = new TH1F("Graph_gaeRatioCrossFONLLsyst3005","Graph",100,2.7,54.3);
   Graph_gaeRatioCrossFONLLsyst3005->SetMinimum(0.6119209);
   Graph_gaeRatioCrossFONLLsyst3005->SetMaximum(1.29573);
   Graph_gaeRatioCrossFONLLsyst3005->SetDirectory(0);
   Graph_gaeRatioCrossFONLLsyst3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gaeRatioCrossFONLLsyst3005->SetLineColor(ci);
   Graph_gaeRatioCrossFONLLsyst3005->SetMarkerStyle(20);
   Graph_gaeRatioCrossFONLLsyst3005->GetXaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLsyst3005->GetXaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetXaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetXaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLsyst3005->GetYaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLsyst3005->GetYaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetYaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetYaxis()->SetTitleFont(42);
   Graph_gaeRatioCrossFONLLsyst3005->GetZaxis()->SetLabelFont(42);
   Graph_gaeRatioCrossFONLLsyst3005->GetZaxis()->SetLabelSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetZaxis()->SetTitleSize(0.035);
   Graph_gaeRatioCrossFONLLsyst3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gaeRatioCrossFONLLsyst3005);
   
   grae->Draw("5");
   pRatio->Modified();
   cSigma->cd();
   cSigma->Modified();
   cSigma->cd();
   cSigma->SetSelected(cSigma);
}
