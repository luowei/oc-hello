//
//  List.c
//  HelloWorld
//
//  Created by luowei on 14-10-23.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


/////////////////////  链表的基本操作  ///////////////////////

////链表的操作，以有头节点为例，无头节点类似
//Node* head = NULL;

//创建链表，头结点data=0，next=NULL;因为要改变传入参数的地址值,所以要传入LinkedList*指针地址值
bool createNodeList(LinkedList* head)
{
    (*head) = (Node*) malloc(sizeof(Node));
    if(NULL == (*head))
    {
        return false;
    }
    else
    {
        (*head)->data = 0;
         (*head)->next = NULL;
        return true;
    }
}

//增加节点；因为不要改变传入参数的内存地址值，所以直接传入LinkedList即可
bool addNode(LinkedList head,Node* node)
{
    if(NULL == head)
    {
        return false;
    }
    Node* p = head->next;
    Node* q = head;
    while(NULL != p)
    {
        q = p;
        p = p->next;
    }
    q->next = node;
    node->next = NULL;
    return true;
}

//删除节点
bool deleteNode(LinkedList* head,int index)
{
    if(NULL == (*head))
    {
        return false;
    }
    Node* p = (*head)->next;
    
    int length = 0;
    while(NULL != p)
    {
        length ++;
        p = p->next;
    }
    
    if(length < index)
    {
        return false;
    }
    else
    {
        Node* q = (*head);
        p = (*head);
        for(int i=0;i<index;i++)
        {
            q = p;
            p = p->next;
        }
        Node* t = p->next;
        q->next = t;
        free(p);
        return true;
    }
}

//逆序
void reverseNodeList(LinkedList* head)
{
    if(NULL == (*head))
    {
        return;
    }
    //如果链表长度为1
    if((*head)->next == NULL)
    {
        return;
    }
    Node* p = (*head)->next;
    Node* q = p->next;
    Node* t = NULL;
    while(NULL != q)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }
    (*head)->next->next = NULL;
    (*head)->next = p;
}

//排序(降序)
void sort(LinkedList* head)
{
    //冒泡排序
    Node* pHead = (*head);
    if((*head) == NULL)
    {
        return;
    }
    if(pHead->next == NULL)
    {
        return;
    }
    Node* pi = pHead->next;
    Node* pj = pi->next;
    for(;pi != NULL;pi=pi->next)
    {
        for(pj = pi->next;pj != NULL;pj=pj->next)
        {
            if(pj->data > pi->data)
            {
                int tmp = pj->data;
                pj->data = pi->data;
                pi->data = tmp;
            }
        }
    }
}
//销毁
void destroyNodeList(LinkedList* head)
{
    if(NULL == (*head))
    {
        return;
    }
    if(NULL == (*head)->next)
    {
        free((*head));
        (*head) = NULL;
        return;
    }
    Node* p = (*head)->next;
    while(NULL != p)
    {
        Node* tmp = p;
        p = p->next;
        free(tmp);
    }
    free(*head);
    head = NULL;
}

/*
void main()
{
    createNodeList();
    
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    node1->next = NULL;
    
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    node2->next = NULL;
    
    addNode(node1);
    addNode(node2);
    
    reverseNodeList();
    
    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 3;
    node3->next = NULL;
    
    addNode(node3);
    
    sort();
    
    deleteNode(2);
    
    destroyNodeList();
}
 */


/////////////反转单链表////////////

//1.第一种方法就是重新建立一个单链表newList，每次将list中的第一个结点放到newList后面;

LinkedList reverseSinglyLinkedList(LinkedList list)
{
    LinkedList  newList;    //新链表的头结点
    Node       *tmp;       //指向list的第一个结点，也就是要摘除的结点
    
    //
    //参数为空或者内存分配失败则返回NULL
    //
    if (list == NULL || (newList = (LinkedList)malloc(sizeof(Node))) == NULL)
    {
        return NULL;
    }
    
    //
    //初始化newList
    //
    newList->data = list->data;
    newList->next = NULL;
    
    //
    //依次将list的第一个结点放到newList的第一个结点位置
    //
    while (list->next != NULL)
    {
        tmp = newList->next;         //保存newList中的后续结点
        newList->next = list->next;       //将list的第一个结点放到newList中
        list->next = list->next->next;     //从list中摘除这个结点
        newList->next->next = tmp;        //恢复newList中后续结点的指针
    }
    
    //
    //原头结点应该释放掉，并返回新头结点的指针
    //
    free(list);
    return newList;
}


//2.第二种方法是每次都将原第一个结点之后的那个结点放在list后面;
//为了反转这个单链表，我们先让头结点的next域指向结点2，再让结点1的next域指向结点3，最后将结点2的next域指向结点1，就完成了第一次交换，顺序就变成了Header-结点2-结点1-结点3-结点4-NULL，然后进行相同的交换将结点3移动到结点2的前面，然后再将结点4移动到结点3的前面就完成了反转;

LinkedList reverseSinglyLinkedList2(LinkedList list)
{
    Node   *tmp = NULL;
    Node   *p = NULL;
    
    if (list == NULL)
    {
        return NULL;
    }
    tmp = list->next;
    while (tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = list->next;
        list->next = p;
    }
    return list;
}


//取得链表的长度，并把链表的长度存储到头结点
int getLen(LinkedList list)
{
    Node* p=list->next;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    list->data = len;
    
    return list->data;
}

