
#!/bin/bash
#source clean.sh


DOANALYSISPbPb_ROOFIT_BINNED_PT_BS=0
DOANALYSISPbPb_ROOFIT_BINNED_CENT_BS=0
DOANALYSISPbPb_ROOFIT_BINNED_Y_BS=0
DOANALYSISPbPb_ROOFIT_FULL_BS=0


DOANALYSISPbPb_ROOFIT_FULL_BP=0
DOANALYSISPbPb_ROOFIT_BINNED_PT_BP=1
DOANALYSISPbPb_ROOFIT_BINNED_Y_BP=0
DOANALYSISPbPb_ROOFIT_BINNED_CENT_BP=0

CENTPbPbMIN=0
CENTPbPbMAX=90

#INPUTMCPbPbCANDWISE_BS="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_mc_ntphi_PbPb_2018_corrected_test_new.root"
#INPUTDATAPbPbCANDWISE_BS="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_data_ntphi_PbPb_2018_corrected_test_new.root"  
INPUTMCPbPbCANDWISE_BS="./flat_trees/selected_mc_ntphi_PbPb_2018_new_train_BDT.root"
INPUTDATAPbPbCANDWISE_BS="./flat_trees/selected_data_ntphi_PbPb_2018_new_train_BDT.root"  

#INPUTMCPbPbCANDWISE_BP="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_mc_ntKp_PbPb_2018_corrected_BDT.root"
#INPUTDATAPbPbCANDWISE_BP="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_data_ntKp_PbPb_2018_new_train_BDT.root"  
INPUTMCPbPbCANDWISE_BP="./flat_trees/selected_mc_ntKp_PbPb_2018_new_train_BDT.root"
INPUTDATAPbPbCANDWISE_BP="./flat_trees/selected_data_ntKp_PbPb_2018_new_train_BDT.root"  


LABELPbPb="PbPb"
#LUMIPbPb=13.1983052423 #paper 20170227
LUMIPbPb=56.564165324
#NEW NMB from https://twiki.cern.ch/twiki/pub/CMS/HINUpsilonRaa2016/Jason_MinBiasCounting_2017-02-02.pdf
#2339717742. 2339717742*5.607/1e9 = 13.1187973794
#13.1187973794/0.99*0.996 = 13.1983052423
NMBEVT=2329685794.627413
ISMCPbPb=0
ISDOWEIGHTPbPb=1
SELGENPbPb="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"

#BASECUTPbPb="(hiBin<181)&&Btrk1Pt>0.9&&Btrk2Pt>0.9&&Bchi2cl>0.05&&BsvpvDistance/BsvpvDisErr>2&&Bpt>5&&abs(Btrk1Eta-0.0)<2.4&&abs(Btrk2Eta-0.0)<2.4&&(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015)&&(abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter)&&(Btrk1PixelHit+Btrk1StripHit>10)&&(Btrk2PixelHit+Btrk2StripHit>10)&&(Btrk1PtErr/Btrk1Pt<0.1)&&(Btrk2PtErr/Btrk2Pt<0.1)&&Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer)<0.18&&Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer)<0
BASECUTPbPb="(hiBin<181)&&Btrk1Pt>1.0&&Btrk2Pt>1.0&&Bchi2cl>0.05&&BsvpvDistance/BsvpvDisErr>2.2&&Bpt>5&&abs(Btrk1Eta-0.0)<2.4&&abs(Btrk2Eta-0.0)<2.4&&(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015)&&(abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter)&&(Btrk1PixelHit+Btrk1StripHit>10)&&(Btrk2PixelHit+Btrk2StripHit>10)&&(Btrk1PtErr/Btrk1Pt<0.1)&&(Btrk2PtErr/Btrk2Pt<0.1)&&Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer)<0.18&&Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer)<0.18"

CUTPbPb=${BASECUTPbPb}"&&((Bpt>5&&Bpt<10&&BDT_pt_5_10>0.17)||(Bpt>10&&Bpt<15&&BDT_pt_10_15>0.17)||(Bpt>15&&Bpt<20&&BDT_pt_15_20>0.26)||(Bpt>20&&Bpt<50&&BDT_pt_20_50>0.25))"

CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


#TRGPbPb="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
#TRGPbPbMC="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPb="(Bpt>0)"
TRGPbPbMC="(Bpt>0)"
echo "TRGPbPb="$TRGPbPb

OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_FULL="ROOTfiles/yields_Bs_full.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_FULL="ROOTfiles/yields_Bp_full.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_Y="ROOTfiles/yields_Bs_binned_y.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_PT="ROOTfiles/yields_Bs_binned_pt.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_CENT="ROOTfiles/yields_Bp_binned_cent.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_CENT="ROOTfiles/yields_Bs_binned_cent.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_PT="ROOTfiles/yields_Bp_binned_pt.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_Y="ROOTfiles/yields_Bp_binned_y.root"

NPROOFIT_PbPb="1"
NPROOFIT_PbPb_BP="701.019629*TMath::Erf((Bmass-5.140349)/-0.035471)+701.019629+16.946432*TMath::Gaus(Bmass,5.343914,0.040000)/(sqrt(2*3.14159)*0.040000)"

#NPROOFIT_PbPb="1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))"


if [ $DOANALYSISPbPb_ROOFIT_BINNED_PT_BS  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntphi\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BS\"','\"$INPUTMCPbPbCANDWISE_BS\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_PT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

if [ $DOANALYSISPbPb_ROOFIT_BINNED_Y_BS  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntphi\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BS\"','\"$INPUTMCPbPbCANDWISE_BS\"','\"abs\(By\)\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_Y\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi


if [ $DOANALYSISPbPb_ROOFIT_BINNED_CENT_BS  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntphi\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BS\"','\"$INPUTMCPbPbCANDWISE_BS\"','\"HiBin\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_BINNED_CENT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi


if [ $DOANALYSISPbPb_ROOFIT_FULL_BS  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntphi\"','1','1','0','\"$INPUTDATAPbPbCANDWISE_BS\"','\"$INPUTMCPbPbCANDWISE_BS\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BS_FULL\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

if [ $DOANALYSISPbPb_ROOFIT_FULL_BP  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntKp\"','1','1','0','\"$INPUTDATAPbPbCANDWISE_BP\"','\"$INPUTMCPbPbCANDWISE_BP\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_FULL\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb_BP\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

if [ $DOANALYSISPbPb_ROOFIT_BINNED_PT_BP  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntKp\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BP\"','\"$INPUTMCPbPbCANDWISE_BP\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_PT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb_BP\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

if [ $DOANALYSISPbPb_ROOFIT_BINNED_Y_BP  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntKp\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BP\"','\"$INPUTMCPbPbCANDWISE_BP\"','\"abs\(By\)\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_Y\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb_BP\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

if [ $DOANALYSISPbPb_ROOFIT_BINNED_CENT_BP  -eq 1  ]; then
root -b  -q 'roofitB.C+('\"ntKp\"','0','1','0','\"$INPUTDATAPbPbCANDWISE_BP\"','\"$INPUTMCPbPbCANDWISE_BP\"','\"HiBin\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_BP_BINNED_CENT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb_BP\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi
