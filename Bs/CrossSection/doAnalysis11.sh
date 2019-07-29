
#!/bin/bash
#source clean.sh
CENTPbPbMIN=0
CENTPbPbMAX=100

DOANALYSISPP_FONLL=0
DOANALYSISPP_FIT=0
DOANALYSISPP_FITONSAVED=0
DOANALYSISPP_ROOFIT=0
DOANALYSISPP_ROOFITONSAVED=0
DOANALYSISPP_MCSTUDY=0
DOANALYSISPP_CROSS=0

DOANALYSISPbPb_FIT=0
DOANALYSISPbPb_FITONSAVED=0
DOANALYSISPbPb_ROOFIT=1
DOANALYSISPbPb_ROOFITONSAVED=0
DOANALYSISPbPb_MCSTUDY=0
DOANALYSISPbPb_CROSS=0
DORAA=0
DORAARATIO=0
DOANALYSISPbPb_REWEIGHT=0


#Closure Test

DOCLOSUREPbPb=0
FINCLOSUREPbPb=0


#ONY For Acceptance Studies
DOANALYSISPbPb_FITONY=0
DOANALYSISPbPb_MCSTUDYONY=0


DOANALYSISPbPb_PTSHAPESYST=0
DOANALYSISPbPb_PTSHAPESYSTPLOT=0
### pt inclusive interval mass fit
DOANALYSISPP_FIT_Inc=0
DOANALYSISPP_FITONSAVED_Inc=0
DOANALYSISPP_ROOFIT_Inc=0
DOANALYSISPP_ROOFITONSAVED_Inc=0
DOANALYSISPbPb_FIT_Inc=0
DOANALYSISPbPb_FITONSAVED_Inc=0
DOANALYSISPbPb_ROOFIT_Inc=0
DOANALYSISPbPb_ROOFITONSAVED_Inc=0

### pp 3-bin result
DOANALYSISPP_FONLL_750=0
DOANALYSISPP_FIT_750=0
DOANALYSISPP_FITONSAVED_750=0
DOANALYSISPP_ROOFIT_750=0
DOANALYSISPP_ROOFITONSAVED_750=0
DOANALYSISPP_MCSTUDY_750=0
DOANALYSISPP_CROSS_750=0

### pp cut base MVA (CUTBASE)
DOANALYSISPP_FIT_CUTBASE=0
DOANALYSISPP_FITONSAVED_CUTBASE=0
DOANALYSISPP_ROOFIT_CUTBASE=0
DOANALYSISPP_ROOFITONSAVED_CUTBASE=0
DOANALYSISPP_MCSTUDY_CUTBASE=0
DOANALYSISPP_CROSS_CUTBASE=0

### pp sample with PbPb MVA (BDT)
DOANALYSISPP_FIT_PbPbBDT=0
DOANALYSISPP_FITONSAVED_PbPbBDT=0
DOANALYSISPP_ROOFIT_PbPbBDT=0
DOANALYSISPP_ROOFITONSAVED_PbPbBDT=0
DOANALYSISPP_MCSTUDY_PbPbBDT=0
DOANALYSISPP_CROSS_PbPbBDT=0

### pp sample with old PbPb MVA (BDT)
DOANALYSISPP_FIT_OLDPbPbBDT=0
DOANALYSISPP_FITONSAVED_OLDPbPbBDT=0
DOANALYSISPP_ROOFIT_OLDPbPbBDT=0
DOANALYSISPP_ROOFITONSAVED_OLDPbPbBDT=0
DOANALYSISPP_MCSTUDY_OLDPbPbBDT=0
DOANALYSISPP_CROSS_OLDPbPbBDT=0

### pp 4-bin result for acceptance
DOANALYSISPP_FIT_750_acc=0
DOANALYSISPP_MCSTUDY_750_acc=0

### Rapidity result for acceptance
DOANALYSISPP_FIT_Y=0
DOANALYSISPP_MCSTUDY_Y=0

### Reweighting
DOPTREWEIGHT=0

### Cross checks
DOClosure=0

### Project some varibles
PROJECTVAR=0

### MC pp PbPb comparison
DOVARCOMPARE_MC=0

### Data - MC comparison
DOVARCOMPARE_PP=0

### Checking prompt background structure
CHECKPROMPT=0

### PDF Syst.
DOPDFSYST=0

### Pt Shape Syst.
DOPTSHAPESYST=0

### Track Eta Weight Syst.
DOTKETAWEIGHTSYST=0

## PP MONTE CARLO
INPUTMCPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50.root"
INPUTMCPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root"

## PP DATA 
INPUTDATAPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50.root"
INPUTDATAPPCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50_candWise.root"

## PbPb MONTE CARLO
INPUTMCPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50.root"
#INPUTMCPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_candWise.root"

## PbPb DATA 
INPUTDATAPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_PbPb_20180314_bPt0tkPt0MuAll_Bs_HIOniaL1DoubleMu0_AllDatamerged_BDT7to50_candWise.root"

#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_pthatweight_JingBDT.root"
#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MakeBDT/MC/crab_Bfinder_20190115_Hydjet_Pythia8_BsToJpsiPhi_20181231_pt5tkpt0p7dls2_v3_pthatweight_BDTMerged.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/BsAllSoFar.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/MakeBDT/Files/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v2_1031_NoJSON_skimhltBsize_ntphi_BDTMerged.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/Data/New/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_skimhltBsize_ntphi_NewBDTMerged.root"


#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh/MC_Bs_pp_TMVA_BDT_pp.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh/Data_Bs_pp_TMVA_BDT_pp.root"

#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4Bins/MC_Bs_pp_TMVA_BDT_pp.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4Bins/Data_Bs_pp_TMVA_BDT_pp.root"
#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/MC_Bs_pp_TMVA_BDT_pp.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/Data_Bs_pp_TMVA_BDT_pp.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Recalculation/Reassigned.root"

#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh3BinsRedo/MC_Bs_PbPb_TMVA_BDT_pp_CentWighted.root"
#INPUTMCPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/PthatService/output/PthatMergedCentreweightBDT.root"
#INPUTDATAPbPbCANDWISE="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh3BinsRedo/Data_Bs_PbPb_TMVA_BDT_pp.root"

INPUTMCPbPbCANDWISE="/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/MC_Bs_PbPb_TMVA_BDT_PbPb.root"
INPUTDATAPbPbCANDWISE="/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/Data_Bs_PbPb_TMVA_BDT_PbPb.root"  
#INPUTMCPbPbCANDWISE=""
#INPUTDATAPbPbCANDWISE=""

## ANALYSIS PP TRIGGERED
FONLLDATINPUT="pp_Bplus_5p03TeV_y2p4"
FONLLOUTPUTFILE="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4.root"
FONLLOUTPUTFILEREWEIGHT="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4_reweightBin.root"
OUTPUTFILERAA="ROOTfiles/outputRAA.root"

echo "mc files=" $INPUTMCPbPbCANDWISE
echo "data files=" $INPUTDATAPbPbCANDWISE


##FILENAME PT SHAPE SYST

WEIGHTEDEFFOUTFILE="plotPtShapeSyst/Files/EffWeighted.root"
UNWEIGHTEDEFFOUTFILE="plotPtShapeSyst/Files/EffUnWeighted.root"
PLOTNAME="plotPtShapeSyst/Plots/EffRatio.png"
PTSHAPEOUTFILENAME="plotPtShapeSyst/Files/EffRatio.root"



LABELPP="pp"
LUMIPP=27.748 # paper 20170224

