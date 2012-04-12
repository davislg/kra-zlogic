//
//  operator.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include <iostream>

#ifndef WIN32
#include "types_osx.h"
#else
#include "types_win32.h"
#endif

#ifndef OPERATOR_H
#define OPERATOR_H

extern INT64 addOp(INT64, INT64);
extern INT64 subtractOp(INT64, INT64);
extern INT64 multiplyOp(INT64, INT64);
extern INT64 divideOp(INT64, INT64);
extern INT64 andOp(INT64, INT64);
extern INT64 orOp(INT64, INT64);
extern INT64 xorOp(INT64, INT64);
extern INT64 shiftLeftOp(INT64, INT64);
extern INT64 shiftRightOp(INT64, INT64);
extern INT64 modOp(INT64, INT64);
extern INT64 notOp(INT64);

/*EopCodes:
 * Moved outside of the class so I don't have to keep dealing with scoping.
 * This enum could be defined inside the class but everytime you want to use
 * any of the values you have to case Operator::<value> 
 */
typedef enum EopCodes {
  OPCODE_UNSET       = 0x00,
  OPCODE_ADD         = 0x01,
  OPCODE_SUBTRACT    = 0x02,
  OPCODE_MULTIPLY    = 0x03,
  OPCODE_DIVIDE      = 0x04,
  OPCODE_AND         = 0x05,
  OPCODE_OR          = 0x06,
  OPCODE_XOR         = 0x07,
  OPCODE_SL          = 0x08,
  OPCODE_SR          = 0x09,
  OPCODE_MOD         = 0x0A,
  OPCODE_NOT		 = 0x0B,
  OPCODE_SIGN		 = 0x0C,
  OPCODE_EQUAL		 = 0x0D,
} EopCodes;

// Usings
using namespace std;

namespace kraz_core_math {

class Operator {

// Constants
public:


// Declarations
private:
    EopCodes value;
    INT64 (*opMethod)(INT64, INT64);
    
// Constructors
public:
    Operator();	
    Operator(const string);

// Destructors
   public:	
    ~Operator();	


// Public Methods
public:
    void set(EopCodes);
    EopCodes getValue();
    INT64 doMathOperation(INT64, INT64);
            
// Private Methods
private:
    void init();
};

}
#endif
