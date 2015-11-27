//
//  HYRecordTableViewCell.h
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-14.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HYRecordTableViewCell,HYAdressInfo;
@protocol HYRecordTableViewCellDelegate <NSObject>

@optional
-(void) updateTel:(HYRecordTableViewCell *)cell;

@end
@interface HYRecordTableViewCell : UITableViewCell

@property (nonatomic,weak) id<HYRecordTableViewCellDelegate>delegate;

@property (nonatomic,strong) HYAdressInfo *addressInfo;
@property (weak, nonatomic) IBOutlet UILabel *lacLable;
@property (weak, nonatomic) IBOutlet UILabel *cellLable;
@property (weak, nonatomic) IBOutlet UILabel *lngLable;
@property (weak, nonatomic) IBOutlet UILabel *latLable;
@property (weak, nonatomic) IBOutlet UILabel *adressLable;
@property (weak, nonatomic) IBOutlet UILabel *telLable;
@property (weak, nonatomic) IBOutlet UILabel *numLable;

@property (assign,nonatomic) NSInteger tagId;
@end
