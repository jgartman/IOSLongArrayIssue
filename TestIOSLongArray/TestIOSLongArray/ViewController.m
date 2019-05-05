//
//  ViewController.m
//  TestIOSLongArray
//
//  Created by Josh Gartman on 5/5/19.
//  Copyright © 2019 Josh Gartman. All rights reserved.
//

#import "ViewController.h"
#import "TestClass.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    TestClass* t = [[TestClass alloc] init];
    [t testFunc];
}

@end
