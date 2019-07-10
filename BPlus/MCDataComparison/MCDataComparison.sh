

doppComparison=0
doPbPbComparison=1
doShapePbPb=0
doReweightPbPb=0
doCentReweightPbPbBP=0
doCentReweightPbPbBs=0
doCentTree=0
WithCentWeights=1
WithWeights=1




#ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/skim_Dntuple_crab_pp_MinimumBias1to20_AOD_D0Dsy1p1_tkpt0p5eta2p0_04122016.root"
#ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/ntD_EvtBase_20161206_DfinderMC_pp_20160502_dPt0tkPt0p5_D0_prompt_Dpt1Dy1p5tkPt0p5Decay2p9Dalpha0p14Skim_pthatweight.root"
#PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/ntD_EvtBase_20170328_DfinderData_PAMinimumBias1-8_PbPb_20170328_PARun2016B_PromptReco_v1_D0_dPt0tkPt0p2_Dalpha0p14Dchi20p05_LowDsvpv6Dchi20p15_HightkPt0p5.root"
#PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/PbPbMC/Prompt/PbPbPrompt.root"


#ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/NewAnalysisSamples/ppData/ppAll.root"
#ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/NewAnalysisSamples/ppMC/Pthat0/Pthat0.root"

#ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/TMVAVeryLowCheck/Data_D0_pp_TMVA_BDTG_pp.root"
#ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/Unskim2/ppUnskim2.root"
CentOutFile="CentOut.root"

ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ppReweightStudy/Data/PD23.root"
ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ppReweightStudy/MC/MC.root"





#PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BTMVA/TMVAMerge2/Data_D0_pp_TMVA_BDTG_pp.root"
#PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BTMVA/TMVAMerge2/MC_D0_pp_TMVA_BDTG_pp.root"

#PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsRAA2015RunII/PthatService/output/PthatMergedreweighted.root"
#PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4Bins/Data_Bs_pp_TMVA_BDT_pp.root"

#PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ForJulia/crab_Bfinder_20190221_Pythia8_BuToJpsiK_Bpt0p0_1032_NoJSON_pthatweight_hardcut_v2.root"
#PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ForJulia/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_skimhltBsize_ntKp.root"

#PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_pthatweight.root"
PbPbMC="/export/d00/scratch/gwangjun/crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_pthatweight_hardcut.root"
PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/crab_Bfinder_20190513_HIDoubleMuon__PsiPeri__HIRun2018A_04Apr2019_v1_1033p1_GoldenJSON_skimhltBsize_ntKp.root"

PbPbMCCentWeight="crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_pthatweight_hardcut_weighted.root"


PbPbMCBs="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data/MC_Bs_PbPb_TMVA_BDT_PbPb.root"
PbPbDataBs="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data/Data_Bs_PbPb_TMVA_BDT_PbPb.root"


#PbPbData="crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_loose_skimhlt_empty.root"
#CommonCut=('Btrk1Pt > 1 && Btrk2Pt > 1 && Bchi2cl > 0.05 && BsvpvDistance/BsvpvDisErr > 2 && abs(Btrk1Eta-0.0) < 2.4  && abs(Btrk2Eta-0.0) < 2.4 &&  abs(By-0.0) < 2.4')
#CommonCut="(Dalpha < 0.20 && (DsvpvDistance/DsvpvDisErr) > 2.5 && Dchi2cl > 0.05 && Dtrk1Pt > 0.5 && Dtrk2Pt > 0.5 && Dy < 1 && Dy > -1 && abs(Dtrk1Eta) < 2.0  && abs(Dtrk2Eta) < 2.0 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3)"

