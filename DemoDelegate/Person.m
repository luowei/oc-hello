//
//  Person.m
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import "Person.h"

@implementation Person
//@synthesize dog = _dog;

//-(void)setDog:(Dog *)dog{
//    if(_dog!=dog){
////        [_dog release];
////        _dog = [dog retain];
//        //通知_dog的主人是self
//        [_dog setDelegate:self];
//    }
//}
//
//-(Dog *)dog{
//    return _dog;
//}

-(void)bark:(Dog *)thisDog count:(int)count{
    //当狗叫的时候来调用 xiaoLi人的这个方法
    NSLog(@"person this dog %d bark %d",[thisDog ID],count);
}

-(void)dealloc{
    self.dog = nil;
}
@end
