//
//  octalLogic.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include "octalLogic.h"

// Constructors
kraz_core_math::OctalLogic::OctalLogic() 
	: Logic(kraz_core_math::NumericBase::OCTAL) { }

// Public Methods
int kraz_core_math::OctalLogic::getMaxLength() { return 0x0A; }
