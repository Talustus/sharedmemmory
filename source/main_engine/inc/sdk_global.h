/*
 * =====================================================================================
 *
 *       Filename:  sdk_global.h
 *
 *    Description:  global struct typedef
 *
 *        Version:  1.0
 *        Created:  2011��05��26�� 02ʱ39��08��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *        Company:  9527
 *
 * =====================================================================================
 */
#ifndef __sdk_global_h__
#define __sdk_global_h__

//module id
#define MODULE_ID_MAIN      0x01
#define MODULE_ID_CODEC     0x02
#define MODULE_ID_RECORD    0x03
#define MODULE_ID_PARAM     0x04
#define MODULE_ID_NET       0x05
#define MODULE_ID_GUI       0x06
#define MODULE_ID_WEB       0x07
#define MODULE_ID_PTZ       0x08
#define MODULE_ID_DAEMON    0x09
#define MODULE_ID_PUMNG     0x0A
#define MODULE_ID_ALL       0xFF
#define MODULE_MSG_REGISTER 0xFFFF

#define LIKELY(x)   (__builtin_expect(!!(x),1))
#define UNLIKELY(x) (__builtin_expect(!!(x),0))

typedef unsigned char  	    u8;	/**< UNSIGNED 8-bit data type */
typedef unsigned short 	    u16;/**< UNSIGNED 16-bit data type */
typedef unsigned int   	   u32;	/**< UNSIGNED 32-bit data type */
typedef unsigned long long u64; /**< UNSIGNED 64-bit data type */
typedef signed char         s8;	/**< SIGNED 8-bit data type */
typedef signed short       s16;	/**< SIGNED 16-bit data type */
typedef signed int         s32;	/**< SIGNED 32-bit data type */


/*****************���ܺ궨��*****************************/
#ifndef MAX
#define MAX(x, y)       ((x) > (y) ? (x) : (y))
#endif

#ifndef MIN
#define MIN(x, y)       ((x) < (y) ? (x) : (y))
#endif


#define TEST_BIT(x,  n)      ((x) & ( 1 << (n)))
#define SET_BIT(x,  n)     do {  x =  (x | ( 1 << (n))) ; } while(0);
#define CLEAR_BIT(x,  n)    do { x =  (x & (~( 1 << (n))));  } while(0);

//chang  by zw add for gloab_info

#define BYTE unsigned char



//��������
typedef struct tag_remote_alarm_pra
{ 
  	BYTE  	sen_alarm_onoff;		/*�ⲿ���� ����	 		��0 ���� 1*/
 	BYTE  	sen1_off;     				/*�ⲿ��������1   			��0 ���� 1*/
 	BYTE  	sen1_mod;     			/*����1ģʽ   				����0 ������ 1*/
  	BYTE	sen2_off;				/*�ⲿ��������2   			��0 ���� 1*/
 	BYTE  	sen2_mod;     			/*����2ģʽ   				����0 ������1*/
  	BYTE	sdloss_onoff;			/*SD����ʧ���� 			��0 ���� 1*/
	BYTE 	Param1;
	BYTE 	Param2;
  	int  	timeout ;       			/*����  ����ʱ��*/
  
	//��������
	BYTE 		sdrec_enable;			/*����SD��ץͼ��¼��ʹ�� 	�������1 �� �ر����0*/
	BYTE		mail_enable;			/*�����ʼ�����ʹ�� 	�������1 �� �ر����0*/
	BYTE		ftp_enable;				/*����ftp����ʹ�� 	�������1 �� �ر����0*/
	BYTE		alarmout_enable;		/*�������ʹ�� 	�������1 �� �ر����0*/
}REMOTE_ALARM_PRA;

typedef struct motion_rect_s
{
	int 	start_x[4];	//��ʼ����ٷֱ�
	int		start_y[4];	
	int 	end_x[4];		//�յ�����ٷֱ�
	int		end_y[4];	
}MOTION_RECT;


typedef struct tag_remote_motion_pra
{ 
	BYTE 	motion_Enable;	/* �Ƿ����ƶ���� */ 
	BYTE 	byMotionSensitive;		//  1-5 �� ��  �� ���
	int 	start_x[4];	//��ʼ����
	int		start_y[4];	
	int 	end_x[4];		//�յ�����
	int		end_y[4];	
 	int  		timeout ;       /*����ʱ��*/
	//��������
	BYTE 		msdrec_enable;
	BYTE		mmail_enable;
	BYTE		mftp_enable;
	BYTE		malarmout_enable;
}REMOTE_MOTION_PRA; 


