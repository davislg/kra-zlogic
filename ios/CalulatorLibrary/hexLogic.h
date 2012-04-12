//
//  hexLogic.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#ifndef HEXLOGIC_H
#define HEXLOGIC_H

#include "logic.h"

namespace kraz_core_math {

    class HexLogic : public kraz_core_math::Logic {    

    // Constructors
public: 
    HexLogic();

    // Public Methods
public:
    // Assume Decimal Input
    virtual string getDisplayValue(const string value) { return toHex(value); }

    // Assume Decimal Input
    virtual string getDisplayValue(INT64 value) { return toHex(value); }

    int getMaxLength();

};

}

#endif
