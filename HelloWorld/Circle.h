//
// Created by luowei on 13-10-17.
// Copyright (c) 2013 luowei. All rights reserved.
//


#import <Foundation/Foundation.h>



@interface Circle : NSObject {
    int redius;
    int x;
    int y;
}

//@property (nonatomic) int redius;
//@property (nonatomic) int x,y;


-(void)print;

-(void)setR:(int)r andX:(int)x andy:(int)y;

+(int)allNum;

@end