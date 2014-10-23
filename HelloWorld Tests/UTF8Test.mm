//
//  UTF8Test.m
//  HelloWorld
//
//  Created by luowei on 14-10-22.
//  Copyright (c) 2014年 luowei. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface UTF8Test : XCTestCase

@end

@implementation UTF8Test

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testUnicharAndUTF
{
    
}


//========== C++ Code ========
uint32 uniCharToUTF8(wchar_t uniChar, char *outUTFString)
{
    
	uint32 utf8CharLength = 0;
    
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

uint32 UTF8StrToUnicode( const char* utf8String, uint32 utf8StringLength, wchar_t* outUnicodeString, uint32 unicodeStringBufferSize )
{
	uint32 utf8Index = 0;
	uint32 uniIndex = 0;
    
	while ( utf8Index < utf8StringLength )
	{
		unsigned char utf8Char = utf8String[utf8Index];
        
		if ( unicodeStringBufferSize != 0 && uniIndex >= unicodeStringBufferSize )
			break;
        
		if ((utf8Char & 0x80) == 0)
		{
			const uint32 cUTF8CharRequire = 1;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& wideChar = outUnicodeString[uniIndex];
                
				wideChar = utf8Char;
			}
            
			utf8Index++;
			
		}
		else if((utf8Char & 0xE0) == 0xC0)  ///< 110x-xxxx 10xx-xxxx
		{
			const uint32 cUTF8CharRequire = 2;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& wideChar = outUnicodeString[uniIndex];
				wideChar  = (utf8String[utf8Index + 0] & 0x3F) << 6;
				wideChar |= (utf8String[utf8Index + 1] & 0x3F);
			}
			
			utf8Index += cUTF8CharRequire;
		}
		else if((utf8Char & 0xF0) == 0xE0)  ///< 1110-xxxx 10xx-xxxx 10xx-xxxx
		{
			const uint32 cUTF8CharRequire = 3;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& wideChar = outUnicodeString[uniIndex];
                
				wideChar  = (utf8String[utf8Index + 0] & 0x1F) << 12;
				wideChar |= (utf8String[utf8Index + 1] & 0x3F) << 6;
				wideChar |= (utf8String[utf8Index + 2] & 0x3F);
			}
			
            
			utf8Index += cUTF8CharRequire;
		}
		else if((utf8Char & 0xF8) == 0xF0)  ///< 1111-0xxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
		{
			const uint32 cUTF8CharRequire = 4;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& wideChar = outUnicodeString[uniIndex];
                
				wideChar  = (utf8String[utf8Index + 0] & 0x0F) << 18;
				wideChar  = (utf8String[utf8Index + 1] & 0x3F) << 12;
				wideChar |= (utf8String[utf8Index + 2] & 0x3F) << 6;
				wideChar |= (utf8String[utf8Index + 3] & 0x3F);
			}
            
			utf8Index += cUTF8CharRequire;
		}
		else ///< 1111-10xx 10xx-xxxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
		{
			const uint32 cUTF8CharRequire = 5;
            
			// UTF8字码不足
			if ( utf8Index + cUTF8CharRequire > utf8StringLength )
				break;
            
			if ( outUnicodeString )
			{
				wchar_t& wideChar = outUnicodeString[uniIndex];
                
				wideChar  = (utf8String[utf8Index + 0] & 0x07) << 24;
				wideChar  = (utf8String[utf8Index + 1] & 0x3F) << 18;
				wideChar  = (utf8String[utf8Index + 2] & 0x3F) << 12;
				wideChar |= (utf8String[utf8Index + 3] & 0x3F) << 6;
				wideChar |= (utf8String[utf8Index + 4] & 0x3F);
			}
            
			utf8Index += cUTF8CharRequire;
		}
        
		uniIndex++;
	}
    
	return uniIndex;
}

@end
