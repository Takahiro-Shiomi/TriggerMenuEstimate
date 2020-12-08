#include "../include/TriggerMenuEstimate.h"
#include <iostream>
#include <vector>
#include <TVector3.h>
#include <TVector2.h>
#include <stdlib.h>
#include <typeinfo>
#include <TRandom.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void TriggerMenuEstimate::Tile()
{
  for(int i=0;i!=(int)roi_pt.size();i++){
    if(roi_source.at(i)!=1){continue;}
    if(roi_ovlp.at(i) || !roi_station.at(i) || roi_hotroi.at(i)){continue;}
    bool isTile = false;
    if(TileOKS(roi_side.at(i), roi_sector.at(i), roi_roi.at(i)) && roi_roi.at(i)<=39){
      int r_sec = roi_sector.at(i);
      bool coin = false;
      for(int tile=0;tile<TILE_murcv_trig_n;tile++){
        if((*TILE_murcv_trig_part)[tile]==3 && roi_eta.at(i)<=0){continue;}
        if((*TILE_murcv_trig_part)[tile]==4 && roi_eta.at(i)>=0){continue;}
        int t_sec = (*TILE_murcv_trig_mod)[tile];
        bool bit = (*TILE_murcv_trig_bit0)[tile] ||
                   (*TILE_murcv_trig_bit1)[tile] ||
                   (*TILE_murcv_trig_bit2)[tile] ||
                   (*TILE_murcv_trig_bit3)[tile];

        int mod = TileSec(r_sec, t_sec);
        if(mod<0) continue;
        if(mod>=0){
          coin = true;
          if(bit){
            isTile = true;
            break;
          }
        }
      }
      if(coin && !isTile){roi_inner.at(i)=0;}
      else{roi_inner.at(i)=1;}
    }
  }
}


bool TriggerMenuEstimate::TileOKS(const int side, const int sector, const int roi)
{
  int hemi = (side==1) ? 0 : 1; //Aside=0,Cside=1
  static int oks[2][48] = { // A-side
    {0x7fff7, 0x7fff7, 0x7ffe7, 0x7ffe7, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7,
      0x7ffe7, 0x7ffe7, 0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7,
      0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7ffff/*0x7fff7*/, 0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe0,
      0x7ffe1/*0x7ffe0*/, 0x7ffe1/*0x7ffe0*/, 0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7,
      0x7fff7, 0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7, 0x7ffe7, 0x7ffe7,
      0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe0},
    {0x7fff7, 0x7fff7, 0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7,
      0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7ffe0, 0x7ffe0, 0x7fff7,
      0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7, 0x7fff7, 0x7ffff/*0x7ffe0*/, 0x7fff7/*0x7ffe0*/,
      0x7ffff, 0x7ffff, 0x7ffff, 0x7fff7, 0x7fff7/*0x7ffe0*/, 0x7fff7/*0x7ffe0*/, 0x7ffff/*0x7fff7*/, 0x7fff7,
      0x7fff7, 0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7, 0x7fff7, 0x7fff7,
      0x7ffe0, 0x7ffe0, 0x7ffe0, 0x7fff7, 0x7fff7, 0x7fff7, 0x7ffe0, 0x7ffe1/*0x7ffe0*/}};

  int ssc = int((roi+4)/8);

  return (((oks[hemi][sector]>>ssc) & 0x1) == 0);
}


