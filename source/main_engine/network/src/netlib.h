/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, bingchuan

 ******************************************************************************
  �� �� ��   : net.h
  �� �� ��   : v1.0
  ��    ��   : 9527
  ��������   : 2014��10��27��
  ��������   : net.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��10��27��
    ��    ��   : 9527
    �޸�����   : �����ļ�

******************************************************************************/

 /*******************����ͷ�ļ�******************/

 /*******************�ⲿ����˵��****************/

 /*****************�ⲿ����ԭ��˵��**************/

 /*****************�ڲ�����ԭ��˵��**************/

 /********************ȫ�ֱ���*******************/

 /*******************��������********************/

 /*******************�궨��**********************/

 /*******************����ʵ��********************/

#ifndef __NET_H__
#define __NET_H__

#include "sdk_struct.h"
#include "adapt.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

typedef int (*NetStatusCB)(void *data); //����Ƶ���ݻص�

extern int  sdk_init_net_server(sdk_eth_cfg_t *net_param,sdk_wifi_cfg_t *wifi_param);
extern int  sdk_get_net_params(sdk_eth_cfg_t *net_param);
extern int  sdk_search_ap(sdk_wifi_search_t *ap_list);
extern int sdk_set_mac_params(const char *if_name,const char *mac);
extern int  sdk_set_net_params(sdk_eth_cfg_t *net_param);
extern int sdk_set_wifi_params(sdk_wifi_cfg_t *wifi_cfg);

extern int sdk_start_net_server(NetStatusCB networkCB/*,char *ssid*/);

extern int sdk_stop_net_server();

extern int check_iwlist_scanning(char *inSsid, char *inKey, WiFi_Item_Config *poutItemInfo);
extern int check_connect_handle(WiFi_Item_Config *pItemApInfo);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __NET_H__ */

