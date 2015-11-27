//
//  fmbdManager.m
//  AddressBook
//
//  Created by zhaotengfei on 15-9-24.
//  Copyright (c) 2015年 zhaotengfei. All rights reserved.
//

#import "fmbdManager.h"
#import "FMDatabase.h"
#import <UIKit/UIKit.h>
@interface fmbdManager (){
    FMDatabase *db;
}

@end
@implementation fmbdManager

+(fmbdManager *)shareManager{
    static fmbdManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[fmbdManager alloc]init];
    });
    return manager;
}

-(BOOL)open{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSError *error = nil;
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
    NSString *writablePath = [path stringByAppendingPathComponent:@"HYRemote.sqlite"];
    if (![fileManager fileExistsAtPath:writablePath]) {
        NSString *resource =[[NSBundle mainBundle]pathForResource:@"HYRemote" ofType:@"sqlite"];
        [fileManager copyItemAtPath:resource toPath:writablePath error:&error];
        if (error != nil) {
            NSLog(@"errInfo:%@", [error description]);
        }
    }
    db = [FMDatabase databaseWithPath:writablePath];
    if (![db open]) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"无法验证" message:@"数据库打开失败" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert show];
        return NO;
    }
    return YES;
}

-(BOOL)insert:(AdressInfo *)addressInfo{
    
    NSString *insertSql = [NSString stringWithFormat:
             @"INSERT INTO AddressInfo(CELL,LAC,LNG,LAT,TELEPHONE,ADDRESS) VALUES('%@','%@','%@','%@','%@','%@')",
                           addressInfo.cellContent,addressInfo.lacContent,addressInfo.lngContent,
                           addressInfo.latContent,addressInfo.telContent,addressInfo.addressContent];
    BOOL res = [db executeUpdate:insertSql];
    if (!res) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"增加数据失败" message:@"" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert show];
    }
    [db close];
    return res;
}

-(BOOL)update:(NSString *)lng lat:(NSString *)lat tel:(NSString *)tel{
    NSString *updateSql =[NSString stringWithFormat:
             @"UPDATE AddressInfo SET TELEPHONE = '%@' WHERE LNG = '%@' AND LAT = '%@'",tel,lng,lat];
    BOOL res = [db executeUpdate:updateSql];
    if (!res) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"更新数据失败" message:@"" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert show];
    }
    [db close];
    return res;
}

-(BOOL)deleteData:(NSString *)lng lat:(NSString *)lat{
    NSString *deleteSql = [NSString stringWithFormat:
             @"DELETE FROM AddressInfo WHERE LNG = '%@' AND LAT = '%@'",lng,lat];
    BOOL res = [db executeUpdate:deleteSql];
    if (!res) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"删除数据失败" message:@"" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
        [alert show];
    }
    [db close];
    return res;
}

-(BOOL)checkData:(NSString *)lng lat:(NSString *)lat{
    BOOL result;
    NSString *checkSql = [NSString stringWithFormat:
                           @"select * FROM AddressInfo WHERE LNG = '%@' AND LAT = '%@'",lng,lat];
    FMResultSet *rs = [db executeQuery:checkSql];
    if (rs.next) {
        result = NO;
    }else{
        result = YES;
    }
    [db close];
    return result;
}

-(NSMutableArray *)searchData{
    NSString *sql = [NSString stringWithFormat:
                     @"SELECT * FROM AddressInfo"];
    FMResultSet *rs = [db executeQuery:sql];
    NSMutableArray *contactArr = [NSMutableArray array];
    NSMutableArray *contactArr2 = [NSMutableArray array];
    int index = 0;
    while (rs.next) {
        AdressInfo *tmp = [[AdressInfo alloc]init];
        index++;
        tmp.numContent =[NSString stringWithFormat:@"%d",index];
        tmp.cellContent = [rs stringForColumn:@"CELL"];
        tmp.lacContent = [rs stringForColumn:@"LAC"];
        tmp.lngContent = [rs stringForColumn:@"LNG"];
        tmp.latContent = [rs stringForColumn:@"LAT"];
        tmp.telContent = [rs stringForColumn:@"TELEPHONE"];
        tmp.addressContent = [rs stringForColumn:@"ADDRESS"];
        [contactArr addObject:tmp];
    }
    [db close];
    id obj;
    NSEnumerator *en = [contactArr reverseObjectEnumerator];
    while (obj = [en nextObject]) {
        [contactArr2 addObject:obj];
    }
    return contactArr2;
}
-(BOOL)searchUser:(NSString *)name password:(NSString *)pwd{
    NSString *sql = [NSString stringWithFormat:
             @"SELECT * FROM User WHERE NAME = '%@' AND Passworld = '%@'",name,pwd];
    BOOL result;
    FMResultSet *rs = [db executeQuery:sql];
    if (rs.next) {
        result = YES;
    }else{
        result = NO;
    }
    [db close];
    return result;
}

@end
