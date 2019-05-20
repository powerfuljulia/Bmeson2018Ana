void canvasRAAPbPb_0_100(TCanvas*c, TGraphAsymmErrors *grae, bool drawOnlyPoint = 0)
{
c->cd();
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Mon Mar 19 05:40:09 2018) by ROOT version6.02/13
//   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
//   gStyle->SetOptStat(0);
//   gStyle->SetOptTitle(0);
//   canvasRAA->SetHighLightColor(2);
//   canvasRAA->Range(0.5519499,-0.2310559,1.777118,1.69441);
//   canvasRAA->SetFillColor(0);
//   canvasRAA->SetBorderMode(0);
//   canvasRAA->SetBorderSize(2);
//   canvasRAA->SetLogx();
//   canvasRAA->SetLeftMargin(0.12);
//   canvasRAA->SetRightMargin(0.03);
//   canvasRAA->SetTopMargin(0.075);
//   canvasRAA->SetBottomMargin(0.12);
//   canvasRAA->SetFrameBorderMode(0);
//   canvasRAA->SetFrameBorderMode(0);
//   
//   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,5,55,10,0,1.55);
//   hemptyEff1->SetMinimum(0);
//   hemptyEff1->SetMaximum(2);
//   hemptyEff1->SetStats(0);
//
   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
