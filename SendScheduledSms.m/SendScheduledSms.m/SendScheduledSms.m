#import <Foundation/Foundation.h>
#import "../../Ozeki.Libs.Rest_header_only/Ozeki.Libs.Rest.h"

int main(int argc, const char * argv[]) {
    Configuration * configuration = [ [ Configuration alloc ] init];
    [ configuration setUsername : @"http_user" ];
    [ configuration setPassword : @"qwe123" ];
    [ configuration setApiUrl : @"http://192.168.0.14:9509/api" ];
    
    MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
    
    Message * msg = [ [ Message alloc ] init ];
    [ msg setToAddress : @"+36201111111" ];
    [ msg setText : @"Hello world!" ];
    
    NSDateFormatter * dateFormat = [ [ NSDateFormatter alloc ] init ];
    [ dateFormat setDateFormat : @"yyyy-MM-dd HH:mm:ss" ];
    
    [ msg setTimeToSend: [ dateFormat dateFromString : @"2021-07-23 10:00:00" ] ] ;
    
    MessageSendResult * result = [ api SendMessage : msg ];
    
    NSLog(@"%@", result);
    
    return 0;
}
