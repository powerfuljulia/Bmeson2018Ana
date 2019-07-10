#include "TTree.h"
#define MAX_XB       20000
#define MAX_GEN      6000
//pp
int     pBeamScrapingFilter;
int     pPAprimaryVertexFilter;
int     HLT_HIL1DoubleMu0ForPPRef_v1;
//pbpb
int     pclusterCompatibilityFilter;
int     pprimaryVertexFilter;
int     phfCoincFilter3;
double  BDT[MAX_XB]; 
int     HLT_HIL1DoubleMu0_v1;
int     HLT_HIL1DoubleMu0_part1_v1;
int     HLT_HIL1DoubleMu0_part2_v1;
int     HLT_HIL1DoubleMu0_part3_v1;
int     hiBin;
//common
float   pthatweight;
int     Gsize;
float   Gpt[MAX_GEN];
float   Gy[MAX_GEN];
int   GpdgId[MAX_GEN];   
int   GisSignal[MAX_GEN];
float   Gmu1pt[MAX_GEN];
float 	Gmu1eta[MAX_GEN];
float   Gmu2pt[MAX_GEN];
float 	Gmu2eta[MAX_GEN];
float   Gtk1pt[MAX_GEN];
float 	Gtk1eta[MAX_GEN];
float Gtk2pt[MAX_GEN];
float Gtk2eta[MAX_GEN];

void setAddressTree(TTree* ntKp, TTree* ntHlt, TTree* ntSkim, TTree* ntHi, TTree* ntGen, bool ispp){
	if(ispp){
		ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
		ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0ForPPRef_v1",&HLT_HIL1DoubleMu0ForPPRef_v1);
	}
	else{
		ntSkim->SetBranchAddress("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
		ntSkim->SetBranchAddress("pprimaryVertexFilter",&pprimaryVertexFilter);
		ntSkim->SetBranchAddress("phfCoincFilter3",&phfCoincFilter3);
	//mvaTree->SetBranchAddress("BDT",BDT);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part1_v1",&HLT_HIL1DoubleMu0_part1_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part2_v1",&HLT_HIL1DoubleMu0_part2_v1);
		ntHlt->SetBranchAddress("HLT_HIL1DoubleMu0_part3_v1",&HLT_HIL1DoubleMu0_part3_v1);
		ntHi->SetBranchAddress("hiBin",&hiBin);
	}
	ntHi->SetBranchAddress("pthatweight",&pthatweight);
	ntGen->SetBranchAddress("Gsize",&Gsize);
    ntGen->SetBranchAddress("Gpt",Gpt);
    ntGen->SetBranchAddress("Gy",Gy);
    ntGen->SetBranchAddress("GpdgId",GpdgId);
    ntGen->SetBranchAddress("GisSignal",GisSignal);
    ntGen->SetBranchAddress("Gmu1pt",Gmu1pt);
    ntGen->SetBranchAddress("Gmu1eta",Gmu1eta);
    ntGen->SetBranchAddress("Gmu2pt",Gmu2pt);
    ntGen->SetBranchAddress("Gmu2eta",Gmu2eta);
    ntGen->SetBranchAddress("Gtk1pt",Gtk1pt);
   ntGen->SetBranchAddress("Gtk1eta",Gtk1eta);
      ntGen->SetBranchAddress("Gtk2pt",Gtk2pt);
    ntGen->SetBranchAddress("Gtk2eta",Gtk2eta);
}
