#!/bin/bash

CENTPbPbMIN=0
CENTPbPbMAX=100

#
DOSAVEHISTPP=0
DOSAVEHISTPbPb=0
#DOSAVEHISTPPMB=1
#DOSAVEHISTPbPbMB=1

#
DOFITDEFAULTNEWPP=0
DOFITDEFAULTNEWPbPb=0
#DOFITDEFAULTNEWPPMB=1
#DOFITDEFAULTNEWPbPbMB=1

DOFITINCREASEWIDPP=0
DOFITINCREASEWIDPbPb=1
#DOFITINCREASEWIDPPMB=1
#DOFITINCREASEWIDPbPbMB=1

DOFITDECREASEWIDPP=0
DOFITDECREASEWIDPbPb=1
#DOFITDECREASEWIDPPMB=1
#DOFITDECREASEWIDPbPbMB=1

DOFITPOLY3PP=0
DOFITPOLY3PbPb=1
#DOFITPOLY2PPMB=1
#DOFITPOLY2PbPbMB=1


DOFITPOLY1PP=0
DOFITPOLY1PbPb=1
#DOFITEXPO2PPMB=1
#DOFITEXPO2PbPbMB=1


DOFITEXPO2PP=0
DOFITEXPO2PbPb=1
#DOFITEXPO2PPMB=1
#DOFITEXPO2PbPbMB=1

##


#rm -rf outYield
#rm -rf outfMasshisto
#mkdir outfMasshisto
#mkdir outYield

INPUTMCPP="/data/BmesonMCPbPb/loop_Bs0_pthat5_bstojpsiphi_pp.root"
INPUTDATAPP="/data/wangj/Data2015/Bntuple/pp/ntB_EvtBase_20160420_BfinderData_pp_20160419_bPt0jpsiPt0tkPt0p5.root"
#INPUTMCPbPb="/data/BmesonMCPbPb/loop_Bs0_PbPb_MC_25072017_pthat10.root"
#INPUTDATAPbPb="/data/wangj/Data2015/Bntuple/PbPb/Bntuple_BfinderData_PbPb_20160406_bPt5jpsiPt0tkPt0p8_BpB0BsX_skimhlt.root"
#INPUTDATAPbPb="/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged.root"
#INPUTDATAPPMB="/data/dmeson2015/DataDntuple/skim_ncand_D0Dntuple_crab_pp_ALLMinimumBias_AOD_D0_tkpt0p5_Ds_01212016_skimmedPt1.root"
#INPUTMCPPMB="/data/wangj/MC2015/Dntuple/pp/revised/ntD_pp_Dzero_kpi_prompt/ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight.root"
#INPUTDATAPbPbMB="/data/jisun/PbPb2015/HF2and_tk1p0_skim_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016.root"
#INPUTMCPbPbMB="/data/wangj/MC2015/Dntuple/PbPb/revised/ntD_PbPb_Dzero_kpi_prompt/ntD_EvtBase_20160330_Dfinder_20160329_PbPb_Pythia8_prompt_D0_dPt1tkPt0p5_pthatweight.root"


#INPUTMCPbPb="/export/d00/scratch/zzshiNPFIT_PbPb/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh/MC_Bs_pp_TMVA_BDT_pp.root"
#INPUTDATAPbPb="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh/Data_Bs_pp_TMVA_BDT_pp.root"
INPUTMCPbPb="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/MC_Bs_pp_TMVA_BDT_pp.root"
INPUTDATAPbPb="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/Data_Bs_pp_TMVA_BDT_pp.root"


##

ISMCPP=0
ISDOWEIGHTPP=0
#SELGENPP="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
#CUTPP="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&Dtrk1OriginalAlgo>3&&Dtrk1OriginalAlgo<=8&&Dtrk2OriginalAlgo>3&&Dtrk2OriginalAlgo<=8&&(Dtrk1PixelHit+Dtrk1StripHit)>=11&&(Dtrk2PixelHit+Dtrk2StripHit)>=11&&(Dtrk1Chi2ndf/(Dtrk1nStripLayer+Dtrk1nPixelLayer)<0.15)&&(Dtrk2Chi2ndf/(Dtrk2nStripLayer+Dtrk2nPixelLayer)<0.15)"
CUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8))&& ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Btrk1highPurity&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>2.&&cos(Bdtheta)>2.60e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025&&abs(Btktkmass-1.019455)<1.55e-02"
TRGPP="(HLT_HIL1DoubleMu0_v1)"
#TRGPP="((HLT_DmesonPPTrackingGlobal_Dpt15_v1&&Dpt>20&&Dpt<40)||(HLT_DmesonPPTrackingGlobal_Dpt30_v1&&Dpt>40&&Dpt<60)||(HLT_DmesonPPTrackingGlobal_Dpt50_v1&&Dpt>60))"
LABELPP="PP"
NPFIT_PP="3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) + 2.11124e2"

BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015"
CUTPbPb=${BASECUTPbPb}"&&((Bpt>5&&Bpt<7&&BDT_pt_5_7>0.52)||(Bpt>7&&Bpt<15&&BDT_pt_7_15>0.58)||(Bpt>15&&Bpt<20&&BDT_pt_15_20> 0.59)||(Bpt>30&&Bpt<50&&BDT_pt_20_50>0.65))"
CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"
TRGPbPb="(Bpt > 0)"
LABELPbPb="PbPb"
NPFIT_PbPb="1"

#cp config/parametersHighpt.h parameters.h

