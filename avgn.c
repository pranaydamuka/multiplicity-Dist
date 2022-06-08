void avgn() {

  
   TMultiGraph *mg = new TMultiGraph();
   
   TGraphAsymmErrors *gr2 = new TGraphAsymmErrors();
   TGraph *gr3 = new TGraph();
   TGraphAsymmErrors *gr4 = new TGraphAsymmErrors();
   TGraphAsymmErrors *gr5 = new TGraphAsymmErrors();
   TCanvas *c1 = new TCanvas();
   //gPad->SetGrid();
   gPad->SetLogx(1);
   //reading into the 2nd file
   
   fstream file2;
   file2.open("avgnexp.txt", ios::in);
   int n = 0;
   while(1)
        {
        
          double a, b, c, d;
          file2 >> a >> b >> c >> d;
          n = gr2->GetN();
          gr2->SetPoint(n, a, b);
          gr2->SetPointError(n, 0, 0, c, d);
          if(file2.eof()) break;
        
        }
        file2.close();
   
        gr2->SetMarkerSize(2);
        gr2->SetMarkerStyle(20);
        gr2->SetMarkerColor(kRed);
        gr2->SetLineColor(kRed);
            
   // reading into the 3rd file
   
 
   fstream file3;
   file3.open("avgntheory.txt", ios::in);
   while(1)
        {
        
          double a, b;
          file3 >> a >> b;
          gr3->SetPoint(gr3->GetN(), a, b);
          if(file3.eof()) break;
        
        }
        file3.close();
   
        gr3->SetMarkerSize(2);
        gr3->SetMarkerStyle(30);
        gr3->SetMarkerColor(kBlue);
        gr3->SetLineColor(kBlue);
    
   fstream file4;
   file4.open("avgn4C.txt", ios::in);
   int m = 0;
   while(1)
        {
        
          double a, b, c, d;
          file4 >> a >> b >> c >> d;
          m = gr4->GetN();
          gr4->SetPoint(m, a, b);
          gr4->SetPointError(m, 0, 0, c, d);
          if(file4.eof()) break;
        
        }
        file4.close();
   
        gr4->SetMarkerSize(2);
        gr4->SetMarkerStyle(26);
        gr4->SetMarkerColor(kMagenta);
        gr4->SetLineColor(kMagenta);  
        
        
   fstream file5;
   file5.open("avgnmonash.txt", ios::in);
   int p = 0;
   while(1)
        {
        
          double a, b, c, d;
          file5 >> a >> b >> c >> d;
          p = gr5->GetN();
          gr5->SetPoint(p, a, b);
          gr5->SetPointError(p, 0, 0, c, d);
          if(file5.eof()) break;
        
        }
        file5.close();
   
        gr5->SetMarkerSize(2);
        gr5->SetMarkerStyle(34);
        gr5->SetMarkerColor(kGreen);
        gr5->SetLineColor(kGreen);            
    
   
   mg->Add(gr2, "P");
   mg->Add(gr3,"P");
   mg->Add(gr4,"P");
   mg->Add(gr5,"P");
   mg->Draw("a");
   //mg->SetTitle("#sqrt{s} Vs <n>, |#eta| < 2.4;z = n/<n>;#psi(z)");
   mg->GetXaxis()->SetTitle("  #sqrt{s} ");
   mg->GetYaxis()->SetTitle("<n>");
   mg->GetYaxis()->CenterTitle(true);
   mg->GetXaxis()->CenterTitle(true);
   mg->GetYaxis()->SetLabelSize(0.04);
   mg->GetXaxis()->SetLabelSize(0.04);
   mg->GetYaxis()->SetTitleSize(0.045);
   mg->GetXaxis()->SetTitleSize(0.045);
   mg->GetYaxis()->SetTitleOffset(0.75);
   mg->GetXaxis()->SetTitleOffset(0.6);
   TLegend *leg = new TLegend(0.12,0.72,0.3,0.85);
   leg->AddEntry(gr2, "CMS", "p");
   leg->AddEntry(gr3, "Theory ", "p");
   leg->AddEntry(gr4, "Pythia 8 4C ", "p");
   leg->AddEntry(gr5, "Pythia 8 Monash ", "p");
   leg->SetBorderSize(0);
   leg->Draw();
   TLegend *leg1 = new TLegend(0.4, 0.835, 0.6, 0.88);
   leg1->AddEntry((TObject*)0, "|#eta| < 2.4", "c");
   
   leg1->SetBorderSize(0);
   leg1->Draw();   

}
