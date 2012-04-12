//
//  logic.h
//
//  Created by Lawrence Davis on 3/11/10.
//  Copyright Kra-Z Development 2010. All rights reserved.
//

#ifndef LOGIC_H
#define LOGIC_H

#include "operator.h"
#include "numericBase.h"

// Usings
using namespace std;

namespace kraz_core_math {

class Logic {    
    
// Declarations
//protected: 
public:
    kraz_core_math::NumericBase *numericBase;
    kraz_core_math::Operator *op;
    
    INT64 num1;
    INT64 num2;
    INT64 result;
    bool positive;
    bool num1Set;
    bool num2Set;
    bool resultSet;

// Constructors
public:
    Logic(const int);

    
// Public Methods 
public:
    // Assume Decimal Input
    virtual string getDisplayValue(const string value) { return toDec(value); }

    // Assume Decimal Input
    virtual string getDisplayValue(INT64 value) { return toDec(value); }

    //virtual int getMaxLength() = 0;

    string itos(INT64);
    
    bool isNum1Set();
    bool isNum2Set();
    bool isResultSet();

    void reset();

    kraz_core_math::NumericBase *getNumericBase();
    kraz_core_math::Operator *getOperator();

    //INT64 doOperation();
	string doOperation();
    
    string toString(INT64, int);
 
    unsigned INT64 toULong(INT64);
    INT64 toLong(const char *, int);

    //INT64 toBin(string);
    string toBin(INT64);
    string toBin(const string);
	string toBinDisplay(const string);
    string toOct(INT64);
    string toOct(const string);
    string toDec(INT64);
    string toDec(const string);
    string toHex(INT64);
    string toHex(const string);

    INT64 fromBin(const string);
    INT64 fromOct(const string);
    INT64 fromDec(const string);
    INT64 fromHex(const string);

    string notOp(const string);
    string setSign(string);
	
    string setOperator(const string, const string);

    void equal();
    string equal(const string, bool);

    void setNum1(const string);
    void setNum2(const string);
    void setResult(const string);

	string getNum1();
    string getNum2();
	string getResult();

	bool num1IsSet();
	bool num2IsSet();
	bool resultIsSet();
	
    string getBinaryValue(const string);
    string toUnsignedString(const INT64);
    string toUnsignedString(const INT64, int bits);
    char forDigit(const INT64, const INT64);
    string padLeft(const string, const int);

    // Private Methods
    private:
	void init();

};

}

#endif

