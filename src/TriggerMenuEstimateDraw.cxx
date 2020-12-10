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
    
    h_dr->Draw();
    c1->Print(pdf,"pdf");

    I_dr->Draw();
    c1->Print(pdf,"pdf");

    /*
    A_etaphi->Draw("colz");
    c1->Print(pdf,"pdf");

    T_etaphi->Draw("colz");
    c1->Print(pdf,"pdf");

    B_etaphi->Draw("colz");
    c1->Print(pdf,"pdf");
    */
    for(int i=0;i!=15;i++){
    A_etaphi[i]->Draw("colz");
    c1->Print(pdf,"pdf");
    c1->Clear();
    T_etaphi[i]->Draw("colz");
    c1->Print(pdf,"pdf");
    c1->Clear();
    E_etaphi[i]->Divide(T_etaphi[i],A_etaphi[i],1,1);
    E_etaphi[i]->Draw("colz");
    c1->Print(pdf,"pdf");
    c1->Clear();
    E_eta[i]->Divide(I_eta[i],A_eta[i],1,1);
    E_eta[i]->Draw("LP");
    c1->Print(pdf,"pdf");
    c1->Clear();
    E_roi[i]->Divide(I_roi[i],A_roi[i],1,1);
    E_roi[i]->Draw("LP");
    c1->Print(pdf,"pdf");
    c1->Clear();
    }

/*
    A_eta->Draw("hist");
    A_eta->SetFillColor(kAzure+3);
    I_eta->Draw("same hist");
    I_eta->SetFillColor(kOrange+1);
    c1->Print(pdf,"pdf");


    A_roi->Draw("hist");
    A_roi->SetFillColor(kAzure+3);
    I_roi->Draw("same hist");
    I_roi->SetFillColor(kOrange+1);
    c1->Print(pdf,"pdf");
*/
    
    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
