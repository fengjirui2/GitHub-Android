//
//  JHSDKAPIPath.h
//  JuheApisSDK
//
//  Created by ThinkLand on 8/19/14.
//  Copyright (c) 2014 ThinkLand. All rights reserved.
//

/**
 api接口宏定义格式：kJHAPIS_大类名称_小类名称_具体调用接口
 如:生活常用-IP地址-根据IP/域名查询地址
 宏:kJHAPIS_LIFE_IP_IP2ADDR
 */

/***** 热门数据 *******
 全国车辆违章			kJHAPIS_LIFE_WZ_XXX
 全国天气预报			kJHAPIS_LIFE_WEATHER_XXX
 12306火车票查询订票	kJHAPIS_LIFE_TRAIN_XXX
 身份证查询			kJHAPIS_LIFE_IDCARD_XXX
 身份证查询			kJHAPIS_LIFE_IDCARD_XXX
 手机号码归属地		kJHAPIS_LIFE_MOBILE_XXX
 */

/*************  生活常用 LIFE  ************************************************************************************************
 line 25 - 552
 IP地址                   kJHAPIS_LIFE_IP_XXXX
 手机号码归属地            kJHAPIS_LIFE_MOBILE_XXX
 全国加油站[实时油价]       kJHAPIS_LIFE_OIL_XXX
 菜谱大全                 kJHAPIS_LIFE_COOK_XXX
 Whois                   kJHAPIS_LIFE_WHOIS_XXX
 网站安全检测              kJHAPIS_LIFE_WEBSCAN_XXX
 航班动态                 kJHAPIS_LIFE_PLAN_XXX
 12306火车票查询订票       kJHAPIS_LIFE_TRAIN_XXX
 货币汇率                 kJHAPIS_LIFE_EXCHANGE_XXX
 空气质量                 kJHAPIS_LIFE_AIR_XXX
 水质量                   kJHAPIS_LIFE_WATER_xxx
 全国车辆违章              kJHAPIS_LIFE_WZ_XXX
 全国省市今日油价           kJHAPIS_LIFE_CNOIL_XXX
 苹果序列号                kJHAPIS_LIFE_APPLEINFO_XXX
 身份证查询                kJHAPIS_LIFE_IDCARD_XXX
 全国天气预报               kJHAPIS_LIFE_WEATHER_XXX
 常用快递                  kJHAPIS_LIFE_EXP_XXX
 餐饮美食                  kJHAPIS_LIFE_CATERING_XXX
 在线试题                  kJHAPIS_LIFE_EXAM_XXX
 Alexa网站排名             kJHAPIS_LIFE_ALEXA_XXX
 中国彩票开奖结果           kJHAPIS_LIFE_LOTTERY_XXX
 短信API服务               kJHAPIS_LIFE_SMS_XXX
 挂号网API                 kJHAPIS_LIFE_HOSPITAL_XXX
 语音验证码                 kJHAPIS_LIFE_VOICE_XXX
 邮编查询                   kJHAPIS_LIFE_POSTCODE_XXX
 域名备案查询               kJHAPIS_LIFE_JAPI_BEIAN
 */
/*************  电商 EX **********************************************************************************************
 
 条码查询                    kJHAPIS_EX_JHBAR_XXX
 
 */

/*** IP ***/
/**
 @brief 根据IP/域名查询地址
 @param ip          string   必填   需要查询的IP地址或域名
 @param dtype       string   非必填  返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_IP_IP2ADDR    @"juhe.apis.ip.ip2addr"               //1、根据IP/域名查询地址

/*** 手机号码归属地 ***/
/**
 @brief 手机号码归属地
 @param phone       int 	必填 	需要查询的手机号码或手机号码前7位
 @param dtype       string 	非必填  	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_MOBILE         @"juhe.apis.mobile.get"              //1、手机归属地查询

/*** 全国加油站[实时油价] ***/
/**
 @brief 全国加油站[实时油价] -> 按城市检索加油站
 @param city        string 	必填 	城市名urlencode utf8;
 @param page        int 	非必填 	页数，默认1
 */
#define kJHAPIS_LIFE_OIL_REGION     @"juhe.apis.oil.region"             //1、按城市检索加油站

/**
 @brief 全国加油站[实时油价] -> 检索周边加油站
 @param lon         double 	必填 	经纬(如:121.538123)
 @param lat         double 	必填 	纬度(如：31.677132)
 @param r           int 	非必填 	搜索范围，单位M，默认3000，最大10000
 @param page        int 	非必填 	页数,默认1
 */
#define kJHAPIS_LIFE_OIL_LOCAL      @"juhe.apis.oil.local"              //2、检索周边加油站

/*** 菜谱大全 ***/
/**
 @brief 菜谱大全 -> 菜谱大全
 @param menu        string 	必填 	需要查询的菜谱名
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 @param pn          string 	非必填 	数据返回起始下标
 @param rn          string 	非必填 	数据返回条数，最大30
 */
#define kJHAPIS_LIFE_COOK_QUERY     @"juhe.apis.cook.query"             //1、菜谱大全

/**
 @brief 菜谱大全 -> 分类标签列表
 @param parentid 	int 	非必填 	分类ID，默认全部
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_COOK_CATEGORY  @"juhe.apis.cook.category"          //2、分类标签列表

/**
 @brief 菜谱大全 -> 按标签检索菜谱 
 @param parentid 	int 	非必填 	分类ID，默认全部
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_COOK_INDEX     @"juhe.apis.cook.index"             //3、按标签检索菜谱

/**
 @brief 菜谱大全 -> 按菜谱ID查看详细
 @param id          int 	必填 	菜谱的ID
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_COOK_QUERYID   @"juhe.apis.cook.queryid"           //4、按菜谱ID查看详细


/*** Whois ***/
/**
 @brief Whois -> whois查询
 @param domain      string 	必填 	域名如:juhe.cn ,1jing.com
 @param dtype       string 	必填 	返回类型,xml/json/jsonp可选
 @param callback 	string 	非必填 	如返回的为JSONP，则须传递此参数
 */
#define kJHAPIS_LIFE_WHOIS_SEARCH    @"juhe.apis.whois.search"          //1、whois查询


/*** 网站安全检测 ***/
/**
 @brief 网站安全检测 -> 网站安全检测
 @param domain      string 	必填 	域名如:juhe.cn ,1jing.com
 @param dtype       string 	必填 	返回类型,xml/json/jsonp可选
 @param callback 	string 	非必填 	如返回的为JSONP，则须传递此参数
 */
#define kJHAPIS_LIFE_WEBSCAN_TEST   @"juhe.apis.webscan.test"           //1、网站安全检测


/*** 航班动态 ***/
/**
 @brief 航班动态 -> 城市列表
 @param dtype       string 	非必填 	返回类型，如：json 或者 xml（默认json
 */
#define kJHAPIS_LIFE_PLAN_CITY      @"juhe.apis.plan.city"              //1、城市列表

