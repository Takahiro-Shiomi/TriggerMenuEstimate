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
        if(TGC_Run3_n>=1){TGC_Run3();}
        //if(muctpi_ndatawords>=1){RPC_Run3();}
        if(roi_pt.size()>=1){
            h_events->Fill(1);
            for(unsigned int i=0;i!=roi_pt.size();i++){A_eta->Fill(roi_eta.at(i),(float)1/(float)roi_eta.size());}

            OverlapRemoval();
            Tile();

            int can[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            for(unsigned int i=0;i!=roi_pt.size();i++){
                if(!roi_ovlp.at(i) && roi_station.at(i) && !roi_hotroi.at(i) && (roi_inner.at(i)==2 || roi_inner.at(i)==1)){
                    for(unsigned int j=0;j!=15;j++){
                        if(roi_pt.at(i)>=j+1){can[j] = can[j] + 1;}
                    }
                }
            }

            for(unsigned int j=0;j!=15;j++){
                if(can[j]>=1){
                    h_events->Fill(j+2);
                    for(unsigned int i=0;i!=roi_pt.size();i++){
                        if(!roi_ovlp.at(i) && roi_station.at(i) && !roi_hotroi.at(i)){
                            if(roi_pt.at(i)>=j+1){N_eta[j]->Fill(roi_eta.at(i),(float)1/(float)can[j]);}
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
}
