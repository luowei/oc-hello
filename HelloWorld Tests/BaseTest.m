//
//  BaseTest.m
//  singleview-demo
//
//  Created by luowei on 14-10-21.
//  Copyright (c) 2014年 rootls. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface BaseTest : XCTestCase

@end

@implementation BaseTest

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

-(void)testEquals
{
    NSString* str1 = [NSString stringWithFormat:@"abc"];
    NSString* str2 = @"abc";
    

//    XCTAssertEqual(str1, str2, @"str1 equals str2"); //false
    XCTAssertEqualObjects(str1, str2, @"str1 equalObjects str2"); //true
}

-(void)testArrary
{
    NSArray *arrary = [NSArray arrayWithObjects:@1,@2,@3,@4, nil];
    NSLog(@"数组元素的数量为:%lu",[arrary count]);
    for (id e in arrary) {
        NSLog(@"数组元数为:%@,",e);
    }
    XCTAssertEqual([arrary count],4,@"数组元素的个数");
    
//    NSMutableArray* arr = [NSMutableArray arrayWithCapacity:0];
    NSMutableArray* arr = @[].mutableCopy;
    [arr addObject:@'a'];
    [arr addObject:@'b'];
    [arr addObject:@'c'];
    
//    NSMutableString* arrStr = [NSMutableString stringWithString:@""];
    NSMutableString* arrStr = @"".mutableCopy;
    for (int i=0; i<[arr count]; i++) {
        id c = [arr objectAtIndex:i];
        NSString* cStr = [NSString stringWithFormat:@"%c",[(NSNumber*)c charValue]];
        NSLog(@"** %@",cStr);
        [arrStr appendFormat:@"%@",cStr];
    }
    
    NSLog(@"可变数组的元素为:%@ -- %@",[arrStr description],[@"abc" description]);
    
    XCTAssertEqualObjects(arrStr, @"abc" , @"arrStr equals abc");
}

-(void)testArray2
{
    //类方法数组创建
    NSArray *array1 = [NSArray arrayWithObject:@"obj"];
    NSArray *array2 = [NSArray arrayWithObjects:@"obj1", @"obj2", @"obj3", nil];
    NSArray *array3 = [NSArray arrayWithArray:array2];
    NSLog(@"array1 :%@", array1);
    NSLog(@"array2 :%@", array2);
    NSLog(@"array3 :%@", array3);
    
    //实例方法创建数组
    NSArray *array4 = [[NSArray alloc] initWithObjects:@"AAA", @"bbb", nil];
    NSLog(@"array4 :%@", array4);
    //数组个数
    NSLog(@"array3 count :%ld", [array3 count]);
    //访问元素
    NSLog(@"obj at index :%@", [array2 objectAtIndex:2]);
    //追加(返回新的array对象)
    NSArray *array5 = [array3 arrayByAddingObject:@"ccc"];
    NSLog(@"array5 :%@", array5);
    //根据指定的字符串连接数组元素
    NSString *joinString1 = [array5 componentsJoinedByString:@"|"];
    NSLog(@"joinString :%@",joinString1);
    //是否包含指定对象
    NSLog(@"isContains :%d", [array5 containsObject:@"obj2"]);
    //查找某个对象所在索引
    NSLog(@"indexOfObject :%ld",[array5 indexOfObject:@"obj3"]);
    //最后一个元素
    NSLog(@"lastObejct :%@", [array5 lastObject]);
    //遍历数组
    for (id element in array5) {
        NSLog(@"element :%@", element);
    }
    
    
    //可变数组(期望容量设置为3)
    NSMutableArray *mutableArray = [NSMutableArray arrayWithCapacity:3];
    //直接添加
    [mutableArray addObject:@"aaa"];
    [mutableArray addObject:@"eee"];
    [mutableArray addObject:@"000"];
    NSLog(@"addObject :%@", mutableArray);
    
    //插入元素
    [mutableArray insertObject:@"ccc" atIndex:0];
    NSLog(@"insertObject :%@", mutableArray);
    //移除指定元素
    [mutableArray removeObject:@"ccc"];
    NSLog(@"removeObject :%@", mutableArray);
    //移除指定下标元素
    [mutableArray removeObjectAtIndex:0];
    NSLog(@"removeObjectAtIndex :%@", mutableArray);
    //移除最后一个元素
    [mutableArray removeLastObject];
    NSLog(@"removeLastObject :%@", mutableArray);
    //添加数组
    [mutableArray addObjectsFromArray:array5];
    NSLog(@"addObjectsFromArray :%@", mutableArray);
    //移除指定数组中的内容
    [mutableArray removeObjectsInArray:array2];
    NSLog(@"removeObjectsInArray :%@", mutableArray);
    //指定索引替换对象
    [mutableArray replaceObjectAtIndex:0 withObject:@"==="];
    NSLog(@"replaceObjectAtIndex :%@", mutableArray);
    //删除全部对象
    [mutableArray removeAllObjects];
    NSLog(@"removeAllObjects :%@", mutableArray);
}

