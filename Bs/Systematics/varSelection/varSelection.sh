BSSAVEHISTPP_DECAYLENGTH=1
BSSAVEHISTPBPB_DECAYLENGTH=0
##################################
BSSAVEHISTPP_CHI2=0
BSSAVEHISTPBPB_CHI2=0
BSSAVEHISTPP_COSTHETA=0
BSSAVEHISTPBPB_COSTHETA=0
BSSAVEHISTPP_TRK1PT=0
BSSAVEHISTPBPB_TRK1PT=0
BSSAVEHISTPP_TRK2PT=0
BSSAVEHISTPBPB_TRK2PT=0
BSSAVEHISTPP_BLXY=0
BSSAVEHISTPBPB_BLXY=0
BSSAVEHISTPP_BDT=0
BSSAVEHISTPBPB_BDT=0
##################################

BSFITPP_DECAYLENGTH=0
BSFITPBPB_DECAYLENGTH=0

INPUTDATAPP="/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20171120_bPt0_BfinderData_pp_20171119_bPt0jpsiPt0tkPt0p5_Bs.root"
INPUTMCPP="/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_pp_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt0jpsiPt0tkPt0p5_Bp_pthatweight_JingBDT.root"

INPUTDATAPBPB="/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20171110_bPt10_BfinderData_PbPb_20171109_bPt10jpsiPt0tkPt0p8_Bs_HIOniaL1DoubleMu0_AllDatamerged.root"
INPUTMCPBPB="/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20171110_bPt10_BfinderMC_PbPb_BsToJpsiPhi_HydjetCymbMB_5p02_20171109_bPt10jpsiPt0tkPt0p8_Bs_pthatweight_BDT15to50.root"

TRGPP="(HLT_HIL1DoubleMu0_v1)"
TRGPPMC="(HLT_HIL1DoubleMu0ForPPRef_v1)"

TRGPBPB="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"
TRGPBPMC="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"

FILTERCUTPP="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0" ### event condition && Bmumu mass window && B mass window && muon acceptance && muon ID cut
FILTERCUTPP_FIDUCIAL="Btrk1Pt>0.5 && abs(By) < 2.4 && Btrk1highPurity && abs(Btrk1Eta)<2.4 && (BsvpvDistance/BsvpvDisErr) > 3.5 && Bchi2cl > 0.005 && Bpt>10 && Bpt<50" ### nominal cut?

FILTERCUTPBPB="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&((abs(Bmu1eta)<1.2 && Bmu1pt>3.5) || (abs(Bmu1eta)>1.2 && abs(Bmu1eta)<2.1 && Bmu1pt>(5.77-1.8*abs(Bmu1eta))) || (abs(Bmu1eta)>2.1 && abs(Bmu1eta)<2.4 && Bmu1pt>1.8)) && ((abs(Bmu2eta)<1.2 && Bmu2pt>3.5) || (abs(Bmu2eta)>1.2 && abs(Bmu2eta)<2.1 && Bmu2pt>(5.77-1.8*abs(Bmu2eta))) || (abs(Bmu2eta)>2.1 && abs(Bmu2eta)<2.4 && Bmu2pt>1.8)) && Bmu1TMOneStationTight && Bmu2TMOneStationTight && Bmu1InPixelLayer > 0 && (Bmu1InPixelLayer+Bmu1InStripLayer) > 5 && Bmu2InPixelLayer > 0 && (Bmu2InPixelLayer+Bmu2InStripLayer) > 5 && Bmu1dxyPV< 0.3 && Bmu2dxyPV< 0.3 && Bmu1dzPV<20 && Bmu2dzPV<20 && Bmu1isGlobalMuon && Bmu2isGlobalMuon && Bmu1TrgMatchFilterE>0 && Bmu2TrgMatchFilterE>0" ### event condition && Bmumu mass window && B mass window && muon acceptance && muon ID cut
FILTERCUTPBPB_FIDUCIAL="Btrk1Pt>0.5 && abs(By) < 2.4 && Btrk1highPurity && abs(Btrk1Eta)<2.4 && (BsvpvDistance/BsvpvDisErr) > 3.5 && Bchi2cl > 0.005 && Bpt>10 && Bpt<50" ### nominal cut?

MATCHEDCUTPP="Bgen==23333"
MATCHEDCUTPBPB="Bgen==23333"

