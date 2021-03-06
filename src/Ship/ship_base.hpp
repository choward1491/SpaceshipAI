//
//  ship_base.hpp
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

#ifndef ship_base_hpp
#define ship_base_hpp

#include "dynamic_model.hpp"
#include "EquationsOfMotion.hpp"
#include "thruster_configuration.hpp"
#include "ship_massprops.hpp"

namespace ship {
    using num_type = double;
    
    class base : public dynamic::model<num_type> {
    public:
        
        base();
        ~base();
        std::string name() const;
        void init();
        void update();
        int  numDims() const;
        void setupPrintData( Printer & p );
        void operator()( num_type & time, ModelState & dqdt );
        
    protected:
        thruster_::configuration tconfig;
        EquationsOfMotion eom;
        
    private:
        
        ship::massprops mprops;
        quat attitude;
        
        // internal methods
        virtual void doAIComputations();
        virtual bool doFireBullet() const;
        
        // helper methods
        void addThrusters( thruster_::configuration & tc );
    };
}



#endif /* ship_base_hpp */
