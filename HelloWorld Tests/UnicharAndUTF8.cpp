//
//  UnicharAndUTF8.c
//  HelloWorld
//
//  Created by luowei on 14-10-22.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#include <stdio.h>


//========== C Code ========
unsigned int uniCharToUTF8(wchar_t uniChar, char *outUTFString)
{
    
	unsigned int utf8CharLength = 0;
    
	if (uniChar < 0x80)
	{
		if ( outUTFString )
			outUTFString[utf8CharLength++] = (char)uniChar;
		else
			utf8CharLength++;
	}
	else if(uniChar < 0x800)
	{
		if ( outUTFString )
		{
			outUTFString[utf8CharLength++] = 0xc0 | ( uniChar >> 6 );
			outUTFString[utf8CharLength++] = 0x80 | ( uniChar & 0x3f );
		}
		else
		{
			utf8CharLength += 2;
		}
	}
	else if(uniChar < 0x10000 )
	{
		if ( outUTFString )
		{
			outUTFString[utf8CharLength++] = 0xe0 | ( uniChar >> 12 );
			outUTFString[utf8CharLength++] = 0x80 | ( (uniChar >> 6) & 0x3f );
			outUTFString[utf8CharLength++] = 0x80 | ( uniChar & 0x3f );
		}
		else
		{
			utf8CharLength += 3;
		}
	}
	else if( uniChar < 0x200000 )
	{
		if ( outUTFString )
		{
			outUTFString[utf8CharLength++] = 0xf0 | ( (int)uniChar >> 18 );
			outUTFString[utf8CharLength++] = 0x80 | ( (uniChar >> 12) & 0x3f );
			outUTFString[utf8CharLength++] = 0x80 | ( (uniChar >> 6) & 0x3f );
			outUTFString[utf8CharLength++] = 0x80 | ( uniChar & 0x3f );
		}
		else
		{
			utf8CharLength += 4;
		}
        
	}
    
	return utf8CharLength;
}

unsigned int UTF8StrToUnicode( const char* utf8String, unsigned int utf8StringLength, wchar_t* outUnicodeString, unsigned int unicodeStringBufferSize )
{
	unsigned int utf8Index = 0;
	unsigned int uniIndex = 0;
    
	while ( utf8Index < utf8StringLength )
	{
		unsigned char utf8Char = utf8String[utf8Index];
        
		if ( unicodeStringBufferSize != 0 && uniIndex >= unicodeStringBufferSize )
			break;
        
		if ((utf8Char & 0x80) == 0)
		{
			const unsigned int cUTF8CharRequire = 1;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& WideChar = outUnicodeString[uniIndex];
                
				WideChar = utf8Char;
			}
            
			utf8Index++;
			
		}
		else if((utf8Char & 0xE0) == 0xC0)  ///< 110x-xxxx 10xx-xxxx
		{
			const unsigned int cUTF8CharRequire = 2;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
            //C++中的引用{int a;int& ra=a;}：
            //1.声明一个引用，名字是ra，ra引用了a ;
            //2.声明的时候必须同时给出它到底引用了谁 ;
            //3.引用一旦声明，就不能再修改到其他变量上了，这与指针不同 ;
            
			if ( outUnicodeString )
			{
				wchar_t& WideChar = outUnicodeString[uniIndex];
				WideChar  = (utf8String[utf8Index + 0] & 0x3F) << 6;
				WideChar |= (utf8String[utf8Index + 1] & 0x3F);
			}
			
			utf8Index += cUTF8CharRequire;
		}
		else if((utf8Char & 0xF0) == 0xE0)  ///< 1110-xxxx 10xx-xxxx 10xx-xxxx
		{
			const unsigned int cUTF8CharRequire = 3;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& WideChar = outUnicodeString[uniIndex];
                
				WideChar  = (utf8String[utf8Index + 0] & 0x1F) << 12;
				WideChar |= (utf8String[utf8Index + 1] & 0x3F) << 6;
				WideChar |= (utf8String[utf8Index + 2] & 0x3F);
			}
			
            
			utf8Index += cUTF8CharRequire;
		}
		else if((utf8Char & 0xF8) == 0xF0)  ///< 1111-0xxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
		{
			const unsigned int cUTF8CharRequire = 4;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& WideChar = outUnicodeString[uniIndex];
                
				WideChar  = (utf8String[utf8Index + 0] & 0x0F) << 18;
				WideChar  = (utf8String[utf8Index + 1] & 0x3F) << 12;
				WideChar |= (utf8String[utf8Index + 2] & 0x3F) << 6;
				WideChar |= (utf8String[utf8Index + 3] & 0x3F);
			}
            
			utf8Index += cUTF8CharRequire;
		}
		else ///< 1111-10xx 10xx-xxxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
		{
			const unsigned int cUTF8CharRequire = 5;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& WideChar = outUnicodeString[uniIndex];
                
				WideChar  = (utf8String[utf8Index + 0] & 0x07) << 24;
				WideChar  = (utf8String[utf8Index + 1] & 0x3F) << 18;
				WideChar  = (utf8String[utf8Index + 2] & 0x3F) << 12;
				WideChar |= (utf8String[utf8Index + 3] & 0x3F) << 6;
				WideChar |= (utf8String[utf8Index + 4] & 0x3F);
			}
            
			utf8Index += cUTF8CharRequire;
		}
        
		uniIndex++;
	}
    
	return uniIndex;
}