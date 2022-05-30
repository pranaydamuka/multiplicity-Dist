#include "TTree.h"
#include "TFile.h"
#include "Pythia8/Pythia.h"  
#include <iostream>
#include "TH1.h"
#include <TCanvas.h>
#include <TPad.h>
using namespace Pythia8;
int main() {

  //creating a root file
  TFile *f = new TFile("24_13000_4C.root", "RECREATE");
  
  int nch;                                
  double pt[500]; 
  double eta[500];
                   //the max. value of array can be equal to or greater than max. no. of particles produced in an event
  
  TTree *t = new TTree("mthirteenthousandfourc", "tree");
  t->Branch("nch", &nch, "nch/I");
  t->Branch("pt",pt,"pt[nch]/D");
  t->Branch("eta", &eta, "eta[nch]/D");        
  
  //pythia code
  Pythia pythia;
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
  pythia.readString("SoftQCD:nonDiffractive = on");
  pythia.readString("SoftQCD:doubleDiffractive = on");
  
  pythia.readString("Beams:eCM = 13000.");
    
      
  pythia.readString("Tune:pp = 5");       //4C tune

  pythia.readString("HadronLevel:Hadronize = on");
  pythia.readString("PartonLevel:Remnants = on");
  pythia.readString("SpaceShower:dipoleRecoil = on");
  pythia.init();
  
  
  for (int i = 0; i < 10000000; ++i) {
    if (!pythia.next()) continue;
    
    
    int n = 0;
    for (int j = 0; j < pythia.event.size(); ++j) {
    	
    	if(pythia.event[j].eta() > 2.4) continue;
	if(pythia.event[j].eta() < -2.4) continue;
	if(pythia.event[j].id() == -211 && pythia.event[j].mother1() == 310) continue;
	if(pythia.event[j].id() == 211 && pythia.event[j].mother1() == 310) continue;
	if(pythia.event[j].id() == -211 && pythia.event[j].mother2() == 310) continue;
	if(pythia.event[j].id() == 211 && pythia.event[j].mother2() == 310) continue;
	if(pythia.event[j].id() == 211 && pythia.event[j].mother1() == 3122) continue; 
        if(pythia.event[j].id() == -211 && pythia.event[j].mother1() == 3122) continue;
        if(pythia.event[j].id() == 211 && pythia.event[j].mother2() == 3122) continue; 
        if(pythia.event[j].id() == -211 && pythia.event[j].mother2() == 3122) continue;
        
	
	
        if (pythia.event[j].isFinal() && pythia.event[j].isCharged() && pythia.event[j].isHadron()) {
             pt[n] = pythia.event[j].pT();
             eta[n] = pythia.event[j].eta();
             n++;
         
        }     
        nch = n; 
                                                                   
    	
    }
    t->Fill();
  }
  pythia.stat();

  //  Write tree.
  t->Print();
  t->Write();
  delete f;

  // Done.
  return 0;
}
