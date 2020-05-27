//
//  HitPattern.hpp
//  hitpattern
//
//  Created by Jingyan Li on 4/6/20.
//  Copyright © 2020 Jingyan Li. All rights reserved.
//

#ifndef HitPattern_hpp
#define HitPattern_hpp

#include <iostream>
#include <vector>

class HitPattern{
    
   public:
    
    HitPattern(int hitpattern, double eta);
    
    ~HitPattern(){}
    
    int findEtaReg(double eta);//converts eta to eta region index
    
    int getEtaReg(){return iEtaReg_;}
    
    int getnumExpLayer(){return numExpLayer_;}
    
    void setMissingLayer();
    
    double getL1Missing(){return isL1Missing;}// is Layer 1 missing ?
    
    double getL2Missing(){return isL2Missing;}
    
    double getL3Missing(){return isL3Missing;}
    
    double getL4Missing(){return isL4Missing;}
    
    double getL5Missing(){return isL5Missing;}
    
    double getL6Missing(){return isL6Missing;}
    
    double getD1Missing(){return isD1Missing;}
    
    double getD2Missing(){return isD2Missing;}
    
    double getD3Missing(){return isD3Missing;}
    
    double getD4Missing(){return isD4Missing;}
    
    double getD5Missing(){return isD5Missing;}
    
    double getnumMissingLayer(){return numMissingLayer;} //how many layers are missing ?
    
    double getnumMissingPS(){return numMissingPS;}// how many PS layers are missing?
    
    double getnumMissing2S(){return numMissing2S;}// how many 2S layers are missing?
    
   private:
    
    int hitpattern_;
    
    int iEtaReg_;
    
    double eta_;
    
    double isL1Missing;
    double isL2Missing;
    double isL3Missing;
    double isL4Missing;
    double isL5Missing;
    double isL6Missing;
    
    double isD1Missing;
    double isD2Missing;
    double isD3Missing;
    double isD4Missing;
    double isD5Missing;
    
    double numMissingLayer;
    
    double numMissingPS;
    
    double numMissing2S;
    
    
    static const int numEtaRegs=8;
    
    static const int numMaxLayer=7;
    
    int numExpLayer_;
    
    std::vector<double> etaRegions_= {0.0,0.20,0.41,0.62,0.90,1.26,1.68,2.08,2.4};
    
    int layerMap[numEtaRegs][numMaxLayer+1] =
    {
        { 6,  1,  2,  3,  4,  5,  6,  0 },
        { 6,  1,  2,  3,  4,  5,  6,  0 },
        { 6,  1,  2,  3,  4,  5,  6,  0 },
        { 6,  1,  2,  3,  4,  5,  6,  0 },
        { 7,  1,  2,  3,  4,  7,  8,  9 },
        { 7,  1,  2,  3,  7,  8,  9, 10 },
        { 6,  1,  2,  8,  9, 10, 11,  0 },
        { 6,  1,  7,  8,  9, 10, 11,  0 },
    };// layer map : the first element of each row tells you how many layers Kalman Filter expects.
      // different row means different eta region, eg: row 0 => eta region 1 => 0<|eta|<0.2
      // different column means Kalman Layer index, eg: row 0, column 3 => in the first eta region, the third layer we expect the particle to hit is Layer 3
      // element 1-6 Laye r1-6 7-11 Disk 1-5
    
    double diskModuleCut[5]={1.45, 1.6, 1.8, 1.975, 2.15}; //eta cut we set up to find out if a missing layer is from PS module or 2S module
    
    
};

#endif /* HitPattern_hpp */
