//
//  binaryLogic.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#ifndef BINARYLOGIC_H
#define BINARYLOGIC_H

#include "logic.h"

namespace kraz_core_math {

    class BinaryLogic : public kraz_core_math::Logic {    

    // Constructors
public: 
    BinaryLogic();

    // Public Methods
public:
    // Assume Decimal Input
    virtual string getDisplayValue(const string value) { return toBinDisplay(value); }

    // Assume Decimal Input
    virtual string getDisplayValue(INT64 value) { return toBin(value); }

    int getMaxLength();

};

}

#endif
