//
//  StringTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-27.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DSString.h"

@interface StringTest : XCTestCase

@end

@implementation StringTest

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testMatch
{
    char* s = "ababcabcacbab";
    char* t = "abc";
    int idx = findIndex(s, t,0);
    
    XCTAssertTrue(idx==2, @"");
    printf("*****idx:%d\n",idx);
    
    char* str = "BBC ABCDAB ABCDABCDABDE";
    char* tmp = "ABCDABD";
    
    int index1 = KMPMatch(str, tmp);
    int index2 = BFMatch(str, tmp);
    
    printf("*****index1:%d index2:%d \n",index1,index2);
    
    XCTAssertTrue(index1==index2, @"");
}

@end
