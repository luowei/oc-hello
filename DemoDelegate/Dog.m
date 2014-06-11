//
//  Dog.m
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import "Dog.h"

@implementation Dog
//@synthesize ID = _ID;
//@synthesize delegate = _delegate;

-(id)init{
    self = [super init];
    if(self){
        //创建一个每隔1秒就调用updateTimer的定时器
        timer = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(updateTimer) userInfo:nil repeats:YES];
    }
    return self;	
}


-(void)updateTimer{
    barkCount ++;
    NSLog(@"Dog bark %d",barkCount);
    
    //通知dog的主人
    [_delegate bark:self count:barkCount];
    
}
@end
