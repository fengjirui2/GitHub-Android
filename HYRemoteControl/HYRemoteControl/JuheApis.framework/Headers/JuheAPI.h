//
//  JuheAPI.h
//  JuheApisSDK
//
//  Created by ThinkLand on 8/8/14.
//  Copyright (c) 2014 ThinkLand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JuheAPI : NSObject

+ (instancetype)shareJuheApi;

/**
 @brief  执行聚合数据请求, 操作请求返回的数据
 @param api           聚合数据服务接口宏定义，可以在JHSDKAPIPath.h文件中查找
 @param paras         对应于服务类型的一些参数, 是Objective-C的NSDictionary类型
 @param success       请求得到处理, 并且返回有效数据时, 对返回的数据, 在主线程, 执行自定义的行为
 @param failure       没有网络, 或者服务器没有响应, 或者服务器没有返回有效数据, 对返回的NSError对象, 在主线程, 执行自定义的行为
 @discuss             
 a. 数据服务类型的选择, 对应可用的HTTP请求方法, 对应可用的请求参数, 执行请求返回的Objective-C对象, 请参考SDK文档
 b. 执行数据请求是异步的, 开发者直接调用即可.
 */

- (void)executeWorkWithAPI:(NSString *)api parameters:(NSDictionary *)paras success:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failre;

@end
