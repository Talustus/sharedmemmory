/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  ����ģ��ӿ�
 *
 *        Version:  1.0
 *        Created:  2014��10��10�� 00ʱ56��41��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef __main_h__
#define __main_h__


/*
 * ȫ���������Ͷ���
 */
#include "sdk_global.h"

/*
 * ���������� ���ݽṹ����
 */
#include "sdk_struct.h"

/*
 * ����Э�鼰�ӿڶ���
 */
#include "sdk_netlib.h"

/*----------- ������ϢID���� -----------*/

/*
 * ��ϢID��ѭ"ֻ����׷���޸ģ�������ı�ԭ����
 * ����ģ��ʹ����ϢID��Ϊ�����洢��ԪID���޸���ϢID��Ӱ����������ļ�.
 */
typedef enum _SDK_MAIN_MSG_ID
{
    SDK_MAIN_MSG_KEEPLIVE       = 0X00, //    	
    SDK_MAIN_MSG_VERSION        = 0x01, //  �汾��Ϣ       sdk_version_t
    SDK_MAIN_MSG_SYS_CFG        = 0x02, //	ϵͳ����       sdk_sys_cfg_t
    SDK_MAIN_MSG_STATUS         = 0x03, //	ϵͳ״̬       sdk_status_t
    SDK_MAIN_MSG_PARAM_DEFAULT  = 0x04, //	4 Ĭ�ϲ���     sdk_default_param_t, SDK_PARAM_MASK_ID_E
    SDK_MAIN_MSG_CLOUD_ID  	    = 0x05, //  ��ƽ̨UID��Ϣ  sdk_cloud_uid_t 

    SDK_MAIN_MSG_WIFI_SEARCH    = 0X06, //	WIFI����	  sdk_wifi_search_t
    SDK_MAIN_MSG_LOG                  , //	��־����    SDK_LOG_OP_E
    SDK_MAIN_MSG_NET_MNG_CFG          , //	��������    sdk_net_mng_cfg_t
    SDK_MAIN_MSG_PTZ_CFG              , //  ��̨����    sdk_ptz_param_t
    SDK_MAIN_MSG_PTZ_CONTROL          , //  ��̨����    SDK_PTZ_MSG_ID_E

    SDK_MAIN_MSG_BAIDU_INFO     = 0x0B, // �ٶȵ�һ��������Ϣ 	sdk_register_cfg_t
    SDK_MAIN_MSG_WIFI_PARAM_CFG = 0X0C, //	WIFI����	 sdk_wifi_cfg_t
    SDK_MAIN_MSG_CLOSE_SYSTEM		  , //  13 �ر�ϵͳ  pmsg->args:SDK_CLOSE_SYS_OP_E
    SDK_MAIN_MSG_ENCODE_CFG           , //  14 ��������       sdk_encode_t 
    SDK_MAIN_MSG_RECORD_CFG           , //	15 ¼������       sdk_record_cfg_t
    SDK_MAIN_MSG_RECORD_QUERY         , //  16 ¼���ѯ       sdk_record_item_t, sdk_record_cond_t
    SDK_MAIN_MSG_MOTION_CFG           , //  17 ��Ƶ�ƶ�����   sdk_motion_cfg_t
    SDK_MAIN_MSG_ALARM_IN_CFG         , //	18 �ⲿ������������sdk_alarm_in_cfg_t
    SDK_MAIN_MSG_HIDE_CFG             , //	19 ��Ƶ�ڱα�������sdk_hide_cfg_t
    SDK_MAIN_MSG_LOST_CFG             , //	20 ��Ƶ��ʧ����   sdk_lost_cfg_t

    SDK_MAIN_MSG_OSD_CFG              , //  22 OSD����       sdk_osd_cfg_t
    SDK_MAIN_MSG_AUDIO_CONTROL	      , //  22 ��Ƶ����  args:SDK_AUDIO_CONTROL_OP_E; extend:����/�ر�
    SDK_MAIN_MSG_SNAP_CONTROL	  	  , //  23 ץ��ͼƬ  
    SDK_MAIN_MSG_SYSTIME		  	  , //	25 ϵͳʱ������	  sdk_date_t
    SDK_MAIN_MSG_NET_LINK_CFG		  , //	24 ������������ sdk_eth_cfg_t

    SDK_MAIN_MSG_USER                 , //  �û�����    SDK_USER_OP_E
    SDK_MAIN_MSG_COMM_CFG			  , //  ��������       sdk_comm_cfg_t
    SDK_MAIN_MSG_OVERLAY_CFG		  , //  �ڵ���������   sdk_overlay_cfg_t
    SDK_MAIN_MSG_DISK		  		  , //	���̹���	pmsg->args:SDK_DISK_OP_E
    SDK_MAIN_MSG_SERIAL_CFG		      , //	���ڲ�������	  sdk_serial_func_cfg_t
    SDK_MAIN_MSG_IMAGE_ATTR_CFG       , //	ͼ����������   sdk_image_attr_t
    SDK_MAIN_MSG_TV_CFG         	  , //	TV����   sdk_vo_sideSize_t
    SDK_MAIN_MSG_NOTIFY               , //  ֪ͨ�¼�����/ֹͣ args:SDK_EVENT_TYPE_E, chann:ͨ��, extend:����/ֹͣ.
    SDK_MAIN_MSG_DEVLIST              , //  GUI ��ѯ�豸�б� sdk_device_t
    SDK_MAIN_MSG_MANUAL_REC		      , //	�ֶ���(�ر�)¼�� 	sdk_manual_record_t
    SDK_MAIN_MSG_MANUAL_ALMIN		  , //	�ֶ���(�ر�)�������� 	sdk_manual_alarmin_t
    SDK_MAIN_MSG_MANUAL_ALMOUT	      , //	�ֶ���(�ر�)�������  sdk_manual_alarmout_t
    SDK_MAIN_MSG_RECORD_BACKUP	      , //	¼�񱸷�  pmsg->args:SDK_BACKUP_OP_E
    SDK_MAIN_MSG_PLATFORM_CFG         , //  ƽ̨��Ϣ����
    SDK_MAIN_MSG_CHANGE_REMOTE_IP     , //  �ı�Զ���豸��ip sdk_remote_net_t
    SDK_MAIN_MSG_DDNS_CFG			  , //	DDNS���� sdk_ddns_cfg_t
    SDK_MAIN_MSG_CAPABILITY		      , //	�豸��������Ϣ sdk_device_capability_t
    SDK_MAIN_MSG_UPNP_CFG             , //  UPNP ����
    SDK_MAIN_MSG_SCREEN_CFG           , //  screen���� sdk_screen_t
    SDK_MAIN_MSG_CRUISE_CTL           , //  ����Ѳ��     �޶�Ӧ�ṹ�壬ֻ��ID
    SDK_MAIN_MSG_PRESET_SET           , //  Ԥ�õ㼯�� sdk_preset_param_t
    SDK_MAIN_MSG_PREVIEW_TOUR         , //  Ԥ��Ѳ������    sdk_tour_t
    SDK_MAIN_MSG_3A_ATTR_CFG          , //	3A��������   sdk_3a_attr_t
    SDK_MAIN_MSG_UPGRAD               , //	����        SDK_UPGRAD_OP_E
    SDK_MAIN_MSG_SCHED_CFG		      , //	�����ų�	   
    SDK_MAIN_MSG_REGIONAL_CFG         , //  ����������� ����hz ���� �������  sdk_regional_param_t
    SDK_MAIN_MSG_IODEV_PARAM		  , //	iodev�豸����  led  ��������  sdk_iodev_param_t
    SDK_MAIN_MSG_AUDIO_DETECT_CFG     , //  �������   sdk_audio_detect_cfg_t
    SDK_MAIN_MSG_MIRROR_FLIP_CFG      , //  ����תʵ��  sdk_mirror_flip_cfg_t  
    SDK_MAIN_MSG_POWER_FREQ_CFG       , // power frequency config msg
    SDK_MAIN_MSG_STOP_SERVER    	  , //  ֹͣ main�����е����з���
    SDK_MAIN_MSG_AWS 				  , //  AWS
    SDK_MAIN_MSG_BUTT
}SDK_MAIN_MSG_ID_E;

