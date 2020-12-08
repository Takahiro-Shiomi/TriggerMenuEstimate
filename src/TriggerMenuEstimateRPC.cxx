#include "../include/TriggerMenuEstimate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerMenuEstimate::RPC_Run3()
{
    for(int j=0;j!=muctpi_ndatawords;j++){
        if(muctpi_source->at(j)!=0)continue;
        if(muctpi_candidateVetoed->at(j)==1)continue;
        if(muctpi_bcid->at(j)!=(bcid&0x7))continue;
        
        int rpc_pt=muctpi_thrNumber->at(j);
        //if(rpc_pt>=5){continue;}
        float rpc_eta = (*muctpi_eta)[j];
        float rpc_phi = (*muctpi_phi)[j];
        int   rpc_roi = (*muctpi_roi)[j];
        int   rpc_sector = (*muctpi_sectorID)[j];
        int   rpc_source = (*muctpi_source)[j];
        int   rpc_side = (*muctpi_hemisphere)[j];

        roi_pt.push_back(rpc_pt);
        roi_eta.push_back(rpc_eta);
        roi_phi.push_back(rpc_phi);
        roi_roi.push_back(rpc_roi);
        roi_sector.push_back(rpc_sector);
        roi_source.push_back(rpc_source);
        roi_side.push_back(rpc_side);
        roi_ovlp.push_back(false);
        roi_charge.push_back(2);
        roi_inner.push_back(2);
        roi_station.push_back(true);
        roi_hotroi.push_back(false);
    }
}
