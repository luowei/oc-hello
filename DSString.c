//
//  DSString.c
//  HelloWorld
//
//  Created by luowei on 14-10-27.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>

/*
 算法的基本思想:从主串s的第pos个字符起和模式的第一个字符比较，若相等，则继续逐个比较后续字符；
 否则从主串的下一个字符起再重新和模式的字符比较。
 依次类推，直至模式t中的每个字符依次和主串s中的一个连续的字符序列相等，则匹配成功，函数值为和
 模式t中的第一个字符相等的字符在主串要中的序号，否则称匹配不成功，函数值为零。
 */

//带回溯返回子串t在主串s中第pos个字符之后的位置；若不存在，则函数值为0.
int findIndex(char* s,char* t,int pos){
    int argErr = 1;
    if(s!=NULL &&t!=NULL && 0 <= pos <= strlen(s)-1){
        argErr = 0;
    }
    if(argErr){
        return 0;
    }
    
    int i = pos;
    int j = 0;
    while (*(s+i)!='\0' && *(t+j)!='\0') {
        if(*(s+i) == *(t+j)){
            ++i;
            ++j;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if (*(t+j)=='\0') {
        return i-j;
    }else return 0;
}

//指针i回溯法匹配
int BFMatch(char *s,char *p)
{
    int i,j;
    i=0;
    while(i<strlen(s))
    {
        j=0;
        while(s[i]==p[j]&&j<strlen(p))
        {
            i++;
            j++;
        }
        if(j==strlen(p))
            return i-strlen(p);
        i=i-j+1;                //指针i回溯
    }
    return -1;
}



//KMP
//参考:http://www.cnblogs.com/dolphin0520/archive/2011/08/24/2151846.html

//设置模式串中的每个位的的next[]值，
//每个位置的模式值为模式串中戴上到每个对应位置处的模式的子串，其后缀与前缀相同且最长时的长度
/*
 如：模式串:ABCDABD 

 "ABCDAB"的前缀为[A, AB, ABC, ABCD, ABCDA]，后缀为[BCDAB, CDAB, DAB, AB, B]，共有元素为"AB"，长度为2；
 */
void getNext(char *p,int *next)
{
    int j,k;
    next[0]=-1;
    j=0;
    k=-1;
    while(j<strlen(p)-1)
    {
        if(k==-1||p[j]==p[k])    //匹配的情况下,p[j]==p[k]
        {
            j++;
            k++;
            next[j]=k;
        }
        else                   //p[j]!=p[k]
            k=next[k];
    }
}

//KMP字符串模式匹配
int KMPMatch(char *s,char *p)
{
    int next[100];
    int i,j;
    i=0;
    j=0;
    getNext(p,next);
    while(i<strlen(s))
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];       //消除了指针i的回溯
        }
        if(j==strlen(p))
            return i-strlen(p);
    }
    return -1;
}

