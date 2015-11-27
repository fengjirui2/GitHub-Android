//
//  HYSearchViewController.h
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import <UIKit/UIKit.h>
@class HYSearchViewController,HYAdressInfo;

@protocol HYSearchViewControllerDelegate <NSObject>

@optional
-(void) addAdress:(HYSearchViewController *) addVc didAddAdress:(HYAdressInfo *)adress;

@end
@interface HYSearchViewController : UIViewController

@property (nonatomic,weak) id<HYSearchViewControllerDelegate> delegate;
@end
