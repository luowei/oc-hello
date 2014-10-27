//
//  IntvQuestion.c
//  HelloWorld
//
//  Created by luowei on 14-10-26.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


/*
 1.判断单链表是否有环，要求空间尽量少?
 如何找出环的连接点在哪里？
 如何知道环的长度？
 
 分析:
 1.判断是否有环。使用两个指针。一个每次前进1，另一个每次前进2，且都从链表第一个元素开始。显然，如果有环，两个指针必然会相遇。
 
 2.环的长度。记下第一次的相遇点，这个指针再次从相遇点出发，直到第二次相遇。此时，步长为1的指针所走的步数恰好就是环的长度。
 
 3.环的链接点。记下第一次的相遇点，使一个指针指向这个相遇点，另一个指针指向链表第一个元素。然后，两个指针同步前进，且步长都为1。当两个指针相遇时所指的点就是环的连接点。
 
 */

//原文地址：http://blog.csdn.net/sj13051180/article/details/6754228

// head 头文件中已定义
//struct Node
//{
//    int data;
//    struct Node* next;
////    Node( int value ): data(value), next(NULL) {};
//} Node;


//判断单链表是否有环
bool IsCircle( Node *pHead )
{
    //空指针 或 只有一个元素且next为空时，必无环
    if( pHead == NULL || pHead->next == NULL ) return false;
    
    Node *pSlow = pHead;
    Node *pFast = pHead;
    
    while( ( pFast != NULL ) && ( pFast->next != NULL )  )
    {
        //分别按步长1、2前进
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        
        if( pSlow == pFast ) break;
    }
    if( ( pFast == NULL ) || ( pFast->next == NULL ) )
        return false;
    else
        return true;
}

//求环的长度
int GetLen( Node *pHead )
{
    if( pHead == NULL || pHead->next == NULL ) return false;
    
    Node *pSlow = pHead;
    Node *pFast = pHead;
    
    //求相遇点
    while( ( pFast != NULL ) && ( pFast->next != NULL )  )
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        
        if( pSlow == pFast ) break;
    }
    
    //计算长度
    int cnt = 0;
    while( ( pFast != NULL ) && ( pFast->next != NULL )  )
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        cnt++;
        
        //再次相遇时，累计的步数就是环的长度
        if( pSlow == pFast ) break;
    }
    return cnt;
}
//求环的入口点
Node* GetEntrance( Node* pHead )
{
    if( pHead == NULL || pHead->next == NULL ) return false;
    
    Node *pSlow = pHead;
    Node *pFast = pHead;
    
    //求相遇点
    while( ( pFast != NULL ) && ( pFast->next != NULL )  )
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        
        if( pSlow == pFast ) break;
    }
    
    pSlow = pHead;
    while( pSlow != pFast )
    {
        //同步前进
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    return pSlow;  
}


/*
 用非递归的方式合并两个有序链表
 分析：就是把一个链表上的所有结点插入到另一个链表中
 */

//两个有序链表的合并
Node* merge( Node* pHeadA, Node* pHeadB )
{
    //处理空指针
    if( pHeadA == NULL || pHeadB == NULL )
    {
        return ( pHeadA == NULL ) ? pHeadB : pHeadA;
    }
    
    //处理第一个节点
    Node *px, *py;
    if( pHeadA->data <= pHeadB->data )
    {
        px = pHeadA;    py = pHeadB;
    }
    else
    {
        px = pHeadB;    py = pHeadA;
    }
    Node *pResult = px;
    
    //将py上的节点按顺序插入到px
    Node *pre = px;
    px = px->next;
    while( py != NULL && px != NULL )
    {
        //在px上找到py应该插入的位置
        while( py != NULL && px != NULL && py->data > px->data )
        {
            py = py->next;
            px = px->next;
            pre = pre->next;
        }
        //py插入到pre和px之间
        if( py != NULL && px != NULL )
        {
            //py指针前移
            Node* tmp = py;
            py = py->next;
            
            //pre指针前移
            Node* tmpPre = pre;
            pre = pre->next;
            
            //插入
            tmp->next = px;
            tmpPre->next = tmp;
            
            //px指针前移
            px = px->next;
        }
        else
            break;
    }
    if( px == NULL ) pre->next = py;
    
    return pResult;  
}


/*
 把十进制数(long型)分别以二进制和十六进制形式输出，不能使用printf系列
 */

