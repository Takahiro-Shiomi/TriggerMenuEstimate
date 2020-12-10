#include "../include/TriggerMenuEstimate.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerMenuEstimate::FillHist()
{
    Clear();
    bool off = Offline();
    if(off){
        if(TGC_Run3_n>=1){TGC_Run3();}
        //if(muctpi_ndatawords>=1){RPC_Run3();}
        if(roi_pt.size()>=1){
            OverlapRemoval();
            Match();
            for(int i=0;i!=(int)roi_pt.size();i++){
                if(roi_station.at(i) && !roi_ovlp.at(i) && roi_match.at(i) && !roi_hotroi.at(i)){
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
            if(RoI_eta.size()!=0){
                Tile();
                //EIFI();
                for(int i=0;i!=(int)RoI_eta.size();i++){
                    A_roi[RoI_pt.at(i)-1]->Fill(RoI_roi.at(i));
                    A_eta[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i));
                    A_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
                    if(RoI_inner.at(i)==1){
                        T_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
                        I_roi[RoI_pt.at(i)-1]->Fill(RoI_roi.at(i));
                        I_eta[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i));
                    }
                }
            }
        }
    }
}

void TriggerMenuEstimate::Clear()
{
    off_eta.clear();
    off_phi.clear();
    off_pt.clear();

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
    roi_match.clear();

    RoI_eta.clear();
    RoI_pt.clear();
    RoI_phi.clear();
    RoI_sec.clear();
    RoI_sou.clear();
    RoI_side.clear();
    RoI_roi.clear();
    RoI_inner.clear();
}
