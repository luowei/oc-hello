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


typedef struct Node
{
    int     data;
    struct Node    *next;
}Node, *LinkedList;

//创建链表，头结点data=0，next=NULL
bool createNodeList(LinkedList head);
//增加节点
bool addNode(LinkedList head,Node* node);
//删除节点
bool deleteNode(LinkedList,int index);
//逆序
void reverseNodeList(LinkedList);
//排序(降序)
void sort(LinkedList);
//销毁
void destroyNodeList(LinkedList);


//另外两种逆序方法
LinkedList reverseSinglyLinkedList(LinkedList list);
LinkedList reverseSinglyLinkedList2(LinkedList list);

#endif





