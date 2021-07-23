#import <Foundation/Foundation.h>
#import "../../Ozeki.Libs.Rest_header_only/Ozeki.Libs.Rest.h"

int main(int argc, const char * argv[]) {
    Configuration * configuration = [ [ Configuration alloc ] init];
    [ configuration setUsername : @"http_user" ];
    [ configuration setPassword : @"qwe123" ];
    [ configuration setApiUrl : @"http://192.168.0.14:9509/api" ];
    
    MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
    
    MessageReceiveResult * result = [ api DownloadIncoming ];
    
    NSLog(@"%@", result);
    
    for (Message * message in result.messages)
    {
        NSLog(@"%@", message);
    }
    
    return 0;
}
