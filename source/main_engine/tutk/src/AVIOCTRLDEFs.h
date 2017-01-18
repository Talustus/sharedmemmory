/*
 * AVIOCTRLDEFs.h
 *	Define AVIOCTRL Message Type and Context
 *  Created on: 2011-08-12
 *  Author: TUTK
 *
 */


#ifndef _AVIOCTRL_DEFINE_H_
#define _AVIOCTRL_DEFINE_H_

#define BYTE 	unsigned char
#define DWORD 	unsigned int 
#define WORD 	unsigned int
#define BOOL 	unsigned int


#define MACADDR_LEN 	20  
#define NAME_LEN      	32
#define PASSWD_LEN 		16


/////////////////////////////////////////////////////////////////////////////////
/////////////////// Message Type Define//////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// AVIOCTRL Message Type
typedef enum 
{
	IOTYPE_USER_IPCAM_START 					= 0x01FF,
	IOTYPE_USER_IPCAM_STOP	 					= 0x02FF,
	IOTYPE_USER_IPCAM_AUDIOSTART 				= 0x0300,
	IOTYPE_USER_IPCAM_AUDIOSTOP 				= 0x0301,

	IOTYPE_USER_IPCAM_SPEAKERSTART 				= 0x0350,
	IOTYPE_USER_IPCAM_SPEAKERSTOP 				= 0x0351,

	IOTYPE_USER_IPCAM_SETSTREAMCTRL_REQ			= 0x0320,
	IOTYPE_USER_IPCAM_SETSTREAMCTRL_RESP		= 0x0321,
	IOTYPE_USER_IPCAM_GETSTREAMCTRL_REQ			= 0x0322,
	IOTYPE_USER_IPCAM_GETSTREAMCTRL_RESP		= 0x0323,

	IOTYPE_USER_IPCAM_SETMOTIONDETECT_REQ		= 0x0324,
	IOTYPE_USER_IPCAM_SETMOTIONDETECT_RESP		= 0x0325,
	IOTYPE_USER_IPCAM_GETMOTIONDETECT_REQ		= 0x0326,
	IOTYPE_USER_IPCAM_GETMOTIONDETECT_RESP		= 0x0327,
	
	IOTYPE_USER_IPCAM_GETSUPPORTSTREAM_REQ		= 0x0328,	// Get Support Stream
	IOTYPE_USER_IPCAM_GETSUPPORTSTREAM_RESP		= 0x0329,	

	IOTYPE_USER_IPCAM_DEVINFO_REQ				= 0x0330,
	IOTYPE_USER_IPCAM_DEVINFO_RESP				= 0x0331,

	IOTYPE_USER_IPCAM_SETPASSWORD_REQ			= 0x0332,
	IOTYPE_USER_IPCAM_SETPASSWORD_RESP			= 0x0333,

	IOTYPE_USER_IPCAM_LISTWIFIAP_REQ			= 0x0340,
	IOTYPE_USER_IPCAM_LISTWIFIAP_RESP			= 0x0341,
	IOTYPE_USER_IPCAM_SETWIFI_REQ				= 0x0342,
	IOTYPE_USER_IPCAM_SETWIFI_RESP				= 0x0343,
	IOTYPE_USER_IPCAM_GETWIFI_REQ				= 0x0344,
	IOTYPE_USER_IPCAM_GETWIFI_RESP				= 0x0345,
	IOTYPE_USER_IPCAM_SETWIFI_REQ_2				= 0x0346,
	IOTYPE_USER_IPCAM_GETWIFI_RESP_2			= 0x0347,

	IOTYPE_USER_IPCAM_SETRECORD_REQ				= 0x0310,
	IOTYPE_USER_IPCAM_SETRECORD_RESP			= 0x0311,
	IOTYPE_USER_IPCAM_GETRECORD_REQ				= 0x0312,
	IOTYPE_USER_IPCAM_GETRECORD_RESP			= 0x0313,

	IOTYPE_USER_IPCAM_SETRCD_DURATION_REQ		= 0x0314,
	IOTYPE_USER_IPCAM_SETRCD_DURATION_RESP  	= 0x0315,
	IOTYPE_USER_IPCAM_GETRCD_DURATION_REQ		= 0x0316,
	IOTYPE_USER_IPCAM_GETRCD_DURATION_RESP  	= 0x0317,

	IOTYPE_USER_IPCAM_LISTEVENT_REQ				= 0x0318,
	IOTYPE_USER_IPCAM_LISTEVENT_RESP			= 0x0319,
	
	IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL 		= 0x031A,
	IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_RESP 	= 0x031B,
	
	IOTYPE_USER_IPCAM_GETAUDIOOUTFORMAT_REQ		= 0x032A,
	IOTYPE_USER_IPCAM_GETAUDIOOUTFORMAT_RESP	= 0x032B,

	IOTYPE_USER_IPCAM_GET_EVENTCONFIG_REQ		= 0x0400,	// Get Event Config Msg Request
	IOTYPE_USER_IPCAM_GET_EVENTCONFIG_RESP		= 0x0401,	// Get Event Config Msg Response
	IOTYPE_USER_IPCAM_SET_EVENTCONFIG_REQ		= 0x0402,	// Set Event Config Msg req
	IOTYPE_USER_IPCAM_SET_EVENTCONFIG_RESP		= 0x0403,	// Set Event Config Msg resp

	IOTYPE_USER_IPCAM_SET_ENVIRONMENT_REQ		= 0x0360,
	IOTYPE_USER_IPCAM_SET_ENVIRONMENT_RESP		= 0x0361,
	IOTYPE_USER_IPCAM_GET_ENVIRONMENT_REQ		= 0x0362,
	IOTYPE_USER_IPCAM_GET_ENVIRONMENT_RESP		= 0x0363,
	
	IOTYPE_USER_IPCAM_SET_VIDEOMODE_REQ			= 0x0370,	// Set Video Flip Mode
	IOTYPE_USER_IPCAM_SET_VIDEOMODE_RESP		= 0x0371,
	IOTYPE_USER_IPCAM_GET_VIDEOMODE_REQ			= 0x0372,	// Get Video Flip Mode
	IOTYPE_USER_IPCAM_GET_VIDEOMODE_RESP		= 0x0373,
	
	IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ		= 0x0380,	// Format external storage
	IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_RESP		= 0x0381,	
	
	IOTYPE_USER_IPCAM_PTZ_COMMAND				= 0x1001,	// P2P PTZ Command Msg

	IOTYPE_USER_IPCAM_EVENT_REPORT				= 0x1FFF,	// Device Event Report Msg
	IOTYPE_USER_IPCAM_RECEIVE_FIRST_IFRAME		= 0x1002,	// Send from client, used to talk to device that
															// client had received the first I frame
	
	
	IOTYPE_USER_IPCAM_GET_FLOWINFO_REQ			= 0x0390,
	IOTYPE_USER_IPCAM_GET_FLOWINFO_RESP			= 0x0391,
	IOTYPE_USER_IPCAM_CURRENT_FLOWINFO			= 0x0392,
	
	IOTYPE_USER_IPCAM_GET_TIMEZONE_REQ          = 0x3A0,
	IOTYPE_USER_IPCAM_GET_TIMEZONE_RESP         = 0x3A1,
	IOTYPE_USER_IPCAM_SET_TIMEZONE_REQ          = 0x3B0,
	IOTYPE_USER_IPCAM_SET_TIMEZONE_RESP         = 0x3B1,
    

    // dropbox support
    IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_REQ      = 0x500,
    IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_RESP     = 0x501,
    IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_REQ      = 0x502,
    IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_RESP     = 0x503,
    
//user defined
	IOTYPE_USER_IPCAM_USER_DEFINED              = 0x40000,

	IOTYPE_USER_IPCAM_GET_ATTRIBUTE_REQ			= 0x40001,	//��ȡ�豸֧�ֵ�����
	IOTYPE_USER_IPCAM_GET_ATTRIBUTE_RESP		= 0x40002,

	IOTYPE_USER_IPCAM_GET_VIDEO_DISPLAY_REQ		= 0x40003,	//��Ƶ��ʾ����
	IOTYPE_USER_IPCAM_GET_VIDEO_DISPLAY_RESP	= 0x40004,
	IOTYPE_USER_IPCAM_SET_VIDEO_DISPLAY_REQ		= 0x40005,
	IOTYPE_USER_IPCAM_SET_VIDEO_DISPLAY_RESP	= 0x40006,

	IOTYPE_USER_IPCAM_GET_ALARM_ARG_REQ			= 0x40007,	//�澯��صĲ���
	IOTYPE_USER_IPCAM_GET_ALARM_ARG_RESP		= 0x40008,
	IOTYPE_USER_IPCAM_SET_ALARM_ARG_REQ			= 0x40009,
	IOTYPE_USER_IPCAM_SET_ALARM_ARG_RESP		= 0x40010,

	IOTYPE_USER_IPCAM_GET_EMAIL_ARG_REQ			= 0x40011,	//email��صĲ���
	IOTYPE_USER_IPCAM_GET_EMAIL_ARG_RESP		= 0x40012,
	IOTYPE_USER_IPCAM_SET_EMAIL_ARG_REQ			= 0x40013,
	IOTYPE_USER_IPCAM_SET_EMAIL_ARG_RESP		= 0x40014,

	IOTYPE_USER_IPCAM_FACTORY_SETTINGS_REQ		= 0x40015,	//�ָ���������
	IOTYPE_USER_IPCAM_FACTORY_SETTINGS_RESP		= 0x40016,

	IOTYPE_USER_IPCAM_SET_DEVICE_INFO_REQ		= 0x40017,	//�����豸��Ϣ
	IOTYPE_USER_IPCAM_SET_DEVICE_INFO_RESP		= 0x40018,	

	IOTYPE_USER_IPCAM_REBOOT_SYSTEM_REQ			= 0x40019,	//����ϵͳ
	IOTYPE_USER_IPCAM_REBOOT_SYSTEM_RESP		= 0x40020,

	IOTYPE_USER_IPCAM_GET_PTZ_STATUS_REQ		= 0x40021,	//��ȡ��̨״̬	
	IOTYPE_USER_IPCAM_GET_PTZ_STATUS_RESP		= 0x40022,	

	IOTYPE_USER_IPCAM_GET_VIDEO_QUALITY_REQ		= 0x40023,	//��ȡ��Ƶ����	
	IOTYPE_USER_IPCAM_GET_VIDEO_QUALITY_RESP	= 0x40024,
	IOTYPE_USER_IPCAM_SET_VIDEO_QUALITY_REQ		= 0x40025,	//������Ƶ����	
	IOTYPE_USER_IPCAM_SET_VIDEO_QUALITY_RESP	= 0x40026,

	IOTYPE_USER_IPCAM_TEST_EMAIL_ARG_REQ		= 0X40027,	//����email����
	IOTYPE_USER_IPCAM_TEST_EMAIL_ARG_RESP		= 0X40028,
	IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_REQ		= 0X40029,	//����ϵͳ
	IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_RESP		= 0X40030,
    
	IOTYPE_USER_IPCAM_GET_ALARM_LIST_REQ		= 0X40031,	//��ѯ�¼��б���־��0x0318���ڲ�ѯ�¼�¼���ļ���
	IOTYPE_USER_IPCAM_GET_ALARM_LIST_RESP		= 0X40032,

	IOTYPE_USER_IPCAM_GET_AUDIO_MOTION_REQ		= 0X40033,	//��ȡ�������
	IOTYPE_USER_IPCAM_GET_AUDIO_MOTION_RESP		= 0X40034,
	IOTYPE_USER_IPCAM_SET_AUDIO_MOTION_REQ		= 0X40035,	//���������������
	IOTYPE_USER_IPCAM_SET_AUDIO_MOTION_RESP		= 0X40036,

	IOTYPE_USER_IPCAM_GET_NET_REQ				= 0X40037,	//��ȡ��������
	IOTYPE_USER_IPCAM_GET_NET_RESP				= 0X40038,
	IOTYPE_USER_IPCAM_SET_NET_REQ				= 0X40039,	//������������
	IOTYPE_USER_IPCAM_SET_NET_RESP				= 0X40040,

	IOTYPE_USER_IPCAM_GET_SNAP_REQ				= 0X40041,	//�ͻ���ץ������
	IOTYPE_USER_IPCAM_GET_SNAP_RESP				= 0X40042,

	IOTYPE_USER_IPCAM_DEFAULT_VIDEO_REQ			= 0X40043,	//�ͻ�������Ĭ�ϵ���Ƶ�ֱ��ʡ�������֡�ʣ���Ƶ����
	IOTYPE_USER_IPCAM_DEFAULT_VIDEO_RESP		= 0X40044,
	
	IOTYPE_USER_IPCAM_WIRTE_DEV_CONFIG_REQ		= 0X40045,	//д���豸��������Ϣ  (mac��ַ serid����Ҫ���ñ��治ɾ����)
	IOTYPE_USER_IPCAM_WIRTE_DEV_CONFIG_RESP		= 0X40046,

	IOTYPE_USER_IPCAM_READ_DEV_CONFIG_REQ		= 0X40047,	//��ȡ�豸��������Ϣ
	IOTYPE_USER_IPCAM_READ_DEV_CONFIG_RESP		= 0X40048,

	IOTYPE_USER_IPCAM_RESET_STATUS_RESP			= 0X40049,	//��λ��״̬�仯��֪ͨ

	IOTYPE_USER_IPCAM_SET_NTP_CONFIG_REQ		= 0X40050,	//д��ntp��������Ϣ
	IOTYPE_USER_IPCAM_SET_NTP_CONFIG_RESP		= 0X40051,

	IOTYPE_USER_IPCAM_GET_NTP_CONFIG_REQ		= 0X40052,	//��ȡntp��������Ϣ
	IOTYPE_USER_IPCAM_GET_NTP_CONFIG_RESP		= 0X40053,

	IOTYPE_USER_IPCAM_GET_COMPANY_CONFIG_REQ	= 0X40054,	//��ȡ��˾��Ϣ
	IOTYPE_USER_IPCAM_GET_COMPANY_CONFIG_RESP	= 0X40055,

	IOTYPE_USER_IPCAM_GET_DEVICEMODEL_CONFIG_REQ	= 0X40056,	//��ȡװ����Ϣ
	IOTYPE_USER_IPCAM_GET_DEVICEMODEL_CONFIG_RESP	= 0X40057,

	IOTYPE_USER_IPCAM_SET_DEVICEMODEL_CONFIG_REQ	= 0X40058,	//�����豸����Ϣ   �豸�ͺ�  �����̵�
	IOTYPE_USER_IPCAM_SET_DEVICEMODEL_CONFIG_RESP	= 0X40059,

	IOTYPE_USER_IPCAM_GET_DROPBOX_CONFIG_REQ	= 0X4005A,	//��ȡDROPBOX��Ϣ
	IOTYPE_USER_IPCAM_GET_DROPBOX_CONFIG_RESP	= 0X4005B,

	IOTYPE_USER_IPCAM_SET_DROPBOX_CONFIG_REQ	= 0X4005C,	//��ȡDROPBOX��Ϣ
	IOTYPE_USER_IPCAM_SET_DROPBOX_CONFIG_RESP	= 0X4005D,

	IOTYPE_USER_IPCAM_GET_UPLOAD_FUNCTION_CONFIG_REQ	= 0X4005e,	//��ȡDROPBOX������Ϣ
	IOTYPE_USER_IPCAM_GET_UPLOAD_FUNCTION_CONFIG_RESP	= 0X4005f,

	IOTYPE_USER_IPCAM_SET_UPLOAD_FUNCTION_CONFIG_REQ	= 0X40060,
	IOTYPE_USER_IPCAM_SET_UPLOAD_FUNCTION_CONFIG_RESP	= 0X40061,

	
	IOTYPE_USER_IPCAM_START_OAUTH_CONFIG_REQ	= 0X40062,	//��ʼ��֤
	IOTYPE_USER_IPCAM_START_OAUTH_CONFIG_RESP	= 0X40063,

	IOTYPE_USER_IPCAM_OAUTH_OK_CONFIG_REQ	= 0X40064,	//��ȨOK
	IOTYPE_USER_IPCAM_OAUTH_OK_CONFIG_RESP	= 0X40065,

	IOTYPE_USER_IPCAM_CLOSE_LED_CONFIG_REQ	= 0X40066,	//�ر�ledָʾ��
	IOTYPE_USER_IPCAM_CLOSE_LED_CONFIG_RESP	= 0X40067,

	IOTYPE_USER_IPCAM_CLOSE_LED_STATUS_CONFIG_REQ	= 0X40068,	//ledָʾ�ƹر�״̬
	IOTYPE_USER_IPCAM_CLOSE_LED_STATUS_CONFIG_RESP	= 0X40069,

	//add by jy
	IOTYPE_USER_IPCAM_GET_PICTURE_REQ			= 0X40070,	// send picture to server
	IOTYPE_USER_IPCAM_GET_PICTURE_RESP			= 0X40071,


	IOTYPE_USER_IPCAM_GET_PICTURE_TO_SHARE_REQ			= 0X40072,	// send picture to server to share
	IOTYPE_USER_IPCAM_GET_PICTURE_TO_SHARE_RESP			= 0X40073,

	IOTYPE_USER_IPCAM_SET_TIMEMODE_TO_SHARE_REQ			= 0X40074,	// set time mode 0 Chinese 1 America 2 Europe
	IOTYPE_USER_IPCAM_SET_TIMEMODE_TO_SHARE_RESP		= 0X40075,

	IOTYPE_USER_IPCAM_GET_TIMEMODE_TO_SHARE_REQ			= 0X40076,	// get time mode 0 Chinese 1 America 2 Europe
	IOTYPE_USER_IPCAM_GET_TIMEMODE_TO_SHARE_RESP		= 0X40077,
	//end

	IOTYPE_USER_IPCAM_GET_MOTION_AREA_REQ			= 0X40078,	// �ƶ�������� ������ȡ
	IOTYPE_USER_IPCAM_GET_MOTION_AREA_RESP			= 0X40079,	// 

	IOTYPE_USER_IPCAM_SET_MOTION_AREA_REQ			= 0X4007A,	// �ƶ�������� ��������
	IOTYPE_USER_IPCAM_SET_MOTION_AREA_RESP			= 0X4007B,	// 

	IOTYPE_USER_IPCAM_SET_PLAYBACK_RATE_REQ			= 0X4007C,	//���ûط�����
	IOTYPE_USER_IPCAM_SET_PLAYBACK_RATE_RESP		= 0X4007D,	// 
	//¼���ų�
	IOTYPE_USER_IPCAM_SET_RECORD_SCHEDULE_REQ		 = 0X4007E,	//����¼���ų�
	IOTYPE_USER_IPCAM_SET_RECORD_SCHEDULE_RES		 = 0X4007F,	// 

	IOTYPE_USER_IPCAM_GET_RECORD_SCHEDULE_REQ 		= 0X40080,	//��ȡ¼���ų�
	IOTYPE_USER_IPCAM_GET_RECORD_SCHEDULE_RES 		= 0X40081,	// 

	//����
	IOTYPE_USER_IPCAM_SET_LED_STATUS_REQ			= 0X40082,	//����ָʾ��״̬
	IOTYPE_USER_IPCAM_SET_LED_STATUS_RESP			= 0X40083,	// 

	IOTYPE_USER_IPCAM_GET_LED_STATUS_REQ			= 0X40084,	//��ȡָʾ��״̬
	IOTYPE_USER_IPCAM_GET_LED_STATUS_RESP			= 0X40085,

	IOTYPE_USER_IPCAM_SET_BUZZER_STATUS_REQ			= 0X40086,	//���÷�����״̬
	IOTYPE_USER_IPCAM_SET_BUZZER_STATUS_RESP		= 0X40087,	// 

	IOTYPE_USER_IPCAM_GET_BUZZER_STATUS_REQ			= 0X40088,	//��ȡ������״̬
	IOTYPE_USER_IPCAM_GET_BUZZER_STATUS_RESP		= 0X40089,
	//FOR AWS
	// AWS support ����ѷ¼���ϴ����� ��ѯ������ 
    IOTYPE_USER_IPCAM_GET_AWS_STATUS_REQ      = 0X4008A,
    IOTYPE_USER_IPCAM_GET_AWS_STATUS_RESP     = 0X4008B,
    IOTYPE_USER_IPCAM_SET_AWS_STATUS_REQ      = 0X4008C,
    IOTYPE_USER_IPCAM_SET_AWS_STATUS_RESP     = 0X4008D,

	 // REMOTE UPGRADE   ��������
    IOTYPE_USER_IPCAM_REMOTE_UPGRADE_REQ      = 0X4008E,
    IOTYPE_USER_IPCAM_REMOTE_UPGRADE_RESP     = 0X4008F,
    
    // UPGRADE PROGRESS  �������Ȳ�ѯ
    IOTYPE_USER_IPCAM_UPGRADE_PROGRESS_REQ      = 0X40090,
    IOTYPE_USER_IPCAM_UPGRADE_PROGRESS_RESP     = 0X40091,

	/*
	20150408
	1 Ϊ�˼����ԣ����е���ϢID�޶���Χ��0X40000 ~0X49999��Ӧ��������Ŀǰʹ������
	2 ����ID ����µķ���ʹ�ã��������ڰٶȵĲ��Թ�����
	 ��������ÿ��ID��ҪЭ��ȷ����ID�޶���Χ��:0X50000 ~0X59999�� 
	3 ����ID��˳�� ��main.h �е�SDK_MAIN_MSG_ID_E ���御������һ��
	4 ������ID ����ʹ�õĽṹ�壬������sdk_struct.h  �еĽṹ�屣��һ��
	*/

	IOTYPE_USER_IPCAM_GET_MDSYS_INFO_REQ			= 0X50001,	//��ȡħ��ϵͳ����(�������� �汾 �ȵ�) sdk_sys_cfg_t
	IOTYPE_USER_IPCAM_GET_MDSYS_INFO_RESP		    = 0X50002,
	//IOTYPE_USER_IPCAM_GET_BAIDU_INFO_REQ			= 0X50003,	//��ȡ�ٶ������Ϣ  sdk_register_cfg_t
	//IOTYPE_USER_IPCAM_GET_BAIDU_INFO_RESP		    = 0X50004,
	IOTYPE_USER_IPCAM_GET_MAC_ADDR_REQ				= 0X50003,
	IOTYPE_USER_IPCAM_GET_MAC_ADDR_RESP				= 0X50004,
	IOTYPE_USER_CMD_MAX
	}ENUM_AVIOCTRL_MSGTYPE;


