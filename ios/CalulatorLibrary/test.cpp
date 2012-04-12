//
//  test.cpp
//  Kra-ZLogic
//
//  Created by Lawrence Davis on 4/11/10.
//  Copyright 2010 Kra-Z Development. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "binaryLogic.h"
#include "decimalLogic.h"
#include "hexLogic.h"
#include "octalLogic.h"

using namespace std;

#define NUM1 32
#define NUM2 -32
#define NUM3 1
#define NUM4 -1

void conversionTest(); void opTest(); void binaryTest(); void octalTest(); void decimalTest(); void hexTest();

int main() {

#ifndef WIN32
    system("clear"); //clears the screen
#else
    system("cls"); //clears the screen
#endif

    // Conversion Test
    conversionTest();

    // Operator Test
    opTest();

	// Binary Test
    binaryTest();

    // Octal Test
    octalTest();

    // Decimal Test
    decimalTest();

    // Hex Test
    hexTest();

    // Pause Screen
//    char ch;
    cout << "\n\n\nPress ENTER to continue...";
//    cin.get(ch);

    return 0;
}

/********************************* Test *********************************/

/********************************* Conversion Test *********************************/
void conversionTest() {
    kraz_core_math::DecimalLogic logic;
    logic.num1 = NUM1;
    logic.num2 = NUM2;

    // Conversion
	cout << "\n******************** Conversion Test ********************" << endl;
    cout << "NUM1: " << logic.getDisplayValue(NUM1).c_str() << endl;
    cout << "To Binary: " << logic.toBin(NUM1).c_str() << endl;
    cout << "To Octal: " << logic.toOct(NUM1).c_str() << endl;
    cout << "To Decimal: " << logic.toDec(NUM1).c_str() << endl;
    cout << "To Hex: " << logic.toHex(NUM1).c_str() << endl;

    cout << "\nNUM2: " << logic.getDisplayValue(NUM2).c_str() << endl;
    cout << "To Binary: " << logic.toBin(NUM2).c_str() << endl;
    cout << "To Octal: " << logic.toOct(NUM2).c_str() << endl;
    cout << "To Decimal: " << logic.toDec(NUM2).c_str() << endl;
    cout << "To Hex: " << logic.toHex(NUM2).c_str() << endl;

	cout << "\nNUM3: " << logic.getDisplayValue(NUM3).c_str() << endl;
    cout << "To Binary: " << logic.toBin(NUM3).c_str() << endl;
    cout << "To Octal: " << logic.toOct(NUM3).c_str() << endl;
    cout << "To Decimal: " << logic.toDec(NUM3).c_str() << endl;
    cout << "To Hex: " << logic.toHex(NUM3).c_str() << endl;

	cout << "\nNUM4: " << logic.getDisplayValue(NUM4).c_str() << endl;
    cout << "To Binary: " << logic.toBin(NUM4).c_str() << endl;
    cout << "To Octal: " << logic.toOct(NUM4).c_str() << endl;
    cout << "To Decimal: " << logic.toDec(NUM4).c_str() << endl;
    cout << "To Hex: " << logic.toHex(NUM4).c_str() << endl;
}