ISMCPP=0
ISMCPBPB=0

WEIGHTPP="pthatweight*(pow(10,-0.094152+0.008102*Bgenpt+Bgenpt*Bgenpt*0.000171+Bgenpt*Bgenpt*Bgenpt*-0.000005+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))"
WEIGHTPBPB="pthatweight*(pow(10,-0.107832+0.010248*Bgenpt+Bgenpt*Bgenpt*0.000079+Bgenpt*Bgenpt*Bgenpt*-0.000003+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))*(6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08))"

### weight data = 1

LABELPP="PP"
LABELPBPB="PbPb"

VARBINS=9 ### original : 5

PTTHRESHOLDPP=0 ## ?
PTTHRESHOLDPBPB=0

########## DECAYLENGTH ##########

ADDCUTPP_DECAYLENGTH="(Bchi2cl > 0.05 && cos(Bdtheta) > 0.2)"
ADDCUTPBPB_DECAYLENGTH="(Bchi2cl > 0.05 && cos(Bdtheta) > 0.2)"

NOMINALPP_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)>3.5"
NOMINALPBPB_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)>3.5"

LABEL_DECAYLENGTH="Decaylength"
VAR_DECAYLENGTH="(BsvpvDistance/BsvpvDisErr)"

VARMIN_DECAYLENGTH=1.5 ## original : 3.5
VARMAX_DECAYLENGTH=5.5 ## original : 7.5
VARVAL_DECAYLENGTH=3.5 ## add new

VARSIGN_DECAYLENGTH=1

########## CHI2 ##########

