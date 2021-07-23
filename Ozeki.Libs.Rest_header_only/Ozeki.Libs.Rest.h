#import <Foundation/Foundation.h>

//This is what happens when the repository gets updated.

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

@implementation Configuration
{
    
    NSString * _username;
    
    NSString * _password;
    
    NSString * _api_url;
    
}

- (void)setUsername:(NSString *)Username
{
    _username = Username;
}

- (void)setPassword:(NSString *)Password
{
    _password = Password;
}

- (void)setApiUrl:(NSString *)ApiUrl
{
    _api_url = ApiUrl;
}

- (NSString *)Username
{
    return _username;
}

- (NSString *) Password
{
    return _password;
}

- (NSString *) ApiUrl
{
    return _api_url;
}

- (NSString *)description
{
    return [ NSString stringWithFormat : @"[ Username: '%@', Password: '%@', ApiUrl: '%@' ]",  _username, _password, _api_url ];
}

@end


@implementation Message
{
    NSString* _id;

    NSString * _from_connection;

    NSString * _from_address;

    NSString * _from_station;

    NSString * _to_connection;

    NSString * _to_address;

    NSString * _to_station;

    NSString * _text;

    NSDate * _create_date;

    NSDate * _valid_until;

    NSDate * _time_to_send;

    BOOL * _is_submit_report_requested;

    BOOL * _is_delivery_report_requested;

    BOOL * _is_view_report_requested;

    NSMutableArray *_tags;
}

- (instancetype) init
{
    if ((self = [ super init ])) {
        NSDate *NOW = [ [ NSDate alloc ] init ];
        NSCalendar *CALENDAR = [NSCalendar currentCalendar];
        NSDateComponents *DAYS = [[NSDateComponents alloc] init];
        DAYS.day = 7;
        
        [ self setID: [ [ [ NSUUID UUID ] UUIDString ] lowercaseString ] ];
        [ self setCreateDate : NOW ];
        [ self setValidUntil : [CALENDAR dateByAddingComponents : DAYS toDate : [NSDate date] options:0] ];
        [ self setTimeToSend : NOW ];
        [ self setIsSubmitReportRequested: true ];
        [ self setIsDeliveryReportRequested: true ];
        [ self setIsViewReportRequested: true ];
        _tags = [ [ NSMutableArray array ] init ];
    }
    return self;
}

- (void)setID:(NSString *)ID
{
    _id = ID;
}

- (NSString *)ID
{
    return _id;
}

- (void)setFromConnection:(NSString *)FromConnection
{
    _from_connection = FromConnection;
}
- (NSString *)FromConnection
{
    return _from_connection;
}

- (void)setFromAddress:(NSString *)FromAddress
{
    _from_address = FromAddress;
}
- (NSString *)FromAddress
{
    return _from_address;
}

- (void)setFromStation:(NSString *)FromStation
{
    _from_station = FromStation;
}
- (NSString *)FromStation
{
    return _from_station;
}

- (void)setToConnection:(NSString *)ToConnection
{
    _to_connection = ToConnection;
}
- (NSString *)ToConnection
{
    return _to_connection;
}

- (void)setToAddress:(NSString *)ToAddress
{
    _to_address = ToAddress;
}

- (NSString *)ToAddress
{
    return _to_address;
}

- (void)setToStation:(NSString *)ToStation
{
    _to_station = ToStation;
}

- (NSString *)ToStation
{
    return _to_station;
}

- (void)setText:(NSString *)Text
{
    _text = Text;
}

- (NSString *)Text
{
    return _text;
}

- (void)setCreateDate:(NSDate *)CreateDate
{
    _create_date = CreateDate;
}

- (NSDate *)CreateDate
{
    return _create_date;
}

- (void)setValidUntil:(NSDate *)ValidUntil;
{
    _valid_until = ValidUntil;
}

- (NSDate *)ValidUntil
{
    return _valid_until;
}

- (void)setTimeToSend:(NSDate *)TimeToSend
{
    _time_to_send = TimeToSend;
}

- (NSDate *)TimeToSend
{
    return _time_to_send;
}

