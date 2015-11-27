//
//  HYRecordTableViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYRecordTableViewController.h"
#import "HYAdressInfo.h"
#import "HYRecordTableViewCell.h"
#import "HYfmbdManager.h"
#import "HYSearchViewController.h"
#import "HYDeviceLocationViewController.h"
@interface HYRecordTableViewController ()<HYRecordTableViewCellDelegate,HYSearchViewControllerDelegate>

@property (nonatomic,strong) HYfmbdManager *db;
@property (nonatomic,assign) NSInteger selectRowIndex;
@property (nonatomic,strong) UIView *bgColorView;
@property (nonatomic,strong) NSMutableArray *recordArr;

- (IBAction)backAction:(id)sender;

@end

@implementation HYRecordTableViewController


-(NSMutableArray *)recordArr{
    if (!_recordArr) {
        [self.db open];
        _recordArr = [self.db searchData];
        
        if (_recordArr == nil) {
            _recordArr = [NSMutableArray array];
        }
    }

    return _recordArr;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    //隐藏状态栏
     [self.navigationController setNavigationBarHidden:YES];

    self.db = [HYfmbdManager shareManager];
    [self clearExtraLine:self.tableView];
    self.bgColorView = [[UIView alloc] init];
    self.bgColorView.backgroundColor = [UIColor colorWithRed:(74/255.0) green:(144/255.0) blue:(226/255.0) alpha:0.7f];
    self.bgColorView.layer.masksToBounds = YES;
    self.tableView.rowHeight = 110;
    
    self.selectRowIndex = 0;
    [self.view bringSubviewToFront:self.view];
    HYSearchViewController * search =(HYSearchViewController *)[self.navigationController.tabBarController.viewControllers objectAtIndex:3];
    search.delegate = self;
}

-(void)viewDidAppear:(BOOL)animated{
    if (self.recordArr.count<=0) {
        return;
    }
    NSIndexPath *select = [NSIndexPath indexPathForRow:self.selectRowIndex inSection:0];
    [self.tableView selectRowAtIndexPath:select animated:YES scrollPosition:UITableViewScrollPositionMiddle];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.recordArr.count;;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    HYRecordTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"RecordCell"];
    if (cell == nil) {
        cell = [[[NSBundle mainBundle] loadNibNamed:@"HYRecordTableViewCell" owner:self options:nil] lastObject];
    }
    id record = self.recordArr[indexPath.row];
    if ([record isKindOfClass: [HYAdressInfo class]]) {
        HYAdressInfo *addressModel = self.recordArr[indexPath.row];
       cell.addressInfo = addressModel;
    }
    
    cell.selectedBackgroundView = self.bgColorView;
    cell.tagId = [indexPath row];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    cell.delegate = self;
    return cell;
}

#pragma mark - 去掉多余单元格
- (void)clearExtraLine:(UITableView *) tableView {
    UIView *view = [[UIView alloc]init];
    view.backgroundColor = [UIColor clearColor];
    [self.tableView setTableFooterView:view];
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/


// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        //删除
        HYAdressInfo *tmp = (HYAdressInfo *)[self.recordArr objectAtIndex:indexPath.row];
        if (![self.db open]) {
            return;
        }
        if (![self.db deleteData:tmp.lngContent lat:tmp.latContent]) {
            return;
        }
        [self.recordArr removeObjectAtIndex:indexPath.row];
        //刷新表视图
        [self.tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationTop];
        
    }
}

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

- (IBAction)backAction:(id)sender {
    //初始化
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"是否退出" message:@"确定退出吗" preferredStyle:UIAlertControllerStyleActionSheet];
    //添加按钮
    [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil]];
    
    [alert addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDestructive handler:^(UIAlertAction *action){
        [self dismissViewControllerAnimated:YES completion:nil];
    }]];
    //弹出
    [self presentViewController:alert animated:YES completion:NULL];
}


#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    HYDeviceLocationViewController *dev = [segue destinationViewController];
    [dev.tabBarController.navigationItem setTitle:@"fdsf"];
    [dev.tabBarController.navigationItem setHidesBackButton:NO];
    NSIndexPath *path = [self.tableView indexPathForSelectedRow];
    self.selectRowIndex = path.row;
    dev.addressModel = self.recordArr[path.row];
}

#pragma mark - HYRecordTableViewCellDelegate的方法
-(void) updateTel:(HYRecordTableViewCell *)cell{
    NSString *title = @"电话号码修正";
    NSString *message = @"请仔细检查号码";
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
    }];
    
    UIAlertAction *otherAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        UITextField *tmpField = (UITextField *)[alertController.textFields lastObject];
        cell.telLable.text = tmpField.text;
        
        if (![self.db open]) {
            return;
        }
        if (![self.db update:cell.lngLable.text lat:cell.latLable.text tel:tmpField.text]) {
            return;
        }
        
    }];
    
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        [textField becomeFirstResponder];
        textField.keyboardType = UIKeyboardTypeNumberPad;
    }];
    // Add the actions.
    [alertController addAction:cancelAction];
    [alertController addAction:otherAction];
    
    [self presentViewController:alertController animated:YES completion:nil];

}

#pragma mark - HYSearchViewController delegate
-(void) addAdress:(HYSearchViewController *)addVc didAddAdress:(HYAdressInfo *)adress{
    if (![self.db open]) {
        return;
    }
    if (![self.db insert:adress]) {
        return;
    }
    //添加数据模型
    adress.numContent = [NSString stringWithFormat:@"%lu",self.recordArr.count+1];
    [self.recordArr insertObject:adress atIndex:0];
    self.selectRowIndex = 0;
    //刷新表视图
    [self.tableView reloadData];
}

@end
