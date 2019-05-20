void BsBpRatio()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Sun Sep 30 18:06:11 2018) by ROOT version6.02/13
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->Range(-17.59459,-1.440397,63.48649,8.493378);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLeftMargin(0.18);
   canvasRAA->SetRightMargin(0.043);
   canvasRAA->SetBottomMargin(0.145);
   canvasRAA->SetFrameFillStyle(0);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameFillStyle(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,-3,60,10,0,7.5);
   hemptyEff1->SetLineStyle(0);
   hemptyEff1->SetMarkerStyle(20);
   hemptyEff1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff1->GetXaxis()->CenterTitle(true);
   hemptyEff1->GetXaxis()->SetLabelFont(42);
   hemptyEff1->GetXaxis()->SetLabelOffset(0.007);
   hemptyEff1->GetXaxis()->SetLabelSize(0.048);
   hemptyEff1->GetXaxis()->SetTitleSize(0.055);
   hemptyEff1->GetXaxis()->SetTitleFont(42);
   hemptyEff1->GetYaxis()->SetTitle("R_{AA}^{B^{0}_{s}} / R_{AA}^{B^{+}}");
   hemptyEff1->GetYaxis()->CenterTitle(true);
   hemptyEff1->GetYaxis()->SetLabelFont(42);
   hemptyEff1->GetYaxis()->SetLabelOffset(0.007);
   hemptyEff1->GetYaxis()->SetLabelSize(0.048);
   hemptyEff1->GetYaxis()->SetTitleSize(0.055);
   hemptyEff1->GetYaxis()->SetTitleOffset(1.4);
   hemptyEff1->GetYaxis()->SetTitleFont(42);
   hemptyEff1->GetZaxis()->SetLabelFont(42);
   hemptyEff1->GetZaxis()->SetLabelOffset(0.007);
   hemptyEff1->GetZaxis()->SetLabelSize(0.05);
   hemptyEff1->GetZaxis()->SetTitleSize(0.06);
   hemptyEff1->GetZaxis()->SetTitleFont(42);
   hemptyEff1->Draw("");
   TLine *line = new TLine(-3,1,60,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.96,0.95,"28 pb^{-1} (pp) + 351 #mub^{-1} (PbPb) 5.02 TeV");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.21,0.74,"|y| < 2.4");
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
      tex = new TLatex(0.62,0.18,"Cent. 0-100%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.21,0.83,"Supplementary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.55,0.75,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","R_{AA}^{B^{0}_{s}} / R_{AA}^{B^{+}}","pf");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 924;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(2.2);
   entry->SetTextFont(42);
   entry->SetTextSize(0.065);
   leg->Draw();
   
   Double_t Graph0_fx3001[2] = {
   11,
   32.5};
   Double_t Graph0_fy3001[2] = {
   3.980763,
   1.79735};
   Double_t Graph0_felx3001[2] = {
   4,
   17.5};
   Double_t Graph0_fely3001[2] = {
   1.310567,
   0.3401429};
   Double_t Graph0_fehx3001[2] = {
   4,
   17.5};
   Double_t Graph0_fehy3001[2] = {
   1.310567,
   0.3401429};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");

   ci = 924;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#990099");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(33);
   grae->SetMarkerSize(2.2);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,2.7,54.3);
   Graph_Graph3001->SetMinimum(1.073795);
   Graph_Graph3001->SetMaximum(5.674743);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineStyle(0);
   Graph_Graph3001->SetMarkerStyle(20);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(1.05);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("5");
   Double_t xAxis1[3] = {7, 15, 50}; 
   
   TH1D *hRAAratio2 = new TH1D("hRAAratio2","",2, xAxis1);
   hRAAratio2->SetBinContent(1,3.980763);
   hRAAratio2->SetBinContent(2,1.79735);
   hRAAratio2->SetBinError(1,1.794392);
   hRAAratio2->SetBinError(2,0.656781);
   hRAAratio2->SetEntries(2);

   ci = TColor::GetColor("#990099");
   hRAAratio2->SetLineColor(ci);
   hRAAratio2->SetLineStyle(0);
   hRAAratio2->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hRAAratio2->SetMarkerColor(ci);
   hRAAratio2->SetMarkerStyle(33);
   hRAAratio2->SetMarkerSize(2.2);
   hRAAratio2->GetXaxis()->SetLabelFont(42);
   hRAAratio2->GetXaxis()->SetLabelOffset(0.007);
   hRAAratio2->GetXaxis()->SetLabelSize(0.05);
   hRAAratio2->GetXaxis()->SetTitleSize(0.06);
   hRAAratio2->GetXaxis()->SetTitleOffset(0.9);
   hRAAratio2->GetXaxis()->SetTitleFont(42);
   hRAAratio2->GetYaxis()->SetLabelFont(42);
   hRAAratio2->GetYaxis()->SetLabelOffset(0.007);
   hRAAratio2->GetYaxis()->SetLabelSize(0.05);
   hRAAratio2->GetYaxis()->SetTitleSize(0.06);
   hRAAratio2->GetYaxis()->SetTitleOffset(1.05);
   hRAAratio2->GetYaxis()->SetTitleFont(42);
   hRAAratio2->GetZaxis()->SetLabelFont(42);
   hRAAratio2->GetZaxis()->SetLabelOffset(0.007);
   hRAAratio2->GetZaxis()->SetLabelSize(0.05);
   hRAAratio2->GetZaxis()->SetTitleSize(0.06);
   hRAAratio2->GetZaxis()->SetTitleFont(42);
   hRAAratio2->Draw("same p");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