void LongFormat( long value )
{
    //处理符号位
    long mask = 0x1 << ( 8 * sizeof(long) - 1 );
    if( value & mask ) printf("1");
    else printf("0");
    //转换为二进制
    mask = 0x1 << ( 8 * sizeof(long) - 2 );
    for( int i=1; i<8*sizeof(long); i++ )
    {
        if( value & mask ) printf("1");
        else printf("0");
        mask >>= 1;
    }
    printf("\n");
    
    //处理符号位
    printf("0x");
    mask = 0xF << ( 8 * sizeof(long) - 4 );
    long tmp = ( value & mask ) >> ( 8 * sizeof(long) - 4 );
    if( tmp < 10 )
        printf(tmp);
    else
        printf( (char)( 'a' + ( tmp - 10 ) ));
    //转换为十六进制
    mask = 0xF << ( 8 * sizeof(long) - 8 );
    for( int i=1; i<2*sizeof(long); i++ )
    {
        tmp = ( value & mask ) >> ( 8 * sizeof(long) - 4 * i - 4 );
        if( tmp < 10 )
            printf(tmp);
        else
            printf( (char)( 'a' + ( tmp - 10 ) ));
        
        mask >>= 4;
    }
}


/*
 找出两个字符串中最大公共子字符串,如"abccade","dgcadde"的最大子串为"cad"
 */

void GetSubStr( char *strA, char *strB, char *ans )
{
    int max = 0;
    char *pAns = NULL;
    
    //遍历字符串A
    for( int i=0; *(strA+i) != '\0'; i++ )
    {
        //保存strB的首地址，每次都从strB的第一个元素开始比较
        char *pb = strB;
        while( *pb != '\0' )
        {
            //保存strA的首地址
            char *pa = strA + i;
            int cnt = 0;
            char *pBegin = pb;
            
            //如果找到一个相等的元素
            if( *pb == *pa )
            {
                while( *pb == *pa && *pb != '\0' )
                {
                    pa++;
                    pb++;
                    cnt++;
                }
                if( cnt > max )
                {
                    max = cnt;
                    pAns = pBegin;
                }
                if( *pb == '\0' ) break;
            }
            else
                pb++;
        }
    }
    //返回结果
    memcpy( ans, pAns, max );
    *(ans+max) = '\0';
}


//如果成功删除返回真。否则，返回假。
bool DeleteValue(DbNode *pHead, int target )
{
    if( pHead == NULL ) return false;
    
    //至少有两个元素
    bool flag = false;
    DbNode* ph = pHead;
    while( ph->next != pHead  )
    {
        DbNode *pPre = ph->front;
        DbNode *pNext = ph->next;
        
        if( ph->data == target )
        {
            //如果删除的是第一个元素
            if( ph == pHead ) pHead = ph->next;
            
            pPre->next = pNext;
            pNext->front = pPre;
            
            DbNode *tmp = ph;
            free(tmp);
            
            //设置删除标记
            flag = true;
        }
        ph = pNext;
    }
    //只有一个元素或最后一个元素
    if( ph->next == pHead )
    {
        if( ph->data == target )
        {
            //如果要删除的是最后一个元素
            if( ph->front != ph )
            {
                DbNode *pPre = ph->front;
                DbNode *pNext = ph->next;
                pPre->next = pNext;
                pNext->front = pPre;
                
                DbNode *tmp = ph;
                free(tmp);
            }
            else
            {
                free(pHead);
                pHead = NULL;
            }
            flag = true;
        }
    }
    return flag;
}


void DeleteSame( DbNode *pHeadA, DbNode *pHeadB )
{
    if( pHeadA != NULL && pHeadB != NULL )
    {
        DbNode *pa = pHeadA;
        while( pa->next != pHeadA )
        {
            //如果B中含有pa->data，并且已经删除
            if( DeleteValue( pHeadB, pa->data ) )
            {
                //在A中删除pa->data
                DbNode *tmp = pa->next;
                DeleteValue( pHeadA, pa->data );
                pa = tmp;
            }
            else
                pa = pa->next;
        }
        //只有一个元素或最后一个元素
        if( DeleteValue( pHeadB, pa->data ) )
        {
            DeleteValue( pHeadA, pa->data );
        }         
    }  
}

/*
 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 
 例如：如果输入如下矩阵：
 
 1              2              3              4
 
 5              6              7              8
 
 9              10             11             12
 
 13             14             15             16
 
 则依次打印出数字:1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10。
 */

const int MAX_ROW = 100;
const int MAX_COL = 100;

