//
//  Dog.h
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>

//声明协议
@protocol DogBark;

@interface Dog : NSObject{
    NSTimer *timer;
    int barkCount;
    
//    int _ID;
//    
//    //ownner，dog的主人
//    id<DogBark> _delegate;
}

@property int ID;
@property id<DogBark> delegate;

@end

//定义一个人和狗通讯的协议
@protocol DogBark <NSObject>
@required
-(void)bark:(Dog *)thisDog count:(int)count;

@end
