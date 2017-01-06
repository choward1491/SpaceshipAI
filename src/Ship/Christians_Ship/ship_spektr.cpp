//
//  ship_spektr.cpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 1/3/17.
//  Copyright © 2017 Christian Howard. All rights reserved.
//

#include "ship_spektr.hpp"
#include "NeuralNet.hpp"
#include "NeuralPrototypes.hpp"
#include "FileWrap.hpp"
#include "sim_state.hpp"
#include "Matrix.hpp"

using np = NeuralPrototypes;

namespace ship {
    
    //double *ref_state;
    //bool shouldFireBullet;
    
    static np act_funcs = np();
    
    
    spektr::spektr():ref_state(nullptr),shouldFireBullet(false),cnet(nullptr),c_eps(1e-3) {
        max_thrusts.resize(tconfig.numThrusters());
        for(int i = 0; i < tconfig.numThrusters(); ++i){
            max_thrusts[i] = tconfig.getThrusterAt(i).getMaxThrust();
        }
        la::Mat<double> lb(11,1,0.0), rb(11,1,0.0);
        for(int i = 0; i < 11; ++i){ rb(i) = max_thrusts[i]; }
        pso.setdims(lb,rb);
        pso.setMaxIter( 50 );
        pso.setNumParticles( 20 );
    }
    spektr::~spektr() {
        ref_state = nullptr;
    }
    void spektr::setDesiredState( double* state ) {
        ref_state = state;
    }
    void spektr::setControlNetwork( NeuralNet & control_net ) {
        
        // initialize topology and activation functions for network
        std::vector<int> layers { 13+11, 5, 5, 5, 1 };
        control_net.setLayers(layers);
        control_net.setActivationFunc(1, act_funcs.getFunction(np::Poly) );
        control_net.setActivationFunc(2, act_funcs.getFunction(np::LeakyLU) );
        control_net.setActivationFunc(3, act_funcs.getFunction(np::Sigmoid) );
        control_net.setActivationFunc(3, act_funcs.getFunction(np::Linear) );
        nn_in_state.resize(13+11);
        nn_out_state.resize(1);
        nn_grad.resize(control_net.numWeights());
        control.resize(11);
        
        // set internal pointer to control network
        cnet = &control_net;
        
        // initialize control network based on whether it exists already or not in file
        initControlNetworkWeights();
    }
    
    void spektr::doAIComputations() {
        getControl();
    }
    bool spektr::doFireBullet() const {
        return shouldFireBullet;
    }
    
    void spektr::initControlNetworkWeights() {
        wrap::file f;
        f.openFile("cw.txt", wrap::file::Read);
        if( f.isOpen() ){
            int i;
            while( fscanf(f, "%lf\n",&cnet->weightAt(i))){ ++i; }
        }else{
            for(int i = 0; i < cnet->numWeights(); ++i){
                double s = prng.rand();
                cnet->weightAt(i) = -3.0 + s*6.0;
            }
        }
    }
    
    void spektr::getControl() {
        for(int i = 0; i < 13; ++i){
            nn_in_state[i] = ( ref_state[i] - this->stateAt(i) );
            s_vec[i] = nn_in_state[i];
        }
        
        if( prng.rand() <= c_eps ){
            for(int i = 0; i < tconfig.numThrusters(); ++i){
                tconfig.getThrusterAt(i).setThrust(max_thrusts[i]*prng.rand());
            }
        }else{
            pso.func.setNetwork(*cnet);
            pso.func.setInitInput(nn_in_state);
            pso.solve();
            opt::Mat& soln = pso.soln();
            for(int i = 0; i < tconfig.numThrusters(); ++i){
                tconfig.getThrusterAt(i).setThrust(soln(i));
                control[i] = soln(i);
            }
        }
    }
    
    const std::vector<double> & spektr::getControlVec() const {
        return control;
    }
    const std::vector<double> & spektr::getStateVec() const {
        return s_vec;
    }
    
}