void PrintMatrix( int data[][MAX_COL], int row, int col )
{
    int top = 0;
    int bottom = row-1;
    int left = 0;
    int right = col-1;
    
    int cnt = 0;
    int total = row * col;
    while( cnt < total )
    {
        //从左到右，打印最上面一行
        int j;
        for( j=left; j<=right && cnt<total; j++ )
        {
            printf("%d ",data[top][j]);
            cnt++;
        }
        top++;
        
        //从上到下，打印最右面一列
        for( j=top; j<=bottom && cnt<total; j++ )
        {
            printf("%d ",data[j][right]);
            cnt++;
        }
        right--;
        
        //从右到左，打印最下面一行
        for( j=right; j>=left && cnt<total; j-- )
        {
            printf("%d ",data[bottom][j]);
            cnt++;
        }
        bottom--;
        
        //从下到上，打印最左边一列
        for( j=bottom; j>=top && cnt<total; j-- )
        {
            printf("%d ",data[j][left]);
            cnt++;
        }
        left++;
    }
}


/*
 用1、2、3、4、5、6这六个数字，写一个main函数，打印出所有不同的排列;
 如：512234、412345等，要求："4"不能在第三位，"3"与"5"不能相连.
 */

bool IsValid( char *str )
{
    for( int i=1; *(str+i) != '\0'; i++ )
    {
        if( i == 2 && *(str+i) == '4' ) return false;
        
        if( (*(str+i) == '3' && *(str+i-1) == '5') || (*(str+i) == '5' && *(str+i-1) == '3') )
            return false;
    }
    return true;
}

void PrintStr( char *str, char *start )
{
    if( str == NULL ) return;
    
    if( *start == '\0' )
    {
        if( IsValid( str ) ) printf("%s \n",str);
    }
    
    for( char *ptmp = start; *ptmp != '\0'; ptmp++ )
    {
        char tmp = *start;
        *start = *ptmp;
        *ptmp = tmp;
        
        PrintStr( str, start+1 );
        
        tmp = *start;
        *start = *ptmp;
        *ptmp = tmp;
    }  
}

/*
 题目：输入一个字符串，输出该字符串中对称的子字符串的最大长度。
 比如输入字符串“google”，由于该字符串里最长的对称子字符串是“goog”，因此输出。
 
 思路
 方法一：判断字符串的每一个子串，若是对称的，则求出它的长度即可。这种办法对每一个子串，从两头向中间判断是不是子串。总的时间复杂度为O(n^3),
 下面给出时间复杂度是O(n^2)的思路。
 方法二：与方法一正好相反，字符串中的每一个开始，向两边扩展，此时可分为两种情况：
 （1）对称子串长度是奇数时， 以当前字符为对称轴向两边扩展比较
 （2）对称子串长度是偶数时，以当前字符和它右边的字符为对称轴向两边扩展
 */

//为了更清楚，先给出判断一个字符串是否是对称的小算法：
int isSymString(char str[])
{
    if (! str)
        return 0;
    char *start, *end;
    start = str;
    end = str + strlen(str) - 1;
    for (; start < end; ++start, --end)
        if (*start != *end) // Unsymmetrical
            return 0;
    return 1;               // symmetrical
}

//下面是正式的求字符串中对称子串的长度:
int maxSymSubstring(char str[])
{
    char *fromStart2End, *left, *right;
    int length = 1, newlength;
    
    for (fromStart2End = str; *fromStart2End; fromStart2End++)
    {
        newlength = 1;            //对称子串可能为奇数时
        left = fromStart2End - 1;
        right = fromStart2End + 1;
        for (; left >= str && right <= str + strlen(str) - 1; --left, ++right)
            if (*left == *right)    newlength += 2;
            else    break;
        if (newlength > length)
            length = newlength;
        
        newlength = 0;           //对称子串可能为偶数时
        left = fromStart2End;
        right = fromStart2End + 1;
        for (; left >= str && right <= str + strlen(str) - 1; --left, ++right)
            if (*left == *right)    newlength += 2;
            else    break;
        if (newlength > length)
            length = newlength;
    }// for
    return length;
}

/*
 逆序输出链表：输入一个链表的头结点，从尾到头反过来输出每个结点的值
 */

void PrintReverse( LinkedList* pHead )
{
    LinkedList* ph = pHead;
    if( ph != NULL )
    {
        //->运算符优先级高于单目运算符
        PrintReverse( &(*ph)->next);
        printf("%d ",(*ph)->data);
    }
}