/********************************* Operator Test *********************************/
void opTest() {
    kraz_core_math::DecimalLogic logic;
	string output = "0";
	
	cout << "\n******************** Operator Test ********************" << endl;
	// Mod
    cout << "Mod Test:" << endl;
    logic.op->set(OPCODE_MOD);

	logic.setNum1("13");
	logic.setNum2("5");
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Mod 13 % 5: " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM2));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Mod " << NUM1 << " % " << NUM2 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM4));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Mod " << NUM3 << " % " << NUM4 << ": " << output.c_str() <<  endl;

	//And
	cout << "\nAnd Test:" << endl;
    logic.op->set(OPCODE_AND);
	
	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM2));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "And " << NUM1 << " & " << NUM2 << ": " << output.c_str() <<  endl;
	
	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM4));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "And " << NUM3 << " & " << NUM4 << ": " << output.c_str() <<  endl;

	// Or
    cout << "\nOr Test:" << endl;
    logic.op->set(OPCODE_OR);

	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM2));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Or " << NUM1 << " | " << NUM2 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM4));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Or " << NUM3 << " | " << NUM4 << ": " << output.c_str() <<  endl;

	// Xor
    cout << "\nXor Test:" << endl;
    logic.op->set(OPCODE_XOR);

	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM2));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Xor " << NUM1 << " | " << NUM2 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM4));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "Xor " << NUM3 << " | " << NUM4 << ": " << output.c_str() <<  endl;

	// Shift Left
    cout << "\nShift Left Test:" << endl;
    logic.op->set(OPCODE_SL);

	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SL " << NUM1 << " << " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM2));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SL " << NUM2 << " << " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SL " << NUM3 << " << " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM4));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SL " << NUM4 << " << " << NUM1 << ": " << output.c_str() <<  endl;

	// Shift Right
    cout << "\nShift Right Test:" << endl;
    logic.op->set(OPCODE_SR);

	logic.setNum1(logic.getDisplayValue(NUM1));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SR " << NUM1 << " >> " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM2));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SR " << NUM2 << " >> " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM3));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SR " << NUM3 << " >> " << NUM1 << ": " << output.c_str() <<  endl;

	logic.setNum1(logic.getDisplayValue(NUM4));
	logic.setNum2(logic.getDisplayValue(NUM1));
    output = logic.getDisplayValue(logic.doOperation());
    cout << "SR " << NUM4 << " >> " << NUM1 << ": " << output.c_str() <<  endl;

	// Not
    cout << "\nNot Test:" << endl;
    output = logic.notOp(logic.getDisplayValue(NUM1));
    cout << "Not " << logic.getDisplayValue(NUM1).c_str() << ": " << output.c_str() <<  endl;
    output = logic.notOp(logic.getDisplayValue(NUM2));
    cout << "Not " << logic.getDisplayValue(NUM2).c_str() << ": " << output.c_str() <<  endl;
    output = logic.notOp(logic.getDisplayValue(NUM3));
    cout << "Not " << logic.getDisplayValue(NUM3).c_str() << ": " << output.c_str() <<  endl;
    output = logic.notOp(logic.getDisplayValue(NUM4));
    cout << "Not " << logic.getDisplayValue(NUM4).c_str() << ": " << output.c_str() <<  endl;

	// Set Sign
    cout << "\nSet Sign Test:" << endl;
    output = logic.setSign(logic.getDisplayValue(NUM1));
    cout << "Sign " << logic.getDisplayValue(NUM1).c_str() << ": " << output.c_str() <<  endl;
    output = logic.setSign(logic.getDisplayValue(NUM2));
    cout << "Sign " << logic.getDisplayValue(NUM2).c_str() << ": " << output.c_str() <<  endl;
    output = logic.setSign(logic.getDisplayValue(NUM3));
    cout << "Sign " << logic.getDisplayValue(NUM3).c_str() << ": " << output.c_str() <<  endl;
    output = logic.setSign(logic.getDisplayValue(NUM4));
    cout << "Sign " << logic.getDisplayValue(NUM4).c_str() << ": " << output.c_str() <<  endl;

}