//   hemptyEff1->SetLineColor(ci);
//   hemptyEff1->SetMarkerStyle(20);
//   hemptyEff1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
//   hemptyEff1->GetXaxis()->CenterTitle(true);
//   hemptyEff1->GetXaxis()->SetLabelFont(42);
//   hemptyEff1->GetXaxis()->SetTitleSize(0.05);
//   hemptyEff1->GetXaxis()->SetTitleFont(42);
//   hemptyEff1->GetYaxis()->SetTitle("R_{AA}");
//   hemptyEff1->GetYaxis()->CenterTitle(true);
//   hemptyEff1->GetYaxis()->SetLabelFont(42);
//   hemptyEff1->GetYaxis()->SetTitleSize(0.05);
//   hemptyEff1->GetYaxis()->SetTitleOffset(1.1);
//   hemptyEff1->GetYaxis()->SetTitleFont(42);
//   hemptyEff1->GetZaxis()->SetLabelFont(42);
//   hemptyEff1->GetZaxis()->SetLabelSize(0.035);
//   hemptyEff1->GetZaxis()->SetTitleSize(0.035);
//   hemptyEff1->GetZaxis()->SetTitleFont(42);
//   hemptyEff1->Draw("");
//   TLine *line = new TLine(5,1,55,1);
//   line->SetLineStyle(2);
//   line->SetLineWidth(2);
//   line->Draw();
//   TLatex *   tex = new TLatex(0.2,0.936,"28.0 pb^{-1} (pp 5.02 TeV) + 351 #mub^{-1} (PbPb 5.02 TeV)");
//tex->SetNDC();
//   tex->SetTextFont(42);
//   tex->SetTextSize(0.038);
//   tex->SetLineWidth(2);
//   tex->Draw();
//      tex = new TLatex(0.81,0.21,"B^{#pm}");
//tex->SetNDC();
//   tex->SetTextSize(0.08);
//   tex->SetLineWidth(2);
//   tex->Draw();
//      tex = new TLatex(0.16,0.9,"CMS");
//tex->SetNDC();
//   tex->SetTextAlign(13);
//   tex->SetTextSize(0.06);
//   tex->SetLineWidth(2);
//   tex->Draw();
//      tex = new TLatex(0.81,0.16,"|y| < 2.4");
//tex->SetNDC();
//   tex->SetTextFont(42);
//   tex->SetTextSize(0.04);
//   tex->SetLineWidth(2);
//   tex->Draw();
//   
//   TLegend *leg = new TLegend(0.6036242,0.7474695,0.942953,0.8457592,NULL,"brNDC");
//   leg->SetBorderSize(0);
//   leg->SetTextSize(0.04);
//   leg->SetLineColor(0);
//   leg->SetLineStyle(1);
//   leg->SetLineWidth(1);
//   leg->SetFillColor(0);
//   leg->SetFillStyle(1001);
//   TLegendEntry *entry=leg->AddEntry("gNuclearModification_UnCor","R_{AA}","pe");
//   entry->SetLineStyle(1);
//
//   ci = TColor::GetColor("#0033cc");
//   entry->SetMarkerColor(ci);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1.2);
//   entry->SetTextFont(42);
//   entry->SetTextSize(0.038);
//   entry=leg->AddEntry("gNuclearModification","Syst. uncert.","f");
//
//   ci = 924;
//   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
//   entry->SetFillColor(ci);
//   entry->SetFillStyle(1001);
//   entry->SetLineStyle(1);
//   entry->SetMarkerColor(4);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1);
//   entry->SetTextFont(42);
//   entry->SetTextSize(0.03);
//   entry=leg->AddEntry("TBox","Global uncert.","f");
//   entry->SetFillColor(16);
//   entry->SetFillStyle(1001);
//   entry->SetLineColor(16);
//   entry->SetLineStyle(1);
//   entry->SetMarkerColor(1);
//   entry->SetMarkerStyle(21);
//   entry->SetMarkerSize(1);
//   entry->SetTextFont(42);
//   entry->SetTextSize(0.03);
//   leg->Draw();
   
   Double_t gNuclearModification_fx3001[5] = {
   8.5,
   12.5,
   17.5,
   25,
   40};
   Double_t gNuclearModification_fy3001[5] = {
   0.3458558,
   0.4480066,
   0.4402087,
   0.615181,
   0.3486562};
   Double_t gNuclearModification_felx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_fely3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   Double_t gNuclearModification_fehx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_fehy3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   grae = new TGraphAsymmErrors(5,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification_Bp");
   grae->SetTitle("Graph");

   ci = 111;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#0033cc");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_gNuclearModification3001 = new TH1F("Graph_gNuclearModification3001","Graph",100,2.7,54.3);
   Graph_gNuclearModification3001->SetMinimum(0.2364759);
   Graph_gNuclearModification3001->SetMaximum(0.7605233);
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
   
   if(!drawOnlyPoint) grae->Draw("5");
   Double_t xAxis1[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2 = new TH1D("hNuclearModification2_Bp","",5, xAxis1);
   hNuclearModification2->SetBinContent(1,0.3458558);
   hNuclearModification2->SetBinContent(2,0.4480066);
   hNuclearModification2->SetBinContent(3,0.4402087);
   hNuclearModification2->SetBinContent(4,0.615181);
   hNuclearModification2->SetBinContent(5,0.3486562);
   hNuclearModification2->SetBinError(1,0.1086955);
   hNuclearModification2->SetBinError(2,0.07447295);
   hNuclearModification2->SetBinError(3,0.07507186);
   hNuclearModification2->SetBinError(4,0.09192405);
   hNuclearModification2->SetBinError(5,0.1120147);
   hNuclearModification2->SetEntries(109.8058);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2->SetLineColor(ci);
   hNuclearModification2->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2->SetMarkerColor(ci);
   hNuclearModification2->SetMarkerStyle(21);
   hNuclearModification2->SetMarkerSize(1.2);
   hNuclearModification2->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2->GetXaxis()->SetLabelFont(42);
   hNuclearModification2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetXaxis()->SetTitleFont(42);
   hNuclearModification2->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2->GetYaxis()->SetLabelFont(42);
   hNuclearModification2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetYaxis()->SetTitleFont(42);
   hNuclearModification2->GetZaxis()->SetLabelFont(42);
   hNuclearModification2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetZaxis()->SetTitleFont(42);
   hNuclearModification2->Draw("same");
//   TBox *box = new TBox(5,0.9586116,5.35,1.045662);
//   box->SetFillColor(16);
//   box->SetLineColor(16);
//   box->Draw();
//   Double_t xAxis2[6] = {7, 10, 15, 20, 30, 50}; 
//   
//   TH1D *hNuclearModification3 = new TH1D("hNuclearModification3_Bp","",5, xAxis2);
//   hNuclearModification3->SetBinContent(1,0.3458558);
//   hNuclearModification3->SetBinContent(2,0.4480066);
//   hNuclearModification3->SetBinContent(3,0.4402087);
//   hNuclearModification3->SetBinContent(4,0.615181);
//   hNuclearModification3->SetBinContent(5,0.3486562);
//   hNuclearModification3->SetBinError(1,0.1086955);
//   hNuclearModification3->SetBinError(2,0.07447295);
//   hNuclearModification3->SetBinError(3,0.07507186);
//   hNuclearModification3->SetBinError(4,0.09192405);
//   hNuclearModification3->SetBinError(5,0.1120147);
//   hNuclearModification3->SetEntries(109.8058);
//
//   ci = TColor::GetColor("#0033cc");
//   hNuclearModification3->SetLineColor(ci);
//   hNuclearModification3->SetLineWidth(3);
//
//   ci = TColor::GetColor("#0033cc");
//   hNuclearModification3->SetMarkerColor(ci);
//   hNuclearModification3->SetMarkerStyle(21);
//   hNuclearModification3->SetMarkerSize(1.2);
//   hNuclearModification3->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
//   hNuclearModification3->GetXaxis()->SetLabelFont(42);
//   hNuclearModification3->GetXaxis()->SetLabelSize(0.035);
//   hNuclearModification3->GetXaxis()->SetTitleSize(0.035);
//   hNuclearModification3->GetXaxis()->SetTitleFont(42);
//   hNuclearModification3->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
//   hNuclearModification3->GetYaxis()->SetLabelFont(42);
//   hNuclearModification3->GetYaxis()->SetLabelSize(0.035);
//   hNuclearModification3->GetYaxis()->SetTitleSize(0.035);
//   hNuclearModification3->GetYaxis()->SetTitleFont(42);
//   hNuclearModification3->GetZaxis()->SetLabelFont(42);
//   hNuclearModification3->GetZaxis()->SetLabelSize(0.035);
//   hNuclearModification3->GetZaxis()->SetTitleSize(0.035);
//   hNuclearModification3->GetZaxis()->SetTitleFont(42);
//   hNuclearModification3->Draw("same p");
//      tex = new TLatex(0.81,0.21,"B^{#pm}");
//tex->SetNDC();
//   tex->SetTextSize(0.08);
//   tex->SetLineWidth(2);
//   tex->Draw();
//   
//   TH2F *hemptyEff_copy4 = new TH2F("hemptyEff_copy4","",50,5,55,10,0,1.55);
//   hemptyEff_copy4->SetMinimum(0);
//   hemptyEff_copy4->SetMaximum(2);
//   hemptyEff_copy4->SetDirectory(0);
//   hemptyEff_copy4->SetStats(0);
//
//   ci = TColor::GetColor("#000099");
//   hemptyEff_copy4->SetLineColor(ci);
//   hemptyEff_copy4->SetMarkerStyle(20);
//   hemptyEff_copy4->GetXaxis()->SetTitle("p_{T} (GeV/c)");
//   hemptyEff_copy4->GetXaxis()->CenterTitle(true);
//   hemptyEff_copy4->GetXaxis()->SetLabelFont(42);
//   hemptyEff_copy4->GetXaxis()->SetTitleSize(0.05);
//   hemptyEff_copy4->GetXaxis()->SetTitleFont(42);
//   hemptyEff_copy4->GetYaxis()->SetTitle("R_{AA}");
//   hemptyEff_copy4->GetYaxis()->CenterTitle(true);
//   hemptyEff_copy4->GetYaxis()->SetLabelFont(42);
//   hemptyEff_copy4->GetYaxis()->SetTitleSize(0.05);
//   hemptyEff_copy4->GetYaxis()->SetTitleOffset(1.1);
//   hemptyEff_copy4->GetYaxis()->SetTitleFont(42);
//   hemptyEff_copy4->GetZaxis()->SetLabelFont(42);
//   hemptyEff_copy4->GetZaxis()->SetLabelSize(0.035);
//   hemptyEff_copy4->GetZaxis()->SetTitleSize(0.035);
//   hemptyEff_copy4->GetZaxis()->SetTitleFont(42);
//   hemptyEff_copy4->Draw("sameaxis");
//   canvasRAA->Modified();
//   canvasRAA->cd();
//   canvasRAA->SetSelected(canvasRAA);
}
