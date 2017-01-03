//
//  thruster.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "thruster.hpp"



thruster::thruster():mass(nullptr),T(0) {
    
}
void thruster::setMass( double & m ) {
    mass = &m;
}
void thruster::setThrustDirection( const vec3 & dir_ ) {
    dir = dir_;
}
void thruster::setThrusterLocation( const vec3 & loc_ ) {
    loc = loc_;
}
void thruster::setThrust( const double & thrust ) {
    if( thrust >= 0 ){
        if( thrust > Tmax ){ T = Tmax; }
        else{ T = thrust; }
    }
    else{ T = 0.0; }
}

void thruster::setMaxThrust( const double & thrust ){
    Tmax = thrust;
}

double thruster::getMaxThrust() const {
    return Tmax;
}

void thruster::getForce( double time, vec3 & outForce ) {
    outForce = ref_body->getAttitude().rotate(dir*T);
}
void thruster::getLocation( double time, vec3 & locBody ) {
    locBody = loc;
}
void thruster::getBodyMoment( double time, vec3 & outMomentBody ) {
    vec3 loc, force = dir*T;
    getLocation(time, loc);
    outMomentBody = loc.cross(force);
}


//vec3 dir, loc;
//double T, *mass;
