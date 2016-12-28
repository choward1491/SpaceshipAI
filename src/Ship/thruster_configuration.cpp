//
//  thruster_configuration.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "thruster_configuration.hpp"

namespace thruster_ {
    
    configuration::configuration():eom(nullptr){
        
    }
    void configuration::setEOM( EquationsOfMotion & eom_ ){
        eom = &eom_;
    }
    void configuration::addThruster( const thruster & T ){
        thruster Tt = T;
        Tt.setEOM(eom);
        thrusters.push_back(Tt);
    }
    thruster & configuration::getThrusterAt(int idx){
        return thrusters[idx];
    }
    int configuration::numThrusters() const{
        return static_cast<int>(thrusters.size());
    }
    
    void configuration::addThrustersToEOM() {
        for(int i = 0; i < thrusters.size(); ++i ){
            eom->addForceContributor(thrusters[i]);
        }
    }

    //std::vector<thruster> thrusters;
    //EquationsOfMotion* eom;

}
