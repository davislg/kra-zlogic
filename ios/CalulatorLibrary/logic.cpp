//
//  logic.cpp
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "logic.h"

// Usings
using namespace std;

// Prototypes
//template <typename T>
//inline T highbit(T& t);

//string toString(T& t, ios_base & (*f)(ios_base&));

INT64 toLong(const char *, int); void init();

// Constructors
kraz_core_math::Logic::Logic(const int base) { 
    kraz_core_math::Logic::numericBase = new kraz_core_math::NumericBase(base);
    kraz_core_math::Logic::op = new kraz_core_math::Operator();
	
	kraz_core_math::Logic::num1 = 0;
    kraz_core_math::Logic::num2 = 0;
    kraz_core_math::Logic::result = 0;
	kraz_core_math::Logic::positive = true;
    kraz_core_math::Logic::num1Set = false;
    kraz_core_math::Logic::num2Set = false;
    kraz_core_math::Logic::resultSet = false;
}

// Private Methods
//string trim(string value) {
//	value = remove(value.begin(), value.end(), ' ');
//	return value;
//}

string trim(string str) {
	size_t startpos = str.find_first_not_of(" \t");
	size_t endpos = str.find_last_not_of(" \t");
	
	if ((string::npos == startpos) || (string::npos == endpos)) {
		str = "";
	} else {
		str = str.substr(startpos, endpos-startpos+1);
	}
	return str;

}

char *trim(char *value) {
	string s;
	ostringstream oss;
	oss << value;
	return (char *)trim(oss.str()).c_str();
}

void kraz_core_math::Logic::init() {
    numericBase = new kraz_core_math::NumericBase(kraz_core_math::NumericBase::DECIMAL);
    op = new kraz_core_math::Operator;

    num1 = 0x00;
    num2 = 0x00;
    result = -1;
    positive = true;
    num1Set = false;
    num2Set = false;
    resultSet = false;
}

template < typename T >
inline T highbit(T& t){
    return t = (((T)(-1)) >> 1) + 1;
}

template <class T>
string toString(T& t, ios_base & (*f)(ios_base&)) {
  ostringstream oss;
  oss << f << t;
  return oss.str();
}

string kraz_core_math::Logic::toString(INT64 value, int base) {
    string r;
    switch(base){
        case kraz_core_math::NumericBase::BINARY:
            r = toBin(value);
            break;
        case kraz_core_math::NumericBase::OCTAL:
            r = toOct(value);
            break;
        case kraz_core_math::NumericBase::DECIMAL:
            r = toDec(value);
            break;
        case kraz_core_math::NumericBase::HEX:
            r = toHex(value);
            break;
        default:
            r = toDec(value);
            break;
    }
    return r;
}

INT64 kraz_core_math::Logic::toLong(const char * value, int base) {
    //Initialize result to 0
	string tmp = trim(value);
	if (strcmp(value,"")==0) {
		value = 0x00;
	}
    INT64 ret = 0;
	int pos = tmp.find("-");

	bool isNegative = (pos!=-1)?true:false;
	char *str = (char *)value;

    //Process characters in order from most significant to least significant
    while(*str) {
        //shift the number left a place
        ret *= base;

        //add the current digit
        if ('A' <= *str && *str <= 'Z') {
            ret += *str - 'A' + 10;
        } else if ('a' <= *str && *str <= 'z') {
            ret += *str - 'a' + 10;
		} else if ('-' == *str) {
			// do nothing
        } else {
            ret += *str - '0';
        }
        //move to the next digit
        str++;
    }

	if (isNegative) {
		ret *= -1;
	}

    return ret;
}

// Public Methods
// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toBin(INT64 value) {
    std::ostringstream oss;
    for ( unsigned INT64 bit = highbit(bit); bit; bit >>= 1 ){
	    oss << ( ( value & bit ) ? '1' : '0' );
    }
    return oss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toBin(const string value) {
	const char * c = trim(value).c_str();
	//INT64 l = toLong(c,kraz_core_math::NumericBase::DECIMAL);
	INT64 l = 0x00;
	try {
		l = toLong(c,numericBase->getValue());
	}
	catch (...) {
		l = 0x00;
	}
	std::ostringstream oss;
    for ( unsigned INT64 bit = highbit(bit); bit; bit >>= 1 ){
	    oss << ( ( l & bit ) ? '1' : '0' );
    }
    return oss.str();
}

