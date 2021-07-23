#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface Configuration : NSObject

- (void)setUsername:(NSString *)Username;
- (NSString *)Username;

- (void)setPassword:(NSString *)Password;
- (NSString *)Password;

- (void)setApiUrl:(NSString *)ApiUrl;
- (NSString *)ApiUrl;

- (NSString *)description;

@end

@interface Message : NSObject

- (instancetype) init;

- (void)setID:(NSString *)ID;
- (NSString *)ID;

- (void)setFromConnection:(NSString *)FromConnection;
- (NSString *)FromConnection;

- (void)setFromAddress:(NSString *)FromAddress;
- (NSString *)FromAddress;

- (void)setFromStation:(NSString *)FromStation;
- (NSString *)FromStation;

- (void)setToConnection:(NSString *)ToConnection;
- (NSString *)ToConnection;

- (void)setToAddress:(NSString *)ToAddress;
- (NSString *)ToAddress;

- (void)setToStation:(NSString *)ToStation;
- (NSString *)ToStation;

- (void)setText:(NSString *)Text;
- (NSString *)Text;

- (void)setCreateDate:(NSDate *)CreateDate;
- (NSDate *)CreateDate;

- (void)setValidUntil:(NSDate *)ValidUntil;
- (NSDate *)ValidUntil;

- (void)setTimeToSend:(NSDate *)TimeToSend;
- (NSDate *)TimeToSend;

- (void)setIsSubmitReportRequested:(BOOL)IsSubmitReportRequested;
- (BOOL)IsSubmitReportRequested;

- (void)setIsDeliveryReportRequested:(BOOL)IsDeliveryReportRequested;
- (BOOL)IsDeliveryReportRequested;

- (void)setIsViewReportRequested:(BOOL)IsViewReportRequested;
- (BOOL)IsViewReportRequested;

- (void)addTag:(NSString *)key value:(NSString *)value;
- (NSMutableArray *)getTags;

- (NSMutableDictionary *)getJSON;

- (NSString *)description;

@end

typedef NS_ENUM(NSInteger, Folder)
{
    Inbox,
    Outbox,
    Sent,
    NotSent,
    Deleted
};

typedef NS_ENUM(NSInteger, DeliveryStatus)
{
    Failed = 0,
    Success = 1
};

@interface MessageSendResult : NSObject

- (instancetype) initWithMessage:(Message *)message DeliveryStatus:(NSInteger *)status ResponseMessage:(NSString *)response_message;

- (NSString *) description;

- (Message *) message;

- (NSString *) status;

- (NSString *) responseMessage;

@end

@interface MessageSendResults : NSObject

- (NSString *) description;

- (NSMutableArray<MessageSendResult *> *) results;

- (NSInteger) totalCount;

- (NSInteger) successCount;

- (NSInteger) failedCount;

@end

@interface MessageDeleteResult : NSObject

- (instancetype) initWithFolder:(NSInteger)folder;

- (void) addMessageIdRemoveSucceeded:(NSString *)message_id;

- (void) addMessageIdRemoveFailed:(NSString *)message_id;

- (NSMutableArray<NSString *> *) messageIdsRemoveSucceeded;

- (NSMutableArray<NSString *> *) messageIdsRemoveFailed;

- (NSString *) description;

@end

@interface MessageMarkResult : NSObject

- (instancetype) initWithFolder:(NSInteger)folder;

- (void) addMessageIdMarkSucceeded:(NSString *)message_id;

- (void) addMessageIdMarkFailed:(NSString *)message_id;

- (NSMutableArray<NSString *> *) messageIdsMarkSucceeded;

- (NSMutableArray<NSString *> *) messageIdsMarkFailed;

- (NSString *) description;

@end

@interface MessageReceiveResult : NSObject

- (instancetype) initWithFolder:(NSInteger *)folder Limit:(NSString *)limit;

- (void) addMessage:(Message *)message;

- (NSMutableArray<Message *> *) messages;

- (NSString *) description;

@end

@interface MessageApi : NSObject

- (instancetype)initWithConfiguration:(Configuration *)configuration;

- (void)setConfiguration:(Configuration *)Configuration;

- (MessageSendResult *)SendMessage:(Message *)message;

- (MessageSendResults *)SendMessages:(NSArray *)messages;

- (Boolean)DeleteMessage:(Message *)message Folder:(NSInteger)folder;

- (MessageDeleteResult *)DeleteMessages:(NSMutableArray<Message *> *)messages Folder:(NSInteger)folder;

- (Boolean)MarkMessage:(Message *)message Folder:(NSInteger)folder;

- (MessageDeleteResult *)MarkMessages:(NSMutableArray<Message *> *)messages Folder:(NSInteger)folder;

- (MessageReceiveResult *)DownloadIncoming;

- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