#28.0*0.991
ISMCPP=0
ISDOWEIGHTPP=0
SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0"
SELGENPPACCPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
BASECUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015"
CUTPP=${BASECUTPP}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.191055)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.208973)||(Bpt>55&&Bpt<100&&BDTStage1_pt15to50>0.10))"
CUTPP=${CUTPP}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
RECOONLYPP=$CUTPP
TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"
OUTPUTFILEPPSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPP.root"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBplusPP.root"
OUTPUTFILEPPSAVEHIST_ROOFIT="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit.root"
OUTPUTFILEPP_ROOFIT="ROOTfiles/hPtSpectrumBplusPP_roofit.root"
OUTPUTFILEMCSTUDYPP="ROOTfiles/MCstudiesPP.root"
OUTPUTFILEPlotPP="ROOTfiles/CrossSectionPP.root"
OUTPUTFILEPPDATA="ROOTfiles/data_pp.root"
OUTPUTFILEPPMC="ROOTfiles/mc_pp.root"

#SETTING for NP fit
NPFIT_PP="1"
#NPFIT_PP="1.238105*Gaus(x,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((x-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*Gaus(x,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*Gaus(x,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"
NPROOFIT_PP="1"
#NPROOFIT_PP="1.238105*TMath::Gaus(Bmass,5.067665,0.015902)/(sqrt(2*3.14159)*0.015902)+30.054860*TMath::Erf((Bmass-5.142158)/-0.114983)+30.054860+10.468093*(0.390932*TMath::Gaus(Bmass,5.375549,0.166548)/(sqrt(2*3.14159)*0.166548)+(1-0.390932)*TMath::Gaus(Bmass,5.375549,0.040095)/(sqrt(2*3.14159)*0.040095))"





if [ $DOANALYSISPP_FONLL -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT" "$FONLLOUTPUTFILE" "$LABELPP"
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FIT -eq 1 ]; then      
g++ fitBPP.C $(root-config --cflags --libs) -g -o fitB.exe 
#./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST" "plotFits/plotFits" "$NPFIT_PP" 0 "0" "100"
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP" "plotFits/plotFits" "$NPFIT_PP" 0 "0" "100"


rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP" "plotFits/plotFitsOnSaved" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT\"','\"plotFits/plotFitsOnSaved_roofit\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then      
g++ MCefficiencyPP.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "plotEff/plotEff" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "plotEff/plotEff" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0 1
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" "plotCrossSection/plotCrossSection" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100" 0 1
rm CrossSectionRatio.exe
fi

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
#BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Bmu1TrgMatchFilterE>0&&Bmu2TrgMatchFilterE>0&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455)<0.015"

#BASECUTPbPb="(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8)))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight &&Bmu1InPixelLayer>0 && (Bmu1InPixelLayer+Bmu1InStripLayer)>5 &&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>0.&&Btrk2Pt>0.&&abs(Btktkmass-1.019455) < 0.015"

#BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015"


#######


BASECUTPbPb="(hiBin<181)&&Btrk1Pt>0.9&&Btrk2Pt>0.9&&Bchi2cl>0.05&&BsvpvDistance/BsvpvDisErr>2&&Bpt>5&&abs(Btrk1Eta-0.0)<2.4&&abs(Btrk2Eta-0.0)<2.4&&(TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015)&&(abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter)&&(Btrk1PixelHit+Btrk1StripHit>10)&&(Btrk2PixelHit+Btrk2StripHit>10)&&(Btrk1PtErr/Btrk1Pt<0.1)&&(Btrk2PtErr/Btrk2Pt<0.1)&&Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer)<0.18&&Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer)<0.18"

#CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.213755)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.254413))"
#CUTPbPb=${CUTPbPb&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"


#CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT>0.213755)||(Bpt>15&&Bpt<50&&BDT>0.254413))"
#CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
#CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


#CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT_pt_7_15>0.213755)||(Bpt>15&&Bpt<50&&BDT_pt_15_50>0.254413)||(Bpt>50&&Bpt<100&&BDT_pt_15_50>-0.4) )"

#CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT_pt_7_15>0.57)||(Bpt>15&&Bpt<30&&BDT_pt_15_30> 0.59)||(Bpt>30&&Bpt<50&&BDT_pt_30_50>0.70) )"
CUTPbPb=${BASECUTPbPb}"&&((Bpt>5&&Bpt<10&&BDT_pt_5_10>0.20)||(Bpt>10&&Bpt<15&&BDT_pt_10_15>0.22)||(Bpt>15&&Bpt<20&&BDT_pt_15_20>0.22)||(Bpt>20&&Bpt<50&&BDT_pt_20_50>0.28))"

CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


echo "NEW CUT CUTPbPb = " $CUTPbPb


#CUTPbPbData=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT_pt_7_15>0.213755)||(Bpt>15&&Bpt<50&&BDT_pt_15_50>0.254413))"
#CUTPbPbData=${CUTPbPbData}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


RECOONLYPbPb=$CUTPbPb
#TRGPbPb="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
#TRGPbPbMC="(HLT_HIL1DoubleMu0_v1||HLT_HIL1DoubleMu0_part1_v1||HLT_HIL1DoubleMu0_part2_v1||HLT_HIL1DoubleMu0_part3_v1)"
TRGPbPb="(Bpt>0)"
TRGPbPbMC="(Bpt>0)"
echo "TRGPbPb = " $TRGPbPb

OUTPUTFILEPbPbSAVEHIST="ROOTfiles/hPtSpectrumSaveHistBplusPbPb.root"
OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBplusPbPb.root"
OUTPUTFILEPbPbONY="ROOTfiles/hPtSpectrumBplusPbPb_Y.root"

OUTPUTFILEPbPbSAVEHIST_ROOFIT="ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"
OUTPUTFILEPbPb_ROOFIT="ROOTfiles/hPtSpectrumBplusPbPb_roofit.root"
OUTPUTFILEMCSTUDYPbPb="ROOTfiles/MCstudiesPbPb.root"
OUTPUTFILEMCSTUDYPbPbONY="ROOTfiles/MCstudiesPbPb_Y.root"


OUTPUTFILECLOSUREPbPb="ROOTfiles/hPtMCPbPbClosurePart1.root"
CLOSUREPPMB="ROOTfiles/hPtMCPbPbClosurePart2.root"


OUTPUTFILEPlotPbPb="ROOTfiles/CrossSectionPbPb.root"
OUTPUTFILEPbPbDATA="ROOTfiles/data_PbPb.root"
OUTPUTFILEPbPbMC="ROOTfiles/mc_PbPb.root"

#SETTING for NP fit
NPFIT_PbPb="1"
#NPFIT_PbPb="1.299998*Gaus(x,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((x-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*Gaus(x,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*Gaus(x,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 
NPROOFIT_PbPb="1"
#NPROOFIT_PbPb="1.299998*TMath::Gaus(Bmass,6.099828,-0.242801)/(sqrt(2*3.14159)*-0.242801)+8.186179*TMath::Erf((Bmass-5.000000)/-0.205218)+8.186179+1.263652*(0.426611*TMath::Gaus(Bmass,5.383307,0.249980)/(sqrt(2*3.14159)*0.249980)+(1-0.426611)*TMath::Gaus(Bmass,5.383307,0.037233)/(sqrt(2*3.14159)*0.037233))" 


