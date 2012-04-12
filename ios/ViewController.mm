//
//  ApplicationController.m
//  Kra-ZLogic
//
//  Created by Lawrence Davis on 4/11/10.
//  Copyright 2010 Kra-Z Development. All rights reserved.
//

//#import "ApplicationController.h"

#include "operator.h"
#include "logic.h"
#include "binaryLogic.h"
#include "decimalLogic.h"
#include "hexLogic.h"
#include "octalLogic.h"

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
//@synthesize Display;
//@synthesize BinaryDisplay1;
//@synthesize BinaryDisplay2;

// Buttons
// Numbers
@synthesize button0;
@synthesize button1;
@synthesize button2;
@synthesize button3;
@synthesize button4;
@synthesize button5;
@synthesize button6;
@synthesize button7;
@synthesize button8;
@synthesize button9;
@synthesize buttonA;
@synthesize buttonB;
@synthesize buttonC;
@synthesize buttonD;
@synthesize buttonE;
@synthesize buttonF;

// Private Declarations
kraz_core_math::Logic * logic;
NSString *display2Default;

// Methods
- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //logic = new kraz_core_math::DecimalLogic;
    display2Default = @"0000000000000000000000000000000000000000000000000000000000000000";
    displayIsDirty	= true;
    [self setMode: 2];	//kraz_core_math::NumericBase::DECIMAL];
    [self zeroDisplay];
}

- (void)viewDidUnload {
	//[self setDisplay:nil];
	//[self setBinaryDisplay1:nil];
	//[self setBinaryDisplay2:nil];
	[super viewDidUnload];
	// Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation) interfaceOrientation {
	if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
		return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
	} else {
		return YES;
	}
}

- (IBAction)buttonDigitPressed: (id) sender {
    NSString *input;
    if ((long)[sender tag] < 0x0A) {
        input = [NSString stringWithFormat:@"%d",(long)[sender tag]];
    } else {
        input = [NSString stringWithFormat:@"%X",(long)[sender tag]];
    }
    [self setDisplay0:input];
}

- (IBAction)buttonOperationPressed: (id) sender {
    [self doOp:(long)[sender tag]];
}

- (IBAction)buttonClear: (id) sender {
    [self zeroDisplay];
}

- (IBAction)modeChanged:(UISegmentedControl *)sender {
	int mode = [sender selectedSegmentIndex];
	//[self alert:[NSString stringWithFormat:@"Mode: %d",mode]];
	[self setMode:mode];
}

- (void)clearDisplay {
	[self clearDisplay1];
	[self clearDisplay2];
	displayIsDirty = false;
}

- (void)clearDisplay1 {
    [self setDisplay1:@""];
}

- (void)clearDisplay2 {
    [self setDisplay2:display2Default];
}

- (void)zeroDisplay {
    displayIsDirty=true;
	[self clearDisplay];
	[self setDisplay0:@"0"];
	displayIsDirty=true;
	logic->reset();
}

- (void)setDisplay0:(NSString*)value {
  	if (displayIsDirty){
		[self clearDisplay];
	}
	[self setDisplay1:value];
	[self setDisplay2:display.text];  
}

- (void)setDisplay1:(NSString*)value {
    NSString *displayText = display.text;
	if (displayText==@"-") {
        displayText=@"";
	}
	// Trim leading 0s in Binary Mode
	if (logic->numericBase->getValue()==kraz_core_math::NumericBase::BINARY) {
		NSRange beginRange = [value rangeOfString:@"1" options:NSCaseInsensitiveSearch];
		NSRange range = NSMakeRange(beginRange.location, value.length - beginRange.location);
		if (beginRange.location < 64 && value.length > 22) {
			value = [value substringWithRange:range];
			
		}
	}
	
	if (([displayText length]) <= [self getDisplayMaxLength]){
		if (!displayIsDirty){
			displayText=[displayText stringByReplacingOccurrencesOfString:@" " withString:@""];
			displayText=[NSString stringWithFormat:@"%@%@ ",displayText, value];
		} else {
			displayText=[displayText stringByReplacingOccurrencesOfString:@" " withString:@""];
			displayText=[NSString stringWithFormat:@"%@ ",value];
		}
        
	} else if (([displayText length]) > [self getDisplayMaxLength ]) {
		if (displayIsDirty){
			displayText=[displayText stringByReplacingOccurrencesOfString:@" " withString:@""];
			displayText=[NSString stringWithFormat:@"%@ ",value];
		}
	}
    
	if (logic->numericBase->getValue()==kraz_core_math::NumericBase::HEX) {
		displayText = [displayText uppercaseString];
	}
	if (([displayText length]) > 60){
		[display setFont: [UIFont fontWithName:@"Helvetica" size:8.0f]];
	}else if (([displayText length]) > 64) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:8.0f]];
	}else if (([displayText length]) > 56) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:8.0f]];
	}else if (([displayText length]) > 48) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:8.0f]];
	}else if (([displayText length]) > 40) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:10.0f]];
	}else if (([displayText length]) > 32) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:12.0f]];
	}else if (([displayText length]) > 24) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:16.0f]];
	}else if (([displayText length]) > 19) {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:20.0f]];
	} else {
		[display setFont: [UIFont fontWithName:@"Helvetica" size:24.0f]];
	}
    
	display.text=displayText;
}

