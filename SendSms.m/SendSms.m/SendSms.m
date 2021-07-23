#import <Foundation/Foundation.h>
#import "../../Ozeki.Libs.Rest_header_only/Ozeki.Libs.Rest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Configuration * configuration = [ [ Configuration alloc ] init ];
        [ configuration setUsername : @"http_user" ];
        [ configuration setPassword : @"qwe123" ];
        [ configuration setApiUrl : @"http://192.168.0.14:9509/api" ];
        
        Message * msg = [ [ Message alloc ] init ];
        [ msg setToAddress : @"+36201111111" ];
        [ msg setText : @"Hello world!" ];
        
        MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
        
        MessageSendResult * result = [ api SendMessage : msg ];
        
        NSLog(@"%@", result);
    }
    return 0;
}
