void canvasRAAPbPb_0_100()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Wed May  9 13:04:31 2018) by ROOT version6.02/13
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(-10.27799,-0.4801324,57.93308,2.831126);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLeftMargin(0.18);
   canvasRAA->SetRightMargin(0.043);
   canvasRAA->SetBottomMargin(0.145);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,2,55,10,0,2.5);
   hemptyEff1->SetMinimum(0);
   hemptyEff1->SetMaximum(2);
   hemptyEff1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff1->SetLineColor(ci);
   hemptyEff1->SetMarkerStyle(20);
   hemptyEff1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff1->GetXaxis()->CenterTitle(true);
   hemptyEff1->GetXaxis()->SetLabelFont(42);
   hemptyEff1->GetXaxis()->SetLabelSize(0.048);
   hemptyEff1->GetXaxis()->SetTitleSize(0.055);
   hemptyEff1->GetXaxis()->SetTitleFont(42);
   hemptyEff1->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff1->GetYaxis()->CenterTitle(true);
   hemptyEff1->GetYaxis()->SetLabelFont(42);
   hemptyEff1->GetYaxis()->SetLabelSize(0.048);
   hemptyEff1->GetYaxis()->SetTitleSize(0.055);
   hemptyEff1->GetYaxis()->SetTitleOffset(1.4);
   hemptyEff1->GetYaxis()->SetTitleFont(42);
   hemptyEff1->GetZaxis()->SetLabelFont(42);
   hemptyEff1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleFont(42);
   hemptyEff1->Draw("");
   TLine *line = new TLine(2,1,55,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.96,0.95,"28 pb^{-1} (pp) + 351 #mub^{-1} (PbPb) 5.02 TeV");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.75,0.5,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.21,0.88,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.5,0.66,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification_UnCor","B^{0}_{s} R_{AA}","p");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry->SetTextSize(0.07);
   entry=leg->AddEntry("gNuclearModification","Syst. uncert.","f");

   ci = 924;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.06);
   entry=leg->AddEntry("TBox","Global uncert.","f");
   entry->SetFillColor(16);
   entry->SetFillStyle(1001);
   entry->SetLineColor(16);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.06);
   leg->Draw();
   
   Double_t gNuclearModification_fx3001[2] = {
   11,
   32.5};
   Double_t gNuclearModification_fy3001[2] = {
   1.507894,
   0.8738383};
   Double_t gNuclearModification_felx3001[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fely3001[2] = {
   0.4953364,
   0.1654302};
   Double_t gNuclearModification_fehx3001[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fehy3001[2] = {
   0.4953364,
   0.1654302};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = 924;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#990099");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(33);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_gNuclearModification3001 = new TH1F("Graph_gNuclearModification3001","Graph",100,2.7,54.3);
   Graph_gNuclearModification3001->SetMinimum(0.5789259);
   Graph_gNuclearModification3001->SetMaximum(2.132713);
   Graph_gNuclearModification3001->SetDirectory(0);
   Graph_gNuclearModification3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3001->SetLineColor(ci);
   Graph_gNuclearModification3001->SetMarkerStyle(20);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3001);
   
   grae->Draw("5");
   Double_t xAxis1[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification2 = new TH1D("hNuclearModification2","",2, xAxis1);
   hNuclearModification2->SetBinContent(1,1.507894);
   hNuclearModification2->SetBinContent(2,0.8738383);
   hNuclearModification2->SetBinError(1,0.6052666);
   hNuclearModification2->SetBinError(2,0.3033643);
   hNuclearModification2->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification2->SetLineColor(ci);
   hNuclearModification2->SetLineStyle(0);
   hNuclearModification2->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification2->SetMarkerColor(ci);
   hNuclearModification2->SetMarkerStyle(33);
   hNuclearModification2->SetMarkerSize(2.2);
   hNuclearModification2->GetXaxis()->SetLabelFont(42);
   hNuclearModification2->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification2->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification2->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification2->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification2->GetXaxis()->SetTitleFont(42);
   hNuclearModification2->GetYaxis()->SetLabelFont(42);
   hNuclearModification2->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification2->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification2->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification2->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification2->GetYaxis()->SetTitleFont(42);
   hNuclearModification2->GetZaxis()->SetLabelFont(42);
   hNuclearModification2->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification2->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification2->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification2->GetZaxis()->SetTitleFont(42);
   hNuclearModification2->Draw("same p");
   Double_t xAxis2[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification3 = new TH1D("hNuclearModification3","",2, xAxis2);
   hNuclearModification3->SetBinContent(1,1.507894);
   hNuclearModification3->SetBinContent(2,0.8738383);
   hNuclearModification3->SetBinError(1,0.6052666);
   hNuclearModification3->SetBinError(2,0.3033643);
   hNuclearModification3->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification3->SetLineColor(ci);
   hNuclearModification3->SetLineStyle(0);
   hNuclearModification3->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification3->SetMarkerColor(ci);
   hNuclearModification3->SetMarkerStyle(33);
   hNuclearModification3->SetMarkerSize(2.2);
   hNuclearModification3->GetXaxis()->SetLabelFont(42);
   hNuclearModification3->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification3->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification3->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification3->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification3->GetXaxis()->SetTitleFont(42);
   hNuclearModification3->GetYaxis()->SetLabelFont(42);
   hNuclearModification3->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification3->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification3->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification3->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification3->GetYaxis()->SetTitleFont(42);
   hNuclearModification3->GetZaxis()->SetLabelFont(42);
   hNuclearModification3->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification3->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification3->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification3->GetZaxis()->SetTitleFont(42);
   hNuclearModification3->Draw("same");
   TBox *box = new TBox(2,0.9586116,4,1.045662);
   box->SetFillColor(16);
   box->SetLineColor(16);
   box->Draw();
   
   TH2F *hemptyEff_copy4 = new TH2F("hemptyEff_copy4","",50,2,55,10,0,2.5);
   hemptyEff_copy4->SetMinimum(0);
   hemptyEff_copy4->SetMaximum(2);
   hemptyEff_copy4->SetDirectory(0);
   hemptyEff_copy4->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy4->SetLineColor(ci);
   hemptyEff_copy4->SetMarkerStyle(20);
   hemptyEff_copy4->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy4->GetXaxis()->CenterTitle(true);
   hemptyEff_copy4->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy4->GetXaxis()->SetLabelSize(0.048);
   hemptyEff_copy4->GetXaxis()->SetTitleSize(0.055);
   hemptyEff_copy4->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy4->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy4->GetYaxis()->CenterTitle(true);
   hemptyEff_copy4->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy4->GetYaxis()->SetLabelSize(0.048);
   hemptyEff_copy4->GetYaxis()->SetTitleSize(0.055);
   hemptyEff_copy4->GetYaxis()->SetTitleOffset(1.4);
   hemptyEff_copy4->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy4->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy4->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy4->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy4->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy4->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
