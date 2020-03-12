# 指纹锁——ZWL2
### 功能
* 指纹开锁
* 智能配网
* OTA升级
* 加入HA自动发现
### 使用方法
1. MQTT服务器配置`/app/include/mqtt_config.h`
   * `MQTT_HOST`MQTT服务器域名或IP
   * `MQTT_PORT`MQTT服务器端口号
   * `MQTT_USER`MQTT用户名
   * `MQTT_PASS`MQTT密码

2. MQTT主题配置`/app/include/mqtt_config.h`

    * `OTA_TOPIC`OTA主题
    * `LWT_TOPIC`遗嘱主题
    * `BIRTH_TOPIC`出生主题
    * `CONTROL_TOPIC`控制主题
    * `STATUS_TOPIC`状态主题
    * HA实体注册主题：
        * `SENSOR_LOCK_TOPIC`锁开关状态实体
        * `SENSOR_ISHOME_TOPIC`离家模式实体
        * `SWITCH_TOPIC`锁开关状态实体

### 指纹

* **添加指纹**
  1. 短按按键
  2. 向控制主题发送 `R`

* **删除指纹**

  1. 删除单个：

     向控制主题发送 `D2`+指纹编号(三位数)

  2. 删除多个：

     向控制主题发送 `D2`+起始指纹编号(三位数)+`T`+结束指纹编号(三位数)

### OAT升级

- 使用ota升级话题发送升级文件获取地址
- 消息格式`{"url"="http://yourdomain.com:port/directory/"}`

### 智能配网

* 支持AirKiss与ESPTouch

* 使用
  1. 长按D3进入配网模式
  2. 搜索到信号后指纹模块开始闪烁
  3. 在APP/微信中开始配网

### 其他

* IO分配：
  * D2 -> 门锁传感器
  * D5 -> 门锁开关
  * D3 -> 按键
  * D1 -> 指纹模块触发
  * RX -> 指纹模块TX
  * TX -> 指纹模块RX