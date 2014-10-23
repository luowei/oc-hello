//
//  StructTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-23.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>

typedef struct Nod1{
    int data;
    char c;
    char chars[10];
    struct Nod* next;
} Nod1;

typedef struct Nod2{
    char c;
    int data;
    struct Nod* next;
    char chars[10];
} Nod2;

@interface StructTest : XCTestCase

@end

@implementation StructTest

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}



- (void)testStruct
{
    NSLog(@"Nod1 size:%lu",sizeof(Nod1)); //24
    NSLog(@"Nod2 size:%lu",sizeof(Nod2)); //32
}

@end
