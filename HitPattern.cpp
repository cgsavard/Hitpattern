//
//  HitPattern.cpp
//  hitpattern
//
//  Created by Jingyan Li on 4/6/20.
//  Copyright © 2020 Jingyan Li. All rights reserved.
//

#include "HitPattern.hpp"

HitPattern::HitPattern(int hitpattern, double eta){
    eta_=eta;
    hitpattern_=hitpattern;
    iEtaReg_=findEtaReg(eta);
    numExpLayer_=layerMap[iEtaReg_][0];
}

int HitPattern::findEtaReg(double eta){
    for (int i=0;i<numEtaRegs;i++){
        if (eta>etaRegions_[i]&&eta<etaRegions_[i+1]){
            return i;
        }
    }
    return -1;
}

void HitPattern::setMissingLayer(){
    int ProbingLayer;
    int LayerID;
    
    for (int i=0; i<numExpLayer_; i++){
        ProbingLayer=((1<<i)&hitpattern_)>>i;
        LayerID=layerMap[iEtaReg_][i+1];
        if (!ProbingLayer){
            switch (LayerID) {
                case 1:
                    isL1Missing=1;
                    numMissingLayer++;
                    numMissingPS++;
                    break;
                case 2:
                    isL2Missing=1;
                    numMissingLayer++;
                    numMissingPS++;
                    if (iEtaReg_==6){
                        isD1Missing=1;
                        numMissingLayer++;
                        numMissingPS++;
                    }
                    break;
                case 3:
                    isL3Missing=1;
                    numMissingLayer++;
                    numMissingPS++;
                    if (iEtaReg_==5){
                        isL4Missing=1;
                        numMissingLayer++;
                        numMissing2S++;
                    }
                    break;
                case 4:
                    isL4Missing=1;
                    numMissingLayer++;
                    numMissing2S++;
                    break;
                case 5:
                    isL5Missing=1;
                    numMissingLayer++;
                    numMissing2S++;
                    break;
                case 6:
                    isL6Missing=1;
                    numMissingLayer++;
                    numMissing2S++;
                    break;
                case 7:
                    isD1Missing=1;
                    numMissingLayer++;
                    if(eta_>diskModuleCut[0]){
                        numMissingPS++;
                    }
                    else{
                        numMissing2S++;
                    }
                    if (iEtaReg_==4){
                        isD1Missing=0.5;
                        isL5Missing=0.5;
                    }
                    break;
                case 8:
                    isD2Missing=1;
                    numMissingLayer++;
                    if(eta_>diskModuleCut[1]){
                        numMissingPS++;
                    }
                    else{
                        numMissing2S++;
                    }
                    if (iEtaReg_==4){
                        isD2Missing=0.5;
                        isL6Missing=0.5;
                    }
                    break;
                case 9:
                    isD3Missing=1;
                    numMissingLayer++;
                    if(eta_>diskModuleCut[2]){
                        numMissingPS++;
                    }
                    else{
                        numMissing2S++;
                    }
                    if (iEtaReg_==4||iEtaReg_==5){
                        isD3Missing=0.5;
                        numMissingLayer-=0.5;
                        numMissing2S-=0.5;
                    }
                    break;
                case 10:
                    isD4Missing=1;
                    numMissingLayer++;
                    if(eta_>diskModuleCut[3]){
                        numMissingPS++;
                    }
                    else{
                        numMissing2S++;
                    }
                    if (iEtaReg_==5){
                        isD4Missing=0.5;
                        numMissingLayer-=0.5;
                        numMissing2S-=0.5;
                    }
                    break;
                case 11:
                    isD5Missing=1;
                    numMissingLayer++;
                    if (eta_>diskModuleCut[4]){
                        numMissingPS++;
                    }
                    else{
                        numMissing2S++;
                    }
                    break;
                    
                default:
                    break;
            }
            
        }
    }
    
}


