//
//  ANSICTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-25.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>

#include "Header.h"

@interface QuestionTest : XCTestCase

@end

@implementation QuestionTest

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

-(void)testGoldCoin{
    
    int goldCoin[10];
    int tryCnt = 10000;
    int successCnt = 0;
    
    initRandom();
    //总共进行tryCnt次实验
    for( int i=0; i<tryCnt; i++ )
    {
        int max = gegenrateGoldCoin( goldCoin, 10 );
        int choose = takeCoin( goldCoin, 10 );
        
        if( max == choose ) successCnt++;
    }
    printf(" %f\n",(successCnt * 1.0 / tryCnt));
    
}

-(void)testGenerate{
    int Q[6];
    //找出前6项
    Generate( 3, 5, 6 ,Q );
    
    int exp[6]={3,5,6,9,10,12};
    XCTAssertTrue(memcmp(Q, exp, sizeof(Q))==0, @"");
}

-(void)testProc{
    
    char data[] = "SONGjianGoodBest";
    Proc( data );
    XCTAssertTrue(strcmp(data,"jianoodestONBGGS")==0,@"");
}

-(void)testIsSquare{
    int result;
    int square = IsSquare(225, &result);
    
    XCTAssertTrue(square==1 && result==15, @"");
}

-(void)testNMultiply{
    int zeroCnt = zeroCount(1024);
    XCTAssertTrue(zeroCnt==253, @"");
}

-(void)testNearestInt{
    int data[] = { 0, 1, 3, 8 };
    
//    char a[20];
//    sprintf(a,"%d",1234);
//    printf("=====:%s",a);
    
    printf("=====:%d",NearestInt( 81, data, 4 ));
}

-(void)testCountSort{
    
    int arr[64], i, md = 0xffff, diff;
    for(i = 0; i < 64; ++i){
        arr[i] = rand()&0xffff;
    }
    
//    int distance = countSort(arr);
//    printf("=====%d",distance);
    
    base_sort(arr, 64, 5);
    for(i = 1; i < 64; ++i){
        diff = arr[i] - arr[i-1];
        if(diff == 0){
            printf("arr[%d] == arr[%d]\n", i, i-1);
            continue;
        }
        if(diff < md){
            md = diff;
        }
    }
    printf("min = %d\n", md);
    
}

-(void)testDiv{
    int a = Div(100, 25);
    XCTAssertTrue(a==4,@"");
    
    int b = Div(100, 12);
    XCTAssertTrue(b==8, @"");
    
}

-(void)testGetCount{
    int pi[] = {3,4,4,5,5,5,6,6,7,7,7,8,9,10,10};
    int cnt = GetCount(pi, 3, 10, 6);
    
    XCTAssertTrue(cnt==2, @"");
}

-(void)testMaxKSlop{
    int x[]={1,6,4,2,3};
    int y[]={2,4,6,11,9};
    
    double k = getMaxKSlope(x, y);
    printf("*** max k:%f",k);
}








@end