/**
 @brief 航班动态 -> 航班查询
 @param name        string 	是 	航班号，如:CZ3869
 @param date        string 	否 	请求时间，如：2012-12-27 （默认当天时间）
 @param dtype       string 	否 	返回类型，如：json 或者 xml（默认json）
 */
#define kJHAPIS_LIFE_PLAN_S         @"juhe.apis.plan.s"                 //2、航班查询

/**
 @brief 航班查询 -> 航线查询
 @param start       string 	是 	起飞城市(urlencode),如：北京 或 PEK
 @param end         string 	是 	到达城市,如：上海浦东 或 PVG
 @param date        string 	否 	请求时间，如：2012-12-27 （默认当天时间）
 @param dtype       string 	否 	返回类型，如： json 或 xml （默认json）
 */
#define kJHAPIS_LIFE_PLAN_S2S       @"juhe.apis.plan.s2s"               //3、航线查询

/**
 @brief 航班查询 -> 机场简介
 @param code        string 	是 	机场国际三字编码，如:FUG
 @param dtype       string 	否 	返回类型，如：json 或者 xml（默认json）
 */
#define kJHAPIS_LIFE_PLAN_AIRPORT   @"juhe.apis.plan.airport"           //4、机场简介



/* 12306火车票查询订票 */
/**
 @brief 2306火车票查询订票--1、车次查询
 @param lname       string 	必填 	车次名称，如：G4
 @param ldtype      string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_TRAIN_S             @"juhe.apis.train.s"                //1、车次查询

/**
 @brief 12306火车票查询订票--2、站到站查询
 @param start       string 	必填 	出发站
 @param end         string 	必填 	终点站
 @param traintype 	string 	非必填 	列车类型，G-高速动车 K-快速 T-空调特快 D-动车组 Z-直达特快 Q-其他
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_TRAIN_S2S           @"juhe.apis.train.s2s"              //2、站到站查询

/**
 @brief 12306火车票查询订票--3、12306实时余票查询
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 @param from        string 	必填 	出发站,如：上海虹桥
 @param to          string 	必填 	到达站,如：温州南
 @param date        string 	非必填 	出发日期，默认今日
 @param tt          string 	非必填 	车次类型，默认全部，如：G(高铁)、D(动车)、T(特快)、Z(直达)、K(快速)、Q(其他)
 */
#define kJHAPIS_LIFE_TRAIN_YP            @"juhe.apis.train.yp"               //3、12306实时余票查询

/**
 @brief 12306火车票查询订票--4、12306订票①：查询车次
 @param from        string 	必填 	出发站名称：如上海虹桥
 @param to          string 	必填 	到达站名称：如温州南
 @param date        date 	非必填 	默认当天，格式：2014-07-11
 @param tt          string 	非必填 	车次类型，默认全部，如：G(高铁)、D(动车)、T(特快)、Z(直达)、K(快速)、Q(其他)
 */
#define kJHAPIS_LIFE_TRAIN_TICKET_CC     @"juhe.apis.train.ticket.cc"        //4、12306订票①：查询车次

/**
 @brief 12306火车票查询订票--5、12306订票②：提交订单
 @param name                    string 	必填 	乘客姓名
 @param seat                    string 	必填 	座位类型：商务座:9,一等座:M,二等座：O,特等座：P,高级软卧：6,软卧：4,硬卧：3,软座:2,硬座：1,无座：0
 @param mobile                  string 	必填 	乘客手机号码
 @param idcard                  string 	必填 	乘客身份证号码
 @param username                string 	必填 	12306官网账号
 @param password                string 	必填 	12306官网密码
 @param train_no                string 	必填 	步骤①对应车次返回值
 @param station_train_code      string 	必填 	步骤①对应车次返回值
 @param from_station_telecode 	string 	必填 	步骤①对应车次返回值
 @param to_station_telecode 	string 	必填 	步骤①对应车次返回值
 @param from_station_name       string 	必填 	步骤①对应车次返回值
 @param to_station_name         string 	必填 	步骤①对应车次返回值
 @param secretStr               string 	必填 	步骤①对应车次返回值
 */
#define kJHAPIS_LIFE_TRAIN_TICKET_ORDER    @"juhe.apis.train.ticket.order"     //5、12306订票②：提交订单


/*** 货币汇率 ***/
/**
 @brief 货币汇率 -> 人民币牌价   
 */
#define kJHAPIS_LIFE_EXCHANGE_RMBQUOT       @"juhe.apis.exchange.rmbquot"       //1、人民币牌价

/**
 @brief 货币汇率 -> 外汇汇率
 */
#define kJHAPIS_LIFE_EXCHANGE_FRATE         @"juhe.apis.exchange.frate"         //2、外汇汇率

/*** 空气质量 ***/
/**
 @brief 空气质量 -> 城市空气质量
 @param city        String 	是 	城市名称的中文拼音，查询城市为“上海”，则输入shanghai,
 */
#define kJHAPIS_LIFE_AIR_CITYAIR            @"juhe.apis.air.cityair"            //1、城市空气质量

/**
 @brief 空气质量 -> 城市空气PM2.5指数
 @param city        String 	是 	城市名称的中文名称或拼音，如：上海 或 shanghai
 */
#define kJHAPIS_LIFE_AIR_PM                 @"juhe.apis.air.pm"                 //2、城市空气PM2.5指数

/**
 @brief 空气质量 -> 城市辐射指数
 @param city        String 	是 	城市名称的中文拼音，查询城市为“上海”，则输入：上海
 @param num         Int 	否 	查询页码数，不写默认为第一页。
 */
#define kJHAPIS_LIFE_AIR_RADIA              @"juhe.apis.air.radia"              //3、城市辐射指数




/*** 水质量 ***/
/**
 @brief 水质量 -> 流域查询水质量
 @param river       String 	是 	流域名称，查询流域为“长江流域”，则输入“长江流域”
 */
#define kJHAPIS_LIFE_WATER_RIVER            @"juhe.apis.water.river"            //1、流域查询水质量

/**
 @brief 水质量 -> 监测站点查询水质
 @param state       String 	是 	监测站点名称，查询站点为“湖北宜昌南津关”，则输入“湖北宜昌南津关”
 */
#define kJHAPIS_LIFE_WATER_STATE            @"juhe.apis.water.state"            //2、监测站点查询水质量


/* 全国车辆违章 */
/**
 @brief 车辆违章查询--1、获取支持城市接口
 @param province    string  非必填 默认全部，省份简写，如：ZJ、JS
 @param dtype       string  非必填 返回数据格式：json或xml或jsonp,默认json
 @param callback    string  非必填 当选择jsonp格式时必须传递
 */
#define kJHAPIS_LIFE_WZ_CITYS               @"juhe.apis.wz.citys"               //1、获取支持城市接口