- (void)addTag:(NSString *)key value:(NSString *)value
{
    NSDictionary<NSString*, NSString*> *tag = @{ key : value };
    [ _tags addObject : tag ];
}

- (void)setIsSubmitReportRequested:(BOOL)IsSubmitReportRequested
{
    _is_submit_report_requested = &IsSubmitReportRequested;
}

- (BOOL)IsSubmitReportRequested
{
    return *(_is_submit_report_requested);
}

- (void)setIsDeliveryReportRequested:(BOOL)IsDeliveryReportRequested
{
    _is_delivery_report_requested = &IsDeliveryReportRequested;
}

- (BOOL)IsDeliveryReportRequested
{
    return *(_is_delivery_report_requested);
}

- (void)setIsViewReportRequested:(BOOL)IsViewReportRequested
{
    _is_view_report_requested = &IsViewReportRequested;
}

- (BOOL)IsViewReportRequested
{
    return *(_is_view_report_requested);
}

- (NSMutableArray *)getTags
{
    
    NSMutableArray * JSONArray = [ NSMutableArray array ];
    
    for (NSDictionary * tag in _tags)
    {
        for (NSString* key in tag)
        {
            NSMutableDictionary<NSString *, NSString *> * _tag = [ [ NSMutableDictionary dictionary ] init ];
            [ _tag setObject : key forKey : @"name" ];
            [ _tag setObject : [ tag objectForKey : key ] forKey : @"value" ];
            
            [ JSONArray  setObject : _tag atIndexedSubscript : [ JSONArray count ] ];
        }
    }
    
    return JSONArray;
}

- (NSMutableDictionary *)getJSON
{
    NSDateFormatter *DATE_FORMAT = [ [ NSDateFormatter alloc] init ];
    [ DATE_FORMAT setDateFormat : @"YYYY-MM-dd\'T\'HH:mm:ss" ];
    
    NSMutableDictionary * JSONObject = [ NSMutableDictionary new ];
    
    if (_id != nil)
    {
        [ JSONObject setObject : _id forKey : @"message_id"  ];
    }
    
    if (_from_connection != nil)
    {
        [ JSONObject setObject : _from_connection forKey : @"from_connection" ];
    }
    
    if (_from_address != nil)
    {
        [ JSONObject setObject : _from_address forKey : @"from_address" ];
    }
    
    if (_from_station != nil)
    {
        [ JSONObject setObject : _from_station forKey : @"from_station" ];
    }
    
    if (_to_connection != nil)
    {
        [ JSONObject setObject : _to_connection forKey : @"to_connection" ];
    }
    
    if (_to_address != nil)
    {
        [ JSONObject setObject : _to_address forKey : @"to_address" ];
    }
    
    if (_to_station != nil)
    {
        [ JSONObject setObject : _to_station forKey : @"to_station" ];
    }
    
    if (_text != nil)
    {
        [ JSONObject setObject : _text forKey : @"text" ];
    }
    
    if (_create_date != nil)
    {
        NSString *create_date_formated = [DATE_FORMAT stringFromDate : _create_date ];
        
        [ JSONObject setObject : create_date_formated forKey : @"create_date" ];
    }
    
    if (_valid_until != nil)
    {
        NSString *valid_until_formated = [DATE_FORMAT stringFromDate : _valid_until ];
        
        [ JSONObject setObject : valid_until_formated forKey : @"valid_until" ];
    }
    
    if (_time_to_send != nil)
    {
        NSString *time_to_send_formated = [DATE_FORMAT stringFromDate : _time_to_send ];
        
        [ JSONObject setObject : time_to_send_formated forKey : @"time_to_send" ];
    }
    
    if (_is_submit_report_requested != nil)
    {
        [ JSONObject setValue : [ NSNumber numberWithBool: *(_is_submit_report_requested) ] forKey : @"is_submit_report_requested" ];
    }
    
    if (_is_delivery_report_requested != nil)
    {
        [ JSONObject setValue : [ NSNumber numberWithBool: *(_is_delivery_report_requested) ] forKey : @"is_delivery_report_requested" ];
    }
    
    if (_is_view_report_requested != nil)
    {
        [ JSONObject setValue : [ NSNumber numberWithBool: *(_is_view_report_requested) ] forKey : @"is_view_report_requested" ];
    }
    
    if ([ _tags count ] != 0)
    {
        [ JSONObject setObject : [ self getTags ] forKey : @"tags" ];
    }
    
    return JSONObject;
}

