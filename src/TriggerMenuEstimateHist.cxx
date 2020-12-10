#include "../include/TriggerMenuEstimate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

void TriggerMenuEstimate::InitHist()
{
    h_dr = new TH1D("h_dr",";#DeltaR;Events",100,0,1);
    I_dr = new TH1D("I_dr",";#DeltaR;Events",100,0,1);
    for(int i=0;i!=15;i++){
    A_etaphi[i] = new TH2D(Form("A_etaphi%d",i),";#eta^{RoI};#phi^{RoI}",300,-2.5,2.5,288,-TMath::Pi(),TMath::Pi());
    T_etaphi[i] = new TH2D(Form("T_etaphi%d",i),";#eta^{RoI};#phi^{RoI}",300,-2.5,2.5,288,-TMath::Pi(),TMath::Pi());
    B_etaphi[i] = new TH2D(Form("B_etaphi%d",i),";#eta^{RoI};#phi^{RoI}",300,-2.5,2.5,288,-TMath::Pi(),TMath::Pi());
    E_etaphi[i] = new TH2D(Form("E_etaphi%d",i),Form("p_{T}=%dGeV;#eta^{RoI};#phi^{RoI}",i+3),300,-2.5,2.5,288,-TMath::Pi(),TMath::Pi());
    A_eta[i] = new TH1D(Form("A_eta%d",i),";#eta^{RoI};Events",100,-2.5,2.5);
    I_eta[i] = new TH1D(Form("I_eta%d",i),";#eta^{RoI};Events",100,-2.5,2.5);
    E_eta[i] = new TH1D(Form("E_eta%d",i),Form("p_{T}=%dGeV;#eta^{RoI};Events",i+3),100,-2.5,2.5);
    A_roi[i] = new TH1D(Form("A_roi%d",i),";RoI No.;Events",100,0,148);
    I_roi[i] = new TH1D(Form("I_roi%d",i),";RoI No.;Events",100,0,148);
    E_roi[i] = new TH1D(Form("E_roi%d",i),Form("p_{T}=%dGeV;RoI No.;Events",i+3),100,0,148);
    }
}

void TriggerMenuEstimate::End()
{
    if(h_dr!=0){delete h_dr;}
    if(I_dr!=0){delete I_dr;}
    for(int i=0;i!=15;i++){
    if(A_etaphi[i]!=0){delete A_etaphi[i];}
    if(T_etaphi[i]!=0){delete T_etaphi[i];}
    if(B_etaphi[i]!=0){delete B_etaphi[i];}
    if(E_etaphi[i]!=0){delete E_etaphi[i];}
    if(A_eta[i]!=0){delete A_eta[i];}
    if(I_eta[i]!=0){delete I_eta[i];}
    if(E_eta[i]!=0){delete E_eta[i];}
    if(A_roi[i]!=0){delete A_roi[i];}
    if(I_roi[i]!=0){delete I_roi[i];}
    if(E_roi[i]!=0){delete E_roi[i];}
    }
}
