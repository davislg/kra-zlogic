//
//  decimalLogic.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#ifndef DECIMALLOGIC_H
#define DECIMALLOGIC_H

#include "logic.h"

namespace kraz_core_math {

    class DecimalLogic : public kraz_core_math::Logic {    

    // Constructors
public: 
    DecimalLogic();

    // Public Methods
public:
    // Assume Decimal Input
    virtual string getDisplayValue(const string value) { return toDec(value); }

    // Assume Decimal Input
    virtual string getDisplayValue(INT64 value) { return toDec(value); }

    int getMaxLength();

};

}

#endif
