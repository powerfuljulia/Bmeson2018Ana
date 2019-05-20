#!/bin/bash

CENTPbPbMIN=0
CENTPbPbMAX=10

#

DOANPPMB=0
DOANPP=0
DOANPbPbMB=1
DOANPbPb=1

##

if [ $DOANPPMB -eq 1 ]; then
sed '1iconst int nbins=8;' printoutAN.C > printoutAN_PPMB.C
g++ printoutAN_PPMB.C $(root-config --cflags --libs) -g -o printoutAN_PPMB.exe 
./printoutAN_PPMB.exe "PPMB"
rm printoutAN_PPMB.exe
rm printoutAN_PPMB.C
fi

if [ $DOANPP -eq 1 ]; then
sed '1iconst int nbins=7;' printoutAN.C > printoutAN_PP.C
g++ printoutAN_PP.C $(root-config --cflags --libs) -g -o printoutAN_PP.exe 
./printoutAN_PP.exe "PP"
rm printoutAN_PP.exe
rm printoutAN_PP.C
fi

if [ $DOANPbPbMB -eq 1 ]; then
sed '1iconst int nbins=8;' printoutAN.C > printoutAN_PbPbMB.C
g++ printoutAN_PbPbMB.C $(root-config --cflags --libs) -g -o printoutAN_PbPbMB.exe 
./printoutAN_PbPbMB.exe "PbPbMB" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm printoutAN_PbPbMB.exe
rm printoutAN_PbPbMB.C
fi

if [ $DOANPbPb -eq 1 ]; then
sed '1iconst int nbins=7;' printoutAN.C > printoutAN_PbPb.C
g++ printoutAN_PbPb.C $(root-config --cflags --libs) -g -o printoutAN_PbPb.exe 
./printoutAN_PbPb.exe "PbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm printoutAN_PbPb.exe
rm printoutAN_PbPb.C
fi