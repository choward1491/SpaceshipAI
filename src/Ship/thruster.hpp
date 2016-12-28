//
//  thruster.hpp
//  SpaceshipBattleAI
//
//  Created by Christian J Howard on 12/28/16.
//
//  The MIT License (MIT)
//    Copyright © 2016 Christian Howard. All rights reserved.
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

#ifndef thruster_hpp
#define thruster_hpp

#include "ForceContributor.hpp"
#include "EquationsOfMotion.hpp"
#include "math3d_define.hpp"

class thruster : public ForceContributor {
public:
    
    thruster();
    void setMass( double & m );
    void setThrustDirection( const vec3 & dir_ );
    void setThrusterLocation( const vec3 & loc );
    void setThrust( const double & thrust );
    void setMaxThrust( const double & thrust );
    
    virtual void getForce( double time, vec3 & outForce );
    virtual void getLocation( double time, vec3 & locBody );
    
private:
    vec3 dir, loc;
    double T, Tmax, *mass;
};

#endif /* thruster_hpp */
