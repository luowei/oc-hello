//
// Created by luowei on 13-10-17.
// Copyright (c) 2013 luowei. All rights reserved.
//


#import "Circle.h"
#import "XYPoint.h"

int sum = 5;


@implementation Circle {
}

//@synthesize redius;
//@synthesize origin;

- (void)setOrigin:(XYPoint *)pt {
     origin = pt;
}

- (XYPoint *)origin {
    return origin;
}

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