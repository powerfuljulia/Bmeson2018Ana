void canvas1DhEff_PbPb()
{
//=========Macro generated from canvas: canvas1D/
//=========  (Mon Jul 15 02:23:28 2019) by ROOT version6.02/13
   TCanvas *canvas1D = new TCanvas("canvas1D", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvas1D->SetHighLightColor(2);
   canvas1D->Range(-4.625,-0.1,61.625,0.9);
   canvas1D->SetFillColor(0);
   canvas1D->SetBorderMode(0);
   canvas1D->SetBorderSize(2);
   canvas1D->SetFrameBorderMode(0);
   canvas1D->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,2,55,10,0,0.8);
   hemptyEff1->SetMinimum(0);
   hemptyEff1->SetMaximum(1);
   hemptyEff1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff1->SetLineColor(ci);
   hemptyEff1->SetMarkerStyle(20);
   hemptyEff1->GetXaxis()->SetTitle("p_{T} GeV^{-1}c)");
   hemptyEff1->GetXaxis()->CenterTitle(true);
   hemptyEff1->GetXaxis()->SetLabelFont(42);
   hemptyEff1->GetXaxis()->SetLabelSize(0.035);
   hemptyEff1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff1->GetXaxis()->SetTitleOffset(0.9);
   hemptyEff1->GetXaxis()->SetTitleFont(42);
   hemptyEff1->GetYaxis()->SetTitle("#alpha x #epsilon");
   hemptyEff1->GetYaxis()->CenterTitle(true);
   hemptyEff1->GetYaxis()->SetLabelFont(42);
   hemptyEff1->GetYaxis()->SetLabelSize(0.035);
   hemptyEff1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff1->GetYaxis()->SetTitleOffset(0.95);
   hemptyEff1->GetYaxis()->SetTitleFont(42);
   hemptyEff1->GetZaxis()->SetLabelFont(42);
   hemptyEff1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleFont(42);
   hemptyEff1->Draw("");
   Double_t xAxis1[4] = {7, 10, 15, 50}; 
   
   TH1D *hEff2 = new TH1D("hEff2","",3, xAxis1);
   hEff2->SetBinContent(0,1.60418e-05);
   hEff2->SetBinContent(1,0.0006077568);
   hEff2->SetBinContent(2,0.01012011);
   hEff2->SetBinContent(3,0.06508844);
   hEff2->SetBinError(0,7.333237e-06);
   hEff2->SetBinError(1,0.0001195078);
   hEff2->SetBinError(2,0.0005501901);
   hEff2->SetBinError(3,0.001065886);
   hEff2->SetEntries(3955.745);
   hEff2->SetStats(0);
   hEff2->SetLineColor(2);
   hEff2->SetMarkerColor(2);
   hEff2->SetMarkerStyle(20);
   hEff2->GetXaxis()->CenterTitle(true);
   hEff2->GetXaxis()->SetLabelFont(42);
   hEff2->GetXaxis()->SetLabelSize(0.035);
   hEff2->GetXaxis()->SetTitleSize(0.035);
   hEff2->GetXaxis()->SetTitleFont(42);
   hEff2->GetYaxis()->CenterTitle(true);
   hEff2->GetYaxis()->SetLabelFont(42);
   hEff2->GetYaxis()->SetLabelSize(0.035);
   hEff2->GetYaxis()->SetTitleSize(0.035);
   hEff2->GetYaxis()->SetTitleFont(42);
   hEff2->GetZaxis()->SetLabelFont(42);
   hEff2->GetZaxis()->SetLabelSize(0.035);
   hEff2->GetZaxis()->SetTitleSize(0.035);
   hEff2->GetZaxis()->SetTitleFont(42);
   hEff2->Draw("same");
   TLatex *   tex = new TLatex(0.5,0.815,"Centrality 0 - 100%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.5,0.75,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.08,0.95,"CMS Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.92,"1.5 nb^{-1} (5.02 TeV PbPb)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   canvas1D->Modified();
   canvas1D->cd();
   canvas1D->SetSelected(canvas1D);
}
