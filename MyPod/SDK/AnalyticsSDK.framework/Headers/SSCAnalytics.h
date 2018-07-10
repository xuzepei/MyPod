//
//  Analytics.h


#import <Foundation/Foundation.h>
#import "Flurry.h"
#import "GAI.h"
#import "GAIDictionaryBuilder.h"
#import "GAIFields.h"
#import "SSCAnalyticsTool.h"
#import <FirebaseAnalytics/FirebaseAnalytics.h>
#import <FirebaseCore/FirebaseCore.h>


typedef enum
{
    AT_UNKNOWN = 0,
    AT_FLURRY = 1,
    AT_NATIVE = 2,
    AT_GOOGLE = 4,
    AT_QUANTCAST = 8,
    AT_COMSCORE = 16,
    AT_FIREBASE = 32,
}AnalyticsType;

//int FLURRY = 0x00000001;
//int ANALYTICS = 0x00000001 << 1;
//int GOOGLE = 0x00000001 << 2;

@interface SSCAnalytics : NSObject<FlurryDelegate>

@property(nonatomic,assign)BOOL flurryIsReady;
@property(nonatomic,assign)BOOL nativeIsReady;
@property(nonatomic,assign)BOOL googleIsReady;
@property(nonatomic,assign)BOOL quantcastIsReady;
@property(nonatomic,assign)BOOL comScoreIsReady;
@property(nonatomic,assign)BOOL firebaseIsReady;
@property(nonatomic,assign)BOOL flurryDebugIsReady;
@property(nonatomic,assign)BOOL nativeDebugIsReady;
@property(nonatomic,assign)BOOL googleDebugIsReady;
@property(nonatomic,assign)BOOL quantcastDebugIsReady;
@property(nonatomic,assign)BOOL comScoreDebugIsReady;
@property(nonatomic,assign)BOOL firebaseDebugIsReady;
@property(nonatomic,assign)BOOL isDebug;
@property(nonatomic,assign)BOOL needStartSessionForGA;
@property(nonatomic,assign)int types;

+ (NSString*)getVersion;
+ (SSCAnalytics*)getInstance;

- (void)startAllSessions;
- (void)startSession:(int)types;
- (void)endSession;

- (void)sendEvent:(NSString*)action label:(NSString*)label;
- (void)sendEvent:(NSString*)category action:(NSString*)action label:(NSString*)label;
- (void)sendEvent:(NSString*)action params:(NSDictionary*)params;
- (void)sendEvent:(NSString*)category action:(NSString*)action params:(NSDictionary*)params;
- (void)sendEvent:(NSString*)category action:(NSString*)action label:(NSString*)label value:(NSNumber*)value params:(NSDictionary*)params;
- (void)sendEvent:(NSString*)action params:(NSDictionary*)params disableToast:(BOOL)disableToast;

- (void)sendEventScreen:(NSString*)screenName;
//- (void)sendUserTiming:(NSString*)category interval:(long)interval name:(NSString*)name label:(NSString*)label;

- (void)setDebugMode:(BOOL)isDebug;
- (BOOL)getDebugMode;

@end
