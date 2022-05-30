#define test_cxx
#include "test.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void test::Loop()
{

   TH1F *h1 = new TH1F("mult","Multiplicity", 113, -0.5, 112.5);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if (Cut(ientry) <= 0) continue;
      
      
      //int i;
      //int count = 0;
      //for (i = 0; i <= nch; ++i ) {
          
         //if(eta[i] > 0.5) continue;
         //if(eta[i] < -0.5) continue;
         
         //count++; 
         //} 
      
      h1->Fill(nch);
      
      
   }
   
   h1->Draw();
  
  
   /*
   //bin content extraction
   ofstream file1;
   file1.open("o2360_05_monash_MC_pnn.txt");
   TAxis * axis = h1->GetXaxis();
   int nbin = axis->GetNbins();
   for (int ibin = 0; ibin <= nbin; ibin++) {
   
   	double b = h1->GetBinContent(ibin+1);
   	
   	file1 << ibin << "  \t "<< b/h1->Integral() << endl;
   	
   	//cout << h1->Integral() << endl;
   }  
   file1.close();
   */
   
 }
 
