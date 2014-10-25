//
//  Base.c
//  HelloWorld
//
//  Created by luowei on 14-10-25.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* charArr2Point(char chars[]){
    //为了便于通用,可以把这种求数组的长度定义成宏
    int len = sizeof(chars)/sizeof(chars[0]);
    char* a = malloc(len * sizeof(char));
    
    a = &chars[0];
    
    return a;
    
}

//反转字符串(返回新的字符串,即新地址与新的内存空间)
char* revertString(char* str)
{
    int n = (int)strlen(str);
    char* newStr;// = malloc(n * sizeof(char));
    for(int i=0;i<n;i++){
        (*(newStr+i)) = str[n-1-i];
    }
    return newStr;
}

//反转字符串(改变传入的字符串，返回原地址与内存空间,只是改变内存空间中的值)
char* revertString2(char* str)
{
    int len = (int)strlen(str);
    char c;
    for(int i=0;i<len/2;i++){
        c = *(str+i);
        *(str+i) = *(str+(len-1-i));
        *(str+(len-1-i)) = c;
    }
    return str;
}

//实现函数memmove:拷贝src所指的内存内容前n个字节到dest所指的地址上
//因为要考虑内存地址叠加问题，即dest的地址是在src的哪个位置;
//dest是在src的下面，还是上面，上面的话是 dest>(src+n)，下面dest<(src-n)
void* myMemmove(void *dest, const void *src, int n)
{
    if(dest==NULL || src==NULL){
        return NULL;
    }
    char* p_dest=(char*)dest;
    char* p_src=(char*)src;
    
    //p_dest在p_src上面或相等，或者p_dest在src+n下面时
    if(p_dest <= p_src || p_dest > (p_src+n)){
        while(n--){
            //++ 优先级大于 *
            *p_dest++= *p_src++;
        }
        //*p_dest='\0';  后面如果要舍弃，就加上去
    }
    //如果出现p_dest在p_src在下面，就要会出现覆盖src中还未拷贝的值，让指针从下面向上面方向移动就这样的问题
    else if(p_dest < (p_src+n)){
        p_dest = p_dest+n-1;
        p_src = p_src+n-1;
        while (n--) {
            *p_dest-- = *p_src--;
        }
        //*(p_dest+n)='\0';
    }
    
    return dest;
}


// 十进制转换为二进制，十进制数的每1bit转换为二进制的1位数字
char *int_to_bin(unsigned long data)
{
    int bit_num = sizeof(unsigned long) * 8;
    char *p_bin = (char*) malloc(sizeof(char) * (bit_num+1));
    p_bin[bit_num] = '\0';
    for (unsigned int i = 0; i < bit_num; ++i)
    {
        p_bin[i] = data << i >> (bit_num-1);
        if (p_bin[i] == 0)
            p_bin[i] = '0';
        else if (p_bin[i] == 1)
            p_bin[i] = '1';
        else
            p_bin[i] = 'a';
    }
    return p_bin;
}

// 十进制转换为十六进制，十进制数的每4bit转换为十六进制的1位数字
char *int_to_hex(unsigned long data)
{
    int bit_num = sizeof(unsigned long) * 8;
    char *p_hex = (char*)malloc(sizeof(char) * (sizeof(unsigned long)*8/4+3));
    p_hex[0] = '0';
    p_hex[1] = 'x';
    p_hex[bit_num/4+2] = '\0';
    char *p_tmp = p_hex + 2;
    for (unsigned int i = 0; i < bit_num/4; ++i)
    {
        p_tmp[i] = data << (4*i) >> (bit_num-4);
        if (p_tmp[i] >= 0 && p_tmp[i] <= 9)
            p_tmp[i] += '0';
        else if (p_tmp[i] >= 10 && p_tmp[i] <= 15)
            p_tmp[i] = p_tmp[i] - 10 + 'A';
    }
    return p_hex;
}

//找出两个字符串中最大公共子字符串,如"abccade","dgcadde"的最大子串为"cad"
void sameStr( char *str1, char *str2, char *str3 )
{
    int i,j,k,len,max=0,n=0;
    char *temp;
    
    if ( strlen( str2 ) < strlen( str3 ) ) /*为了保证外层循环的那个字符串总是最长的*/
    {
        temp = str2;
        str2 = str3;
        str3 = temp;
    }
    
    
    for ( i=0; *(str2+i)!='\0'; i++ )
    {
        len = 0;
        for ( j=0,k=i; *(str3+j)!='\0'&&*(str2+k)!='\0'; j++,k++ )
        {
            if ( *(str2+k) == *(str3+j) )
            {
                len++;
            }
            else  /*当下一个字符不相同时，要避免相隔相同的字母len累加*/
            {
                if ( max < len )
                {
                    max = len;
                    n = k-len;
                }
                len = 0;
            }
        }
        if ( max < len )  /*当一个字符串的末尾字符串相等时*/
        {
            max = len;
            n = k-len;
            len = 0;
        }
        
    }
    
    
    for ( j=0; j<max; j++,n++ )
        *str1++ = *(str2+n);
    *str1 = '\0';
}

//求两个字符串的最大公共字符子串，如"abccade","dgcadde"的最大子串为"cad"
int getCommon(char *s1, char *s2, char **r)
{
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);
    int maxlen = 0;
    int i = 0, j = 0;
    
    for (i = 0;  i < len1;  i++)
    {
        for(j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                int as = i, bs = j, count = 1;
                while((as + 1 < len1 )&& (bs + 1 < len2) && (s1[++as] ==s2[++bs]))
                    count++;
                if (count > maxlen)
                {
                    maxlen = count;
                    *r = s1 + i;
                }
            }
        }  
    }  
    return  maxlen;
}