/**
 @brief 车辆违章查询--2、请求违章查询接口
 @param dtype       string  必填      返回数据格式：json或xml或jsonp,默认json
 @param callback    string  非必填     当选择jsonp格式时必须传递
 @param ity         String 	必填      城市代码 *
 @param hphm        String 	必填      号牌号码 完整7位 *
 @param hpzl        String 	必填      号牌类型，默认02
 @param engineno 	String 	非必填    发动机号 (根据城市接口中的参数填写)
 @param classno 	String 	非必填    车架号 (根据城市接口中的参数填写)
 */
#define kJHAPIS_LIFE_WZ_QUERY               @"juhe.apis.wz.query"               //2、请求违章查询接口

/**
 @brief 车辆违章查询--3、车辆（号牌）种类编号查询接口
 @param dtype       string 	非必填 	返回数据格式：json或xml或jsonp,默认json
 @param callback 	String 	非必填 	返回格式选择jsonp时，必须传递
 */
#define kJHAPIS_LIFE_WZ_HPZL                @"juhe.apis.wz.hpzl"                //3、车辆（号牌）种类编号查询接口

/**
 @brief 车辆违章查询--4、接口剩余次数查询
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_WZ_STATUS              @"juhe.apis.wz.status"              //4、接口剩余次数查询

/*** 全国省市今日油价 ***/
/**
 @brief 全国省市今日油价
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_CNOIL_OILCITY              @"juhe.apis.cnoil.oilcity"              //1、全国省市今日油



/*** 苹果序列号 ***/
/**
 @brief 苹果序列号 -> 苹果序列号/IMEI号查询
 @param sn          string 	必填 	苹果产品的序列号或IMEI号
 @param dtype       string 	非必填 	返回数据格式：json或xml,默认json
 */
#define kJHAPIS_LIFE_APPLEINFO_INDEX        @"juhe.apis.appleinfo.index"        //1、苹果序列号/IMEI号查询


/*** 身份证查询 ***/
/**
 @brief 身份证查询--1、身份证信息查询
 @param cardno      string 	必填 	身份证号码
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 @discuss nil
 */
#define kJHAPIS_LIFE_IDCARD_INDEX           @"juhe.apis.idcard.index"            //1、身份证信息查询

/**
 @brief 身份证查询--2、身份证泄漏查询
 @param cardno      string 	必填 	身份证号码
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 */
#define kJHAPIS_LIFE_IDCARD_LEAK            @"juhe.apis.idcard.leak"             //2、身份证泄漏查询

/**
 @brief 身份证查询--3、身份证挂失查询
 @param cardno      string 	必填 	身份证号码
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 */
#define kJHAPIS_LIFE_IDCARD_LOSS            @"juhe.apis.idcard.loss"             //3、身份证挂失查询




/*** 全国天气预报 ***/
/**
 @brief 全国天气 -> 根据城市名/id查询天气
 @param cityname 	string 	必填 	城市名或城市ID，如："苏州"
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 @param format      int 	非必填 	未来6天预报(future)两种返回格式，1或2，默认1
 */
#define kJHAPIS_LIFE_WEATHER_INDEX          @"juhe.apis.weather.index"          //1、根据城市名/id查询天气

/**
 @brief 全国天气 -> 天气种类及标识列表
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_WEATHER_UNI            @"juhe.apis.weather.uni"            //2、天气种类及标识列表
/**
 @brief 全国天气 -> 根据IP查询天气
 @param ip          string 	必填 	ip地址，如：58.215.185.154
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 @param format      int 	非必填 	未来6天预报(future)两种返回格式，1或2，默认1
 */
#define kJHAPIS_LIFE_WEATHER_IP             @"juhe.apis.weather.ip"             //3、根据IP查询天气
/**
 @brief 全国天气 -> 根据GPS坐标查询天气
 @param lon         string 	必填 	经度，如：116.39277
 @param lat         string 	必填 	纬度，如：39.933748
 @param format      int 	非必填 	未来6天预报(future)两种返回格式，1或2，默认1
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 */
#define kJHAPIS_LIFE_WEATHER_GEO            @"juhe.apis.weather.geo"            //4、根据GPS坐标查询天气
/**
 @brief 全国天气 -> 城市天气三小时预报
 @param cityname    string 	必填 	城市名，如："苏州"
 @param dtype       string 	必填 	返回数据格式：json或xml,默认json
 */
#define kJHAPIS_LIFE_WEATHER_FORECAST3H     @"juhe.apis.weather.forecast3h"     //5、城市天气三小时预报
/**
 @brief 全国天气 -> 支持城市列表
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_WEATHER_CITYS          @"juhe.apis.weather.citys"          //6、支持城市列表



/*** 常用快递 ***/
/**
 @brief 常用快递 -> 常用快递查询API
 @param com         string 	是 	需要查询的快递公司编号
 @param no          string 	是 	需要查询的订单号
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_EXP_INDEX              @"juhe.apis.exp.index"              //1、常用快递查询API

/**
 @brief 常用快递 -> 快递公司编号对照表
 */
#define kJHAPIS_LIFE_EXP_COM                @"juhe.apis.exp.com"                //2、快递公司编号对照表



/*** 餐饮美食 ***/
/**
 @brief 餐饮美食 -> 检索周边美食
 @param lng         double 	是 	经纬(如:121.538123)，传递的适合google地图的坐标系
 @param lat         double 	是 	纬度(如：31.677132)
 @param radius      int 	否 	搜索范围，单位M，默认3000
 @param page        int 	否 	当前页数，默认1,最大50.
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_CATERING_QUERY         @"juhe.apis.catering.query"         //1、检索周边美食




/*** 在线试题 ***/
/**
 @brief 在线试题 -> 试题目录
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_EXAM_CATALOG           @"juhe.apis.exam.catalog"           //1、试题目录

/**
 @brief 在线试题 -> 试题考题
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_EXAM_QUERY             @"juhe.apis.exam.query"             //2、试题考题

/*** Alexa网站排名 ***/
/**
 @brief Alexa网站排名 -> alexa网站排名查询
 @param site        string 	是 	域名如:juhe.cn ,1jing.com
 @param dtype       string 	是 	返回类型,xml/json可选
 */
#define kJHAPIS_LIFE_ALEXA_INDEX          @"juhe.apis.alexa.index"              //1、alexa网站排名查询


