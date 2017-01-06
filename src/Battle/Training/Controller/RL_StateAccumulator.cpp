//
//  RL_StateAccumulator.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/4/17.
//  Copyright © 2017 Christian Howard. All rights reserved.
//

#include "RL_StateAccumulator.hpp"

namespace rl_training {
    void state_accumulator::setTrainingShip( ship::spektr * s ){
        ship_ = s;
    }
    std::string state_accumulator::name() const {
        return "state_accumulator";
    }
    void state_accumulator::init() {
        index = 0;
    }
    void state_accumulator::update() {
        
    }
    std::vector<double> & state_accumulator::stateAt(int idx) {
        return state_history[idx];
    }
    std::vector<double> & state_accumulator::actionAt(int idx) {
        return action_history[idx];
    }
    
    //ship::spektr* ship_;
    //std::vector< std::vector<double> > state_history;
    //std::vector< std::vector<double> > action_history;
}
