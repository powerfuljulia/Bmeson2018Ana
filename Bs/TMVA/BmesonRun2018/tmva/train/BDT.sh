ptmin=7;
ptmax=15;

mvatype=BDT;

inputname=/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/ToCopy/Data/New/crab_Bfinder_20181220_HIDoubleMuon_HIRun2018A_PromptReco_v1v2_1031_NoJSON_skimhltBsize_ntphi.root;
#inputname=/mnt/hadoop/cms/store/user/gwangjun/Bp2018/MC/crab_Bfinder_20190221_Pythia8_BuToJpsiK_Bpt0p0_1032_NoJSON_pthatweight_hardcut_v2.root;
outputname=BDToutput;

g++ BDT.C $(root-config --cflags --libs) -g -o BDT.exe
./BDT.exe "$inputname" "$outputname" "ptmin" "ptmax" "mvatype"