/////////////////////////////////////////////////////////////////////////////////
/////////////////// Type ENUM Define ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	AVIOCTRL_OK					= 0x00,
	AVIOCTRL_ERR				= -0x01,
	AVIOCTRL_ERR_PASSWORD		= AVIOCTRL_ERR - 0x01,
	AVIOCTRL_ERR_STREAMCTRL		= AVIOCTRL_ERR - 0x02,
	AVIOCTRL_ERR_MONTIONDETECT	= AVIOCTRL_ERR - 0x03,
	AVIOCTRL_ERR_DEVICEINFO		= AVIOCTRL_ERR - 0x04,
	AVIOCTRL_ERR_LOGIN			= AVIOCTRL_ERR - 5,
	AVIOCTRL_ERR_LISTWIFIAP		= AVIOCTRL_ERR - 6,
	AVIOCTRL_ERR_SETWIFI		= AVIOCTRL_ERR - 7,
	AVIOCTRL_ERR_GETWIFI		= AVIOCTRL_ERR - 8,
	AVIOCTRL_ERR_SETRECORD		= AVIOCTRL_ERR - 9,
	AVIOCTRL_ERR_SETRCDDURA		= AVIOCTRL_ERR - 10,
	AVIOCTRL_ERR_LISTEVENT		= AVIOCTRL_ERR - 11,
	AVIOCTRL_ERR_PLAYBACK		= AVIOCTRL_ERR - 12,

	AVIOCTRL_ERR_INVALIDCHANNEL	= AVIOCTRL_ERR - 0x20,
}ENUM_AVIOCTRL_ERROR; //APP don't use it now


