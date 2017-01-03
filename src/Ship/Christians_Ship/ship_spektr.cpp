//
//  ship_spektr.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/3/17.
//  Copyright © 2017 Christian Howard. All rights reserved.
//

#include "ship_spektr.hpp"

namespace ship {
    
    //double *ref_state;
    //bool shouldFireBullet;
    
    spektr::spektr():ref_state(nullptr),shouldFireBullet(false) {
        max_thrusts.resize(tconfig.numThrusters());
        for(int i = 0; i < tconfig.numThrusters(); ++i){
            max_thrusts[i] = tconfig.getThrusterAt(i).getMaxThrust();
        }
    }
    spektr::~spektr() {
        ref_state = nullptr;
    }
    void spektr::setDesiredState( double* state ) {
        ref_state = state;
    }
    
    void spektr::doAIComputations() {
        
    }
    bool spektr::doFireBullet() const {
        return shouldFireBullet;
    }
}
