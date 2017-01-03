//
//  ship_base.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "ship_base.hpp"
#include "model_state.hpp"
#include "history_printer.hpp"

namespace ship {
    
    void base::addThrusters( thruster_::configuration & tconfig ){
        const int num_thrusters = 11;
        
        double maxThrusts[num_thrusters]= { 5e3, 5e3, 8e3,
            500, 500,
            500, 500,
            500, 500,
            500, 500 };
        
        vec3 locations[num_thrusters]   = { vec3(-83,21,-4), vec3(-83,-21,-4), vec3(-91, 0, 5),
        vec3(-82,-56,-4), vec3(-82, 56, -4),
        vec3(-70,-61,6), vec3(-70,61,6),
        vec3(177,-70,1),vec3(177,70,1),
        vec3(177,-68,-6),vec3(177,68,-6) };
        
        vec3 directions[num_thrusters]  = { vec3(1,0,0), vec3(1,0,0), vec3(1,0,0),
        vec3(0,0,1), vec3(0,0,1),
        vec3(0,0,-1), vec3(0,0,-1),
        vec3(0,0,-1), vec3(0,0,-1),
        vec3(0,0,1), vec3(0,0,1) };
        
        for(int i = 0; i < num_thrusters; ++i ){
            thruster t;
            t.setMass(mprops.getMass());
            t.setMaxThrust(maxThrusts[i]);
            t.setThrust(0.0);
            t.setThrustDirection(directions[i]);
            t.setThrusterLocation(locations[i]);
            tconfig.addThruster(t);
        }
        
        tconfig.getThrusterAt(3).setThrust(500);
        tconfig.getThrusterAt(9).setThrust(500);
        tconfig.getThrusterAt(6).setThrust(500);
        tconfig.getThrusterAt(8).setThrust(500);
        tconfig.getThrusterAt(2).setThrust(5e3);
        
        //tconfig.getThrusterAt(9).setThrust(0*500);
        //tconfig.getThrusterAt(4).setThrust(0*500);
        
        //tconfig.getThrusterAt(7).setThrust(500);
        //tconfig.getThrusterAt(8).setThrust(500);
        
    }
    
    base::base() {
        
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
        local::state<num_type> & s = this->getLocalState();
        eom.setEOM_State(&s[0]);
        quat q0(0.0, vec3(0.0, 0, 1.0) );
        
        stateAt(0) = 0.0;
        stateAt(1) = 0.0;
        stateAt(2) = 0.0;
        
        stateAt(3) = 0.0;
        stateAt(4) = 0.0;
        stateAt(5) = 0.0;
        
        stateAt(6) = q0[0];
        stateAt(7) = q0[1];
        stateAt(8) = q0[2];
        stateAt(9) = q0[3];
        
        stateAt(10)= 0.0;
        stateAt(11)= 0.0;
        stateAt(12)= 0.0;
        
        update();
        
    }
    void base::update() {
        eom.updateComponents();
        attitude = eom.getAttitude();
        auto e_angles = eom.getAttitude().getEulerAngles();
    }
    int  base::numDims() const {
        return eom.numDims();
    }
    void base::setupPrintData( Printer & p ) {
        
        auto pos = eom.getPos();
        p.addVariableToPrint(stateAt(0), "px");
        p.addVariableToPrint(stateAt(1), "py");
        p.addVariableToPrint(stateAt(2), "pz");
        
        auto v = eom.getVel();
        p.addVariableToPrint(stateAt(3), "vx");
        p.addVariableToPrint(stateAt(4), "vy");
        p.addVariableToPrint(stateAt(5), "vz");
        
        p.addVariableToPrint(attitude[0], "q1");
        p.addVariableToPrint(attitude[1], "q2");
        p.addVariableToPrint(attitude[2], "q3");
        p.addVariableToPrint(attitude[3], "q4");
        
        auto omega = eom.getAngularVel();
        p.addVariableToPrint(stateAt(10), "wx");
        p.addVariableToPrint(stateAt(11), "wy");
        p.addVariableToPrint(stateAt(12), "wz");
    }
    void base::operator()( num_type & time, ModelState & dqdt ) {
        doAIComputations();
        eom(time,&dqdt[0]);
    }
    
    void base::doAIComputations() {
        
    }
    
    bool base::doFireBullet() const {
        return false;
    }

}