// ServType, unsigned long, 32 bits, is a bit mask for function declareation
// bit value "0" means function is valid or enabled
// in contract, bit value "1" means function is invalid or disabled.
// ** for more details, see "ServiceType Definitation for AVAPIs"
// 
// Defined bits are listed below:
//----------------------------------------------
// bit		fuction
// 0		Audio in, from Device to Mobile
// 1		Audio out, from Mobile to Device 
// 2		PT function
// 3		Event List function
// 4		Play back function (require Event List function)
// 5		Wi-Fi setting function
// 6		Event Setting Function
// 7		Recording Setting function
// 8		SDCard formattable function
// 9		Video flip function
// 10		Environment mode
// 11		Multi-stream selectable
// 12		Audio out encoding format

// The original enum below is obsoleted.
typedef enum
{
	SERVTYPE_IPCAM_DWH					= 0x00,
	SERVTYPE_RAS_DWF					= 0x01,
	SERVTYPE_IOTCAM_8125				= 0x10,
	SERVTYPE_IOTCAM_8125PT				= 0x11,
	SERVTYPE_IOTCAM_8126				= 0x12,
	SERVTYPE_IOTCAM_8126PT				= 0x13,	
}ENUM_SERVICE_TYPE;

// AVIOCTRL Quality Type
typedef enum 
{
//�ֻ���
	AVIOCTRL_QUALITY_UNKNOWN			= 0x00,	
	AVIOCTRL_QUALITY_MAX				= 0x01,	// ex. 640*480, 15fps, 320kbps (or 1280x720, 5fps, 320kbps)
	AVIOCTRL_QUALITY_HIGH				= 0x02,	// ex. 640*480, 10fps, 256kbps
	AVIOCTRL_QUALITY_MIDDLE				= 0x03,	// ex. 320*240, 15fps, 256kbps
	AVIOCTRL_QUALITY_LOW				= 0x04, // ex. 320*240, 10fps, 128kbps
	AVIOCTRL_QUALITY_MIN				= 0x05,	// ex. 160*120, 10fps, 64kbps

//cms��

	AVIOCTRL_QUALITY_CMS1				= 0x0A,	
	AVIOCTRL_QUALITY_CMS2				= 0x0B,	// ex. 640*480, 15fps, 320kbps (or 1280x720, 5fps, 320kbps)
	AVIOCTRL_QUALITY_CMS3				= 0x0C,	// ex. 640*480, 10fps, 256kbps
	AVIOCTRL_QUALITY_CMS4				= 0x0D,	// ex. 320*240, 15fps, 256kbps
	AVIOCTRL_QUALITY_CMS5				= 0x0E, // ex. 320*240, 10fps, 128kbps

}ENUM_QUALITY_LEVEL;


typedef enum
{
	AVIOTC_WIFIAPMODE_NULL				= 0x00,
	AVIOTC_WIFIAPMODE_MANAGED			= 0x01,
	AVIOTC_WIFIAPMODE_ADHOC				= 0x02,
}ENUM_AP_MODE;


typedef enum
{
	AVIOTC_WIFIAPENC_INVALID			= 0x00, 
	AVIOTC_WIFIAPENC_NONE				= 0x01, //
	AVIOTC_WIFIAPENC_WEP				= 0x02, //WEP, for no password
	AVIOTC_WIFIAPENC_WPA_TKIP			= 0x03, 
	AVIOTC_WIFIAPENC_WPA_AES			= 0x04, 
	AVIOTC_WIFIAPENC_WPA2_TKIP			= 0x05, 
	AVIOTC_WIFIAPENC_WPA2_AES			= 0x06,

	AVIOTC_WIFIAPENC_WPA_PSK_TKIP  = 0x07,
	AVIOTC_WIFIAPENC_WPA_PSK_AES   = 0x08,
	AVIOTC_WIFIAPENC_WPA2_PSK_TKIP = 0x09,
	AVIOTC_WIFIAPENC_WPA2_PSK_AES  = 0x0A,

}ENUM_AP_ENCTYPE;


// AVIOCTRL Event Type
typedef enum 
{
	AVIOCTRL_EVENT_ALL					= 0x00,	// all event type(general APP-->IPCamera)
	AVIOCTRL_EVENT_MOTIONDECT			= 0x01,	// motion detect start//==s==
	AVIOCTRL_EVENT_VIDEOLOST			= 0x02,	// video lost alarm
	AVIOCTRL_EVENT_IOALARM				= 0x03, // io alarmin start //---s--

	AVIOCTRL_EVENT_MOTIONPASS			= 0x04, // motion detect end  //==e==
	AVIOCTRL_EVENT_VIDEORESUME			= 0x05,	// video resume
	AVIOCTRL_EVENT_IOALARMPASS			= 0x06, // IO alarmin end   //---e--

	AVIOCTRL_EVENT_EXPT_REBOOT			= 0x10, // system exception reboot
	AVIOCTRL_EVENT_SDFAULT				= 0x11, // sd record exception
	AVIOCTRL_EVENT_AUDIO_MOTION			= 0x12, //
}ENUM_EVENTTYPE;

// AVIOCTRL Record Type
typedef enum
{
	AVIOTC_RECORDTYPE_OFF				= 0x00,
	AVIOTC_RECORDTYPE_FULLTIME			= 0x01,
	AVIOTC_RECORDTYPE_ALARM				= 0x02,
	AVIOTC_RECORDTYPE_MANUAL			= 0x03,
}ENUM_RECORD_TYPE;

// AVIOCTRL Play Record Command
typedef enum 
{
	AVIOCTRL_RECORD_PLAY_PAUSE			= 0x00,
	AVIOCTRL_RECORD_PLAY_STOP			= 0x01,
	AVIOCTRL_RECORD_PLAY_STEPFORWARD	= 0x02, //now, APP no use
	AVIOCTRL_RECORD_PLAY_STEPBACKWARD	= 0x03, //now, APP no use
	AVIOCTRL_RECORD_PLAY_FORWARD		= 0x04, //now, APP no use
	AVIOCTRL_RECORD_PLAY_BACKWARD		= 0x05, //now, APP no use
	AVIOCTRL_RECORD_PLAY_SEEKTIME		= 0x06, //now, APP no use
	AVIOCTRL_RECORD_PLAY_END			= 0x07,
	AVIOCTRL_RECORD_PLAY_START			= 0x10,
}ENUM_PLAYCONTROL;

// AVIOCTRL Environment Mode
typedef enum
{
	AVIOCTRL_ENVIRONMENT_INDOOR_50HZ 	= 0x00,
	AVIOCTRL_ENVIRONMENT_INDOOR_60HZ	= 0x01,
	AVIOCTRL_ENVIRONMENT_OUTDOOR		= 0x02,
	AVIOCTRL_ENVIRONMENT_NIGHT			= 0x03,	
}ENUM_ENVIRONMENT_MODE;

// AVIOCTRL Video Flip Mode
typedef enum
{
	AVIOCTRL_VIDEOMODE_NORMAL 			= 0x00,
	AVIOCTRL_VIDEOMODE_FLIP				= 0x01,
	AVIOCTRL_VIDEOMODE_MIRROR			= 0x02,
	AVIOCTRL_VIDEOMODE_FLIP_MIRROR 		= 0x03,
}ENUM_VIDEO_MODE;

// AVIOCTRL PTZ Command Value
typedef enum 
{
	AVIOCTRL_PTZ_STOP					= 0,
	AVIOCTRL_PTZ_UP						= 1,
	AVIOCTRL_PTZ_DOWN					= 2,
	AVIOCTRL_PTZ_LEFT					= 3,
	AVIOCTRL_PTZ_LEFT_UP				= 4,
	AVIOCTRL_PTZ_LEFT_DOWN				= 5,
	AVIOCTRL_PTZ_RIGHT					= 6, 
	AVIOCTRL_PTZ_RIGHT_UP				= 7, 
	AVIOCTRL_PTZ_RIGHT_DOWN				= 8, 
	AVIOCTRL_PTZ_AUTO					= 9, 
	AVIOCTRL_PTZ_SET_POINT				= 10,
	AVIOCTRL_PTZ_CLEAR_POINT			= 11,
	AVIOCTRL_PTZ_GOTO_POINT				= 12,

	AVIOCTRL_PTZ_SET_MODE_START			= 13,
	AVIOCTRL_PTZ_SET_MODE_STOP			= 14,
	AVIOCTRL_PTZ_MODE_RUN				= 15,

	AVIOCTRL_PTZ_MENU_OPEN				= 16, 
	AVIOCTRL_PTZ_MENU_EXIT				= 17,
	AVIOCTRL_PTZ_MENU_ENTER				= 18,

	AVIOCTRL_PTZ_FLIP					= 19,
	AVIOCTRL_PTZ_START					= 20,

	AVIOCTRL_LENS_APERTURE_OPEN			= 21,
	AVIOCTRL_LENS_APERTURE_CLOSE		= 22,

	AVIOCTRL_LENS_ZOOM_IN				= 23, 
	AVIOCTRL_LENS_ZOOM_OUT				= 24,

	AVIOCTRL_LENS_FOCAL_NEAR			= 25,
	AVIOCTRL_LENS_FOCAL_FAR				= 26,

	AVIOCTRL_AUTO_PAN_SPEED				= 27,
	AVIOCTRL_AUTO_PAN_LIMIT				= 28,
	AVIOCTRL_AUTO_PAN_START				= 29,

	AVIOCTRL_PATTERN_START				= 30,
	AVIOCTRL_PATTERN_STOP				= 31,
	AVIOCTRL_PATTERN_RUN				= 32,

	AVIOCTRL_SET_AUX					= 33,
	AVIOCTRL_CLEAR_AUX					= 34,
	AVIOCTRL_MOTOR_RESET_POSITION		= 35,
	AVIOCTRL_PTZ_AUTO_LEFT_RIGHT		= 36,	//����Ѳ��
	AVIOCTRL_PTZ_AUTO_UP_DOWN			= 37,	//����Ѳ��
	AVIOCTRL_PTZ_AUTO_LEFT_RIGHT_STOP	= 38,	//����Ѳ��
	AVIOCTRL_PTZ_AUTO_UP_DOWN_STOP		= 39,	//����Ѳ��
	AVIOCTRL_PTZ_AUTO_TRACK				= 40,	//�켣Ѳ��

	AVIOCTRL_PTZ_AUTO_LEFT_RIGHT_EX		= 41,	//����Ѳ��(���Զ�ֹͣ)
	AVIOCTRL_PTZ_AUTO_UP_DOWN_EX		= 42,	//����Ѳ��(���Զ�ֹͣ)
}ENUM_PTZCMD;



