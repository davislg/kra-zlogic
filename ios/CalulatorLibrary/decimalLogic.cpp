//
//  decimalLogic.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include "decimalLogic.h"

// Constructors
kraz_core_math::DecimalLogic::DecimalLogic() 
    : Logic(kraz_core_math::NumericBase::DECIMAL) { }

// Public Methods
int kraz_core_math::DecimalLogic::getMaxLength() { return 0x09; }
