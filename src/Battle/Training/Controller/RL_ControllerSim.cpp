//
//  RL_ControllerSim.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/3/17.
//  Copyright © 2017 Christian Howard. All rights reserved.
//

#include "RL_ControllerSim.hpp"

namespace rl_training {
    
    controller::controller():des_state(13){
        timer.start();
        this->setSimHistoryPath("/Users/christianjhoward/battle2.txt");
        this->setSimHistoryRate(100.0);
        this->willWriteSimHistory(true);
        ship_.setControlNetwork(net);
        
        des_state = { 5,5,5,0,0,0,1,0,0,0,0,0,0 };
        ship_.setDesiredState( &des_state[0] );
    }
    
    controller::~controller(){
        
    }
    
    bool controller::isMonteCarloDone() {
        return (this->getCompletedMC() == 1);
    }
    void controller::linkModelsToSim(){
        this->addDynamics(ship_);
        this->addDiscrete(t_step, 100.0);
    }
    bool controller::finishedSimulation(){      // method to return whether the sim has finished
        return static_cast<double>(getTime()) >= 30.0;
    }
    void controller::finalizeMonteCarloRun(){   // method to finalize a monte carlo run
        
    }
    void controller::finalize(){
        timer.stop();
        printf("The controller has completed!\n");
        printf("The controller took %0.8lf seconds\n",timer.getDuration());
    }
    
}