ADDCUTPP_CHI2="(cos(Bdtheta) > 0.2 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_CHI2="(cos(Bdtheta) > 0.2 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_CHI2="Bchi2cl > 0.05"
NOMINALPBPB_CHI2="Bchi2cl > 0.05"

LABEL_CHI2="Chi2"
VAR_CHI2="Bchi2cl"

VARMIN_CHI2=0.010 ## original : 3.5
VARMAX_CHI2=0.090 ## original : 7.5
VARVAL_CHI2=0.050 ## add new

VARSIGN_CHI2=1

########## COSTHETA ##########

ADDCUTPP_COSTHETA="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_COSTHETA="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_COSTHETA="cos(Bdtheta) > 0.2"
NOMINALPBPB_COSTHETA="cos(Bdtheta) > 0.2"

LABEL_COSTHETA="costheta"
VAR_COSTHETA="cos(Bdtheta)"

VARMIN_COSTHETA=0.15 ## original : 3.5
VARMAX_COSTHETA=0.95 ## original : 7.5
VARVAL_COSTHETA=0.2 ## add new

VARSIGN_COSTHETA=1

########## COSTHETA ##########

ADDCUTPP_COSTHETA="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_COSTHETA="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_COSTHETA="cos(Bdtheta) > 0.2"
NOMINALPBPB_COSTHETA="cos(Bdtheta) > 0.2"

LABEL_COSTHETA="costheta"
VAR_COSTHETA="cos(Bdtheta)"

VARMIN_COSTHETA=0.15 ## original : 3.5
VARMAX_COSTHETA=0.95 ## original : 7.5
VARVAL_COSTHETA=0.2 ## add new

VARSIGN_COSTHETA=1

########## TRK1PT ##########

ADDCUTPP_TRK1PT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_TRK1PT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_TRK1PT="cos(Bdtheta) > 0.2"
NOMINALPBPB_TRK1PT="cos(Bdtheta) > 0.2"

LABEL_TRK1PT="costheta"
VAR_TRK1PT="cos(Bdtheta)"

VARMIN_TRK1PT=0.15 ## original : 3.5
VARMAX_TRK1PT=0.95 ## original : 7.5
VARVAL_TRK1PT=0.2 ## add new

VARSIGN_TRK1PT=1

########## TRK2PT ##########

ADDCUTPP_TRK2PT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_TRK2PT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_TRK2PT="cos(Bdtheta) > 0.2"
NOMINALPBPB_TRK2PT="cos(Bdtheta) > 0.2"

LABEL_TRK2PT="costheta"
VAR_TRK2PT="cos(Bdtheta)"

VARMIN_TRK2PT=0.15 ## original : 3.5
VARMAX_TRK2PT=0.95 ## original : 7.5
VARVAL_TRK2PT=0.2 ## add new

VARSIGN_TRK2PT=1

########## BLXY ##########

ADDCUTPP_BLXY="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_BLXY="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_BLXY="cos(Bdtheta) > 0.2"
NOMINALPBPB_BLXY="cos(Bdtheta) > 0.2"

LABEL_BLXY="costheta"
VAR_BLXY="cos(Bdtheta)"

VARMIN_BLXY=0.15 ## original : 3.5
VARMAX_BLXY=0.95 ## original : 7.5
VARVAL_BLXY=0.2 ## add new

VARSIGN_BLXY=1

########## BDT ##########

ADDCUTPP_BDT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"
ADDCUTPBPB_BDT="Bchi2cl > 0.05 && (BsvpvDistance/BsvpvDisErr)>3.5)"

NOMINALPP_BDT="cos(Bdtheta) > 0.2"
NOMINALPBPB_BDT="cos(Bdtheta) > 0.2"

LABEL_BDT="costheta"
VAR_BDT="cos(Bdtheta)"

VARMIN_BDT=0.15 ## original : 3.5
VARMAX_BDT=0.95 ## original : 7.5
VARVAL_BDT=0.2 ## add new

VARSIGN_BDT=1


#### Saving histograms
if [ $BSSAVEHISTPP_DECAYLENGTH -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_DECAYLENGTH}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_DECAYLENGTH" "$VARMAX_DECAYLENGTH" "$VARVAL_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_DECAYLENGTH}" "1" "$WEIGHTPP" "$LABELPP" "$NOMINALPP_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_DECAYLENGTH" "$VARMAX_DECAYLENGTH" "$VARVAL_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_DECAYLENGTH -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_DECAYLENGTH}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_DECAYLENGTH" "$VARMAX_DECAYLENGTH" "$VARVAL_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_DECAYLENGTH}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_DECAYLENGTH" "$LABEL_DECAYLENGTH" "$VAR_DECAYLENGTH" "$VARBINS" "$VARMIN_DECAYLENGTH" "$VARMAX_DECAYLENGTH" "$VARVAL_DECAYLENGTH" "$VARSIGN_DECAYLENGTH" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_CHI2 -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_CHI2}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_CHI2" "$VARMAX_CHI2" "$VARVAL_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_CHI2}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_CHI2" "$VARMAX_CHI2" "$VARVAL_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_CHI2 -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_CHI2}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_CHI2" "$VARMAX_CHI2" "$VARVAL_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_CHI2}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_CHI2" "$LABEL_CHI2" "$VAR_CHI2" "$VARBINS" "$VARMIN_CHI2" "$VARMAX_CHI2" "$VARVAL_CHI2" "$VARSIGN_CHI2" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_COSTHETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_COSTHETA}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_COSTHETA" "$VARMAX_COSTHETA" "$VARVAL_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_COSTHETA}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_COSTHETA" "$VARMAX_COSTHETA" "$VARVAL_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_COSTHETA -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_COSTHETA}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_COSTHETA" "$VARMAX_COSTHETA" "$VARVAL_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_COSTHETA}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_COSTHETA" "$LABEL_COSTHETA" "$VAR_COSTHETA" "$VARBINS" "$VARMIN_COSTHETA" "$VARMAX_COSTHETA" "$VARVAL_COSTHETA" "$VARSIGN_COSTHETA" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_TRK1PT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_TRK1PT}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_TRK1PT" "$LABEL_TRK1PT" "$VAR_TRK1PT" "$VARBINS" "$VARMIN_TRK1PT" "$VARMAX_TRK1PT" "$VARVAL_TRK1PT" "$VARSIGN_TRK1PT" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_TRK1PT}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_TRK1PT" "$LABEL_TRK1PT" "$VAR_TRK1PT" "$VARBINS" "$VARMIN_TRK1PT" "$VARMAX_TRK1PT" "$VARVAL_TRK1PT" "$VARSIGN_TRK1PT" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_TRK1PT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_TRK1PT}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_TRK1PT" "$LABEL_TRK1PT" "$VAR_TRK1PT" "$VARBINS" "$VARMIN_TRK1PT" "$VARMAX_TRK1PT" "$VARVAL_TRK1PT" "$VARSIGN_TRK1PT" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_TRK1PT}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_TRK1PT" "$LABEL_TRK1PT" "$VAR_TRK1PT" "$VARBINS" "$VARMIN_TRK1PT" "$VARMAX_TRK1PT" "$VARVAL_TRK1PT" "$VARSIGN_TRK1PT" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_TRK2PT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_TRK2PT}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_TRK2PT" "$LABEL_TRK2PT" "$VAR_TRK2PT" "$VARBINS" "$VARMIN_TRK2PT" "$VARMAX_TRK2PT" "$VARVAL_TRK2PT" "$VARSIGN_TRK2PT" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_TRK2PT}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_TRK2PT" "$LABEL_TRK2PT" "$VAR_TRK2PT" "$VARBINS" "$VARMIN_TRK2PT" "$VARMAX_TRK2PT" "$VARVAL_TRK2PT" "$VARSIGN_TRK2PT" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_TRK2PT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_TRK2PT}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_TRK2PT" "$LABEL_TRK2PT" "$VAR_TRK2PT" "$VARBINS" "$VARMIN_TRK2PT" "$VARMAX_TRK2PT" "$VARVAL_TRK2PT" "$VARSIGN_TRK2PT" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_TRK2PT}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_TRK2PT" "$LABEL_TRK2PT" "$VAR_TRK2PT" "$VARBINS" "$VARMIN_TRK2PT" "$VARMAX_TRK2PT" "$VARVAL_TRK2PT" "$VARSIGN_TRK2PT" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_BLXY -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_BLXY}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_BLXY" "$LABEL_BLXY" "$VAR_BLXY" "$VARBINS" "$VARMIN_BLXY" "$VARMAX_BLXY" "$VARVAL_BLXY" "$VARSIGN_BLXY" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_BLXY}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_BLXY" "$LABEL_BLXY" "$VAR_BLXY" "$VARBINS" "$VARMIN_BLXY" "$VARMAX_BLXY" "$VARVAL_BLXY" "$VARSIGN_BLXY" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_BLXY -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_BLXY}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_BLXY" "$LABEL_BLXY" "$VAR_BLXY" "$VARBINS" "$VARMIN_BLXY" "$VARMAX_BLXY" "$VARVAL_BLXY" "$VARSIGN_BLXY" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_BLXY}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_BLXY" "$LABEL_BLXY" "$VAR_BLXY" "$VARBINS" "$VARMIN_BLXY" "$VARMAX_BLXY" "$VARVAL_BLXY" "$VARSIGN_BLXY" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPP_BDT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPP" "$INPUTMCPP" "$TRGPP" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${ADDCUTPP_BDT}" "$ISMCPP" "1" "$LABELPP" "$NOMINALPP_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_BDT" "$VARMAX_BDT" "$VARVAL_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPP"
./saveMasshisto.exe "$INPUTMCPP" "$INPUTMCPP" "$TRGPPMC" "${FILTERCUTPP}&&${FILTERCUTPP_FIDUCIAL}&&${MATCHEDCUTPP}&&${ADDCUTPP_BDT}" 1 "$WEIGHTPP" "$LABELPP" "$NOMINALPP_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_BDT" "$VARMAX_BDT" "$VARVAL_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPP"
rm saveMasshisto.exe
fi

if [ $BSSAVEHISTPBPB_BDT -eq 1 ]; then
g++ saveMasshisto.C $(root-config --cflags --libs) -g -o saveMasshisto.exe
./saveMasshisto.exe "$INPUTDATAPBPB" "$INPUTMCPBPB" "$TRGPBPB" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${ADDCUTPBPB_BDT}" "$ISMCPBPB" "1" "$LABELPBPB" "$NOMINALPBPB_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_BDT" "$VARMAX_BDT" "$VARVAL_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPBPB"
./saveMasshisto.exe "$INPUTMCPBPB" "$INPUTMCPBPB" "$TRGPBPBMC" "${FILTERCUTPBPB}&&${FILTERCUTPBPB_FIDUCIAL}&&${MATCHEDCUTPBPB}&&${ADDCUTPBPB_BDT}" 1 "$WEIGHTPBPB" "$LABELPBPB" "$NOMINALPBPB_BDT" "$LABEL_BDT" "$VAR_BDT" "$VARBINS" "$VARMIN_BDT" "$VARMAX_BDT" "$VARVAL_BDT" "$VARSIGN_BDT" "$PTTHRESHOLDPBPB"
rm saveMasshisto.exe
fi
