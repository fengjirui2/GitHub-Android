//
//  HYLoginViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYLoginViewController.h"
#import "MBProgressHUD+MJ.h"
#import "HYfmbdManager.h"
#define UserNameKey @"name"
#define PwdKey @"pwd"
#define RmbPwdKey @"rmb_pwd"

@interface HYLoginViewController ()
@property (weak, nonatomic) IBOutlet UITextField *nameField;
@property (weak, nonatomic) IBOutlet UITextField *pwdField;
@property (weak, nonatomic) IBOutlet UISwitch *rembSwitch;
@property (weak, nonatomic) IBOutlet UIButton *loginBtn;

- (IBAction)loginAction;
@end

@implementation HYLoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //注册通知，添加观察者
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textChange) name:UITextFieldTextDidChangeNotification object:self.nameField];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textChange) name:UITextFieldTextDidChangeNotification object:self.pwdField];
    
    //读取上次数据
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    self.nameField.text = [defaults stringForKey:UserNameKey];
    self.rembSwitch.on = [defaults valueForKey:RmbPwdKey];
    if (self.rembSwitch.isOn) {
        self.pwdField.text = [defaults stringForKey:PwdKey];
        self.loginBtn.enabled = YES;
    }
    
    //设置NavigationBar不可见
    [self.navigationController setNavigationBarHidden:YES];
}

-(void)textChange{
    //修改按钮的点击状态
    self.loginBtn.enabled = (self.nameField.text.length && self.pwdField.text.length);
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

- (IBAction)loginAction {
    
    HYfmbdManager *db;
    db =[HYfmbdManager shareManager];
    //数据库是否打开
    if (![db open]) {
        return;
    }
    //用户名密码是否正确
    if (![db searchUser:self.nameField.text password:self.pwdField.text]) {
        [MBProgressHUD showError:@"账号或密码不正确"];
        return;
    }
    
    //显示蒙板
    [MBProgressHUD showMessage:@"努力加载中"];
    //模拟两秒跳转
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //移除蒙板
        [MBProgressHUD hideHUD];
        [self performSegueWithIdentifier:@"LoginToMain" sender:nil];
    });
    
    //持久化数据
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:self.nameField.text forKey:UserNameKey];
    [defaults setObject:self.pwdField.text forKey:PwdKey];
    [defaults setBool:self.rembSwitch.isOn forKey:RmbPwdKey];
    
    //同步设置
    [defaults synchronize];
}
@end
