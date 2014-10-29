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
#include <assert.h>
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

/*
 正整数序列Q中的每个元素都至少能被正整数a和b中的一个整除，现给定a和b，需要计算出Q中的前几项，
 例如，当a=3，b=5，N=6时，序列为3，5，6，9，10，12
 
设计一个函数void generate（int a,int b,int N ,int * Q）计算Q的前几项
 
 */
//从正整数序列Q中的每个元素都至少能被正整数a和b中的一个整除的前N项
void Generate( int a,int b,int N ,int * Q )
{
    int tmpA, tmpB;
    int i = 1;
    int j = 1;
    
    for( int k=0; k<N; k++ )
    {
        tmpA = a * i;
        tmpB = b * j;
        
        if( tmpA <= tmpB )
        {
            Q[k] = tmpA;
            i++;
        }
        else
        {
            Q[k] = tmpB;
            j++;
        }
    }
}

/*
 有一个由大小写组成的字符串，现在需要对他进行修改，将其中的所有小写字母排在大写字母的前面.
 思路:字符串在调整的过程中可以分成两个部分,已排好的小写字母部分、待调整的剩余部分。用两个指针i和j，其中i指向待调整的剩余部分的第一个元素，用j指针遍历待调整的部分。当j指向一个小写字母时，交换i和j所指的元素。向前移动i、j，直到字符串末尾。
 
 */

//把由大小写组成的字符串的所有小写字母排在大写字母的前面
void Proc( char *str )
{
    int i = 0;
    int j = 0;
    
    //移动指针i, 使其指向第一个大写字母
    while( str[i] != '\0' && str[i] >= 'a' && str[i] <= 'z' ) i++;
    
    if( str[i] != '\0' )
    {
        //指针j遍历未处理的部分，找到第一个小写字母
        for( j=i; str[j] != '\0'; j++ )
        {
            if( str[j] >= 'a' && str[j] <= 'z' )
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
                i++;
            }
        }
    }
}

/*
 判断一个自然数是否是某个数的平方。说明：不能使用开方运算
 
 也就是判断一个自然数是否是完全平方数。
 方法一：从1开始逐个尝试，即判断1*1，2*2，3*3…,算法复杂度O( N^0.5 )
 方法二：相当于在1…N之间找一个数x，使x*x = N。这样看就是一个查找问题，所以用折半查找。算法复杂度O( logN )。
 方法三：使用完全平方数的性质：每个完全平方数都可以表示成一系列奇数的和。
 
 不妨这样简单理解一下：
 设x是一个完全平方数，即 x = a^2，所以
 a^2 = ( a – 1 +1 )^2 = (a-1)^2 + 2( a – 1 ) + 1
    =( (a-2) + 1 )^2 + 2( a – 1 ) + 1
    =(a-2)^2 + ( 2( a – 2 ) + 1 ) + (2( a – 1 ) + 1 )
 即 x = 1 + 3 + 5 + … + (2( a – 1 ) + 1 )
 
 故x可以表示为一系列奇数的和.
 因此判断完全平方数的算法：x – 1 – 3 – 5…即从x中连续不断的减去一个奇数，如果结果可以为0，则x是完全平方数。否则，不是。算法复杂度O(N )，当然由于这里做的全部是减法，可能也回比较快。
 */

//判断一个自然数是否是某个数的平方
int IsSquare(int x,int* result)
{
    int i=1;
    int sum=0;
    for(;sum<x;i+=2){
        sum+=i;
    }
    if (x==sum) {
        *result = (i-1)/2;
        return 1;
    }
    return 0;
}

/*
 给定能随机生成整数1到5的函数，写出能随机生成整数1到7的函数
 
 1. 通过 rand5()*5+rand5() 产生 6 7 8 9 10 11 …… 26，27 28 29 30 这25个数，每个数的出现机率相等
 2. 只需要前面 3*7 个数，所以舍弃后面的4个数(也就说当为后面4个数时,重新计算)
 3. 将 6 7 8 转化为 1，9 10 11 转化为 2，……，24 25 26 转化为 7。公式是 (a-3)/3
 */

int rand5()
{
    return (rand()%5+1);
}

int rand7()
{
    int a;
    while((a=rand5()*5+rand5())>26);
    return (a-3)/3;
}

/*
 1024! 末尾有多少个0
 
 求末尾0个数，也就是对1024！进行因子分解，求因子中10的个数。在进一步，因子中10的个数，就相当与质因子中2*5的个数。因为质因子5的个数比2少，所以也就是求1024！中质因子5的个数。即能产生多余0的个数是和包含因子5的个数相关的。
 
 1，2，3，…，1024中哪些数都含有质因子5？主要有以下几类：
 
 第一类：5的倍数，1024/5 = 204个
 第二类：25的倍数，1024/25 = 40个 (因为25能产生2个包含5的质因子)
 第三类：125的倍数，1024/125 = 8个 (5^3)
 第四类：625的倍数，1024/625 = 1个 (5^4)
 则，总的因子5的个数：204 + 40 + 8 + 1 = 253
 
 总结如下：N的阶乘中末位0的个数为：N/5 + N/25 + N/125 ……
 */

