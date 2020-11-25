#include "../include/TriggerMenuEstimate.h"
#include <iostream>
#include <vector>
#include <TVector3.h>
#include <stdlib.h>
#include <typeinfo>
#include <TRandom.h>

using namespace std;

void TriggerMenuEstimate::Tile()
{
    for(int i=0;i!=(int)roi_pt.size();i++){
        if(abs(roi_eta.at(i))<=1.3){
            int r_sec = roi_sector.at(i);
            bool coin = false;
            for(int tile=0;tile<TILE_murcv_trig_n;tile++){
                if((*TILE_murcv_trig_part)[tile]==3 && !roi_side.at(i)){continue;}
                if((*TILE_murcv_trig_part)[tile]==4 && roi_side.at(i)){continue;}
                int t_sec = (*TILE_murcv_trig_mod)[tile];

                if(r_sec>=2){
                    int sec1 = (r_sec-2) + (int)(r_sec-2)/3;
                    int sec2 = (r_sec-2) + 1 + (int)(r_sec-2)/3;
                    if(t_sec==sec1 || t_sec==sec2){
                        if((*TILE_murcv_trig_bit0)[tile]==1 || (*TILE_murcv_trig_bit2)[tile]==1){coin = true;}
                    }
                }
                if(r_sec<2){
                    int sec1 = r_sec + 61;
                    int sec2 = r_sec + 62;
                    if(t_sec==sec1 || t_sec==sec2){
                        if((*TILE_murcv_trig_bit0)[tile]==1 || (*TILE_murcv_trig_bit2)[tile]==1){coin = true;}
                    }
                }
            }
            if(coin){
                T_eta->Fill(roi_eta.at(i),roi_phi.at(i));
                roi_inner.push_back(1);
            }
            else{
                B_eta->Fill(roi_eta.at(i),roi_phi.at(i));
                roi_inner.push_back(0);
            }
        }
    }
}
