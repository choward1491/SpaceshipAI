//
//  ship_massprops.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "ship_massprops.hpp"

namespace ship {
    
    massprops::massprops() {
        mass = 1.0;
        I(0,0) = 1.0; I(1,1) = 1.0; I(2,2) = 1.0;
        Iinv = I;
    }
    
    void massprops::initialize() {
        
    }
    void massprops::update( double time )  {
        
    }
    double & massprops::getMass() {
        return mass;
    }
    mat3 & massprops::getI() {
        return I;
    }
    mat3 & massprops::getIinv() {
        return Iinv;
    }
}