int TriggerMenuEstimate::TileSec(const int sector, const int module)
{
  if(sector == 0 || sector == 1) {
    if(module<60 || module>63) return -1;
    return module - 60;
  } else if(sector == 2 || sector == 3) {
    if(module<0 || module>3) return -1;
    return module - 0;
  } else if(sector == 4 || sector == 5) {
    if(module<2 || module>5) return -1;
    return module - 2;
  } else if(sector == 6 || sector == 7) {
    if(module<4 || module>7) return -1;
    return module - 4;
  } else if(sector == 8 || sector == 9) {
    if(module<8 || module>11) return -1;
    return module - 8;
  } else if(sector == 10 || sector == 11) {
    if(module<10 || module>13) return -1;
    return module - 10;
  } else if(sector == 12 || sector == 13) {
    if(module<12 || module>15) return -1;
    return module - 12;
  } else if(sector == 14 || sector == 15) {
    if(module<16 || module>19) return -1;
    return module - 16;
  } else if(sector == 16 || sector == 17) {
    if(module<18 || module>21) return -1;
    return module - 18;
  } else if(sector == 18 || sector == 19) {
    if(module<20 || module>23) return -1;
    return module - 20;
  } else if(sector == 20 || sector == 21) {
    if(module<24 || module>27) return -1;
    return module - 24;
  } else if(sector == 22 || sector == 23) {
    if(module<26 || module>29) return -1;
    return module - 26;
  } else if(sector == 24 || sector == 25) {
    if(module<28 || module>31) return -1;
    return module - 28;
  } else if(sector == 26 || sector == 27) {
    if(module<32 || module>35) return -1;
    return module - 32;
  } else if(sector == 28 || sector == 29) {
    if(module<34 || module>37) return -1;
    return module - 34;
  } else if(sector == 30 || sector == 31) {
    if(module<36 || module>39) return -1;
    return module - 36;
  } else if(sector == 32 || sector == 33) {
    if(module<40 || module>43) return -1;
    return module - 40;
  } else if(sector == 34 || sector == 35) {
    if(module<42 || module>45) return -1;
    return module - 42;
  } else if(sector == 36 || sector == 37) {
    if(module<44 || module>47) return -1;
    return module - 44;
  } else if(sector == 38 || sector == 39) {
    if(module<48 || module>51) return -1;
    return module - 48;
  } else if(sector == 40 || sector == 41) {
    if(module<50 || module>53) return -1;
    return module - 50;
  } else if(sector == 42 || sector == 43) {
    if(module<52 || module>55) return -1;
    return module - 52;
  } else if(sector == 44 || sector == 45) {
    if(module<56 || module>59) return -1;
    return module - 56;
  } else if(sector == 46 || sector == 47) {
    if(module<58 || module>61) return -1;
    return module - 58;
  }

  return -1;
}


void TriggerMenuEstimate::EIFI()
{
  int roi[roi_pt.size()];
  for(int i=0;i!=(int)roi_pt.size();i++){roi[i]=-1;}

  for(int i=0;i!=(int)roi_pt.size();i++){
    if(roi_source.at(i)!=1){continue;}
    if(roi_ovlp.at(i) || !roi_station.at(i) || roi_hotroi.at(i)){continue;}
    if(roi_inner.at(i)!=2){continue;}
    if(EIFIOKS(roi_side.at(i),roi_sector.at(i),roi_roi.at(i))){
      if(EIFIRoI(roi_side.at(i),roi_sector.at(i),roi_roi.at(i))){
        float DR = 100;
        int roinum = -100;
        for(int j=0;j!=tgc_coin_n;j++){
          if((*tgc_coin_type)[j]!=4){continue;}

          bool same = false;
          for(int k=0;k!=(int)roi_pt.size();k++){if(roi[k]==j){same=true;}}
          if(same){continue;}

          float x_in = (*tgc_coin_x_In)[j];
          float y_in = (*tgc_coin_y_In)[j];
          float z_in = (*tgc_coin_z_In)[j];

          TVector3 v1;
          v1.SetXYZ(x_in,y_in,z_in);
          float eta_in = v1.PseudoRapidity();
          float phi_in = v1.Phi();

          float deta = abs(roi_eta.at(i) - eta_in);
          float dphi = TVector2::Phi_mpi_pi(roi_phi.at(i) - phi_in);
          float dR = sqrt(deta*deta + dphi*dphi);
          if(dR<DR){
            DR = dR;
            roinum = j;
          }
        }
        //I_dr->Fill(DR);
        if(DR<=0.2){
          roi[i] = roinum;
          roi_inner.at(i)=1;
        }
        else{roi_inner.at(i)=0;}
      }
    }
  }
}


