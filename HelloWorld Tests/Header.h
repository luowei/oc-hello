//
//  Header.h
//  HelloWorld
//
//  Created by luowei on 14-10-23.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

/*
// file : myboolean.h
#ifndef MYBOOLEAN_H
#define MYBOOLEAN_H

#define false 0
#define true 1
typedef int bool; // or #define bool int

#endif
*/
 

#ifndef HelloWorld_Header_h
#define HelloWorld_Header_h

#define __USE_C99_MATH
#include <stdbool.h>

//获得数组的长度
#define dim(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct Node
{
    int     data;
    struct Node    *next;
}Node, *LinkedList;

typedef struct DbNode
{
    int data;
    struct DbNode *front,*next;
} DbNode;

//创建链表，头结点data=0，next=NULL
bool createNodeList(LinkedList* head);
//增加节点
bool addNode(LinkedList head,Node* node);
//删除节点
bool deleteNode(LinkedList*,int index);
//逆序
void reverseNodeList(LinkedList*);
//排序(降序)
void sort(LinkedList*);
//销毁
void destroyNodeList(LinkedList*);


//另外两种逆序方法
LinkedList reverseSinglyLinkedList(LinkedList list);
LinkedList reverseSinglyLinkedList2(LinkedList list);

//取得链表的长度，并把链表的长度存储到头结点
int getLen(LinkedList list);


//字符数组转换成字符指针
char* charArr2Point(char chars[]);

//反转字符串
char* revertString(char* str);
char* revertString2(char* str);

//内存拷贝
void* myMemmove(void *dest, const void *src, int n);

// 十进制转换为二进制，十进制数的每1bit转换为二进制的1位数字
char *int_to_bin(unsigned long data);
// 十进制转换为十六进制，十进制数的每4bit转换为十六进制的1位数字
char *int_to_hex(unsigned long data);

//找出两个字符串中最大公共子字符串,如"abccade","dgcadde"的最大子串为"cad"
void sameStr( char *str1, char const *str2, char const *str3 );
int getCommon(char *s1, char *s2, char **r);



//判断单链表是否有环
bool isCircle( Node *pHead );

//求环的长度
int getLen( Node *pHead );

//求环的入口点
Node* getEntrance( Node* pHead );

//两个有序链表的合并
Node* merge( Node* pHeadA, Node* pHeadB );

//把十进制数(long型)分别以二进制和十六进制形式输出
void longFormat( long value );

//找出两个字符串中最大公共子字符串
void getSubStr( char *strA, char *strB, char *ans );

//如果成功删除返回真。否则，返回假。
bool deleteValue(DbNode *pHead, int target );

//删除两个链表中的相同的字符串
void deleteSame( DbNode *pHeadA, DbNode *pHeadB );

//初始化随机数种子
void initRandom();

//为每个房间产生随机数量的金币
int gegenrateGoldCoin( int *goldCoin, int size );

//按照给定的策略从房间中拿金币
int takeCoin( int *goldCoin, int size );

#endif





