//
//  MyProtocol.h
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MyProtocol <NSObject>

@optional //可选的
-(void)print:(int)value;

@required //必须要实现的
-(void)printValue:(int)value1 andValue:(int)value2;

@end
