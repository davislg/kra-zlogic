//
//  ViewController.h
//  Kra-ZLogic
//
//  Created by Davis on 3/19/12.
//  Copyright (c) 2012 Kra-Z Development. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController {
    NSString *string;
    BOOL displayIsDirty;
    
    long long result;
    //IBOutlet UILabel *calculatorScreen;
    long long currentOperation;
    long long currentNumber;

    IBOutlet UITextField *display;
    IBOutlet UILabel *binaryDisplay1;
    IBOutlet UILabel *binaryDisplay2;
}

- (IBAction)buttonDigitPressed:(id)sender;
- (IBAction)buttonOperationPressed:(id)sender;
- (IBAction)buttonClear:(id)sender;
- (IBAction)modeChanged:(UISegmentedControl *)sender;

// Buttons
// Numbers
@property (nonatomic, retain) IBOutlet UIButton *button0;
@property (nonatomic, retain) IBOutlet UIButton *button1;
@property (nonatomic, retain) IBOutlet UIButton *button2;
@property (nonatomic, retain) IBOutlet UIButton *button3;
@property (nonatomic, retain) IBOutlet UIButton *button4;
@property (nonatomic, retain) IBOutlet UIButton *button5;
@property (nonatomic, retain) IBOutlet UIButton *button6;
@property (nonatomic, retain) IBOutlet UIButton *button7;
@property (nonatomic, retain) IBOutlet UIButton *button8;
@property (nonatomic, retain) IBOutlet UIButton *button9;
@property (nonatomic, retain) IBOutlet UIButton *buttonA;
@property (nonatomic, retain) IBOutlet UIButton *buttonB;
@property (nonatomic, retain) IBOutlet UIButton *buttonC;
@property (nonatomic, retain) IBOutlet UIButton *buttonD;
@property (nonatomic, retain) IBOutlet UIButton *buttonE;
@property (nonatomic, retain) IBOutlet UIButton *buttonF;


// Methods
- (void)clearDisplay;
- (void)clearDisplay1;
- (void)clearDisplay2;
- (void)zeroDisplay;
- (void)setDisplay0:(NSString*)value;
- (void)setDisplay1:(NSString*)value;
- (void)setDisplay2:(NSString*)value;
- (void)setMode:(INT32)value;
- (INT32)getDisplayMaxLength;
- (void)doOp:(INT32)value;

- (void)disableNumbers;
- (void)enableNumbers:(INT32)value;
@end
