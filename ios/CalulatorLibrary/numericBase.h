//
//  numericBase.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include <iostream>

#ifndef NUMERICBASE_H
#define NUMERICBASE_H

#ifndef WIN32
#include "types_osx.h"
#else
#include "types_win32.h"
#endif

namespace kraz_core_math {

class NumericBase {

// Constants
public:
    static const int UNSET       = 0x00;
    static const int BINARY      = 0x02;
    static const int OCTAL       = 0x08;
    static const int DECIMAL     = 0x0A;
    static const int HEX         = 0x10;
    
    // Declarations
private:
    //int base;
    //std::ios_base *iosBase;
    std::ios_base *base;
    int value;

// Constructors
public:
    NumericBase(const int);

// Public Methods
public:
    int getBase();
    int getValue();

// Private Methods
private:
    void init();
};

}

#endif
