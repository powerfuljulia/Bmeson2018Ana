void DrawBRpA(){
   Double_t Graph0_fx3004[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph0_fy3004[5] = {
   0.9659208,
   1.069293,
   0.7747728,
   0.876683,
   1.091473};
   Double_t Graph0_felx3004[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph0_fely3004[5] = {
   0.2548944,
   0.2495598,
   0.1608088,
   0.1639167,
   0.1742041};
   Double_t Graph0_fehx3004[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph0_fehy3004[5] = {
   0.2890554,
   0.2801409,
   0.1798253,
   0.1834407,
   0.1966067};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3004,Graph0_fy3004,Graph0_felx3004,Graph0_fehx3004,Graph0_fely3004,Graph0_fehy3004);
   grae->SetName("Graph0");
   grae->SetTitle("RpA syst uncertainty from FONLL reference");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerColor(4);
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","RpA syst uncertainty from FONLL reference",100,5,65);
   Graph_Graph3004->SetMinimum(0.5404171);
   Graph_Graph3004->SetMaximum(1.42298);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);
   grae->SetHistogram(Graph_Graph3004);
   
   //grae->Draw("2");
   
   Double_t Graph1_fx3005[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph1_fy3005[5] = {
   0.9659208,
   1.069293,
   0.7747728,
   0.876683,
   1.091473};
   Double_t Graph1_felx3005[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph1_fely3005[5] = {
   0.2548944,
   0.2495598,
   0.1608088,
   0.1639167,
   0.1742041};
   Double_t Graph1_fehx3005[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph1_fehy3005[5] = {
   0.2890554,
   0.2801409,
   0.1798253,
   0.1834407,
   0.1966067};
   grae = new TGraphAsymmErrors(5,Graph1_fx3005,Graph1_fy3005,Graph1_felx3005,Graph1_fehx3005,Graph1_fely3005,Graph1_fehy3005);
   grae->SetName("Graph1");
   grae->SetTitle("RpA syst uncertainty from FONLL reference");
   grae->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","RpA syst uncertainty from FONLL reference",100,5,65);
   Graph_Graph3005->SetMinimum(0.5404171);
   Graph_Graph3005->SetMaximum(1.42298);
   Graph_Graph3005->SetDirectory(0);
   Graph_Graph3005->SetStats(0);
   grae->SetHistogram(Graph_Graph3005);
   
   //grae->Draw("2");
   
   Double_t gRpAsyst_fx3006[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t gRpAsyst_fy3006[5] = {
   0.9659208,
   1.069293,
   0.7747728,
   0.876683,
   1.091473};
   Double_t gRpAsyst_felx3006[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fely3006[5] = {
   0.163786,
   0.1733856,
   0.1252511,
   0.1399525,
   0.1817517};
   Double_t gRpAsyst_fehx3006[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fehy3006[5] = {
   0.163786,
   0.1733856,
   0.1252511,
   0.1399525,
   0.1817517};
   grae = new TGraphAsymmErrors(5,gRpAsyst_fx3006,gRpAsyst_fy3006,gRpAsyst_felx3006,gRpAsyst_fehx3006,gRpAsyst_fely3006,gRpAsyst_fehy3006);
   grae->SetName("gRpAsyst");
   grae->SetTitle("RpA syst uncertainty from pPb");

   ci = TColor::GetColor("#ffff66");
   grae->SetFillColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_gRpAsyst3006 = new TH1F("Graph_gRpAsyst3006","RpA syst uncertainty from pPb",100,5,65);
   Graph_gRpAsyst3006->SetMinimum(0.5871515);
   Graph_gRpAsyst3006->SetMaximum(1.335595);
   Graph_gRpAsyst3006->SetDirectory(0);
   Graph_gRpAsyst3006->SetStats(0);
   grae->SetHistogram(Graph_gRpAsyst3006);
   
   grae->Draw("2e");
   
   Double_t gRpAsyst_fx3007[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t gRpAsyst_fy3007[5] = {
   0.9659208,
   1.069293,
   0.7747728,
   0.876683,
   1.091473};
   Double_t gRpAsyst_felx3007[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fely3007[5] = {
   0.163786,
   0.1733856,
   0.1252511,
   0.1399525,
   0.1817517};
   Double_t gRpAsyst_fehx3007[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fehy3007[5] = {
   0.163786,
   0.1733856,
   0.1252511,
   0.1399525,
   0.1817517};
   grae = new TGraphAsymmErrors(5,gRpAsyst_fx3007,gRpAsyst_fy3007,gRpAsyst_felx3007,gRpAsyst_fehx3007,gRpAsyst_fely3007,gRpAsyst_fehy3007);
   grae->SetName("gRpAsyst");
   grae->SetTitle("RpA syst uncertainty from pPb");
   grae->SetFillStyle(0);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_gRpAsyst3007 = new TH1F("Graph_gRpAsyst3007","RpA syst uncertainty from pPb",100,5,65);
   Graph_gRpAsyst3007->SetMinimum(0.5871515);
   Graph_gRpAsyst3007->SetMaximum(1.335595);
   Graph_gRpAsyst3007->SetDirectory(0);
   Graph_gRpAsyst3007->SetStats(0);
   grae->SetHistogram(Graph_gRpAsyst3007);
   
   grae->Draw("2e");
   
   Double_t Graph2_fx3008[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph2_fy3008[5] = {
   0.9659208,
   1.069293,
   0.7747728,
   0.876683,
   1.091473};
   Double_t Graph2_felx3008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fely3008[5] = {
   0.07848593,
   0.1010036,
   0.1124761,
   0.1993566,
   0.2048654};
   Double_t Graph2_fehx3008[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fehy3008[5] = {
   0.07848593,
   0.1010036,
   0.1124761,
   0.1993566,
   0.2048654};
   grae = new TGraphAsymmErrors(5,Graph2_fx3008,Graph2_fy3008,Graph2_felx3008,Graph2_fehx3008,Graph2_fely3008,Graph2_fehy3008);
   grae->SetName("Graph2");
   grae->SetTitle("RpA stat uncertainty from pPb");
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","RpA stat uncertainty from pPb",100,9.25,48.25);
   Graph_Graph3008->SetMinimum(0.5988927);
   Graph_Graph3008->SetMaximum(1.359742);
   Graph_Graph3008->SetDirectory(0);
   Graph_Graph3008->SetStats(0);
   grae->SetHistogram(Graph_Graph3008);
   
   grae->Draw("p");
}