- (NSString *)description
{
    return [ NSString stringWithFormat : @"%@->%@ '%@'",  _from_address, _to_address, _text ];
}

@end

@implementation MessageSendResult
{
    Message * _message;
    NSInteger _status;
    NSString * _response_message;
}

- (instancetype) initWithMessage:(Message *)message DeliveryStatus:(NSInteger *)status ResponseMessage:(NSString *)response_message
{
    if ((self = [ super init ])) {
        _message = message;
        _status = * status;
        _response_message = response_message;
    }
    return self;
}

- (NSString *) description
{
    if (_status == 0)
    {
        return [ NSString stringWithFormat : @"%@, %@", @"Failed", _message ];
    }
    else
    {
        return [ NSString stringWithFormat : @"%@, %@", @"Success", _message ];
    }
}

- (Message *) message
{
    return _message;
}

- (NSString *) status
{
    if (_status == 1)
    {
        return @"Success";
    }
    else
    {
        return @"Failed";
    }
}

- (NSString *) responseMessage
{
    return _response_message;
}

@end

@implementation MessageSendResults
{
    NSMutableArray<MessageSendResult *> * _results;
    NSInteger _total_count;
    NSInteger _success_count;
    NSInteger _failed_count;
}

- (instancetype) initWithMessages:(NSMutableArray<MessageSendResult *> *)messages TotalCount:(NSInteger)total_count SuccessCount:(NSInteger)success_count FailedCount:(NSInteger)failed_count
{
    if (( self = [ super init ] ))
    {
        _results = messages;
        _total_count = total_count;
        _success_count = success_count;
        _failed_count = failed_count;
    }
    return self;
}

- (NSMutableArray<MessageSendResult *> *) results
{
    return _results;
}

- (NSString *) description
{
    return [ NSString stringWithFormat : @"Total: %ld. Success: %ld. Failed: %ld.",  _total_count, _success_count, _failed_count ];
}

- (NSInteger) totalCount
{
    return _total_count;
}

- (NSInteger) successCount
{
    return _success_count;
}

- (NSInteger) failedCount
{
    return _failed_count;
}

@end

@implementation MessageDeleteResult
{
    NSInteger _folder;
    NSMutableArray<NSString *> *_message_ids_remove_succeeded;
    NSMutableArray<NSString *> *_message_ids_remove_failed;
    NSInteger _total_count;
    NSInteger _success_count;
    NSInteger _failed_count;
}

- (instancetype) initWithFolder:(NSInteger)folder
{
    if (( self = [ super init ] ))
    {
        _folder = folder;
        _message_ids_remove_succeeded = [ NSMutableArray<NSString *> array ];
        _message_ids_remove_failed = [ NSMutableArray<NSString *> array ];
    }
    return self;
}

- (void) addMessageIdRemoveSucceeded:(NSString *)message_id
{
    [ _message_ids_remove_succeeded addObject : message_id ];
    _total_count += 1;
    _success_count += 1;
}

- (void) addMessageIdRemoveFailed:(NSString *)message_id
{
    [ _message_ids_remove_failed addObject : message_id ];
    _total_count += 1;
    _failed_count += 1;
}

- (NSMutableArray<NSString *> *) messageIdsRemoveSucceeded
{
    return _message_ids_remove_succeeded;
}

- (NSMutableArray<NSString *> *) messageIdsRemoveFailed
{
    return _message_ids_remove_failed;
}

- (NSString *) description
{
    return [ NSString stringWithFormat : @"Total: %ld. Success: %ld. Failed: %ld.",  _total_count, _success_count, _failed_count ];
}

@end

@implementation MessageMarkResult
{
    NSInteger _folder;
    NSMutableArray<NSString *> *_message_ids_mark_succeeded;
    NSMutableArray<NSString *> *_message_ids_mark_failed;
    NSInteger _total_count;
    NSInteger _success_count;
    NSInteger _failed_count;
}

