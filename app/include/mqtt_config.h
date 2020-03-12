#ifndef __MQTT_CONFIG_H__
#define __MQTT_CONFIG_H__

/*DEFAULT CONFIGURATIONS*/

#define MQTT_HOST			"yourhost"       //MQTT服务器地址(IPv4 | 域名)"
#define MQTT_PORT			1883            //端口
#define MQTT_BUF_SIZE		2048
#define MQTT_KEEPALIVE		120	            /*second*/

#define MQTT_USER			"mqtt_username"
#define MQTT_PASS			"mqtt_password"

#define OTA_TOPIC           "/esp8266/ota/%s"
#define LWT_TOPIC           "/ZWL2/lwt/%s"
#define BIRTH_TOPIC         "/ZWL2/birth/%s"
#define CONTROL_TOPIC       "LOCK/ZWL2/%s/set"
#define STATUS_TOPIC        "LOCK/ZWL2/%s/status"

//HA注册实体主题
#define SENSOR_LOCK_TOPIC   "hatest/binary_sensor/%s/lock/config"
#define SENSOR_ISHOME_TOPIC "hatest/binary_sensor/%s/ishome/config"
#define SWITCH_TOPIC        "hatest/lock/%s/lock/config"

//HA注册实体消息
#define SENSOR_LOCK_DATA    "{\"name\":\"门锁状态\",\
                            \"stat_t\":\"%s\",\
                            \"pl_on\":\"UNLOCKED\",\
                            \"pl_off\":\"LOCKED\"}"

#define SENSOR_ISHOME_DATA  "{\"name\":\"离家模式\",\
                            \"stat_t\":\"%s\",\
                            \"pl_on\":\"levhome\",\
                            \"pl_off\":\"athome\"}"

#define SWITCH_LOCK_DATA    "{\"name\":\"门锁\",\
                             \"cmd_t\":\"%s\",\
                             \"stat_t\":\"%s\",\
                             \"pl_lock\":\"LOCK\",\
                             \"pl_unlk\":\"UNLOCK\"}"


#define LWT_MESSAGE         "offline"

#define MQTT_RECONNECT_TIMEOUT 	5	        /*second*/

#define DEFAULT_SECURITY	0
#define QUEUE_BUFFER_SIZE		 		2048

//#define PROTOCOL_NAMEv31	                /*MQTT version 3.1 compatible with Mosquitto v0.15*/
#define PROTOCOL_NAMEv311			        /*MQTT version 3.11 compatible with https://eclipse.org/paho/clients/testing/*/

#endif // __MQTT_CONFIG_H__
