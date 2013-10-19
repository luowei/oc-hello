//
//  main.m
//  HelloWorld
//
//  Created by luowei on 13-10-17.
//  Copyright (c) 2013年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Circle.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        // insert code here...
        NSLog(@"Hello, World!");

        Circle *c = [[Circle alloc] init];
        [c setR:3 andX:4 andy:5];
        [c print];
        NSLog(@"allSum : %d",[Circle allNum]);

        
    }
    return 0;
}

