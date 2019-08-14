
#!/bin/bash
#source clean.sh


DOANALYSISPbPb_ROOFIT_BINNED=0
DOANALYSISPbPb_ROOFIT_FULL=1

CENTPbPbMIN=0
CENTPbPbMAX=100

INPUTMCPbPbCANDWISE="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_mc_ntphi_PbPb_2018_corrected.root"
INPUTDATAPbPbCANDWISE="/afs/cern.ch/work/j/jusilva/CMSSW_7_5_8_patch5/src/UserCode/Bmeson2018Ana/Bs/CrossSection/cut_trees/selected_data_ntphi_PbPb_2018_test_onlyevtscuts+mass.root"  


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

OUTPUTFILEPbPbSAVEHIST_ROOFIT="ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"

NPROOFIT_PbPb="1"
#NPROOFIT_PbPb="1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))"





if [ $DOANALYSISPbPb_ROOFIT_BINNED  -eq 1  ]; then
echo "IGOTHEREBABY"

#root-b-q'roofitB.C++('1','1','0','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/Data_Bs_PbPb_TMVA_BDT_PbPb.root"','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/MC_Bs_PbPb_TMVA_BDT_PbPb.root"','"Bpt"','"(Bpt>0)"','"(hiBin<181)&&Btrk1Pt>0.9&&Btrk2Pt>0.9&&Bchi2cl>0.05&&BsvpvDistance/BsvpvDisErr>2&&Bpt>5&&abs(Btrk1Eta-0.0)<2.4&&abs(Btrk2Eta-0.0)<2.4&&(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015)&&(abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter)&&(Btrk1PixelHit+Btrk1StripHit>10)&&(Btrk2PixelHit+Btrk2StripHit>10)&&(Btrk1PtErr/Btrk1Pt<0.1)&&(Btrk2PtErr/Btrk2Pt<0.1)&&Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer)<0.18&&Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer)<0.18&&((Bpt>5&&Bpt<10&&BDT_pt_5_10>0.20)||(Bpt>10&&Bpt<15&&BDT_pt_10_15>0.22)||(Bpt>15&&Bpt<20&&BDT_pt_15_20>0.22)||(Bpt>20&&Bpt<50&&BDT_pt_20_50>0.28))&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"','"TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"','0','1','1','"PbPb"','"ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"','"plotFits/plotFits_roofit"','"1"','0','0','100')'

echo "INPUTDATAPBPBCANDWISE=" $INPUTDATAPbPbCANDWISE	
echo  "INPUTMCPbPbCANDWISE	=" $INPUTMCPbPbCANDWISE	
echo "TRGPbPb			=" $TRGPbPb			
echo "CUTPbPb			=" $CUTPbPb			
echo "SELGENPbPb		=" $SELGENPbPb		
echo "ISMCPbPb			=" $ISMCPbPb			
echo "ISDOWEIGHTPbPb		=" $ISDOWEIGHTPbPb		
echo "LABELPbPb		=" $LABELPbPb		
echo "OUTPUTFILEPbPbSAVEHIST_ROOFIT=" $OUTPUTFILEPbPbSAVEHIST_ROOFIT
echo "NPROOFIT_PbPb		=" $NPROOFIT_PbPb		
echo "CENTPbPbMIN		=" $CENTPbPbMIN		
echo "CENTPbPbMAX=" $CENTPbPbMAX



#exit
#root-b-q'roofitB.C('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"$TRGPbPb\"')'
#'\"$TRGPbPb\"')'
#,'\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
#exit2
root -b  -q 'roofitB.C+('0','1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi


if [ $DOANALYSISPbPb_ROOFIT_FULL  -eq 1  ]; then
echo "IGOTHEREBABY"

#root-b-q'roofitB.C++('1','1','0','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/Data_Bs_PbPb_TMVA_BDT_PbPb.root"','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/MC_Bs_PbPb_TMVA_BDT_PbPb.root"','"Bpt"','"(Bpt>0)"','"(hiBin<181)&&Btrk1Pt>0.9&&Btrk2Pt>0.9&&Bchi2cl>0.05&&BsvpvDistance/BsvpvDisErr>2&&Bpt>5&&abs(Btrk1Eta-0.0)<2.4&&abs(Btrk2Eta-0.0)<2.4&&(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015)&&(abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter)&&(Btrk1PixelHit+Btrk1StripHit>10)&&(Btrk2PixelHit+Btrk2StripHit>10)&&(Btrk1PtErr/Btrk1Pt<0.1)&&(Btrk2PtErr/Btrk2Pt<0.1)&&Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer)<0.18&&Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer)<0.18&&((Bpt>5&&Bpt<10&&BDT_pt_5_10>0.20)||(Bpt>10&&Bpt<15&&BDT_pt_10_15>0.22)||(Bpt>15&&Bpt<20&&BDT_pt_15_20>0.22)||(Bpt>20&&Bpt<50&&BDT_pt_20_50>0.28))&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"','"TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"','0','1','1','"PbPb"','"ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"','"plotFits/plotFits_roofit"','"1"','0','0','100')'

echo "INPUTDATAPBPBCANDWISE=" $INPUTDATAPbPbCANDWISE	
echo  "INPUTMCPbPbCANDWISE	=" $INPUTMCPbPbCANDWISE	
echo "TRGPbPb			=" $TRGPbPb			
echo "CUTPbPb			=" $CUTPbPb			
echo "SELGENPbPb		=" $SELGENPbPb		
echo "ISMCPbPb			=" $ISMCPbPb			
echo "ISDOWEIGHTPbPb		=" $ISDOWEIGHTPbPb		
echo "LABELPbPb		=" $LABELPbPb		
echo "OUTPUTFILEPbPbSAVEHIST_ROOFIT=" $OUTPUTFILEPbPbSAVEHIST_ROOFIT
echo "NPROOFIT_PbPb		=" $NPROOFIT_PbPb		
echo "CENTPbPbMIN		=" $CENTPbPbMIN		
echo "CENTPbPbMAX=" $CENTPbPbMAX



#exit
#root-b-q'roofitB.C('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"$TRGPbPb\"')'
#'\"$TRGPbPb\"')'
#,'\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
#exit2
root -b  -q 'roofitB.C+('1','1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/new_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi

