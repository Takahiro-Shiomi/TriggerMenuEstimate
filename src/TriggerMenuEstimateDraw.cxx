#include "../include/TriggerMenuEstimate.h"
#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "THStack.h"
#include "TLegend.h"
#include "TGraphErrors.h"

using namespace std;

void TriggerMenuEstimate::Draw(TString pdf)
{
  TCanvas_opt *c1 = new TCanvas_opt();
  gStyle->SetOptStat(0);
  c1->SetTopMargin(0.20);
  c1->Print(pdf + "[", "pdf");

  A_etaphi[15]->Draw("colz");
  c1->Print(pdf,"pdf");
  N_etaphi[15]->Draw("colz");
  c1->Print(pdf,"pdf");
  c1->Clear();
  E_etaphi[15]->Divide(N_etaphi[15],A_etaphi[15],1,1);
  E_etaphi[15]->Draw("colz");
  c1->Print(pdf,"pdf");
  c1->Clear();

  for(int i=0;i!=15;i++){
    c1->Divide(2,2);
    c1->cd(1);
    A_etaphi[i]->Draw("colz");
    c1->cd(2);
    N_etaphi[i]->Draw("colz");
    c1->cd(3);
    E_etaphi[i]->Divide(N_etaphi[i],A_etaphi[i],1,1);
    E_etaphi[i]->Draw("colz");
    c1->Print(pdf,"pdf");
    c1->Clear();
  }

  h_events->Draw("hist text");
  h_events->GetXaxis()->SetBinLabel(1,"All");
  h_events->GetXaxis()->SetBinLabel(2,"2Muons");
  h_events->GetXaxis()->SetBinLabel(3,"MU3");
  h_events->GetXaxis()->SetBinLabel(4,"MU4");
  h_events->GetXaxis()->SetBinLabel(5,"MU5");
  h_events->GetXaxis()->SetBinLabel(6,"MU6");
  h_events->GetXaxis()->SetBinLabel(7,"MU7");
  h_events->GetXaxis()->SetBinLabel(8,"MU8");
  h_events->GetXaxis()->SetBinLabel(9,"MU9");
  h_events->GetXaxis()->SetBinLabel(10,"MU10");
  h_events->GetXaxis()->SetBinLabel(11,"MU11");
  h_events->GetXaxis()->SetBinLabel(12,"MU12");
  h_events->GetXaxis()->SetBinLabel(13,"MU13");
  h_events->GetXaxis()->SetBinLabel(14,"MU14");
  h_events->GetXaxis()->SetBinLabel(15,"MU15");
  h_events->GetXaxis()->SetBinLabel(16,"MU18");
  h_events->GetXaxis()->SetBinLabel(17,"MU20");
  c1->Print(pdf,"pdf");

  for(int i=0;i!=15;i++){
    double All = h_events->GetBinContent(1);
    double L12MU4 = h_events->GetBinContent(i+3);
    double x = i;
    double rate = (L12MU4/All) * 1700;  //L1_MU4 Rate
    //double rate = (L12MU4/All) * 80;  //L1_2MU4 Rate
    h_rate->SetBinContent(i+1,rate);
  }
  h_rate->Draw("PL text");
  h_rate->GetXaxis()->SetBinLabel(1,"MU3");
  h_rate->GetXaxis()->SetBinLabel(2,"MU4");
  h_rate->GetXaxis()->SetBinLabel(3,"MU5");
  h_rate->GetXaxis()->SetBinLabel(4,"MU6");
  h_rate->GetXaxis()->SetBinLabel(5,"MU7");
  h_rate->GetXaxis()->SetBinLabel(6,"MU8");
  h_rate->GetXaxis()->SetBinLabel(7,"MU9");
  h_rate->GetXaxis()->SetBinLabel(8,"MU10");
  h_rate->GetXaxis()->SetBinLabel(9,"MU11");
  h_rate->GetXaxis()->SetBinLabel(10,"MU12");
  h_rate->GetXaxis()->SetBinLabel(11,"MU13");
  h_rate->GetXaxis()->SetBinLabel(12,"MU14");
  h_rate->GetXaxis()->SetBinLabel(13,"MU15");
  h_rate->GetXaxis()->SetBinLabel(14,"MU18");
  h_rate->GetXaxis()->SetBinLabel(15,"MU20");
  c1->Print(pdf,"pdf");

  c1 -> Print( pdf + "]", "pdf" );
  delete c1;
}
