<b>ESPRSSIF MIT License</b>

Copyright © 2015 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>

Permission is hereby granted <b>for use on ESPRESSIF SYSTEMS ESP8266 only, in which case, it is free of charge,</b> to any person obtaining a copy of this software and 
associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

<b>乐鑫 MIT 许可证</b>

版权 © 2015  <乐鑫信息科技（上海）有限公司>

<b>该许可证授权仅限于乐鑫信息科技 ESP8266 产品的应用开发。</b>在此情况下，该许可证免费授权任何获得该软件及其相关文档（统称为“软件”）的人无限制地经营该软件，包括无限制
的使用、复制、修改、合并、出版发行、散布、再授权、及贩售软件及软件副本的权利。被授权人在享受这些权利的同时，需服从下面的条件：

在软件和软件的所有副本中都必须包含以上的版权声明和授权声明。

该软件按本来的样子提供，没有任何明确或暗含的担保，包括但不仅限于关于试销性、适合某一特定用途和非侵权的保证。作者和版权持有人在任何情况下均不就由软件或软件使用引起的以合同形式、民事侵权或其它方式提出的任何索赔、损害或其它责任负责。
==================================v1.0.2==================================

1. optimize some method name

2. Usage:

   The same as v1.0.1

==================================v1.0.1==================================

1. fix some bugs

2. Usage:

   The same as v1.0.0

==================================v1.0.0==================================

1. Support iOS 6.0 above

2. Espressif's mesh version v1.2.0 is supported

3. The header file of API is esp_base_api/ESPBaseApiUtil.h 

4. The framework of the lib are as follows:

   esp_type: the base type of Espressif's IOT devices

   esp_base_api: the entrance of base API

   esp_core: the core lib used by Espressif's iOS App Team 

   esp_net:  the net related files are in here

   esp_socket: the bridge between unix socket and Objective-c including TCP and UDP

5. Usage:

   (1) open mesh proxy when app is launched:

       [[ESPProxyServer sharedProxyServer]start];

   (2) get all devices in the same AP:

       NSArray *deviceArray = [ESPBaseApiUtil discoverDevices];

   (3) send http request to mesh device via mesh proxy:
       
       ESPIOTAddress *iotAddress = [deviceArray objectAtIndex:0];

       NSString *bssid = [iotAddress bssid];

       NSString *inetAddress = [iotAddress inetAddress];

       NSString *url = [NSString stringWithFormat:@"http://%@/config?command=light",inetAddress];

       NSDictionary *headers = nil;

       NSDictionary *result = [ESPBaseApiUtil GetForJson:url Bssid:bssid Headers:headers];

   (4) close mesh proxy when app is terminated(it is usually unnecessary to close it explicitly):

       [[ESPProxyServer sharedProxyServer]stop];

6. <b>Last But not Least: </b>

   <b>Don't forget to add "App Transport Security Settings" in Info.plist and add key/value "Allow Arbitrary Loads"/YES</b>

   For Espressif's IOT device only support http instead of https at present