/*** 中国彩票开奖结果 ***/
/**
 @brief 中国彩票开奖结果 -> 彩票开奖结果查询
 @param otteryid 	int 	否 	彩票ID，为空则为所有
 @param date        date 	否 	指定开奖日期，不指定默认为昨日
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_LOTTERY_QUERY          @"juhe.apis.lottery.query"          //1、彩票开奖结果查询

/**
 @brief 中国彩票开奖结果 -> 历史开奖数据查询
 @param lotteryid 	int 	否 	彩票ID
 @param year        int 	否 	指定年份，如2013，默认2014
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_LOTTERY_HISTORY        @"juhe.apis.lottery.history"        //2、历史开奖数据查询

/**
 @brief 中国彩票开奖结果 -> 支持彩种列表
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_LOTTERY_LOLIST         @"juhe.apis.lottery.lolist"         //3、支持彩种列表


/*** 短信API服务 ***/
/**
 @brief 短信API服务 -> 发送短信
 @param mobile      string 	是 	接收短信的手机号码
 @param tpl_id      int 	是 	短信模板ID，请参考个人中心短信模板设置
 @param tpl_value 	string 	是 	变量名和变量值对。如果你的变量名或者变量值中带有#&=中的任意一个特殊符号，请先分别进行urlencode编码后再传递，详细说明>
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_SMS_SEND               @"juhe.apis.sms.send"               //1、发送短信


/*** 挂号网API ***/
/**
 @brief 挂号网API -> 医院检索
 @param keyword 	string 	是 	查询的关键字，院名/疾病名
 @param province 	string 	否 	限定医院省份，如：浙江
 @param area        string 	否 	限定医院城市或区，如：杭州
 @param pn          int 	否 	页数，默认1
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_QUERY         @"juhe.apis.hospital.query"         //1、医院检索

/**
 @brief 挂号网API -> 医院详情
 @param id          string 	是 	医院ID
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_INFO          @"juhe.apis.hospital.info"          //2、医院详情

/**
 @brief 挂号网API -> 医生检索
 @param keyword 	string 	是 	查询的关键字，院名/疾病名
 @param province 	string 	否 	限定医院省份，如：浙江
 @param area        string 	否 	限定医院城市或区，如：杭州
 @param pn          int 	否 	页数，默认1
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_DOCTOR        @"juhe.apis.hospital.doctor"        //3、医生检索

/**
 @brief 挂号网API -> 医生详情
 @param id          string 	是 	医生ID
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_DOCTORINFO    @"juhe.apis.hospital.doctorinfo"    //4、医生详情

/**
 @brief 挂号网API -> 在线预约挂号申请
 @param username 	string 	是 	挂号网账号
 @param password 	string 	是 	挂号网密码
 @param doctorid 	string 	是 	挂号医生ID
 @param date        string 	是 	预约的日期
 @param time        string 	是 	预约时段
 @param disease 	string 	否 	疾病描述
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_RESERVE       @"juhe.apis.hospital.reserve"       //5、在线预约挂号申请

/**
 @brief 挂号网API -> 提交预约手机验证码
 @param id          string 	是 	预约ID
 @param code        string 	是 	手机验证码
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_HOSPITAL_SUBMIT        @"juhe.apis.hospital.submit"        //6、提交预约手机验证码


/*** 语音验证码 ***/
/**
 @brief 语音验证码 -> 发送语音验证码
 @param valicode 	string 	是 	验证码内容，字母、数字 4-8位
 @param to          string 	是 	接收手机号码
 @param playtimes 	int 	否 	验证码播放次数，默认3
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_CAPTHCA_VOICE          @"juhe.apis.captcha.voice"          //1、发送语音验证码


/*** 邮编查询 ***/ /* 2014/09/11 new */
/**
 @brief 邮编查询 -> 邮编查询地名
 @param postcode	string	是	邮编，如：215001
 @param page        int     否	页数，默认1
 @param pagesize	int     否	每页返回，默认:20,最大不超过50
 @param dtype       string	否	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_POSTCODE_QUERY         @"juhe.apis.postcode.query"         //1、邮编查询地名
/**
 @brief 邮编查询 -> 省份城市区域列表
 @param dtype       string	否	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_POSTCODE_PCD           @"juhe.apis.postcode.pcd"           //2、省份城市区域列表
/**
 @brief 邮编查询 -> 地名查询邮编
 @param pid         int     是	省份ID
 @param cid         int     是	城市ID
 @param did         int     否	区域ID
 @param q           string	否	地名关键字，如:木渎
 @param dtype       string	否	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LIFE_POSTCODE_SEARCH        @"juhe.apis.postcode.search"        //3、地名查询邮编

/**
 @brief 域名备案查询 -> 1、备案查询
 @param type        int 	是 	0通过域名查询，如:juhe.cn
                                1通过主办单位名称查询，如：苏州新科兰德科技有限公司
                                2通过网站名称查询，如：聚合数据平台
                                3通过域名负责人查询，如：左磊
                                4通过许可证号查询查询，如：苏ICP备14006450号-3
 @param v           string 	是 	接口版本，当前1.0
 @param keyword 	string 	是 	对应type的值，如：juhe.cn
 */
#define kJHAPIS_LIFE_JAPI_BEIAN             @"juhe.apis.japi.beian"             //1、备案查询


/*************  位置信息服务 LBS  ************************************************************************************************/
 /* line
 移动联通基站             kJHAPIS_LBS_JZ_GSM
 谷歌POI                 kJHAPIS_LBS_GOOGLE_XXX
 百度POI                 kJHAPIS_LBS_BAIDU_XXX
 经纬度地址解析            kJHAPIS_LBS_GEO_XXX
 电信基站                kJHAPIS_LBS_JZ_CDMA
 地图坐标服务             kJHAPIS_LBS_OFFSET_INDEX
 */

/* 移动联通基站 */
/**
 @brief 移动联通基站 -> 移动联通基站定位接口
 @param mnc         int     必填  移动基站：0 联通基站:1 默认:0
 @param lac         int     必填  小区号
 @param cell        int     必填  基站号
 @param hex         int     非必填 进制类型，16或者10，默认为10
 @param dtype       string  非必填 返回的数据格式：json/xml/jsonp，默认json
 @param callback    string  非必填 当选择jsonp格式时必须传递
 */
#define kJHAPIS_LBS_JZ_GSM              @"juhe.apis.jizhan.gsm"                 //1、移动联通基站定位

/**
 @brief 电信基站 -> 电信基站定位接口
 @param sid         int     必填  SID
 @param nid         int     必填  NID
 @param cellid      int     必填  基站号(bid)
 @param hex         int     非必填 进制类型，16或者10，默认为10
 @param dtype       string  非必填 返回的数据格式：json/xml/jsonp，默认json
 @param callback    string  非必填 当选择jsonp格式时必须传递
 */
#define kJHAPIS_LBS_JZ_CDMA             @"juhe.apis.jizhan.cdma"                //1、电信基站定位

