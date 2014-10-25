//
//  ListTest.m
//  HelloWorld
//
//  Created by luowei on 14-10-23.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Header.h"


@interface ListTest : XCTestCase

@end

@implementation ListTest

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

-(void)testListOpt{
    
    //链表的操作，以有头节点为例，无头节点类似
    LinkedList head;
    
    createNodeList(&head);
    
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    node1->next = NULL;
    
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    node2->next = NULL;
    
    addNode(head,node1);
    addNode(head,node2);
    
    reverseNodeList(&head);
    
    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 3;
    node3->next = NULL;
    
    addNode(head,node3);
    
    sort(&head);
    
    deleteNode(&head,2);
    
    destroyNodeList(&head);
}


- (void)testListResever
{
    LinkedList head;
    createNodeList(&head);
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    node1->next = NULL;
    
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    node2->next = NULL;
    
    addNode(head,node1);
    addNode(head,node2);
    
    printf("list len:%d",getLen(head));
    
    head = reverseSinglyLinkedList(head);
    
    head = reverseSinglyLinkedList2(head);
}


@end

