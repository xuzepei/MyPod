//
//  SSCAnalyticsTool.h
//  AnalyticsTest
//
//  Created by xuzepei on 16/4/19.
//  Copyright © 2016年 moki. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Session;

@interface SSCAnalyticsTool : NSObject

@property(nonatomic,strong)Session* session;
//@property(nonatomic,assign)BOOL isDebugMode;
@property (nonatomic, strong)NSMutableSet* requestedUrl;

+ (SSCAnalyticsTool*)getInstance;
+ (NSString*)getVersion;

- (void)startSession;
- (void)endSession;
- (void)sendEvent:(NSString*)category action:(NSString*)action label:(NSString*)label value:(long)value;



@end
