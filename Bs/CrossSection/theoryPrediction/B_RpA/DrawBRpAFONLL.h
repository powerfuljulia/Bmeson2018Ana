void DrawBRpAFONLL(){
   Double_t Graph0_fx3010[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph0_fy3010[5] = {
   1.111012,
   1.19193,
   0.9107678,
   0.857477,
   1.140866};
   Double_t Graph0_felx3010[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph0_fely3010[5] = {
   0.2932141,
   0.2782383,
   0.1891055,
   0.1603304,
   0.182098};
   Double_t Graph0_fehx3010[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph0_fehy3010[5] = {
   0.3324985,
   0.3123672,
   0.2114556,
   0.1794929,
   0.205514};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3010,Graph0_fy3010,Graph0_felx3010,Graph0_fehx3010,Graph0_fely3010,Graph0_fehy3010);
   grae->SetName("Graph0");
   grae->SetTitle("RpA syst uncertainty from FONLL reference");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0066ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerColor(4);
   
   TH1F *Graph_Graph3010 = new TH1F("Graph_Graph3010","RpA syst uncertainty from FONLL reference",100,5,65);
   Graph_Graph3010->SetMinimum(0.6164315);
   Graph_Graph3010->SetMaximum(1.585012);
   Graph_Graph3010->SetDirectory(0);
   Graph_Graph3010->SetStats(0);
   grae->SetHistogram(Graph_Graph3010);
   
   //grae->Draw("2");
   
   Double_t Graph1_fx3011[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph1_fy3011[5] = {
   1.111012,
   1.19193,
   0.9107678,
   0.857477,
   1.140866};
   Double_t Graph1_felx3011[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph1_fely3011[5] = {
   0.2932141,
   0.2782383,
   0.1891055,
   0.1603304,
   0.182098};
   Double_t Graph1_fehx3011[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t Graph1_fehy3011[5] = {
   0.3324985,
   0.3123672,
   0.2114556,
   0.1794929,
   0.205514};
   grae = new TGraphAsymmErrors(5,Graph1_fx3011,Graph1_fy3011,Graph1_felx3011,Graph1_fehx3011,Graph1_fely3011,Graph1_fehy3011);
   grae->SetName("Graph1");
   grae->SetTitle("RpA syst uncertainty from FONLL reference");
   grae->SetFillStyle(0);

   ci = TColor::GetColor("#0066ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3011 = new TH1F("Graph_Graph3011","RpA syst uncertainty from FONLL reference",100,5,65);
   Graph_Graph3011->SetMinimum(0.6164315);
   Graph_Graph3011->SetMaximum(1.585012);
   Graph_Graph3011->SetDirectory(0);
   Graph_Graph3011->SetStats(0);
   grae->SetHistogram(Graph_Graph3011);
   
   grae->Draw("2");
   
   Double_t gRpAsyst_fx3012[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t gRpAsyst_fy3012[5] = {
   1.111012,
   1.19193,
   0.9107678,
   0.857477,
   1.140866};
   Double_t gRpAsyst_felx3012[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fely3012[5] = {
   0.1666517,
   0.170446,
   0.1302398,
   0.1209043,
   0.1699891};
   Double_t gRpAsyst_fehx3012[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fehy3012[5] = {
   0.1666517,
   0.170446,
   0.1302398,
   0.1209043,
   0.1699891};
   grae = new TGraphAsymmErrors(5,gRpAsyst_fx3012,gRpAsyst_fy3012,gRpAsyst_felx3012,gRpAsyst_fehx3012,gRpAsyst_fely3012,gRpAsyst_fehy3012);
   grae->SetName("gRpAsyst");
   grae->SetTitle("RpA syst uncertainty from pPb");

   ci = TColor::GetColor("#ffff66");
   grae->SetFillColor(ci);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_gRpAsyst3012 = new TH1F("Graph_gRpAsyst3012","RpA syst uncertainty from pPb",100,5,65);
   Graph_gRpAsyst3012->SetMinimum(0.6739924);
   Graph_gRpAsyst3012->SetMaximum(1.424956);
   Graph_gRpAsyst3012->SetDirectory(0);
   Graph_gRpAsyst3012->SetStats(0);
   grae->SetHistogram(Graph_gRpAsyst3012);
   
   grae->Draw("2e");
   
   Double_t gRpAsyst_fx3013[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t gRpAsyst_fy3013[5] = {
   1.111012,
   1.19193,
   0.9107678,
   0.857477,
   1.140866};
   Double_t gRpAsyst_felx3013[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fely3013[5] = {
   0.1666517,
   0.170446,
   0.1302398,
   0.1209043,
   0.1699891};
   Double_t gRpAsyst_fehx3013[5] = {
   2.5,
   2.5,
   2.5,
   2.5,
   15};
   Double_t gRpAsyst_fehy3013[5] = {
   0.1666517,
   0.170446,
   0.1302398,
   0.1209043,
   0.1699891};
   grae = new TGraphAsymmErrors(5,gRpAsyst_fx3013,gRpAsyst_fy3013,gRpAsyst_felx3013,gRpAsyst_fehx3013,gRpAsyst_fely3013,gRpAsyst_fehy3013);
   grae->SetName("gRpAsyst");
   grae->SetTitle("RpA syst uncertainty from pPb");
   grae->SetFillStyle(0);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_gRpAsyst3013 = new TH1F("Graph_gRpAsyst3013","RpA syst uncertainty from pPb",100,5,65);
   Graph_gRpAsyst3013->SetMinimum(0.6739924);
   Graph_gRpAsyst3013->SetMaximum(1.424956);
   Graph_gRpAsyst3013->SetDirectory(0);
   Graph_gRpAsyst3013->SetStats(0);
   grae->SetHistogram(Graph_gRpAsyst3013);
   
   grae->Draw("2e");
   
   Double_t Graph2_fx3014[5] = {
   12.5,
   17.5,
   22.5,
   27.5,
   45};
   Double_t Graph2_fy3014[5] = {
   1.111012,
   1.19193,
   0.9107678,
   0.857477,
   1.140866};
   Double_t Graph2_felx3014[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fely3014[5] = {
   0.07915482,
   0.09844013,
   0.1194168,
   0.1763585,
   0.1862258};
   Double_t Graph2_fehx3014[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fehy3014[5] = {
   0.07915482,
   0.09844013,
   0.1194168,
   0.1763585,
   0.1862258};
   grae = new TGraphAsymmErrors(5,Graph2_fx3014,Graph2_fy3014,Graph2_felx3014,Graph2_fehx3014,Graph2_fely3014,Graph2_fehy3014);
   grae->SetName("Graph2");
   grae->SetTitle("RpA stat uncertainty from pPb");
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3014 = new TH1F("Graph_Graph3014","RpA stat uncertainty from pPb",100,9.25,48.25);
   Graph_Graph3014->SetMinimum(0.6165211);
   Graph_Graph3014->SetMaximum(1.39169);
   Graph_Graph3014->SetDirectory(0);
   Graph_Graph3014->SetStats(0);
   grae->SetHistogram(Graph_Graph3014);
   
   grae->Draw("p");
}

