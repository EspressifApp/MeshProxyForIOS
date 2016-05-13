//
//  ESPLineReader.h
//  MeshProxy
//
//  Created by 白 桦 on 4/12/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESPLineReader : NSObject

/**
 * init ESPLineReader by data
 *
 * @param data data to be read
 * @return ESPLineReader
 */
- (id) initWithData: (NSData *)data;

/**
 * init ESPLineReader by NSString
 *
 * @param str String to be read
 * @return ESPLineReader
 */
- (id) initWithStr: (NSString *)str;

/**
 * read one line
 *
 * @return one line
 */
- (NSString *) readLine;

@end