string kraz_core_math::Logic::toBinDisplay(const string value) {
	string displayValue = toBin(value);
	size_t pos = 0x00;
	pos = displayValue.find("1");
	if (pos>64){
		pos=63;
	}
	int endpos = strlen(displayValue.c_str()) - pos;
	displayValue = displayValue.substr(pos,endpos);
	
	return displayValue;
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toOct(INT64 value) {
    stringstream ss;
    ss << std::oct << value;
    return ss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toOct(const string value) {
	const char * c = trim(value).c_str();
    stringstream ss;
    //ss << std::oct << toLong(c, kraz_core_math::NumericBase::DECIMAL);
	INT64 l = 0x00;
	try {
		l = toLong(c,numericBase->getValue());
	}
	catch (...) {
		l = 0x00;
	}
    ss << std::oct << l;
    return ss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toDec(INT64 value) {
    stringstream ss;
    ss << std::dec << value;
    return ss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toDec(const string value) {
   	const char * c = trim(value).c_str();
	stringstream ss;
    //ss << std::dec << toLong(c, kraz_core_math::NumericBase::DECIMAL);
	INT64 l = 0x00;
	try {
		l = toLong(c,numericBase->getValue());
	}
	catch (...) {
		l = 0x00;
	}
    ss << std::dec << l;
    return ss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toHex(INT64 value) {
    stringstream ss;
    ss << std::hex << value;
    return ss.str();
}

// Always assume value is Decimal (Base 10)
string kraz_core_math::Logic::toHex(const string value) {
	const char * c = trim(value).c_str();
    stringstream ss;
    //ss << std::hex << toLong(c, kraz_core_math::NumericBase::DECIMAL);
	INT64 l = 0x00;
	try {
		l = toLong(c,numericBase->getValue());
	}
	catch (...) {
		l = 0x00;
	}
    ss << std::hex << l;
    return ss.str();
}

// Value is converted to Decimal (Base 10)
INT64 kraz_core_math::Logic::fromBin(string bin) {
    return toLong(trim(bin).c_str(), kraz_core_math::NumericBase::BINARY); 
}

// Value is converted to Decimal (Base 10)
INT64 kraz_core_math::Logic::fromOct(string oct) {
    return toLong(trim(oct).c_str(), kraz_core_math::NumericBase::OCTAL); 
}

// Value is converted to Decimal (Base 10)
INT64 kraz_core_math::Logic::fromDec(string dec) {
    return toLong(trim(dec).c_str(), kraz_core_math::NumericBase::DECIMAL); 
}

// Value is converted to Decimal (Base 10)
INT64 kraz_core_math::Logic::fromHex(string hex) {
    return toLong(trim(hex).c_str(), kraz_core_math::NumericBase::HEX); 
}

bool kraz_core_math::Logic::isNum1Set() { return num1Set; }
bool kraz_core_math::Logic::isNum2Set() { return num2Set; }
bool kraz_core_math::Logic::isResultSet() { return resultSet; }

void kraz_core_math::Logic::reset(){
    num1 = 0x00;
    num2 = 0x00;
    result = -1;
    num1Set = false;
    num2Set = false;
    resultSet = false;
}  

kraz_core_math::NumericBase *kraz_core_math::Logic::getNumericBase(){ return numericBase; }
kraz_core_math::Operator *kraz_core_math::Logic::getOperator(){ return op; }   

string kraz_core_math::Logic::setSign(string value){
	value = trim(value);
    INT64 r = toLong(value.c_str(), numericBase->getValue()); 
    r *= -1;
    return toString(r, numericBase->getValue()); // kraz_core_math::NumericBase::DECIMAL);
}

INT64 addOp(INT64 num1, INT64 num2){ return (num1 + num2); }
INT64 subtractOp(INT64 num1, INT64 num2){ return (num1 - num2); }
INT64 multiplyOp(INT64 num1, INT64 num2){ return (num1 * num2); }
INT64 divideOp(INT64 num1, INT64 num2){ return (num1 / num2); }
INT64 andOp(INT64 num1, INT64 num2){ return (num1 & num2); }
INT64 orOp(INT64 num1, INT64 num2){ return (num1 | num2); }
INT64 xorOp(INT64 num1, INT64 num2){ return (num1 ^ num2); }
INT64 shiftLeftOp(INT64 num1, INT64 num2){ return (num1 << num2); }
INT64 shiftRightOp(INT64 num1, INT64 num2){ return (num1 >> num2); }
INT64 modOp(INT64 num1, INT64 num2) { return (num1 % num2); }
INT64 notOp(INT64 num1) { return ~(num1); }

string kraz_core_math::Logic::notOp(string value) {
    value = trim(value);
	if (value == ""){ value = "0"; }
    INT64 r = ~(toLong(value.c_str(), numericBase->getValue()));
    return toString(r,numericBase->getValue());
}

void kraz_core_math::Logic::equal() {
#if 0 //Old Way
    //int opValue = op.getValue();
    int opValue = op->getValue();
    switch (opValue) {
        case kraz_core_math::Operator::ADD:
            result = addOp();
            break;
        case kraz_core_math::Operator::SUBTRACT:
            result = subtractOp();
             break;
        case kraz_core_math::Operator::MULTIPLY:
            result = multiplyOp();
            break;
        case kraz_core_math::Operator::DIVIDE:
            result = divideOp();
            break;
        case kraz_core_math::Operator::AND:
            result = andOp();
            break;
        case kraz_core_math::Operator::OR:
            result = orOp();
            break;
        case kraz_core_math::Operator::XOR:
            result = xorOp();
            break;
        case kraz_core_math::Operator::SL:
            result = shiftLeftOp();
            break;
        case kraz_core_math::Operator::SR:
            result = shiftRightOp();
            break;
        case kraz_core_math::Operator::MOD:
            result = modOp();
            break;
        default:
            result = 0;
            break;
    }
#else //New way

  //Validate the opCode 
  EopCodes opValue = op->getValue();
  if (opValue == OPCODE_UNSET) return;

  //Make sure there are two number on which to perform the operation
  if (!num1Set || !num2Set) return;

  //Do the mathmatical operation and return the result
  result = toLong(doOperation().c_str(), numericBase->getValue());
#endif 
}

string kraz_core_math::Logic::doOperation() {
	if (op->getValue() != OPCODE_UNSET) {
		//Call the function referenced by the function pointer
		return toString(op->doMathOperation(num1, num2), numericBase->getValue());
	}
	return 0;
}

void kraz_core_math::Logic::setNum1(const string value) {
	num1Set = true;
	num1 = toLong(trim(value).c_str(), numericBase->getValue());
}

void kraz_core_math::Logic::setNum2(const string value) {
	num2Set = true;
	num2 = toLong(trim(value).c_str(), numericBase->getValue());
}


 