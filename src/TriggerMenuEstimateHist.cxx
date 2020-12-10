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
  A_etaphi = new TH2D("A_etaphi",";#eta^{RoI};#phi^{RoI}",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
  N_etaphi = new TH2D("N_etaphi",";#eta^{RoI};#phi^{RoI}",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
  E_etaphi = new TH2D("E_etaphi",";#eta^{RoI};#phi^{RoI}",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
}

void TriggerMenuEstimate::End()
{
  if(h_events!=0){delete h_events;}
  if(h_rate!=0){delete h_rate;}
  if(A_etaphi!=0){delete A_etaphi;}
  if(N_etaphi!=0){delete N_etaphi;}
  if(E_etaphi!=0){delete E_etaphi;}
}