- (instancetype) initWithFolder:(NSInteger)folder
{
    if (( self = [ super init ] ))
    {
        _folder = folder;
        _message_ids_mark_succeeded = [ NSMutableArray<NSString *> array ];
        _message_ids_mark_failed = [ NSMutableArray<NSString *> array ];
    }
    return self;
}

- (void) addMessageIdMarkSucceeded:(NSString *)message_id
{
    [ _message_ids_mark_succeeded addObject : message_id ];
    _total_count += 1;
    _success_count += 1;
}

- (void) addMessageIdMarkFailed:(NSString *)message_id
{
    [ _message_ids_mark_failed addObject : message_id ];
    _total_count += 1;
    _failed_count += 1;
}

- (NSMutableArray<NSString *> *) messageIdsMarkSucceeded
{
    return _message_ids_mark_succeeded;
}

- (NSMutableArray<NSString *> *) messageIdsMarkFailed
{
    return _message_ids_mark_failed;
}

- (NSString *) description
{
    return [ NSString stringWithFormat : @"Total: %ld. Success: %ld. Failed: %ld.",  _total_count, _success_count, _failed_count ];
}

@end

@implementation MessageReceiveResult
{
    NSMutableArray<Message *> * _messages;
    NSInteger * _folder;
    NSString * _limit;
}

- (instancetype) initWithFolder:(NSInteger *)folder Limit:(NSString *)limit
{
    if (( self = [ super init ] ))
    {
        _messages = [ NSMutableArray<Message *> array ];
        _folder = folder;
        _limit = limit;
    }
    return self;
}

- (void) addMessage:(Message *)message
{
    [ _messages addObject : message ];
}

- (NSMutableArray<Message *> *) messages
{
    return _messages;
}

- (NSString *) description
{
    return [ NSString stringWithFormat : @"Message count: %ld.", [ _messages count ] ];
}

@end

@implementation MessageApi
{
    Configuration * _configuration;
}

- (instancetype)initWithConfiguration:(Configuration *)Configuration
{
    if ((self = [ super init ])) {
        [ self setConfiguration : Configuration ];
    }
    return self;
}

- (void)setConfiguration:(Configuration *)Configuration
{
    _configuration = Configuration;
}

- (NSString *) createAuthorizationHeader:(NSString *)username password:(NSString *)password
{
    NSString * username_password = [ NSString stringWithFormat : @"%@:%@", username, password ];
    NSData * encode_data = [username_password dataUsingEncoding:NSUTF8StringEncoding];
    NSString * username_password_encoded  = [encode_data base64EncodedStringWithOptions : 0];
    return  [ NSString stringWithFormat : @"Basic %@", username_password_encoded ];
}

- (NSData *) createRequestBody:(NSArray *)messages
{
    NSMutableDictionary * JSONObject = [ NSMutableDictionary new ];
    
    NSMutableArray * JSONArray = [ NSMutableArray array ];
    
    for (Message* message in messages)
    {
        [ JSONArray addObject : [ message getJSON ]];
    }
    
    [ JSONObject setObject : JSONArray forKey : @"messages"];
    
    NSError * error;
    
    return [ NSJSONSerialization dataWithJSONObject : JSONObject options : kNilOptions error : &error ];
}

- (NSData *) createRequestBodyToManipulate:(NSMutableArray<Message *> *)messages Folder:(NSInteger)folder
{
    NSMutableDictionary * JSONObject = [ NSMutableDictionary new ];
    
    NSMutableArray<NSString *> * JSONArray = [ NSMutableArray<NSString *> array ];
    
    NSString * folder_name;
    
    switch (folder) {
        case 0:
            folder_name = @"inbox";
            break;
        case 1:
            folder_name = @"outbox";
            break;
        case 2:
            folder_name = @"sent";
            break;
        case 3:
            folder_name = @"notsent";
            break;
        case 4:
            folder_name = @"deleted";
            break;
        default:
            break;
    }
    
    [ JSONObject setObject : folder_name forKey : @"folder"];
    
    for (Message* message in messages)
    {
        [ JSONArray addObject : [ [ NSString alloc ] initWithFormat : @"%@", message.ID ] ];
    }
    
    [ JSONObject setObject : JSONArray forKey : @"message_ids"];
    
    NSError * error;
    
    return [ NSJSONSerialization dataWithJSONObject : JSONObject options : kNilOptions error : &error ];
}

