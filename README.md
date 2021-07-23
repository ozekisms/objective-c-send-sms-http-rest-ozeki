# objective-c-send-sms-http-rest-ozeki
 
### How to use the Ozeki.Libs.Rest library

In order to use the __Ozeki.Libs.Rest library__ in your own project, you need to place the __Ozeki.Libs.Rest.h__ and the __Ozeki.Libs.Rest.m__ files in your project.
After you've placed these two files _(what you can download from this github repository, together with 5 example projects)_, you can import it with this line:

```objective-c
import "Ozeki.Libs.Rest.h"
```
When you imported the header file, you are ready to use the __Ozeki.Libs.Rest library__, to send, mark, delete and receive SMS messages.

#### Creating a Configuration

To send your SMS message to the built in API of the __Ozeki SMS Gateway__, your client application needs to know the details of your __Gateway__ and the __http_user__.
We can define a __Configuration__ instance with these lines of codes in Objective-C.

```objective-c
Configuration * configuration = [ [ Configuration alloc ] init ];
[ configuration setUsername : @"http_user" ];
[ configuration setPassword : @"qwe123" ];
[ configuration setApiUrl : @"http://127.0.0.1:9509" ];
```

#### Creating a Message

After you have initialized your configuration object you can continue by creating a Message object.
A message object holds all the needed data for message what you would like to send.
In Objective-C we create a __Message__ instance with the following lines of codes:

```objective-c
Message * msg = [ [ Message alloc ] init ];
[ msg setToAddress : @"+36201111111" ];
[ msg setText : @"Hello world!" ];
```

#### Creating a MessageApi

You can use the __MessageApi__ class of the __Ozeki.Libs.Rest library__ to create a __MessageApi__ object which has the methods to send, delete, mark and receive SMS messages from the Ozeki SMS Gateway.
To create a __MessageApi__, you will need these lines of codes and a __Configuration__ instance.

```objective-c
MessageApi * api = [ [ MessageApi alloc ] initWithConfiguration : configuration ];
```

After everything is ready you can begin with sending the previously created __Message__ object:

```objective-c
MessageSendResult * result = [ api SendMessage : msg ];

NSLog(@"%@", result);
```

After you have done all the steps, you check the Ozeki SMS Gateway and you will see the message in the _Sent_ folder of the __http_user__.
