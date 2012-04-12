//
//  numericBase.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include "numericBase.h"

// Constructors
kraz_core_math::NumericBase::NumericBase(const int b) { 
	init();
	value = b; 
}
    
// Public Methods
//int kraz_core_math::NumericBase::getBase() {
//    return kraz_core_math::NumericBase::base;
//}
  
int kraz_core_math::NumericBase::getValue() {
    return value;
}

// Private Methods
void kraz_core_math::NumericBase::init() {
    //base = kraz_core_math::NumericBase::DECIMAL;
    value = kraz_core_math::NumericBase::DECIMAL;
}