if [ $DOSAVEHISTPP -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "$CUTPP" "$ISMCPP" "$ISDOWEIGHTPP" "$LABELPP" 
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPb -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPbPb" "$INPUTMCPbPb" "$TRGPbPb" "$CUTPbPb" "$ISMCPbPb" "$ISDOWEIGHTPbPb" "$LABELPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm saveMasshisto.exe
fi

if [ $DOFITDEFAULTNEWPP -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPP" "$NPFIT_PP"
rm fitDdefaultnew.exe
fi

if [ $DOFITDEFAULTNEWPbPb -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX" 
rm fitDdefaultnew.exe
fi

if [ $DOFITINCREASEWIDPP -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPP" "$NPFIT_PP"
rm fitDincreasewid.exe
fi

if [ $DOFITINCREASEWIDPbPb -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDincreasewid.exe
fi

if [ $DOFITDECREASEWIDPP -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPP" "$NPFIT_PP"
rm fitDdecreasewid.exe
fi

if [ $DOFITDECREASEWIDPbPb -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdecreasewid.exe
fi

if [ $DOFITPOLY1PP -eq 1 ]; then
g++ fitDpoly1.C $(root-config --cflags --libs) -g -o fitDpoly1.exe 
./fitDpoly1.exe "$LABELPP" "$NPFIT_PP"
rm fitDpoly1.exe
fi

if [ $DOFITPOLY1PbPb -eq 1 ]; then
g++ fitDpoly1.C $(root-config --cflags --libs) -g -o fitDpoly1.exe 
./fitDpoly1.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDpoly1.exe
fi

if [ $DOFITPOLY3PP -eq 1 ]; then
g++ fitDpoly3.C $(root-config --cflags --libs) -g -o fitDpoly3.exe 
./fitDpoly3.exe "$LABELPP" "$NPFIT_PP"
rm fitDpoly3.exe
fi

if [ $DOFITPOLY3PbPb -eq 1 ]; then
g++ fitDpoly3.C $(root-config --cflags --libs) -g -o fitDpoly3.exe 
./fitDpoly3.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDpoly3.exe
fi


if [ $DOFITEXPO2PP -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPP" "$NPFIT_PP"
rm fitDexpo2.exe
fi

if [ $DOFITEXPO2PbPb -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPbPb" "$NPFIT_PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDexpo2.exe
fi

#
#rm parameters.h

##
ISMCPPMB=0
ISDOWEIGHTPPMB=0
SELGENPPMB="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"
CUTPPMB="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12"
TRGPPMB="(HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)"
LABELPPMB="PPMB"

ISMCPbPbMB=0
#ISDOWEIGHTPbPbMB=1
#SELGENPbPbMB="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))"

ISDOWEIGHTPbPbMB=1
SELGENPbPbMB="(TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0)"
#CUTPbPbMB="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))"
#TRGPbPbMB="(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1)"


#BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015"


#CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT_pt_7_15>0.57)||(Bpt>15&&Bpt<30&&BDT_pt_15_30> 0.59)||(Bpt>30&&Bpt<50&&BDT_pt_30_50>0.70) )"
#CUTPbPbMB=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"



TRGPbPbMB="(Bpt > 0)"
LABELPbPbMB="PbPbMB"

#cp config/parametersLowpt.h parameters.h

if [ $DOSAVEHISTPPMB -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPPMB" "$INPUTMCPPMB" "$TRGPPMB" "$CUTPPMB" "$ISMCPPMB" "$ISDOWEIGHTPPMB" "$LABELPPMB"
rm saveMasshisto.exe
fi

if [ $DOSAVEHISTPbPbMB -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe 
./saveMasshisto.exe "$INPUTDATAPbPbMB" "$INPUTMCPbPbMB" "$TRGPbPbMB" "$CUTPbPbMB" "$ISMCPbPbMB" "$ISDOWEIGHTPbPbMB" "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm saveMasshisto.exe
fi

if [ $DOFITDEFAULTNEWPPMB -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPPMB"
rm fitDdefaultnew.exe
fi

if [ $DOFITDEFAULTNEWPbPbMB -eq 1 ]; then
g++ fitDdefaultnew.C $(root-config --cflags --libs) -g -o fitDdefaultnew.exe 
./fitDdefaultnew.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdefaultnew.exe
fi

if [ $DOFITINCREASEWIDPPMB -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPPMB"
rm fitDincreasewid.exe
fi

if [ $DOFITINCREASEWIDPbPbMB -eq 1 ]; then
g++ fitDincreasewid.C $(root-config --cflags --libs) -g -o fitDincreasewid.exe 
./fitDincreasewid.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDincreasewid.exe
fi

if [ $DOFITDECREASEWIDPPMB -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPPMB"
rm fitDdecreasewid.exe
fi

if [ $DOFITDECREASEWIDPbPbMB -eq 1 ]; then
g++ fitDdecreasewid.C $(root-config --cflags --libs) -g -o fitDdecreasewid.exe 
./fitDdecreasewid.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDdecreasewid.exe
fi

if [ $DOFITPOLY2PPMB -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPPMB"
rm fitDpoly2.exe
fi

if [ $DOFITPOLY2PbPbMB -eq 1 ]; then
g++ fitDpoly2.C $(root-config --cflags --libs) -g -o fitDpoly2.exe 
./fitDpoly2.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDpoly2.exe
fi

if [ $DOFITEXPO2PPMB -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPPMB"
rm fitDexpo2.exe
fi

if [ $DOFITEXPO2PbPbMB -eq 1 ]; then
g++ fitDexpo2.C $(root-config --cflags --libs) -g -o fitDexpo2.exe 
./fitDexpo2.exe "$LABELPbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitDexpo2.exe
fi

#
#rm parameters.h

##
