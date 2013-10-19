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

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        // insert code here...
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


    }
    return 0;
}