if [ $DOCLOSUREPbPb -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTMCPbPbCANDWISE"  "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILECLOSUREPbPb" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
echo "Closure Part 1 DONE !!!"
fi


if [ $FINCLOSUREPbPb -eq 1 ]; then  
g++ Closure.C $(root-config --cflags --libs) -g -o Closure.exe 
./Closure.exe "PbPb" "$OUTPUTFILECLOSUREPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$CLOSUREPbPb"
rm Closure.exe
echo "Closure Part 2 DONE !!!"
fi





if [ $DOANALYSISPbPb_REWEIGHT -eq 1 ]; then      
g++ ReweightBpt.C $(root-config --cflags --libs) -g -o ReweightBpt.exe
./ReweightBpt.exe "$INPUTMCPbPbCANDWISE" "$FONLLOUTPUTFILE"
rm ReweightBpt.exe
fi

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
#./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$CUTPbPbData" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
#./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_FITONY -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
#./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$CUTPbPbData" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
#./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbSAVEHIST" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "abs(By)" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPbONY" "plotFits/plotFits" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 







if [ $DOANALYSISPbPb_FITONSAVED -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST" "$OUTPUTFILEPbPbSAVEHIST" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb" "plotFits/plotFitsOnSaved" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 






if [ $DOANALYSISPbPb_ROOFIT -eq 1 ]; then      
echo "I GOT HERE BABY"

#root -b -q 'roofitB.C++('1','0','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/Data_Bs_PbPb_TMVA_BDT_PbPb.root"','"/eos/cms/store/group/phys_heavyions/zshi/ForJulia/OfficialBDTSamples/MC_Bs_PbPb_TMVA_BDT_PbPb.root"','"Bpt"','"(Bpt > 0)"','"(hiBin < 181) && Btrk1Pt > 0.9 && Btrk2Pt > 0.9 && Bchi2cl > 0.05 && BsvpvDistance/BsvpvDisErr > 2 && Bpt > 5 && abs(Btrk1Eta-0.0) < 2.4  && abs(Btrk2Eta-0.0) < 2.4 && (TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015) && (abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter) && (Btrk1PixelHit + Btrk1StripHit > 10) && (Btrk2PixelHit + Btrk2StripHit > 10) && (Btrk1PtErr/Btrk1Pt < 0.1)&& (Btrk2PtErr/Btrk2Pt < 0.1) && Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer) < 0.18 && Btrk2Chi2ndf/(Btrk2nStripLayer+Btrk2nPixelLayer) < 0.18&&((Bpt>5&&Bpt<10&&BDT_pt_5_10>0.20)||(Bpt>10&&Bpt<15&&BDT_pt_10_15> 0.22)||(Bpt>15&&Bpt<20&&BDT_pt_15_20>0.22)||(Bpt>20&&Bpt<50&&BDT_pt_20_50>0.28))&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"','"TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==531&&GisSignal>0"','0','1','1','"PbPb"','"ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit.root"','"plotFits/plotFits_roofit"','"1"','0','0','100')'

echo "INPUTDATAPBPBCANDWISE          ="$INPUTDATAPbPbCANDWISE	        
echo "INPUTMCPbPbCANDWISE	     ="$INPUTMCPbPbCANDWISE	       
echo "TRGPbPb			     ="$TRGPbPb			       
echo "CUTPbPb			     ="$CUTPbPb			       
echo "SELGENPbPb		     ="$SELGENPbPb		       
echo "ISMCPbPb			     ="$ISMCPbPb			       
echo "ISDOWEIGHTPbPb		     ="$ISDOWEIGHTPbPb		       
echo "LABELPbPb		     ="$LABELPbPb		       
echo "OUTPUTFILEPbPbSAVEHIST_ROOFIT ="$OUTPUTFILEPbPbSAVEHIST_ROOFIT   
echo "NPROOFIT_PbPb		     ="$NPROOFIT_PbPb		       
echo "CENTPbPbMIN		     ="$CENTPbPbMIN		       
echo "CENTPbPbMAX                   ="$CENTPbPbMAX                       



#exit 
#root -b -q 'roofitB.C('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"$TRGPbPb\"')'
#'\"$TRGPbPb\"')'
#,'\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
#exit 2
root -b -q 'roofitB.C+('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPba\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"plotFits/plotFits_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'

rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_ROOFITONSAVED -eq 1 ]; then      
root -b -q 'roofitB.C++('1','1','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"$LABELPbPb\"','\"$OUTPUTFILEPbPb_ROOFIT\"','\"plotFits/plotFitsOnSaved_roofit\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 1 "$INPUTMCPbPb" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "plotEff/plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "plotEff/plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

if [ $DOANALYSISPbPb_MCSTUDYONY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "abs(By)" "Gy" "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPbONY" "plotEff/plotEff" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi


if [ $DOANALYSISPbPb_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection/plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX" 0
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPbPb_ROOFIT" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" "plotCrossSection/plotCrossSection" 1 "$LABELPbPb" 0 0 "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX" 0
rm CrossSectionRatio.exe
fi

if [ $DORAA -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb" "$LABELPbPb" "$OUTPUTFILERAA" "plotRAA" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi

OUTPUTFILERAARATIO="plotBsBpRatio/outputRAA_Bs.root"
if [ $DORAARATIO -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb" "$LABELPbPb" "$OUTPUTFILERAARATIO" "plotBsBpRatio" 1 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
cd plotBsBpRatioDORAA
root -b -q plotBsBpRatio.cc
cd -
fi


if [ $DOANALYSISPbPb_PTSHAPESYST -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$WEIGHTEDEFFOUTFILE" "plotPtShapeSyst/Plots" 1 "$CENTPbPbMIN" "$CENTPbPbMAX"
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt" "Gpt" "$LABELPbPb" "$UNWEIGHTEDEFFOUTFILE" "plotPtShapeSyst/Plots" 2 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi


if [ $DOANALYSISPbPb_PTSHAPESYSTPLOT -eq 1 ]; then    
g++ PtShapeSyst.C $(root-config --cflags --libs) -g -o PtShapeSyst.exe 
./PtShapeSyst.exe "$WEIGHTEDEFFOUTFILE" "$UNWEIGHTEDEFFOUTFILE" "$PLOTNAME" "$PTSHAPEOUTFILENAME"
rm PtShapeSyst.exe
fi





### pt inclusive interval mass fit
OUTPUTFILEPPSAVEHIST_Inc="ROOTfiles/hPtSpectrumSaveHistBplusPP_Inc.root"
OUTPUTFILEPP_Inc="ROOTfiles/hPtSpectrumBplusPP_Inc.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_Inc="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_Inc.root"
OUTPUTFILEPP_ROOFIT_Inc="ROOTfiles/hPtSpectrumBplusPP_roofit_Inc.root"
OUTPUTFILEPbPbSAVEHIST_Inc="ROOTfiles/hPtSpectrumSaveHistBplusPbPb_Inc.root"
OUTPUTFILEPbPb_Inc="ROOTfiles/hPtSpectrumBplusPbPb_Inc.root"
OUTPUTFILEPbPbSAVEHIST_ROOFIT_Inc="ROOTfiles/hPtSpectrumSaveHistBplusPbPb_roofit_Inc.root"
OUTPUTFILEPbPb_ROOFIT_Inc="ROOTfiles/hPtSpectrumBplusPbPb_roofit_Inc.root"

if [ $DOANALYSISPP_FIT_Inc -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "ppInc" "$OUTPUTFILEPPSAVEHIST_Inc" "plotFits/plotFits_Inc" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_Inc -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_Inc" "$OUTPUTFILEPPSAVEHIST_Inc" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "ppInc" "$OUTPUTFILEPP_Inc" "plotFits/plotFitsOnSaved_Inc" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_Inc -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"ppInc\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_Inc\"','\"plotFits/plotFits_roofit_Inc\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_Inc -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_Inc\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_Inc\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"ppInc\"','\"$OUTPUTFILEPP_ROOFIT_Inc\"','\"plotFits/plotFitsOnSaved_roofit_Inc\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_FIT_Inc -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "PbPbInc" "$OUTPUTFILEPbPbSAVEHIST_Inc" "plotFits/plotFits_Inc" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_FITONSAVED_Inc -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST_Inc" "$OUTPUTFILEPbPbSAVEHIST_Inc" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "PbPbInc" "$OUTPUTFILEPbPb_Inc" "plotFits/plotFitsOnSaved_Inc" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi 

if [ $DOANALYSISPbPb_ROOFIT_Inc -eq 1 ]; then      
root -b -q 'roofitB.C++('1','0','\"$INPUTDATAPbPbCANDWISE\"','\"$INPUTMCPbPbCANDWISE\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"PbPbInc\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_Inc\"','\"plotFits/plotFits_roofit_Inc\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPbPb_ROOFITONSAVED_Inc -eq 1 ]; then      
root -b -q 'roofitB.C++('1','1','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_Inc\"','\"$OUTPUTFILEPbPbSAVEHIST_ROOFIT_Inc\"','\"Bpt\"','\"$TRGPbPb\"','\"$CUTPbPb\"','\"$SELGENPbPb\"','$ISMCPbPb','1','$ISDOWEIGHTPbPb','\"PbPbInc\"','\"$OUTPUTFILEPbPb_ROOFIT_Inc\"','\"plotFits/plotFitsOnSaved_roofit_Inc\"','\"$NPROOFIT_PbPb\"','0','$CENTPbPbMIN','$CENTPbPbMAX')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

#########################################
### below are unrelated to main results
#########################################

### pp 3-bin result

FONLLOUTPUTFILE_750="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4_750.root"
OUTPUTFILEPPSAVEHIST_750="ROOTfiles/hPtSpectrumSaveHistBplusPP_750.root"
OUTPUTFILEPP_750="ROOTfiles/hPtSpectrumBplusPP_750.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_750="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_750.root"
OUTPUTFILEPP_ROOFIT_750="ROOTfiles/hPtSpectrumBplusPP_roofit_750.root"
OUTPUTFILEMCSTUDYPP_750="ROOTfiles/MCstudiesPP_750.root"
OUTPUTFILEPlotPP_750="ROOTfiles/CrossSectionPP_750.root"

if [ $DOANALYSISPP_FONLL_750 -eq 1 ]; then      
g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
./Bplusdsigmadpt.exe "$FONLLDATINPUT" "$FONLLOUTPUTFILE_750" "$LABELPP" 2
rm Bplusdsigmadpt.exe
fi 

if [ $DOANALYSISPP_FIT_750 -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt750" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_750" "plotFits/plotFits_750" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_750 -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_750" "$OUTPUTFILEPPSAVEHIST_750" "Bpt750" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_750" "plotFits/plotFitsOnSaved_750" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_750 -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt750\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_750\"','\"plotFits/plotFits_roofit_750\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_750 -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_750\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_750\"','\"Bpt750\"','\"$TRGPP\"','\"$CUTPP\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_750\"','\"plotFits/plotFitsOnSaved_roofit_750\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_750 -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt750" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_750" "plotEff/plotEff_750" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt750" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_750" "plotEff/plotEff_750" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_750 -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE_750" "$OUTPUTFILEPP_750" "$OUTPUTFILEMCSTUDYPP_750" "$OUTPUTFILEPlotPP_750" "plotCrossSection/plotCrossSection_750" 0 "$LABELPP" 2 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE_750" "$OUTPUTFILEPP_ROOFIT_750" "$OUTPUTFILEMCSTUDYPP_750" "$OUTPUTFILEPlotPP_750" "plotCrossSection/plotCrossSection_750" 0 "$LABELPP" 2 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi

### pp cut base MVA (CUTBASE)

CUTPPTEST1=${BASECUTPP}"&&Btrk1Pt>1.2&&Btrk2Pt>1.2&&abs(Btrk1Eta)<2.2&&abs(Btrk2Eta)<2.2&&abs(Btrk1Dxy/Btrk1D0Err)>2.0&&abs(Btrk2Dxy/Btrk2D0Err)>2.0&&abs(Btktkmass-1.019455)<0.01&&BsvpvDistance/BsvpvDisErr>1.0&&Balpha<2.0"
CUTPPTEST2=${BASECUTPP}"&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&abs(Btrk1Dxy/Btrk1D0Err)>2.0&&abs(Btrk2Dxy/Btrk2D0Err)>2.0&&abs(Btktkmass-1.019455)<0.1&&BsvpvDistance/BsvpvDisErr>3.0&&Balpha<1.0"
CUTPPGA=${BASECUTPP}"&&((Bpt>7&&Bpt<15&&(Btrk1Pt>0.96044105851185124&&Btrk2Pt>0.47625434136305045&&abs(Btrk1Eta)<2.4147199180394177&&abs(Btrk2Eta)<2.3052611917398886&&abs(Btrk1Dxy/Btrk1D0Err)>-0.50700522672246873&&abs(Btrk2Dxy/Btrk2D0Err)>-0.29258267190923393&&abs(Btktkmass-1.019455)<0.011577334741913982&&BsvpvDistance/BsvpvDisErr>-38.83571176258711&&Balpha<3.104092988813095&&Bd0/Bd0Err>510.17997420026234&&cos(Bdtheta)>-0.40326844831704939&&Bchi2cl>0.0048939239665767064))||(Bpt>15&&Bpt<50&&(Btrk1Pt>0.88010392070518972&&Btrk2Pt>0.74630343789870546&&abs(Btrk1Eta)<2.2626072028730744&&abs(Btrk2Eta)<2.4187801371666175&&abs(Btrk1Dxy/Btrk1D0Err)>-0.30170714307721802&&abs(Btrk2Dxy/Btrk2D0Err)>-1.2682355606270277&&abs(Btktkmass-1.019455)<0.014813912795464632&&BsvpvDistance/BsvpvDisErr>-56.600106798148566&&Balpha<2.5800384512856156&&Bd0/Bd0Err>397.24968036422979&&cos(Bdtheta)>-0.63456958254017426&&Bchi2cl>0.015022113220583305)))"
CUTPPSA=${BASECUTPP}"&&((Bpt>7&&Bpt<15&&(Btrk1Pt>0.71565632117161249&&Btrk2Pt>0.62671842469539352&&abs(Btrk1Eta)<2.3207630900394727&&abs(Btrk2Eta)<2.236847801435355&&abs(Btrk1Dxy/Btrk1D0Err)>-0.38577601161179392&&abs(Btrk2Dxy/Btrk2D0Err)>-0.16309354096390094&&abs(Btktkmass-1.019455)<0.014545888171388814&&BsvpvDistance/BsvpvDisErr>-42.596270959847509&&Balpha<2.7652295615929741&&Bd0/Bd0Err>802.63077836893149&&cos(Bdtheta)>0.43368262385321005&&Bchi2cl>0.028789996308814111))||(Bpt>15&&Bpt<50&&(Btrk1Pt>0.91356686474361837&&Btrk2Pt>0.19171506036885516&&abs(Btrk1Eta)<2.3392715226530796&&abs(Btrk2Eta)<2.3078365882854683&&abs(Btrk1Dxy/Btrk1D0Err)>-0.11454398324021145&&abs(Btrk2Dxy/Btrk2D0Err)>-0.19920443359320594&&abs(Btktkmass-1.019455)<0.013306526456497065&&BsvpvDistance/BsvpvDisErr>-15.959551234787837&&Balpha<2.8647447058466882&&Bd0/Bd0Err>860.06669582941322&&cos(Bdtheta)>-0.23202397218792103&&Bchi2cl>0.0043531031731609809)))"
#CUTPPCUTBASE=${CUTPPTEST1}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
#CUTPPCUTBASE=${CUTPPTEST2}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
CUTPPCUTBASE=${CUTPPGA}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
#CUTPPCUTBASE=${CUTPPSA}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
SELGENPPACCPPCUTBASE="TMath::Abs(Gy)<2.4&&abs(GpdgId)==531&&GisSignal>0&&((TMath::Abs(Gmu1eta)<1.2&&Gmu1pt>3.5)||(TMath::Abs(Gmu1eta)>1.2&&TMath::Abs(Gmu1eta)<2.1&&Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta)))||(TMath::Abs(Gmu1eta)>2.1&&TMath::Abs(Gmu1eta)<2.4&&Gmu1pt>1.8))&&((TMath::Abs(Gmu2eta)<1.2&&Gmu2pt>3.5)||(TMath::Abs(Gmu2eta)>1.2&&TMath::Abs(Gmu2eta)<2.1&&Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta)))||(TMath::Abs(Gmu2eta)>2.1&&TMath::Abs(Gmu2eta)<2.4&&Gmu2pt>1.8))&&Gtk1pt>0.&&Gtk2pt>0.&&TMath::Abs(Gtk1eta)<2.4&&TMath::Abs(Gtk2eta)<2.4"
OUTPUTFILEPPSAVEHIST_CUTBASE="ROOTfiles/hPtSpectrumSaveHistBplusPP_CUTBASE.root"
OUTPUTFILEPP_CUTBASE="ROOTfiles/hPtSpectrumBplusPP_CUTBASE.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_CUTBASE="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_CUTBASE.root"
OUTPUTFILEPP_ROOFIT_CUTBASE="ROOTfiles/hPtSpectrumBplusPP_roofit_CUTBASE.root"
OUTPUTFILEMCSTUDYPP_CUTBASE="ROOTfiles/MCstudiesPP_CUTBASE.root"
OUTPUTFILEPlotPP_CUTBASE="ROOTfiles/CrossSectionPP_CUTBASE.root"

if [ $DOANALYSISPP_FIT_CUTBASE -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$CUTPPCUTBASE" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_CUTBASE" "plotFits/plotFits_CUTBASE" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_CUTBASE -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_CUTBASE" "$OUTPUTFILEPPSAVEHIST_CUTBASE" "Bpt" "$TRGPP" "$CUTPPCUTBASE" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_CUTBASE" "plotFits/plotFitsOnSaved_CUTBASE" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_CUTBASE -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPPCANDWISE\"','\"$INPUTMCPPCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPCUTBASE\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_CUTBASE\"','\"plotFits/plotFits_roofit_CUTBASE\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_CUTBASE -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_CUTBASE\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_CUTBASE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPCUTBASE\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_CUTBASE\"','\"plotFits/plotFitsOnSaved_roofit_CUTBASE\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_CUTBASE -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP" "$SELGENPPACCPPCUTBASE" "$RECOONLYPP" "$CUTPPCUTBASE&&$TRGPPMC" "BptCutBase" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_CUTBASE" "plotEff/plotEff_CUTBASE" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPPCUTBASE" "$RECOONLYPP" "$CUTPPCUTBASE&&$TRGPPMC" "BptCutBase" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_CUTBASE" "plotEff/plotEff_CUTBASE" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_CUTBASE -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_CUTBASE" "$OUTPUTFILEMCSTUDYPP_CUTBASE" "$OUTPUTFILEPlotPP_CUTBASE" "plotCrossSection/plotCrossSection_CUTBASE" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT_CUTBASE" "$OUTPUTFILEMCSTUDYPP_CUTBASE" "$OUTPUTFILEPlotPP_CUTBASE" "plotCrossSection/plotCrossSection_CUTBASE" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi


### pp sample with PbPb MVA (BDT)

INPUTMCPP_PbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_PbPb_BDT7to50.root"
INPUTMCPP_PbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_PbPb_BDT7to50_candWise.root"
INPUTDATAPP_PbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to50.root"
INPUTDATAPP_PbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to50_candWise.root"
CUTPPPbPbBDT=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>0.213755)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>0.254413))"
CUTPPPbPbBDT=${CUTPPPbPbBDT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
OUTPUTFILEPPSAVEHIST_PbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_PbPbBDT.root"
OUTPUTFILEPP_PbPbBDT="ROOTfiles/hPtSpectrumBplusPP_PbPbBDT.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_PbPbBDT.root"
OUTPUTFILEPP_ROOFIT_PbPbBDT="ROOTfiles/hPtSpectrumBplusPP_roofit_PbPbBDT.root"
OUTPUTFILEMCSTUDYPP_PbPbBDT="ROOTfiles/MCstudiesPP_PbPbBDT.root"
OUTPUTFILEPlotPP_PbPbBDT="ROOTfiles/CrossSectionPP_PbPbBDT.root"

if [ $DOANALYSISPP_FIT_PbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP_PbPbBDTCANDWISE" "$INPUTMCPP_PbPbBDTCANDWISE" "Bpt" "$TRGPP" "$CUTPPPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "plotFits/plotFits_PbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_PbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "$OUTPUTFILEPPSAVEHIST_PbPbBDT" "Bpt" "$TRGPP" "$CUTPPPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_PbPbBDT" "plotFits/plotFitsOnSaved_PbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_PbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPP_PbPbBDTCANDWISE\"','\"$INPUTMCPP_PbPbBDTCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"plotFits/plotFits_roofit_PbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_PbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_PbPbBDT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_PbPbBDT\"','\"plotFits/plotFitsOnSaved_roofit_PbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_PbPbBDT -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP_PbPbBDT" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPPPbPbBDT&&$TRGPPMC" "BptPbPbBDT" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "plotEff/plotEff_PbPbBDT" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPP_PbPbBDTCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPPPbPbBDT&&$TRGPPMC" "BptPbPbBDT" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "plotEff/plotEff_PbPbBDT" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_PbPbBDT -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_PbPbBDT" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "$OUTPUTFILEPlotPP_PbPbBDT" "plotCrossSection/plotCrossSection_PbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT_PbPbBDT" "$OUTPUTFILEMCSTUDYPP_PbPbBDT" "$OUTPUTFILEPlotPP_PbPbBDT" "plotCrossSection/plotCrossSection_PbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi

### pp sample with Old PbPb MVA (BDT)

INPUTMCPP_OLDPbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_20180223PbPbBDT.root"
INPUTMCPP_OLDPbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_BsToJpsiPhi_Pythia8_5p02_20180314_bPt0tkPt0MuAll_Bs_pthatweight_BDT7to50_20180223PbPbBDT_candWise.root"
INPUTDATAPP_OLDPbPbBDT="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50_20180223PbPbBDT.root"
INPUTDATAPP_OLDPbPbBDTCANDWISE="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderData_pp_20180314_bPt0tkPt0MuAll_Bs_BDT7to50_20180223PbPbBDT_candWise.root"
CUTPPOLDPbPbBDT=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15_20180223MVA>0.245684)||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50_20180223MVA>0.255746))&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
CUTPPOLDPbPbBDT=${CUTPPOLDPbPbBDT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
OUTPUTFILEPPSAVEHIST_OLDPbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_OLDPbPbBDT.root"
OUTPUTFILEPP_OLDPbPbBDT="ROOTfiles/hPtSpectrumBplusPP_OLDPbPbBDT.root"
OUTPUTFILEPPSAVEHIST_ROOFIT_OLDPbPbBDT="ROOTfiles/hPtSpectrumSaveHistBplusPP_roofit_OLDPbPbBDT.root"
OUTPUTFILEPP_ROOFIT_OLDPbPbBDT="ROOTfiles/hPtSpectrumBplusPP_roofit_OLDPbPbBDT.root"
OUTPUTFILEMCSTUDYPP_OLDPbPbBDT="ROOTfiles/MCstudiesPP_OLDPbPbBDT.root"
OUTPUTFILEPlotPP_OLDPbPbBDT="ROOTfiles/CrossSectionPP_OLDPbPbBDT.root"

if [ $DOANALYSISPP_FIT_OLDPbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPP_OLDPbPbBDTCANDWISE" "$INPUTMCPP_OLDPbPbBDTCANDWISE" "Bpt" "$TRGPP" "$CUTPPOLDPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_OLDPbPbBDT" "plotFits/plotFits_OLDPbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_FITONSAVED_OLDPbPbBDT -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 1 "$OUTPUTFILEPPSAVEHIST_OLDPbPbBDT" "$OUTPUTFILEPPSAVEHIST_OLDPbPbBDT" "Bpt" "$TRGPP" "$CUTPPOLDPbPbBDT" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_OLDPbPbBDT" "plotFits/plotFitsOnSaved_OLDPbPbBDT" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_ROOFIT_OLDPbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','0','\"$INPUTDATAPP_OLDPbPbBDTCANDWISE\"','\"$INPUTMCPP_OLDPbPbBDTCANDWISE\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPOLDPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_OLDPbPbBDT\"','\"plotFits/plotFits_roofit_OLDPbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_ROOFITONSAVED_OLDPbPbBDT -eq 1 ]; then      
root -b -q 'roofitB.C++('0','1','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_OLDPbPbBDT\"','\"$OUTPUTFILEPPSAVEHIST_ROOFIT_OLDPbPbBDT\"','\"Bpt\"','\"$TRGPP\"','\"$CUTPPOLDPbPbBDT\"','\"$SELGENPP\"','$ISMCPP','1','$ISDOWEIGHTPP','\"$LABELPP\"','\"$OUTPUTFILEPP_ROOFIT_OLDPbPbBDT\"','\"plotFits/plotFitsOnSaved_roofit_OLDPbPbBDT\"','\"$NPROOFIT_PP\"','0','0','100')'
rm roofitB_C.d roofitB_C_ACLiC_dict_rdict.pcm roofitB_C.so
fi 

if [ $DOANALYSISPP_MCSTUDY_OLDPbPbBDT -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP_OLDPbPbBDT" "$SELGENPP" "$SELGENPPACCPP&&Gtk1pt>0.8&&Gtk2pt>0.8" "$RECOONLYPP" "$CUTPPOLDPbPbBDT&&$TRGPPMC" "BptOLDPbPbBDT" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_OLDPbPbBDT" "plotEff/plotEff_OLDPbPbBDT" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPP_OLDPbPbBDTCANDWISE" "$SELGENPP" "$SELGENPPACCPP&&Gtk1pt>0.8&&Gtk2pt>0.8" "$RECOONLYPP" "$CUTPPOLDPbPbBDT&&$TRGPPMC" "BptOLDPbPbBDT" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_OLDPbPbBDT" "plotEff/plotEff_OLDPbPbBDT" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

if [ $DOANALYSISPP_CROSS_OLDPbPbBDT -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
#./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_OLDPbPbBDT" "$OUTPUTFILEMCSTUDYPP_OLDPbPbBDT" "$OUTPUTFILEPlotPP_OLDPbPbBDT" "plotCrossSection/plotCrossSection_OLDPbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
./CrossSectionRatio.exe "$FONLLOUTPUTFILE" "$OUTPUTFILEPP_ROOFIT_OLDPbPbBDT" "$OUTPUTFILEMCSTUDYPP_OLDPbPbBDT" "$OUTPUTFILEPlotPP_OLDPbPbBDT" "plotCrossSection/plotCrossSection_OLDPbPbBDT" 0 "$LABELPP" 0 0 "$LUMIPP" "0" "100"
rm CrossSectionRatio.exe
fi

### pp 4-bin result for acceptance

OUTPUTFILEPPSAVEHIST_750_acc="ROOTfiles/hPtSpectrumSaveHistBplusPP_750_acc.root"
OUTPUTFILEMCSTUDYPP_750_acc="ROOTfiles/MCstudiesPP_750_acc.root"

if [ $DOANALYSISPP_FIT_750_acc -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt750_acc" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_750_acc" "plotFits/plotFits_750_acc" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_MCSTUDY_750_acc -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt750_acc" "Gpt" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_750_acc" "plotEff/plotEff_750_acc" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

### Rapidity result for acceptance

OUTPUTFILEPPSAVEHIST_Y="ROOTfiles/hPtSpectrumSaveHistBplusPP_Y.root"
OUTPUTFILEMCSTUDYPP_Y="ROOTfiles/MCstudiesPP_Y.root"
if [ $DOANALYSISPP_FIT_Y -eq 1 ]; then      
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
#./fitB.exe 0 0 "$INPUTDATAPP" "$INPUTMCPP" "abs(By)" "$TRGPP" "$CUTPP&&Bpt>15&&Bpt<50" "$SELGENPP&&Gpt>15&&Gpt<50" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_Y" "plotFits/plotFits_Y" "$NPFIT_PP" 0 "0" "100"
./fitB.exe 0 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "abs(By)" "$TRGPP" "$CUTPP&&Bpt>7&&Bpt<50" "$SELGENPP&&Gpt>15&&Gpt<50" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPPSAVEHIST_Y" "plotFits/plotFits_Y" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
fi 

if [ $DOANALYSISPP_MCSTUDY_Y -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPP" "$SELGENPP&&Gpt>15&&Gpt<50" "$SELGENPPACCPP&&Gpt>15&&Gpt<50" "$RECOONLYPP&&Bpt>15&&Bpt<50" "$CUTPP&&$TRGPPMC&&Bpt>15&&Bpt<50" "abs(By)" "abs(Gy)" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_Y" "plotEff/plotEff_Y" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP&&Gpt>15&&Gpt<50" "$SELGENPPACCPP&&Gpt>15&&Gpt<50" "$RECOONLYPP&&Bpt>15&&Bpt<50" "$CUTPP&&$TRGPPMC&&Bpt>15&&Bpt<50" "abs(By)" "abs(Gy)" "$LABELPP" "$OUTPUTFILEMCSTUDYPP_Y" "plotEff/plotEff_Y" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
fi

### Reweighting

if [ $DOPTREWEIGHT -eq 1 ]; then
#g++ Bplusdsigmadpt.cc $(root-config --cflags --libs) -g -o Bplusdsigmadpt.exe 
#./Bplusdsigmadpt.exe "$FONLLDATINPUT"  "$FONLLOUTPUTFILEREWEIGHT" "$LABELPP" 1
#rm Bplusdsigmadpt.exe
root -b -q weightMCpp.C++
rm weightMCpp_C.d weightMCpp_C.so weightMCpp_C_ACLiC_dict_rdict.pcm
root -b -q weightMCPbPb.C++
rm weightMCPbPb_C.d weightMCPbPb_C.so weightMCPbPb_C_ACLiC_dict_rdict.pcm
fi

### CLOSURE TEST

if [ $DOClosure -eq 1 ]; then      

OUTPUTFILEPPMCClosure="ROOTfiles/hPtSpectrumBplusPPMCClosure.root"
LUMIPPMCClosure=1
ISMCPPMCClosure=1
ISDOWEIGHTPPMCClosure=0
TRGPPMCClosure="1"
LABELPPMCClosure="PPMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 0 0 "$INPUTMCPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPPMCClosure" "$CUTPP"   "$SELGENPP"   "$ISMCPPMCClosure"   "$LUMIPPMCClosure"   "$ISDOWEIGHTPPMCClosure"   "$LABELPPMCClosure"  "$OUTPUTFILEPPMCClosure" "plotClosure" "$NPFIT_PP" 0 "0" "100"
rm fitB.exe
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPPMCClosure" "$LABELPP"

OUTPUTFILEPbPbMCClosure="ROOTfiles/hPtSpectrumBplusPbPbMCClosure.root"
LUMIPbPbMCClosure=1
ISMCPbPbMCClosure=1
ISDOWEIGHTPbPbMCClosure=0
TRGPbPbMCClosure="1"
LABELPbPbMCClosure="PbPbMCClosure"

g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe 
./fitB.exe 1 0 "$INPUTMCPbPbCANDWISE"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMCClosure" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPbMCClosure"   "$LUMIPbPbMCClosure"   "$ISDOWEIGHTPbPbMCClosure"   "$LABELPbPbMCClosure"  "$OUTPUTFILEPbPbMCClosure" "plotClosure" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
g++ ClosureTest.C $(root-config --cflags --libs) -g -o ClosureTest.exe 
./ClosureTest.exe "$OUTPUTFILEPbPbMCClosure" "$LABELPbPb"
rm ClosureTest.exe

fi

### Project some varibles

if [ $PROJECTVAR -eq 1 ]; then      
g++ plotSth.C $(root-config --cflags --libs) -g -o plotSth.exe 
./plotSth.exe 0 "$INPUTDATAPPCANDWISE" "$INPUTMCPPCANDWISE" "Bpt" "$TRGPP" "$TRGPPMC" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "" "plotSth" "$NPFIT_PP" 0 "0" "100"
./plotSth.exe 1 "$INPUTDATAPbPbCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPbPb" "$TRGPbPbMC" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "" "plotSth" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm plotSth.exe
fi 

### MC pp PbPb comparison

CUT=${BASECUTPbPb}
#CUT=${CUT}"&&Btrk1Pt>0.8&&Btrk2Pt>0.8"
_MCCUTPP=${CUT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
_MCCUTPbPb=${CUT}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
 
if [ $DOVARCOMPARE_MC -eq 1 ]; then      
g++ fitCompareMC.C $(root-config --cflags --libs) -g -o fitCompareMC.exe 
#./fitCompareMC.exe 0 "$INPUTMCPPCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPPMC" "$TRGPbPbMC" "$_MCCUTPP" "$_MCCUTPbPb" "$ISMCPP" 0 21 "$LABELPP" "" "plotCompMC" "$NPFIT_PP" 0 "0" "100"
./fitCompareMC.exe 0 "$INPUTMCPP_PbPbBDTCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPPMC" "$TRGPbPbMC" "$_MCCUTPP" "$_MCCUTPbPb" "$ISMCPP" 21 23 "$LABELPP" "" "plotCompMC" "$NPFIT_PP" 0 "0" "100"
#./fitCompareMC.exe 0 "$INPUTMCPPCANDWISE" "$INPUTMCPbPbCANDWISE" "Bpt" "$TRGPPMC" "$TRGPbPbMC" "$_MCCUTPP" "$_MCCUTPbPb" "$ISMCPP" 21 23 "$LABELPP" "" "plotCompMC" "$NPFIT_PP" 0 "0" "100"
rm fitCompareMC.exe
fi 

### Data - MC comparison

if [ $DOVARCOMPARE_PP -eq 1 ]; then      
g++ fitVariables.C $(root-config --cflags --libs) -g -o fitVariables.exe 
CUT=$CUTPP
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"                   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 0
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 1
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 2
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 3
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 4
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 5
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 6
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 7
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 8
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 9
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 10
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 11
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 12
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 13
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 14
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 15
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 16
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 17
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 18

#CUT=${BASECUTPP}
#CUT=${CUT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 19
#./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 20
##./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<15"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 19
##./fitVariables.exe 0 0 "$INPUTDATAPPCANDWISE"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 20
#./fitVariables.exe 0 0 "$INPUTDATAPP_PbPbBDTCANDWISE"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 21
#./fitVariables.exe 0 0 "$INPUTDATAPP_PbPbBDTCANDWISE"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 22
##./fitVariables.exe 0 0 "$INPUTDATAPP_PbPbBDTCANDWISE"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>7&&Bpt<15"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 21
##./fitVariables.exe 0 0 "$INPUTDATAPP_PbPbBDTCANDWISE"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPP" "$TRGPPMC" "$CUT&&Bpt>15&&Bpt<50"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "" "$NPFIT_PP" 0 "0" "100" 22
rm fitVariables.exe
fi 

### Checking prompt background structure

if [ $CHECKPROMPT -eq 1 ]; then      
g++ fitPrompt.C $(root-config --cflags --libs) -g -o fitPrompt.exe 

#INPUTPROMPTPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs.root"
INPUTPROMPTPP="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples//Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs.root"
#INPUTPROMPTPPMVA1="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs_pp_BDT7to15.root"
#INPUTPROMPTPPMVA2="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs_pp_BDT15to50.root"
INPUTPROMPTPPMVA1="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs_pp_BDT7to15.root"
INPUTPROMPTPPMVA2="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs_pp_BDT15to50.root"
INPUTPROMPTPPMVA1="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPPMVA1}
INPUTPROMPTPPMVA2="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPPMVA2}
INPUTPROMPTMVA=${INPUTPROMPTPPMVA1}";"${INPUTPROMPTPPMVA2}
OUTPUTPROMPTPP="plotChecksPrompt/pp"
CUT=${BASECUTPP}
CUT=${CUT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
PPBDTCUTVAL=(0.191055 0.208973)
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PPBDTCUTVAL[0]}"-0.0))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PPBDTCUTVAL[1]}"-0.0)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_d4.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTd4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PPBDTCUTVAL[0]}"-0.2))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PPBDTCUTVAL[1]}"-0.2)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p2.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTm0p2" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PPBDTCUTVAL[0]}"-0.4))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PPBDTCUTVAL[1]}"-0.4)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p4.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTm0p4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PPBDTCUTVAL[0]}"-0.6))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PPBDTCUTVAL[1]}"-0.6)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPPCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p6.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "BDTm0p6" ${INPUTPROMPTMVA}

#INPUTPROMPTPPMVA1="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to15.root"
#INPUTPROMPTPPMVA2="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT15to50.root"
INPUTPROMPTPPMVA1="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to15.root"
INPUTPROMPTPPMVA2="Bntuple20180316_bPt0_BfinderMC_pp_JpsiMM_5p02TeV_TuneCUETP8M1_ext_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT15to50.root"
INPUTPROMPTPPMVA1="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPPMVA1}
INPUTPROMPTPPMVA2="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPPMVA2}
INPUTPROMPTMVA=${INPUTPROMPTPPMVA1}";"${INPUTPROMPTPPMVA2}
OUTPUTPROMPTPP="plotChecksPrompt/pp_PbPbBDT"
CUT=${BASECUTPbPb}
CUT=${CUT}"&&abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter"
PbPbBDTCUTVAL=(0.213755 0.254413)
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.0))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.0)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_d4.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "PbPbBDTd4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.2))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.2)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p2.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "PbPbBDTm0p2" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.4))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.4)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p4.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "PbPbBDTm0p4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.6))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.6)))"
#./fitPrompt.exe 0 0 "$INPUTPROMPTPP"  "$INPUTMCPP_PbPbBDTCANDWISE"  "Bpt" "$TRGPPMC" "$CUTWITHBDT"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "${OUTPUTPROMPTPP}_m0p6.root" "plotChecksPrompt" "$NPFIT_PP" 0 "0" "100" "PbPbBDTm0p6" ${INPUTPROMPTMVA}

INPUTPROMPTPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs.root"
INPUTPROMPTPbPbMVA1="Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to15.root"
INPUTPROMPTPbPbMVA2="Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT15to50.root"
INPUTPROMPTPbPbMVA1="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPbPbMVA1}
INPUTPROMPTPbPbMVA2="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPbPbMVA2}
INPUTPROMPTMVA=${INPUTPROMPTPbPbMVA1}";"${INPUTPROMPTPbPbMVA2}
OUTPUTPROMPTPbPb="plotChecksPrompt/pbpb"
CUT=${BASECUTPbPb}
CUT=${CUT}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.0))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.0)))"
#./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_d4.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTd4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.2))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.2)))"
#./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p2.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p2" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.4))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.4)))"
#./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p4.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p4" ${INPUTPROMPTMVA}
#CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.6))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.6)))"
#./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p6.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p6" ${INPUTPROMPTMVA}

for f in 00_03 03_06 06_09 09_12 12_15 15_30 30_Inf
do
	INFIX=""
	if [ $f = "03_06" ] || [ $f = "06_09" ] ; then
		INFIX="_ext"
	fi
	SUBD="folder_PbPb_"$f
	INPUTPROMPTPbPb="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/samples/Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM/Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_"$f$INFIX"_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs.root"
	INPUTPROMPTPbPbMVA1="Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_"$f$INFIX"_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT7to15.root"
	INPUTPROMPTPbPbMVA2="Bntuple20180316_bPt0_BfinderMC_PbPb_JpsiMM_ptJpsi_"$f$INFIX"_Hydjet_MB_20180314_bPt0tkPt0MuAll_Bs_PbPb_BDT15to50.root"
	INPUTPROMPTPbPbMVA1="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPbPbMVA1}
	INPUTPROMPTPbPbMVA2="/export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BsTMVA/TMVA_Bs-20180317-study/nominal/TMVA_Bs-20180317-tkPt0-phi0p015-HPtag-more_evtWiseProd/tmvaVal/prod/"${INPUTPROMPTPbPbMVA2}
	INPUTPROMPTMVA=${INPUTPROMPTPbPbMVA1}";"${INPUTPROMPTPbPbMVA2}
	OUTPUTPROMPTPbPb="plotChecksPrompt/pbpb_$f"
	CUT=${BASECUTPbPb}
	CUT=${CUT}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3"
