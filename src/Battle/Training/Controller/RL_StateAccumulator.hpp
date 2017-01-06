//
//  RL_StateAccumulator.hpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/4/17.
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

#ifndef RL_StateAccumulator_hpp
#define RL_StateAccumulator_hpp

#include <vector>
#include "discrete_model.hpp"
#include "ship_spektr.hpp"

namespace rl_training {
    class state_accumulator : public discrete::model<double> {
    public:
        state_accumulator() = default;
        ~state_accumulator() = default;
        void setTrainingShip( ship::spektr * s );
        
        virtual std::string name() const;
        virtual void init();
        virtual void update();
        
        std::vector<double> & stateAt(int idx);
        std::vector<double> & actionAt(int idx);
        
    private:
        int index;
        ship::spektr* ship_;
        std::vector< std::vector<double> > state_history;
        std::vector< std::vector<double> > action_history;
    };
}

#endif /* RL_StateAccumulator_hpp */
