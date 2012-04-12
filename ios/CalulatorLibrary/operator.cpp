//
//  operator.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include <iostream>
#include <string>
#include "operator.h"
#include "logic.h"

// Usings
using namespace std;

// Constructors
kraz_core_math::Operator::Operator() { init(); }

kraz_core_math::Operator::Operator(const string op) {
    init();

    if (op == "+") {
    	set(OPCODE_ADD);
    } else if (op == "-") {
    	set(OPCODE_SUBTRACT);
    } else if (op == "x") {
    	set(OPCODE_MULTIPLY);
    } else if (op == "/") {
    	set(OPCODE_DIVIDE);
    } else if (op == "and") {
    	set(OPCODE_AND);
    } else if (op == "or") {
    	set(OPCODE_OR);
    } else if (op == "xor") {
    	set(OPCODE_XOR);
    } else if (op == "<<") {
    	set(OPCODE_SL);
    } else if (op == ">>") {
    	set(OPCODE_SR);
    } else if (op == "mod") {
    	set(OPCODE_MOD);
    }
   
}

//INT64 kraz_core_math::Logic::doOperation() {
//  if (op->getValue() != OPCODE_UNSET) {
//    //Call the function referenced by the function pointer
//    return op->doMathOperation(num1, num2);
//  }
//  return 0;
//}

// Destructors
kraz_core_math::Operator::~Operator() { }

// Public Methods
void kraz_core_math::Operator::set(EopCodes op) {
    value = op;
    switch(op) {
    case OPCODE_UNSET:
      opMethod = NULL;
      break;
    case OPCODE_ADD:
      opMethod = addOp;
      break;
    case OPCODE_SUBTRACT:
      opMethod = subtractOp;
      break;
    case OPCODE_MULTIPLY:
      opMethod = multiplyOp;
      break;
    case OPCODE_DIVIDE:
      opMethod = divideOp;
      break;
    case OPCODE_AND:
      opMethod = andOp;
      break;
    case OPCODE_OR:
      opMethod = orOp;
      break;
    case OPCODE_XOR:
      opMethod = xorOp;
      break;
    case OPCODE_SL:
      opMethod = shiftLeftOp;
      break;
    case OPCODE_SR:
      opMethod = shiftRightOp;
      break;
    case OPCODE_MOD:
      opMethod = modOp;
      break;
    
    // Required by Xcode 4.3        
    case OPCODE_NOT:
    case OPCODE_SIGN:
    case OPCODE_EQUAL:
      break;
            
    // Since there is no default if you missed one of the operation's you'd
    // get a warning about unhandled cases in your switch
    }
}

INT64 
kraz_core_math::Operator::doMathOperation(INT64 num1, INT64 num2)
{
  if (opMethod == NULL) return 0;
  return opMethod(num1, num2);
}

EopCodes 
kraz_core_math::Operator::getValue() {
    return value;
}

// Private Methods
void kraz_core_math::Operator::init() {
    value = OPCODE_UNSET; 
}
