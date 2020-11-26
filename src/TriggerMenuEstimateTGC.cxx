#include "../include/TriggerMenuEstimate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "TVector3.h"

using namespace std;

void TriggerMenuEstimate::TGC_Run3()
{
    for(int j=0;j!=TGC_Run3_n;j++){
        if(TGC_Run3_type->at(j)!=2)continue;
        if(!TGC_Run3_IsEndcap->at(j))continue;

        int station = TGC_Run3_station->at(j);
        bool flag = HotRoI(j);

        int TGC_pt=TGC_Run3_pt->at(j);
        if(TGC_pt>15 || TGC_pt<1){continue;}

        float TGC_x=TGC_Run3_x->at(j);
        float TGC_y=TGC_Run3_y->at(j);
        float TGC_z=TGC_Run3_z->at(j);
        TVector3 v1;
        v1.SetXYZ(TGC_x,TGC_y,TGC_z);
        float TGC_eta=v1.PseudoRapidity();
        float TGC_phi=v1.Phi();

        int   TGC_roi = (*TGC_Run3_RoI)[j];
        int   TGC_side = (*TGC_Run3_Side)[j];
        int   TGC_source;
        if((*TGC_Run3_IsEndcap)[j]){TGC_source=1;}
        else if(!(*TGC_Run3_IsEndcap)[j]){TGC_source=2;}
        int   TGC_sector;
        if(TGC_source==1){
            if((*TGC_Run3_PhiSector)[j]>=1&&(*TGC_Run3_PhiSector)[j]<=46){TGC_sector=(*TGC_Run3_PhiSector)[j]+1;}
            else if((*TGC_Run3_PhiSector)[j]>=47){TGC_sector=(*TGC_Run3_PhiSector)[j]-47;}
        }
        if(TGC_source==2){
            if((*TGC_Run3_PhiSector)[j]>=1&&(*TGC_Run3_PhiSector)[j]<=23){TGC_sector=(*TGC_Run3_PhiSector)[j];}
            else if((*TGC_Run3_PhiSector)[j]==24){TGC_sector=0;}
        }

        roi_pt.push_back(TGC_pt);
        roi_eta.push_back(TGC_eta);
        roi_phi.push_back(TGC_phi);
        roi_roi.push_back(TGC_roi);
        roi_side.push_back(TGC_side);
        roi_source.push_back(TGC_source);
        roi_sector.push_back(TGC_sector);
        roi_ovlp.push_back(false);
        if(TGC_side == 0){
            if((*TGC_Run3_Charge)[j] == 0){ roi_charge.push_back(0); }
            else if((*TGC_Run3_Charge)[j] == 1){ roi_charge.push_back(1); }
            else { roi_charge.push_back(2);}
        }else if(TGC_side == 1){
            if((*TGC_Run3_Charge)[j] == 0){ roi_charge.push_back(1); }
            else if((*TGC_Run3_Charge)[j] == 1){ roi_charge.push_back(0); }
            else { roi_charge.push_back(2);}
        }
        if(station==0){roi_station.push_back(true);}
        if(station!=0){roi_station.push_back(false);}
        roi_hotroi.push_back(flag);
        roi_inner.push_back(2);
        roi_match.push_back(false);
    } 
}