/* 谷歌POI */
/**
 @brief 谷歌POI -> 获取数据分类
 @param fid         string 	否 	所属分类ID，默认空，即全部分类，否则返回指定分类下的子类
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_GOOGLE_CATEGORY    @"juhe.apis.google.category"             //1、获取数据分类

/**
 @brief 谷歌POI -> 指定城市内检索
 @param citycode 	string 	是 	城市的区号，如:021
 @param cid         int 	否 	分类ID，可从分类接口获取到，默认全部
 @param keyword 	string 	是 	关键字，不支持多关键字
 @param page        string 	否 	页数，默认1 最大50.
 @param pnums       int 	否 	每次返回数据数目，默认20，最大20
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_GOOGLE_REGION      @"juhe.apis.google.region"               //2、指定城市内检索

/**
 @brief 谷歌POI -> 检索周边区域
 @param lng         double 	是 	经纬(如:121.538123)，传递的应该是google地图的经纬度
 @param lat         double 	是 	纬度(如：31.677132)
 @param cid         int 	是 	所属分类ID
 @param r           int 	否 	搜索范围，单位M，默认1000
 @param page        int 	否 	当前页数，默认1,最大50.
 @param pnums       int 	否 	每次返回数据条数，默认20，最大20
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_GOOGLE_LOCAL       @"juhe.apis.google.local"                //3、检索周边区域

/* 百度POI */
/**
 @brief 百度POI -> 数据分类接口
 @param fid         string 	非必填 	分类父ID，默认空，即全部分类，否则返回指定分类下的子类
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_BAIDU_GETCATEGORY    @"juhe.apis.baidu.getcategory"         //1、数据分类接口
/**
 @brief 百度POI -> 查询数据接口
 @param city        string 	必填 	城市的名称
 @param cid         int 	非必填 	分类ID，可从分类接口获取到，默认全部
 @param keyword 	string 	非必填 	名称包含的关键字
 @param page        string 	非必填 	页数，默认第一页 最大50.
 @param pnums       int 	非必填 	每次返回数据数目，默认20，最大20
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_BAIDU_GETDATA        @"juhe.apis.baidu.getdata"             //2、查询数据接口
/**
 @brief 百度POI -> 获取周边数据接口
 @param lng         float 	必填 	经纬(如:121.538123)，传递的应该是百度地图的经纬度
 @param lat         float 	必填 	纬度(如：31.677132)
 @param r           int 	非必填 	搜索范围，单位M，默认1000
 @param cid         int 	非必填 	分类ID，可从分类接口获取到，默认全部
 @param page        string 	非必填 	页数，默认第一页 最大50.
 @param pnums       int 	非必填 	每次返回数据数目，默认20，最大20
 @param dtype       string 	非必填 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_LBS_BAIDU_GETLOCATE      @"juhe.apis.baidu.getlocate"           //3、获取周边数据接口

/* 经纬度地址解析 */
#define kJHAPIS_LBS_GEO_GPS              @"juhe.apis.geo.gps"                   //1、经纬度地址解析

/* 地图坐标服务 */
#define kJHAPIS_LBS_OFFSET_INDEX        @"juhe.apis.offset.index"               //1、经纬度转换

/************* 金融基金 FINANCE ************************************************************************************************
 
 股票数据               kJHAPIS_FINANCE_STOCK_XXX
 净值数据               kJHAPIS_FINANCE_FUND_NETDATA_XXX
 暂停基金               kJHAPIS_FINANCE_FUND_SUSPEND_XXX
 重仓股基金             kJHAPIS_FINANCE_FUND_ZCGJJ
 基金财务数据           kJHAPIS_FINANCE_FUND_FINDATA_XXX
 黄金数据               kJHAPIS_FINANCE_GOLD_XXX
 */


/*** 股票数据 ***/
/**
 @brief 股票数据 -> 沪深股市
 @param gid         string 	是 	股票编号，上海股市以sh开头，深圳股市以sz开头如：sh601009
 */
#define kJHAPIS_FINANCE_STOCK_HS                @"juhe.apis.finance.stock.hs"                    //1、沪深股市

/**
 @brief 股票数据 -> 香港股市
 @param num         int 	是 	股票代码，如：00001 为“长江实业”股票代码
 */
#define kJHAPIS_FINANCE_STOCK_HK                @"juhe.apis.finance.stock.hk"            //2、香港股市

/**
 @brief 股票数据 -> 美国股市
 @param gid         string 	是 	股票代码，如：appl 为“苹果公司”的股票代码
 */
#define kJHAPIS_FINANCE_STOCK_US                @"juhe.apis.finance.stock.usa"           //3、美国股市

/**
 @brief 净值数据,暂停基金,重仓股基金,基金财务数据,黄金数据,method均为“GET”,parameters为空(nil)。
 */
/*** 净值数据 ***/
#define kJHAPIS_FINANCE_FUND_NETDATA_ALL        @"juhe.apis.fund.netdata.all"            //1、全部开放基金
#define kJHAPIS_FINANCE_FUND_NETDATA_STOCK      @"juhe.apis.fund.netdata.stock"          //2、股票型基金
#define kJHAPIS_FINANCE_FUND_NETDATA_BOND       @"juhe.apis.fund.netdata.bond"           //3、普通债券型基金
#define kJHAPIS_FINANCE_FUND_NETDATA_MONET      @"juhe.apis.fund.netdata.monet"          //4、货币型基金
#define kJHAPIS_FINANCE_FUND_NETDATA_CLOSE      @"juhe.apis.fund.netdata.close"          //5、封闭型基金
#define kJHAPIS_FINANCE_FUND_NETDATA_INNOV      @"juhe.apis.fund.netdata.innov"          //6、创新封基
#define kJHAPIS_FINANCE_FUND_NETDATA_LOF        @"juhe.apis.fund.netdata.lof"            //7、LOF
#define kJHAPIS_FINANCE_FUND_NETDATA_ETF        @"juhe.apis.fund.netdata.etf"            //8、ETF
#define kJHAPIS_FINANCE_FUND_NETDATA_QDII       @"juhe.apis.fund.netdata.qdii"           //9、QDII


/*** 暂停基金 ***/
#define kJHAPIS_FINANCE_FUND_SUSPEND_PURCH      @"juhe.apis.fund.suspend.purch"          //1、暂停申购的基金
#define kJHAPIS_FINANCE_FUND_SUSPEND_REDEE      @"juhe.apis.fund.suspend.redee"          //2、暂停赎回的基金

/*** 重仓股基金 ***/
#define kJHAPIS_FINANCE_FUND_ZCGJJ              @"juhe.apis.fund.zcgjj"                  //1、重仓股基金

/*** 基金财务数据 ***/
#define kJHAPIS_FINANCE_FUND_FINDATA_MAIN       @"juhe.apis.fund.findata.main"           //1、主要财务指标
#define kJHAPIS_FINANCE_FUND_FINDATA_SIZE       @"juhe.apis.fund.findata.size"           //2、基金规模
#define kJHAPIS_FINANCE_FUND_FINDATA_CONFIG     @"juhe.apis.fund.indata.config"          //3、资产配置

/*** 黄金数据 ***/
#define kJHAPIS_FINANCE_GOLD_SHGOLD             @"juhe.apis.finance.gold.shgold"        //1、上海黄金交易所
#define kJHAPIS_FINANCE_GOLD_SHFUTURE           @"juhe.apis.finance.gold.shfuture"      //2、上海期货交易所
#define kJHAPIS_FINANCE_GOLD_BANKGOLD           @"juhe.apis.finance.gold.bankgold"      //3、银行账户黄金