-(void)testDictionary
{
    NSDictionary *dictionary = [NSDictionary dictionaryWithObjectsAndKeys:
                                @"linus",@"name",@"15821428888",@"number", nil];
    
    NSUInteger count = [dictionary count];
    NSLog(@"键值对数量为： %ld",count);
    
    for(id value in [dictionary objectEnumerator]){
        NSLog(@"***** value:%@\n",value);
    }
    
    XCTAssertEqual([dictionary count], 2,@"");
    
    
    NSMutableDictionary* dict = @{}.mutableCopy;
//    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithCapacity:0];
    
    [dict setValue:@"123" forKey:@"aaa"];
    NSLog(@"=====value ::: %@",[dict valueForKey:@"aaa"]);
    
    for (id key in [dict keyEnumerator]){
        NSLog(@"##### key:%@--value:%@\n",key,[dict valueForKey:key]);
    }
    
    XCTAssertNotNil([dict valueForKey:@"aaa"], @" value is not nil");
    
}

-(void)testTypeBytes
{
    NSObject* obj = [[NSObject alloc]init];
    NSString* str = [NSString stringWithFormat:@"aaa"];
    //point size:8 obj size:8
    NSLog(@"\n------:%p\n point size:%lu obj size:%lu",str,sizeof(str),sizeof(obj));
    
    //char占1个字节,8位；unichar占2个字节,16位；wchar_t占4个字节,32位
    NSLog(@"\n------\n char size:%lu unichar size:%lu wchar_t size:%lu",
          sizeof(char),sizeof(unichar),sizeof(wchar_t));
    //int size:4 short size:2 long size:8 bool size:1 float size:4 double size:8
    NSLog(@"\n-----\n int size:%lu short size:%lu long size:%lu bool size:%lu float size:%lu double size:%lu \n",
          sizeof(int),sizeof(short),sizeof(long),sizeof(bool),sizeof(float),sizeof(double));
    
    //long int size:8 long long int size:8
    NSLog(@"\n----\n long int size:%lu  long long int size:%lu",sizeof(long int),sizeof(long long int));
    
    NSInteger b = 3;
    NSLog(@"=====:%ld",b);
}

-(void)testInitUnichar{
    
    //unichar[] to NSString
    unichar a[11];
    a[0]=0x3007; //〇
    NSString* str=@"一二三四五六七八九十";
    for(int i=0;i<10;i++){
        a[i+1] = [str characterAtIndex:i];
    }
    
    NSString* outstr = [NSString stringWithCharacters:a length:11];
    NSLog(@"\n unichar array:%@",outstr);
    
    //NSString  <=> NSInteger
    NSInteger integerNumber = 888;
    NSString * string = [NSString stringWithFormat:@"%ld",(long)integerNumber];
    NSLog(@"string is %@", string);
    int integer = [string intValue];
    NSLog(@"integer is %i", integer);
    
}

@end
