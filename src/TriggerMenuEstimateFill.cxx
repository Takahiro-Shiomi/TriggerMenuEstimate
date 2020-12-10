#include "../include/TriggerMenuEstimate.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerMenuEstimate::FillHist()
{
  Clear();
  bool hlt = HLT();
  if(hlt){
    h_events->Fill(0);
    single = false;
    if(TGC_Run3_n>=1){TGC_Run3();}
    if(muctpi_ndatawords>=1){RPC_Run3();}
    if(roi_pt.size()>=2 && !single){
      h_events->Fill(1);
      for(unsigned int i=0;i!=roi_pt.size();i++){
        A_etaphi[roi_pt.at(i)-1]->Fill(roi_eta.at(i),roi_phi.at(i));
        A_etaphi[15]->Fill(roi_eta.at(i),roi_phi.at(i));
      }
      OverlapRemoval();
      for(int i=0;i!=(int)roi_pt.size();i++){
        if(roi_station.at(i) && !roi_ovlp.at(i) && !roi_hotroi.at(i)){
          RoI_eta.push_back(roi_eta.at(i));
          RoI_phi.push_back(roi_phi.at(i));
          RoI_pt.push_back(roi_pt.at(i));
          RoI_sec.push_back(roi_sector.at(i));
          RoI_sou.push_back(roi_source.at(i));
          RoI_side.push_back(roi_side.at(i));
          RoI_roi.push_back(roi_roi.at(i));
          RoI_inner.push_back(roi_inner.at(i));
        }
      }
      //EIFI();
      //Tile();
      if(RoI_pt.size()>=2){
        for(unsigned int i=0;i!=RoI_pt.size();i++){
          if(RoI_inner.at(i)==2 || RoI_inner.at(i)==1){
            N_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
            N_etaphi[15]->Fill(RoI_eta.at(i),RoI_phi.at(i));
            for(int j=0;j!=15;j++){
              if(RoI_pt.at(i)>=j+1){h_events->Fill(j+2,(float)1/(float)RoI_pt.size());}
            }
          }
        }
      }
    }
  }
}

void TriggerMenuEstimate::Clear()
{
  roi_pt.clear();
  roi_eta.clear();
  roi_phi.clear();
  roi_roi.clear();
  roi_sector.clear();
  roi_source.clear();
  roi_side.clear();
  roi_ovlp.clear();
  roi_charge.clear();
  roi_station.clear();
  roi_hotroi.clear();
  roi_inner.clear();

  RoI_eta.clear();
  RoI_pt.clear();
  RoI_phi.clear();
  RoI_sec.clear();
  RoI_sou.clear();
  RoI_side.clear();
  RoI_roi.clear();
  RoI_inner.clear();
}