- (MessageSendResults *)SendMessages:(NSMutableArray<Message *> *)messages
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBody: messages ];
    MessageSendResults * response = [ self getResponseSend: [ self do_request_post: [ self createURLToSendSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ]];
    return response;
}

- (MessageSendResult *)SendMessage:(Message *)message
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBody: [ [ NSArray alloc ] initWithObjects : message, nil ] ];
    MessageSendResult * response = [ self getResponseSend:  [ self do_request_post: [ self createURLToSendSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ] ].results[0];
    return response;
}

- (Boolean)DeleteMessage:(Message *)message Folder:(NSInteger)folder
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBodyToManipulate: [ [ NSMutableArray<Message *> alloc ] initWithObjects : message, nil ] Folder : folder ];
    MessageDeleteResult * response = [ self getResponseDelete :  [ self do_request_post: [ self createURLToDeleteSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ] Messages: [ [ NSMutableArray alloc ] initWithObjects : message, nil ] ];
    if ([ [ response messageIdsRemoveFailed ] count ] == 0 && [ [ response messageIdsRemoveSucceeded ] count ] == 1)
    { return true; } else { return false; }
}

- (MessageDeleteResult *)DeleteMessages:(NSMutableArray<Message *> *)messages Folder:(NSInteger)folder
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBodyToManipulate: messages Folder : folder ];
    MessageDeleteResult * response = [ self getResponseDelete :  [ self do_request_post: [ self createURLToDeleteSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ] Messages: messages ];
    return response;
}

- (Boolean)MarkMessage:(Message *)message Folder:(NSInteger)folder
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBodyToManipulate: [ [ NSMutableArray<Message *> alloc ] initWithObjects : message, nil ] Folder : folder ];
    MessageDeleteResult * response = [ self getResponseDelete :  [ self do_request_post: [ self createURLToMarkSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ] Messages: [ [ NSMutableArray alloc ] initWithObjects : message, nil ] ];
    if ([ [ response messageIdsRemoveFailed ] count ] == 0 && [ [ response messageIdsRemoveSucceeded ] count ] == 1)
    { return true; } else { return false; }
}

- (MessageDeleteResult *)MarkMessages:(NSMutableArray<Message *> *)messages Folder:(NSInteger)folder
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    NSData * request_body = [ self createRequestBodyToManipulate: messages Folder : folder ];
    MessageDeleteResult * response = [ self getResponseDelete :  [ self do_request_post: [ self createURLToMarkSMS : _configuration.ApiUrl ] RequestBody: request_body AuthorizationHeader : authorization_header ] Messages: messages ];
    return response;
}

- (MessageReceiveResult *) DownloadIncoming
{
    NSString * authorization_header = [ self createAuthorizationHeader : _configuration.Username password: _configuration.Password ];
    MessageReceiveResult * response = [ self getResponseReceive : [ self do_request_get:[ self createURLToReceiveSMS : _configuration.ApiUrl folder: Inbox ] AuthorizationHeader : authorization_header ] ];
    return response;
}

- (NSDictionary *) do_request_post:(NSURL *)url RequestBody:(NSData *)request_body AuthorizationHeader:(NSString *)authorization_header
{
    NSMutableURLRequest * request = [ [ NSMutableURLRequest alloc ] init ];
    
    [ request setHTTPMethod : @"POST" ];
    
    [ request setURL : url ];
    
    [ request addValue: authorization_header forHTTPHeaderField : @"Authorization" ];
    
    [ request addValue: @"application/json" forHTTPHeaderField : @"Content-Type" ];
    
    [ request addValue : [ NSString stringWithFormat : @"%ld", [ request_body length ] ] forHTTPHeaderField : @"Content-Length" ];
    
    [ request addValue: @"application/json" forHTTPHeaderField : @"Accept" ];
    
    [ request setHTTPBody : request_body ];
    
    NSError * error;
    
    NSData * response_data = [NSURLConnection sendSynchronousRequest : request returningResponse : nil error : &error ];
    
    NSMutableDictionary * parsed_response_data = [ NSJSONSerialization JSONObjectWithData: response_data options: NSJSONReadingMutableContainers error: &error ];

    return parsed_response_data;
}

