//
//  HYRemoteViewController.h
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-16.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "HYAdressInfo.h"

@interface HYRemoteViewController : UIViewController<MFMailComposeViewControllerDelegate>
@property(nonatomic,strong) HYAdressInfo *addressModel;
@end
