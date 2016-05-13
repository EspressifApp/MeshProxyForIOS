//
//  ESPDeviceType.h
//  MeshProxy
//
//  Created by 白 桦 on 4/28/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import <Foundation/Foundation.h>

enum ESPDeivceTypeEnum
{
    NEW,
    ROOT,
    PLUG,
    LIGHT,
    HUMITURE,
    FLAMMABLE,
    VOLTAGE,
    REMOTE,
    PLUGS
};

typedef enum ESPDeivceTypeEnum ESPDeviceTypeEnum;

@interface ESPDeviceType : NSObject

@property (nonatomic, assign) int serial;
@property (nonatomic, assign) BOOL isLocalSupport;

- (instancetype)initWithSerial:(int) serial TypeName:(NSString *) typeName IsLocalSupport:(BOOL) isLocalSupport;

- (ESPDeviceTypeEnum)typeEnum;

+ (ESPDeviceType *)resolveDeviceTypeBySerial:(int) serial;

+ (ESPDeviceType *)resolveDeviceTypeByTypeName:(NSString *) typeName;

@end