- (NSDictionary *) do_request_get:(NSURL *)url AuthorizationHeader:(NSString *)authorization_header
{
    NSMutableURLRequest * request = [ [ NSMutableURLRequest alloc ] init ];
    
    [ request setHTTPMethod : @"GET" ];
    
    [ request setURL : url ];
    
    [ request addValue: authorization_header forHTTPHeaderField : @"Authorization" ];
            
    [ request addValue: @"application/json" forHTTPHeaderField : @"Accept" ];
        
    NSError * error;
    
    NSData * response_data = [NSURLConnection sendSynchronousRequest : request returningResponse : nil error : &error];
    
    NSMutableDictionary * parsed_response_data = [NSJSONSerialization JSONObjectWithData: response_data options: NSJSONReadingMutableContainers error: &error];
    
    return parsed_response_data;
}

- (NSURL *) createURLToSendSMS:(NSString *)url
{
    NSString * base_url = [ url componentsSeparatedByString : @"?" ][0];
    NSString * uri_to_send_sms = [ NSString stringWithFormat : @"%@?action=sendmsg", base_url ];
    return [ [ NSURL alloc ] initWithString : uri_to_send_sms ];
}

- (NSURL *) createURLToDeleteSMS:(NSString *)url
{
    NSString * base_url = [ url componentsSeparatedByString : @"?" ][0];
    NSString * uri_to_send_sms = [ NSString stringWithFormat : @"%@?action=deletemsg", base_url ];
    return [ [ NSURL alloc ] initWithString : uri_to_send_sms ];
}

- (NSURL *) createURLToMarkSMS:(NSString *)url
{
    NSString * base_url = [ url componentsSeparatedByString : @"?" ][0];
    NSString * uri_to_send_sms = [ NSString stringWithFormat : @"%@?action=markmsg", base_url ];
    return [ [ NSURL alloc ] initWithString : uri_to_send_sms ];
}

- (NSURL *) createURLToReceiveSMS:(NSString *)url folder:(NSInteger)folder
{
    NSString * base_url = [ url componentsSeparatedByString : @"?" ][0];
    
    NSString * folder_name;
    
    switch (folder) {
        case 0:
            folder_name = @"inbox";
            break;
        case 1:
            folder_name = @"outbox";
            break;
        case 2:
            folder_name = @"sent";
            break;
        case 3:
            folder_name = @"notsent";
            break;
        case 4:
            folder_name = @"deleted";
            break;
        default:
            break;
    }
    
    NSString * uri_to_send_sms = [ NSString stringWithFormat : @"%@?action=receivemsg&folder=%@", base_url, folder_name ];
    
    return [ [ NSURL alloc ] initWithString : uri_to_send_sms ];
}

- (NSString *)description
{
    return [ NSString stringWithFormat : @"%@",  _configuration ];
}

