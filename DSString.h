//
//  DSString.h
//  HelloWorld
//
//  Created by luowei on 14-10-27.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#ifndef HelloWorld_DSString_h
#define HelloWorld_DSString_h


//返回子串t在主串s中第pos个字符之后的位置；若不存在，则函数值为0.
int findIndex(char* s,char* t,int pos);

//KMP字符串模式匹配
int KMPMatch(char *s,char *p);

//指针i回溯法匹配
int BFMatch(char *s,char *p);


#endif
