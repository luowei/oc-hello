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

#import "NSString+ReverseString.h"

#import "Human.h"
#import "Dogo.h"

//定义一个返回值为int,名字为sumBlockT，参数为(int a,int b),的blocks类型
typedef int (^SumBlockT) (int a,int b);

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        //----- DemoBase --------
        NSLog(@"\n\n\n-------------DemoBase--------");
        
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
        NSLog(@"\n\n\n-------DemoProtocol--------");
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
        
        //-------DemoCategory--------
        NSLog(@"\n\n\n-------DemoCategory--------");
        NSString* string = @"苹果电脑，iOS应用开发，维唯为为制作！";
        NSString* retString = [string reverseString];
        NSLog(@" ret string is %@",retString);
        
        //-------DemoBlocks--------
        NSLog(@"\n\n\n-------DemoBlocks--------");
        
        NSLog(@"\n\n******blocks 示例1 *******");
        //声明一个返回值void,参数void的blocks变量，变量名为myBlocks，并赋值为NULL
        void (^myBlocks) (void) = NULL;
        //给myBlocks赋值
        myBlocks = ^(void){
            NSLog(@" in blocks ");
        };
        NSLog(@"==before myBlocks==");
        myBlocks();     //执行myBlocks
        NSLog(@"==after myBlocks==");
        
        NSLog(@"\n\n******blocks 示例2 *******");
        int (^myBlocks2) (int a,int b) = ^(int a,int b){
            int c = a + b;
            return c;
        };
        NSLog(@"==before myBlocks2==");
        NSLog(@"myBlocks2(100,200)=%i",myBlocks2(100,200));     //执行myBlocks2
        NSLog(@"==after myBlocks2==");
        
        NSLog(@"\n\n******blocks 示例3 *******");
        __block int sum = 0 ;  //指定sum为__block变量
        int (^myBlocks3) (int a,int b) = ^(int a,int b){
            sum = a + b;
            return sum;
        };
        NSLog(@"sum is %i",myBlocks3(20,30));     //执行myBlocks2
        
        NSLog(@"\n\n******blocks 示例4 *******");
        SumBlockT sumBlocks = ^(int a,int b){
            return a+b;
        };
        NSLog(@"excute sumBlocks:%i",sumBlocks(2,3));
        
        NSLog(@"\n\n******blocks 示例5 *******");
        Human *xiaoming = [[Human alloc]init];
        Dogo *dogo = [[Dogo alloc]init];
        [dogo setID:10];
        [dogo setBarkCallback:^(Dogo* thisDogo, int count) {
            NSLog(@"~~~~~block demo:Human Dogo %d bark %d",[thisDogo ID],count);
        }];
        [xiaoming setDogo:dogo];
        
        
        //-------DemoDelegate--------
        NSLog(@"\n\n\n-------DemoDelegate--------");
        Person *xiaoLi = [[Person alloc]init];
        Dog *dog = [[Dog alloc]init];
        [dog setID:10];
        [dog setDelegate:xiaoLi];
        [xiaoLi setDog:dog];
        
        //----主程序要持续运行，需要加上这段死循环
        while (1) {
            //启动当前主线程RunLoop,当有输入源或Timer消息源时，会让出时间片执行输入或消息任务
            [[NSRunLoop currentRunLoop]run];
        }
        
    }
    return 0;
}

