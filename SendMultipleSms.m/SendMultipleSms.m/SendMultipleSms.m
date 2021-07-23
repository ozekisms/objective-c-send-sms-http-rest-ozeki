#import <Foundation/Foundation.h>
#import "../../Ozeki.Libs.Rest_header_only/Ozeki.Libs.Rest.h"

int main(int argc, const char * argv[]) {
    Configuration * configuration = [ [ Configuration alloc ] init];
    [ configuration setUsername : @"http_user" ];
    [ configuration setPassword : @"qwe123" ];
    [ configuration setApiUrl : @"http://192.168.0.14:9509/api" ];
    
    MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
    
    Message * msg1 = [ [ Message alloc ] init ];
    [ msg1 setToAddress : @"+36201111111" ];
    [ msg1 setText : @"Hello world 1" ];
    
    Message * msg2 = [ [ Message alloc ] init ];
    [ msg2 setToAddress : @"+36202222222" ];
    [ msg2 setText : @"Hello world 2" ];
    
    Message * msg3 = [ [ Message alloc ] init ];
    [ msg3 setToAddress : @"+36203333333" ];
    [ msg3 setText : @"Hello world 3" ];
    
    NSMutableArray<Message *> * messages = [ [ NSMutableArray<Message *> alloc ] initWithObjects: msg1, msg2, msg3, nil ];
    
    MessageSendResults * result = [ api SendMessages: messages ];
    
    NSLog(@"%@", result);
    
    return 0;
}
