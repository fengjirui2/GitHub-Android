//
//  HYLocationViewController.m
//  HYRemoteControl
//
//  Created by zhaotengfei on 15-10-13.
//  Copyright (c) 2015年 hyet. All rights reserved.
//

#import "HYCurrentLocationViewController.h"
#import <BaiduMapAPI/BMapKit.h>
@interface HYCurrentLocationViewController ()<BMKMapViewDelegate,BMKLocationServiceDelegate,BMKGeoCodeSearchDelegate>

@property (nonatomic,strong)BMKMapView *mapView;
@property (nonatomic,strong)BMKLocationService *locationService;
//地理位置搜索对象
@property (nonatomic,strong)BMKGeoCodeSearch *search;
@end

@implementation HYCurrentLocationViewController

- (void)dealloc
{
    self.mapView.delegate = nil;
    self.locationService.delegate = nil;
}

- (void)viewWillDisappear:(BOOL)animated{
    //关闭定位
//    [self.locationService stopUserLocationService];
    
    //隐藏图标
//    self.mapView.showsUserLocation = NO;
    
    //移除annotation
//    [self.mapView removeAnnotation:[self.mapView.annotations lastObject]];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    //隐藏状态栏
    [self.navigationController setNavigationBarHidden:YES];
    
    
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0) {
        //设置边界
        self.edgesForExtendedLayout = UIRectEdgeNone;
    }
    
    //添加地图
    self.mapView = [[BMKMapView alloc]initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    
    //设置当前类为mapView的代理对象
    self.mapView.delegate = self;
    
    //添加到父视图上
    [self.view addSubview:self.mapView];
    
    //创建定位对象
    self.locationService = [[BMKLocationService alloc]init];
    self.locationService.delegate = self;
    //设置再次定位到最小距离
    [BMKLocationService setLocationDistanceFilter:10];
    
    //开启定位服务
    [self.locationService startUserLocationService];
    //在地图上显示用户到位置
    self.mapView.showsUserLocation = YES;
    
    //创建搜索对象
    self.search = [[BMKGeoCodeSearch alloc]init];
    //设置代理
    self.search.delegate = self;
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark BMKGeoCodeSearch的代理回调方法

-(void)onGetReverseGeoCodeResult:(BMKGeoCodeSearch *)searcher result:(BMKReverseGeoCodeResult *)result errorCode:(BMKSearchErrorCode)error{
    //定义大头针标注
    BMKPointAnnotation *annotation = [[BMKPointAnnotation alloc]init];
    
    //设置显示位置
    annotation.coordinate = result.location;
    
    //设置title
    annotation.title = result.address;
    
    //添加到地图中
    [self.mapView addAnnotation:annotation];
    
    //使地图显示该位置
    [self.mapView setCenterCoordinate:result.location];
}

#pragma mark - BMKLocationService的代理方法

-(void)willStartLocatingUser{
    NSLog(@"开始定位");
}

/***
 定位成功，再次定位的回调方法
 */
-(void)didUpdateBMKUserLocation:(BMKUserLocation *)userLocation{
    //完成地理编码
    //创建反向地理编码选项对象
    BMKReverseGeoCodeOption *option = [[BMKReverseGeoCodeOption alloc]init];
    //给对象坐标负值
    option.reverseGeoPoint = userLocation.location.coordinate;
    //执行反向编码操作
    [self.search reverseGeoCode:option];
}

-(void)didFailToLocateUserWithError:(NSError *)error{
    NSLog(@"定位失败%@",error.description);
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