#	CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.0))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.0)))"
#	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_d4.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTd4_$f" ${INPUTPROMPTMVA}
#	CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.2))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.2)))"
#	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p2.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p2_$f" ${INPUTPROMPTMVA}
#	CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.4))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.4)))"
#	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p4.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p4_$f" ${INPUTPROMPTMVA}
#	CUTWITHBDT=${CUT}"&&((Bpt>7&&Bpt<15&&BDTStage1_pt7to15>("${PbPbBDTCUTVAL[0]}"-0.6))||(Bpt>15&&Bpt<50&&BDTStage1_pt15to50>("${PbPbBDTCUTVAL[1]}"-0.6)))"
#	./fitPrompt.exe 1 0 "$INPUTPROMPTPbPb"  "$INPUTMCPbPbCANDWISE"  "Bpt" "$TRGPbPbMC" "$CUTWITHBDT"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "${OUTPUTPROMPTPbPb}_m0p6.root" "plotChecksPrompt" "$NPFIT_PbPb" 0 "0" "100" "BDTm0p6_$f" ${INPUTPROMPTMVA}
done

rm fitPrompt.exe
fi 

### PDF Syst.
OUTPUTFILEPP_PDFSYST="plotPDFSyst/hPtSpectrumBplusPP_PDFSyst.root"
OUTPUTFILEPbPb_PDFSYST="plotPDFSyst/hPtSpectrumBplusPbPb_PDFSyst.root"
if [ $DOPDFSYST -eq 1 ]; then      
g++ fitPDFSyst.C $(root-config --cflags --libs) -g -o fitPDFSyst.exe 
./fitPDFSyst.exe 0 1 "$OUTPUTFILEPPSAVEHIST" "$OUTPUTFILEPPSAVEHIST" "Bpt" "$TRGPP" "$CUTPP" "$SELGENPP" "$ISMCPP" 1 "$ISDOWEIGHTPP" "$LABELPP" "$OUTPUTFILEPP_PDFSYST" "plotPDFSyst" "$NPFIT_PP" 0 "0" "100"
./fitPDFSyst.exe 1 1 "$OUTPUTFILEPbPbSAVEHIST" "$OUTPUTFILEPbPbSAVEHIST" "Bpt" "$TRGPbPb" "$CUTPbPb" "$SELGENPbPb" "$ISMCPbPb" 1 "$ISDOWEIGHTPbPb" "$LABELPbPb" "$OUTPUTFILEPbPb_PDFSYST" "plotPDFSyst" "$NPFIT_PbPb" 0 "0" "100"
rm fitPDFSyst.exe
fi 

