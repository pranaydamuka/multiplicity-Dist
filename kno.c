void kno() {

  
   TMultiGraph *mg = new TMultiGraph();
   TGraphAsymmErrors *gr1 = new TGraphAsymmErrors();
   TGraph *gr2 = new TGraph();
   TGraph *gr3 = new TGraph();
   TGraph *gr4 = new TGraph();
   TCanvas *c1 = new TCanvas();
   //gPad->SetGrid();
   gPad->SetLogy(1);
   //reading into the 1st file
   fstream file1;
   file1.open("7000exp24.txt", ios::in);
   int n = 0;
   while(1)
        {
        
          double a, b, c, d;
          file1 >> a >> b >> c >> d;
          n = gr1->GetN();
          gr1->SetPoint(n, a, b);
          gr1->SetPointError(n, 0, 0, c, d);

          if(file1.eof()) break;
        
        }
        file1.close();
        gr1->SetMarkerStyle(kOpenCircle);
        gr1->SetMarkerSize(1.3);
        gr1->SetMarkerColor(kRed);
        gr1->SetLineColor(kRed);
   //reading into the 2nd file
   
   fstream file2;
   file2.open("cap7000the24.txt", ios::in);
   while(1)
        {
        
          double a, b;
          file2 >> a >> b;
          gr2->SetPoint(gr2->GetN(), a, b);
          if(file2.eof()) break;
        
        }
        file2.close();
   
        gr2->SetMarkerSize(1);
        gr2->SetMarkerColor(kOrange);
        gr2->SetLineColor(kOrange);
            
   // reading into the 3rd file
   
  
   fstream file3;
   file3.open("o7000_24_4C_psiz.txt", ios::in);
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
    
   fstream file4;
   file4.open("o7000_24_monash_psiz.txt", ios::in);
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
    
   //mg->Add(gr1, "AC");
   mg->Add(gr1, "APE");
   mg->Add(gr2, "AC");
   mg->Add(gr3,"AC");
   mg->Add(gr4,"AC");
   mg->Draw("a");
   mg->GetXaxis()->SetTitle("z   ");
    mg->GetYaxis()->SetTitle("#psi(z)");
    mg->GetYaxis()->CenterTitle(true);
    mg->GetXaxis()->CenterTitle(true);
    mg->GetYaxis()->SetLabelSize(0.04);
    mg->GetXaxis()->SetLabelSize(0.04);
    mg->GetYaxis()->SetTitleSize(0.045);
    mg->GetXaxis()->SetTitleSize(0.045);
    mg->GetYaxis()->SetTitleOffset(0.9);
    mg->GetXaxis()->SetTitleOffset(0.9);
   mg->GetYaxis()->SetRangeUser(2.45*pow(10, -4), 5);
   mg->GetXaxis()->SetRangeUser(0.0, 7);
   TLegend *leg = new TLegend(0.70,0.72,0.88,0.86);
   leg->AddEntry(gr1, "CMS Data", "kOpenCircle");
   leg->AddEntry(gr2, "Theoretical Prediction", "l");
   leg->AddEntry(gr3, "Pythia 8 4C ", "l");
   leg->AddEntry(gr4, "Pythia 8 Monash ", "l");
   leg->SetBorderSize(0);
   leg->Draw();
   TLegend *leg1 = new TLegend(0.3, 0.835, 0.6, 0.88);
   leg1->AddEntry((TObject*)0, "#sqrt{s} = 7 TeV, |#eta| < 2.4", "c");
   leg1->SetBorderSize(0);
   leg1->Draw();   

}