- (void)setDisplay2:(NSString*)value {
    if (value==0x00 || value==@"" || value==@"-") {
        value=display2Default;
	}
	
	std::string input = [value UTF8String];
	NSString *d2 = [NSString stringWithUTF8String: logic->toBin(input).c_str()];
	
	if ([d2 length]==64){
        
		// Break into 2 parts (upper and lower 32 bits)
		NSString *d2a = [d2 substringWithRange:NSMakeRange(0,32)];
		NSString *d2b = [d2 substringWithRange:NSMakeRange(32, 32)];		
		
		// Break upper 32 bits into 4 bit increments
		NSString *d2a1 = [d2a substringWithRange:NSMakeRange(0, 4)]; 
		NSString *d2a2 = [d2a substringWithRange:NSMakeRange(4, 4)]; 
		NSString *d2a3 = [d2a substringWithRange:NSMakeRange(8, 4)]; 
		NSString *d2a4 = [d2a substringWithRange:NSMakeRange(12, 4)]; 
		NSString *d2a5 = [d2a substringWithRange:NSMakeRange(16, 4)]; 
		NSString *d2a6 = [d2a substringWithRange:NSMakeRange(20, 4)]; 
		NSString *d2a7 = [d2a substringWithRange:NSMakeRange(24, 4)]; 
		NSString *d2a8 = [d2a substringWithRange:NSMakeRange(28, 4)]; 
        
		// Break lower 32 bits into 4 bit increments
		NSString *d2b1 = [d2b substringWithRange:NSMakeRange(0, 4)]; 
		NSString *d2b2 = [d2b substringWithRange:NSMakeRange(4, 4)]; 
		NSString *d2b3 = [d2b substringWithRange:NSMakeRange(8, 4)]; 
		NSString *d2b4 = [d2b substringWithRange:NSMakeRange(12, 4)]; 
		NSString *d2b5 = [d2b substringWithRange:NSMakeRange(16, 4)]; 
		NSString *d2b6 = [d2b substringWithRange:NSMakeRange(20, 4)]; 
		NSString *d2b7 = [d2b substringWithRange:NSMakeRange(24, 4)]; 
		NSString *d2b8 = [d2b substringWithRange:NSMakeRange(28, 4)]; 
		
		binaryDisplay2.text = [NSString stringWithFormat:@"%@ %@  %@ %@  %@ %@  %@ %@", 
                               d2a1, d2a2, d2a3, d2a4, d2a5, d2a6, d2a7, d2a8];
		binaryDisplay1.text = [NSString stringWithFormat:@"%@ %@  %@ %@  %@ %@  %@ %@", 
                               d2b1, d2b2, d2b3, d2b4, d2b5, d2b6, d2b7, d2b8];
	}
}

- (void)setMode:(INT32)value {
    [display setFont: [UIFont fontWithName:@"Helvetica" size:24.0f]];
	displayIsDirty=true;
	if (logic == 0x00) {
		logic = new kraz_core_math::DecimalLogic;
	}
	NSString *newValue = [[NSString alloc]initWithString:(NSString *)@""];
	std::string input = [display.text UTF8String];
	switch (value) {
		case 0:
			//[lblDisplay1 setFont: [UIFont fontWithName:@"Helvetica" size:8.0f]];
			newValue=[NSString stringWithUTF8String:logic->toBinDisplay(input).c_str()];
			logic = new kraz_core_math::BinaryLogic;
			break;
		case 1:
			newValue=[NSString stringWithUTF8String:logic->toOct(input).c_str()];
			logic = new kraz_core_math::OctalLogic;
			break;
		case 2:
			newValue=[NSString stringWithUTF8String:logic->toDec(input).c_str()];
			logic = new kraz_core_math::DecimalLogic;
			break;
		case 3:
			newValue=[NSString stringWithUTF8String:logic->toHex(input).c_str()];
			logic = new kraz_core_math::HexLogic;
			break;
		default:
			break;
	}	
	[self setDisplay0:newValue];
	[self enableNumbers:logic->numericBase->getValue()];
	displayIsDirty = true;
}

