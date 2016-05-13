//
//  ESPIOTAddress.m
//  MeshProxy
//
//  Created by 白 桦 on 4/28/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import "ESPIOTAddress.h"

@implementation ESPIOTAddress


+ (ESPIOTAddress *)EmptyIOTAddress
{
    static dispatch_once_t predicate;
    static ESPIOTAddress *EmptyIOTAddress;
    dispatch_once(&predicate, ^{
        EmptyIOTAddress = [[ESPIOTAddress alloc]initWithBssid:nil InetAddress:nil];
    });
    return EmptyIOTAddress;
}

- (instancetype)init
{
    abort();
}

- (instancetype) initWithBssid:(NSString *)bssid InetAddress:(NSString *)inetAddress
{
    return [self initWithBssid:bssid InetAddress:inetAddress IsMeshDevice:NO];
}

- (instancetype) initWithBssid:(NSString *)bssid InetAddress:(NSString *)inetAddress IsMeshDevice:(BOOL)isMeshDevice
{
    self = [super init];
    if (self) {
        _bssid = bssid;
        _inetAddress = inetAddress;
        _isMeshDevice = isMeshDevice;
    }
    return self;
}

- (BOOL)isEqual:(id)object
{
    if (self == object) {
        return YES;
    }
    if (![object isKindOfClass:[ESPIOTAddress class]]) {
        return NO;
    }
    
    const ESPIOTAddress *other = object;
    if ([_deviceType isEqual:other.deviceType] && [_bssid isEqualToString:other.bssid]) {
        return YES;
    } else {
        return NO;
    }
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"bssid:%@,InetAddress:%@,DeviceType:%@,parentBssid:%@",_bssid,_inetAddress,_deviceType,_parentBssid];
}

- (NSUInteger)hash
{
    return [_bssid hash];
}

@end
