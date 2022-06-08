#include "TCanvas.h"
#include "TROOT.h"
#include "TMath.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
#include "TFile.h"
#include "TStyle.h"
#include "THistPainter.h"

using namespace std;
void pnvsn()
{
  
   TCanvas *c1 = new TCanvas("c1","multipads", 600, 800);
   
   TPad *p2 = new TPad("p2","p2",0,0.1,0.9,0.4); p2->Draw();
   
   
   //p2->SetGrid();
   p2->SetTopMargin(0);
   p2->SetBottomMargin(0.3);
   TPad *p1 = new TPad("p1","p1",0,0.4,0.9,1);  p1->Draw();
   p1->SetBottomMargin(0);
   p1->SetLogy ();
   p1->cd();
   //p1->SetGrid();

   TMultiGraph *mg = new TMultiGraph();
   TGraphAsymmErrors *gr1 = new TGraphAsymmErrors();
   TGraph *gr3 = new TGraph();
   TGraph *gr4 = new TGraph();
   
   gPad->SetLogy(1);
   //reading into the 1st file
   fstream file1;
   file1.open("o7000pnvsn05.txt", ios::in);
   int n = 0;
   while(1)
        {
        
          double a, b, c, d, e, f;
          file1 >> a >> b >> c >> d >> e >> f;
          n = gr1->GetN();
          gr1->SetPoint(n, a, b);
          gr1->SetPointError(n, c, d, e, f);

          if(file1.eof()) break;
        
        }
        file1.close();
        gr1->SetMarkerStyle(kOpenCircle);
        gr1->SetMarkerSize(1.3);
        gr1->SetMarkerColor(kRed);
        gr1->SetLineColor(kRed);
        //gr1->SetLineWidth(1);
   //reading into the 2nd file
   
  
  
  
  
   fstream file3;
   file3.open("o7000_05_4C_pnn.txt", ios::in);
   while(1)
        {
        
          double a, b;
          file3 >> a >> b;
          gr3->SetPoint(gr3->GetN(), a, b);
          if(file3.eof()) break;
        
        }
        file3.close();
   
        gr3->SetMarkerSize(1);
        gr3->SetMarkerColor(kBlue);
        gr3->SetLineColor(kBlue);
        gr3->SetLineStyle(9);
        //gr3->SetLineWidth(1);
        
  
  
  
   fstream file4;
   file4.open("o7000_05_monash_pnn.txt", ios::in);
   while(1)
        {
        
          double a, b;
          file4 >> a >> b;
          gr4->SetPoint(gr4->GetN(), a, b);
          if(file4.eof()) break;
        
        }
        file4.close();
   
        gr4->SetMarkerSize(1);
        gr4->SetMarkerColor(kBlack);
        gr4->SetMarkerStyle(kDot);
        gr4->SetLineColor(kBlack);
        gr4->SetLineStyle(kDotted);
        gr4->SetLineWidth(2);
   
    
   /*
  //std::string char_file1 = "";
  std::string char_file2 = "";
  //char_file1 = "/home/fellow/Desktop/root/root-6.24.06/buildroot/l900_monash.root";
  char_file2 = "/home/fellow/Desktop/root/root-6.24.06/buildroot/ol900_4C.root";
  

  //TCanvas *c1 = new TCanvas();
  //TFile *f1 = TFile::Open(char_file1.c_str());
  TFile *f2 = TFile::Open(char_file2.c_str());
  
    
 
 //TH1D * h1;
 TH1D * h2; 
  
    //h1 = (TH1D*)f1->Get("mult");
    h2 = (TH1D*)f2->Get("mult");
   
  
    
   
    
    gPad->SetLogy(1);
    
    
    //h1->SetLineColor(kMagenta);
    h2->SetLineColor(kGreen);
    
    
    
    //h1->GetXaxis()->SetTitle("n_{ch}");
    //h2->GetXaxis()->SetTitle("No of charged particles");
    
    
    
    
    //h1->GetYaxis()->SetTitle("Probability");
    h2->GetYaxis()->SetTitle("Probability"); 
    
    //h1->Scale(1.0/h1->Integral());
    h2->Scale(1.0/h2->Integral());
    */
    
    //mg->Add(gr1, "AC");
    mg->Add(gr1, "APE");
    mg->Add(gr3, "AC");
    mg->Add(gr4, "AC");
    mg->Draw("a");
    //h1->Draw("SAME HIST C");
    //h2->Draw("HIST SAME C");
    //mg->SetTitle("Multiplicity distribution for |#eta| < 0.5;z = n/<n>;#psi(z)");
    mg->GetXaxis()->SetTitle("n    ");
    mg->GetYaxis()->SetTitle("P(n)");
    mg->GetYaxis()->CenterTitle(true);
    mg->GetXaxis()->CenterTitle(true);
    mg->GetYaxis()->SetLabelSize(0.04);
    mg->GetXaxis()->SetLabelSize(0.04);
    mg->GetYaxis()->SetTitleSize(0.045);
    mg->GetXaxis()->SetTitleSize(0.073);
    mg->GetYaxis()->SetTitleOffset(0.7);
   // mg->GetXaxis()->SetRange(0.0, 33.0);
    //mg->GetYaxis()->SetRange(1.2*pow(10, -5), 1);
    
    TLegend *leg = new TLegend(0.72,0.7,0.88,0.85);
    leg->AddEntry(gr1, "CMS Data", "kOpenCircle");
    leg->AddEntry(gr4, "Pythia 8 Monash ", "l");
    leg->AddEntry(gr3, "Pythia 8 4C ", "l");
    leg->SetTextSize(0.048);
    leg->SetBorderSize(0);
    leg->Draw();
    TLegend *leg1 = new TLegend(0.3, 0.8, 0.6, 0.88);
    leg1->AddEntry((TObject*)0, "#sqrt{s} = 7 TeV, |#eta| < 0.5", "c");
    leg1->SetBorderSize(0);
    leg1->Draw();   
    
   
   
   
   
   p2->cd();
   TMultiGraph *mg1 = new TMultiGraph();
   TGraphAsymmErrors *r2 = new TGraphAsymmErrors();
   TGraphAsymmErrors *r3 = new TGraphAsymmErrors();
   
   TLine *line = new TLine(0.0, 1.0, 57.7, 1.0);
 
   
    
   fstream file5;
   file5.open("r7000pnvsn05.txt", ios::in);
   fstream file7;
   file7.open("r7000_05_4C_pnn.txt", ios::in);
   fstream file8;
   file8.open("r7000_05_monash_pnn.txt", ios::in);
 
   int s = 0;
   int t = 0;
   while(1)
        {
        
          double a, b, c, d, e, f;
          file5 >> a >> b >> c >> d >> e >> f;
          s = r2->GetN();
          t = r3->GetN();
          
          double i, j;
          file7 >> i >> j;
          r2->SetPoint(s, a, b/j);
          
          double m, n;
          file8 >> m >> n;
          r3->SetPoint(t, a, b/n);
          
          double z3 = (e/b)*(b/j);
          double z4 = (f/b)*(b/j);
          
          
          double z5 = (e/b)*(b/n);
          double z6 = (f/b)*(b/n);
          
          
          r2->SetPointError(s, c, d, z3, z4);
          r3->SetPointError(t, c, d, z5, z6);
          if(file5.eof()) break;
          if(file7.eof()) break;
          if(file8.eof()) break;
        
        }
        file5.close();
        file7.close();
        file8.close(); 
        r2->SetMarkerStyle(kOpenSquare);
        r2->SetMarkerSize(1.0);
        r2->SetMarkerColor(kBlue);
        r2->SetLineColor(kBlue);
        
        
        r3->SetMarkerStyle(kFullDiamond);
        r3->SetMarkerSize(1.0);
        r3->SetMarkerColor(kBlack);
        r3->SetLineColor(kBlack);
        
 
        
   mg1->Add(r2, "APE");
   mg1->Add(r3, "APE");
   mg1->GetXaxis()->SetTitle("n    ");
    mg1->GetYaxis()->CenterTitle(true);
    mg1->GetXaxis()->CenterTitle(true);
    mg1->GetYaxis()->SetLabelSize(0.05);
    mg1->GetXaxis()->SetLabelSize(0.085);
    mg1->GetYaxis()->SetTitleSize(0.085);
    mg1->GetXaxis()->SetTitleSize(0.11);
    mg1->GetYaxis()->SetTitleOffset(0.45);
    mg1->GetXaxis()->SetTitleOffset(0.9);
    //mg1->GetYaxis()->SetNdivisions(310, kTRUE);
    //gStyle->SetOptStat(kFALSE);
    //mg1->GetYaxis()->SetTitle("Data/4C");
   //mg1->GetXaxis()->SetRange(0.0, 26);
    //mg1->GetYaxis()->SetRangeUser(0.0, 1.6);
    
    mg1->Draw("a");
    line->Draw("AL");
    
     TLegend *leg2 = new TLegend(0.2, 0.75, 0.4, 0.95);
     leg2->SetTextSize(0.082);
     leg2->AddEntry(r2, "Data/4C ", "kOpenSquare");
     leg2->AddEntry(r3, "Data/Monash ", "kOpenDiamond");
     leg2->SetBorderSize(0);
     leg2->Draw();   
      
 }
