#!/bin/bash

g++ plotAlpha.C $(root-config --cflags --libs) -g -o plotAlpha.exe 
./plotAlpha.exe 
rm plotAlpha.exe