- (MessageSendResults *) getResponseSend:(NSDictionary *)response
{
    NSDateFormatter * DATE_FORMAT = [ [ NSDateFormatter alloc] init ];
    [ DATE_FORMAT setDateFormat : @"YYYY-MM-dd\'T\'HH:mm:ss" ];
    
    NSMutableArray<MessageSendResult *> * messages = [ NSMutableArray array ];
    
    for (NSDictionary * message in response[@"data"][@"messages"])
    {
        Message * msg = [ [ Message alloc ] init ];
        
        if ([ [ message allKeys ] containsObject : @"message_id" ])
        {
            [ msg setID : [ message objectForKey : @"message_id" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_connection" ])
        {
            [ msg setFromConnection : [ message objectForKey : @"from_connection" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_address" ])
        {
            [ msg setFromAddress : [ message objectForKey : @"from_address" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_station" ])
        {
            [ msg setFromStation : [ message objectForKey : @"from_station" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_connection" ])
        {
            [ msg setToConnection : [ message objectForKey : @"to_connection" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_address" ])
        {
            [ msg setToAddress : [ message objectForKey : @"to_address" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_station" ])
        {
            [ msg setToStation : [ message objectForKey : @"to_station" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"text" ])
        {
            [ msg setText : [ message objectForKey : @"text" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"create_date" ])
        {
            [ msg setCreateDate : [ DATE_FORMAT dateFromString : [ message objectForKey : @"create_date" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"valid_until" ])
        {
            [ msg setValidUntil : [ DATE_FORMAT dateFromString : [ message objectForKey : @"valid_until" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"time_to_send" ])
        {
            [ msg setTimeToSend : [ DATE_FORMAT dateFromString : [ message objectForKey : @"time_to_send" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"submit_report_requested" ])
        {
            [ msg setIsSubmitReportRequested : [ message objectForKey : @"submit_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"delivery_report_requested" ])
        {
            [ msg setIsDeliveryReportRequested : [ message objectForKey : @"delivery_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"view_report_requested" ])
        {
            [ msg setIsViewReportRequested : [ message objectForKey : @"view_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"tags" ] && [ [ message objectForKey : @"tags" ] count ] > 0)
        {
            for (NSDictionary * tag in [ message objectForKey : @"tags" ])
            {
                [ msg addTag : [ tag objectForKey: @"name" ] value : [ tag objectForKey : @"value" ] ];
            }
        }
        
        NSInteger status;
        NSString * response_message = @"";
        
        if ([message[@"status"]  isEqual: @"SUCCESS"])
        {
            status = Success;
        }
        else
        {
            status = Failed;
            response_message = message[@"status"];
            
        }
        
        MessageSendResult * message_send_result = [ [ MessageSendResult alloc ] initWithMessage : msg DeliveryStatus : &status  ResponseMessage : response_message ];
        
        [ messages addObject : message_send_result ];
    }
    
    
    return [ [ MessageSendResults alloc ] initWithMessages: messages TotalCount: [ response[@"data"][@"total_count"] intValue ]  SuccessCount: [ response[@"data"][@"success_count"] intValue ] FailedCount: [ response[@"data"][@"failed_count"] intValue ]  ];
}

- (MessageDeleteResult *) getResponseDelete:(NSDictionary *)response Messages:(NSMutableArray<Message *> *)messages
{
    NSInteger folder;
    
    if ([response[@"data"][@"folder"]  isEqual: @"inbox"])
    {
        folder = Inbox;
    }
    else
    {
        if ([response[@"data"][@"folder"]  isEqual: @"outbox"])
        {
            folder = Outbox;
        }
        else
        {
            if ([response[@"data"][@"folder"]  isEqual: @"sent"])
            {
                folder = Sent;
            }
            else
            {
                if ([response[@"data"][@"folder"]  isEqual: @"notsent"])
                {
                    folder = NotSent;
                }
                else
                {
                    folder = Deleted;
                }
            }
        }
    }
    
    MessageDeleteResult * result = [ [ MessageDeleteResult alloc ] initWithFolder : folder  ];
    
    for (Message * message in messages)
    {
        BOOL success = false;
        
        for (NSString * ID in response[@"data"][@"message_ids"])
        {
            if ([ message.ID isEqual : ID ])
            {
                success = true;
            }
        }
        if (success)
        {
            [ result addMessageIdRemoveSucceeded : message.ID];
        }
        else
        {
            [ result addMessageIdRemoveFailed : message.ID];
        }
    }
    
    
    return result;
}

- (MessageMarkResult *) getResponseMark:(NSDictionary *)response Messages:(NSMutableArray<Message *> *)messages
{
    NSInteger folder;
    
    if ([response[@"data"][@"folder"]  isEqual: @"inbox"])
    {
        folder = Inbox;
    }
    else
    {
        if ([response[@"data"][@"folder"]  isEqual: @"outbox"])
        {
            folder = Outbox;
        }
        else
        {
            if ([response[@"data"][@"folder"]  isEqual: @"sent"])
            {
                folder = Sent;
            }
            else
            {
                if ([response[@"data"][@"folder"]  isEqual: @"notsent"])
                {
                    folder = NotSent;
                }
                else
                {
                    folder = Deleted;
                }
            }
        }
    }
    
    MessageMarkResult * result = [ [ MessageMarkResult alloc ] initWithFolder : folder  ];
    
    for (Message * message in messages)
    {
        BOOL success = false;
        
        for (NSString * ID in response[@"data"][@"message_ids"])
        {
            if ([ message.ID isEqual : ID ])
            {
                success = true;
            }
        }
        if (success)
        {
            [ result addMessageIdMarkSucceeded : message.ID];
        }
        else
        {
            [ result addMessageIdMarkFailed : message.ID];
        }
    }
    
    
    return result;
}

- (MessageReceiveResult *) getResponseReceive:(NSDictionary *)response
{
    NSDateFormatter * DATE_FORMAT = [ [ NSDateFormatter alloc] init ];
    [ DATE_FORMAT setDateFormat : @"YYYY-MM-dd\'T\'HH:mm:ss" ];
    
    NSInteger folder;
    
    if ([response[@"data"][@"folder"]  isEqual: @"inbox"])
    {
        folder = Inbox;
    }
    else
    {
        if ([response[@"data"][@"folder"]  isEqual: @"outbox"])
        {
            folder = Outbox;
        }
        else
        {
            if ([response[@"data"][@"folder"]  isEqual: @"sent"])
            {
                folder = Sent;
            }
            else
            {
                if ([response[@"data"][@"folder"]  isEqual: @"notsent"])
                {
                    folder = NotSent;
                }
                else
                {
                    folder = Deleted;
                }
            }
        }
    }
    
    MessageReceiveResult * result = [ [ MessageReceiveResult alloc ] initWithFolder : &folder Limit : response[@"data"][@"limit"] ];
    
    for (NSDictionary * message in response[@"data"][@"data"])
    {
        Message * msg = [ [ Message alloc ] init ];
        
        if ([ [ message allKeys ] containsObject : @"message_id" ])
        {
            [ msg setID : [ [ [ NSString alloc ] initWithFormat : @"%@", [ message objectForKey : @"message_id" ] ] lowercaseString ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_connection" ])
        {
            [ msg setFromConnection : [ message objectForKey : @"from_connection" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_address" ])
        {
            [ msg setFromAddress : [ message objectForKey : @"from_address" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"from_station" ])
        {
            [ msg setFromStation : [ message objectForKey : @"from_station" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_connection" ])
        {
            [ msg setToConnection : [ message objectForKey : @"to_connection" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_address" ])
        {
            [ msg setToAddress : [ message objectForKey : @"to_address" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"to_station" ])
        {
            [ msg setToStation : [ message objectForKey : @"to_station" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"text" ])
        {
            [ msg setText : [ message objectForKey : @"text" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"create_date" ])
        {
            [ msg setCreateDate : [ DATE_FORMAT dateFromString : [ message objectForKey : @"create_date" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"valid_until" ])
        {
            [ msg setValidUntil : [ DATE_FORMAT dateFromString : [ message objectForKey : @"valid_until" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"time_to_send" ])
        {
            [ msg setTimeToSend : [ DATE_FORMAT dateFromString : [ message objectForKey : @"time_to_send" ] ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"submit_report_requested" ])
        {
            [ msg setIsSubmitReportRequested : [ message objectForKey : @"submit_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"delivery_report_requested" ])
        {
            [ msg setIsDeliveryReportRequested : [ message objectForKey : @"delivery_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"view_report_requested" ])
        {
            [ msg setIsViewReportRequested : [ message objectForKey : @"view_report_requested" ] ];
        }
        
        if ([ [ message allKeys ] containsObject : @"tags" ] && [ [ message objectForKey : @"tags" ] count ] > 0)
        {
            for (NSDictionary * tag in [ message objectForKey : @"tags" ])
            {
                [ msg addTag : [ tag objectForKey: @"name" ] value : [ tag objectForKey : @"value" ] ];
            }
        }
        
        [ result addMessage : msg ];
    }
    
    [ self DeleteMessages : result.messages Folder : Inbox ];
    
    return result;
}

@end


NS_ASSUME_NONNULL_END
