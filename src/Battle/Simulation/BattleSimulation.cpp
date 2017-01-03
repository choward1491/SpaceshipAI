//
//  BattleSimulation.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "BattleSimulation.hpp"


namespace battle {
    
    simulation::simulation(){
        players.push_back( new ship::base() );
        this->setSimHistoryPath("/Users/christianjhoward/battle.txt");
        this->setSimHistoryRate(100.0);
        this->willWriteSimHistory(true);
    }
    
    simulation::~simulation(){
        for(int i = 0; i < players.size(); ++i ){
            if( players[i] ){ delete players[i]; players[i] = nullptr; }
        }
    }
    
    bool simulation::isMonteCarloDone() {
        return (this->getCompletedMC() == 1);
    }
    void simulation::linkModelsToSim(){         // method to link models to sim
        for(int i = 0; i < players.size(); ++i){
            dynamic::model<double> & dm = *reinterpret_cast<dynamic::model<double>*>(players[i]);
            this->addDynamics(dm);
        }
        this->addDiscrete(t_step, 100.0);
    }
    bool simulation::finishedSimulation(){      // method to return whether the sim has finished
        return static_cast<double>(getTime()) >= 30.0;
    }
    void simulation::finalizeMonteCarloRun(){   // method to finalize a monte carlo run
        
    }
    void simulation::finalize(){
        timer.stop();
        printf("The simulation has completed!\n");
        printf("The simulation took %0.8lf seconds\n",timer.getDuration());
    }
    
}
