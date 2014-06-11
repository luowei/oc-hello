//
//  main.m
//  HelloWorld
//
//  Created by luowei on 13-10-17.
//  Copyright (c) 2013年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Circle.h"
#import "XYPoint.h"

#import "MyProtocol.h"
#import "MyProtocolTest.h"

#import "Person.h"
#import "Dog.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        //----- DemoBase --------
        NSLog(@"-------------DemoBase--------");
        
        NSLog(@"Hello, World!");

        Circle *c = [[Circle alloc] init];
        [c setR:3 andX:4 andy:5];
        c.redius = 6;
        c.x = 8;
        c.y = 10;

        [c print];
        NSLog(@"allSum : %d",[Circle allNum]);


        XYPoint *myPoint = [[XYPoint alloc] init];
        [myPoint setX:30];
        [myPoint setY:40];
        c.origin = myPoint;

        NSLog(@"origin at(%i,%i) ",c.origin.x,c.origin.y);

        //-------DemoProtocol--------
        NSLog(@"-------DemoProtocol--------");
        MyProtocolTest *myProtocolTest = [[MyProtocolTest alloc]init];
        [myProtocolTest showInfo];
        
        //判断print方法有没有实现
        SEL sel = @selector(print:);
        if([myProtocolTest respondsToSelector:sel]){
            //如果MyProtocolTest实现了print方法就调用，没有实现就不会调用
            [myProtocolTest print:8];
        }
        
        [myProtocolTest printValue:2 andValue:4];
        
        //用协议方式
        id<MyProtocol> myProtocol = [[MyProtocolTest alloc]init];
        if([myProtocol respondsToSelector:@selector(print:)]){
            [myProtocol print:100];
        }
        [myProtocol printValue:101 andValue:102];
        
        //-------DemoDelegate--------
        NSLog(@"-------DemoDelegate--------");
        Person *xiaoLi = [[Person alloc]init];
        Dog *dog = [[Dog alloc]init];
        [dog setID:10];
        [dog setDelegate:xiaoLi];
        [xiaoLi setDog:dog];
        
        while (1) {
            [[NSRunLoop currentRunLoop]run];
        }
        
    }
    return 0;
}

