//
//  Dogo.m
//  HelloWorld
//
//  Created by luowei on 14-6-12.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import "Dogo.h"

@implementation Dogo

//@synthesize barkCallback;

-(id)init{
    self = [super init];
    if(self){
        timer = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(updateTimer:) userInfo:nil repeats:YES];
    }
    return self;
}

//-(void)setBark :(void (^)(Dogo *thisDogo,int count))eachBark{
////    barkCallback = [eachBark copy];
//    barkCallback = eachBark;
//}

-(void)updateTimer:(id)arg{
    barkCount++;
    NSLog(@"~~~~~block demo:dogo %d bark count %d",_ID,barkCount);
    
    //给Human汇报一下，调用Human中的blocks
    if(_barkCallback){
        _barkCallback(self,barkCount);
    }
}
@end
