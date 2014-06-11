//
//  Person.h
//  HelloWorld
//
//  Created by luowei on 14-6-11.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Dog.h"

@interface Person : NSObject<DogBark>{
//    Dog *_dog;
}

//@property(retain) Dog *dog;
@property Dog *dog;

@end