#CommonCut=('Btrk1Pt>1.0 && Bpt>5.0 && (BsvpvDistance/BsvpvDisErr)>3.5 && Bchi2cl>0.05 && TMath::Abs(Btrk1Eta)<2.4 && TMath::Abs(By)<2.4 && TMath::Abs(PVz)<15 && Bmass>5 && Bmass<6 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1dxyPV<0.3 && Bmu2dxyPV<0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1InPixelLayer>0 && (Bmu1InPixelLayer+Bmu1InStripLayer)>5 && Bmu2InPixelLayer>0 && (Bmu2InPixelLayer+Bmu2InStripLayer)>5 && ((TMath::Abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (TMath::Abs(Bmu1eta)>1.2 && TMath::Abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*TMath::Abs(Bmu1eta))) || (TMath::Abs(Bmu1eta)>2.1 && TMath::Abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && TMath::Abs(Bmumumass-3.096900)<0.15 && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Btrk1highPurity && (Btrk1PixelHit+Btrk1StripHit)>=11 && (Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer))<0.18 && TMath::Abs(Btrk1PtErr/Btrk1Pt)<0.1')

CommonCut="Btrk1Pt>1.0 && Bpt>5.0 && (BsvpvDistance/BsvpvDisErr)>2.0 && Bchi2cl>0.05 && TMath::Abs(Btrk1Eta)<2.4 && TMath::Abs(By)<2.4 && TMath::Abs(PVz)<15 && Bmass>5 && Bmass<6 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1dxyPV<0.3 && Bmu2dxyPV<0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1InPixelLayer>0 && (Bmu1InPixelLayer+Bmu1InStripLayer)>5 && Bmu2InPixelLayer>0 && (Bmu2InPixelLayer+Bmu2InStripLayer)>5 && ((TMath::Abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (TMath::Abs(Bmu1eta)>1.2 && TMath::Abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*TMath::Abs(Bmu1eta))) || (TMath::Abs(Bmu1eta)>2.1 && TMath::Abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && TMath::Abs(Bmumumass-3.096900)<0.15 && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Btrk1highPurity && (Btrk1PixelHit+Btrk1StripHit)>=11 && (Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer))<0.18 && TMath::Abs(Btrk1PtErr/Btrk1Pt)<0.1 && ((Bpt>5 && Bpt<7 && (BsvpvDistance/BsvpvDisErr)>10.497 && cos(Bdtheta)>0.922 && Btrk1Pt>0.983 && Bchi2cl>0.064 && TMath::Abs(Btrk1Eta)<2.380) || (Bpt>7 && Bpt<10 && (BsvpvDistance/BsvpvDisErr)>15.208 && cos(Bdtheta)>0.966 && Btrk1Pt>0.976 && Bchi2cl>0.057) || (Bpt>10 && Bpt<15 && (BsvpvDistance/BsvpvDisErr)>7.091 && cos(Bdtheta)>0.983 && Btrk1Pt>1.540 && Bchi2cl>0.052) || (Bpt>15 && Bpt<20 && (BsvpvDistance/BsvpvDisErr)>5.884 && cos(Bdtheta)>0.616 && Btrk1Pt>1.336 && Bchi2cl>0.055) || (Bpt>20 && Bpt<30 && (BsvpvDistance/BsvpvDisErr)>3.473 && cos(Bdtheta)>-0.535 && Btrk1Pt>1.727 && Bchi2cl>0.048) || (Bpt>30 && Bpt<50 && cos(Bdtheta)>0.993 && Btrk1Pt>1.577 && Bchi2cl>0.050 && TMath::Abs(Btrk1Eta)<2.387) || (Bpt>50 && Bpt<100))"

SignalCut="$CommonCut && (abs(Bmass -  5.27925 ) < 0.08 )"
SideBandCut="$CommonCut && (abs(Bmass -  5.27925 ) > 0.15 &&  abs(Bmass -  5.27925) < 0.25)"
GenCut=" $CommonCut && (abs(Bmass -  5.27925 ) < 0.08 && Bgen == 23333)"



if [ $doShapePbPb -eq 1 ]; then
g++ ShapeVariation.C $(root-config --cflags --libs) -g -o ShapeVariation.exe 
./ShapeVariation.exe "PbPb" "$PbPbData" "$CommonCut"
fi