//n! 末尾有多少个0
int zeroCount(int n)
{
    int count = 0;
    while(n > 0) {
        n = n/5;
        count += n;
    }
    return count;
}


/*
  给定一个集合A=[0,1,3,8](该集合中的元素都是在0，9之间的数字，但未必全部包含)， 指定任意一个正整数K，请用A中的元素组成一个大于K的最小正整数。比如，A=[1,0] K=21 那么输出结构应该为100
 
 首先，计算正整数K的位数。假设k有m位。把用A中的元素组成一个大于K的最小正整数记为x。那么x就有m位或者m+1位。
 根据K的最高位，在A中选数字。分两种情况：A中的数字都比k的最高位小、A中至少有一个数字等于大于k的最高位。
 
 1.A中的数字都比k的最高位小，则x有m+1位。这时，只要用A中的数字组成一个m+1位的最小正整数即可。
 2.A中至少有一个数字等于大于k的最高位。这时x的最高位就是不小于K最高位的最小数字。然后，用同样的方法继续比较下一位。
 */
//用指针的方法，对A数组进行排序
void arrSort(int* a, int n)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(*(a+i) > *(a+j))
			{
				t = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = t;
			}
		}
	}
}

//target为int值，最多是10位数
const int MAX_INT_CNT = 20;

int NearestInt( int target, int *data, int size )
{
    int ans = 0;
    
    //计算target的位数
    int cnt = 0;
    int tmp = target;
    while( tmp > 0 )
    {
        cnt++;
        tmp /= 10;
    }
    
    //将target转换为字符串
    char des[MAX_INT_CNT];
    sprintf( des,"%d", target );
    
    //对数组排序
    arrSort( data, *(data+size) );
    
    int flag = 0;
    int i, j;
    for( i=0; i<cnt; i++ )
    {
        ans *= 10;
        //遍历数组，找到一个合适的元素
        for( j=0; j<size && flag==0; j++ )
        {
            if( des[i] == data[j] )
            {
                ans += data[j];
                break;
            }
            if( des[i] < data[j] )
            {
                ans += data[j];
                flag = 1;
                break;
            }
        }
        if( j >= size ) flag = 2;
        //flag == 2表示前面的数字都相等，只要后面的多一位就行
        if( flag == 2 )
        {
            if( i == 0 )
            {
                //找到一个非0元素
                for( j=0; j<size; j++ )
                {
                    if( data[j] > 0 )break;
                }
                ans += data[j];
            }
            else
                ans += data[0];
        }
        //flag == 1表示前面的数字比较大，后面的取最小的数字即可
        if( flag == 1 ) ans += data[0];
    }
    //如果前面的数字都相等
    if( flag == 2 )
    {
        ans *= 10;
        ans += data[0];
    }
    return ans;
}

/*
 拷贝src所指的内存内容前n个字节到dest所指的地址上
 其实就是自己写一个memcpy函数。注意下面三种情况：
 1.指针为空
 2.两个指针间距过小( 如dest = 10010, src =10020, n = 20 )
 3.void*的转换
 */
//拷贝src所指的内存内容前n个字节到dest所指的地址上
void* Memmove( void *dest, const void *src, size_t n )
{
    char *cDest = (char*) dest;
    char *cSrc = (char*) src;
    
    //assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行
    assert( cDest != NULL && cSrc != NULL );
    assert( cDest >= cSrc + n || cSrc >= cDest + n );
    
    while( n-- )    *cDest++ = *cSrc++;
    return dest;
}

/*
 问题：
 有一个整数数组，请求出两两之差绝对值最小的值（记住，只要得出最小值即可，不需要求出是哪两个数）。
 
 想法：
 1.最起码的想法自然就是穷举了，复杂度相当高，两个循环，O(n^2)，其实也不是很高哦。
 2.适当变换一下题目的说法，两两绝对值之差最小，想象一下数轴，绝对值是两者距离，距离之差最小，就是数轴上的数距离最小，那排序就是很自然地想法了，排序之后的搜索过程复杂度为O(n)，也就是说，如果采用搜索法，复杂度下限就是Ω(n)。
 
 接下来是排序算法，根据《算法导论》，基于比较的排序的渐进下限O(nlgn)，目前性能最好最实用的当属快排了，应用快排之后的算法复杂度当为O(nlgn)。
 不基于比较的算法可以把复杂度进一步拉下来，达到O(n)，计数排序要求存储器的支持，数据可能达不到要求；基数排序要提取基数，隐含了大量的除法操作；桶排序要求分散均匀，而均匀分散可以采用散列技术，只要求用一个单调函数即可。
 综上，基于搜索和排序的算法可以把复杂度降到O(n)。
 
 */
