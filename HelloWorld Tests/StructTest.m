//
//  StructTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-23.
//  Copyright (c) 2014年 luowei. All rights reserved.
//
//结构体大小的计算方法和步骤
/*
 1)将结构体内所有数据成员的长度值相加，记为sum_a；
 2)将各数据成员为了内存对齐，按各自对齐模数而填充的字节数累加到和sum_a上，记为sum_b。对齐模数是#pragma pack指定的数值以及该数据成员自身长度中数值较小者。该数据相对起始位置应该是对齐模式的整数倍;
 3)将和sum_b向结构体模数对齐，该模数是【#pragma pack指定的数值】、【未指定#pragma pack时，系统默认的对齐模数（32位系统为4字节，64位为8字节）】和【结构体内部最大的基本数据类型成员】长度中数值较小者。结构体的长度应该是该模数的整数倍。
 
 */

#import <XCTest/XCTest.h>

typedef struct Nod1{
    int data;   //4B
    char c;     //1B
    char chars[10]; //10B
    struct Nod* next;   //8B
} Nod1;  // 4+1+10+8=23 最按照模数8的倍数对齐填充1B->24(模数8的倍数)

typedef struct Nod2{
    char c;    //1B+(3B)
    int data;  //4B+(4B) 因为此成员的首地址是2，非4的倍数，所以前面的元素后面要填充3个字节
    struct Nod* next; //8B
    char chars[10]; //10B
} Nod2;    //1+4+8+10=23+(7)=30 -> 32(模数8的倍数)

typedef struct Nod3{
    struct Nod* next; //8B
    int data;   //4B
    char c;     //1B
    char chars[10]; //10B
} Nod3; // 8+4+1+10=23 最按照模数8的倍数对齐填充1B->24

typedef struct Nod4{
    char c;     //1B+(3B)
    int data;   //4B
    char chars[3]; //1Bx3
    char chars1[3]; //1Bx3
    char chars2[5]; //1Bx5+(3B)
    struct Nod* next; //8B
} Nod4; // 30 -> 32

@interface StructTest : XCTestCase

@end

@implementation StructTest

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}



- (void)testStruct
{
    NSLog(@"Nod1 size:%lu",sizeof(Nod1)); //24
    NSLog(@"Nod2 size:%lu",sizeof(Nod2)); //32
    NSLog(@"Nod3 size:%lu",sizeof(Nod3)); //24
    NSLog(@"Nod4 size:%lu",sizeof(Nod4)); //32

}

@end
