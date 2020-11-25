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

    double x[15];
    double rate[15];
    for(int i=0;i!=15;i++){
        double L12MU4 = h_events->GetBinContent(i+3);
        double All = h_events->GetBinContent(1);
        x[i] = i+3;
        rate[i] = (L12MU4/All) * 1700;
    }
    TGraphErrors *tge = new TGraphErrors(15,x,rate,0,0);
    tge->Draw("apl");
    tge->SetMarkerColor(kAzure);
    tge->SetMarkerStyle(8);
    tge->SetLineColor(kAzure);
    tge->SetLineWidth(1);
    tge->SetLineStyle(7);
    tge -> Write();
    c1 -> Print( pdf , "pdf" );


    A_eta->Draw("hist");
    A_eta->SetFillColor(kPink+1);
    A_eta->SetLineWidth(1);
    N_eta[0]->Draw("hist same");
    N_eta[0]->SetFillColor(kPink+10);
    N_eta[0]->SetLineColor(kPink+10);
    N_eta[0]->SetLineWidth(1);
    N_eta[1]->Draw("hist same");
    N_eta[1]->SetFillColor(kRed);
    N_eta[1]->SetLineColor(kRed);
    N_eta[1]->SetLineWidth(1);
    N_eta[2]->Draw("hist same");
    N_eta[2]->SetFillColor(kOrange+8);
    N_eta[2]->SetLineColor(kOrange+8);
    N_eta[2]->SetLineWidth(1);
    N_eta[3]->Draw("hist same");
    N_eta[3]->SetFillColor(kOrange);
    N_eta[3]->SetLineColor(kOrange);
    N_eta[3]->SetLineWidth(1);
    N_eta[4]->Draw("hist same");
    N_eta[4]->SetFillColor(kYellow+1);
    N_eta[4]->SetLineColor(kYellow+1);
    N_eta[4]->SetLineWidth(1);
    N_eta[5]->Draw("hist same");
    N_eta[5]->SetFillColor(kSpring+10);
    N_eta[5]->SetLineColor(kSpring+10);
    N_eta[5]->SetLineWidth(1);
    N_eta[6]->Draw("hist same");
    N_eta[6]->SetFillColor(kSpring);
    N_eta[6]->SetLineColor(kSpring);
    N_eta[6]->SetLineWidth(1);
    N_eta[7]->Draw("hist same");
    N_eta[7]->SetFillColor(kGreen-1);
    N_eta[7]->SetLineColor(kGreen-1);
    N_eta[7]->SetLineWidth(1);
    N_eta[8]->Draw("hist same");
    N_eta[8]->SetFillColor(kTeal-6);
    N_eta[8]->SetLineColor(kTeal-6);
    N_eta[8]->SetLineWidth(1);
    N_eta[9]->Draw("hist same");
    N_eta[9]->SetFillColor(kCyan);
    N_eta[9]->SetLineColor(kCyan);
    N_eta[9]->SetLineWidth(1);
    N_eta[10]->Draw("hist same");
    N_eta[10]->SetFillColor(kCyan+2);
    N_eta[10]->SetLineColor(kCyan+2);
    N_eta[10]->SetLineWidth(1);
    N_eta[11]->Draw("hist same");
    N_eta[11]->SetFillColor(kAzure+1);
    N_eta[11]->SetLineColor(kAzure+1);
    N_eta[11]->SetLineWidth(1);
    N_eta[12]->Draw("hist same");
    N_eta[12]->SetFillColor(kAzure);
    N_eta[12]->SetLineColor(kAzure);
    N_eta[12]->SetLineWidth(1);
    N_eta[13]->Draw("hist same");
    N_eta[13]->SetFillColor(kBlue-1);
    N_eta[13]->SetLineColor(kBlue-1);
    N_eta[13]->SetLineWidth(1);
    N_eta[14]->Draw("hist same");
    N_eta[14]->SetFillColor(kViolet+2);
    N_eta[14]->SetLineColor(kViolet+2);
    N_eta[14]->SetLineWidth(1);
    c1->Print(pdf,"pdf");

    T_eta->Draw("colz");
    c1->Print(pdf,"pdf");

    B_eta->Draw("colz");
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
