#ifndef __NET_H__
#define __NET_H__
#define BYTE 	unsigned char

typedef struct _netinfo 
{
	int conn_mod;	/*0-STATIC  1-DHCP */
	char ipaddr[16];
	char netmask[16];
	char gateway[16];
	char dns[2][16];
} NETINFO;

//wifi��������
#define SSID_LEN          37
#define WIFIPASS_LEN  50

//wifi״̬
enum wifi_stat_type
{
	WIFI_STAT_CLOSE=0,  /*�ر�wifi*/
	WIFI_STAT_OPEN=1    /*����wifi*/
};

//wifi��������
enum wifi_net_type
{
	WIFI_TYPE_INFRA=0,
	WIFI_TYPE_ADHOC=1
};

//wifi��ȫģʽ
enum wifi_enc_type
{
	WIFI_ENC_NONE=0,
	WIFI_ENC_WEP,
	WIFI_ENC_TKIP,
	WIFI_ENC_AES
};

//wifi��֤ģʽ
enum wifi_auth_mode
{
	WIFI_AUTH_OPEN=0,
	WIFI_AUTH_SHARED,
	WIFI_AUTH_WPAPSK,
	WIFI_AUTH_WPA2PSK
};

//wifi����
typedef struct tag_remote_wificfg
{
	BYTE  netstat;   /*״̬0:�ر�1:����*/
	
	BYTE  nettype;  /*��������0:Infra 1:Adhoc  */         

	BYTE  enctype; /*��ȫģʽ0:NONE 1:WEP 2:TKIP 3:AES */
	
	BYTE  authmode;  /*��֤ģʽ0:OPEN 1:SHARED 2:WPAPSK 3:WPA2PSK */        

	BYTE  defkeyid;  /*Ĭ����ԿID��(1,2,3,4) */

	char   ssid[SSID_LEN];    /*ssid */

	char   pass[WIFIPASS_LEN];   /*����*/
	
}REMOTE_WIFICFG;

///////////////����----begin///////////
//wifi��Ϣ
typedef struct tag_remote_wifi_info
{
	BYTE  nettype;  /*��������0:Infra 1:Adhoc  */         

	BYTE  enctype; /*��ȫģʽ0:NONE 1:WEP 2:TKIP 3:AES */
	
	BYTE  authmode;  /*��֤ģʽ0:OPEN 1:SHARED 2:WPAPSK 3:WPA2PSK */        

	char   ssid[SSID_LEN];    /*ssid */

}REMOTE_WIFI_INFO;

//wifi����
#define WIFI_FIND_LEN 30
typedef struct tag_remote_wifi_find
{
	int   count;
	REMOTE_WIFI_INFO  wifi_info[WIFI_FIND_LEN];	
}REMOTE_WIFI_FIND;

//wifi��Ϣ
typedef struct tag_wifi_info_com
{
	BYTE  nettype;  /*��������0:Infra 1:Adhoc  */         

	BYTE  enctype; /*��ȫģʽ0:NONE 1:WEP 2:TKIP 3:AES */
	
	BYTE  authmode;  /*��֤ģʽ0:OPEN 1:SHARED 2:WPAPSK 3:WPA2PSK */
	BYTE  signal;   // signal intensity 0--100%

	char   ssid[SSID_LEN];    /*ssid */

}WIFI_INFO_COM;
typedef struct tag_wifi_find_com
{
	int   count;
	WIFI_INFO_COM  wifi_info[WIFI_FIND_LEN];	
}WIFI_FIND_COM;



/*****************************************************************************
 �� �� ��  : init_net_server
 ��������  : ��ʼ�������
 �������  : ��
 �������  : ��
 �� �� ֵ  :  -1:faile  0:sucess
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : video_device.h
    �޸�����   : �����ɺ���

*****************************************************************************/
int sdk_init_net_server();


/*****************************************************************************
 �� �� ��  : start_net_server
 ��������  : �������������
 �������  : ��
 �������  : ��
 �� �� ֵ  : -1:faile  0:sucess
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : video_device.h
    �޸�����   : �����ɺ���

*****************************************************************************/
int sdk_start_net_server();
int sdk_stop_net_server();

/**********wireless *************/
/*****************************************************************************
 �� �� ��  : set_netwifi_params
 ��������  : ����wifi����
 �������  : REMOTE_WIFICFG *wifi_vars  
 �������  : ��
 �� �� ֵ  : -1:fail, 0:succ
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : video_device.h
    �޸�����   : �����ɺ���

*****************************************************************************/

int   sdk_set_netwifi_params(REMOTE_WIFICFG *wifi_vars);

/*****************************************************************************
 �� �� ��  : set_netwifi_params_notsavecfg
 ��������  : ��ȡwifi����
 �������  : REMOTE_WIFICFG *wifi_vars  
 �������  : ��
 �� �� ֵ  : -1:fail, 0:succ
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : video_device.h
    �޸�����   : �����ɺ���

*****************************************************************************/
int sdk_get_netwifi_params(REMOTE_WIFICFG *wifi_vars);


/*****************************************************************************
 �� �� ��  : search_netwifi_com
 ��������  : ��������·����0
 �������  : WIFI_FIND_COM *wifi_find  
 �������  : ��
 �� �� ֵ  : 0:succ , -1:fail
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : video_device.h
    �޸�����   : �����ɺ���

*****************************************************************************/
int  sdk_search_netwifi_com(WIFI_FIND_COM *wifi_find);

//wired net
/*****************************************************************************
 �� �� ��  : get_net_params
 ��������  : ���������������
 �������  : NETINFO *net_param  
 �������  : ��
 �� �� ֵ  :  -1:faile  0:sucess
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : 9527
    �޸�����   : �����ɺ���

*****************************************************************************/

int  sdk_set_net_params(NETINFO *net_param);


/*****************************************************************************
 �� �� ��  : get_net_params
 ��������  : ��ȡ�����������
 �������  : NETINFO *net_param  
 �������  : ��
 �� �� ֵ  : -1:faile  0:sucess

 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��6��18��
    ��    ��   : 9527
    �޸�����   : �����ɺ���

*****************************************************************************/
int sdk_get_net_params(NETINFO *net_param);




#endif

