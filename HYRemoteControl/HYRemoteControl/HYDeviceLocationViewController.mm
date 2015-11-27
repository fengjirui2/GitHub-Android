//
//  HYDeviceLocationViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYDeviceLocationViewController.h"
#import <BaiduMapAPI/BMapKit.h>
#import "HYRemoteViewController.h"
#import "HYAdressInfo.h"
@interface HYDeviceLocationViewController ()<BMKMapViewDelegate,UIGestureRecognizerDelegate>

@property (weak, nonatomic) IBOutlet BMKMapView *mapView;

@end

@implementation HYDeviceLocationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.mapView.zoomLevel = 19;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewWillAppear:(BOOL)animated {
    [self.mapView viewWillAppear];
    self.mapView.delegate = self; // 此处记得不用的时候需要置nil，否则影响内存的释放
    
    CLLocationCoordinate2D coor;
    coor.latitude = [self.addressModel.latContent floatValue] + 0.0062;
    coor.longitude = [self.addressModel.lngContent floatValue] + 0.0064;
    [self.mapView setCenterCoordinate:coor animated:YES];
    
    
    // 添加一个PointAnnotation
    BMKPointAnnotation* annotation = [[BMKPointAnnotation alloc]init];
    annotation.coordinate = coor;
    annotation.title = self.addressModel.addressContent;
    
    [self.mapView addAnnotation:annotation];
    [self.navigationController setNavigationBarHidden:YES];
    
}

// Override
- (BMKAnnotationView *)mapView:(BMKMapView *)mapView viewForAnnotation:(id <BMKAnnotation>)annotation
{
    if ([annotation isKindOfClass:[BMKPointAnnotation class]]) {
        BMKPinAnnotationView *newAnnotation = [[BMKPinAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"myAnnotation"];
        newAnnotation.pinColor = BMKPinAnnotationColorPurple;
        newAnnotation.image =  [UIImage imageNamed:@"marker"];
        newAnnotation.animatesDrop = YES;
        [newAnnotation setSelected:NO animated:YES];
        newAnnotation.draggable = YES;
        
        UITapGestureRecognizer *doubleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleDoubleTap:)];
        doubleTap.delegate = self;
        doubleTap.numberOfTapsRequired = 2;
        doubleTap.cancelsTouchesInView = NO;
        doubleTap.delaysTouchesEnded = NO;
        
        [newAnnotation addGestureRecognizer:doubleTap];
        
        
        return newAnnotation;
    }
    return nil;
    
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

-(void)viewWillDisappear:(BOOL)animated {
    [self.mapView viewWillDisappear];
    self.mapView.delegate = nil; // 不用时，置nil
}

- (void)dealloc {
    if (self.mapView) {
        self.mapView = nil;
    }
}

#pragma mark - 添加自定义的手势（若不自定义手势，不需要下面的代码）
- (void)handleDoubleTap:(UITapGestureRecognizer *)theDoubleTap {
    /*
     *do something
     */
    
    NSString *message = [NSString stringWithFormat:@"基站号:%@",self.addressModel.lacContent];
    message = [message stringByAppendingString:[NSString stringWithFormat:@"\n小区号:%@",self.addressModel.cellContent]];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"远程控制" message:message preferredStyle:UIAlertControllerStyleAlert];
    
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
        
    }];
    
    UIAlertAction *otherAction = [UIAlertAction actionWithTitle:@"远程控制" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        HYRemoteViewController *remote = [[HYRemoteViewController alloc] init];
        remote.addressModel = self.addressModel;
        
        [self.navigationController pushViewController:remote animated:YES];
    }];
    
    // Add the actions.
    [alertController addAction:cancelAction];
    [alertController addAction:otherAction];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

@end
