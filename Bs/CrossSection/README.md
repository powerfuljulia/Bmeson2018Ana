To get this repository
=====
```
git clone -b MVA20180316 git@github.com:taweiXcms/BsRAA2015RunII.git
cd BsRAA2015RunII/CrossSection
```

The macro's, created with root lines: ``canvas->SaveAs("XXX.C")``, for paper plots are in:
```
plotFits/plotFitsOnSaved_roofit/data_pp_1.C
plotFits/plotFitsOnSaved_roofit/data_pp_2.C
plotFits/plotFitsOnSaved_roofit/data_PbPb_1.C
plotFits/plotFitsOnSaved_roofit/data_PbPb_2.C
plotCrossSection/plotCrossSection_750/canvasSigmaBplusRatiopp.C
plotCrossSection/plotCrossSection/canvasSigmaBplusRatiopp_AddPbPb.C
plotRAA/canvasRAAPbPb_0_100_BpRAA.C
plotBsBpRatio/BsBpRatio.C
```

If you would like to run the original macro that created these ``XXX.C``'s and ``XXX.pdf``'s. Please follow the below
=====
Set options as instructed below in ``doAnalysis.sh``. And run with:
```bash
 'source doAnalysis.sh'
```

For figure 1-a and 2-a
-----
Set:
```bash
DOANALYSISPP_ROOFITONSAVED = 1
```
Which will run:
```bach
roofitB.C
```
Output:
```
plotFits/plotFitsOnSaved_roofit/data_pp_1.pdf
plotFits/plotFitsOnSaved_roofit/data_pp_2.pdf
```

For figure 1-b and 2-b
-----
Set:
```bash
DOANALYSISPbPb_ROOFITONSAVED = 1
```
Which will run:
```
roofitB.C
```
Output:
```
plotFits/plotFitsOnSaved_roofit/data_PbPb_1.pdf
plotFits/plotFitsOnSaved_roofit/data_PbPb_2.pdf
```

For figure 3
-----
Set:
```bash
DOANALYSISPP_CROSS_750 = 1
```
Which will run:
```
CrossSectionRatio.C
```
Output:
```
plotCrossSection/plotCrossSection_750/canvasSigmaBplusRatiopp.pdf
```

For figure 4-a
-----
Set:
```bash
DOANALYSISPP_CROSS = 1
```
Which will run:
```
CrossSectionRatio.C
```
Output:
```
plotCrossSection/plotCrossSection/canvasSigmaBplusRatiopp_AddPbPb.pdf
```

For figure 4-b
-----
Set:
```bash
DORAA = 1
```
Which will run:
```
NuclearModificationFactor.C
```
Output:
```
plotRAA/canvasRAAPbPb_0_100_BpRAA.pdf
```

For figure 5
-----
Set:
```bash
DORAARATIO = 1
```
Which will run:
```bash
plotBsBpRatio/plotBsBpRatio.cc
```
Output:
```bash
plotBsBpRatio/BsBpRatio.pdf
```

