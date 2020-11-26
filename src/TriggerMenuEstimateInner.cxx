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
    for(int i=0;i!=(int)RoI_pt.size();i++){
        A_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
        if(abs(RoI_eta.at(i))<=1.9){
            int r_sec = RoI_sec.at(i);
            bool coin = false;
            for(int tile=0;tile<TILE_murcv_trig_n;tile++){
                if((*TILE_murcv_trig_part)[tile]==3 && RoI_eta.at(i)<=0){continue;}
                if((*TILE_murcv_trig_part)[tile]==4 && RoI_eta.at(i)>=0){continue;}
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
                T_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
                RoI_inner.at(i)=1;
            }
            else{
                B_etaphi[RoI_pt.at(i)-1]->Fill(RoI_eta.at(i),RoI_phi.at(i));
                RoI_inner.at(i)=0;
            }
        }
    }
}