bool TriggerMenuEstimate::EIFIOKS(const int side, const int sector, const int roi)
{
  int hemi = (side==1) ? 0 : 1;
  static int oks[2][48] = { // A-side
    {0x208,   0x208,   0x7fff8, 0x7fff8, 0x21f, 0x21f, 0x208,   0x208,
      0x7fff8, 0x7fff8, 0x21f,   0x21f,   0x21f, 0x21f, 0x7fff8, 0x7fff8,
      0x21f,   0x21f,   0x21f,   0x208,   0x208, 0x208, 0x21f,   0x21f,
      0x21f,   0x21f,   0x208,   0x208,   0x21f, 0x21f, 0x208,   0x208,
      0x208,   0x21f,   0x21f,   0x21f,   0x208, 0x208, 0x7fff8, 0x7fff8,
      0x21f,   0x21f,   0x21f,   0x208,   0x208, 0x208, 0x21f,   0x21f},
    {0x7fff8, 0x7fff8, 0x208,   0x208,   0x21f, 0x21f, 0x208,   0x208,
      0x208,   0x208,   0x7ffff, 0x7ffff, 0x208, 0x21f, 0x21f,   0x208,
      0x21f,   0x21f,   0x21f,   0x208,   0x208, 0x208, 0x21f,   0x21f,
      0x208,   0x208,   0x208,   0x208,   0x21f, 0x208, 0x208,   0x208,
      0x208,   0x21f,   0x21f,   0x21f,   0x208, 0x208, 0x208,   0x208,
      0x7ffff, 0x7ffff, 0x21f,   0x208,   0x208, 0x208, 0x21f,   0x21f}};

  int ssc = int((roi+4)/8);

  bool isOKS = (((oks[hemi][sector]>>ssc) & 0x1) == 0);

  return isOKS;

}

bool TriggerMenuEstimate::EIFIRoI(const int side, const int sector, const int roi)
{
  std::string buf, tag;
  char delimiter = '\n';
  bool isRoI = false;

  if(side==1){
    std::ifstream fin("/gpfs/fs7001/shiomi/ATLAS/Physics/TriggerRate/InnerStudy/TriggerMenuEstimate/share/InnerCoincidenceEIFIMap.A.v01.db");
    while(getline(fin,buf,delimiter)){
      std::istringstream header(buf);
      int Sec, SSC, pt[6], RoI[8];
      header>>tag>>Sec>>SSC>>pt[0]>>pt[1]>>pt[2]>>pt[3]>>pt[4]>>pt[5]>>RoI[7]>>RoI[6]>>RoI[5]>>RoI[4]>>RoI[3]>>RoI[2]>>RoI[1]>>RoI[0];
      if(tag=="#"){
        if(Sec==sector){
          if(SSC==int((roi+4)/8)){
            int Num = (SSC==0) ? (roi)%8 : (roi+4)%8;
            if(RoI[Num]==1){isRoI=true;}
          }
        }
      }
    }
  }
  else if(side==0){
    std::ifstream fin("/gpfs/fs7001/shiomi/ATLAS/Physics/TriggerRate/InnerStudy/TriggerMenuEstimate/share/InnerCoincidenceEIFIMap.C.v01.db");
    while(getline(fin,buf,delimiter)){
      std::istringstream header(buf);
      int Sec, SSC, pt[6], RoI[8];
      header>>tag>>Sec>>SSC>>pt[0]>>pt[1]>>pt[2]>>pt[3]>>pt[4]>>pt[5]>>RoI[7]>>RoI[6]>>RoI[5]>>RoI[4]>>RoI[3]>>RoI[2]>>RoI[1]>>RoI[0];
      if(tag=="#"){
        if(Sec==sector){
          if(SSC==int((roi+4)/8)){
            int Num = (SSC==0) ? (roi)%8 : (roi+4)%8;
            if(RoI[Num]==1){isRoI=true;}
          }
        }
      }
    }
  }
  return isRoI;
}