/************* 影视娱乐 ENTERTAINMENT ************************************************************************************************
 影讯API合集            kULR_ENT_MOVIE_XXX
 电影票房               kULR_ENT_BOXOFFICE_XXX
 星座运势               kULR_ENT_CONSTELLATION_XXX
 周公解梦               kJHAPIS_ENT_DREAM_XXX
 历史上的今天            kJHAPIS_ENT_TOH_XXX
 老黄历                 kJHAPIS_ENT_LAOHUANGLI_XXX
 */

/*** 影讯API合集 ***/
/**
 @brief 影讯API合集 -> 按关键字检索影片信息
 @param title       string 	是 	需要检索的影片标题,utf8编码的urlencode
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_INDEX                 @"juhe.apis.movie.index"                //1、按关键字检索影片信息

/**
 @brief 影讯API合集 -> 检索周边影院
 @param lat         string 	是 	纬度，百度地图坐标系
 @param lon         string 	是 	经度，百度地图坐标系
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_CINEMAS_LOCAL         @"juhe.apis.movie.cinemas.local"        //2、检索周边影院

/**
 @brief 影讯API合集 -> 关键字影院检索
 @param cityid      string 	是 	城市ID
 @param keyword 	string 	否 	关键字，urlencode utf8
 @param page        int 	否 	页数，默认1
 @param pagesize 	int 	否 	每页返回条数，默认20
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_CINEMAS_SEARCH        @"juhe.apis.movie.cinemas.search"       //3、关键字影院检索

/**
 @brief 影讯API合集 -> 影院上映影片信息
 @param cinemaid 	int 	是 	影院ID
 @param movieid 	int 	否 	指定电影ID，默认全部电影
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_CINEMAS_MOVIES        @"juhe.apis.movie.cinemas.movies"       //4、影院上映影片信息

/**
 @brief 影讯API合集 -> 今日放映影片
 @param cityid      int 	是 	城市ID
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_TODAY                 @"juhe.apis.movie.movies.today"         //5、今日放映影片

/**
 @brief 影讯API合集 -> 支持城市列表
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_CITYS                 @"juhe.apis.movie.citys"                //6、支持城市列表

/**
 @brief 影讯API合集 -> 影片上映影院查询
 @param cityid      int 	是 	城市ID
 @param movieid 	int 	是 	影片ID
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_CINEMAS               @"juhe.apis.movie.movies.cinemas"       //7、影片上映影院查询

/**
 @brief 影讯API合集 -> 按影片ID检索影片信息
 @param movieid 	string 	是 	需要检索的影片id
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_MOVIE_QUERY                 @"juhe.apis.movie.query"                //8、按影片ID检索影片信息


/*** 电影票房 ***/
/**
 @brief 电影票房 -> 最新票房榜
 @param area        string 	是 	票房榜的区域,CN-内地，US-北美，HK-香港
 @param dtype       string 	否 	返回数据的格式,xml/json，默认json
 */
#define kJHAPIS_ENT_BOXOFFICE_RANK              @"juhe.apis.boxoffice.rank"             //1、最新票房榜

/**
 @brief 电影票房 -> 网票票房
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_ENT_BOXOFFICE_WP                @"juhe.apis.boxoffice.wp"               //2、网票票房


/***  星座运势 ***/
/**
 @brief 星座运势 -> 运势查询
 @param consName 	string 	是 	星座名称，如:白羊座
 @param type        string 	是 	运势类型：today,tomorrow,week,nextweek,month,year
 */
#define kJHAPIS_ENT_CONSTELLATION_GETALL        @"juhe.apis.constellation.getall"       //1、运势查询


/***  周公解梦 ***/ /* 2014/09/11 new */
/**
 @brief 周公解梦 -> 类型
 @param fid         string 	是 	所属分类，默认全部，0:一级分类
 */
#define kJHAPIS_ENT_DREAM_CATEGORY              @"juhe.apis.dream.category"             //1、类型
/**
 @brief 周公解梦 -> 解梦查询
 @param q           string 	是 	梦境关键字，如：黄金 需要utf8 urlencode
 @param cid         int 	否 	指定分类，默认全部
 @param full        int 	否 	是否显示详细信息，1:是 0:否，默认0
 */
#define kJHAPIS_ENT_DREAM_QUERY                 @"juhe.apis.dream.query"                //2、解梦查询
/**
 @brief 周公解梦 -> 根据ID查询解梦信息
 @param id          string 	是 	解梦ID
 */
#define kJHAPIS_ENT_DREAM_QUERYID               @"juhe.apis.dream.queryid"              //3、根据ID查询解梦信息

/***  历史上的今天 ***/ /* 2014/09/11 new */
/**
 @brief 历史上的今天 -> 事件列表
 @param v           string 	是 	版本，当前：1.0
 @param month       int 	是 	月份，如：10
 @param day         int 	是 	日，如：1
 */
#define kJHAPIS_ENT_TOH_TOH                     @"juhe.apis.toh.toh"                    //1、事件列表
/**
 @brief 历史上的今天 -> 类型
 @param v           string 	是 	版本，当前：1.0
 @param id          int 	是 	事件ID
 */
#define kJHAPIS_ENT_TOH_TOHDET                  @"juhe.apis.toh.tohdet"                 //2、根据ID查询事件详情


/***  老黄历 ***/ /* 2014/09/11 new */
/**
 @brief 老黄历 -> 日历
 @param date          string 	是 	日期，格式2014-09-09
 */
#define kJHAPIS_ENT_LAOHUANGLI_D                @"juhe.apis.laohuangli.d"               //1、日历
/**
 @brief 老黄历 -> 时辰
 @param date          string 	是 	日期，格式2014-09-09
 */
#define kJHAPIS_ENT_LAOHUANGLI_H                @"juhe.apis.laohuangli.h"               //2、时辰


/************* 全网数据 ONLINE ************************************************************************************************
 地产数据               kJHAPIS_OL_ESTATE_XXX
 图书电商数据             kJHAPIS_OL_GOODBOOK_XXX
 全网视频检索             kJHAPIS_OL_VIDEO_XXX
 招聘信息大全             kJHAPIS_OL_JOB_XXX
 旅游资讯大全             kJHAPIS_OL_TRAVEL_XXX
*/

/*** 地产数据 ***/
/**
 @brief 地产数据 -> 地产检索
 @param city        string 	是 	城市名称，请参考支持城市列表
 @param q           String 	否 	地产名关键字
 @param page        int 	否 	页数，默认1,每页返回10条
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_OL_ESTATE_QUERY             @"juhe.apis.estate.query"                   //1、地产检索
/**
 @brief  地产数据 -> 周边地产
 @param lat         string 	是 	纬度（百度地图坐标系）
 @param lng         string 	是 	经度
 @param radius      String 	否 	检索半径，默认5000 单位米
 @param page        int 	否 	页数，默认1,每页返回20条
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_OL_ESTATE_LOCAL             @"juhe.apis.estate.local"                   //2、周边地产
/**
 @brief  地产数据 -> 支持城市列表
 @param nil
 */
