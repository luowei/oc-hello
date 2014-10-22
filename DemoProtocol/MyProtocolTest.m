//
//  MyProtocolTest.m
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import "MyProtocolTest.h"

@implementation MyProtocolTest

-(void)showInfo{
    NSLog(@"show info is calling ! ");
}

-(void)printValue:(int)value1 andValue:(int)value2{
    NSLog(@" print value1 %i and value2 %d",value1,value2);
}

-(void)print:(int)value{
    NSLog(@" print value %d ",value);
}

@end

