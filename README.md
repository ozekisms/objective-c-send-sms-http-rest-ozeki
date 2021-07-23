# objective-c-send-sms-http-rest-ozeki
 Objective C send SMS with Ozeki SMS Gateway
 
### How to use the Ozeki.Libs.Rest library

In order to use the Ozeki.Libs.Rest library in your own project, you need to place the Ozeki.Libs.Rest.h and the Ozeki.Libs.Rest.m files in your project.
After you've placed these two files (what you can download from this github repository, together with 5 example projects), you can import it with this line:

```objective-c
import "Ozeki.Libs.Rest.h"
```
When you imported the header file, you are ready to use the Ozeki.Libs.Rest library, to send, mark, delete and receive SMS messages.

#### Creating a Configuration

To send your SMS message to the built in API of the Ozeki SMS Gateway, your client application needs to know the details of your Gateway and the http_user.
We can define a configuration instance with these lines of codes in Objective-C.

```objective-c
Configuration * configuration = [ [ Configuration alloc ] init ];
[ configuration setUsername : @"http_user" ];
[ configuration setPassword : @"qwe123" ];
[ configuration setApiUrl : @"http://127.0.0.1:9509" ];
```

#### Creating a Message

After you have initialized your configuration object you can continue by creating a Message object.
A message object holds all the needed data for message what you would like to send.
In Objective-C we create a Message instance with the following lines of codes:

```objective-c
Message * msg = [ [ Message alloc ] init ];
[ msg setToAddress : @"+36201111111" ];
[ msg setText : @"Hello world!" ];
```

#### Creating a MessageApi

You can use the MessageApi class of the Ozeki.Libs.Rest library to create a MessageApi object which has the methods to send, delete, mark and receive SMS messages from the Ozeki SMS Gateway.
To create a MessageApi, you will need these lines of codes and a Configuration instance.

```objective-c
MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
```

After everything is ready you can begin with sending the previously created SMS:

```objective-c
MessageSendResult * result = [ api SendMessage : msg ];

NSLog(@"%@", result);
```

After you have done all the steps, you check the Ozeki SMS Gateway and you will see the message in the _Sent_ folder of the http_user.
