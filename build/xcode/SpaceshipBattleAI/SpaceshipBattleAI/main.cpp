//
//  main.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#include "ship_base.hpp"
#include "BattleSimulation.hpp"
#include "RL_ControllerSim.hpp"

int main(int argc, const char * argv[]) {
    
    rl_training::controller csim;
    csim.run();
    
    return 0;
}
