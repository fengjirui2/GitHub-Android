//
//  fmbdManager.h
//  AddressBook
//
//  Created by zhaotengfei on 15-9-24.
//  Copyright (c) 2015年 zhaotengfei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdressInfo.h"
@interface fmbdManager : NSObject

//单例方法
+(fmbdManager *)shareManager;

//打开数据库
-(BOOL)open;
//插入数据
-(BOOL)insert:(AdressInfo *)addressInfo;
//更新数据
-(BOOL)update:(NSString *)lng lat:(NSString *)lat tel:(NSString *)tel;
//删除数据
-(BOOL)deleteData:(NSString *)lng lat:(NSString *)lat;
//查询用户
-(BOOL)searchUser:(NSString *)name password:(NSString *)pwd;
//查询基站信息
-(NSMutableArray *)searchData;
//检查数据
-(BOOL)checkData:(NSString *)lng lat:(NSString *)lat;
@end
