//
//  HYMainViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYMainViewController.h"

@interface HYMainViewController ()
@property (weak, nonatomic) IBOutlet UILabel *lblURL;
@property (weak, nonatomic) IBOutlet UILabel *lblTel;
@end

@implementation HYMainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //隐藏状态栏
    [self.navigationController setNavigationBarHidden:YES];
    // Do any additional setup after loading the view.
    UITapGestureRecognizer *tapGesture1 = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(clickURL:)];
    self.lblURL.userInteractionEnabled = YES;
    [self.lblURL addGestureRecognizer:tapGesture1];
    
    UITapGestureRecognizer *tapGesture2 = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(clickTel:)];
    self.lblTel.userInteractionEnabled = YES;
    [self.lblTel addGestureRecognizer:tapGesture2];
    
    [self.view bringSubviewToFront:self.lblTel];
    [self.view bringSubviewToFront:self.lblURL];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

-(void)clickURL:(id)sender{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:self.lblURL.text]];
}

-(void)clickTel:(id)sender{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"tel://40008118910"]];
}
@end
