//
//  IntvQuestion2.c
//  HelloWorld
//
//  Created by luowei on 14-10-27.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Header.h"


/*
 题目：个房间里放着随机数量的金币。每个房间只能进入一次，并只能在一个房间中拿金币。一个人采取如下策略：前四个房间只看不拿。随后的房间只要看到比前四个房间都多的金币数，就拿。否则就拿最后一个房间的金币。编程计算这种策略拿到最多金币的概率。
 */


const int MAX_COIN = 100;
const int MIN_COIN = 1;

//初始化随机数种子
void initRandom()
{
    srand( (int)time( NULL ) );
}

//为每个房间产生随机数量的金币
int gegenrateGoldCoin( int *goldCoin, int size )
{
    int max = 0;
    for( int i=0; i<size; i++ )
    {
        goldCoin[i] = ( rand()%( MAX_COIN - MIN_COIN + 1) ) + MIN_COIN;
        if( goldCoin[i] > max )  max = goldCoin[i];
    }
    //范围最多的金币数
    return max;
}

//按照给定的策略从房间中拿金币
int takeCoin( int *goldCoin, int size )
{
    int firstFour[4];
    int maxInFirstFour = 0;
    for( int i=0; i<4; i++ )
    {
        firstFour[i] = goldCoin[i];
        if( goldCoin[i] > maxInFirstFour ) maxInFirstFour = goldCoin[i];
    }
    
    for( int i=4; i<size; i++ )
    {
        //如果比前四个房间的金币都多，则拿
        if( goldCoin[i] > maxInFirstFour ) return goldCoin[i];
    }
    
    //拿最后一个房间的金币
    return goldCoin[size-1];
}


/*
 字符串原地压缩
 题目描述：“eeeeeaaaff" 压缩为 "e5a3f2"
 */
//字符串的原地压缩，即行程编码、游程编码
void StrCompress( char *original, char *cmpr )
{
    if( original == NULL )
    {
        cmpr = NULL;
        return;
    }
    
    int cnt = 0;
    int i,j;
    for( i=0, j=0; *(original+j) != '\0';  )
    {
        //统计相同字符的个数
        while( *( original + i ) == *( original + j ) )
        {
            cnt++;
            j++;
        }
        
        //复制字符
        *cmpr++ = *( original + i );
        
        //复制字符个数
        char* strCnt;
        char* cntS;
        //把int转成char*,()
//        itoa(cnt,cnts,10);
        
        sprintf(cntS, "%d",cnt);
        strcpy(strCnt, 	cntS);
        
        const char *pcstr = strCnt;
        while( *pcstr != '\0' ) *cmpr++ = *pcstr++;
        
        cnt = 0;
        i = j;
    }
    
    *cmpr++ = '\0';
}


/*
 取值为[1，n-1] 含n 个元素的整数数组至少存在一个重复数，O(n) 时间内找出其中任意一个重复数。
 可以使用类似单链表求环的方法解决这个问题。把数组想想成一个链表，这里用数组元素的值作为下一个元素在数组中的索引。
 
 设数组A共有n个元素，即A={ a0, a1, a2, …, an-1 }。
 
 首先给出下标n-1，则第一个元素为A[n-1]，然后用A[n-1]-1作为下标，可以到达元素A[A[n-1]-1]，再以A[A[n-1]-1]为下标，可以得到元素A[A[A[n-1]-1]]…可以看到这里并没用直接用元素值作索引，而是用元素值减1，这样做是为了避免陷入死循环。
 
 如果A[i]=A[j]=x，即x在数组中出现了两次。则A[i]--->A[x]--->…---> A[j]---> A[x]，因此链表边形成了环。
 
 一旦链表产生后，问题就简单多了。因为重复出现得到元素恰好是环的入口点。于是，问题就相当于单链表求环的入口点。用指针追过的办法，指针x每次步长为2，指针y每次步长为1。直到x、y相遇，然后重置x，使x重新开始。这次同步移动x、y，每次步长都为1，当x、y再次相遇时，恰好是环的入口点。
 */

//在O(n)的时间内，找出任意重复的一个数
int FindRepeat( int *data, int size )
{
    int x = size;
    int y = size;
    
    //找到相遇点
    do{
        x = data[data[x-1]-1];
        y = data[y-1];
    }while( x != y );
    
    //找到重复的元素
    x = size;
    do{
        x = data[x-1];
        y = data[y-1];
    }while( x != y );
    
    return x;
}