/////////////////////////////////////////////////////////////////////////////
///////////////////////// Message Body Define ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/*
IOTYPE_USER_IPCAM_START 				= 0x01FF,
IOTYPE_USER_IPCAM_STOP	 				= 0x02FF,
IOTYPE_USER_IPCAM_AUDIOSTART 			= 0x0300,
IOTYPE_USER_IPCAM_AUDIOSTOP 			= 0x0301,
IOTYPE_USER_IPCAM_SPEAKERSTART 			= 0x0350,
IOTYPE_USER_IPCAM_SPEAKERSTOP 			= 0x0351,
** @struct SMsgAVIoctrlAVStream
*/
typedef struct
{
	unsigned int channel; // Camera Index
	unsigned char reserved[4];
} SMsgAVIoctrlAVStream;


/*
IOTYPE_USER_IPCAM_GETSTREAMCTRL_REQ		= 0x0322,
** @struct SMsgAVIoctrlGetStreamCtrlReq
*/
typedef struct
{
	unsigned int channel;	// Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetStreamCtrlReq;

/*
IOTYPE_USER_IPCAM_SETSTREAMCTRL_REQ		= 0x0320,
IOTYPE_USER_IPCAM_GETSTREAMCTRL_RESP	= 0x0323,
** @struct SMsgAVIoctrlSetStreamCtrlReq, SMsgAVIoctrlGetStreamCtrlResq
*/
typedef struct
{
	unsigned int  channel;	// Camera Index
	unsigned char quality;	//refer to ENUM_QUALITY_LEVEL
	unsigned char reserved[3];
} SMsgAVIoctrlSetStreamCtrlReq, SMsgAVIoctrlGetStreamCtrlResq;

/*
IOTYPE_USER_IPCAM_SETSTREAMCTRL_RESP	= 0x0321,
** @struct SMsgAVIoctrlSetStreamCtrlResp
*/
typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetStreamCtrlResp;


/*
IOTYPE_USER_IPCAM_GETMOTIONDETECT_REQ	= 0x0326,
** @struct SMsgAVIoctrlGetMotionDetectReq
*/
typedef struct
{
	unsigned int channel; 	// Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetMotionDetectReq;


/*
IOTYPE_USER_IPCAM_SETMOTIONDETECT_REQ		= 0x0324,
IOTYPE_USER_IPCAM_GETMOTIONDETECT_RESP		= 0x0327,
** @struct SMsgAVIoctrlSetMotionDetectReq, SMsgAVIoctrlGetMotionDetectResp
*/
typedef struct
{
	unsigned int channel; 		// Camera Index
	unsigned int sensitivity; 	// 0(Disabled) ~ 100(MAX):
								// index		sensitivity value
								// 0			0
								// 1			25
								// 2			50
								// 3			75
								// 4			100
}SMsgAVIoctrlSetMotionDetectReq, SMsgAVIoctrlGetMotionDetectResp;


/*
IOTYPE_USER_IPCAM_SETMOTIONDETECT_RESP	= 0x0325,
** @struct SMsgAVIoctrlSetMotionDetectResp
*/
typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetMotionDetectResp;


/*
IOTYPE_USER_IPCAM_DEVINFO_REQ			= 0x0330,
** @struct SMsgAVIoctrlDeviceInfoReq
*/
typedef struct
{
	unsigned char reserved[4];
}SMsgAVIoctrlDeviceInfoReq;


/*
IOTYPE_USER_IPCAM_DEVINFO_RESP			= 0x0331,
** @struct SMsgAVIoctrlDeviceInfo
*/
typedef struct
{
	unsigned char model[16];	// IPCam mode
	unsigned char vendor[16];	// IPCam manufacturer
	unsigned int version;		// IPCam firmware version	ex. v1.2.3.4 => 0x01020304;  v1.0.0.2 => 0x01000002
	unsigned int channel;		// Camera index
	unsigned int total;			// 0: No cards been detected or an unrecognizeable sdcard that could not be re-formatted.
								// -1: if camera detect an unrecognizable sdcard, and could be re-formatted
								// otherwise: return total space size of sdcard (MBytes)								
								
	unsigned int free;			// Free space size of sdcard (MBytes)
	unsigned char reserved[8];	// reserved
}SMsgAVIoctrlDeviceInfoResp;

/*
IOTYPE_USER_IPCAM_SETPASSWORD_REQ		= 0x0332,
** @struct SMsgAVIoctrlSetPasswdReq
*/
typedef struct
{
	char oldpasswd[32];			// The old security code
	char newpasswd[32];			// The new security code
}SMsgAVIoctrlSetPasswdReq;


/*
IOTYPE_USER_IPCAM_SETPASSWORD_RESP		= 0x0333,
** @struct SMsgAVIoctrlSetPasswdResp
*/
typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetPasswdResp;


/*
IOTYPE_USER_IPCAM_LISTWIFIAP_REQ		= 0x0340,
** @struct SMsgAVIoctrlListWifiApReq
*/
typedef struct
{
	unsigned char reserved[4];
}SMsgAVIoctrlListWifiApReq;

typedef struct
{
	char ssid[32]; 				// WiFi ssid
	char mode;	   				// refer to ENUM_AP_MODE
	char enctype;  				// refer to ENUM_AP_ENCTYPE
	char signal;   				// signal intensity 0--100%
	char status;   				// 0 : invalid ssid or disconnected
								// 1 : connected with default gateway
								// 2 : unmatched password
								// 3 : weak signal and connected
								// 4 : selected:
								//		- password matched and
								//		- disconnected or connected but not default gateway
}SWifiAp;

/*
IOTYPE_USER_IPCAM_LISTWIFIAP_RESP		= 0x0341,
** @struct SMsgAVIoctrlListWifiApResp
*/
typedef struct
{
	unsigned int number; // MAX number: 1024(IOCtrl packet size) / 36(bytes) = 28
	SWifiAp stWifiAp[0];
}SMsgAVIoctrlListWifiApResp;

/*
IOTYPE_USER_IPCAM_SETWIFI_REQ			= 0x0342,
** @struct SMsgAVIoctrlSetWifiReq
*/
typedef struct
{
	unsigned char ssid[32];			//WiFi ssid
	unsigned char password[32];		//if exist, WiFi password
	unsigned char mode;				//refer to ENUM_AP_MODE
	unsigned char enctype;			//refer to ENUM_AP_ENCTYPE
	unsigned char reserved[10];
}SMsgAVIoctrlSetWifiReq;

//IOTYPE_USER_IPCAM_SETWIFI_REQ_2		= 0x0346,
typedef struct
{
	unsigned char ssid[32];		// WiFi ssid
	unsigned char password[64];	// if exist, WiFi password
	unsigned char mode;			// refer to ENUM_AP_MODE
	unsigned char enctype;		// refer to ENUM_AP_ENCTYPE
	unsigned char reserved[10];
}SMsgAVIoctrlSetWifiReq2;

/*
IOTYPE_USER_IPCAM_SETWIFI_RESP			= 0x0343,
** @struct SMsgAVIoctrlSetWifiResp
*/
typedef struct
{
	int result; //0: wifi connected; 1: failed to connect
	unsigned char reserved[4];
}SMsgAVIoctrlSetWifiResp;

/*
IOTYPE_USER_IPCAM_GETWIFI_REQ			= 0x0344,
** @struct SMsgAVIoctrlGetWifiReq
*/
typedef struct
{
	unsigned char reserved[4];
}SMsgAVIoctrlGetWifiReq;

/*
IOTYPE_USER_IPCAM_GETWIFI_RESP			= 0x0345,
** @struct SMsgAVIoctrlGetWifiResp //if no wifi connected, members of SMsgAVIoctrlGetWifiResp are all 0
*/
typedef struct
{
	unsigned char ssid[32];		// WiFi ssid
	unsigned char password[32]; // WiFi password if not empty
	unsigned char mode;			// refer to ENUM_AP_MODE
	unsigned char enctype;		// refer to ENUM_AP_ENCTYPE
	unsigned char signal;		// signal intensity 0--100%
	unsigned char status;		// refer to "status" of SWifiAp
}SMsgAVIoctrlGetWifiResp;

//changed: WI-FI Password 32bit Change to 64bit 
//IOTYPE_USER_IPCAM_GETWIFI_RESP_2    = 0x0347,
typedef struct
{
 unsigned char ssid[32];	 // WiFi ssid
 unsigned char password[64]; // WiFi password if not empty
 unsigned char mode;	// refer to ENUM_AP_MODE
 unsigned char enctype; // refer to ENUM_AP_ENCTYPE
 unsigned char signal;  // signal intensity 0--100%
 unsigned char status;  // refer to "status" of SWifiAp
}SMsgAVIoctrlGetWifiResp2;

/*
IOTYPE_USER_IPCAM_GETRECORD_REQ			= 0x0312,
** @struct SMsgAVIoctrlGetRecordReq
*/
typedef struct
{
	unsigned int channel; // Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetRecordReq;

/*
IOTYPE_USER_IPCAM_SETRECORD_REQ			= 0x0310,
IOTYPE_USER_IPCAM_GETRECORD_RESP		= 0x0313,
** @struct SMsgAVIoctrlSetRecordReq, SMsgAVIoctrlGetRecordResq
*/
typedef struct
{
	unsigned int channel;		// Camera Index
	unsigned int recordType;	// Refer to ENUM_RECORD_TYPE
	unsigned char reserved[4];
}SMsgAVIoctrlSetRecordReq, SMsgAVIoctrlGetRecordResq;

/*
IOTYPE_USER_IPCAM_SETRECORD_RESP		= 0x0311,
** @struct SMsgAVIoctrlSetRecordResp
*/
typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetRecordResp;


/*
IOTYPE_USER_IPCAM_GETRCD_DURATION_REQ	= 0x0316,
** @struct SMsgAVIoctrlGetRcdDurationReq
*/
typedef struct
{
	unsigned int channel; // Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetRcdDurationReq;

/*
IOTYPE_USER_IPCAM_SETRCD_DURATION_REQ	= 0x0314,
IOTYPE_USER_IPCAM_GETRCD_DURATION_RESP  = 0x0317,
** @struct SMsgAVIoctrlSetRcdDurationReq, SMsgAVIoctrlGetRcdDurationResp
*/
typedef struct
{
	unsigned int channel; 		// Camera Index
	unsigned int presecond; 	// pre-recording (sec)
	unsigned int durasecond;	// recording (sec)
}SMsgAVIoctrlSetRcdDurationReq, SMsgAVIoctrlGetRcdDurationResp;


/*
IOTYPE_USER_IPCAM_SETRCD_DURATION_RESP  = 0x0315,
** @struct SMsgAVIoctrlSetRcdDurationResp
*/
typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetRcdDurationResp;


typedef struct
{
	unsigned short year;	// The number of year.
	unsigned char month;	// The number of months since January, in the range 1 to 12.
	unsigned char day;		// The day of the month, in the range 1 to 31.
	unsigned char wday;		// The number of days since Sunday, in the range 0 to 6. (Sunday = 0, Monday = 1, ...)
	unsigned char hour;     // The number of hours past midnight, in the range 0 to 23.
	unsigned char minute;   // The number of minutes after the hour, in the range 0 to 59.
	unsigned char second;   // The number of seconds after the minute, in the range 0 to 59.
}STimeDay;

/*
IOTYPE_USER_IPCAM_LISTEVENT_REQ			= 0x0318,
** @struct SMsgAVIoctrlListEventReq
*/
typedef struct
{
	unsigned int channel; 		// Camera Index
	STimeDay stStartTime; 		// Search event from ...
	STimeDay stEndTime;	  		// ... to (search event)
	unsigned char event;  		// event type, refer to ENUM_EVENTTYPE
	unsigned char status; 		// 0x00: Recording file exists, Event unreaded
								// 0x01: Recording file exists, Event readed
								// 0x02: No Recording file in the event
	unsigned char reserved[2];
}SMsgAVIoctrlListEventReq;


typedef struct
{
	STimeDay stTime;
	unsigned char event;
	unsigned char status;	// 0x00: Recording file exists, Event unreaded
							// 0x01: Recording file exists, Event readed
							// 0x02: No Recording file in the event
	unsigned char reserved[2];
}SAvEvent;
	
/*
IOTYPE_USER_IPCAM_LISTEVENT_RESP		= 0x0319,
** @struct SMsgAVIoctrlListEventResp
*/
#define MAX_VIDEO_NUM 100

typedef struct
{
	unsigned int  channel;		// Camera Index
	unsigned int  total;		// Total event amount in this search session
	unsigned char index;		// package index, 0,1,2...; 
								// because avSendIOCtrl() send package up to 1024 bytes one time, you may want split search results to serveral package to send.
	unsigned char endflag;		// end flag; endFlag = 1 means this package is the last one.
	unsigned char count;		// how much events in this package
	unsigned char reserved[1];
	SAvEvent stEvent[0];		// The first memory address of the events in this package
	int videotime[MAX_VIDEO_NUM];  //max is 100
}SMsgAVIoctrlListEventResp;

	
/*
IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL 	= 0x031A,
** @struct SMsgAVIoctrlPlayRecord
*/
typedef struct
{
	unsigned int channel;	// Camera Index
	unsigned int command;	// play record command. refer to ENUM_PLAYCONTROL
	unsigned int Param;		// command param, that the user defined
	STimeDay stTimeDay;		// Event time from ListEvent
	unsigned char reserved[4];
} SMsgAVIoctrlPlayRecord;

/*
IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL_RESP 	= 0x031B,
** @struct SMsgAVIoctrlPlayRecordResp
*/
typedef struct
{
	unsigned int command;	// Play record command. refer to ENUM_PLAYCONTROL
	unsigned int result; 	// Depends on command
							// when is AVIOCTRL_RECORD_PLAY_START:
							//	result>=0   real channel no used by device for playback
							//	result <0	error
							//			-1	playback error
							//			-2	exceed max allow client amount
	unsigned char reserved[4];
} SMsgAVIoctrlPlayRecordResp; // only for play record start command


/*
IOTYPE_USER_IPCAM_PTZ_COMMAND	= 0x1001,	// P2P Ptz Command Msg 
** @struct SMsgAVIoctrlPtzCmd
*/
typedef struct
{
	unsigned char control;	// PTZ control command, refer to ENUM_PTZCMD
	unsigned char speed;	// PTZ control speed
	unsigned char point;	// no use in APP so far. preset position, for RS485 PT
	unsigned char limit;	// no use in APP so far. 
	unsigned char aux;		// no use in APP so far. auxiliary switch, for RS485 PT
	unsigned char channel;	// camera index
	unsigned char reserve[2];
} SMsgAVIoctrlPtzCmd;

/*
IOTYPE_USER_IPCAM_EVENT_REPORT	= 0x1FFF,	// Device Event Report Msg 
*/
/** @struct SMsgAVIoctrlEvent
 */
typedef struct
{
	STimeDay stTime;
	unsigned long time; 	// UTC Time
	unsigned int  channel; 	// Camera Index
	unsigned int  event; 	// Event Type
	unsigned char reserved[4];
} SMsgAVIoctrlEvent;



#if 0

/* 	IOTYPE_USER_IPCAM_GET_EVENTCONFIG_REQ	= 0x0400,	// Get Event Config Msg Request 
 */
/** @struct SMsgAVIoctrlGetEventConfig
 */
typedef struct
{
	unsigned int	channel; 		  //Camera Index
	unsigned char   externIoOutIndex; //extern out index: bit0->io0 bit1->io1 ... bit7->io7;=1: get this io value or not get
    unsigned char   externIoInIndex;  //extern in index: bit0->io0 bit1->io1 ... bit7->io7; =1: get this io value or not get
	char reserved[2];
} SMsgAVIoctrlGetEventConfig;
 
/*
	IOTYPE_USER_IPCAM_GET_EVENTCONFIG_RESP	= 0x0401,	// Get Event Config Msg Response 
	IOTYPE_USER_IPCAM_SET_EVENTCONFIG_REQ	= 0x0402,	// Set Event Config Msg req 
*/
/* @struct SMsgAVIoctrlSetEventConfig
 * @struct SMsgAVIoctrlGetEventCfgResp
 */
typedef struct
{
	unsigned int channel; 		// Camera Index
	unsigned char mail;			// enable send email
	unsigned char ftp;			// enable ftp upload photo
	unsigned char localIO;		// enable local io output
	unsigned char p2pPushMsg;	// enable p2p push msg
	char reserved[4];
} SMsgAVIoctrlSetEventConfig, SMsgAVIoctrlGetEventCfgResp;

/*
	IOTYPE_USER_IPCAM_SET_EVENTCONFIG_RESP	= 0x0403,	// Set Event Config Msg resp 
*/
/** @struct SMsgAVIoctrlSetEventCfgResp
 */
typedef struct
{
	unsigned int channel; 	// Camera Index
	unsigned int result;	// 0: success; otherwise: failed.
}SMsgAVIoctrlSetEventCfgResp;

#endif


/*
IOTYPE_USER_IPCAM_SET_ENVIRONMENT_REQ		= 0x0360,
** @struct SMsgAVIoctrlSetEnvironmentReq
*/
typedef struct
{
	unsigned int channel;		// Camera Index
	unsigned char mode;			// refer to ENUM_ENVIRONMENT_MODE
	unsigned char reserved[3];
}SMsgAVIoctrlSetEnvironmentReq;


/*
IOTYPE_USER_IPCAM_SET_ENVIRONMENT_RESP		= 0x0361,
** @struct SMsgAVIoctrlSetEnvironmentResp
*/
typedef struct
{
	unsigned int channel; 		// Camera Index
	unsigned char result;		// 0: success; otherwise: failed.
	unsigned char reserved[3];
}SMsgAVIoctrlSetEnvironmentResp;


/*
IOTYPE_USER_IPCAM_GET_ENVIRONMENT_REQ		= 0x0362,
** @struct SMsgAVIoctrlGetEnvironmentReq
*/
typedef struct
{
	unsigned int channel; 	// Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetEnvironmentReq;

/*
IOTYPE_USER_IPCAM_GET_ENVIRONMENT_RESP		= 0x0363,
** @struct SMsgAVIoctrlGetEnvironmentResp
*/
typedef struct
{
	unsigned int channel; 		// Camera Index
	unsigned char mode;			// refer to ENUM_ENVIRONMENT_MODE
	unsigned char reserved[3];
}SMsgAVIoctrlGetEnvironmentResp;


/*
IOTYPE_USER_IPCAM_SET_VIDEOMODE_REQ			= 0x0370,
** @struct SMsgAVIoctrlSetVideoModeReq
*/
typedef struct
{
	unsigned int channel;	// Camera Index
	unsigned char mode;		// refer to ENUM_VIDEO_MODE
	unsigned char reserved[3];
}SMsgAVIoctrlSetVideoModeReq;


/*
IOTYPE_USER_IPCAM_SET_VIDEOMODE_RESP		= 0x0371,
** @struct SMsgAVIoctrlSetVideoModeResp
*/
typedef struct
{
	unsigned int channel; 	// Camera Index
	unsigned char result;	// 0: success; otherwise: failed.
	unsigned char reserved[3];
}SMsgAVIoctrlSetVideoModeResp;


/*
IOTYPE_USER_IPCAM_GET_VIDEOMODE_REQ			= 0x0372,
** @struct SMsgAVIoctrlGetVideoModeReq
*/
typedef struct
{
	unsigned int channel; 	// Camera Index
	unsigned char reserved[4];
}SMsgAVIoctrlGetVideoModeReq;


/*
IOTYPE_USER_IPCAM_GET_VIDEOMODE_RESP		= 0x0373,
** @struct SMsgAVIoctrlGetVideoModeResp
*/
typedef struct
{
	unsigned int  channel; 	// Camera Index
	unsigned char mode;		// refer to ENUM_VIDEO_MODE
	unsigned char reserved[3];
}SMsgAVIoctrlGetVideoModeResp;


/*
/IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ			= 0x0380,
** @struct SMsgAVIoctrlFormatExtStorageReq
*/
typedef struct
{
	unsigned int storage; 	// Storage index (ex. sdcard slot = 0, internal flash = 1, ...)
	unsigned char reserved[4];
}SMsgAVIoctrlFormatExtStorageReq;


/*
IOTYPE_USER_IPCAM_FORMATEXTSTORAGE_REQ		= 0x0381,
** @struct SMsgAVIoctrlFormatExtStorageResp
*/
typedef struct
{
	unsigned int  storage; 	// Storage index
	unsigned char result;	// 0: success;
							// -1: format command is not supported.
							// otherwise: failed.
	unsigned char reserved[3];
}SMsgAVIoctrlFormatExtStorageResp;


typedef struct
{
	unsigned short index;		// the stream index of camera
	unsigned short channel;		// the channel index used in AVAPIs, that is ChID in avServStart2(...,ChID)
	char reserved[4];
}SStreamDef;


/*	IOTYPE_USER_IPCAM_GETSUPPORTSTREAM_REQ			= 0x0328,
 */
typedef struct
{
	unsigned char reserved[4];
}SMsgAVIoctrlGetSupportStreamReq;


/*	IOTYPE_USER_IPCAM_GETSUPPORTSTREAM_RESP			= 0x0329,
 */
typedef struct
{
	unsigned int number; 		// the quanity of supported audio&video stream or video stream
	SStreamDef streams[0];
}SMsgAVIoctrlGetSupportStreamResp;


/* IOTYPE_USER_IPCAM_GETAUDIOOUTFORMAT_REQ			= 0x032A, //used to speak. but once camera is connected by App, send this at once.
 */
typedef struct
{
	unsigned int channel;		// camera index
	char reserved[4];
}SMsgAVIoctrlGetAudioOutFormatReq;

/* IOTYPE_USER_IPCAM_GETAUDIOOUTFORMAT_RESP			= 0x032B,
 */
typedef struct
{
	unsigned int channel;		// camera index
	int format;					// refer to ENUM_CODECID in AVFRAMEINFO.h
	char reserved[4];
}SMsgAVIoctrlGetAudioOutFormatResp;

/* IOTYPE_USER_IPCAM_RECEIVE_FIRST_IFRAME			= 0x1002,
 */
typedef struct
{
	unsigned int channel;		// camera index
	char reserved[4];
}SMsgAVIoctrlReceiveFirstIFrame;

/* IOTYPE_USER_IPCAM_GET_FLOWINFO_REQ              = 0x390
 */
typedef struct
{
	unsigned int channel;			// camera index
	unsigned int collect_interval;	// seconds of interval to collect flow information
									// send 0 indicates stop collecting.
}SMsgAVIoctrlGetFlowInfoReq;

/* IOTYPE_USER_IPCAM_GET_FLOWINFO_RESP            = 0x391
 */
typedef struct
{
	unsigned int channel;			// camera index
	unsigned int collect_interval;	// seconds of interval client will collect flow information
}SMsgAVIoctrlGetFlowInfoResp;

/* IOTYPE_USER_IPCAM_CURRENT_FLOWINFO              = 0x392
 */
typedef struct
{
	unsigned int channel;						// camera index
	unsigned int total_frame_count;				// Total frame count in the specified interval
	unsigned int lost_incomplete_frame_count;	// Total lost and incomplete frame count in the specified interval
	unsigned int total_expected_frame_size;		// Total expected frame size from avRecvFrameData2()
	unsigned int total_actual_frame_size;		// Total actual frame size from avRecvFrameData2()
	unsigned int timestamp_ms;					// Timestamp in millisecond of this report.
	char reserved[8];
}SMsgAVIoctrlCurrentFlowInfo;

/* IOTYPE_USER_IPCAM_GET_TIMEZONE_REQ               = 0x3A0
 * IOTYPE_USER_IPCAM_GET_TIMEZONE_RESP              = 0x3A1
 * IOTYPE_USER_IPCAM_SET_TIMEZONE_REQ               = 0x3B0
 * IOTYPE_USER_IPCAM_SET_TIMEZONE_RESP              = 0x3B1
 */
typedef struct
{
	int cbSize;							// the following package size in bytes, should be sizeof(SMsgAVIoctrlTimeZone)
	int nIsSupportTimeZone;
	int nGMTDiff;						// the difference between GMT in hours
	char szTimeZoneString[256];			// the timezone description string in multi-bytes char format
}SMsgAVIoctrlTimeZone;

/*
// dropbox support
IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_REQ      = 0x500,
IOTYPE_USER_IPCAM_GET_SAVE_DROPBOX_RESP     = 0x501,
*/
typedef struct
{
    unsigned short nSupportDropbox;     // 0:no support/ 1: support dropbox
    unsigned short nLinked;             // 0:no link/ 1:linked
    char szLinkUDID[64];                // Link UDID for App
}SMsgAVIoctrlGetDropbox;


/*
 // dropbox support
 IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_REQ      = 0x502,
 IOTYPE_USER_IPCAM_SET_SAVE_DROPBOX_RESP     = 0x503,
 */
typedef struct
{
    unsigned short nLinked;             // 0:no link/ 1:linked
    char szLinkUDID[64];                // UDID for App
    char szAccessToken[128];             // Oauth token
    char szAccessTokenSecret[128];       // Oauth token secret
	char szAppKey[128];                  // App Key (reserved)
	char szSecret[128];                  // Secret  (reserved)
}SMsgAVIoctrlSetDropbox;




/* IOTYPE_USER_IPCAM_GET_ATTRIBUTE_RESP			= 0X40002,
 * resolution����˵����1��160*120��2��320*240��3��640*480��4��800*600��5��1024*768��6��1280*720�� 7 640*368  8 ;320*200
 * video_display����˵����1�����ȣ�2���Աȶȣ�3���Ҷȣ�4�����Ͷȣ�5����ȡ�
 */
typedef struct
{
	unsigned long resolution; 		//֧�ֵķֱ������ͣ�ÿ��bit����һ�ֱַ��ʡ�
	unsigned long video_display;	//֧�ֵ�video_display��ÿ��bit����һ�����ԡ�
	short brightness_min;			//���ȵ��ڵ���Сֵ
	short brightness_max;			//���ȵ��ڵ����ֵ
	short contrast_min;				//�Աȶȵ��ڵ���Сֵ
	short contrast_max;				//�Աȶȵ��ڵ����ֵ
	short hue_min;					//�Ҷȵ��ڵ���Сֵ
	short hue_max;					//�Ҷȵ��ڵ����ֵ
	short saturation_min;			//ɫ���Ͷȵ��ڵ���Сֵ
	short saturation_max;			//ɫ���Ͷȵ��ڵ����ֵ
	short sharpness_min;			//��ȵ��ڵ���Сֵ
	short sharpness_max;			//��ȵ��ڵ����ֵ
	short pt_rate_min;				//��̨�����ٶȵ���Сֵ
	short pt_rate_max;				//��̨�����ٶȵ����ֵ
	short motion_detect_min;		//�ƶ�������Сֵ
	short motion_detect_max;		//�ƶ��������ֵ
	short sound_detect_min;			//����������Сֵ
	short sound_detect_max;			//�����������ֵ
	unsigned char mic;				//�Ƿ�����˷�
	unsigned char speaker;			//�Ƿ���������
	unsigned char reserved[2];		
} SMsgAVIoctrlGetAttributeResp;

/* IOTYPE_USER_IPCAM_GET_VIDEO_DISPLAY_RESP				= 0X40004,
 * IOTYPE_USER_IPCAM_SET_VIDEO_DISPLAY_REQ				= 0X40005,
 */
typedef struct
{ 
	unsigned char osd;				//�Ƿ���osd����
	unsigned char closeInfrared;	//�Ƿ�رպ��� (1�ر�)
	short brightness;				//����
	short contrast;					//�Աȶ�
	short hue;						//�Ҷ�
	short saturation;				//���Ͷ�
	short sharpness;				//���
	unsigned char osdMode;	// 0:��-��-��  ʱ���֣���  1: ��-��-��  ʱ���֣���  2:��-��-��  ʱ���֣���
	unsigned char reserved[3];	
} SMsgAVIoctrlGetVideoDisplayResp, SMsgAVIoctrlSetVideoDisplayReq;

/* IOTYPE_USER_IPCAM_SET_VIDEO_DISPLAY_RESP				= 0X40006,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlSetVideoDisplayResp;

typedef struct
{ 
	unsigned char io;				//�Ƿ���io����
	unsigned char open;				//�Ƿ�� 1: ����
} AlarmIoCtrl;

/* IOTYPE_USER_IPCAM_GET_ALARM_ARG_RESP				= 0X40008,
 * IOTYPE_USER_IPCAM_SET_ALARM_ARG_REQ				= 0X40009,
 */
 #if 0
typedef struct
{ 
	unsigned char md_sensitivity;	//�ƶ���������ȣ�0��ʾ���ã�
	unsigned char sd_sensitivity;	//������������ȣ�0��ʾ���ã�
	AlarmIoCtrl io_in;				//�Ƿ���io����
	AlarmIoCtrl alarm_io;			//����ʱ�Ƿ������io
	unsigned char alarm_record;		//����ʱ�Ƿ�¼����SD��
	unsigned char alarm_snapshot;	//����ʱ�Ƿ�������SD��
	unsigned char alarm_mail;		//����ʱ�Ƿ�������email 
	unsigned char reserved[3];		
} SMsgAVIoctrlGetAlarmArgResp, SMsgAVIoctrlSetAlarmArgReq;
#else
typedef struct
{ 
	unsigned char md_sensitivity;	//�ƶ���������ȣ�0��ʾ���� 1 2 3��
	unsigned char sd_sensitivity;	//������������ȣ�0��ʾ���� 1 2 3��
	unsigned char buzzer_enable;	//���������أ�0��ʾ���� 1 ʹ�ܣ�

	unsigned char md_time;			//�ƶ������ʱ��  0 �� 120 ��
	unsigned char audio_time;		//���������ʱ��  0 �� 120 ��
	unsigned char buzzer_time;		//����������ʱ��  0 �� 120 ��
	
	unsigned char alarm_record;		//����ʱ�Ƿ�¼����SD��
	unsigned char alarm_record_time;		//0 �� 250��
	
	unsigned char alarm_snapshot;	//����ʱ�Ƿ�������SD��
	unsigned char alarm_mail;		//����ʱ�Ƿ�������email 
	unsigned char reserved[4];		
} SMsgAVIoctrlGetAlarmArgResp, SMsgAVIoctrlSetAlarmArgReq;

#endif

/* IOTYPE_USER_IPCAM_SET_ALARM_ARG_RESP				= 0X40010,
 */
typedef struct
{
	int result;            	       	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlSetAlarmArgResp;

/* IOTYPE_USER_IPCAM_GET_EMAIL_ARG_RESP				= 0X40012,
 * IOTYPE_USER_IPCAM_SET_EMAIL_ARG_REQ					= 0X40013,
 */
typedef struct
{ 
	unsigned char sender[64];			// email��������
	unsigned char receiver[64];			// email��������
	unsigned char smtp_svr[64];			// smtp ��������ַ
	unsigned char smtp_user[32];		// smtp �û�
	unsigned char smtp_pwd[32];			// smtp ����
	unsigned long smtp_port;			// smtp �������˿�
	unsigned char smtp_auth;			// smtp �������Ƿ���Ҫ��֤
	unsigned char smtp_ssl;				// /*�Ƿ�����ssl��ȫ��¼1:��0:��*/
	unsigned char reserved[2];	
} SMsgAVIoctrlGetEmailArgResp, SMsgAVIoctrlSetEmailArgReq;

/* IOTYPE_USER_IPCAM_SET_EMAIL_ARG_RESP				= 0X40014,
 */
typedef struct
{
	int result;            	       	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlSetEmailArgResp;

/* IOTYPE_USER_IPCAM_FACTORY_SETTINGS_RESP				= 0X40016,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlFactorySettingsResp;

/* IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_REQ				= 0X40017,
 */
typedef struct
{ 
	unsigned char device_name[24];		//�豸����	
	unsigned char reserved[4];
} SMsgAVIoctrlSetDeviceInfoReq;

/* IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_RESP				= 0X40018,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlSetDeviceInfoResp;

/* IOTYPE_USER_IPCAM_REBOOT_SYSTEM_RESP				= 0X40020,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlRebootSystemResp;

/* IOTYPE_USER_IPCAM_RESTORE_DEFAULT_RESP			= 0X40021,
 * ����ǰ�Ự�ķֱ��ʡ�������֡�ʡ���̨ת�١�OSD��ʾ����ԴƵ�ʡ����ȡ��Աȶȡ����Ͷȡ��ҶȺ���Ȼָ���ϵͳĬ��ֵ��
 */
typedef struct
{
	unsigned char status;			//��̨״̬���ο�ENUM_PTZ_STATUS
	unsigned char speed;			//��̨�ٶ�
	unsigned char reserved[2];
} SMsgAVIoctrlGetPtzStatusResp;
typedef enum 
{ 
	AVIOCTRL_PTZ_NO_ACTION_PATROL		= 0x0,	//��Ѳ��
	AVIOCTRL_PTZ_LEFT_RIGHT_PATROL		= 0x1,	//����Ѳ��
	AVIOCTRL_PTZ_UP_DOWN_PATROL			= 0x2,	//����Ѳ��
	AVIOCTRL_PTZ_TRACK_PATROL			= 0x3,	//�켣Ѳ��
	AVIOCTRL_PTZ_PATROL					= 0x4,	//�켣Ѳ��
}ENUM_PTZ_STATUS;

typedef enum 
{
	RESOLUTION_160_120		= 0x01,		//�ֱ���160*120
	RESOLUTION_320_240		= 0x02, 	//�ֱ���320*240
	RESOLUTION_640_480		= 0x03, 	//�ֱ���640*480
	RESOLUTION_800_600		= 0x04, 	//�ֱ���800*600
	RESOLUTION_1024_768		= 0x05, 	//�ֱ���1024*768
	RESOLUTION_1280_720		= 0x06,		//�ֱ���1280*720
	RESOLUTION_640_368		= 0x07,		//�ֱ���640*368
	RESOLUTION_320_200		= 0x08		//�ֱ���320*200
}ENUM_RESOLUTION;

/* IOTYPE_USER_IPCAM_GET_VIDEO_QUALITY_RESP			= 0X40024,
 * IOTYPE_USER_IPCAM_SET_VIDEO_QUALITY_REQ			= 0X40025,
 * 
 */
typedef struct
{
	short bitrate;					//����
	unsigned char quant;			//����
	unsigned char fps;				//֡��
	unsigned char resolution;		//�ֱ���,�μ�ENUM_RESOLUTION 
	unsigned char hmethod;	//�Ƿ�̶�����
	unsigned char reserved[2];
} SMsgAVIoctrlSetVideoQualityReq, SMsgAVIoctrlGetVideoQualityResp;

typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlSetVideoQualityResp;

/* IOTYPE_USER_IPCAM_TEST_EMAIL_ARG_RESP			= 0X40028,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlTestEmailArgResp;


/* IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_REQ			= 0X40029,
 */
typedef struct
{
	unsigned int	total;			//���������ܴ�С
	unsigned short	index;			//��ǰ��������
	unsigned short	endflag;		//������־
	unsigned int	size;			//��ǰ���Ĵ�С
	unsigned char	reserved[4];
	unsigned char	szBuf[0];		//������������
}SMsgAVIoctrlUpgradeSystemReq;


/* IOTYPE_USER_IPCAM_UPGRADE_SYSTEM_RESP			= 0X40030,
 */
typedef struct
{
	int result;                   	//return 0 if succeed
	unsigned char reserved[4];
} SMsgAVIoctrlUpgradeSystemResp;

/* IOTYPE_USER_IPCAM_GET_EVENT_LIST_REQ				= 0X40031,
 */
typedef struct
{
	unsigned int nStartTime; 		// Search event from ...
	unsigned int nEndTime;	  		// ... to (search event)
	unsigned char reserved[4];
}SMsgAVIoctrlGetAlarmListReq;



typedef struct alarm_log_t
{
	unsigned int 	time;;
	ENUM_EVENTTYPE 	event_type;
}alarm_log;

typedef struct
{
	unsigned int  	total;		// Total event amount in this search session
	unsigned char 	index;		// package index, 0,1,2...; 
								// because avSendIOCtrl() send package up to 1024 bytes one time, you may want split search results to serveral package to send.
	unsigned char 	endflag;		// end flag; endFlag = 1 means this package is the last one.
	unsigned char 	count;		// how much events in this package
	unsigned char 	reserved[1];
	alarm_log 		stalarm[0];		// The first memory address of the events in this package
}SMsgAVIoctrlAlarmListResp;


/*
IOTYPE_USER_IPCAM_GET_AUDIO_MOTION_REQ		= 0X40033,	//��ȡ�������
IOTYPE_USER_IPCAM_GET_AUDIO_MOTION_RESP		= 0X40034,
IOTYPE_USER_IPCAM_SET_AUDIO_MOTION_REQ		= 0X40035,	//���������������
IOTYPE_USER_IPCAM_SET_AUDIO_MOTION_RESP		= 0X40036,
*/
typedef struct
{
	int				enable;		//ʹ��
	int				sensitive;	//������(1-3:��-��-��)
	int  			timeout ;       /*����ʱ��*/
	//����
	BYTE 			msdrec_enable;
	BYTE			mmail_enable;
	BYTE			mftp_enable;
	BYTE			malarmout_enable;
	unsigned char 	reserved[4];
} SMsgAVIoctrlSetAudioMotionReq, SMsgAVIoctrlGetAudioMotionResp;

typedef struct
{
	int 			result;     //return 0 if succeed
	unsigned char 	reserved[4];
} SMsgAVIoctrlSetAudioMotionResp;

	
/*
IOTYPE_USER_IPCAM_GET_NET_REQ				= 0X40037,	//��ȡ��������
IOTYPE_USER_IPCAM_GET_NET_RESP				= 0X40038,
IOTYPE_USER_IPCAM_SET_NET_REQ				= 0X40039,	//������������
IOTYPE_USER_IPCAM_SET_NET_RESP				= 0X40040,
*/
typedef struct
{
	int 	web_port;
	int 	video_port;
	int 	onvif_port;					/*onvifͨѶ�˿�*/
	int 	rtsp_port;					/*RTSPͨѶ�˿�*/
	char 	ipcamIP[16]; 				/* ipcam IP��ַ */ 
	char 	ipcamIPMask[16]; 			/* ipcam IP��ַ���� */ 
	char 	ipcamGatewayIP[16]; 		/* ���ص�ַ */ 
	char 	byMACAddr[MACADDR_LEN]; 	/* ֻ�����������������ַ */ 
	char 	byDnsaddr[2][16]; 			/* DNS��ַ */ 
	char 	sPPPoEUser[NAME_LEN]; 		/* PPPoE�û��� */ 
	char 	sPPPoEPassword[PASSWD_LEN];	/* PPPoE���� */ 
	char 	sPPPoEIP[16]; 				//PPPoE IP��ַ(ֻ��)
	BYTE 	dwPPPOE; 					/* 0-������,1-���� */ 
	BYTE	conn_mod;					/*0-��̬��ַ 1-DHCP 2-pppoe*/
	BYTE	reserved[2];
} SMsgAVIoctrlSetNetReq, SMsgAVIoctrlGetNetResp;

typedef struct
{
	int 			result;     //return 0 if succeed
	unsigned char 	reserved[4];
} SMsgAVIoctrlSetNetResp;

/*
IOTYPE_USER_IPCAM_GET_SNAP_RESP			= 0X40041	//�ͻ���ץ������
*/
#define SNAP_BUFFER_SIZE 990
typedef struct
{
	short int 	size;//�ܴ�С
	short int 	singleSize;//��ǰ����С
	BYTE		packNum;//�ܰ���
	BYTE		packNo;//���ţ���0��ʼ
	char 	snapBuf[SNAP_BUFFER_SIZE];
} SMsgAVIoctrlSetSnapResp;

/*
IOTYPE_USER_IPCAM_DEFAULT_VIDEO_REQ			= 0X40043,	//�ͻ�������Ĭ�ϵ���Ƶ�ֱ��ʡ�������֡�ʣ���Ƶ����
IOTYPE_USER_IPCAM_DEFAULT_VIDEO_RESP		= 0X40044
*/
typedef struct
{
	int 			client_type; 	//0:cms and web;1: mobile
	unsigned char	reserved[4];
} SMsgAVIoctrlDefaultVideoReq;


typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlDefaultVideoResp;

/* 
IOTYPE_USER_IPCAM_WIRTE_DEV_CONFIG_REQ			= 0X40045,
IOTYPE_USER_IPCAM_READ_DEV_CONFIG_RESP			= 0X40048,
 */
typedef struct
{
	char 	szUID[24];//�ٶ�ʹ�õ��豸ID  
	char 	szPwd[32];//�ٶ�ʹ��ʱpwd��ʱ���� ȫ��д0
	char 	szMacAddr[20];
	unsigned char	reserved[4];
} SMsgAVIoctrlWriteDevConfigReq, SMsgAVIoctrlReadDevConfigResp;

typedef struct
{
	char 	szMacAddr[24];
	char 	szUID[32];//�ٶ�ʹ�õ��豸ID  
	char 	szPwd[32];//�ٶ�ʹ��ʱpwd��ʱ���� ȫ��д
} SDEMsgAVIoctrlWriteDevConfigReq, SDEMsgAVIoctrlReadDevConfigResp;

/* IOTYPE_USER_IPCAM_WIRTE_DEV_CONFIG_RESP			= 0X40046
 */
typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlWriteDevConfigResp;

/* IOTYPE_USER_IPCAM_RESET_STATUS_RESP			= 0X40049
 */
typedef struct
{
	unsigned char	result; 	//0���ɿ���1������
	unsigned char	reserved[3];
} SMsgAVIoctrlResetStatusResp;

/*
IOTYPE_USER_IPCAM_SET_NTP_CONFIG_REQ		= 0X40050,	//д��ntp��������Ϣ
IOTYPE_USER_IPCAM_SET_NTP_CONFIG_RESP		= 0X40051,
IOTYPE_USER_IPCAM_GET_NTP_CONFIG_REQ		= 0X40052,	//��ȡntp��������Ϣ
IOTYPE_USER_IPCAM_GET_NTP_CONFIG_RESP		= 0X40053,

*/
typedef struct _ntp_set_time
{
	unsigned int year;
	unsigned int month;
	unsigned int date;
	
	unsigned int hour;
	unsigned int minute;
	unsigned int second;

}ntp_set_time;
	
typedef struct
{
	unsigned int 	mod;	 ///1,ntp 2 manul
	unsigned char 	Server[32];//NTP Server:
	ntp_set_time 	time;//manul time
	unsigned char 	TimeZone;//TimeZone:  0~25:(GMT-12)~GMT~(GMT+12)
} SMsgAVIoctrlSetNtpConfigReq, SMsgAVIoctrlGetNtpConfigResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetNtpConfigResp;



/*
	IOTYPE_USER_IPCAM_GET_COMPANY_CONFIG_REQ	= 0X40054,	//��ȡ��˾��Ϣ
	IOTYPE_USER_IPCAM_GET_COMPANY_CONFIG_RESP	= 0X40055
*/

typedef struct
{
	unsigned char model[64];	// IPCam mode
	unsigned char vendor[64];	// IPCam manufacturer
	unsigned int version;		// IPCam firmware version	ex. v1.2.3.4 => 0x01020304;  v1.0.0.2 => 0x01000002
	unsigned int channel;		// Camera index
	unsigned int total;			// 0: No cards been detected or an unrecognizeable sdcard that could not be re-formatted.
								// -1: if camera detect an unrecognizable sdcard, and could be re-formatted
								// otherwise: return total space size of sdcard (MBytes)								
								
	unsigned int free;			// Free space size of sdcard (MBytes)
	unsigned char reserved[8];	// reserved
}SMsgAVIoctrlGetCompanyConfigResp;

/*
IOTYPE_USER_IPCAM_GET_DEVICEMODEL_CONFIG_REQ	= 0X40056,	//��ȡװ����Ϣ
IOTYPE_USER_IPCAM_GET_DEVICEMODEL_CONFIG_RESP	= 0X40057,

IOTYPE_USER_IPCAM_SET_DEVICEMODEL_CONFIG_REQ	= 0X40058,	//д��װ����Ϣ
IOTYPE_USER_IPCAM_SET_DEVICEMODEL_CONFIG_RESP	= 0X40059
*/
typedef struct
{
	char			deviceModel[64];	//�豸�ͺ�
	char			manufacturer[64];	//������
	unsigned int	serverMask;			//λ��˵��(0:mic 1:speak 2:wifi 3:I/O����������� 4:SD��¼�� 5:��̨) ��λ1��Ч��0��Ч��
	char 			reserv[4]; 			//����
} SMsgAVIoctrlSetDevModelConfigReq, SMsgAVIoctrlGetDevModelConfigResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetDevModelConfigResp;

/*
IOTYPE_USER_IPCAM_GET_DROPBOX_CONFIG_REQ	= 0X4005A,	//��ȡDROPBOX��Ϣ
IOTYPE_USER_IPCAM_GET_DROPBOX_CONFIG_RESP	= 0X4005B,

IOTYPE_USER_IPCAM_SET_DROPBOX_CONFIG_REQ	= 0X4005B,	//��ȡDROPBOX��Ϣ
IOTYPE_USER_IPCAM_SET_DROPBOX_CONFIG_RESP	= 0X4005D

*/
#if 0
typedef struct
{
	char			enable_dropbox; /*0:disable 1:enable*/
	char			upload_mediaType;/*0:none 1:picture 2:alarm record 3:all time record 4:all picture and record*/
	unsigned short 	timing_snapshot_interval;/*��ʱץ�Ĺ��ܵ�ʱ����ֵ 0:disable��ʱץ�� >0:ץ�ļ��(��λ.��)*/
	char			appKey[64];
	char			appSecret[64];
	char			oauth_accessToken[64];
	char			oauth_accessTokenSecret[64];
	char 			reserv[4]; 			//����
} SMsgAVIoctrlSetDropboxConfigReq, SMsgAVIoctrlGetDropboxConfigResp;
#endif

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetDropboxConfigResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
}SMsgAVIoctrlSetUploadFunctionConfigResp;

/*
IOTYPE_USER_IPCAM_CLOSE_LED_CONFIG_REQ	= 0X40066,	//�ر�ledָʾ��
IOTYPE_USER_IPCAM_CLOSE_LED_CONFIG_RESP	= 0X40067,

IOTYPE_USER_IPCAM_CLOSE_LED_STATUS_CONFIG_REQ	= 0X40068,	//ledָʾ�ƹر�״̬
IOTYPE_USER_IPCAM_CLOSE_LED_STATUS_CONFIG_RESP	= 0X40069
*/
typedef struct
{
	char			isCloseLed;	//1:�ر�LED 0:LED����������ʾ
	char			reserv[7];	//����
} SMsgAVIoctrlCloseLedConfigReq, SMsgAVIoctrlCloseLedStatusConfigResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlCloseLedConfigResp;

//add by jy
typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSendPicConfigResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSendPicToShareConfigResp;


//time mode
/*typedef struct
{
	int 			mode; 		//0:China   1:America  2:Europe
	unsigned char	reserved[4];
} SMsgAVIoctrlSetTimeModeConfigReq, SMsgAVIoctrlGetTimeModeConfigResp;*/


typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetTimeModeConfigResp;

//time mode add by jy
typedef struct
{
	int 			mode; 		//0:China   1:America  2:Europe
	unsigned char	reserved[4];
} SMsgAVIoctrlSetTimeModeConfigReq, SMsgAVIoctrlGetTimeModeConfigResp;

typedef struct
{
	double			rate; 		//����
	unsigned char	reserved[4];
} SMsgAVIoctrlSetPlayBackRateConfigReq;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlPlaybackrateConfigResp;

//end add
//IOTYPE_USER_IPCAM_SET_RECORD_SCHEDULE_REQ		= 0X4007E,	//����¼���ų�
//IOTYPE_USER_IPCAM_SET_RECORD_SCHEDULE_RESP		= 0X4007F,	// 

//IOTYPE_USER_IPCAM_GET_RECORD_SCHEDULE_REQ		= 0X40080,	//��ȡ¼���ų�
//IOTYPE_USER_IPCAM_GET_RECORD_SCHEDULE_RESP		= 0X40081,	// 

#define MAX_WEEK_NUM	7
#define MAX_DAY_NUM		7
#define MAX_DATE_LEN	12

typedef struct  
{
	int slot;						//ÿһλ����һ��Сʱ
	char szDate[MAX_DATE_LEN];
}DayData;

typedef struct
{
	int week[MAX_WEEK_NUM];			//ÿһλ����һ��Сʱ
	DayData day[MAX_DAY_NUM];
	unsigned char	reserved[4];
} SMsgAVIoctrlSetRecordScheduleReq, SMsgAVIoctrlGetRecordScheduleResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetRecordScheduleResp;

//end


//	IOTYPE_USER_IPCAM_SET_MOTION_AREA_REQ			= 0X40079,	// �ƶ�������� ��������
//	IOTYPE_USER_IPCAM_SET_MOTION_AREA_RESP			= 0X4007A,	// 

#define MAX_MOTION_AREA 4

typedef struct _rect_s
{
	int 	start_x;	//��ʼ����
	int		start_y;	
	int 	end_x;		//�յ�����
	int		end_y;	
}rect_t;

typedef struct
{
	int area_enable[MAX_MOTION_AREA];  // area_enable : 1 ����ʹ��  0 �����ֹ   ��ʱû���õ�����
	rect_t area[MAX_MOTION_AREA]; //�����ڵ�����ֵ ������16��������

}SMsgAVIoctrlSetMotionAreaReq, SMsgAVIoctrlGetMotionAreaResp;


typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetMotionAreaResp;


typedef struct
{
	int result;	// 0: success; otherwise: failed.
	unsigned char reserved[4];
}SMsgAVIoctrlSetBaiDuInfoResp;


#define MAX_ACCESS_TOKEN_LEN         128      //
#define MAX_MANU_STR_LEN         64      //������
#define MAX_VER_STR_LEN         32      //�汾��Ϣ����
#define MAX_SERIAL_NO_LEN       32		//���кų���
#define MAX_USR_ID_LEN			32		//�û�ID����
#define MAX_DVR_NAME_LEN        32      //�豸���Ƴ���
#define MAX_CHANN_NAME_LEN      32      //ͨ�����Ƴ���
#if 0
typedef struct
{
	unsigned char			usr_no[MAX_USR_ID_LEN];			//�û�ID			//new add 
	unsigned char			serial_no[MAX_SERIAL_NO_LEN];	//�豸���к� //��֧�ְٶ�  TUTK
	unsigned char 			device_type[MAX_VER_STR_LEN];       /* ��Ʒ�ͺ� */
	unsigned char			manufacturer[MAX_SERIAL_NO_LEN];	//������
	int						serverMask;							//��Ʒ֧�ֵĹ���
	char 					reserv[4]; 							//����
}SMsgAVIoctrlGetMdSysInfoResp;
#else
typedef struct 
{
   
    /*---------- ������Ϣ���ɸ��� ----------*/
    unsigned char serial_1[MAX_SERIAL_NO_LEN];       //���к�  �ٶ�ʹ��
    unsigned char serial_2[MAX_SERIAL_NO_LEN];       //���к� tutk ʹ��
    unsigned char manufacturer[MAX_MANU_STR_LEN];    //������
     unsigned char device_type[MAX_VER_STR_LEN];      //�豸�ͺ�
    unsigned char software_ver[MAX_VER_STR_LEN];      //����汾��
    unsigned char software_date[MAX_VER_STR_LEN];     //�����������
    unsigned char hardware_ver[MAX_VER_STR_LEN];      //Ӳ���汾
    
    unsigned int dev_type;                          //�豸����SDK_DEV_TYPE_E   ��Ҫ���¶���
	unsigned int server_mask;						// ÿһλ�����豸֧�ֵķ�����  ���� �ٶ�  tutk  onvif 
	unsigned int io_mask;						  // ÿһλ�����豸����  ��Ҫ���¶��� 0:mic 1:speak 2:wifi 3:I/O����������� 4:SD��¼�� 5:��̨)

	unsigned char  max_stream;                         //��Ƶ����Ŀ
    unsigned char  max_resolution;                    //������ֱ���
    unsigned char  res[2];                    //������ֱ���
    
}SMsgAVIoctrlGetMdSysInfoResp;
#endif


#if 0
#define MAX_LED_NUM	4
typedef struct
{
	char led_status[MAX_LED_NUM];	//led_status[0]:   red----1:on 0:off
									// led_status[1]:green----1:on 0:off
									// led_status[2]: blue----1:on 0:off
} SMsgAVIoctrlSetLedStatusReq, SMsgAVIoctrlGetLedStatusResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetLedStatusResp;


typedef struct
{
	int  buzzer_status;	// buzzer_status ----1:on 0:off
									
} SMsgAVIoctrlSetBuzzerStatusReq, SMsgAVIoctrlGetBuzzerStatusResp;

typedef struct
{
	int 			result; 	//return 0 if succeed
	unsigned char	reserved[4];
} SMsgAVIoctrlSetBuzzerStatusResp;
#endif

// AWS support ����ѷ¼���ϴ����� ��ѯ������ 
//IOTYPE_USER_IPCAM_GET_AWS_STATUS_REQ	  = 0X4008A,
//IOTYPE_USER_IPCAM_GET_AWS_STATUS_RESP	  = 0X4008B,
//IOTYPE_USER_IPCAM_SET_AWS_STATUS_REQ	  = 0X4008C,
//IOTYPE_USER_IPCAM_SET_AWS_STATUS_RESP	  = 0X4008D,
typedef struct
{
	char			aws_record;	//0: ��Ƶ�����ϴ�  1:�б����¼����ϴ���Ƶ
	char			reserv[3];			//����
} SMsgAVIoctrlSetAwsStatusReq, SMsgAVIoctrlGetAwsStatusResp;

 typedef struct
 {
	 int			 result;	 //return 0 if succeed
	 unsigned char	 reserved[4];
 } SMsgAVIoctrlSetAwsStatusResp;

 // REMOTE UPGRADE	 ��������
//IOTYPE_USER_IPCAM_REMOTE_UPGRADE_REQ	  = 0X4008E,
//IOTYPE_USER_IPCAM_REMOTE_UPGRADE_RESP	  = 0X4008F,
typedef struct
{
	char			 new_version[64];	 //���������Ĳ�Ʒ�汾��
	char			 url_parth[128]; 		 //�����ļ���ŵķ�������ַ
} SMsgAVIoctrlRemoteUpgradeReq;
	 
typedef struct
{
	int			  result;	  //0 : �������� 1:��ǰ�Ѿ������°汾����������   -1:δ֪����
	unsigned char   reserved[4];
} SMsgAVIoctrlRemoteUpgradeResp;



// UPGRADE PROGRESS  �������Ȳ�ѯ
//IOTYPE_USER_IPCAM_UPGRADE_PROGRESS_REQ		= 0X40090,
//IOTYPE_USER_IPCAM_UPGRADE_PROGRESS_RESP 	= 0X40091,
typedef struct
{
		int			progress_value;	//�������� :0~100  ��ʾ��������   -1: δ֪����
		char		reserv[4];	//����
} SMsgAVIoctrlProgressResp;


typedef struct
{
		char		type; // 1 ���� 2 wifi 
		char		reserv[4];	//����
} SMsgAVIoctrlGetMacAddrReq; 


#define MAX_MAC_ADDR_LEN        20      //MAC��ַ����
typedef struct
{
		 char		type; // 1 ���� 2 wifi 
		 char 		mac[MAX_MAC_ADDR_LEN];   
		 char		reserv[4];	//����
} SMsgAVIoctrlGetMacAddrResp; 
#endif
