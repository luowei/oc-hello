//
//  Dogo.h
//  HelloWorld
//
//  Created by luowei on 14-6-12.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Dogo;


//typedef void (^BarkCallback)(Dogo *thisDogo,int count);


@interface Dogo : NSObject{
    int barkCount;
    NSTimer* timer;
    
    //定义一个blocks变量
//    void (^barkCallback)(Dogo *thisDogo,int count);
}

@property int ID;
@property(readwrite,copy) void (^barkCallback)(Dogo *thisDogo,int count);
//@property(readwrite,copy) BarkCallback barkCallback;

//-(void)setBark :(void (^)(Dogo *thisDogo,int count))eachBark;

@end
