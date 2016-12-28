//
//  ship_base.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "ship_base.hpp"
#include "model_state.hpp"

namespace ship {
    
    void base::addThrusters( thruster_::configuration & tconfig ){
        const int num_thrusters = 2;
        double maxThrusts[num_thrusters]= { 1.0, 1.0 };
        vec3 locations[num_thrusters]   = { vec3(-1,1,0), vec3(-1,-1,0) };
        vec3 directions[num_thrusters]  = { vec3(-1,0,0), vec3(-1,0,0) };
        
        for(int i = 0; i < num_thrusters; ++i ){
            thruster t;
            t.setMass(mprops.getMass());
            t.setMaxThrust(maxThrusts[i]);
            t.setThrust(0.0);
            t.setThrustDirection(directions[i]);
            t.setThrusterLocation(locations[i]);
            tconfig.addThruster(t);
        }
        
    }
    
    base::base() {
        local::state<num_type> & s = this->getLocalState();
        eom.setEOM_State(&s[0]);
        eom.setMass(mprops.getMass());
        eom.setInertia(mprops.getI(), mprops.getIinv());
        tconfig.setEOM(eom);
        
        // setup thrusters
        addThrusters(tconfig);
        tconfig.addThrustersToEOM();
        
    }
    base::~base() {
        
    }
    std::string base::name() const {
        return "base_ship";
    }
    void base::init() {
        
    }
    void base::update() {
        eom.updateComponents();
    }
    int  base::numDims() const {
        return eom.numDims();
    }
    void base::setupPrintData( Printer & p ) {
        
    }
    void base::operator()( num_type & time, ModelState & dqdt ) {
        doAIComputations();
        eom(time,&dqdt[0]);
    }
    
    bool base::doFireBullet() const {
        return false;
    }

}
