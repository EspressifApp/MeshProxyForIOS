//
//  ESPIOTAddress.h
//  MeshProxy
//
//  Created by 白 桦 on 4/28/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESPDeviceType.h"

@interface ESPIOTAddress : NSObject

// device's ssid
@property (nonatomic, strong) NSString *ssid;
// the root device's bssid(only mesh device has root device)
@property (nonatomic, strong) NSString *rootBssid;
// device's bssid
@property (nonatomic, strong) NSString *bssid;
// device's inetAddress
@property (nonatomic, strong) NSString *inetAddress;
// device's type
@property (nonatomic, strong) ESPDeviceType *deviceType;
// device's parent's bssid
@property (nonatomic, strong) NSString *parentBssid;
// whether the device is mesh or not
@property (nonatomic, assign) BOOL isMeshDevice;

+ (ESPIOTAddress *)EmptyIOTAddress;

- (instancetype) initWithBssid:(NSString *)bssid InetAddress:(NSString *)inetAddress;

- (instancetype) initWithBssid:(NSString *)bssid InetAddress:(NSString *)inetAddress IsMeshDevice:(BOOL)isMeshDevice;

@end