//1.自然穷举
int countSort(int arr[]){
    
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int i, j, md = 0xffff, diff;
    for(i = 0; i < len; ++i){
        for(j = i+1; j < len; ++j){
            diff = arr[j] > arr[i] ? arr[j] - arr[i]:arr[i] - arr[j];
            if(diff == 0){
                printf("arr[%d] == arr[%d]\n", i, j);
                continue;
            }
            if(diff < md){
                md = diff;
            }
        }
    }
    return md;
    
}

//2.基于搜索和排序的解法
void count_sort(int *arr, int len, int *buf, int bfsz){       //计数排序
    int i, j;
    for(i = 0; i < bfsz; ++i){
        buf[i] = 0;
    }
    for(i = 0; i < len; ++i){
        ++buf[arr[i]];
    }
    for(i = 1; i < bfsz; ++i){
        buf[i] += buf[i-1];
    }
}
void base_sort(int *arr, int len, int n){             //基数排序
    int buf[10];
    int div = 10, base = 1, i, d;                 //div和base确定一个位阶，位阶是说十位数，百位数，千位数这样的位阶
    int ds[len];                                  //基数集，取值范围0~9，所有数相同位阶的数值，比如1234的十位阶为3，百位阶为2
    int back[len];                                //原数组的备份
    for(d = 0; d < n; ++d){
        for(i = 0; i < len; ++i){                 //备份
            back[i] = arr[i];
        }
        for(i = 0; i < len; ++i){                 //计算位阶
            ds[i] = arr[i]%div;
            ds[i] /= base;
        }
        count_sort(ds, len, buf, 10);             //以位阶值排序
        for(i = len-1; i >= 0; --i){              //调换整个数组的顺序
            arr[--buf[ds[i]]] = back[i];
        }
        div *= 10;
        base *= 10;
    }
}

/*
 写一个函数，检查字符是否是整数，如果是，返回其整数值。（或者：怎样只用4行代码编写出一个从字符串到长整形的函数？）
 
 注意：
 1. 处理前导空格
 2. 处理正负号
 3. 处理进制（16进制、8进制、10进制）
 4. 非法字符（ 0---9, a---f, A---F）
 5. 注意整数的范围，不能溢出
 
 */

bool StrToInt( char *pc, long* value )
{
    //去掉前导空格
    while( ( *pc==' ' || *pc=='\t' ) && *pc != '\0' ) pc++;
    if( *pc == '\0' )   return false;
    
    //处理正负号
    int sign = 1;
    if( *pc == '+' || *pc == '-' )
    {
        if( *(pc+1) =='\0' ) return false;
        if( *pc == '-' ) sign = -1;
        pc++;
    }
    
    //处理数值
    long tmp = 0;
    while( *pc != '\0' )
    {
        tmp *= 10;
        //++优先级比*高
        if( *pc < '0' && *pc > '9' ) return false;
        tmp += ( *pc++ - '0' );
    }
    *value = tmp * sign;
    return true;
}

long strtoint(char *str,int length){
    if(length > 1) {
        return str[0]=='-' ? strtoint(str, length-1)*10-(str[length-1]-'0') : strtoint(str, length-1)*10+str[length-1]-'0';
    } else {
        return str[0]=='-' ? -1/10 : str[0]-'0';
    }
}


/*
 给出一个函数来输出一个字符串的所有排列
 
 方法1：
 一个简单的DFS。从后往前不断交互。N个字母求全排列，O( n! )。具体实现，看代码吧。
 
 方法2：
 如果不会写递归，也可以利用STL。STL里有一个next_permutation函数。利用这个函数可以返回大于原字符串的下一个字典序列。当字符串为最大字典序列时，函数返回false。这样只要先对原字符串排序，然后不断调用next_permuation即可。
 */
void Exchange( char *px, char *py )
{
    char tmp = *px;
    *px = *py;
    *py = tmp;
}

void PrintStrPermut( char *pstr, char *pbegin )
{
    //处理空字符串
    if( pstr == NULL || pbegin == NULL ) return;
    
    //递归终止条件
    if( *pbegin == '\0' )
        printf("%s \n",pstr);
    else
    {
        for( char *p=pbegin; *p!='\0'; p++ )
        {
            Exchange( p, pbegin );
            PrintStrPermut( pstr, pbegin+1 );
            Exchange( p, pbegin );
        }
    }
}

void strSort(char* str){
    char t;
	for (int i = 0; *(str+i)!='\0'; i++)
	{
		for (int j = i+1; *(str+i)!='\0'; j++)
		{
			if(*(str+i) > *(str+j))
			{
				t = *(str+i);
				*(str+i) = *(str+j);
				*(str+j) = t;
			}
		}
	}
}

