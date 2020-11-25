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
    h_events = new TH1D("h_events",";;Events",18,0,18);
    A_eta = new TH1D("A_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    T_eta = new TH2D("T_eta",";#eta^{RoI};#phi^{RoI}",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
    B_eta = new TH2D("B_eta",";#eta^{RoI};#phi^{RoI}",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
    for(int i=0;i!=15;i++){
        N_eta[i] = new TH1D(Form("N_eta%d",i),";#eta^{RoI};Events",75,-2.7,2.7);
    }
}

void TriggerMenuEstimate::End()
{
    if(h_events!=0){delete h_events;}
    if(A_eta!=0){delete A_eta;}
    if(T_eta!=0){delete T_eta;}
    if(B_eta!=0){delete B_eta;}
    for(int i=0;i!=15;i++){
        if(N_eta[i]!=0){delete N_eta[i];}
    }
}
