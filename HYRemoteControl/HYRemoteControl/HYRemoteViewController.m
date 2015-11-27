//
//  HYRemoteViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-16.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYRemoteViewController.h"
#import "DatePickerViewController.h"

@interface HYRemoteViewController ()
- (IBAction)openAction;
- (IBAction)closeAction;
- (IBAction)openTimeAction;
- (IBAction)openScondAction;
- (IBAction)singleAction;
- (IBAction)doubleAction;
- (IBAction)setTelephoneAction;
@property (weak, nonatomic) IBOutlet UIButton *openBtn;

@property (weak, nonatomic) IBOutlet UILabel *numId;
@property (weak, nonatomic) IBOutlet UILabel *cell;
@property (weak, nonatomic) IBOutlet UILabel *lac;
@property (weak, nonatomic) IBOutlet UILabel *lng;
@property (weak, nonatomic) IBOutlet UILabel *lat;
@property (weak, nonatomic) IBOutlet UILabel *telephone;
@property (weak, nonatomic) IBOutlet UILabel *address;
@property (copy, nonatomic) NSString *messageBody;
@end

@implementation HYRemoteViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //设置NavigationBar不可见
    [self.navigationController setNavigationBarHidden:YES];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    self.numId.text = self.addressModel.numContent;
    self.cell.text = self.addressModel.cellContent;
    self.lac.text = self.addressModel.lacContent;
    self.lng.text = self.addressModel.lngContent;
    self.lat.text = self.addressModel.latContent;
    self.telephone.text = self.addressModel.telContent;
    self.address.text = self.addressModel.addressContent;
    [self.navigationController setNavigationBarHidden:NO];
}


- (void)showMessageView
{
    
    if( [MFMessageComposeViewController canSendText] ){
        
        MFMessageComposeViewController * controller = [[MFMessageComposeViewController alloc]init]; //autorelease];
        
        controller.recipients = [NSArray arrayWithObject:self.telephone.text];
        controller.body = self.messageBody;
        controller.messageComposeDelegate = self;
        
        [self presentViewController:controller animated:YES completion:nil];
        
        [[[[controller viewControllers] lastObject] navigationItem] setTitle:@"测试短信"];//修改短信界面标题
    }else{
        
        [self alertWithTitle:@"提示信息" msg:@"设备没有短信功能"];
    }
}


//MFMessageComposeViewControllerDelegate

- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result{
    [controller dismissViewControllerAnimated:NO completion:nil];
    
    switch ( result ) {
            
        case MessageComposeResultCancelled:
            
            [self alertWithTitle:@"提示信息" msg:@"发送取消"];
            break;
        case MessageComposeResultFailed:// send failed
            [self alertWithTitle:@"提示信息" msg:@"发送成功"];
            break;
        case MessageComposeResultSent:
            [self alertWithTitle:@"提示信息" msg:@"发送失败"];
            break;
        default:
            break;
    }
}


- (void) alertWithTitle:(NSString *)title msg:(NSString *)msg {
    
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                    message:msg
                                                   delegate:self
                                          cancelButtonTitle:nil
                                          otherButtonTitles:@"确定", nil];
    
    [alert show];
    
}



/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)openAction {
    self.messageBody = [NSString stringWithFormat:@"+CMT:%@,C\r",self.telephone.text];
    [self showMessageView];
}

- (IBAction)closeAction {
    self.messageBody = [NSString stringWithFormat:@"+CMT:%@,S\r",self.telephone.text];
    [self showMessageView];
}

- (IBAction)openTimeAction {
    DatePickerViewController *dataPicker = [[DatePickerViewController alloc]init];
    dataPicker.telephone = self.telephone.text;
    [self.navigationController pushViewController:dataPicker animated:YES];
}

- (IBAction)openScondAction {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"开机次数" message:@"请输入开机次数。" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *concelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *OkAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        UITextField *temField = [[alert textFields] lastObject];
        self.messageBody = [NSString stringWithFormat:@"+CMT:%@,F%@\r",self.telephone.text,temField.text];
        [self showMessageView];
    }];
    [alert addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        [textField becomeFirstResponder];
        textField.keyboardType = UIKeyboardTypeNumberPad;
    }];
    
    [alert addAction:concelAction];
    [alert addAction:OkAction];
    
    [self presentViewController:alert animated:YES completion:nil];
}

- (IBAction)singleAction {
    self.messageBody = [NSString stringWithFormat:@"+CMT:%@,D\r",self.telephone.text];
    [self showMessageView];
}

- (IBAction)doubleAction {
    self.messageBody = [NSString stringWithFormat:@"+CMT:%@,E\r",self.telephone.text];
    [self showMessageView];
}

- (IBAction)setTelephoneAction {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"绑定手机" message:@"请输入要绑定的手机号。" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *concelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *OkAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        UITextField *temField = [[alert textFields] lastObject];
        self.messageBody = [NSString stringWithFormat:@"+CMT:%@,H%@\r",self.telephone.text,temField.text];
        [self showMessageView];
    }];
    [alert addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        [textField becomeFirstResponder];
        textField.keyboardType = UIKeyboardTypeNumberPad;
    }];
    
    [alert addAction:concelAction];
    [alert addAction:OkAction];
    
    [self presentViewController:alert animated:YES completion:nil];
}
@end