- (INT32)getDisplayMaxLength {
	NSString *value = display.text;
	switch(logic->numericBase->getValue()){
		case kraz_core_math::NumericBase::BINARY:
			return 64;
			break;
		case kraz_core_math::NumericBase::OCTAL:
			if ([value hasPrefix:@"1"]) {
				return 22;
			}
			return 21;
			break;
		case kraz_core_math::NumericBase::DECIMAL:
			return 18;
			break;
		case kraz_core_math::NumericBase::HEX:
			return 16;
			break;
		default:
			return 18;
			break;
	}

}

- (void)doOp:(INT32)value {
    //INT64 result = 0x00;
	NSString *rslt;
	boolean_t updateDisplay = false;
	displayIsDirty=true;
	rslt = display.text;
	
	if (
		//value==OPCODE_EQUAL
		//|| 
		value==OPCODE_SIGN
		|| value==OPCODE_NOT
		) {
		if (value==OPCODE_NOT) {
			rslt = [NSString stringWithUTF8String:logic->notOp([display.text UTF8String]).c_str()];
			updateDisplay = true;
		} else if (value==OPCODE_SIGN) {
			rslt = [NSString stringWithUTF8String:logic->setSign([display.text UTF8String]).c_str()];
			updateDisplay = true;
		}
		//logic->setNum1([rslt UTF8String]);
		//logic->num2Set=false;
		//logic->setNum2("0");
	}else{
		if (logic->num1Set){
			if (logic->num2Set){
				if (value==OPCODE_EQUAL) {
					if (logic->num1Set && logic->num2Set) {
						rslt = [NSString stringWithUTF8String:logic->doOperation().c_str()];
						updateDisplay=true;
						logic->num1Set=false;
						logic->num2Set=false;
					}
				} else {
					rslt = [NSString stringWithUTF8String:logic->doOperation().c_str()];
					updateDisplay=true;
					logic->setNum1([rslt UTF8String]);
					logic->num2Set=false;
					logic->op->set((EopCodes)value);
					updateDisplay=true;
				}
			} else {
				logic->setNum2([display.text UTF8String]);
				if (value==OPCODE_EQUAL) {
					if (logic->num1Set && logic->num2Set) {
						rslt = [NSString stringWithUTF8String:logic->doOperation().c_str()];
						updateDisplay=true;
						logic->num1Set=false;
						logic->num2Set=false;
					}
				} else {				
					if (logic->num1Set && logic->num2Set) {
						rslt = [NSString stringWithUTF8String:logic->doOperation().c_str()];
						logic->setNum1([rslt UTF8String]);
						logic->op->set((EopCodes)value);
						logic->num2Set=false;
						//rslt = [NSString stringWithUTF8String:logic->doOperation().c_str()];
						updateDisplay=true;
					}
				}
			}
		} else {
			logic->setNum1([display.text UTF8String]);
			if(value!=OPCODE_EQUAL){ logic->op->set((EopCodes)value); }
		}
	}
	
	if(updateDisplay){
		[self setDisplay0:rslt];
	}
	
	displayIsDirty=true;
	if (value==OPCODE_SIGN) {
		//displayIsDirty=false;
	}  
}

- (void)disableNumbers {
	[button2 setEnabled:FALSE];
	[button3 setEnabled:FALSE];
	[button4 setEnabled:FALSE];
	[button5 setEnabled:FALSE];
	[button6 setEnabled:FALSE];
	[button7 setEnabled:FALSE];
	[button8 setEnabled:FALSE];
	[button9 setEnabled:FALSE];
	[buttonA setEnabled:FALSE];
	[buttonB setEnabled:FALSE];
	[buttonC setEnabled:FALSE];
	[buttonD setEnabled:FALSE];
	[buttonE setEnabled:FALSE];
	[buttonF setEnabled:FALSE];    
}

- (void)enableNumbers:(INT32)value {
    [self disableNumbers];
    
	switch (value) {
		case kraz_core_math::NumericBase::HEX: //0x10:
			[buttonF setEnabled:TRUE];
			[buttonE setEnabled:TRUE];
			[buttonD setEnabled:TRUE];
			[buttonC setEnabled:TRUE];
			[buttonB setEnabled:TRUE];
			[buttonA setEnabled:TRUE];
		case kraz_core_math::NumericBase::DECIMAL: //0x0A:
			[button9 setEnabled:TRUE];
			[button8 setEnabled:TRUE];
		case kraz_core_math::NumericBase::OCTAL: //0x08:
			[button7 setEnabled:TRUE];
			[button6 setEnabled:TRUE];
			[button5 setEnabled:TRUE];
			[button4 setEnabled:TRUE];
			[button3 setEnabled:TRUE];
			[button2 setEnabled:TRUE];
		case kraz_core_math::NumericBase::BINARY: //0x02:
			// Nothing to do
			// 0 & 1 are enabled by default
		default:
			break;
	}
}

- (void)alert:(NSString*)value {
    UIAlertView *alertView = [[UIAlertView alloc] 
                               initWithTitle:@"Alert" message:value delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
	[alertView show];
}

@end