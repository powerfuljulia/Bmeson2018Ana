void canvasRAAPbPb_0_100_ChHadRAA_DRAA_BpRAA_NPJpsiRAA()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Wed May  9 14:06:20 2018) by ROOT version6.02/13
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(-1.014354,-0.7682119,2.948556,4.529801);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLogx();
   canvasRAA->SetLeftMargin(0.18);
   canvasRAA->SetRightMargin(0.043);
   canvasRAA->SetBottomMargin(0.145);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,0.5,600,10,0,4);
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
   TLine *line = new TLine(0.5,1,600,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.96,0.95,"28 pb^{-1} (pp) + 351 #mub^{-1} (PbPb) 5.02 TeV");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.22,0.4,"|y| < 2.4");
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
   TBox *box = new TBox(0.7,0.3322697,0.8,0.3887397);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.8,0.3547214,0.9,0.4153951);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.9,0.3856854,1,0.4519942);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1,0.4035821,1.1,0.4786815);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.1,0.4178419,1.2,0.4951344);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.2,0.4336979,1.4,0.5260356);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.4,0.4471445,1.6,0.5499409);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.6,0.454559,1.8,0.5776292);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.8,0.4545544,2,0.5775976);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2,0.4458492,2.2,0.5856694);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.2,0.4400381,2.4,0.5780321);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.4,0.4004238,3.2,0.5432211);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(3.2,0.3194642,4,0.443112);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4,0.2555583,4.8,0.3477606);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4.8,0.2236467,5.6,0.290029);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(5.6,0.2091373,6.4,0.2633415);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(6.4,0.2084873,7.2,0.2542985);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(7.2,0.218131,9.6,0.2613273);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(9.6,0.254349,12,0.3047338);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(12,0.279773,14.4,0.3421784);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(14.4,0.3230158,19.2,0.395078);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(19.2,0.3691498,24,0.4514966);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(24,0.4081148,28.8,0.4990331);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(28.8,0.4382444,35.2,0.5359827);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(35.2,0.4849575,41.6,0.5931196);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(41.6,0.54671,48,0.6660902);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(48,0.5934783,60.8,0.7232848);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(60.8,0.6229389,73.6,0.7600401);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(73.6,0.6765564,86.4,0.8254808);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(86.4,0.7227269,103.6,0.8827653);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(103.6,0.7255117,120.8,0.8873466);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(120.8,0.732652,140,0.8963203);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(140,0.7948418,165,0.9722788);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(165,0.8158651,250,0.9995696);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(250,0.7867229,400,0.9667282);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   Double_t xAxis1[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100584__2__2__22 = new TH1D("RAA_0_100584__2__2__22","",37, xAxis1);
   RAA_0_100584__2__2__22->SetBinContent(1,-1);
   RAA_0_100584__2__2__22->SetBinContent(2,-1);
   RAA_0_100584__2__2__22->SetBinContent(3,0.3605047);
   RAA_0_100584__2__2__22->SetBinContent(4,0.3850582);
   RAA_0_100584__2__2__22->SetBinContent(5,0.4188398);
   RAA_0_100584__2__2__22->SetBinContent(6,0.4411318);
   RAA_0_100584__2__2__22->SetBinContent(7,0.4564881);
   RAA_0_100584__2__2__22->SetBinContent(8,0.4798668);
   RAA_0_100584__2__2__22->SetBinContent(9,0.4985427);
   RAA_0_100584__2__2__22->SetBinContent(10,0.516094);
   RAA_0_100584__2__2__22->SetBinContent(11,0.5160761);
   RAA_0_100584__2__2__22->SetBinContent(12,0.5157593);
   RAA_0_100584__2__2__22->SetBinContent(13,0.5090351);
   RAA_0_100584__2__2__22->SetBinContent(14,0.4718224);
   RAA_0_100584__2__2__22->SetBinContent(15,0.381288);
   RAA_0_100584__2__2__22->SetBinContent(16,0.3016595);
   RAA_0_100584__2__2__22->SetBinContent(17,0.2568378);
   RAA_0_100584__2__2__22->SetBinContent(18,0.2362394);
   RAA_0_100584__2__2__22->SetBinContent(19,0.2313929);
   RAA_0_100584__2__2__22->SetBinContent(20,0.2397292);
   RAA_0_100584__2__2__22->SetBinContent(21,0.2795414);
   RAA_0_100584__2__2__22->SetBinContent(22,0.3109757);
   RAA_0_100584__2__2__22->SetBinContent(23,0.359047);
   RAA_0_100584__2__2__22->SetBinContent(24,0.4103232);
   RAA_0_100584__2__2__22->SetBinContent(25,0.4535739);
   RAA_0_100584__2__2__22->SetBinContent(26,0.4871136);
   RAA_0_100584__2__2__22->SetBinContent(27,0.5390386);
   RAA_0_100584__2__2__22->SetBinContent(28,0.6064001);
   RAA_0_100584__2__2__22->SetBinContent(29,0.6583816);
   RAA_0_100584__2__2__22->SetBinContent(30,0.6914895);
   RAA_0_100584__2__2__22->SetBinContent(31,0.7510186);
   RAA_0_100584__2__2__22->SetBinContent(32,0.8027461);
   RAA_0_100584__2__2__22->SetBinContent(33,0.8064291);
   RAA_0_100584__2__2__22->SetBinContent(34,0.8144861);
   RAA_0_100584__2__2__22->SetBinContent(35,0.8835603);
   RAA_0_100584__2__2__22->SetBinContent(36,0.9077175);
   RAA_0_100584__2__2__22->SetBinContent(37,0.8767255);
   RAA_0_100584__2__2__22->SetBinError(1,1.279903e-05);
   RAA_0_100584__2__2__22->SetBinError(2,1.387861e-05);
   RAA_0_100584__2__2__22->SetBinError(3,1.439234e-05);
   RAA_0_100584__2__2__22->SetBinError(4,1.673993e-05);
   RAA_0_100584__2__2__22->SetBinError(5,1.996438e-05);
   RAA_0_100584__2__2__22->SetBinError(6,2.296277e-05);
   RAA_0_100584__2__2__22->SetBinError(7,2.652961e-05);
   RAA_0_100584__2__2__22->SetBinError(8,2.303589e-05);
   RAA_0_100584__2__2__22->SetBinError(9,2.956636e-05);
   RAA_0_100584__2__2__22->SetBinError(10,3.708897e-05);
   RAA_0_100584__2__2__22->SetBinError(11,4.504344e-05);
   RAA_0_100584__2__2__22->SetBinError(12,5.385318e-05);
   RAA_0_100584__2__2__22->SetBinError(13,6.332594e-05);
   RAA_0_100584__2__2__22->SetBinError(14,4.278537e-05);
   RAA_0_100584__2__2__22->SetBinError(15,6.266848e-05);
   RAA_0_100584__2__2__22->SetBinError(16,8.299302e-05);
   RAA_0_100584__2__2__22->SetBinError(17,0.0001099248);
   RAA_0_100584__2__2__22->SetBinError(18,0.0001477243);
   RAA_0_100584__2__2__22->SetBinError(19,0.0002002684);
   RAA_0_100584__2__2__22->SetBinError(20,0.0001962782);
   RAA_0_100584__2__2__22->SetBinError(21,0.00043599);
   RAA_0_100584__2__2__22->SetBinError(22,0.0007955915);
   RAA_0_100584__2__2__22->SetBinError(23,0.001121086);
   RAA_0_100584__2__2__22->SetBinError(24,0.002349183);
   RAA_0_100584__2__2__22->SetBinError(25,0.003934258);
   RAA_0_100584__2__2__22->SetBinError(26,0.005431548);
   RAA_0_100584__2__2__22->SetBinError(27,0.007593713);
   RAA_0_100584__2__2__22->SetBinError(28,0.008532134);
   RAA_0_100584__2__2__22->SetBinError(29,0.006423681);
   RAA_0_100584__2__2__22->SetBinError(30,0.009668077);
   RAA_0_100584__2__2__22->SetBinError(31,0.009013466);
   RAA_0_100584__2__2__22->SetBinError(32,0.01230905);
   RAA_0_100584__2__2__22->SetBinError(33,0.01985833);
   RAA_0_100584__2__2__22->SetBinError(34,0.02497965);
   RAA_0_100584__2__2__22->SetBinError(35,0.04145952);
   RAA_0_100584__2__2__22->SetBinError(36,0.0459072);
   RAA_0_100584__2__2__22->SetBinError(37,0.152905);
   RAA_0_100584__2__2__22->SetMinimum(0);
   RAA_0_100584__2__2__22->SetMaximum(1.8);
   RAA_0_100584__2__2__22->SetEntries(11078.9);
   RAA_0_100584__2__2__22->SetDirectory(0);
   RAA_0_100584__2__2__22->SetStats(0);

   ci = TColor::GetColor("#ffcc00");
   RAA_0_100584__2__2__22->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   RAA_0_100584__2__2__22->SetLineColor(ci);
   RAA_0_100584__2__2__22->SetLineWidth(2);
   RAA_0_100584__2__2__22->SetMarkerStyle(20);
   RAA_0_100584__2__2__22->SetMarkerSize(1.3);
   RAA_0_100584__2__2__22->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100584__2__2__22->GetXaxis()->SetRange(1,37);
   RAA_0_100584__2__2__22->GetXaxis()->CenterTitle(true);
   RAA_0_100584__2__2__22->GetXaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__22->GetXaxis()->SetLabelOffset(-0.002);
   RAA_0_100584__2__2__22->GetXaxis()->SetLabelSize(0.045);
   RAA_0_100584__2__2__22->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100584__2__2__22->GetXaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__22->GetYaxis()->SetTitle("R_{AA}, R_{pA}");
   RAA_0_100584__2__2__22->GetYaxis()->CenterTitle(true);
   RAA_0_100584__2__2__22->GetYaxis()->SetNdivisions(508);
   RAA_0_100584__2__2__22->GetYaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__22->GetYaxis()->SetLabelSize(0.045);
   RAA_0_100584__2__2__22->GetYaxis()->SetTitleSize(0.05);
   RAA_0_100584__2__2__22->GetYaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__22->GetZaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__22->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100584__2__2__22->GetZaxis()->SetTitleSize(0.09);
   RAA_0_100584__2__2__22->GetZaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__22->Draw("same");
   box = new TBox(0,0.9080761,0.608,1.091924);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc00");
   box->SetLineColor(ci);
   box->Draw();
   
   Double_t gNuclearModification_fx3001[5] = {
   22.5,
   27.5,
   35,
   50,
   80};
   Double_t gNuclearModification_fy3001[5] = {
   0.4279886,
   0.4447959,
   0.5041472,
   0.6796131,
   0.7424828};
   Double_t gNuclearModification_felx3001[5] = {
   2.5,
   2.5,
   5,
   10,
   20};
   Double_t gNuclearModification_fely3001[5] = {
   0.08040356,
   0.08777721,
   0.09566393,
   0.1257512,
   0.1437027};
   Double_t gNuclearModification_fehx3001[5] = {
   2.5,
   2.5,
   5,
   10,
   20};
   Double_t gNuclearModification_fehy3001[5] = {
   0.08040356,
   0.08777721,
   0.09566393,
   0.1257512,
   0.1437027};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = 927;
   color = new TColor(ci, 0.6, 1, 0.6, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_gNuclearModification30013001 = new TH1F("Graph_Graph_gNuclearModification30013001","Graph",100,12,108);
   Graph_Graph_gNuclearModification30013001->SetMinimum(0.293725);
   Graph_Graph_gNuclearModification30013001->SetMaximum(0.9400455);
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
   
   Double_t gNuclearModification_fx3002[9] = {
   2.5,
   3.5,
   4.5,
   5.5,
   7,
   9,
   11.25,
   13.75,
   17.5};
   Double_t gNuclearModification_fy3002[9] = {
   0.6315195,
   0.4432341,
   0.3674997,
   0.2758138,
   0.2623725,
   0.2722143,
   0.3291268,
   0.3207651,
   0.3937182};
   Double_t gNuclearModification_felx3002[9] = {
   0.5,
   0.5,
   0.5,
   0.5,
   1,
   1,
   1.25,
   1.25,
   2.5};
   Double_t gNuclearModification_fely3002[9] = {
   0.1385446,
   0.08615785,
   0.06750189,
   0.05013722,
   0.04752139,
   0.04884336,
   0.05908503,
   0.05758429,
   0.07618566};
   Double_t gNuclearModification_fehx3002[9] = {
   0.5,
   0.5,
   0.5,
   0.5,
   1,
   1,
   1.25,
   1.25,
   2.5};
   Double_t gNuclearModification_fehy3002[9] = {
   0.1385446,
   0.08615785,
   0.06750189,
   0.05013722,
   0.04752139,
   0.04884336,
   0.05908503,
   0.05758429,
   0.07618566};
   grae = new TGraphAsymmErrors(9,gNuclearModification_fx3002,gNuclearModification_fy3002,gNuclearModification_felx3002,gNuclearModification_fehx3002,gNuclearModification_fely3002,gNuclearModification_fehy3002);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = 928;
   color = new TColor(ci, 0.6, 1, 0.6, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_gNuclearModification30023002 = new TH1F("Graph_Graph_gNuclearModification30023002","Graph",100,0.2,21.8);
   Graph_Graph_gNuclearModification30023002->SetMinimum(0.1593298);
   Graph_Graph_gNuclearModification30023002->SetMaximum(0.8255854);
   Graph_Graph_gNuclearModification30023002->SetDirectory(0);
   Graph_Graph_gNuclearModification30023002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_gNuclearModification30023002->SetLineColor(ci);
   Graph_Graph_gNuclearModification30023002->SetMarkerStyle(20);
   Graph_Graph_gNuclearModification30023002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30023002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30023002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30023002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30023002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30023002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30023002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_gNuclearModification30023002);
   
   grae->Draw("5");
   Double_t xAxis2[6] = {20, 25, 30, 40, 60, 100}; 
   
   TH1D *hNuclearModification2_DRAA13 = new TH1D("hNuclearModification2_DRAA13","",5, xAxis2);
   hNuclearModification2_DRAA13->SetBinContent(1,0.4279886);
   hNuclearModification2_DRAA13->SetBinContent(2,0.4447959);
   hNuclearModification2_DRAA13->SetBinContent(3,0.5041472);
   hNuclearModification2_DRAA13->SetBinContent(4,0.6796131);
   hNuclearModification2_DRAA13->SetBinContent(5,0.7424828);
   hNuclearModification2_DRAA13->SetBinError(1,0.05025093);
   hNuclearModification2_DRAA13->SetBinError(2,0.04192271);
   hNuclearModification2_DRAA13->SetBinError(3,0.04691724);
   hNuclearModification2_DRAA13->SetBinError(4,0.03941607);
   hNuclearModification2_DRAA13->SetBinError(5,0.07611912);
   hNuclearModification2_DRAA13->SetEntries(566.4226);
   hNuclearModification2_DRAA13->SetStats(0);
   hNuclearModification2_DRAA13->SetLineWidth(3);

   ci = TColor::GetColor("#006600");
   hNuclearModification2_DRAA13->SetMarkerColor(ci);
   hNuclearModification2_DRAA13->SetMarkerStyle(21);
   hNuclearModification2_DRAA13->SetMarkerSize(1.2);
   hNuclearModification2_DRAA13->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_DRAA13->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA13->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA13->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA13->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA13->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_DRAA13->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA13->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA13->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA13->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA13->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA13->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA13->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA13->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA13->Draw("psame");
   Double_t xAxis3[10] = {2, 3, 4, 5, 6, 8, 10, 12.5, 15, 20}; 
   
   TH1D *hNuclearModification3_DRAA14 = new TH1D("hNuclearModification3_DRAA14","",9, xAxis3);
   hNuclearModification3_DRAA14->SetBinContent(1,0.6315195);
   hNuclearModification3_DRAA14->SetBinContent(2,0.4432341);
   hNuclearModification3_DRAA14->SetBinContent(3,0.3674997);
   hNuclearModification3_DRAA14->SetBinContent(4,0.2758138);
   hNuclearModification3_DRAA14->SetBinContent(5,0.2623725);
   hNuclearModification3_DRAA14->SetBinContent(6,0.2722143);
   hNuclearModification3_DRAA14->SetBinContent(7,0.3291268);
   hNuclearModification3_DRAA14->SetBinContent(8,0.3207651);
   hNuclearModification3_DRAA14->SetBinContent(9,0.3937182);
   hNuclearModification3_DRAA14->SetBinError(1,0.1116572);
   hNuclearModification3_DRAA14->SetBinError(2,0.04535789);
   hNuclearModification3_DRAA14->SetBinError(3,0.03419174);
   hNuclearModification3_DRAA14->SetBinError(4,0.02501397);
   hNuclearModification3_DRAA14->SetBinError(5,0.01804332);
   hNuclearModification3_DRAA14->SetBinError(6,0.01714575);
   hNuclearModification3_DRAA14->SetBinError(7,0.02192858);
   hNuclearModification3_DRAA14->SetBinError(8,0.03017596);
   hNuclearModification3_DRAA14->SetBinError(9,0.04454357);
   hNuclearModification3_DRAA14->SetEntries(534.8555);
   hNuclearModification3_DRAA14->SetStats(0);
   hNuclearModification3_DRAA14->SetLineWidth(3);

   ci = TColor::GetColor("#006600");
   hNuclearModification3_DRAA14->SetMarkerColor(ci);
   hNuclearModification3_DRAA14->SetMarkerStyle(21);
   hNuclearModification3_DRAA14->SetMarkerSize(1.2);
   hNuclearModification3_DRAA14->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification3_DRAA14->GetXaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA14->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA14->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA14->GetXaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA14->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification3_DRAA14->GetYaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA14->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA14->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA14->GetYaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA14->GetZaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA14->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA14->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA14->GetZaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA14->Draw("psame");
   box = new TBox(0.608,0.9586116,0.74,1.045662);

   ci = 930;
   color = new TColor(ci, 0.6, 1, 0.6, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#99ff99");
   box->SetLineColor(ci);
   box->Draw();
   
   Double_t gNuclearModification_Bp_fx3003[5] = {
   8.5,
   12.5,
   17.5,
   25,
   40};
   Double_t gNuclearModification_Bp_fy3003[5] = {
   0.3458558,
   0.4480066,
   0.4402087,
   0.615181,
   0.3486562};
   Double_t gNuclearModification_Bp_felx3003[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fely3003[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   Double_t gNuclearModification_Bp_fehx3003[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fehy3003[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   grae = new TGraphAsymmErrors(5,gNuclearModification_Bp_fx3003,gNuclearModification_Bp_fy3003,gNuclearModification_Bp_felx3003,gNuclearModification_Bp_fehx3003,gNuclearModification_Bp_fely3003,gNuclearModification_Bp_fehy3003);
   grae->SetName("gNuclearModification_Bp");
   grae->SetTitle("Graph");
   grae->SetFillColor(111);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#0033cc");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph_gNuclearModification30013003 = new TH1F("Graph_Graph_gNuclearModification30013003","Graph",100,2.7,54.3);
   Graph_Graph_gNuclearModification30013003->SetMinimum(0.2364759);
   Graph_Graph_gNuclearModification30013003->SetMaximum(0.7605233);
   Graph_Graph_gNuclearModification30013003->SetDirectory(0);
   Graph_Graph_gNuclearModification30013003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_gNuclearModification30013003->SetLineColor(ci);
   Graph_Graph_gNuclearModification30013003->SetMarkerStyle(20);
   Graph_Graph_gNuclearModification30013003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_gNuclearModification30013003);
   
   grae->Draw("5");
   Double_t xAxis4[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp5 = new TH1D("hNuclearModification2_Bp5","",5, xAxis4);
   hNuclearModification2_Bp5->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp5->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp5->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp5->SetBinContent(4,0.615181);
   hNuclearModification2_Bp5->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp5->SetBinError(1,0.1086955);
   hNuclearModification2_Bp5->SetBinError(2,0.07447295);
   hNuclearModification2_Bp5->SetBinError(3,0.07507186);
   hNuclearModification2_Bp5->SetBinError(4,0.09192405);
   hNuclearModification2_Bp5->SetBinError(5,0.1120147);
   hNuclearModification2_Bp5->SetEntries(109.8058);
   hNuclearModification2_Bp5->SetDirectory(0);
   hNuclearModification2_Bp5->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp5->SetLineColor(ci);
   hNuclearModification2_Bp5->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp5->SetMarkerColor(ci);
   hNuclearModification2_Bp5->SetMarkerStyle(21);
   hNuclearModification2_Bp5->SetMarkerSize(1.2);
   hNuclearModification2_Bp5->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp5->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp5->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp5->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp5->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp5->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp5->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp5->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp5->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp5->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp5->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp5->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp5->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp5->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp5->Draw("same");
   box = new TBox(0.92,0.9586116,1.1,1.045662);

   ci = 933;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#0099ff");
   box->SetLineColor(ci);
   box->Draw();
   
   Double_t Graph0_fx1001[6] = {
   7.5,
   9,
   10.25,
   12,
   14.5,
   23};
   Double_t Graph0_fy1001[6] = {
   0.4664189,
   0.4856157,
   0.4065521,
   0.4536073,
   0.3694549,
   0.3521646};
   Double_t Graph0_fex1001[6] = {
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t Graph0_fey1001[6] = {
   0.05427119,
   0.04438349,
   0.03578226,
   0.05860495,
   0.0518269,
   0.06848064};
   TGraphErrors *gre = new TGraphErrors(6,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");

   ci = 934;
   color = new TColor(ci, 0.4, 0.4, 0.4, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph11001 = new TH1F("Graph_Graph_Graph11001","Graph",100,5.35,25.15);
   Graph_Graph_Graph11001->SetMinimum(0.2590524);
   Graph_Graph_Graph11001->SetMaximum(0.5546307);
   Graph_Graph_Graph11001->SetDirectory(0);
   Graph_Graph_Graph11001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph11001->SetLineColor(ci);
   Graph_Graph_Graph11001->SetLineStyle(0);
   Graph_Graph_Graph11001->SetMarkerStyle(20);
   Graph_Graph_Graph11001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph11001->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph11001->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph11001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph11001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph11001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph11001->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph11001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph11001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph11001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph11001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph11001);
   
   gre->Draw("2");
   
   Double_t Graph1_fx1002[6] = {
   7.5,
   9,
   10.25,
   12,
   14.5,
   23};
   Double_t Graph1_fy1002[6] = {
   0.4664189,
   0.4856157,
   0.4065521,
   0.4536073,
   0.3694549,
   0.3521646};
   Double_t Graph1_fex1002[6] = {
   1,
   0.5,
   0.75,
   1,
   1.5,
   7};
   Double_t Graph1_fey1002[6] = {
   0.02632702,
   0.0353226,
   0.0288783,
   0.03347202,
   0.03358354,
   0.0311077};
   gre = new TGraphErrors(6,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#333333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(29);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph_Graph21002 = new TH1F("Graph_Graph_Graph21002","Graph",100,4.15,32.35);
   Graph_Graph_Graph21002->SetMinimum(0.3010687);
   Graph_Graph_Graph21002->SetMaximum(0.5409264);
   Graph_Graph_Graph21002->SetDirectory(0);
   Graph_Graph_Graph21002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph21002->SetLineColor(ci);
   Graph_Graph_Graph21002->SetLineStyle(0);
   Graph_Graph_Graph21002->SetMarkerStyle(20);
   Graph_Graph_Graph21002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph21002->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21002->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21002->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph21002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph21002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph21002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21002->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21002->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph21002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph21002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph21002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21002->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph21002);
   
   gre->Draw("p");
   
   Double_t Graph3_fx1003[3] = {
   3.75,
   5,
   6};
   Double_t Graph3_fy1003[3] = {
   0.7535804,
   0.6891029,
   0.5425812};
   Double_t Graph3_fex1003[3] = {
   0.4,
   0.4,
   0.4};
   Double_t Graph3_fey1003[3] = {
   0.21432,
   0.1218303,
   0.08921681};
   gre = new TGraphErrors(3,Graph3_fx1003,Graph3_fy1003,Graph3_fex1003,Graph3_fey1003);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");

   ci = 935;
   color = new TColor(ci, 0.4, 0.4, 0.4, " ", 0.5);
   gre->SetFillColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph41003 = new TH1F("Graph_Graph_Graph41003","Graph",100,3.045,6.705);
   Graph_Graph_Graph41003->SetMinimum(0.4019107);
   Graph_Graph_Graph41003->SetMaximum(1.019354);
   Graph_Graph_Graph41003->SetDirectory(0);
   Graph_Graph_Graph41003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph41003->SetLineColor(ci);
   Graph_Graph_Graph41003->SetLineStyle(0);
   Graph_Graph_Graph41003->SetMarkerStyle(20);
   Graph_Graph_Graph41003->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph41003->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph41003->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph41003->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph41003->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph41003->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph41003->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph41003->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph41003->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph41003->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph41003->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph41003->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph41003->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph41003->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph41003->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph41003->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph41003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph41003);
   
   gre->Draw("2");
   
   Double_t Graph4_fx1004[3] = {
   3.75,
   5,
   6};
   Double_t Graph4_fy1004[3] = {
   0.7535804,
   0.6891029,
   0.5425812};
   Double_t Graph4_fex1004[3] = {
   0.75,
   0.5,
   0.5};
   Double_t Graph4_fey1004[3] = {
   0.1209346,
   0.1059286,
   0.07363414};
   gre = new TGraphErrors(3,Graph4_fx1004,Graph4_fy1004,Graph4_fex1004,Graph4_fey1004);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#333333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(34);
   gre->SetMarkerSize(1.7);
   
   TH1F *Graph_Graph_Graph51004 = new TH1F("Graph_Graph_Graph51004","Graph",100,2.65,6.85);
   Graph_Graph_Graph51004->SetMinimum(0.4283902);
   Graph_Graph_Graph51004->SetMaximum(0.9150718);
   Graph_Graph_Graph51004->SetDirectory(0);
   Graph_Graph_Graph51004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph51004->SetLineColor(ci);
   Graph_Graph_Graph51004->SetLineStyle(0);
   Graph_Graph_Graph51004->SetMarkerStyle(20);
   Graph_Graph_Graph51004->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph51004->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51004->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51004->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph51004->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph51004->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph51004->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51004->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph51004->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph51004->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph51004->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51004->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph51004);
   
   gre->Draw("p");
   box = new TBox(1.1,0.9249388,1.34,1.075061);

   ci = 938;
   color = new TColor(ci, 0.4, 0.4, 0.4, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#666666");
   box->SetLineColor(ci);
   box->Draw();
   
   TLegend *leg = new TLegend(0.35,0.55,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","charged hadrons |y| < 1.0","pf");

   ci = TColor::GetColor("#ffcc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.035);
   entry=leg->AddEntry("","D^{0} |y| < 1.0","pf");

   ci = 929;
   color = new TColor(ci, 0.6, 1, 0.6, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#006600");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.035);
   entry=leg->AddEntry("gNuclearModification_UnCor","B^{0}_{s} R_{AA}","pf");

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
   entry->SetTextSize(0.035);
   entry=leg->AddEntry("","B^{+} R_{AA}","pf");

   ci = 932;
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
   entry->SetTextSize(0.035);
   entry=leg->AddEntry("","nonprompt J/#psi 1.6 < |y| < 2.4 (2.76 TeV)","pf");

   ci = 936;
   color = new TColor(ci, 0.4, 0.4, 0.4, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#333333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry->SetTextSize(0.035);
   entry=leg->AddEntry("","nonprompt J/#psi |y| < 2.4 (2.76 TeV)","pf");

   ci = 937;
   color = new TColor(ci, 0.4, 0.4, 0.4, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#333333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry->SetTextSize(0.035);
   leg->Draw();
   
   Double_t gNuclearModification_fx3004[2] = {
   11,
   32.5};
   Double_t gNuclearModification_fy3004[2] = {
   1.507894,
   0.8738383};
   Double_t gNuclearModification_felx3004[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fely3004[2] = {
   0.4953364,
   0.1654302};
   Double_t gNuclearModification_fehx3004[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fehy3004[2] = {
   0.4953364,
   0.1654302};
   grae = new TGraphAsymmErrors(2,gNuclearModification_fx3004,gNuclearModification_fy3004,gNuclearModification_felx3004,gNuclearModification_fehx3004,gNuclearModification_fely3004,gNuclearModification_fehy3004);
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
   
   TH1F *Graph_gNuclearModification3004 = new TH1F("Graph_gNuclearModification3004","Graph",100,2.7,54.3);
   Graph_gNuclearModification3004->SetMinimum(0.5789259);
   Graph_gNuclearModification3004->SetMaximum(2.132713);
   Graph_gNuclearModification3004->SetDirectory(0);
   Graph_gNuclearModification3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3004->SetLineColor(ci);
   Graph_gNuclearModification3004->SetMarkerStyle(20);
   Graph_gNuclearModification3004->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3004->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3004->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3004->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3004->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3004->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3004->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3004->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3004->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3004->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3004->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3004);
   
   grae->Draw("5");
   Double_t xAxis5[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100584__2__2__26 = new TH1D("RAA_0_100584__2__2__26","",37, xAxis5);
   RAA_0_100584__2__2__26->SetBinContent(1,-1);
   RAA_0_100584__2__2__26->SetBinContent(2,-1);
   RAA_0_100584__2__2__26->SetBinContent(3,0.3605047);
   RAA_0_100584__2__2__26->SetBinContent(4,0.3850582);
   RAA_0_100584__2__2__26->SetBinContent(5,0.4188398);
   RAA_0_100584__2__2__26->SetBinContent(6,0.4411318);
   RAA_0_100584__2__2__26->SetBinContent(7,0.4564881);
   RAA_0_100584__2__2__26->SetBinContent(8,0.4798668);
   RAA_0_100584__2__2__26->SetBinContent(9,0.4985427);
   RAA_0_100584__2__2__26->SetBinContent(10,0.516094);
   RAA_0_100584__2__2__26->SetBinContent(11,0.5160761);
   RAA_0_100584__2__2__26->SetBinContent(12,0.5157593);
   RAA_0_100584__2__2__26->SetBinContent(13,0.5090351);
   RAA_0_100584__2__2__26->SetBinContent(14,0.4718224);
   RAA_0_100584__2__2__26->SetBinContent(15,0.381288);
   RAA_0_100584__2__2__26->SetBinContent(16,0.3016595);
   RAA_0_100584__2__2__26->SetBinContent(17,0.2568378);
   RAA_0_100584__2__2__26->SetBinContent(18,0.2362394);
   RAA_0_100584__2__2__26->SetBinContent(19,0.2313929);
   RAA_0_100584__2__2__26->SetBinContent(20,0.2397292);
   RAA_0_100584__2__2__26->SetBinContent(21,0.2795414);
   RAA_0_100584__2__2__26->SetBinContent(22,0.3109757);
   RAA_0_100584__2__2__26->SetBinContent(23,0.359047);
   RAA_0_100584__2__2__26->SetBinContent(24,0.4103232);
   RAA_0_100584__2__2__26->SetBinContent(25,0.4535739);
   RAA_0_100584__2__2__26->SetBinContent(26,0.4871136);
   RAA_0_100584__2__2__26->SetBinContent(27,0.5390386);
   RAA_0_100584__2__2__26->SetBinContent(28,0.6064001);
   RAA_0_100584__2__2__26->SetBinContent(29,0.6583816);
   RAA_0_100584__2__2__26->SetBinContent(30,0.6914895);
   RAA_0_100584__2__2__26->SetBinContent(31,0.7510186);
   RAA_0_100584__2__2__26->SetBinContent(32,0.8027461);
   RAA_0_100584__2__2__26->SetBinContent(33,0.8064291);
   RAA_0_100584__2__2__26->SetBinContent(34,0.8144861);
   RAA_0_100584__2__2__26->SetBinContent(35,0.8835603);
   RAA_0_100584__2__2__26->SetBinContent(36,0.9077175);
   RAA_0_100584__2__2__26->SetBinContent(37,0.8767255);
   RAA_0_100584__2__2__26->SetBinError(1,1.279903e-05);
   RAA_0_100584__2__2__26->SetBinError(2,1.387861e-05);
   RAA_0_100584__2__2__26->SetBinError(3,1.439234e-05);
   RAA_0_100584__2__2__26->SetBinError(4,1.673993e-05);
   RAA_0_100584__2__2__26->SetBinError(5,1.996438e-05);
   RAA_0_100584__2__2__26->SetBinError(6,2.296277e-05);
   RAA_0_100584__2__2__26->SetBinError(7,2.652961e-05);
   RAA_0_100584__2__2__26->SetBinError(8,2.303589e-05);
   RAA_0_100584__2__2__26->SetBinError(9,2.956636e-05);
   RAA_0_100584__2__2__26->SetBinError(10,3.708897e-05);
   RAA_0_100584__2__2__26->SetBinError(11,4.504344e-05);
   RAA_0_100584__2__2__26->SetBinError(12,5.385318e-05);
   RAA_0_100584__2__2__26->SetBinError(13,6.332594e-05);
   RAA_0_100584__2__2__26->SetBinError(14,4.278537e-05);
   RAA_0_100584__2__2__26->SetBinError(15,6.266848e-05);
   RAA_0_100584__2__2__26->SetBinError(16,8.299302e-05);
   RAA_0_100584__2__2__26->SetBinError(17,0.0001099248);
   RAA_0_100584__2__2__26->SetBinError(18,0.0001477243);
   RAA_0_100584__2__2__26->SetBinError(19,0.0002002684);
   RAA_0_100584__2__2__26->SetBinError(20,0.0001962782);
   RAA_0_100584__2__2__26->SetBinError(21,0.00043599);
   RAA_0_100584__2__2__26->SetBinError(22,0.0007955915);
   RAA_0_100584__2__2__26->SetBinError(23,0.001121086);
   RAA_0_100584__2__2__26->SetBinError(24,0.002349183);
   RAA_0_100584__2__2__26->SetBinError(25,0.003934258);
   RAA_0_100584__2__2__26->SetBinError(26,0.005431548);
   RAA_0_100584__2__2__26->SetBinError(27,0.007593713);
   RAA_0_100584__2__2__26->SetBinError(28,0.008532134);
   RAA_0_100584__2__2__26->SetBinError(29,0.006423681);
   RAA_0_100584__2__2__26->SetBinError(30,0.009668077);
   RAA_0_100584__2__2__26->SetBinError(31,0.009013466);
   RAA_0_100584__2__2__26->SetBinError(32,0.01230905);
   RAA_0_100584__2__2__26->SetBinError(33,0.01985833);
   RAA_0_100584__2__2__26->SetBinError(34,0.02497965);
   RAA_0_100584__2__2__26->SetBinError(35,0.04145952);
   RAA_0_100584__2__2__26->SetBinError(36,0.0459072);
   RAA_0_100584__2__2__26->SetBinError(37,0.152905);
   RAA_0_100584__2__2__26->SetMinimum(0);
   RAA_0_100584__2__2__26->SetMaximum(1.8);
   RAA_0_100584__2__2__26->SetEntries(11078.9);
   RAA_0_100584__2__2__26->SetDirectory(0);
   RAA_0_100584__2__2__26->SetStats(0);

   ci = TColor::GetColor("#ffcc00");
   RAA_0_100584__2__2__26->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   RAA_0_100584__2__2__26->SetLineColor(ci);
   RAA_0_100584__2__2__26->SetLineWidth(2);
   RAA_0_100584__2__2__26->SetMarkerStyle(20);
   RAA_0_100584__2__2__26->SetMarkerSize(1.3);
   RAA_0_100584__2__2__26->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100584__2__2__26->GetXaxis()->SetRange(1,37);
   RAA_0_100584__2__2__26->GetXaxis()->CenterTitle(true);
   RAA_0_100584__2__2__26->GetXaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__26->GetXaxis()->SetLabelOffset(-0.002);
   RAA_0_100584__2__2__26->GetXaxis()->SetLabelSize(0.045);
   RAA_0_100584__2__2__26->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100584__2__2__26->GetXaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__26->GetYaxis()->SetTitle("R_{AA}, R_{pA}");
   RAA_0_100584__2__2__26->GetYaxis()->CenterTitle(true);
   RAA_0_100584__2__2__26->GetYaxis()->SetNdivisions(508);
   RAA_0_100584__2__2__26->GetYaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__26->GetYaxis()->SetLabelSize(0.045);
   RAA_0_100584__2__2__26->GetYaxis()->SetTitleSize(0.05);
   RAA_0_100584__2__2__26->GetYaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__26->GetZaxis()->SetLabelFont(42);
   RAA_0_100584__2__2__26->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100584__2__2__26->GetZaxis()->SetTitleSize(0.09);
   RAA_0_100584__2__2__26->GetZaxis()->SetTitleFont(42);
   RAA_0_100584__2__2__26->Draw("same");
   Double_t xAxis6[6] = {20, 25, 30, 40, 60, 100}; 
   
   TH1D *hNuclearModification2_DRAA27 = new TH1D("hNuclearModification2_DRAA27","",5, xAxis6);
   hNuclearModification2_DRAA27->SetBinContent(1,0.4279886);
   hNuclearModification2_DRAA27->SetBinContent(2,0.4447959);
   hNuclearModification2_DRAA27->SetBinContent(3,0.5041472);
   hNuclearModification2_DRAA27->SetBinContent(4,0.6796131);
   hNuclearModification2_DRAA27->SetBinContent(5,0.7424828);
   hNuclearModification2_DRAA27->SetBinError(1,0.05025093);
   hNuclearModification2_DRAA27->SetBinError(2,0.04192271);
   hNuclearModification2_DRAA27->SetBinError(3,0.04691724);
   hNuclearModification2_DRAA27->SetBinError(4,0.03941607);
   hNuclearModification2_DRAA27->SetBinError(5,0.07611912);
   hNuclearModification2_DRAA27->SetEntries(566.4226);
   hNuclearModification2_DRAA27->SetStats(0);
   hNuclearModification2_DRAA27->SetLineWidth(3);

   ci = TColor::GetColor("#006600");
   hNuclearModification2_DRAA27->SetMarkerColor(ci);
   hNuclearModification2_DRAA27->SetMarkerStyle(21);
   hNuclearModification2_DRAA27->SetMarkerSize(1.2);
   hNuclearModification2_DRAA27->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_DRAA27->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA27->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA27->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA27->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA27->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_DRAA27->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA27->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA27->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA27->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA27->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_DRAA27->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_DRAA27->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_DRAA27->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_DRAA27->Draw("psame");
   Double_t xAxis7[10] = {2, 3, 4, 5, 6, 8, 10, 12.5, 15, 20}; 
   
   TH1D *hNuclearModification3_DRAA28 = new TH1D("hNuclearModification3_DRAA28","",9, xAxis7);
   hNuclearModification3_DRAA28->SetBinContent(1,0.6315195);
   hNuclearModification3_DRAA28->SetBinContent(2,0.4432341);
   hNuclearModification3_DRAA28->SetBinContent(3,0.3674997);
   hNuclearModification3_DRAA28->SetBinContent(4,0.2758138);
   hNuclearModification3_DRAA28->SetBinContent(5,0.2623725);
   hNuclearModification3_DRAA28->SetBinContent(6,0.2722143);
   hNuclearModification3_DRAA28->SetBinContent(7,0.3291268);
   hNuclearModification3_DRAA28->SetBinContent(8,0.3207651);
   hNuclearModification3_DRAA28->SetBinContent(9,0.3937182);
   hNuclearModification3_DRAA28->SetBinError(1,0.1116572);
   hNuclearModification3_DRAA28->SetBinError(2,0.04535789);
   hNuclearModification3_DRAA28->SetBinError(3,0.03419174);
   hNuclearModification3_DRAA28->SetBinError(4,0.02501397);
   hNuclearModification3_DRAA28->SetBinError(5,0.01804332);
   hNuclearModification3_DRAA28->SetBinError(6,0.01714575);
   hNuclearModification3_DRAA28->SetBinError(7,0.02192858);
   hNuclearModification3_DRAA28->SetBinError(8,0.03017596);
   hNuclearModification3_DRAA28->SetBinError(9,0.04454357);
   hNuclearModification3_DRAA28->SetEntries(534.8555);
   hNuclearModification3_DRAA28->SetStats(0);
   hNuclearModification3_DRAA28->SetLineWidth(3);

   ci = TColor::GetColor("#006600");
   hNuclearModification3_DRAA28->SetMarkerColor(ci);
   hNuclearModification3_DRAA28->SetMarkerStyle(21);
   hNuclearModification3_DRAA28->SetMarkerSize(1.2);
   hNuclearModification3_DRAA28->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification3_DRAA28->GetXaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA28->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA28->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA28->GetXaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA28->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification3_DRAA28->GetYaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA28->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA28->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA28->GetYaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA28->GetZaxis()->SetLabelFont(42);
   hNuclearModification3_DRAA28->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification3_DRAA28->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification3_DRAA28->GetZaxis()->SetTitleFont(42);
   hNuclearModification3_DRAA28->Draw("psame");
   Double_t xAxis8[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp9 = new TH1D("hNuclearModification2_Bp9","",5, xAxis8);
   hNuclearModification2_Bp9->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp9->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp9->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp9->SetBinContent(4,0.615181);
   hNuclearModification2_Bp9->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp9->SetBinError(1,0.1086955);
   hNuclearModification2_Bp9->SetBinError(2,0.07447295);
   hNuclearModification2_Bp9->SetBinError(3,0.07507186);
   hNuclearModification2_Bp9->SetBinError(4,0.09192405);
   hNuclearModification2_Bp9->SetBinError(5,0.1120147);
   hNuclearModification2_Bp9->SetEntries(109.8058);
   hNuclearModification2_Bp9->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp9->SetLineColor(ci);
   hNuclearModification2_Bp9->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp9->SetMarkerColor(ci);
   hNuclearModification2_Bp9->SetMarkerStyle(21);
   hNuclearModification2_Bp9->SetMarkerSize(1.2);
   hNuclearModification2_Bp9->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp9->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp9->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp9->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp9->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp9->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp9->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp9->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp9->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp9->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp9->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp9->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp9->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp9->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp9->Draw("same");
   
   Double_t Graph0_fx1005[6] = {
   7.5,
   9,
   10.25,
   12,
   14.5,
   23};
   Double_t Graph0_fy1005[6] = {
   0.4664189,
   0.4856157,
   0.4065521,
   0.4536073,
   0.3694549,
   0.3521646};
   Double_t Graph0_fex1005[6] = {
   1,
   0.5,
   0.75,
   1,
   1.5,
   7};
   Double_t Graph0_fey1005[6] = {
   0.02632702,
   0.0353226,
   0.0288783,
   0.03347202,
   0.03358354,
   0.0311077};
   gre = new TGraphErrors(6,Graph0_fx1005,Graph0_fy1005,Graph0_fex1005,Graph0_fey1005);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#333333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(29);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph_Graph21005 = new TH1F("Graph_Graph_Graph21005","Graph",100,4.15,32.35);
   Graph_Graph_Graph21005->SetMinimum(0.3010687);
   Graph_Graph_Graph21005->SetMaximum(0.5409264);
   Graph_Graph_Graph21005->SetDirectory(0);
   Graph_Graph_Graph21005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph21005->SetLineColor(ci);
   Graph_Graph_Graph21005->SetLineStyle(0);
   Graph_Graph_Graph21005->SetMarkerStyle(20);
   Graph_Graph_Graph21005->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph21005->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21005->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21005->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21005->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph21005->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph21005->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph21005->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21005->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21005->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21005->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph21005->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph21005->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph21005->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph21005->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph21005->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph21005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph21005);
   
   gre->Draw("p");
   
   Double_t Graph1_fx1006[3] = {
   3.75,
   5,
   6};
   Double_t Graph1_fy1006[3] = {
   0.7535804,
   0.6891029,
   0.5425812};
   Double_t Graph1_fex1006[3] = {
   0.75,
   0.5,
   0.5};
   Double_t Graph1_fey1006[3] = {
   0.1209346,
   0.1059286,
   0.07363414};
   gre = new TGraphErrors(3,Graph1_fx1006,Graph1_fy1006,Graph1_fex1006,Graph1_fey1006);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#333333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(34);
   gre->SetMarkerSize(1.7);
   
   TH1F *Graph_Graph_Graph51006 = new TH1F("Graph_Graph_Graph51006","Graph",100,2.65,6.85);
   Graph_Graph_Graph51006->SetMinimum(0.4283902);
   Graph_Graph_Graph51006->SetMaximum(0.9150718);
   Graph_Graph_Graph51006->SetDirectory(0);
   Graph_Graph_Graph51006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph51006->SetLineColor(ci);
   Graph_Graph_Graph51006->SetLineStyle(0);
   Graph_Graph_Graph51006->SetMarkerStyle(20);
   Graph_Graph_Graph51006->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph51006->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51006->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51006->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51006->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph51006->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph51006->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph51006->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51006->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51006->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51006->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph51006->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph51006->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph51006->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph51006->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph51006->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph51006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph51006);
   
   gre->Draw("p");
   Double_t xAxis9[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification10 = new TH1D("hNuclearModification10","",2, xAxis9);
   hNuclearModification10->SetBinContent(1,1.507894);
   hNuclearModification10->SetBinContent(2,0.8738383);
   hNuclearModification10->SetBinError(1,0.6052666);
   hNuclearModification10->SetBinError(2,0.3033643);
   hNuclearModification10->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification10->SetLineColor(ci);
   hNuclearModification10->SetLineStyle(0);
   hNuclearModification10->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification10->SetMarkerColor(ci);
   hNuclearModification10->SetMarkerStyle(33);
   hNuclearModification10->SetMarkerSize(2.2);
   hNuclearModification10->GetXaxis()->SetLabelFont(42);
   hNuclearModification10->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification10->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification10->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification10->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification10->GetXaxis()->SetTitleFont(42);
   hNuclearModification10->GetYaxis()->SetLabelFont(42);
   hNuclearModification10->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification10->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification10->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification10->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification10->GetYaxis()->SetTitleFont(42);
   hNuclearModification10->GetZaxis()->SetLabelFont(42);
   hNuclearModification10->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification10->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification10->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification10->GetZaxis()->SetTitleFont(42);
   hNuclearModification10->Draw("same p");
   Double_t xAxis10[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification11 = new TH1D("hNuclearModification11","",2, xAxis10);
   hNuclearModification11->SetBinContent(1,1.507894);
   hNuclearModification11->SetBinContent(2,0.8738383);
   hNuclearModification11->SetBinError(1,0.6052666);
   hNuclearModification11->SetBinError(2,0.3033643);
   hNuclearModification11->SetEntries(12.3755);

   ci = TColor::GetColor("#990099");
   hNuclearModification11->SetLineColor(ci);
   hNuclearModification11->SetLineStyle(0);
   hNuclearModification11->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification11->SetMarkerColor(ci);
   hNuclearModification11->SetMarkerStyle(33);
   hNuclearModification11->SetMarkerSize(2.2);
   hNuclearModification11->GetXaxis()->SetLabelFont(42);
   hNuclearModification11->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification11->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification11->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification11->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification11->GetXaxis()->SetTitleFont(42);
   hNuclearModification11->GetYaxis()->SetLabelFont(42);
   hNuclearModification11->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification11->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification11->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification11->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification11->GetYaxis()->SetTitleFont(42);
   hNuclearModification11->GetZaxis()->SetLabelFont(42);
   hNuclearModification11->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification11->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification11->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification11->GetZaxis()->SetTitleFont(42);
   hNuclearModification11->Draw("same");
   box = new TBox(0.74,0.9586116,0.92,1.045662);

   ci = 931;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#cc33cc");
   box->SetLineColor(ci);
   box->Draw();
   
   TH2F *hemptyEff_copy12 = new TH2F("hemptyEff_copy12","",50,0.5,600,10,0,4);
   hemptyEff_copy12->SetMinimum(0);
   hemptyEff_copy12->SetMaximum(2);
   hemptyEff_copy12->SetDirectory(0);
   hemptyEff_copy12->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy12->SetLineColor(ci);
   hemptyEff_copy12->SetMarkerStyle(20);
   hemptyEff_copy12->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy12->GetXaxis()->CenterTitle(true);
   hemptyEff_copy12->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy12->GetXaxis()->SetLabelSize(0.048);
   hemptyEff_copy12->GetXaxis()->SetTitleSize(0.055);
   hemptyEff_copy12->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy12->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy12->GetYaxis()->CenterTitle(true);
   hemptyEff_copy12->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy12->GetYaxis()->SetLabelSize(0.048);
   hemptyEff_copy12->GetYaxis()->SetTitleSize(0.055);
   hemptyEff_copy12->GetYaxis()->SetTitleOffset(1.4);
   hemptyEff_copy12->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy12->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy12->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy12->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy12->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy12->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
