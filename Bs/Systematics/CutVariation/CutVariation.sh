
doppCutVariation=0
doPbPbCutVariation=1



ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/skim_Dntuple_crab_pp_MinimumBias1to20_AOD_D0Dsy1p1_tkpt0p5eta2p0_04122016.root"
ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/ntD_EvtBase_20161206_DfinderMC_pp_20160502_dPt0tkPt0p5_D0_prompt_Dpt1Dy1p5tkPt0p5Decay2p9Dalpha0p14Skim_pthatweight.root"

PbPbData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/Data_Bs_pp_TMVA_BDT_pp.root"
PbPbMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/BsTMVA/TMVAHigh4BinsRedo/MC_Bs_pp_TMVA_BDT_pp.root"


BASECUTPbPb="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&((abs(Bmu1eta)<1.2&&Bmu1pt>3.5)||(abs(Bmu1eta)>1.2&&abs(Bmu1eta)<2.1&&Bmu1pt>(5.77-1.8*abs(Bmu1eta)))||(abs(Bmu1eta)>2.1&&abs(Bmu1eta)<2.4&&Bmu1pt>1.8))&&((abs(Bmu2eta)<1.2&&Bmu2pt>3.5)||(abs(Bmu2eta)>1.2&&abs(Bmu2eta)<2.1&&Bmu2pt>(5.77-1.8*abs(Bmu2eta)))||(abs(Bmu2eta)>2.1&&abs(Bmu2eta)<2.4&&Bmu2pt>1.8))&&Bmu1TMOneStationTight&&Bmu2TMOneStationTight&&Bmu1InPixelLayer>0&&(Bmu1InPixelLayer+Bmu1InStripLayer)>5&&Bmu2InPixelLayer>0&&(Bmu2InPixelLayer+Bmu2InStripLayer)>5&&Bmu1dxyPV<0.3&&Bmu2dxyPV<0.3&&Bmu1dzPV<20&&Bmu2dzPV<20&&Bmu1isGlobalMuon&&Bmu2isGlobalMuon&&Btrk1highPurity&&Btrk2highPurity&&abs(Btrk1Eta)<2.4&&abs(Btrk2Eta)<2.4&&Btrk1Pt>1.&&Btrk2Pt>1.&&abs(Btktkmass-1.019455)<0.015"
CUTPbPb=${BASECUTPbPb}"&&((Bpt>7&&Bpt<15&&BDT_pt_7_15>0.58)||(Bpt>15&&Bpt<20&&BDT_pt_15_20> 0.59)||(Bpt>30&&Bpt<50&&BDT_pt_20_50>0.65) )"
CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


if [ $doppCutVariation -eq 1 ]; then
g++ CutVariation.C $(root-config --cflags --libs) -g -o CutVariation.exe 
./CutVariation.exe "pp" "$ppData"  "$ppMC" "$CUTPP"
rm CutVariation.exe
fi

if [ $doPbPbCutVariation -eq 1 ]; then
g++ CutVariation.C $(root-config --cflags --libs) -g -o CutVariation.exe 
./CutVariation.exe "PbPb" "$PbPbData"  "$PbPbMC" "$CUTPbPb"
rm CutVariation.exe
fi
