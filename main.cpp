//
//  main.cpp
//  hitpattern
//
//  Created by Jingyan Li on 4/6/20.
//  Copyright © 2020 Jingyan Li. All rights reserved.
//

#include <iostream>
#include "HitPattern.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    HitPattern h1(12,1.5);
    h1.setMissingLayer();
    std::cout << h1.getD5Missing()<<std::endl;
    std::cout << h1.getnumMissingLayer()<<std::endl;
    std::cout << h1.getnumMissingPS()<<std::endl;
    std::cout << h1.getnumMissing2S()<<std::endl;
    return 0;
}