typedef struct Alarm_state
{
	int	 alstate;		//�ܱ���״̬
	int	 motion_s;	    //�ƶ���ⱨ�� 1:����
	int	 sense0_s;	    //����������1		1:����
	int	 sense1_s;    	//����������2		1:����
	int	 sd_s;		    //SD������ 0 :sd ������  1:sd���γ� 2:sd����������3:sd��д���� 
}ALARM_STATE;

REMOTE_ALARM_PRA 	g_alarm_pra;			//�澯ȫ������
REMOTE_MOTION_PRA 	g_motion_pra;			//�ƶ����ȫ������


int					g_detect_alarm;			//�ƶ���ⱨ��
//int					g_audio_motion_state;   //������ⱨ��
int					g_send_alarm_flag;
int					g_alarm_out;			//�������
ALARM_STATE			g_alarm_state;



#if 0 
extern REMOTE_ALARM_PRA 	g_alarm_pra;			//�澯ȫ������
extern REMOTE_MOTION_PRA 	g_motion_pra;			//�ƶ����ȫ������


extern int					g_detect_alarm;			//�ƶ���ⱨ��
extern int					g_audio_motion_state;   //������ⱨ��
extern int					g_send_alarm_flag;
extern int					g_alarm_out;			//�������
extern ALARM_STATE			g_alarm_state;
#endif

//
/*
extern REMOTE_EQUINFO  		g_equinfo;
extern REMOTE_NETCFG  		g_netcfg;
extern REMOTE_WIFICFG 		g_wifi_cfg;
extern REMOTE_VIDEO_PRA_D 	g_video_pra;
extern REMOTE_VIDEO_REL 	g_video_rel;
extern REMOTE_VOICE			g_voice;

extern REMOTE_EMAILCFG		g_email_cfg;
extern REMOTE_FTPCFG		g_ftpcfg;
extern REMOTE_FTPCFG1		g_ftpcfg1;
extern REMOTE_MULTI_CFG		g_multi_cfg;
extern L_IPC_SDRCTRL		g_sdrctrl;
extern PTZ_CFG				g_ptz_cfg;
extern ntp_conf 			g_ntp_pra;
extern DEVICE_INFO			g_device_info;

extern T_PRESET 			g_presetstation;
extern BUZZER_ALARM_PRA 	g_buzzer_pra;			//������ȫ�ֲ���



//����SD��¼���ȫ������
extern L_IPC_SDRCTRL_N		g_reccfg;
extern L_LAMP_CTRL			g_lamp_ctrl;
extern SYCC_ACCOUNT			g_sycc_account;
extern SYCC_LAN				g_sycc_lan;

extern MOBILE_VIDEO_PRA		g_mob_video_cfg;
extern REMOVE_INFRARED_REL 	g_infrared;

extern audio_motion_cfg 	g_audio_motion;
extern SMsgAVIoctrlSetDropboxConfigReq g_dropbox_cfg;
extern SMsgAVIoctrlSetUploadFunctionConfigReq g_UploadFunction_cfg;





//����Ҫ����flashȫ������
extern MB_JPEG_DATA			g_mbjpeg0;
extern MB_JPEG_DATA			g_mbjpeg1;
extern TUTK_INFO 			g_tutk_cfg;
extern ALARM_STATE			g_alarm_state;
extern int					g_audio_motion_state;

extern EXT_LIB_PRO			g_pExt_lib_pro;
extern PTZ_LIB_CTRL			g_pPtz_lib_pro;
extern BUFLIST 				g_remotesendList;	//Զ����Ϣ���Ͷ���
extern L_IPC_SDREC_STATUS 	g_sdrec_status;
extern LOG_ADD_STRUCT 		g_log_add;
extern PUSH_CONTENT			g_push_content;
extern SNAP_CONT 			g_snapcont;

extern int					g_cap_mtype;       //��ͷ������ (0:CCD 1:CMOS) ��� SCENE_TYPE
extern int					g_cap_type;     //12:7725           32:9715            33:9p031

//motion
extern int 					count_altime;
extern int					g_detect_alarm;
extern int					g_send_alarm_flag;
extern int 					g_grap_img_flag;
extern int 					g_send_img_flag;
extern int					g_alarm_out;
extern int					g_i2c_fd;
extern int					g_audio_motion_send_email;

*/

#endif //__sdk_global_h__