typedef enum _SDK_MAIN_USR_ID{
    SDK_USER_AAA,
    SDK_USER_ADD,
    SDK_USER_DEL,
    SDK_USER_MODI,
    SDK_USER_QUERY

}_SDK_MAIN_USR_ID_E;

typedef struct __msg_deviceinfo
{
	unsigned int total; 		// 0: No cards been detected or an unrecognizeable sdcard that could not be re-formatted.
								// -1: if camera detect an unrecognizable sdcard, and could be re-formatted
								// otherwise: return total space size of sdcard (MBytes)								
								
	unsigned int free;			// Free space size of sdcard (MBytes)

	uint8_t szMacAddr[24];	 //MAC STRING
	uint8_t szUID[32];
	uint8_t szPwd[32];	
	uint8_t hardware_ver[64];	   //Ӳ���汾
}SDK_MSG_DEVICEINFO;

typedef int(*sdk_msg_dispatch_cb)(sdk_msg_t *pmsg);

int net_dispatch(sdk_msg_t *pmsg);
int msg_ptz_dispatch(sdk_msg_t *pmsg);
char *net_msg2main_msg_str(int msg_id);
int mcu_operate(int oper_type, int arg, void *p_arg);
int dm_msg_send(int fd, int id, int arg, int ch, void *data, int size, int timeout);
int main_free_system_resources();

#endif //__main_h__