#define kJHAPIS_OL_ESTATE_CITYS             @"juhe.apis.estate.citys"                   //3、支持城市列表

/*** 图书电商数据 ***/
/**
 @brief 图书电商数据 -> 图书分类目录
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_OL_GOODBOOK_CATALOG         @"juhe.apis.goodbook.catalog"               //1、图书分类目录

/**
 @brief 图书电商数据 ->
 @param catalog_id 	int 	是 	目录编号
 @param pn          int 	是 	数据返回起始
 @param rn          int 	是 	数据返回条数，最大30
 @param dtype       string 	否 	返回数据的格式,xml或json，默认json
 */
#define kJHAPIS_OL_GOODBOOK_QUERY           @"juhe.apis.goodbook.query"                 //2、图书内容

/*** 全网视频检索 ***/
/**
 @brief 全网视频检索 -> 明星检索
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param keyword 	string 	必填 	明星姓名或明星id
 @param v           string 	必填 	接口版本当前1.0
 */
#define kJHAPIS_OL_VIDEO_P                  @"juhe.apis.video.p"                        //1、明星检索

/**
 @brief 全网视频检索 -> 视频检索
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param keyword 	string 	必填 	节目名称或节目id
 @param v           string 	必填 	接口版本当前1.0
 */
#define kJHAPIS_OL_VIDEO_V                  @"juhe.apis.video.v"                        //2、视频检索

/**
 @brief 全网视频检索 -> 视频播放链接
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param id          INT 	必填 	视频检索接口中返回的source.id
 @param v           string 	必填 	接口版本当前1.0
 */
#define kJHAPIS_OL_VIDEO_VS                 @"juhe.apis.video.vs"                       //3、视频播放链接

/*** 招聘信息大全 ***/
/**
 @brief 招聘信息大全 ->
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_AREA                 @"juhe.apis.job.area"                       //1、获取地区列表

/**
 @brief 招聘信息大全 -> 获取职位分类列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_CATE                 @"juhe.apis.job.cate"                       //2、获取职位分类列表

/**
 @brief 招聘信息大全 -> 获取公司类型列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_COTYPE               @"juhe.apis.job.cotype"                     //3、获取公司类型列表

/**
 @brief 招聘信息大全 -> 获取招聘平台列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_FROM                 @"juhe.apis.job.from"                      //4、获取招聘平台列表

/**
 @brief 招聘信息大全 -> 获取学历列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_EDU                  @"juhe.apis.job.edu"                        //5、获取学历列表

/**
 @brief 招聘信息大全 -> 获取行业分类
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_IND                  @"juhe.apis.job.ind"                        //6、获取行业分类

/**
 @brief 招聘信息大全 -> 获取工作方式列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_JOB_JOBTYPE              @"juhe.apis.job.jobtype"                    //7、获取工作方式列表

/**
 @brief 招聘信息大全 -> 获取职位列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 @param area        string 	非必填 	地区id，对应list-area中的id
 @param cate        string 	非必填 	分类id,对应list-cate中的id
 @param cotype      string 	非必填 	公司类型id，对应list-cotype中的id
 @param edu         string 	非必填 	学历id,对应list-edu中的id
 @param ind         string 	非必填 	行业分类id,对应list-ind中的id
 @param jobtype 	string 	非必填 	工作方式id,对应list-jobtype中的id，默认全职
 @param from        string 	非必填 	来源id,对应list-from中的id
 @param exp         string 	非必填 	工作经验范围(年)(下划线分隔)，如“3”，“3_5”，“_5”，“5_”
 @param salary      string 	非必填 	薪资范围(元/月)(下划线分隔)，如“3000”，“3000_5000”，“_5000”，“5000_”
 @param scale       string 	非必填 	公司规模(人)(下划线分隔)，如“50”，“30_50”，“_50”，“50_”
 @param pd          string 	非必填 	发布日期(yyyy-MM-dd)
 @param name        string 	非必填 	职位名关键字,如“java工程师”
 @param coname      string 	非必填 	公司名关键字,如“新科兰德”
 @param sort        string 	非必填 	排序方式(true:降序,false:升序)，如“{salaryl:true}”表示按最低薪资降序排列。排序字段名见返回示例
 @param limit       string 	非必填 	每页返回结果数，与skip结合实现分页，最大值为50
 @param skip        string 	非必填 	跳过结果数与limit结合实现分页，最大值为4999
 */
#define kJHAPIS_OL_JOB_JOB                  @"juhe.apis.job.job"                       //8、获取职位列表


/*** 旅游资讯大全 ***/
/**
 @brief 旅游资讯大全 -> 获取景点列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 @param seller      string 	非必填 	商家编号（多个以“,”隔开），如：“1”、“2,4,5”
 @param title       string 	非必填 	景点关键字，如：“欢乐谷”
 @param cityId      string 	非必填 	城市编号（多个以“,”隔开），如：“73_2”、“73_2,88_2”
 @param price       string 	非必填 	价格区间，如：“100_200”、“100_”、“_100”
 @param grade       string 	非必填 	景点级别，如：“3”、“4,5”
 @param sort        string 	非必填 	排序，如:“comm_asc”、“comm_desc”、“price_asc”、“price_desc” 目前仅4种方式，默认第1种
 @param skip        string 	非必填 	跳过数目，如：“300” 默认每页显示50条
 */
#define kJHAPIS_OL_TRAVEL_SCENERY_LIST          @"juhe.apis.travel.scenery.list"                //1、获取景点列表

/**
 @brief 旅游资讯大全 -> 获取门票信息
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	Y 	接口版本当前1
 @param seller      string 	非必填 	商家编号（多个以“,”隔开），如：“1”、“2,4,5”
 @param title       string 	非必填 	景点关键字，如：“欢乐谷”
 @param cityId      string 	非必填 	城市编号（多个以“,”隔开），如：“73_2”、“73_2,88_2”
 @param price       string 	非必填 	价格区间，如：“100_200”、“100_”、“_100”
 @param grade       string 	非必填 	景点级别，如：“3”、“4,5”
 @param sort        string 	非必填 	排序，如:“comm_asc”、“comm_desc”、“price_asc”、“price_desc” 目前仅4种方式，默认第1种
 @param skip        string 	非必填 	跳过数目，如：“300” 默认每页显示50条
 */
#define kJHAPIS_OL_TRAVEL_SCENERY_TICKETINFO    @"juhe.apis.travel.scenery.ticketinfo"      //2、获取门票信息

