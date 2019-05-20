void canvasRAAPbPb_0_100_BpRAA()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Sun Sep 30 18:06:09 2018) by ROOT version6.02/13
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
      tex = new TLatex(0.21,0.79,"|y| < 2.4");
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
      tex = new TLatex(0.35,0.877,"Supplementary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t gNuclearModification_Bp_fx3001[5] = {
   8.5,
   12.5,
   17.5,
   25,
   40};
   Double_t gNuclearModification_Bp_fy3001[5] = {
   0.3458558,
   0.4480066,
   0.4402087,
   0.615181,
   0.3486562};
   Double_t gNuclearModification_Bp_felx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fely3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   Double_t gNuclearModification_Bp_fehx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fehy3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,gNuclearModification_Bp_fx3001,gNuclearModification_Bp_fy3001,gNuclearModification_Bp_felx3001,gNuclearModification_Bp_fehx3001,gNuclearModification_Bp_fely3001,gNuclearModification_Bp_fehy3001);
   grae->SetName("gNuclearModification_Bp");
   grae->SetTitle("Graph");
   grae->SetFillColor(111);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#0033cc");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph_gNuclearModification30013001 = new TH1F("Graph_Graph_gNuclearModification30013001","Graph",100,2.7,54.3);
   Graph_Graph_gNuclearModification30013001->SetMinimum(0.2364759);
   Graph_Graph_gNuclearModification30013001->SetMaximum(0.7605233);
   Graph_Graph_gNuclearModification30013001->SetDirectory(0);
   Graph_Graph_gNuclearModification30013001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_gNuclearModification30013001->SetLineColor(ci);
   Graph_Graph_gNuclearModification30013001->SetMarkerStyle(20);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_gNuclearModification30013001);
   
   grae->Draw("5");
   Double_t xAxis1[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp2 = new TH1D("hNuclearModification2_Bp2","",5, xAxis1);
   hNuclearModification2_Bp2->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp2->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp2->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp2->SetBinContent(4,0.615181);
   hNuclearModification2_Bp2->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp2->SetBinError(1,0.1086955);
   hNuclearModification2_Bp2->SetBinError(2,0.07447295);
   hNuclearModification2_Bp2->SetBinError(3,0.07507186);
   hNuclearModification2_Bp2->SetBinError(4,0.09192405);
   hNuclearModification2_Bp2->SetBinError(5,0.1120147);
   hNuclearModification2_Bp2->SetEntries(109.8058);
   hNuclearModification2_Bp2->SetDirectory(0);
   hNuclearModification2_Bp2->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp2->SetLineColor(ci);
   hNuclearModification2_Bp2->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp2->SetMarkerColor(ci);
   hNuclearModification2_Bp2->SetMarkerStyle(21);
   hNuclearModification2_Bp2->SetMarkerSize(1.2);
   hNuclearModification2_Bp2->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp2->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp2->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp2->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp2->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp2->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp2->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp2->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp2->Draw("same");
   TBox *box = new TBox(4,0.9586116,6,1.045662);

   ci = 929;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#0099ff");
   box->SetLineColor(ci);
   box->Draw();
   
   TLegend *leg = new TLegend(0.7,0.65,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification_UnCor","B^{0}_{s}","pf");

   ci = 925;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry->SetTextSize(0.07);
   entry=leg->AddEntry("","B^{+}","pf");

   ci = 928;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0033cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.07);
   leg->Draw();
   
   Double_t gNuclearModification_fx3002[2] = {
   11,
   32.5};
   Double_t gNuclearModification_fy3002[2] = {
   1.507894,
   0.8738383};
   Double_t gNuclearModification_felx3002[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fely3002[2] = {
   0.4453686,
   0.1146802};
   Double_t gNuclearModification_fehx3002[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fehy3002[2] = {
   0.4453686,
   0.1146802};
   grae = new TGraphAsymmErrors(2,gNuclearModification_fx3002,gNuclearModification_fy3002,gNuclearModification_felx3002,gNuclearModification_fehx3002,gNuclearModification_fely3002,gNuclearModification_fehy3002);
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
   
   TH1F *Graph_gNuclearModification3002 = new TH1F("Graph_gNuclearModification3002","Graph",100,2.7,54.3);
   Graph_gNuclearModification3002->SetMinimum(0.6397477);
   Graph_gNuclearModification3002->SetMaximum(2.072674);
   Graph_gNuclearModification3002->SetDirectory(0);
   Graph_gNuclearModification3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3002->SetLineColor(ci);
   Graph_gNuclearModification3002->SetMarkerStyle(20);
   Graph_gNuclearModification3002->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3002->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3002->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3002);
   
   grae->Draw("5");
   Double_t xAxis2[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp3 = new TH1D("hNuclearModification2_Bp3","",5, xAxis2);
   hNuclearModification2_Bp3->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp3->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp3->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp3->SetBinContent(4,0.615181);
   hNuclearModification2_Bp3->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp3->SetBinError(1,0.1086955);
   hNuclearModification2_Bp3->SetBinError(2,0.07447295);
   hNuclearModification2_Bp3->SetBinError(3,0.07507186);
   hNuclearModification2_Bp3->SetBinError(4,0.09192405);
   hNuclearModification2_Bp3->SetBinError(5,0.1120147);
   hNuclearModification2_Bp3->SetEntries(109.8058);
   hNuclearModification2_Bp3->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp3->SetLineColor(ci);
   hNuclearModification2_Bp3->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp3->SetMarkerColor(ci);
   hNuclearModification2_Bp3->SetMarkerStyle(21);
   hNuclearModification2_Bp3->SetMarkerSize(1.2);
   hNuclearModification2_Bp3->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp3->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp3->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp3->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp3->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp3->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp3->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp3->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp3->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp3->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp3->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp3->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp3->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp3->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp3->Draw("same");
   Double_t xAxis3[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification4 = new TH1D("hNuclearModification4","",2, xAxis3);
   hNuclearModification4->SetBinContent(1,1.507894);
   hNuclearModification4->SetBinContent(2,0.8738383);
   hNuclearModification4->SetBinError(1,0.6052666);
   hNuclearModification4->SetBinError(2,0.3033643);
   hNuclearModification4->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification4->SetLineColor(ci);
   hNuclearModification4->SetLineStyle(0);
   hNuclearModification4->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification4->SetMarkerColor(ci);
   hNuclearModification4->SetMarkerStyle(33);
   hNuclearModification4->SetMarkerSize(2.2);
   hNuclearModification4->GetXaxis()->SetLabelFont(42);
   hNuclearModification4->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification4->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification4->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification4->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification4->GetXaxis()->SetTitleFont(42);
   hNuclearModification4->GetYaxis()->SetLabelFont(42);
   hNuclearModification4->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification4->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification4->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification4->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification4->GetYaxis()->SetTitleFont(42);
   hNuclearModification4->GetZaxis()->SetLabelFont(42);
   hNuclearModification4->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification4->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification4->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification4->GetZaxis()->SetTitleFont(42);
   hNuclearModification4->Draw("same p");
   Double_t xAxis4[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification5 = new TH1D("hNuclearModification5","",2, xAxis4);
   hNuclearModification5->SetBinContent(1,1.507894);
   hNuclearModification5->SetBinContent(2,0.8738383);
   hNuclearModification5->SetBinError(1,0.6052666);
   hNuclearModification5->SetBinError(2,0.3033643);
   hNuclearModification5->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification5->SetLineColor(ci);
   hNuclearModification5->SetLineStyle(0);
   hNuclearModification5->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification5->SetMarkerColor(ci);
   hNuclearModification5->SetMarkerStyle(33);
   hNuclearModification5->SetMarkerSize(2.2);
   hNuclearModification5->GetXaxis()->SetLabelFont(42);
   hNuclearModification5->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification5->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification5->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification5->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification5->GetXaxis()->SetTitleFont(42);
   hNuclearModification5->GetYaxis()->SetLabelFont(42);
   hNuclearModification5->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification5->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification5->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification5->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification5->GetYaxis()->SetTitleFont(42);
   hNuclearModification5->GetZaxis()->SetLabelFont(42);
   hNuclearModification5->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification5->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification5->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification5->GetZaxis()->SetTitleFont(42);
   hNuclearModification5->Draw("same");
   box = new TBox(2,0.9586116,4,1.045662);

   ci = 927;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#cc33cc");
   box->SetLineColor(ci);
   box->Draw();
   
   TH2F *hemptyEff_copy6 = new TH2F("hemptyEff_copy6","",50,2,55,10,0,2.5);
   hemptyEff_copy6->SetMinimum(0);
   hemptyEff_copy6->SetMaximum(2);
   hemptyEff_copy6->SetDirectory(0);
   hemptyEff_copy6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy6->SetLineColor(ci);
   hemptyEff_copy6->SetMarkerStyle(20);
   hemptyEff_copy6->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy6->GetXaxis()->CenterTitle(true);
   hemptyEff_copy6->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy6->GetXaxis()->SetLabelSize(0.048);
   hemptyEff_copy6->GetXaxis()->SetTitleSize(0.055);
   hemptyEff_copy6->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy6->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy6->GetYaxis()->CenterTitle(true);
   hemptyEff_copy6->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy6->GetYaxis()->SetLabelSize(0.048);
   hemptyEff_copy6->GetYaxis()->SetTitleSize(0.055);
   hemptyEff_copy6->GetYaxis()->SetTitleOffset(1.4);
   hemptyEff_copy6->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy6->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy6->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy6->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy6->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy6->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