/********************************* Binary Test *********************************/
void binaryTest() {
    kraz_core_math::BinaryLogic logic;
    
    string n1 = logic.toBin(NUM1);
    string n2 = logic.toBin(NUM2);
    string output;
    logic.num1 = NUM1;
    logic.num2 = NUM2;

    cout << "\n******************** Binary Test ********************" << endl;
    cout << "Base: " << (*logic.numericBase).getValue() << endl;
    cout << "Num1: " << n1.c_str() << " (" << logic.fromBin(n1) << ")" << endl;
    cout << "Num2: " << n2.c_str() << " (" << logic.fromBin(n2) << ")" <<  endl;

    // Add
    cout << "\nAdd Test:" << endl;
    logic.op->set(OPCODE_ADD);
    output = logic.toBin(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " + " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromBin(output) << ")" <<  endl;

    // Subtract
    cout << "\nSubtract Test:" << endl;
    logic.op->set(OPCODE_SUBTRACT);
    output = logic.toBin(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " - " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromBin(output) << ")" <<  endl;

    // Multiply
    cout << "\nMultiply Test:" << endl;
    logic.op->set(OPCODE_MULTIPLY);
    output = logic.toBin(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " x " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromBin(output) << ")" <<  endl;

    // Divide
    cout << "\nDivide Test:" << endl;
    logic.op->set(OPCODE_DIVIDE);
    output = logic.toBin(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " / " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromBin(output) << ")" <<  endl;
}

/********************************* Octal Test *********************************/
void octalTest() {
    kraz_core_math::OctalLogic logic;
    
    string n1 = logic.toOct(NUM1);
    string n2 = logic.toOct(NUM2);
    string output;
    logic.num1 = NUM1;
    logic.num2 = NUM2;

    cout << "\n******************** Octal Test ********************" << endl;
    cout << "Base: " << (*logic.numericBase).getValue() << endl;
    cout << "Num1: " << n1.c_str() << " (" << logic.fromOct(n1) << ")" << endl;
    cout << "Num2: " << n2.c_str() << " (" << logic.fromOct(n2) << ")" <<  endl;

    // Add
    cout << "\nAdd Test:" << endl;
    logic.op->set(OPCODE_ADD);
    output = logic.toOct(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " + " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromOct(output) << ")" <<  endl;

    // Subtract
    cout << "\nSubtract Test:" << endl;
    logic.op->set(OPCODE_SUBTRACT);
    output = logic.toOct(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " - " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromOct(output) << ")" <<  endl;

    // Multiply
    cout << "\nMultiply Test:" << endl;
    logic.op->set(OPCODE_MULTIPLY);
    output = logic.toOct(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " x " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromOct(output) << ")" <<  endl;

    // Divide
    cout << "\nDivide Test:" << endl;
    logic.op->set(OPCODE_DIVIDE);
    output = logic.toOct(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " / " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromOct(output) << ")" <<  endl;
}

/********************************* Decimal Test *********************************/
void decimalTest() {
    kraz_core_math::DecimalLogic logic;
    
    string n1 = logic.toDec(NUM1);
    string n2 = logic.toDec(NUM2);
    string output;
    logic.num1 = NUM1;
    logic.num2 = NUM2;

    cout << "\n******************** Decimal Test ********************" << endl;
    cout << "Base: " << (*logic.numericBase).getValue() << endl;
    cout << "Num1: " << n1.c_str() << " (" << logic.fromDec(n1) << ")" << endl;
    cout << "Num2: " << n2.c_str() << " (" << logic.fromDec(n2) << ")" <<  endl;

    // Add
    cout << "\nAdd Test:" << endl;
    logic.op->set(OPCODE_ADD);
    output = logic.toDec(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " + " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromDec(output) << ")" <<  endl;

    // Subtract
    cout << "\nSubtract Test:" << endl;
    logic.op->set(OPCODE_SUBTRACT);
    output = logic.toDec(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " - " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromDec(output) << ")" <<  endl;

    // Multiply
    cout << "\nMultiply Test:" << endl;
    logic.op->set(OPCODE_MULTIPLY);
    output = logic.toDec(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " x " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromDec(output) << ")" <<  endl;

    // Divide
    cout << "\nDivide Test:" << endl;
    logic.op->set(OPCODE_DIVIDE);
    output = logic.toDec(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " / " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromDec(output) << ")" <<  endl;
}

/********************************* Hex Test *********************************/
void hexTest() {
    kraz_core_math::HexLogic logic;
    
    string n1 = logic.toHex(NUM1);
    string n2 = logic.toHex(NUM2);
    string output;
    logic.num1 = NUM1;
    logic.num2 = NUM2;

    cout << "\n******************** Hex Test ********************" << endl;
    cout << "Base: " << (*logic.numericBase).getValue() << endl;
    cout << "Num1: " << n1.c_str() << " (" << logic.fromHex(n1) << ")" << endl;
    cout << "Num2: " << n2.c_str() << " (" << logic.fromHex(n2) << ")" <<  endl;

    // Add
    cout << "\nAdd Test:" << endl;
    logic.op->set(OPCODE_ADD);
    output = logic.toHex(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " + " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromHex(output) << ")" <<  endl;

    // Subtract
    cout << "\nSubtract Test:" << endl;
    logic.op->set(OPCODE_SUBTRACT);
    output = logic.toHex(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " - " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromHex(output) << ")" <<  endl;

    // Multiply
    cout << "\nMultiply Test:" << endl;
    logic.op->set(OPCODE_MULTIPLY);
    output = logic.toHex(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " x " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromHex(output) << ")" <<  endl;

    // Divide
    cout << "\nDivide Test:" << endl;
    logic.op->set(OPCODE_DIVIDE);
    output = logic.toHex(logic.doOperation());
    cout << "   " << n1.c_str() << endl;
    cout << " / " << n2.c_str() << endl;
    cout << " = " << output.c_str() << " (" << logic.fromHex(output) << ")" <<  endl;
}
