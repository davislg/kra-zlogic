//
//  hexLogic.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include "hexLogic.h"

// Constructors
kraz_core_math::HexLogic::HexLogic() 
	: Logic(kraz_core_math::NumericBase::HEX) { }

// Public Methods
int kraz_core_math::HexLogic::getMaxLength() { return 0x08; }
