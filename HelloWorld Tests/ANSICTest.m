//
//  ANSICTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-25.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Header.h"

@interface ANSICTest : XCTestCase

@end

@implementation ANSICTest

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

-(void)testArrayAndPoint{
    char chars[5]={'a','e','h','m','\0'};
    char ints[5]={1,2,3,4,5};
    
    int len = dim(chars);
    char* a = malloc(len * sizeof(char));
    
    XCTAssertEqual(*chars, 'a', @"");
    XCTAssertEqual(*(chars+3), 'm', @"");
    XCTAssertEqual(*chars+1, 'b', @"");
    
    XCTAssertEqual(*ints, 1, @"");
    XCTAssertEqual(*(ints+2), 3, @"");
    XCTAssertEqual(*ints+8, 9, @"");
    
    a = &chars[0];
    
    printf("\n@@@@@@@a:%s \n\n",a);
    
}

-(void)testCharAndPoint{
    
    char chars[5]={'a','b','c','d','\0'};
    char* str = charArr2Point(chars);
    
    printf("chars:%s , str:%s",chars,str);
    
    char* revertStr = revertString(chars);
    XCTAssertTrue(strcmp(revertStr,"dcba")==0, @"");
    
    revertStr = revertString2(chars);
    XCTAssertTrue(strcmp(revertStr,"dcba")==0, @"");
    
}

-(void)testMemMove{
    char d[7]={'1','2','3','4','5','6'};
    char s[7]={'a','b','c','d','e','f'};
    char *dest=d;
    char *src=s;
    
    dest=(char *)myMemmove( dest, src, 3);
    
    XCTAssertTrue(strcmp(dest, "abc456")==0, @"");
}

-(void)testSameStr{
//    char str1[10],str2[30],str3[30];
//    
//    gets( str2 );
//    gets( str3 );
//    
//    same_str( str1, str2, str3 );
//    
//    printf("/n%s/n",str1);
    
    char a[] = "abccadefgh";
    char b[] = "dgcaddefgh";
    char *r;
    int len=0;
    len = getCommon(a, b , &r);
    printf("Len is %d \n", len);
    printf("Result is %s \n", r);
}


@end
