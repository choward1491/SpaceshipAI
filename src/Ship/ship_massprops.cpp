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
        const double num_points = 1533.0;
        const double mass_per_point = 1.0;
        const double inv_mpp = 1.0/mass_per_point;
        mass = mass_per_point*num_points;
        
        // inertia
        I(0,0) = mass_per_point*0.466642216720505e7;
        I(1,1) = mass_per_point*0.727800140405753e7;
        I(2,2) = mass_per_point*1.156120017509528e7;
        I(0,1) = mass_per_point*0.000002079728409e7;
        I(0,2) = mass_per_point*0.034005113848193e7;
        I(1,2) = -mass_per_point*0.000002204108250e7;
        I(1,0) = I(0,1);
        I(2,0) = I(0,2);
        I(2,1) = I(1,2);
        
        // inverse inertia
        Iinv(0,0) = 0.214757250774730e-6*inv_mpp;
        Iinv(1,1) = 0.137400358216727e-6*inv_mpp;
        Iinv(2,2) = 0.086682003632722e-6*inv_mpp;
        Iinv(0,1) = -0.000000632810280e-6*inv_mpp;
        Iinv(0,2) = -0.006316683954185e-6*inv_mpp;
        Iinv(1,2) = 0.000000280562609e-6*inv_mpp;
        Iinv(1,0) = Iinv(0,1);
        Iinv(2,0) = Iinv(0,2);
        Iinv(2,1) = Iinv(1,2);
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
