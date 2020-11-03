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
        if(TGC_Run3_n>=1){TGC_Run3();}
        if(muctpi_ndatawords>=1){RPC_Run3();}
        if(roi_pt.size()>=1){
            //OverlapRemoval();
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
}