if [ $doppComparison -eq 1 ]; then
#SignalCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1 && Dy > -1 && abs(Dtrk1Eta) < 1.5  && abs(Dtrk2Eta) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Bmass - 1.865) < 0.02"
#SideBandCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1 && Dy > -1 && abs(Dtrk1Eta) < 1.5  && abs(Dtrk2Eta) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Bmass - 1.865) > 0.06 &&  abs(Bmass - 1.865) < 0.12"
#GenCut="Dalpha < 0.20 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1 && Dy > -1 && abs(Dtrk1Eta) < 1.5  && abs(Dtrk2Eta) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Bmass - 1.865) < 0.025 && Dgen == 23333"



g++ MCDataComparison.C $(root-config --cflags --libs) -g -o MCDataComparison.exe 
./MCDataComparison.exe "pp" "$ppData"  "$ppMC" "$SignalCut" "$SideBandCut" "$GenCut" "$CommonCut" "$WithWeights" 
rm MCDataComparison.exe
fi


#if [ $doppComparison -eq 1 ]; then
#	root -b -l -q MCDataComparison.C++'(''"'pp'"','"'$ppData'"','"'$ppMC'"','"'$SignalCut'"','"'$SideBandCut'"','"'$GenCut'"'')'
#fi


if [ $doPbPbComparison -eq 1 ]; then
#SignalCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) < 0.02"
#SideBandCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) > 0.06 &&  abs(Dmass - 1.865) < 0.12"
#GenCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) < 0.02 && Dgen == 23333"

echo "WITHWEIGHT IS = " $WithWeights "!!!!"

if [ $WithWeights -eq 0 ]; then
g++ MCDataComparison.C $(root-config --cflags --libs) -g -o MCDataComparison.exe 
./MCDataComparison.exe "PbPb" "$PbPbData"  "$PbPbMC" "$SignalCut" "$SideBandCut" "$GenCut" "$CommonCut" "$WithWeights" 
rm MCDataComparison.exe
fi

if [ $WithWeights -eq 1 ]; then
g++ MCDataComparison.C $(root-config --cflags --libs) -g -o MCDataComparison.exe 
./MCDataComparison.exe "PbPb" "$PbPbData"  "$PbPbMCCentWeight" "$SignalCut" "$SideBandCut" "$GenCut" "$CommonCut" "$WithWeights" 
rm MCDataComparison.exe
fi



fi

if [ $doReweightPbPb -eq 1 ]; then
#SignalCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) < 0.02"
#SideBandCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) > 0.06 &&  abs(Dmass - 1.865) < 0.12"
#GenCut="Dalpha < 0.10 && (DsvpvDistance/DsvpvDisErr) > 4 && Dchi2cl > 0.10 && Dtrk1Pt > 1 && Dtrk2Pt > 1 && Dy < 1.465 && Dy > -0.535 && abs(Dtrk1Eta-0.465) < 1.5  && abs(Dtrk2Eta-0.465) < 1.5 && (Dtrk1PtErr/Dtrk1Pt) < 0.3 && (Dtrk2PtErr/Dtrk2Pt) < 0.3 && Dpt > 2 && Dpt < 20 && abs(Dmass - 1.865) < 0.02 && Dgen == 23333"
root -b -l -q Reweight.C
fi


if [ $doCentReweightPbPbBP -eq 1 ]; then
g++ CentReweight.C $(root-config --cflags --libs) -g -o CentReweight.exe 
./CentReweight.exe "PbPb" "$PbPbData"  "$PbPbMC" $WithCentWeights
rm CentReweight.exe
fi


if [ $doCentReweightPbPbBs -eq 1 ]; then
g++ CentReweight.C $(root-config --cflags --libs) -g -o CentReweight.exe 
./CentReweight.exe "PbPb" "$PbPbDataBs"  "$PbPbMCBs" $WithCentWeights
rm CentReweight.exe
fi


if [ $doCentTree -eq 1 ]; then
g++ CentWeightMaker.C $(root-config --cflags --libs) -g -o CentWeightMaker.exe 
./CentWeightMaker.exe "PbPb" "$PbPbMC" "$CentOutFile"
rm CentWeightMaker.exe
fi



