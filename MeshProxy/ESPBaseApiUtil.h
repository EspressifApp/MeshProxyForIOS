//
//  ESPBaseApiUtil.h
//  MeshProxy
//
//  Created by 白 桦 on 4/25/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESPIOTAddress.h"

@interface ESPBaseApiUtil : NSObject

/**
 * execute GET to get dictionary of json by Mesh Net
 *
 * @param url the url NSString
 * @param bssid the bssid of the device
 * @param headers the dictionary of header
 * @return the result of json dictionary
 */
+ (NSDictionary *) GetForJson:(NSString *)url Bssid:(NSString *)bssid Headers:(NSDictionary *)headers;

/**
 * execute POST to get dictionary of json by Mesh Net
 *
 *
 */
+ (NSDictionary *) PostForJson:(NSString *)url Bssid:(NSString *)bssid Json:(NSDictionary *)json Headers:(NSDictionary *)headers;

/**
 * discover the devices on the same AP or in the mesh net which root mesh device is on the same AP
 *
 * @return the array of IOTAddress
 */
+ (NSArray *) discoverDevices;

/**
 * discover the specific device on the same AP or in the mesh which root mesh device is on the same AP by its bssid
 *
 * @param bssid the specific device's bssid
 * @return ESPIOTAddress
 */
+ (ESPIOTAddress *) discoverDevice:(NSString *)bssid;

@end