### Pt Shape Syst.
if [ $DOPTSHAPESYST -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt_noPtWeight" "Gpt" "$LABELPP" "plotPtShapeSyst/MCstudiesPP.root" "plotPtShapeSyst/plotPtShapeSyst" "$ISDOWEIGHTPP" "0" "100"
./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt_noPtWeight" "Gpt" "$LABELPbPb" "plotPtShapeSyst/MCstudiesPbPb.root" "plotPtShapeSyst/plotPtShapeSyst" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt750_noPtWeight" "Gpt" "$LABELPP" "plotPtShapeSyst/MCstudiesPP_750.root" "plotPtShapeSyst/plotPtShapeSyst_750" "$ISDOWEIGHTPP" "0" "100"
rm MCefficiency.exe
cd plotPtShapeSyst
root -b -q getPtShapeSyst.C++
rm getPtShapeSyst_C.d getPtShapeSyst_C.so getPtShapeSyst_C_ACLiC_dict_rdict.pcm
cd -
fi

### Track Eta Weight Syst.
if [ $DOTKETAWEIGHTSYST -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
#./MCefficiency.exe 0 "$INPUTMCPPCANDWISE" "$SELGENPP" "$SELGENPPACCPP" "$RECOONLYPP" "$CUTPP&&$TRGPPMC" "Bpt_tkEtaWeight" "Gpt" "$LABELPP" "plotTkEtaWeightSyst/MCstudiesPP.root" "plotTkEtaWeightSyst/plotTkEtaWeightSyst" "$ISDOWEIGHTPP" "0" "100"
#./MCefficiency.exe 1 "$INPUTMCPbPbCANDWISE" "$SELGENPbPb" "$SELGENPbPbACCPbPb" "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC" "Bpt_tkEtaWeight" "Gpt" "$LABELPbPb" "plotTkEtaWeightSyst/MCstudiesPbPb.root" "plotTkEtaWeightSyst/plotTkEtaWeightSyst" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
cd plotTkEtaWeightSyst 
root -b -q getTkEtaWeightSyst.C++
rm getTkEtaWeightSyst_C.d getTkEtaWeightSyst_C.so getTkEtaWeightSyst_C_ACLiC_dict_rdict.pcm
cd -
fi
