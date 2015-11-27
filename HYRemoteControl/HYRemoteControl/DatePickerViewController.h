//
//  DatePickerViewController.h
//  HYRemoteControl
//
//  Created by MacHY02 on 15/11/24.
//  Copyright © 2015年 hyet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
@interface DatePickerViewController : UIViewController<MFMessageComposeViewControllerDelegate>
@property(nonatomic,copy) NSString *telephone;
@property(nonatomic,copy) NSString *messageBody;

@end