/**
 @brief 旅游资讯大全 -> 获取景点商家
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_SCENERY_SELLERLIST    @"juhe.apis.travel.scenery.sellerlist"      //3、获取景点商家

/**
 @brief 旅游资讯大全 -> 获取景点级别
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_SCENERY_GRADELIST     @"juhe.apis.travel.scenery.gradelist"       //4、获取景点级别
/**
 @brief 旅游资讯大全 -> 获取酒店列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 @param seller      string 	非必填 	商家编号（多个以“,”隔开），如：“1”、“2,4”
 @param title       string 	非必填 	酒店关键字，如：“如家”
 @param cityId      string 	非必填 	城市编号（多个以“,”隔开），如：“73_2”、“73_2,77_2”
 @param price       string 	非必填 	价格区间，如：“100_200”“100_”“_100”
 @param facility 	string 	非必填 	酒店设施（多个以“,”隔开），如：“1”“2,3”“4,5,8”
 @param grade       string 	非必填 	酒店级别（多个以“,”隔开），如：“3”“4,5”
 @param sort        string 	非必填 	排序，如:“comm_asc”“comm_desc”“price_asc”“price_desc” 目前仅4种方式，默认第1种
 @param skip        string 	非必填 	跳过数目，如：“300” 默认每页显示50条
 */
#define kJHAPIS_OL_TRAVEL_HOTEL_LIST            @"juhe.apis.travel.hotel.hotellist"       //5、获取酒店列表

/**
 @brief 旅游资讯大全 -> 获取酒店房间信息
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 @param seller      int 	必填 	商家编号，如：“1”
@param  hid         int 	必填 	酒店id，如：“2466”
 */
#define kJHAPIS_OL_TRAVEL_HOTEL_ROOMINFO         @"juhe.apis.travel.hotel.roominfo"          //6、获取酒店房间信息

/**
 @brief 旅游资讯大全 -> 获取酒店级别
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_HOTEL_GRADELIST       @"juhe.apis.travel.hotel.gradelist"         //7、获取酒店级别

/**
 @brief 旅游资讯大全 -> 获取酒店商家
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_HOTEL_SELLERLIST      @"juhe.apis.travel.hotel.sellerlist"        //8、获取酒店商家

/**
 @brief 旅游资讯大全 -> 获取地区列表
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_AREALIST              @"juhe.apis.travel.arealist"                //9、获取地区列表

/**
 @brief 旅游资讯大全 -> 获取酒店设施
 @param pname       string 	必填 	申请接口时填写的包名,如：cn.juhe.test
 @param v           string 	必填 	接口版本当前1
 */
#define kJHAPIS_OL_TRAVEL_HOTEL_FACILITYLIST    @"juhe.apis.travel.hotel.facilitylist"      //10、获取酒店设施


/************* 其他数据 OTHER ************************************************************************************************
 全国WIFI             kJHAPIS_OTHER_WIFI_XXX
 苏州实时公交          kJHAPIS_OTHER_SZBUSLINE_XXX
 实时公共自行车         kJHAPIS_OTHER_BIKE_XXX
 实时IP代理库          kJHAPIS_OTHER_PROXY_XXX
 */

/*** 全国WIFI ***/
#define kJHAPIS_OTHER_WIFI_LOCAL                @"juhe.apis.wifi.local"                     //1、查询周边WIFI
#define kJHAPIS_OTHER_WIFI_REGION               @"juhe.apis.wifi.region"                    //2、按城市查询WIFI

/*** 苏州实时公交 ***/
#define kJHAPIS_OTHER_SZBUSLINE_STATIONCODE     @"juhe.apis.szbusline.stationcode"          //1、站台(编码)查询
#define kJHAPIS_OTHER_SZBUSLINE_BUSSTATION      @"juhe.apis.szbusline.busstation"           //2、根据站台查询公交状态
#define kJHAPIS_OTHER_SZBUSLINE_BUSLINECODE     @"juhe.apis.szbusline.buslinecode"          //3、线路(编码)查询
#define kJHAPIS_OTHER_SZBUSLINE_BUSLINEINFO     @"juhe.apis.szbusline.buslineinfo"          //4、根据线路编码查询详细信息

/*** 实时公共自行车  ***/
#define kJHAPIS_OTHER_BIKE_SZ                   @"juhe.apis.bike.sz"                        //1、苏州
#define kJHAPIS_OTHER_BIKE_CS                   @"juhe.apis.bike.cs"                        //2、常熟
#define kJHAPIS_OTHER_BIKE_KS                   @"juhe.apis.bike.ks"                        //3、昆山
#define kJHAPIS_OTHER_BIKE_WJ                   @"juhe.apis.bike.wj"                        //4、吴江
#define kJHAPIS_OTHER_BIKE_NT                   @"juhe.apis.bike.nt"                        //5、南通
#define kJHAPIS_OTHER_BIKE_YX                   @"juhe.apis.bike.yx"                        //6、宜兴
#define kJHAPIS_OTHER_BIKE_XZ                   @"juhe.apis.bike.xz"                        //7、徐州
#define kJHAPIS_OTHER_BIKE_ZJ                   @"juhe.apis.bike.zj"                        //8、镇江

/*** 实时IP代理库 ***/
#define kJHAPIS_OTHER_PROXY_FATCH               @"juhe.apis.proxy.fatch"                     //1、获取免费代理


/*************  电商 EX **********************************************************************************************
 
 条码查询                    kJHAPIS_EX_JHBAR_XXX
 
 */
/**
 @brief 条码查询 -> 1、省份查询
 @param pname       string 	必填 	申请接口时填写的包名,如：com.aiside.JuheBarcodeDemo
 @param v           string 	必填 	接口版本当前2.0
 */
#define kJHAPIS_EX_JHBAR_PROVINCE        @"juhe.apis.jhbar.province"               //1、省份查询
/**
 @brief 条码查询 -> 2、城市查询
 @param pname       string 	必填 	申请接口时填写的包名,如：com.aiside.JuheBarcodeDemo
 @param v           string 	必填 	接口版本当前2.0
 */
#define kJHAPIS_EX_JHBAR_CITY            @"juhe.apis.jhbar.city"                   //2、城市查询
/**
 @brief 条码查询 -> 3、获取条码信息
 @param pname       string 	必填 	申请接口时填写的包名,如：com.aiside.JuheBarcodeDemo
 @param v           string 	必填 	接口版本当前2.0
 @param barcode     string 	必填 	商品条码
 @param cityid      string 	必填 	城市查询中对应的城市编号
 */
#define kJHAPIS_EX_JHBAR_BAR             @"juhe.apis.jhbar.bar"                    //3、获取条码信息
/**
 @brief 条码查询 -> 4、获取商品购买链接
 @param pname       string 	必填 	申请接口时填写的包名,如：com.aiside.JuheBarcodeDemo
 @param v           string 	必填 	接口版本当前2.0
 @param dsid        string 	必填 	获取条码信息中对应的电商平台编号
 @param cityid      string 	必填 	城市查询中对应的城市编号
 */
#define kJHAPIS_EX_JHBAR_BUY             @"juhe.apis.jhbar.buy"                    //4、获取商品购买链接



/* END */