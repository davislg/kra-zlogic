//
//  octalLogic.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#ifndef OCTALLOGIC_H
#define OCTALLOGIC_H

#include "logic.h"

namespace kraz_core_math {

    class OctalLogic : public kraz_core_math::Logic {    

    // Constructors
public: 
    OctalLogic();

    // Public Methods
public:
    // Assume Decimal Input
    virtual string getDisplayValue(const string value) { return toOct(value); }

    // Assume Decimal Input
    virtual string getDisplayValue(INT64 value) { return toOct(value); }

    int getMaxLength();

};

}

#endif
