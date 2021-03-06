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

//从正整数序列Q中的每个元素都至少能被正整数a和b中的一个整除的前N项
void Generate( int a,int b,int N ,int * Q );

//把由大小写组成的字符串的所有小写字母排在大写字母的前面
void Proc( char *str );

//判断一个自然数是否是某个数的平方
int IsSquare(int x,int* result);

//给定能随机生成整数1到5的函数，写出能随机生成整数1到7的函数
int rand7();

//n! 末尾有多少个0
int zeroCount(int n);

//找出用A中的元素组成一个大于K的最小正整数
int NearestInt( int target, int *data, int size );
//用指针的方法，对A数组进行排序
void arrSort(int* a, int n);

//拷贝src所指的内存内容前n个字节到dest所指的地址上
void* Memmove( void *dest, const void *src, size_t n );

//求一个整数数组中两两之差绝对值最小的值
//1.自然穷举
int countSort(int arr[]);

//2.基于搜索和排序的解法
void count_sort(int *arr, int len, int *buf, int bfsz);
void base_sort(int *arr, int len, int n);

//写一个函数，检查字符是否是整数，如果是，返回其整数值。
bool StrToInt( char *pc, long* value );
long strtoint(char *str,int length);

//给出一个函数来输出一个字符串的所有排列
void Exchange( char *px, char *py );
void PrintStrPermut( char *pstr, char *pbegin );
void strSort(char* str);
void PrintStrPermut2( char *pstr );

//实现两个正整数的除法，
int Div( const int x, const int y );

//在排序数组中，找出给定数字的出现次数
int GetCount( int *pi, int left, int right, int target );

//获得指针的数据长度
int getPointLen(void* p,int pSize);

//从点集成获得最大斜率
double getMaxKSlope(int* x,int* y);


#endif





