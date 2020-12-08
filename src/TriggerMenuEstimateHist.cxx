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
  h_rate = new TH1D("h_rate",";;Rate [kHz]",15,0,15);
  for(int i=0;i!=16;i++){
    A_etaphi[i] = new TH2D(Form("A_etaphi%d",i),Form("pT No.=%d;#eta^{RoI};#phi^{RoI}",i),400,-2.5,2.5,384,-TMath::Pi(),TMath::Pi());
    N_etaphi[i] = new TH2D(Form("N_etaphi%d",i),Form("pT No.=%d;#eta^{RoI};#phi^{RoI}",i),400,-2.5,2.5,384,-TMath::Pi(),TMath::Pi());
    E_etaphi[i] = new TH2D(Form("E_etaphi%d",i),Form("pT No.=%d;#eta^{RoI};#phi^{RoI}",i),400,-2.5,2.5,384,-TMath::Pi(),TMath::Pi());
  }
}

void TriggerMenuEstimate::End()
{
  if(h_events!=0){delete h_events;}
  if(h_rate!=0){delete h_rate;}
  for(int i=0;i!=16;i++){
    if(A_etaphi[i]!=0){delete A_etaphi[i];}
    if(N_etaphi[i]!=0){delete N_etaphi[i];}
    if(E_etaphi[i]!=0){delete E_etaphi[i];}
  }
}
