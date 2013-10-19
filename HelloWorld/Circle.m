//
// Created by luowei on 13-10-17.
// Copyright (c) 2013 luowei. All rights reserved.
//


#import "Circle.h"

int sum = 5;


@implementation Circle {
}

//@synthesize redius;

- (void)print {

    NSLog(@"redus:%d x:%d y:%d",redius,x,y);
}

- (void)setR:(int)r andX:(int)x1 andy:(int)y2 {
    redius=r;
    x=x1;
    y=y2;

}

+ (int)allNum {
    return sum;
}


@end