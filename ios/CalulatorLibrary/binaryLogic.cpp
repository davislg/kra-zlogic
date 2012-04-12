//
//  binaryLogic.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//
#include "binaryLogic.h"

// Constructors
kraz_core_math::BinaryLogic::BinaryLogic() 
	: Logic(kraz_core_math::NumericBase::BINARY) { }

// Public Methods
int kraz_core_math::BinaryLogic::getMaxLength() { return 0x20; } 
