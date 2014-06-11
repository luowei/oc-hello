//
//  Foo.m
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import "Foo.h"

@interface Foo()

//通过匿名的Category声明私有方法test2
-(void)test2;

@end

@implementation Foo

-(void)test{
    [self test2];
}

-(void)test2{
    NSLog(@" test2 is called !");
}

@end
