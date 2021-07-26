# objective-c-send-sms-http-rest-ozeki

This objective c sms library enables you to **send sms** from Objective C. The library uses HTTP Post requests and JSON encoded content to send the text messages to the mobile network1. It connects to the HTTP SMS API of [Ozeki SMS gateway](https://ozeki-sms-gateway.com).

## What is Ozeki SMS Gateway

Ozeki SMS Gateway is a powerful SMS Gateway software you can download and install on your Windows or Linux computer or to your Android mobile phone. 
It offers a very intuitive graphical interface to make using it easier. Your data is in safe hands, becasue 
i runs locally on your computer.You can use the gateway to manage your SMS costs and keep track of your SMS traffic while recording a log of every event. 
This software offers you service provider independence and it works in any country in the world.

Download: [Ozeki SMS Gateway download page](https://ozeki-sms-gateway.com/p_727-download-sms-gateway.html)

Tutorial: [Objective C send sms sample and tutorial](https://ozeki-sms-gateway.com/p_855-objective-c-send-sms-with-the-http-rest-api-code-sample.html)

## How to send sms from Objective C:

**To send sms from Objective C**
1. [Download Ozeki SMS Gateway](https://ozeki-sms-gateway.com/p_727-download-sms-gateway.html)
2. [Connect Ozeki SMS Gateway to the mobile network](https://ozeki-sms-gateway.com/p_70-mobile-network.html)
3. [Create an HTTP SMS API user](https://ozeki-sms-gateway.com/p_2102-create-an-http-sms-api-user-account.html)
4. Setup Xcode
5. Checkout the Github send SMS from Objective C repository
6. Download then extract the SendSms.m.zip file
7. Open the SendSms.xcodeproj file in Xcode
8. Launch Ozeki SMS Gateway app on your Windows machine
9. Run SendSms.m Objective C code in Xcode
10. Check the logs to see if the SMS sent

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

## Manual / API reference
To understand the **example code**, it is a good idea to visit the tutorial page where you can find videos, explanations and downloadable content which will help you.

Link: [How to send sms from Objective C](https://ozeki-sms-gateway.com/p_855-objective-c-send-sms-with-the-http-rest-api-code-sample.html)

## How to send sms through your Android mobile phone
If you wish to [send SMS through your Android mobile phone from Objcetive C](https://android-sms-gateway.com/), you need to [install Ozeki SMS Gateway on your Android](https://ozeki-sms-gateway.com/p_2847-how-to-install-ozeki-sms-gateway-on-android.html) mobile phone. It is recommended to use an Android mobile phone with a minimum of 4GB RAM and a quad core CPU. Most devices today meet these specs. The advantage of using your mobile, is that it is quick to setup and it often allows you to [send sms free of charge](https://android-sms-gateway.com/p_246-how-to-send-sms-free-of-charge.html).
[Android SMS Gateway](https://android-sms-gateway.com)

## Get started now

Stop wasting time, let's start sending SMS!

