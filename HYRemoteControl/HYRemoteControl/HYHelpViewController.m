//
//  HYHelpViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYHelpViewController.h"

@interface HYHelpViewController ()

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@end

@implementation HYHelpViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //隐藏状态栏
    [self.navigationController setNavigationBarHidden:YES];
    
    // Do any additional setup after loading the view.
    CGFloat imgW = self.scrollView.frame.size.width;
    CGFloat imgH = self.scrollView.frame.size.height;
    CGFloat imgY = 0;
    CGFloat imgX;
    for (int i = 0; i<4; i++) {
        UIImageView *imgView = [[UIImageView alloc]init];
        imgX = i * imgW;
        imgView.frame = CGRectMake(imgX, imgY, imgW, imgH);
        NSString *imgName = [NSString stringWithFormat:@"hy_sgms_%02d",i+1];
        UIImage *img = [UIImage imageNamed:imgName];
        imgView.image = img;
        
        [self.scrollView addSubview:imgView];
    }
    
    CGFloat scrollW = self.scrollView.frame.size.width * 4;
    self.scrollView.contentSize = CGSizeMake(scrollW, 0);
    
    self.scrollView.pagingEnabled = YES;
    
    self.scrollView.showsHorizontalScrollIndicator = NO;
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

@end
