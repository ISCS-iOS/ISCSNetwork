//
//  SANetworkRequest.h
//  SANetworkDemo
//
//  Created by 学宝 on 16/7/22.
//  Copyright © 2016年 浙江网仓科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANetworkAccessoryProtocol.h"
#import "SANetworkInterceptorProtocol.h"
#import "SANetworkRequestConfigProtocol.h"
#import "SANetworkResponseProtocol.h"
#import "SANetworkServiceProtocol.h"


/**
 网络接口请求类
 */
@interface SANetworkRequest : NSObject


/**
 请求的tag
 */
@property (nonatomic, assign) NSInteger tag;

/**
 请求载体
 */
@property (nonatomic, strong) NSURLSessionDataTask *sessionDataTask;

/**
 请求配置协议
 */
@property (nonatomic, weak, readonly) NSObject<SANetworkRequestConfigProtocol> *requestConfigProtocol;

/**
 响应协议
 */
@property (nonatomic, weak) id <SANetworkResponseProtocol>responseDelegate;

/**
 拦截协议
 */
@property (nonatomic, weak) id <SANetworkInterceptorProtocol>interceptorDelegate;


/**
 插件协议
 */
@property (nonatomic, weak) id <SANetworkAccessoryProtocol>accessoryDelegate;

/**
 *  @brief 开始网络请求，使用delegate 方式使用这个方法
 */
- (void)startRequest;

/**
 *  @brief 停止网络请求
 */
- (void)stopRequestByStatus:(SANetworkStatus)status;

/**
 *  @brief 添加实现了SANetworkAccessoryProtocol的插件对象
 *
 *  @param accessoryDelegate 插件对象
 *  @warning 务必在启动请求之前添加插件。
 */
- (void)addNetworkAccessoryObject:(id<SANetworkAccessoryProtocol>)accessoryDelegate;

@end
