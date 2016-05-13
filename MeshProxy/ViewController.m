//
//  ViewController.m
//  MeshProxy
//
//  Created by 白 桦 on 5/13/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import "ViewController.h"
#import "ESPProxyServer.h"
#import "ESPBaseApiUtil.h"
#import "ESPIOTAddress.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [[ESPProxyServer sharedProxyServer]start];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)tapTestBtn:(id)sender {
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        NSArray *deviceArray = [ESPBaseApiUtil discoverDevices];
        NSUInteger deviceCount = [deviceArray count];
        if (deviceCount==0) {
            NSLog(@"ViewController no devices available");
        } else {
            NSLog(@"ViewController discover %d devices",(int)deviceCount);
            ESPIOTAddress *iotAddress = [deviceArray objectAtIndex:0];
            NSString *bssid = [iotAddress bssid];
            
            NSString *inetAddress = [iotAddress inetAddress];
            
            NSString *url = [NSString stringWithFormat:@"http://%@/config?command=light",inetAddress];
            
            NSDictionary *headers = nil;
            
            NSDictionary *result = [ESPBaseApiUtil GetForJson:url Bssid:bssid Headers:headers];
            
            NSLog(@"ViewController result is %@",result);
        }
    });
}

@end
