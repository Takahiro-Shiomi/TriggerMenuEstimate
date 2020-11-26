#include "../include/TriggerMenuEstimate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include <TVector2.h>

using namespace std;

bool TriggerMenuEstimate::Offline()
{
    for(int i=0; i!=muon_n; i++){
        if((*muon_author)[i]!=1 || (*muon_Type)[i]!=0){continue;}
        float eta = (*muon_eta)[i];
        if(abs(eta)<=1.05 || abs(eta)>=2.4){continue;}
        off_eta.push_back(eta);
        off_phi.push_back((*muon_phi)[i]);
        off_pt.push_back((*muon_pt)[i]/1000);
    }
    if(off_eta.size()!=0){return true;}
    else return false;
}

void TriggerMenuEstimate::Match()
{
    int roi[(int)off_eta.size()];
    for(int i=0; i!=(int)off_eta.size(); i++){roi[i]=-100;}

    for(int i=0; i!=(int)off_eta.size(); i++){
        int roinum = -100;
        float DR = 10;
        for(int j=0;j!=(int)roi_pt.size();j++){
            bool same = false;
            for(int k=0; k!=(int)off_eta.size();k++){
                if(roi[k]==j){same = true;}
            }
            if(same) continue;
            float deta =abs(off_eta.at(i)-roi_eta.at(j));
            float dphi=TVector2::Phi_mpi_pi(off_phi.at(i)-roi_phi.at(j));
            float dR=sqrt(deta*deta + dphi*dphi);
            if(dR<DR){
                roinum = j;
                DR = dR;
            }
        }
        h_dr->Fill(DR);
        bool match=false;
        if(DR<=0.5){match=true;}
        if(match){
            roi[i] = roinum;
            roi_match.at(roinum) = true;
        }
    }
}
