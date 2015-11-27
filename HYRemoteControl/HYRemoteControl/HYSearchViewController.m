//
//  HYSearchViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYSearchViewController.h"
#import "HYAdressInfo.h"
#import "HYfmbdManager.h"
#import "HYRecordTableViewCell.h"
#import <JuheApis/JuheAPI.h>
#import <JuheApis/JHOpenidSupplier.h>
#import <JuheApis/JHSDKAPIPath.h>
@interface HYSearchViewController ()
@property (copy, nonatomic) NSString *lngCnt;
@property (copy, nonatomic) NSString *latCnt;
@property (copy, nonatomic) NSString *addressCnt;
@property (weak, nonatomic) IBOutlet UITextField *cellField;
@property (weak, nonatomic) IBOutlet UITextField *lacField;
@property (weak, nonatomic) IBOutlet UITextField *telField;
@property (weak, nonatomic) IBOutlet UIButton *commitBtn;

- (IBAction)commitAction;
@end

@implementation HYSearchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //隐藏状态栏
    [self.navigationController setNavigationBarHidden:YES];
    
    //设置代理
    self.delegate = [self.tabBarController.viewControllers objectAtIndex:0];
    
    
    //注册通知，添加观察者
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textChange) name:UITextFieldTextDidChangeNotification object:self.cellField];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textChange) name:UITextFieldTextDidChangeNotification object:self.lacField];
    
    [[JHOpenidSupplier shareSupplier] registerJuheAPIByOpenId:@"JH932ece54de5ff5ef9f3676063ffc7ed2"];
}

-(void)viewDidAppear:(BOOL)animated{
    //成为第一响应者
    [self.cellField becomeFirstResponder];
}
- (void)textChange{
    self.commitBtn.enabled = self.cellField.text.length && self.lacField.text.length;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)commitAction{
    HYfmbdManager *db;
    db =[HYfmbdManager shareManager];
    if (![db open]) {
        return;
    }
    if (![db checkData:self.lacField.text cell:self.cellField.text]) {
        //关闭当前的视图控制器
        [self.navigationController popViewControllerAnimated:YES];
        return;
    }
    
    [self test:kJHAPIS_LBS_JZ_GSM parameters:@{@"lac":self.cellField.text , @"cell":self.lacField.text}];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)test:(NSString *)path  parameters:(NSDictionary *)parameters{
    JuheAPI *juheapi = [JuheAPI shareJuheApi];
    [juheapi executeWorkWithAPI:path
                     parameters:parameters
                        success:^(id responseObject){
                            if ([[parameters objectForKey:@"dtype"] isEqualToString:@"xml"]) {
                                NSLog(@"***xml*** \n %@", responseObject);
                            }else{
                                int error_code = [[responseObject objectForKey:@"error_code"] intValue];
                                if (!error_code) {
                                    NSLog(@" %@", responseObject);
                                    if ([responseObject isKindOfClass:[NSDictionary class]]){
                                        NSDictionary *dictionary = (NSDictionary *)responseObject;
                                        
                                        id data =[[[dictionary valueForKey:@"result"] valueForKey:@"data"] valueForKey:@"ADDRESS"];
                                        self.addressCnt = [data objectAtIndex:0];
                                        
                                        data =[[[dictionary valueForKey:@"result"] valueForKey:@"data"] valueForKey:@"O_LNG"];
                                        self.lngCnt = [data objectAtIndex:0];
                                        
                                        data =[[[dictionary valueForKey:@"result"] valueForKey:@"data"] valueForKey:@"O_LAT"];
                                        self.latCnt = [data objectAtIndex:0];
                                        
                                        //代理传
                                        if ([self.delegate respondsToSelector:@selector(addAdress:didAddAdress:)]) {
                                            HYAdressInfo *adressModel = [[HYAdressInfo alloc] init];
                                            adressModel.lacContent = self.lacField.text;
                                            adressModel.cellContent = self.cellField.text;
                                            adressModel.telContent = self.telField.text;
                                            adressModel.latContent = self.latCnt;
                                            adressModel.lngContent = self.lngCnt;
                                            adressModel.addressContent = self.addressCnt;
                                            
                                            [self.delegate addAdress:self didAddAdress:adressModel];
                                            self.tabBarController.selectedIndex = 0;
                                        }
                                    }
                                }else{
                                    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"小区号或基站号不正确" message:@"请检查小区号或基站号" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
                                    [alert show];
                                    NSLog(@" %@", responseObject);
                                }
                            }
                        }failure:^(NSError *error) {
                            NSLog(@"error:   %@",error.description);
                        }];
}

@end

