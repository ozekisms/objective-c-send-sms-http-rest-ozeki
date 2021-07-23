#import <Foundation/Foundation.h>
#import "../../Ozeki.Libs.Rest_header_only/Ozeki.Libs.Rest.h"
 
int main(int argc, const char * argv[]) {
    Configuration * configuration = [ [ Configuration alloc ] init ];
    [ configuration setUsername : @"http_user" ];
    [ configuration setPassword : @"qwe123" ];
    [ configuration setApiUrl : @"http://192.168.0.14:9509/api" ];
     
    Message * msg = [ [ Message alloc ] init ];
    [ msg setID : @"77edf5e7-691f-4328-a0ce-80402a44cea1" ];
     
    MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
     
    Boolean result = [ api DeleteMessage : msg Folder : Inbox ];
     
    NSLog(@"%hhu", result);
     
    return 0;
}