void PrintStrPermut2( char *pstr )
{
    char *p = pstr;
    while( *p != '\0' ) p++;
    
    strSort( pstr);
    printf("%s \n",pstr);
//    //STL里有一个next_permutation函数
//    while( next_permutation( pstr, p ) )
//    {
//        printf("%s \n",pstr);
//    }
}

/*
 编程实现两个正整数的除法，不能用除法操作符。
 
 a/b=x, 即求a里面有多少个b.
 
 方法一：枚举，b*1，b*2，b*3，…，直到b*x == a 或 b*x < a && b*(x+1) > a，复杂度O( a/b)这样
 方法二：
 除了x = 1+…+1（x个1相加），x还可以用2的幂的和表示（如4 = 2^2, 7 = 2^2+2+1 ）。不用逐一枚举，类似折半查找。不断划分区间，用区间比较。
 不断尝试b*(1<<0)，b*(1<<1)，b*(1<<2)，…，
 直到b*(1<<m) < a && b*(1<<m+1) > a，
 则从a - b*(1<<m)，然后再重新开始。
 
 */

int Div( const int x, const int y )
{
    if( x < y ) return 0;
    
    int tmp = x;
    int ans = 0;
    
    while( tmp >= y )
    {
        int cnt = 1;
        while( ( y * cnt ) <= tmp )  cnt <<= 1;
        
        cnt >>= 1;
        ans += cnt;
        tmp -= y * cnt;
    }
    return ans;
}


/*
 在排序数组中，找出给定数字的出现次数。比如[1, 2, 2, 2, 3] 中的出现次数是次。
 
 方法一：直接遍历，首先找到这个数，然后逐一计数，O(n)可完成。
 方法二：二分查找，首先找到这个数的第一个，记录其位置。再二分查找，找到这个数的最后一个，记录其位置。最后下边相减，O(lgn)可完成。虽然两次都是二分查找，但还是略微有点区别。
 
 LowerSearch把相等的情况划归到左半部分，所以计算mid时要向下取整。
 UpperSearch把相等的情况划归到右半部分，所以计算mid时要向上取整。
 
 */
//target出现的第一个位置
int LowerSearch( int *pi, int left, int right, int target )
{
    while( left < right )
    {
        //mid向下取整
        int mid = ( left + right ) / 2;
        
        if( target <= pi[mid] )
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
//target出现的第最后一个位置
int UpperSearch( int *pi, int left, int right, int target )
{
    while( left < right )
    {
        //这里mid向上取整
        int mid = ( left + right + 1 ) / 2;
        
        if( target >= pi[mid] )
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int GetCount( int *pi, int left, int right, int target )
{
    int first = LowerSearch( pi, left, right, target );
    int second = UpperSearch( pi, left, right, target );
    
    return second-first+1;
}

/*
 平面上N个点，每两个点都确定一条直线，求出斜率最大的那条直线所通过的两个点（斜率不存在的情况不考虑）。时间效率越高越好。
 
 按照一般的方法，逐个求斜率比较，O(n^2)可完成。有没有更快的方法？有。
 
 对所有的点按x坐标排序，然后只比较相邻两点的斜率即可。复杂度O( nlgn )。当然，只要有了算法，编程实现很容易，关键是为什么？
 我不会严格的证明，只能朴素的理解一下。
 
 设有三个点A、B、C
 如果A、B、C在一条直线上，则斜率相等
 如果A、B、C不在一条直线上，则构成三角形ABC。不妨设Xa < Xb < Xc
 即按照x坐标排序后，A、B相邻，B、C相邻。也就是说，三角形中AC为最长边。如图，显然Kab和Kbc中至少有个大于Kac.
 
 */
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void ssort(int x[],int y[],int len)
{
    for( int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                swap(&x[j],&x[j+1]);
                swap(&y[j],&y[j+1]);
            }
        }
    }
}

//获得指针的数据长度
int getPointLen(void* p,int pSize)
{
    if(p==NULL) return 0;
    char* cp = (char*)p;
    
    int i=0;
    for(;*(cp+i*pSize)!=NULL;i++){
        printf("****:%d",*(cp+i*pSize));
    };
    return i;
}

//从点集成获得最大斜率
double getMaxKSlope(int* x,int* y)
{
    int len = getPointLen(x,sizeof(int));
    if(len <2) return 0;
    ssort(x, y, len);
    
//    double a = 0l;
//    double* max=&a;
    double max = 0;
    for(int i = 1;i<len;i++)
    {
//        double n = (y[i]-y[i-1])/(x[i]-x[i-1]);
        double n = (*(y+i)-*(y+i-1))/(*(x+i)-*(x+i-1));
//        (*max) = (*max) > n ? (*max):n;
        max = max > n ? max :n;
    }
    return max;
}
