//###############################################
// Made by Ta-Wei Wang, modified by Hyunchul Kim
//###############################################

using namespace std;

#include "uti.h"

Double_t minhisto=5.;	// mininum of mass window
Double_t maxhisto=6.;	// maximum of mass window
Double_t nbinsmasshisto=50;	// number of bins of mass histograms
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;	// bin width of histogram

TString weightMC = "1";
TString weight;
TString seldata;
TString selmc;
TString collisionsystem;

int saveMasshisto(TString inputdata="",		// file name of input data
						TString inputmc="",			//	file name of input mc
						TString trgselection="",	// trigger selection
						TString cut="",				// apllied cut (check condition!)
						Int_t isMC=0,					// MC : 1, data : 0
						TString weightdata="",		// weight?
						TString collsyst="",			// collision system : PbPb, pp
						TString nominalcut="",		// nominal cut for final result
						TString varname="",			// variable's name?
						TString variable="",			// variable itself?
						Int_t varbins=10,				// variable's bins?
						Float_t varmin=0.5,			// variable's minimum
						Float_t varmax=2.0,			// variable's maximum
						Float_t varini=0.5,			// variable's nominal value(added)
						Int_t isLarger=0,				// var>value : 1, var<value : 0
						Float_t ptmin=0,				// pt min?
						TString outputfile="outfMasshisto/mass"	// output file name
){
	if(varbins<=1)	// varation should be larger than one
		{std::cout << "ERROR : one bin is invalid" << std::endl; return 1;}
	collisionsystem=collsyst;
	seldata = Form("%s&&%s",trgselection.Data(),cut.Data());	// data - applied trigger selection and cut?
	selmc = Form("%s",cut.Data());	// MC - applied cut only
	weight = weightdata; // which weight?

	TFile* inf = new TFile(inputdata.Data());		// call input data
	TFile* infMC = new TFile(inputmc.Data());		// call input mc

	TTree* nt = (TTree*)inf->Get("ntphi");
	nt->AddFriend("ntHlt");
	nt->AddFriend("ntHi");
	nt->AddFriend("ntSkim");
	nt->AddFriend("mvaTree"); //need to check the name with Candan

	TTree* ntMC = (TTree*)infMC->Get("ntphi");
	ntMC->AddFriend("ntHlt");
	ntMC->AddFriend("ntHi");
	ntMC->AddFriend("ntSkim");
	ntMC->AddFriend("mvaTree"); //need to check the name with Candan

	std::cout << " -- Variable" << std::endl;
	std::cout << "		" << varname << "	" << variable << std::endl;
	std::cout << " -- Filling Histograms" << std::endl;
	std::cout << "		" << inputdata << std::endl;
	std::cout << "		" << inputmc << std::endl;
	
	Float_t varstep = (varmax-varmin)/(varbins-1);
	for(float i=0;i<varbins+1;i++) {
		Float_t ivar = varmin+(i-1)*varstep;

		if (i==0) std::cout << setiosflags(ios::left) << "		- Processing varbin no cuts" << std::endl;
		else std::cout << setiosflags(ios::left) << "		- Processing varbin " << setw(3) << ivar << endl; 

		TH1D* h = new TH1D("h","",nbinsmasshisto,minhisto,maxhisto);
		h->Sumw2();
		TH1D* hMCSignal = new TH1D("hMCSignal","",nbinsmasshisto,minhisto,maxhisto);
		hMCSignal->Sumw2();
		TH1D* hMCSwapped = new TH1D("hMCSwapped","",nbinsmasshisto,minhisto,maxhisto);
		hMCSwapped->Sumw2();
	
		if(i>0) {
			if (isLarger==1) { // var<ivar
				nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&%s>%f)",weight.Data(),seldata.Data(),ptmin,variable.Data(),ivar));
				ntMC->Project("hMCSignal","Bmass",Form("%s*(%s&&Bpt>%f&&%s>%f&&(Bgen==23333))",weightMC.Data(),selmc.Data(),ptmin,variable.Data(),ivar));
				ntMC->Project("hMCSwapped","Bmass",Form("%s*(%s&&Bpt>%f&&%s>%f&&(Bgen==23344))",weightMC.Data(),selmc.Data(),ptmin,variable.Data(),ivar));
			}
			else { // var>ivar
				nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&%s<%f)",weight.Data(),seldata.Data(),ptmin,variable.Data(),ivar));
				ntMC->Project("hMCSignal","Bmass",Form("%s*(%s&&Bpt>%f&&%s<%f&&(Bgen==23333))",weightMC.Data(),selmc.Data(),ptmin,variable.Data(),ivar));
				ntMC->Project("hMCSwapped","Bmass",Form("%s*(%s&&Bpt>%f&&%s<%f&&(Bgen==23344))",weightMC.Data(),selmc.Data(),ptmin,variable.Data(),ivar));
			}
		}
		else { // var==varini, var==varini
				nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&%s)",weight.Data(),seldata.Data(),ptmin,nominalcut.Data()));
				ntMC->Project("hMCSignal","Bmass",Form("%s*(%s&&Bpt>%f&&%s&&(Bgen==23333))",weightMC.Data(),selmc.Data(),ptmin,nominalcut.Data()));
				ntMC->Project("hMCSwapped","Bmass",Form("%s*(%s&&Bpt>%f&&%s&&(Bgen==23344))",weightMC.Data(),selmc.Data(),ptmin,nominalcut.Data()));
		}
		
		TString tMC;
		if (isMC==1) tMC="MC"; else tMC="Data";	
		TFile* outf = new TFile(Form("%s_%s_%s_%s_%.0f.root",outputfile.Data(),collisionsystem.Data(),varname.Data(),tMC.Data(),i),"recreate");
		outf->cd();
		h->Write();
		hMCSignal->Write();
		hMCSwapped->Write();
		outf->Close();
		delete h;
		delete hMCSignal;
		delete hMCSwapped;
		delete outf;
	}
	std::cout << std::endl;
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc!=17)
		{
			std::cout << "Wrong number of inputs" << std::endl;
			return 1;
		}
	else
		{
			saveMasshisto(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), argv[6], argv[7], argv[8], argv[9], argv[10], atoi(argv[11]), atof(argv[12]), atof(argv[13]), atof(argv[14]), atoi(argv[15]), atof(argv[16]));	// outputfile is fixed here
			return 0;
		}
}

