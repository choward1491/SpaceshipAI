//
//  get_control.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/4/17.
//  Copyright © 2017 Christian Howard. All rights reserved.
//

#include "get_control.hpp"
#include "NeuralNet.hpp"

namespace ship {
    
    void get_control::setNetwork( NeuralNet & net ) {
        cnet = &net;
    }
    void get_control::setInitInput( std::vector<double> & in_ ) {
        in = in_;
    }
    double get_control::operator()( opt::Mat & m ) {
        for(int i = 0; i < 11; ++i ){
            in[13+i] = m(i);
        }
        (*cnet)(in,out);
        return -out[0];
    }

    //NeuralNet* cnet;
    //std::vector<double> in, out;
    
}
