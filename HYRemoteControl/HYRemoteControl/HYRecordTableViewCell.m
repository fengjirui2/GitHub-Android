//
//  HYRecordTableViewCell.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-14.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYRecordTableViewCell.h"
#import "HYAdressInfo.h"
@interface HYRecordTableViewCell ()

@end
@implementation HYRecordTableViewCell

-(void)setAddressInfo:(HYAdressInfo *)address{
    _addressInfo = address;
    self.lacLable.text = address.lacContent == nil ? @"" : address.lacContent;
    self.cellLable.text = address.cellContent == nil ? @"" : address.cellContent ;
    self.lngLable.text = address.lngContent == nil ? @"" : address.lngContent;
    self.latLable.text = address.latContent == nil ? @"" : address.latContent;
    self.adressLable.text = address.addressContent == nil ? @"" : address.addressContent;
    self.telLable.text = address.telContent == nil ? @"" : address.telContent;
    self.numLable.text = address.numContent == nil ? @"" : address.numContent;
}
- (IBAction)telUpdate:(id)sender {
    if ([self.delegate respondsToSelector:@selector(updateTel:)]) {
        [self.delegate updateTel:self];
    }
}

- (void)awakeFromNib {
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
