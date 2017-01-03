//
//  RL_ControllerSim.hpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/3/17.
//
//  The MIT License (MIT)
//    Copyright © 2017 Christian Howard. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//
//

#ifndef RL_ControllerSim_hpp
#define RL_ControllerSim_hpp

#include "uniform_sim.hpp"
#include "runge_kutta4.hpp"
#include "time_step.hpp"
#include "Timer.hpp"

namespace rl_training {
    
    class controller : public sim::uniform<double, integrate::rk4> {
    public:
        controller();
        ~controller();
        
    private:
        time_step<double> t_step;
        Timer timer;
        
        bool isMonteCarloDone();
        void linkModelsToSim();         // method to link models to sim
        bool finishedSimulation();      // method to return whether the sim has finished
        void finalizeMonteCarloRun();   // method to finalize a monte carlo run
        void finalize();
    };
    
    
}

#endif /* RL_ControllerSim_hpp */
