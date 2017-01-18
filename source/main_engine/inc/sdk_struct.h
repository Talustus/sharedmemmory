#ifndef __sdk_struct_h__
#define __sdk_struct_h__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>
#include <sys/time.h>

//access_token
#define MAX_ACCESS_TOKEN_LEN    128      //
#define MAX_MANU_STR_LEN        64      //������
#define MAX_VER_STR_LEN         32      //�汾��Ϣ����
#define MAX_SERIAL_NO_LEN       32		//���кų���
#define MAX_USR_ID_LEN			32		//�û�ID����
#define MAX_DVR_NAME_LEN        32      //�豸���Ƴ���
#define MAX_CHANN_NAME_LEN      32      //ͨ�����Ƴ���

//#define MAX_CHANN_NUM           32      //���ͨ������
#define MAX_CHANN_NUM           2      //���ͨ������  ����IPC��˵����ͨ������
#define MAX_USER_NAME_LEN       32      //�û�������
#define MAX_PASSWD_LEN          32      //���볤��
#define MAX_ALARM_IN_NAME_LEN   32      //�����������Ƴ���
#if 0
#define MAX_WEEK_NUM            8       //��������
#define MAX_TIME_SEG_NUM        4       //ʱ��θ���
#endif
//chang  bu zw for baidu
#define MAX_WEEK_NUM            7       //��������
#define MAX_TIME_SEG_NUM        5       //ʱ��θ���


#define MAX_ALARM_OUT_NUM       16      //��󱨾��������
#define MAX_ALARM_IN_NUM        16      //��󱨾��������
#define MAX_IP_ADDR_LEN         40      //IP��ַ����
#define MAX_MAC_ADDR_LEN        20      //MAC��ַ����
#define MAX_ETHERNET_NUM        4       //��������
#define MAX_RECORD_ITEM_LEN     64      //¼���¼���Ƴ���
#define MAX_LOG_DESC_LEN        128     //��־��¼���ݳ���
#define MAX_USER_NUM            16      //����û�����
#define MAX_PRESET_NUM          256     //�����̨Ԥ��λ����
#define MAX_CRUISE_NUM          256     //�����̨Ѳ������
#define MAX_CRUISE_PRESET_NUM   16      //ÿ��Ѳ�������֧�ֵ�Ԥ��λ����
#define MAX_CHANN_CONN_NUM      8       //ÿ��ͨ�����֧�ֵ�������
#define MAX_DISK_NUM            8       //�����̸���
#define MAX_ALARM_DESC_LEN      64      //������¼���ݳ���
#define MAX_SCREEN_NUM          4       //���������Ļ����
#define MAX_WINDOWS_NUM         32      //����Ԥ����Ƶ��󴰿ڸ���
#define MAX_PREVIEW_MODE        8       //���Ԥ�����ָ���
#define MAX_OVERLAY_NUM         4       //ÿ��ͨ����󸲸��������
#define MAX_MOTION_NUM          4       //ÿ��ͨ������ƶ�����������
#define MAX_OSD_STR_LEN         64      //OSD�ַ�������
#define MAX_NTP_SETVER_STR_LEN  32      //NTP��������ַ����
#define MAX_BACKUP_ITEM			16		//��󱸷ݶ���

//add by zw
#define MAX_LED_NUM             4      //����LED����
#define MAX_URL_LEN			    128     //������URL��󳤶�

//ceshi

//�������
#define MAX_ROI_REG       		4  //����Ȥ�������������

#define MAX_DAY_NUM	            32	//��������ʹ��


#define MAX_VDA_SENSITIVE_LEVEL 9
#define MAX_STREAM_NUM    		3    	/* �������·��, 0:��������1:������ */
#define MAX_STOR_FRAGMENT_LEN	16		// sizeof(stor_fragment_t)+6��int�ı�����С

#define MAX_NAL_DESC_SIZE       (0)//��Ƶ֡����ǰ�β��ֳ���

#define MAX_DEV_ID_LEN          32      //����豸ID����
#define MAX_WIFI_AP_NUM			16		//���WIFI-AP����
#define MAX_IF_NAME_LEN         8       //����ӿ�������󳤶�

#define NTP_SERVER_NUM          2
#define NTP_SERVER_LEN          64

#define MAX_AP_NUM              30
/*------------------------------------------------*/
#define MAX_MSG_SIZE        (64*1024)
#define CHANN_TYPE_ALL      0xFA
#define PARAM_MASK_ALL		0xFFFF		// �ָ���������



#define BAIDU_INFO_GET_PATH "/config/param/device_info" //��ȡ�ٶ���Ϣ�ɹ����������

//���������ڻظ�����������Ҳ����ɾ��
#define DEVICE_CFG_PATH 	"/config/param/DEVICE_INFO" //
#define MAC_CFG_PATH 		"/config/param/MAC_INFO" //��ȡ�ٶ���Ϣ�ɹ����������
#define UID_CFG_PATH 		"/config/param/UID_INFO" //��ȡ�ٶ���Ϣ�ɹ����������



#define ROOT_DIR            "/apps/ausdom/pic/"         //ץͼĿ¼
#define WARNING_DIR         "/apps/ausdom/Warning_PIC/" //����Ŀ¼


#define WIFI_CONFIG_INI "/config/wireless_info.conf"


//#define  MAX_VIDEO_STREAM_NUM 2 
#define  MAX_VIDEO_STREAM_NUM 1 

#define  MAX_AUDIO_STREAM_NUM 1




/*----------- �����붨�� -----------*/

typedef enum _SDK_ERR_CODE 
{
    SDK_ERR_SUCCESS = 0x00         //�ɹ�
    , SDK_ERR_FAILURE               //ʧ��
    , SDK_ERR_PASS                  //�������
    , SDK_ERR_USER_NOT_EXIST		//�û���������
    , SDK_ERR_ROOT_USER				//root�û�����ɾ��
    , SDK_ERR_TOO_MANY_USER			//�û�����(�������16���û���)
    , SDK_ERR_USER_ALREADY_EXIST	//�û����Ѵ���
    , SDK_ERR_NET_CFG				//�����������ʧ��
    , SDK_ERR_PERMIT                //Ȩ�޴���
    , SDK_ERR_CHANN                 // 10 ͨ���Ŵ���
    , SDK_ERR_CONN_MAX              //�������������
    , SDK_ERR_CONN                  //���Ӵ���
    , SDK_ERR_SEND                  //���ݷ��ʹ���
    , SDK_ERR_RECV                  //���ݽ��մ���
    , SDK_ERR_BUSY                  //�豸��æ
    , SDK_ERR_DATA                  //���ݸ�ʽ����
    , SDK_ERR_CMD                   //�����ִ���
    , SDK_ERR_VER                   //Э��汾����
    , SDK_ERR_NO_DISK               //�޴���
    , SDK_ERR_DISK_ERR              // 20 ���̴���
    , SDK_ERR_RESOURCE              //��Դ������
    , SDK_ERR_FLASH                 //FLASH��д����
    , SDK_ERR_SET_SYSTIME			//����ϵͳʱ�����
    , SDK_ERR_SET_ENCODE_PARAM		//���ñ����������
    , SDK_ERR_SET_MD_PARAM			//�����ƶ�����������
    , SDK_ERR_SET_OSD_PARAM			//����OSD��������
    , SDK_ERR_SET_OVERLAY_PARAM		//�����ڵ������������
    , SDK_ERR_SET_TV_PARAM			//���ñ߾��С����
    , SDK_ERR_SET_IMAGE_ATTR		//����ͼ�����Դ���
    , SDK_ERR_SET_3A_ATTR			//����3A���Դ���
    , SDK_ERR_LOG_QUERY				//��ѯ��־ʧ��
    , SDK_ERR_LOG_EMPTY				//�����־ʧ��
    , SDK_ERR_LOG_BACKUP			//������־ʧ��
    , SDK_ERR_SERIAL_NO				//���ںŴ���
    , SDK_ERR_SERIAL_OPEN			//�򿪴���ʧ��
    , SDK_ERR_SERIAL_PARAM_SET		//���ô��ڲ���ʧ��
    , SDK_ERR_DISK_MOUNT			//���̹���ʧ��
    , SDK_ERR_UMOUNT				//����ж��ʧ��
    , SDK_ERR_BACKUP				//����ʧ��
    , SDK_ERR_LOG_DEL				//ɾ����־ʧ��

    , SDK_ERR_GET_DISK_PART_INOF	//��ȡ���̷�����Ϣ����
    , SDK_ERR_UPGRADING				//����������
    , SDK_ERR_UPGRADE_CHECK_HEAD	//У��������ͷ����
    , SDK_ERR_UPGRADE_FILE_FIND		// ���Ҳ��������ļ�
    , SDK_ERR_UPGRADE				// ����ʧ��

    , SDK_ERR_NVR_NOT_LOGIN				// ǰ���豸��û��½�ɹ�

}
SDK_ERR_CODE_E;


//cgi ��Ϣ����ӿ�
typedef enum _SDK_MSG_DIR
{
    SDK_MSG_RESP= 0x00,
    SDK_MSG_REQ = 0x01
} SDK_MSG_DIR_E;

/*----------- �������� -----------*/

typedef enum _SDK_PARAM_DIR
{
    SDK_PARAM_SET	= 0x01,	    //���ò���
    SDK_PARAM_GET        		//��ѯ����
} SDK_PARAM_DIR_E;

//���ڲ����ֶ���ʱ��ʹ�� ����ȥ������
#if 0
typedef struct sdk_msg_s
{
    uint16_t magic;         //��������չ(���豸����)
    uint16_t version;       //�汾��
#if 1
    union
    {
        struct
        {
            uint8_t src;    //Դģ��ID
            uint8_t dst;    //Ŀ��ģ��ID
        } __attribute__((packed)) id;
        uint16_t session_id;//�û��ỰID(�豸�˷���)
    } __attribute__((packed));
    uint16_t sequence_id;   //�������
#endif
#if 1
    uint16_t msg_id;        //����ID
    uint8_t  f_dir:1;       //��SDK_PARAM_DIR_E)
    uint8_t  f_pkg:1;       //1:extend�ֶ������ְ�;
    uint8_t  f_res:6;       //����
    uint8_t  ack;           //������
#endif
    uint32_t args;          //�������(���á���ȡ����;����������������[�û��������������̹���])
    uint32_t extend;        //��չ�ֶ�(8:pkg_total,8:pkg_num, 8:, 8:)
    uint32_t chann;         //ͨ����(CHANN_TYPE_ALL)
    uint32_t size;          //��Ϣ����
    uint8_t  data[0];       //��Ϣ��
} sdk_msg_t;
#else
//һ��24���ֽ�
typedef struct sdk_msg_s
{
    uint16_t magic;         //��������չ(���豸����) ����Ϊ������Ϣ��ģ��ʶ����
    uint16_t version;       //�汾��
#if 1
    uint16_t msg_id;        //����ID
    uint8_t  msg_dir;       //��SDK_PARAM_DIR_E)
    uint8_t  ack;           //������
#endif
    uint32_t args;          //SDK_PARAM_DIR_E  �������(���á���ȡ����;����������������[�û��������������̹���])
    uint32_t extend;        //��չ�ֶ�(8:pkg_total,8:pkg_num, 8:, 8:)
    uint32_t chann;         //ͨ����(CHANN_TYPE_ALL)
    uint32_t size;          //��Ϣ����
    uint8_t  data[0];       //��Ϣ��
} __attribute__ ((packed))sdk_msg_t;
#endif

/*
*��������
*
*/
typedef enum _PROC_TYPE
{
    PROC_TYPE_CMS =0,
    PROC_TYPE_GUI,
    PROC_TYPE_MAIN,
    PROC_TYPE_WEB
} PROC_TYPE_E;

/*
 *
 * ����������Ϣ
 */
typedef struct sdk_keeplive_s
{
    char process_name[64];
    long keep_count;   //������� ������ Ĭ����60��  ֮��û���յ�������Ϣ  ϵͳ����
    int  process_type; //PROC_TYPE_E
    int  kill_server;
} sdk_keeplive_t;

/*
 *
 * ֹͣ���ط���  ĿǰҲδ����Ϥ ���� ��ʱ��ô����
 */
typedef struct sdk_stop_server_s
{
    char process_name[64]; // ���÷��Ľ�������
    char passwd[32]; 	// ���Ʒ� ����п�������  ������Ϊ�ǷǷ�ָ��
    long server_type;   //Ҫֹͣ��Щ����  ÿһλ����һ������  ���ҹ滮��ֹͣ����
} sdk_stop_server_t;

/*
 *
 * ϵͳ�汾��Ϣ
 */

typedef struct sdk_version_s
{
    uint8_t serial_no[MAX_SERIAL_NO_LEN];       /* ��Ʒ���к� */
    uint8_t device_type[MAX_VER_STR_LEN];       /* ��Ʒ�ͺ� */
    uint8_t software_ver[MAX_VER_STR_LEN];	    /* �汾�� */
    uint8_t software_date[MAX_VER_STR_LEN];	    /* �汾���� */
    uint8_t panel_ver[MAX_VER_STR_LEN];         //ǰ���汾
    uint8_t hardware_ver[MAX_VER_STR_LEN];      //Ӳ���汾
} sdk_version_t;

/*
 *
 * ��ȡ�豸������Ϣ  �ò�����ֻ���� ������������ ϵͳ������Ϣ����
 */
typedef struct sdk_device_s
{
    uint8_t			usr_no[MAX_USR_ID_LEN];			//�û�ID			//new add
    uint8_t			serial_no[MAX_SERIAL_NO_LEN];	//�豸���к� //��֧�ְٶ�  TUTK
    uint8_t 		device_type[MAX_VER_STR_LEN];       /* ��Ʒ�ͺ� */
    uint8_t			manufacturer[MAX_SERIAL_NO_LEN];	//������
    uint32_t		serverMask;			//��Ʒ֧�ֵĹ���
    char 			reserv[4]; 			//����
} sdk_device_t ;

typedef struct sdk_cloud_uid_s
{
    uint8_t			uid_1[MAX_USR_ID_LEN];		//�û�UID ������ʱ���ֶ����úõ�
    uint8_t			uid_2[MAX_SERIAL_NO_LEN];	//����
    char 			reserv[4]; 			        //����
} sdk_cloud_uid_t ;

//#define MAX_NAME_LEN          32      //���볤��

typedef struct sdk_register_cfg_s
{
    uint8_t	 usr_no[MAX_USR_ID_LEN];					//�û�ID
    uint8_t	 access_token[MAX_ACCESS_TOKEN_LEN];		//�ֻ����ṩ����Ϣ
    uint8_t	 stream_id[MAX_ACCESS_TOKEN_LEN];			//�ֻ����ṩ����Ϣ

    uint8_t ssid[MAX_DEV_ID_LEN];		//ssid
    uint8_t pwd[MAX_PASSWD_LEN];		//����
//	uint8_t name[MAX_NAME_LEN];		//device_name

    uint32_t encrypt_type;				//��������0:NONE  1:WPA  2:WPA2 3:WEP
    uint32_t auth_mode;			//��֤��ʽ0:NONE  1:EAP 2:PSK 3:OPEN 4:SHARED
    uint32_t secret_key_type;		//��Կ����ʽ 0:NONE  1:AES 2:TKIP ֻ��Ӧ�ڼ�������ΪWPA/WPA2�����
} sdk_register_cfg_t;



/*
 *
 * ϵͳ���ò��� �������Ӧ������д��֮�� ֻ����
 * �ṩ�豸һ�п�����Ϣ
 */
typedef struct sdk_sys_cfg_s
{

    /*---------- ������Ϣ���ɸ��� ----------*/
    uint8_t serial_1[MAX_SERIAL_NO_LEN];       //���к�  �ٶ�ʹ��
    uint8_t serial_2[MAX_SERIAL_NO_LEN];       //���к� tutk ʹ��
    uint8_t manufacturer[MAX_MANU_STR_LEN];    //������
    uint8_t device_type[MAX_MANU_STR_LEN];       //�豸�ͺ�//֮ǰ��32  �޸�64
    uint8_t software_ver[MAX_VER_STR_LEN];      //����汾��
    uint8_t software_date[MAX_VER_STR_LEN];     //�����������
    uint8_t hardware_ver[MAX_VER_STR_LEN];      //Ӳ���汾

    uint32_t dev_type;                          //�豸����SDK_DEV_TYPE_E   ��Ҫ���¶���
    uint32_t server_mask;						// ÿһλ�����豸֧�ֵķ�����  ���� �ٶ�  tutk  onvif
    uint32_t io_mask;						  // ÿһλ�����豸����  ��Ҫ���¶��� 0:mic 1:speak 2:wifi 3:I/O����������� 4:SD��¼�� 5:��̨)

    uint8_t  max_stream;                         //��Ƶ����Ŀ
    uint8_t  max_resolution;                    //������ֱ���
    uint8_t  res[2];                    //������ֱ���

} sdk_sys_cfg_t;


/*
 * �豸������
 */

typedef enum SDK_VIDEO_CAP_RESOLUTION
{
    SDK_VIDEO_CAP_RESOLUTION_QCIF   = 0x1,				//176*144  n��176*120
    SDK_VIDEO_CAP_RESOLUTION_CIF    = 0x2,				//352*288  n��352*240
    SDK_VIDEO_CAP_RESOLUTION_HD1    = 0x4,				//704*288  n��704*240
    SDK_VIDEO_CAP_RESOLUTION_D1     = 0x8,				//704*576  n��704*480
    SDK_VIDEO_CAP_RESOLUTION_960H   = 0x10,				//960x576
    SDK_VIDEO_CAP_RESOLUTION_QQVGA  = 0x20,				//160*112
    SDK_VIDEO_CAP_RESOLUTION_QVGA   = 0x40,				//320*240
    SDK_VIDEO_CAP_RESOLUTION_VGA    = 0x80,				//640*480
    SDK_VIDEO_CAP_RESOLUTION_SVGA   = 0x100,			//800*600
    SDK_VIDEO_CAP_RESOLUTION_UXGA   = 0x200,			//1600*1200
    SDK_VIDEO_CAP_RESOLUTION_720P   = 0x400,			//1280*720
    SDK_VIDEO_CAP_RESOLUTION_960    = 0x800,			//1280*960
    SDK_VIDEO_CAP_RESOLUTION_1080P	= 0x1000			//1920*1080
} SDK_VIDEO_CAP_RESOLUTION_E;

typedef struct device_chan_capability_s
{
    uint32_t   res_cap[MAX_STREAM_NUM];			// SDK_VIDEO_CAP_RESOLUTION_E
    uint32_t   max_frame_rate[MAX_STREAM_NUM]; 	// �������֧��֡��
} device_chan_capability_t;

typedef struct sdk_device_capability_s
{
    uint8_t    screen_num;                     			// ��Ļ������3531������3521һ����
    uint8_t    eth_num;                        			// ���ڸ������豸����Ϊxx_e2ʱ����������һ����
    uint8_t    res[2];                         			// ����
    device_chan_capability_t ch_cap[MAX_CHANN_NUM];
} sdk_device_capability_t;


/*
 * �ָ�Ĭ�ϲ���
 */

typedef enum _SDK_PARAM_MASK_ID
{
    SDK_PARAM_MASK_ENCODE = 0x00,    	//bit.0: �������
    SDK_PARAM_MASK_PTZ          ,     	//bit.1: PTZ��̨����
    SDK_PARAM_MASK_RECORD       , 		//bit.2: ¼�����
    SDK_PARAM_MASK_NET          ,      	//bit.3: �������
    SDK_PARAM_MASK_CHANNEL      ,  		//bit.4: ͨ������
    SDK_PARAM_MASK_IMAGE_ATTR   ,		//bit.5: ��Ƶ����
    SDK_PARAM_MASK_SERIAL	    ,		//bit.6: ���ڲ���
    SDK_PARAM_MASK_OVERLAY      ,		//bit.7: �ڵ��������
    SDK_PARAM_MASK_MOTION	    ,		//bit.8: �ƶ����
    SDK_PARAM_MASK_COMM         ,		//bit.9: �������
    SDK_PARAM_MASK_OSD          ,		//bit.10: osd����
    SDK_PARAM_MASK_USER         ,		//bit.11: �û�����
    SDK_PARAM_MASK_ALARM_IN     ,		//bit.12: �ⲿ�����������
    SDK_PARAM_MASK_HIDE         ,		//bit.13: ��Ƶ�ڵ�������
    SDK_PARAM_MASK_VIDEO_LOST   ,		//bit.14: ��Ƶ��ʧ����
    SDK_PARAM_MASK_TV           ,		//bit.15: �߾���ڲ���
    SDK_PARAM_MASK_PREVIEW      ,   	//bit.16: Ԥ������
    SDK_PARAM_MASK_TOUR         ,       //bit.17: Ѳ�ز���

    SDK_PARAM_MASK_BUIT
} SDK_PARAM_MASK_ID_E;


typedef struct sdk_default_param
{

    uint32_t param_mask;    //������������ SDK_PARAM_MASK_ID_E
    uint32_t res[1];
} sdk_default_param_t;


/*
 * ϵͳ����״̬��Ϣ
 */
typedef enum _SDK_STATUS_OP
{
    SDK_STATUS_DEVICE = 0x01,  //�豸����״̬
    SDK_STATUS_DISK,           //����״̬
    SDK_STATUS_CHANN,          //ͨ��״̬
    SDK_STATUS_ALARM_IN,       //���뱨��״̬
    SDK_STATUS_ALARM_OUT       //�������״̬
} SDK_STATUS_OP_E;

typedef struct sdk_chan_status_s
{

    uint8_t chan_type;          //ͨ������ 0�����أ�1��IP
    uint8_t record_state;       //¼��״̬,0-��¼��,1-¼��
    uint8_t signal_state;       //�ź�״̬, 0:������1���źŶ�ʧ
    uint8_t encode_state;       //����״̬, 0:�����룬1������

    uint32_t bit_rate;          //ʵ������
    uint32_t conn_num;          //ͨ��������
    uint8_t  conn_ip[MAX_CHANN_CONN_NUM][MAX_IP_ADDR_LEN];//����IP
} sdk_chan_status_t;


typedef struct sdk_disk_status_s
{
    uint32_t volume;        //Ӳ�̵�����
    uint32_t free_space;    //Ӳ�̵�ʣ��ռ�
    uint32_t disk_state;   //Ӳ�̵�״̬,0-�,1-����,2-������
} sdk_disk_status_t;

/*
 * ϵͳ״̬(������ֳ� SDK_STATUS_OP_E)
 */

typedef struct sdk_status_s
{

    uint32_t            device_status;                      //�豸״̬��0-����,1-CPUռ����̫��,����85%,2-Ӳ������
    sdk_disk_status_t   disk_status[MAX_DISK_NUM];          //Ӳ��״̬
    sdk_chan_status_t   chan_status[MAX_CHANN_NUM];         //ͨ��״̬
    uint8_t             alarm_in_status[MAX_ALARM_IN_NUM];  //�����˿ڵ�״̬,0-û�б���,1-�б���
    uint8_t             alarm_out_status[MAX_ALARM_OUT_NUM];//��������˿ڵ�״̬,0-û�����,1-�б������

    uint8_t             local_display;                      //������ʾ״̬, 0:������1��������
    uint8_t             audio_chan_status;                  //����ͨ����״̬ 0-δʹ�ã�1-ʹ����, 0xff��Ч
    uint8_t             res[2];

} sdk_status_t;

/*
 * �ر�ϵͳ
 */
typedef enum _SDK_CLOSE_SYS_OP
{
    SDK_CLOSE_SYS_SHUTDOWN = 0x001,		//�ػ�
    SDK_CLOSE_SYS_REBOOT,			    //����
    SDK_COLSE_SYS_LOGOUT,
    SDK_CLOSE_SYS_BUTT
} SDK_CLOSE_SYS_OP_E;

/*
 * �û�����(�û���������)
 */
typedef struct sdk_user_s
{
    uint8_t user_name[MAX_USER_NAME_LEN];
    uint8_t user_pwd[MAX_PASSWD_LEN];
} sdk_user_t;


/*
 * �û�Ȩ�޶���
 */
typedef struct sdk_user_right_s
{

    sdk_user_t user;
    uint32_t local_right;           //����GUIȨ��
    /*bit.0: ���ؿ�����̨*/
    /*bit.1: �����ֶ�¼��*/
    /*bit.2: ���ػط�*/
    /*bit.3: �������ò���*/
    /*bit.4: ���ز鿴״̬����־*/
    /*bit.5: ���ظ߼�����(��������ʽ�����������ػ�)*/
    /*bit.6: ���ز鿴���� */
    /*bit.7: ���ع���ģ���IP camera */
    /*bit.8: ���ر��� */
    /*bit.9: ���عػ�/���� */

    uint32_t remote_right;          //Զ��Ȩ��
    /*bit.0: Զ�̿�����̨*/
    /*bit.1: Զ���ֶ�¼��*/
    /*bit.2: Զ�̻ط� */
    /*bit.3: Զ�����ò���*/
    /*bit.4: Զ�̲鿴״̬����־*/
    /*bit.5: Զ�̸߼�����(��������ʽ�����������ػ�)*/
    /*bit.6: Զ�̷��������Խ�*/
    /*bit.7: Զ��Ԥ��*/
    /*bit.8: Զ�����󱨾��ϴ����������*/
    /*bit.9: Զ�̿��ƣ��������*/
    /*bit.10: Զ�̿��ƴ���*/
    /*bit.11: Զ�̲鿴���� */
    /*bit.12: Զ�̹���ģ���IP camera */
    /*bit.13: Զ�̹ػ�/���� */

    uint8_t local_backup_right[MAX_CHANN_NUM];     //ͨ��Ȩ��
    uint8_t net_preview_right[MAX_CHANN_NUM];

} sdk_user_right_t;

/*-----------------�ٶ�������Ϣ----------------------------*/
typedef struct sdk_baidu_info_s
{
    // ϵͳ����
    uint8_t user_id[MAX_USR_ID_LEN];             //�ٶȷ����� �ṩ���û�ID  ���ݸ�ID  ��ȡaccess_token
    uint8_t access_token[MAX_ACCESS_TOKEN_LEN];  //�����ȡ��access_token
    //uint8_t device_name[MAX_ACCESS_TOKEN_LEN];  //�û����ٶ���������
    //uint64_t token_live ;  //access_token  ����������

    uint8_t image_quality ;			 //ͼ������ 0 -4 ��: ���壬��������ͨ��һ�㣬����   Ĭ��2
    uint8_t rec_status ;   			 // ¼��״̬  ���Ҳֻ�ܿ��� �ٶ��Ƶ�¼�����
    uint8_t video_enable ;   	     //  ��Ƶ����״̬  0  ��������Ƶ  1 ������Ƶ  Ĭ�Ͽ���
    uint8_t audio_enable ;   	    // ��������״̬  0  �ر����� 1 ��������		 Ĭ�Ϲر�

    uint8_t res[12];
} sdk_baidu_info_t;


/*-----------����ģ��-----------------------*/
/*
 * ����������������
 */
typedef enum _SDK_NET_IDX
{
	SDK_NET_IDX_ETH0    = 0x00, //eth0   sdk_eth_cfg_t
    SDK_NET_IDX_ETH1    = 0x01, //eth1   sdk_eth_cfg_t
    SDK_NET_IDX_PPPOE0  = 0x02, //pppoe  sdk_pppoe_t
    SDK_NET_IDX_WIFI0  	= 0x03, //wifi   sdk_wifi_cfg_t
    SDK_NET_IDX_3G0		= 0x04, //3g     sdk_3g_cfg_t
    SDK_NET_IDX_PPPOE1  = 0x05,
    SDK_NET_IDX_WIFI1   = 0x06,
    SDK_NET_IDX_3G1     = 0x07,
    SDK_NET_IDX_BUTT    = 0x08
} SDK_NET_IDX_E;


//�����ʾ����״̬
typedef enum _SDK_NET_MODE
{
	SDK_NET_MODE_AP      	= 0x00, //ap    ��smartconfig����Ҳ���Ա�ʾΪ��Ҫ�ȴ����ܹ㲥���������ӵ�AP
	SDK_NET_MODE_ETH		= 0x01, //eth1
	SDK_NET_MODE_WIFI    	= 0x02, //WIFI ��smartconfig�����ʾΪ�Ѿ�������SSID pwd ����ȴ��㲥����
	SDK_NET_MODE_PPPOE1   	= 0x03,
	SDK_NET_MODE_3G  		= 0x04,//wifi
	SDK_NET_MODE_BUTT     	= 0x05
} SDK_NET_MODE_E;

/*
 * �������ã��ӽṹ�壩
 */
typedef struct sdk_ip_info_s
{
    uint8_t if_name[MAX_IF_NAME_LEN];//�ӿ�����(����)
    uint8_t ip_addr[MAX_IP_ADDR_LEN];//IP ADDR
    uint8_t mask[MAX_IP_ADDR_LEN];   //IP MASK
    uint8_t gateway[MAX_IP_ADDR_LEN];//����
    uint8_t mac[MAX_MAC_ADDR_LEN];   //MAC STRING
    uint8_t dns1[MAX_IP_ADDR_LEN];   //DNS1
    uint8_t dns2[MAX_IP_ADDR_LEN];   //DNS2
    uint8_t enable_dhcp;             //�Ƿ���DHCP
    uint8_t dns_auto_en;             //�Զ���ȡDNS(������DHCPʱ���Զ���ȡDNS)
    uint8_t res[2];
} sdk_ip_info_t;

/*
 * ������������
 */
typedef struct sdk_eth_cfg_s
{
    sdk_ip_info_t ip_info; //IP��Ϣ����

    uint8_t if_mode;       //SDK_NET_MODE_E
    uint8_t wifi_type;     //ָ��wifi ������
   // uint8_t is_setting;  
    uint8_t res[2];

} sdk_eth_cfg_t;

#define MAX_IP_LEN          20     //IP��ַ����
#define NET_CARD_NAME_LEN   8      //IP��ַ����

typedef struct _net_manager_info_s
{
    uint8_t enable;			    //���ƹ����߳����е�
    uint8_t current_mode;		//SDK_NET_MODE_E ��ǰ�����ģʽ ���� , AP , sta , �������Ƶ�ǰ��WIFIģʽ
    uint8_t connect_status;		//   0  ��ʾû���κ�����   1 ��ʾ������ ,
    uint8_t config_change;		//  0 û�иı�����    1 �ı�����
    uint8_t enable_dhcp;        //�Ƿ���DHCP
    uint8_t wifi_type;			//wifi ������
    uint8_t res[2]   ;
    uint8_t ssid[MAX_DEV_ID_LEN] ; //ssid ��Ϣ
    uint8_t passwd[MAX_PASSWD_LEN] ; //ssid ��Ϣ

    //�洢��ǰ ip ��Ϣ
    uint8_t if_name[NET_CARD_NAME_LEN];// ��������  "eth0" "ra0" "wlan0"
    uint8_t ip_addr[MAX_IP_LEN];//IP ADDR
    uint8_t mask[MAX_IP_LEN];   //IP MASK
    uint8_t gateway[MAX_IP_LEN];//����
    uint8_t mac[MAX_IP_LEN];   //MAC STRING
    uint8_t dns1[MAX_IP_LEN];   //DNS1
    uint8_t dns2[MAX_IP_LEN];   //DNS2
    pthread_mutex_t manager_mutex;

} net_manager_info_t;


/*
 * wifi ����
 */
typedef struct sdk_wifi_cfg_s
{

    //sdk_ip_info_t ip_info;

    uint8_t ssid[MAX_DEV_ID_LEN];		//���������
    uint8_t pwd[MAX_PASSWD_LEN];		//����
    uint32_t enable;				    //0����ֹ��1��wifi client 2: wifi ap
    uint32_t encrypt_type;				//��������0:NONE  1:WPA  2:WPA2 3:WEP
    uint32_t auth_mode;					//��֤��ʽ0:NONE  1:EAP 2:PSK 3:OPEN 4:SHARED
    uint32_t secret_key_type;			//��Կ����ʽ 0:NONE  1:AES 2:TKIP ֻ��Ӧ�ڼ�������ΪWPA/WPA2�����
	uint8_t secrity[32];
    uint32_t stat;					    //������������״̬ 0 ������ 1 ��������2 �ɹ�
} sdk_wifi_cfg_t;


/*
* ����
*/

//wifi��Ϣ
typedef struct _wifi_ap_info_s
{
    uint8_t ssid[MAX_DEV_ID_LEN];    /*ssid */

    uint8_t encrypt_type;				//��������0:NONE  1:WPA  2:WPA2 3:WEP
    uint8_t auth_mode;					//��֤��ʽ0:NONE  1:EAP 2:PSK 3:OPEN 4:SHARED
    uint8_t secret_key_type;			//��Կ����ʽ 0:NONE  1:AES 2:TKIP ֻ��Ӧ�ڼ�������ΪWPA/WPA2�����

    uint8_t signal;   					// signal intensity 0--100%

    uint8_t res[4];

} wifi_ap_info_t;

#if 0
typedef struct _wifi_ap_info_s
{
    uint8_t ssid[MAX_DEV_ID_LEN];    /*ssid */

	uint8_t channel;
	uint8_t authmode;        /*0-OPEN, 1-SHARED, 2-WPAPSK/WPA2PSK*/
	uint8_t encryption;      /*0-NONE, 1-WEP, 2-TKIP/AES*/
    uint8_t signal;   					// signal intensity 0--100%
    uint8_t res[4];

} wifi_ap_info_t;
#endif


typedef struct sdk_wifi_search_s
{

    int   ap_count;  //�ȵ���Ŀ
    wifi_ap_info_t  ap_info[MAX_AP_NUM];
} sdk_wifi_search_t;



/*
 * pppoe����
 */
typedef struct sdk_pppoe_s
{
    sdk_ip_info_t ip_info;              //PPPOE ��ȡ����IP��ַ

    uint8_t user[MAX_USER_NAME_LEN];    //PPPOE �û���
    uint8_t pass[MAX_PASSWD_LEN];       //PPPOE ����
    uint8_t enable;                    	//�Ƿ���PPPOE
    uint8_t if_no;                      //����ӿ�
    uint8_t res[2];                     //����

} sdk_pppoe_t;



/*
 * 3g ����
 */
typedef struct sdk_3g_cfg_s
{

    sdk_ip_info_t   ip_info;            //3g PPP ��ȡ����IP��ַ

    uint32_t enable;
    uint32_t mod_id;
    uint32_t stat;
    uint8_t  res[64];
} sdk_3g_cfg_t;



typedef struct network_info
{
	unsigned char ucNetworkinit; // 0: not-init, 1: has inited
	unsigned char ucNetworkType; // 0: ethernet, 1: wireless
	unsigned char ucNetworkState; // 0: no network, 1: network connected, 2: get ip
	unsigned char ucNeedreconfig; // 0: no need to re-config, 1: need to re-config network(change network)
}sdk_Network_Info;



typedef struct ApInfo
{
    unsigned char channel;
    unsigned char ssid[33];
    unsigned char mac[18];
    unsigned char secrity[23];
	struct ApInfo *next;
}Ap_Info;

typedef struct tag_wifi_config
{
	int status;
	int channel;	
	char ssid[33];
	char pwd[32];
	char bssid[20];	
	char secrity[23];	
}WiFi_Item_Config;



/*
 * �����������
 */
typedef struct sdk_net_mng_cfg_s
{

    uint8_t        def_if_no;                     //Ĭ������ӿ�(���豸�ж����������ʱ����ʹ��ָ��������)
    uint8_t        res[3];

    uint8_t        multicast[MAX_IP_ADDR_LEN];    //�鲥��ַ
    uint8_t        net_manager[MAX_IP_ADDR_LEN];  //���������IP()

    uint16_t       net_manager_port;              //���������PORT
    uint16_t       http_port;                     //DVR HTTP PORT
    uint16_t       dvr_cmd_port;                  //DVR SERVICE PROT
    uint16_t       dvr_data_port;                 //DVR DATA PORT
    uint16_t       dvr_talk_port;                 //DVR TALK PORT
    uint16_t       cloud_port;                    //�Ʒ���˿�
    uint8_t        cloud_addr[128];               //�Ʒ����ַ
    uint8_t        cloud_user[MAX_USER_NAME_LEN]; //�Ʒ����û���
    uint8_t        cloud_pass[MAX_PASSWD_LEN];    //�Ʒ�������
    uint32_t       cloud_interval;                //�Ʒ�����¼��
} sdk_net_mng_cfg_t;



/*
 * ��������
 */

#define 	MAX_DDNS_USER_LEN   	64				// DDNS�û�����󳤶�
#define 	MAX_DDNS_PWD_LEN    	32				// DDNS������󳤶�
#define 	MAX_DDNS_NAME_LEN   	128				// DDNS������󳤶�

typedef enum _SDK_DDNS_TYPE
{
    SDK_DDNS_TYPE_DYNDNS = 0x00,	// Dyndns
    SDK_DDNS_TYPE_3322,				// 3322
    SDK_DDNS_TYPE_ORAY,				// Oray
    SDK_DDNS_TYPE_BUTT
} SDK_DDNS_TYPE_E;

typedef enum _SDK_DDNS_ORAY_USERTYPE
{
    SDK_ORAY_USERTYPE_COMMON = 0x01,	// ��ͨ�û�
    SDK_ORAY_USERTYPE_EXPERT,			// רҵ�û�
    SDK_ORAY_USERTYPE_BUTT
} SDK_DDNS_ORAY_USERTYPE;

typedef struct sdk_ddns_cfg_s
{
    uint8_t enable;						// �Ƿ�����DDNS 0-��,1-��
    uint8_t type;						// DDNS����,SDK_DDNS_TYPE_E
    uint8_t user_type;					// �û�����,SDK_DDNS_ORAY_USERTYPE (���������д�ѡ��)
    uint8_t res[1];					    // ����
    uint32_t interval;					// ��������(��λ:��)
    uint32_t port;						// DDNS�˿�
    uint8_t server[MAX_DDNS_NAME_LEN];	// DDNSЭ���Ӧ�ķ�������ַ(IP����������)
    uint8_t user[MAX_DDNS_USER_LEN];	// �û���
    uint8_t pwd[MAX_DDNS_PWD_LEN];		// ����
    uint8_t domain[MAX_DDNS_NAME_LEN];	// �û������������ַ(Ŀǰ 3322, dyndns �ô˲���,���domainʹ��','����)
    /*----------------------------------*/
    uint8_t client_ip[MAX_IP_ADDR_LEN];	// �豸��IP
    uint8_t domain_num;					// ���������������ĸ���
    uint8_t res1[3];                    // ����
    uint8_t dn[16][MAX_DDNS_NAME_LEN]; 	// ���������ص�����
} sdk_ddns_cfg_t;

/*
 * ƽ̨��Ϣ �ӽṹ��
 *
 */

typedef struct sdk_screen_slot_s
{
    uint32_t magic;				/* 0x55aa55aa */
    uint32_t index[MAX_SCREEN_NUM];
} sdk_screen_slot_t;

/*
 * ƽ̨��Ϣ
 *
 */

typedef struct sdk_platform_s
{
    uint8_t pu_id[MAX_USER_NAME_LEN];
    uint8_t cms_ip[MAX_IP_ADDR_LEN];            //ƽ̨mds ip
    uint8_t mds_ip[MAX_IP_ADDR_LEN];            //ƽ̨mds ip
    uint32_t cms_port;                          //ƽ̨cms�˿ں�
    uint32_t mds_port;                          //ƽ̨mds�˿ں�
    uint32_t protocol;                          //0:tcp   1:udp
    uint32_t plat_enable;                       //ƽ̨����

    sdk_screen_slot_t slot;						//����������
} sdk_platform_t;


/*--------------------�����ṹ��Ԫ------------------------*/
/*
 * ʱ��ṹ�嶨��
 */
typedef struct sdk_time_s
{
    uint32_t year;
    uint32_t mon;
    uint32_t day;
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
} sdk_time_t;

/*
 * ��ϸʱ��ṹ�嶨��
 */
typedef struct sdk_date_s
{
    sdk_time_t _time;
    uint8_t     wday;
    uint8_t     tzone;
	uint8_t     ntp_or_manual;
    uint8_t     res[2-1];
} sdk_date_t;



/*
 * ����ṹ�嶨��
 */
typedef struct sdk_rect_s
{
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
} sdk_rect_t;

/*
 * ��ṹ�嶨��
 */
typedef struct sdk_point_s
{
    uint16_t x;
    uint16_t y;
} sdk_point_t;



/*----------- ����Ƶ���Ͷ��� ��Ƶ����֡ͷ��Ϣ�õ�-----------*/

typedef enum _SDK_AUDIO_SAMPLE_RATE
{
    SDK_AUDIO_SAMPLE_R8K        = 0,   /* 8K Sample rate     */
    SDK_AUDIO_SAMPLE_R11_025K   = 1,   /* 11.025K Sample rate*/
    SDK_AUDIO_SAMPLE_R16K       = 2,   /* 16K Sample rate    */
    SDK_AUDIO_SAMPLE_R22050     = 3,   /* 22.050K Sample rate*/
    SDK_AUDIO_SAMPLE_R24K       = 4,   /* 24K Sample rate    */
    SDK_AUDIO_SAMPLE_R32K       = 5,   /* 32K Sample rate    */
    SDK_AUDIO_SAMPLE_R44_1K     = 6,   /* 44.1K Sample rate  */
    SDK_AUDIO_SAMPLE_R48K       = 7,   /* 48K Sample rate    */
    SDK_AUDIO_SAMPLE_BUTT,
} SDK_AUDIO_SAMPLE_RATE_E;

typedef enum _SDK_AUDIO_CODEC_FORMAT
{
    SDK_AUDIO_FORMAT_NULL	        = 0,   /*                    */
    SDK_AUDIO_FORMAT_G711A	        = 1,   /* G.711 A            */
    SDK_AUDIO_FORMAT_G711Mu	        = 2,   /* G.711 Mu           */
    SDK_AUDIO_FORMAT_ADPCM	        = 3,   /* ADPCM              */
    SDK_AUDIO_FORMAT_G726_16        = 4,   /* G.726              */
    SDK_AUDIO_FORMAT_G726_24        = 5,   /* G.726              */
    SDK_AUDIO_FORMAT_G726_32        = 6,   /* G.726              */
    SDK_AUDIO_FORMAT_G726_40        = 7,   /* G.726              */
    SDK_AUDIO_FORMAT_AMR	        = 8,   /* AMR encoder format */
    SDK_AUDIO_FORMAT_AMRDTX	        = 9,   /* AMR encoder formant and VAD1 enable */
    SDK_AUDIO_FORMAT_AAC	        = 10,  /* AAC encoder        */
    SDK_AUDIO_FORMAT_ADPCM_DVI4	    = 11,  /* ADPCM              */
    SDK_AUDIO_FORMAT_ADPCM_IMA	    = 12,  /* ADPCM              */
    SDK_AUDIO_FORMAT_MEDIA_G726_16  = 13,  /* G.726              */
    SDK_AUDIO_FORMAT_MEDIA_G726_24  = 14,  /* G.726              */
    SDK_AUDIO_FORMAT_MEDIA_G726_32  = 15,  /* G.726              */
    SDK_AUDIO_FORMAT_MEDIA_G726_40  = 16,  /* G.726              */
    SDK_AUDIO_FORMAT_BUTT,
} SDK_AUDIO_CODEC_FORMAT_E;

typedef enum _SDK_AUDIO_SAMPLE_WIDTH
{
    SDK_AUDIO_SAMPLE_WIDTH_8  = 1,    /* 8bits */
    SDK_AUDIO_SAMPLE_WIDTH_16 = 2,    /* 16bits */
    SDK_AUDIO_SAMPLE_WIDTH_BUTT,
} SDK_AUDIO_SAMPLE_WIDTH_E;


/*
 * ��Ƶ֡��Ϣ(�ӽṹ��)
 */
typedef struct sdk_a_frame_info_s
{
    uint8_t encode_type;        //�������� 1: G711A SDK_AUDIO_CODEC_FORMAT_E
    uint8_t samples;            //����Ƶ�� 0: 8000, SDK_AUDIO_SAMPLE_RATE_E
    uint8_t bits;               //λ��    SDK_AUDIO_SAMPLE_WIDTH_E
    uint8_t channels;           //ͨ����
    uint8_t res[4];
} sdk_a_frame_info_t;


typedef enum _SDK_VIDEO_FORMAT
{
    SDK_VIDEO_FORMAT_H264    = 0, //H.264
    SDK_VIDEO_FORMAT_MPEG4   = 1, //MPEG4
    SDK_VIDEO_FORMAT_MJPEG   = 2, //MJPEG
} SDK_VIDEO_FORMAT_E;


typedef enum _SDK_VIDEO_STANDARD
{
    SDK_VIDEO_STANDARD_PAL  = 0, // PAL
    SDK_VIDEO_STANDARD_NTSC = 1, //NTSC
} SDK_VIDEO_STANDARD_E;

typedef enum _SDK_VIDEO_RESOLUTION
{
    SDK_VIDEO_RESOLUTION_QCIF    = 0 ,/* 176 * 144 */
    SDK_VIDEO_RESOLUTION_CIF     = 1 ,/* 352 * 288 */
    SDK_VIDEO_RESOLUTION_HD1     = 2 ,/* 704 * 288 */
    SDK_VIDEO_RESOLUTION_D1      = 3 ,/* 704 * 576 */
    SDK_VIDEO_RESOLUTION_960H    = 4 ,/* 960 * 576 */
    SDK_VIDEO_RESOLUTION_QVGA    = 5 ,/* 320 * 240 */
    SDK_VIDEO_RESOLUTION_VGA     = 6 ,/* 640 * 480 */
    SDK_VIDEO_RESOLUTION_XGA     = 7 ,/* 1024 * 768 */
    SDK_VIDEO_RESOLUTION_SXGA    = 8 ,/* 1400 * 1050 */
    SDK_VIDEO_RESOLUTION_UXGA    = 9 ,/* 1600 * 1200 */
    SDK_VIDEO_RESOLUTION_QXGA    = 10,/* 2048 * 1536 */
    SDK_VIDEO_RESOLUTION_WVGA    = 11,/* 854  * 480  */
    SDK_VIDEO_RESOLUTION_WSXGA   = 12,/* 1680 * 1050 */
    SDK_VIDEO_RESOLUTION_WUXGA   = 13,/* 1920 * 1200 */
    SDK_VIDEO_RESOLUTION_WQXGA   = 14,/* 2560 * 1600 */
    SDK_VIDEO_RESOLUTION_720p    = 15,/* 1280 * 720  */
    SDK_VIDEO_RESOLUTION_1080p   = 16,/* 1920 * 1080 */
    SDK_VIDEO_RESOLUTION_960p    = 17,/* 1280 * 960  */
    SDK_VIDEO_RESOLUTION_SVGA    = 18,/* 800  * 600  */
    SDK_VIDEO_RESOLUTION_BUTT      // ----------

} SDK_VIDEO_RESOLUTION_E;

/*
 * ��Ƶ֡��Ϣ(�ӽṹ��)
 */
typedef struct sdk_v_frame_info_s
{
    uint8_t encode_type;        //�������� 0: H.264  1 mjeg
    uint8_t standard;           //��ʽ     0: PAL, 1: NTSC
    uint8_t resolution;         //�ֱ���   ENUM_RESOLUTION_E
    uint8_t frame_rate;         //֡��     1-25/30
    uint16_t width;             //��
    uint16_t height;            //��
} sdk_v_frame_info_t;



typedef enum _SDK_FRAME_TYPE
{
    SDK_VIDEO_FRAME_I = 0x01,   //I֡
    SDK_VIDEO_FRAME_P = 0x02,   //P֡
    SDK_VIDEO_FRAME_B = 0x03,   //B֡
    SDK_AUDIO_FRAME_A = 0x04,   //��Ƶ֡A
} SDK_FRAME_TYPE_E;

/*
 * ����Ƶ֡�ṹ�嶨��
 */
typedef struct sdk_frame_s
{
    uint16_t  magic;            //��������չ
    uint8_t   res[1];           //����
    uint8_t   frame_type;       //֡����, ��Ƶ��I, P, B��, ��Ƶ��A��
    uint32_t  frame_size;       //֡����
    uint32_t  frame_no;         //֡���
    uint32_t  sec;              //֡ʱ�䣨�룩
    uint32_t  usec;             //֡ʱ�䣨΢�룩
    uint64_t  pts;              //֡PTS
    union
    {
        sdk_v_frame_info_t video_info;//��Ƶ֡��Ϣ
        sdk_a_frame_info_t audio_info;//��Ƶ֡��Ϣ
    };
    uint8_t   data[0];          //֡����
} __attribute__ ((packed))sdk_frame_t;

typedef sdk_frame_t frame_t;


#define MAX_NAL_NUM             9              //���NAL����
//#define MAX_NAL_DESC_SIZE       ((4+9*(4+4)))  //��Ƶ֡����ǰ�β��ֳ���

typedef    enum NAL_TYPE_S
{
    NAL_UNSPECIFIED = 0,
    NAL_NON_IDR,
    NAL_IDR=5,
    NAL_SEI,
    NAL_SPS,
    NAL_PPS,
    NAL_AUD
} NAL_TYPE_E;

typedef struct sdk_nal_desc_s
{
    uint32_t nal_num;           /*NAL����*/
    struct nal_d_s
    {
        uint32_t nal_type;       /*NAL���� NAL_TYPE_E*/
        uint32_t nal_off;       /*NAL��ַ,��frame->data��ʼ*/
        uint32_t nal_size;      /*NAL��С*/
    } nal[MAX_NAL_NUM];
    uint8_t rawdata[0];         /* ���������� */
} sdk_nal_desc_t;


/*****************����ģ�����******************************/


/*------------ ����������� ��ȡ------*/
typedef enum _SDK_CODEC_BR_TYPE
{
    SDK_BR_CBR = 0, ///< Constant Bitrate  ������
    SDK_BR_VBR,     ///< Variable Bitrate  ������
    SDK_BR_ECBR,    ///< Enhanced Constant Bitrate
    SDK_BR_EVBR,    ///< Enhanced Variable Bitrate
    SDK_BR_BUTT

} SDK_VIDEO_BR_TYPE_E;
/*
 * ͨ���������(�ӽṹ��)
 */
typedef struct sdk_av_enc_s
{
    uint8_t resolution;     //SDK_VIDEO_RESOLUTION_E
    uint8_t bitrate_type;   //��������  SDK_VIDEO_BR_TYPE_E
    uint8_t pic_quilty;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    uint8_t frame_rate;     //����֡��1-25(PAL)/30
    uint8_t gop;            //I ֡���1-200
    uint8_t video_type;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    uint8_t res;      		//����
    uint8_t mix_type;       //����Ƶ��: 0, ��Ƶ��: 1.
    uint16_t bitrate;       //�������� 32kbps-16000kbps
    uint8_t level;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    uint8_t h264_ref_mod;   //h264����֡�ο�ģʽ
    uint8_t audio_enc;      //���ӱ����ʽ0:G711A  SDK_AUDIO_CODEC_FORMAT_E
    uint8_t audio_sample;      //��Ƶ����  SDK_AUDIO_SAMPLE_RATE_E
    uint8_t is_using;		//��ʾ��ͨ�������Ƿ�����ʹ��[Ϊ1��ʾ��ͨ�����õ�ǰ��Ч]
    uint8_t  res2[1];
} sdk_av_enc_t;
/*
 * �����������(pmsg->extend����)
 */
typedef enum _SDK_ENC_IDX
{
	SDK_ENC_IDX_MAIN  = 0,
	SDK_ENC_IDX_SECOND= 1,
	SDK_ENC_IDX_THREE = 2,
	SDK_ENC_IDX_ALL   = 4
} SDK_ENC_IDX_T;


/*
 * ͨ��������� ��������
 */
typedef struct sdk_encode_s
{
    sdk_av_enc_t av_enc_info[SDK_ENC_IDX_ALL];  //������  SDK_ENC_IDX_T
    uint32_t     au_in_mod;                     //ǰ����Ƶ��������
} sdk_encode_t;


/*----------------- �������ýṹ�嶨�� -----------------*/
/*
 * ʱ��νṹ�嶨��
 */
typedef struct sdk_sched_time_s
{
    uint8_t enable;	    //����, ����ʱ¼��ʱ��ʾ¼������;
    uint8_t res;
    uint8_t start_hour; //��ʼʱ��
    uint8_t start_min;
	uint8_t start_sec;
    uint8_t stop_hour;  //����ʱ��
    uint8_t stop_min;
	uint8_t stop_sec;
} sdk_day_time_t;

/*
*���¶���һ������ʱ�䶨�� ��ǰ�Ĺ��ڷ��� ��ʵ���Ҳ���� 9527-----20140802
*
*/
//���²���
typedef struct mon_sched_s
{
    uint32_t mon_enable;	 //ÿһλ����һ���� һ��12�� ��13λ��1 �Ļ� ˵��ÿ���¶���������  �����ȼ����
    uint32_t date_sched[MAX_DAY_NUM];  //������������һ��  ����ÿһλ����һ��Сʱ ����31������mon_enable ��bit13 Ϊ1��ʱ����Ч
} mon_sched_t;

//���ܲ���
typedef struct week_sched_s
{
    //uint8_t week_enable;	 //ÿһλ����һ������ bit8  == 1 ��ʱ��  ��ʾÿ�춼��������ƻ� �����ȼ����
    sdk_day_time_t week_sched_info[MAX_WEEK_NUM][MAX_TIME_SEG_NUM];//ÿ�춼���������
} week_sched_t;


//���ֲ�����ʽ���ʹ��
typedef struct sdk_sched_time_ex_s
{
    uint8_t enable;	    //  0:�ر�   1:��  ����ʱ���ܿ���
    uint8_t plan_flag;	//  0: ȫʱ����,  1:���ܲ���    2:���²���
    uint8_t interval_time;		//���α���ʱ���� 5~240S
    uint8_t res[1];		//����

    union
    {
        //����ѡ��һ
        mon_sched_t 	mon_sched;  //���²���
        week_sched_t	week_sched; //���ܲ���
    };
} sdk_sched_time_t;



/*----------- �澯���Ͷ��� -----------*/
//�˴����ڻ����ʵ�ʵ�������� ����
typedef enum _SDK_EVENT_TYPE
{
    SDK_EVENT_MANUAL_REC = 0x000,	//�ֶ�¼���¼�
    SDK_EVENT_TIMER_REC  		,   //��ʱ¼���¼�
	SDK_EVENT_MOTION    		,   //�ƶ�����¼�
    SDK_EVENT_AUDIOALERT 		,	//�������
    SDK_EVENT_ALARM_IN  		,  	//����澯�¼�
    SDK_EVENT_LOST     			,   //��Ƶ��ʧ�¼�
    SDK_EVENT_HIDE     			,   //��Ƶ�ڵ��¼�
    SDK_EVENT_IR       			,   //433 һ�����Ƶ�źŵĸ澯 ����Ҳ��IO�澯
    SDK_EVENT_HD_FORMAT  		,	//��ʽ��   �ϱ��ɹ� ����ʧ��
    SDK_EVENT_HD_ERR     		,   //���̴����¼�
    SDK_EVENT_HD_NOT_EXIST		,	//¼���̲�����
    SDK_EVENT_FORMAT  			,	//��ʽ��   �ϱ��ɹ� ����ʧ��
    SDK_EVENT_PIR				, 	//PIR����
    SDK_EVENT_ALL				,
    SDK_EVENT_BUTT
} SDK_EVENT_TYPE_E;
/*----------�¼����-------------------*/


/*
 *  ������������
 */
typedef struct sdk_alarm_handle_s
{


    uint8_t  record_enable;
    uint8_t  record_time;                 //¼����ʱʱ�� 15�� Ĭ��
    uint8_t  snap_enable;
    uint8_t  snap_num;                    //����ץ������

    uint8_t  beep_enable;                 //�Ƿ������
    uint8_t  beep_time;                   //����ʱ��
    
    uint8_t  alarm_out_enable;			// ʹ��
    uint8_t  alarm_out_time;              //�������ʱ��

    uint8_t  email_enable;               //�����ʼ�email 9527 20140802����

    uint8_t led_enable;  //���Ƿ���Ҫ����   ����ж�ŵƵĻ� ÿһλ����һ����  
    uint8_t led_time;     //�Ƴ�����˸ʱ��

    uint8_t  res[2+4];                    //email, ftp, 3g;
} sdk_alarm_handle_t;

/*
 * �������루IO����������
 */
typedef struct sdk_alarm_in_cfg_s
{
    uint8_t name[MAX_ALARM_IN_NAME_LEN];                        //������������
    uint8_t type;                                               //�����������ͣ�1������(Ĭ��)��0������
    uint8_t enable;                                             //��������
    uint8_t res[2];                                             //����
    sdk_sched_time_t sched_time;								//����ʱ���
    sdk_alarm_handle_t alarm_handle;                            //��������
} sdk_alarm_in_cfg_t;


/*
 * ��Ƶ�ƶ��������
 */
typedef enum _SDK_VDA_MOD_E
{
    SDK_VDA_MD_MOD = 0, 
	SDK_VDA_OD_MOD = 1
} SDK_VDA_MOD_E;

typedef struct sdk_vda_codec_cfg_s
{
    uint8_t enable;                //��������
    uint8_t sensitive;             //������(0 :��ֹ  1:��� 2:�� 3:��  4:��  5:���  )
    uint8_t mode;                  /* 0:MD �ƶ� 1:OD �ڵ� */
    uint8_t res;
    uint32_t mask;				 //��λ ����ʹ�� ���δ���32������ʹ��
    sdk_rect_t area[MAX_MOTION_NUM];  //����
} sdk_vda_codec_cfg_t;


typedef struct sdk_motion_cfg_s
{
    sdk_vda_codec_cfg_t codec_vda_cfg;
    sdk_sched_time_t sched_time;                //����ʱ���
    sdk_alarm_handle_t alarm_handle;            //��������
} sdk_motion_cfg_t;


//���Ǻ���ֱ�Ӻν�sdk_motion_cfg_t�� ����ʱ�����ƶ����ͬ������
typedef struct sdk_audio_detect_cfg_s
{
    uint8_t enable;                //��������
    uint8_t sensitive;             //������(0 :��ֹ  1:��� 2:�� 3:��  4:��  5:���  )     //��������
} sdk_audio_detect_cfg_t;

typedef struct sdk_mirror_flip_cfg_s
{
    uint8_t mirror;                //ˮƽ��ת(0:normal  1: mirror)
    uint8_t flip;             //��ֱ��ת(0:normal  1: flip)
    uint8_t res[2];     		//����
} sdk_mirror_flip_cfg_t;

typedef struct sdk_power_freq_cfg_s
{                
    uint8_t powerfreq;  // 0: 60hz  1: 50hz     
    uint8_t res[3];  
} sdk_power_freq_cfg_t;


/*
 * ��Ƶ�ڵ��������
 */
typedef struct sdk_hide_cfg_s
{
    uint8_t enable;                                         //��������
    uint8_t sensitive;                                          //������(0[���������]----6[���])
    uint8_t res[2];                                             //����
    uint32_t mask;												 // ��λ
    sdk_rect_t area[MAX_MOTION_NUM];                            //����
    sdk_sched_time_t sched_time;								//����ʱ���
    sdk_alarm_handle_t alarm_handle;                            //��������
} sdk_hide_cfg_t;

/*
 * ��Ƶ��ʧ�������
 */
typedef struct sdk_lost_cfg_s
{
    uint8_t enable;                                             //��������
    uint8_t res[3];                                             //����
    sdk_sched_time_t sched_time;								//����ʱ���
    sdk_alarm_handle_t alarm_handle;                            //��������
} sdk_lost_cfg_t;
/*
 *
 *��Ƶ������������  ��������
 */

typedef struct sdk_overlay_cfg_s
{
    uint8_t   enable;                  //�Ƿ���
    uint8_t   max_num;
    uint8_t   res[2];
    uint32_t   mask;                    //bit.0: area[0], bit.1: area[1]
    sdk_rect_t area[MAX_OVERLAY_NUM];   //��������
} sdk_overlay_cfg_t;



/*
 *
 *��ƵOSD����(�ӽṹ��)
 */

typedef struct sdk_osd_info_s
{

    sdk_point_t pos;            //λ��
    uint8_t     valid;          // ��ǰ�����Ƿ���Ч
    uint8_t     font;           // ��������
    // [7 6 5 4 - 3 2 1 0]
    // bit[4-7]: display type, 0: time, 1: string, 2 .....
    // bit[0-3]: display format
    //           sample time format:
    //           bit[2-3], 0: YYYYMMDD, 1: MMDDYYYY, 2: DDMMYYYY
    //           bit[1],   0: '-'       1: '/'
    //           bit[0],   0: 24hour    1: ampm
    uint8_t     format;         // ��ʾ��ʽ
    uint8_t     str_len;        // �ַ�������
    uint8_t     str[MAX_OSD_STR_LEN];//ascii+gb2312�ַ���
} sdk_osd_info_t;



/*
 *
 *��ƵOSD����  ����ͼƬ ����
 */
typedef struct sdk_osd_cfg_s
{
    sdk_osd_info_t  time;        //OSDʱ��
    sdk_osd_info_t  chann_name;  //OSDͨ������
    sdk_osd_info_t  ext_info;       //�������� ����ͼƬ��Ϣ
    uint32_t  osd_invert_color; // ����ɫ
    uint32_t  time_color;	//ʱ����ʾ��ɫ
    uint32_t  chann_name_color; //ͨ����Ϣ��ʾ��ɫ
    uint8_t  res2[32];

} sdk_osd_cfg_t;


/*
 *
 *ͼ����������
 */
typedef struct sdk_image_attr_s
{
    uint8_t brightness;         //����
    uint8_t contrast;           //�Աȶ�
    uint8_t saturation;         //���Ͷ�
    uint8_t hue;                //ɫ��
    uint8_t sharpness;          //���
    uint8_t icut_flag;          //��ʶ
    uint8_t res[2];
} sdk_image_attr_t;


/*
 * ץ�Ľṹ�嶨�� �����������
 */
typedef struct sdk_snap_pic_s
{
    uint16_t width;             //���
    uint16_t height;            //�߶�
    uint8_t  encode;            //�����ʽ,JPEG ĿǰΨһ֧�����ָ�ʽ
    uint8_t  quilty;            //ͼ������ 0 --100
    uint8_t  res[2];            //����
} sdk_snap_pic_t;

/*
*  ������������
*/

typedef struct sdk_snap_info_s
{
    uint16_t width;	//support range 0~ 1920
    uint16_t height;//support range 0 ~ 1080

    //uint32_t  image_quality;  //ͼƬ���� 0~100
    uint32_t  data_len;  //ʵ�����ݳ���

    uint32_t  buffer_max_len;  //���ݳ���
    uint8_t	*data;  //�洢ͼƬ�Ŀռ�
} sdk_snap_info_t;

/*
* ����ץ�����������
*/

typedef struct sdk_snap_data_s
{
    uint8_t pic_num;  //ץ��������
    sdk_snap_info_t *snap_data;
} sdk_snap_data_t;

//����Ȥ������������
typedef struct _sdk_roi_cfg_s
{
    uint32_t enable;						//1:����	0: ������
    uint32_t abs_qp;						//0 ������� 1 ��������
    uint32_t qp_val;						//����ֵ 0-51

    sdk_rect_t	roiRect[MAX_ROI_REG]; //����  ��8138s��ֻ֧��һ����
} sdk_roi_cfg_t;


//3d����
typedef struct _sdk_3di_cfg_s
{
    uint32_t deinterlace;  ///< temporal_deInterlace=1(enabled), 0(disabled)
    uint32_t denoise;  ///< temporal_deInterlace=1(enabled), 0(disabled)
} sdk_3di_cfg_t;


/* ------------SENSOR---------------------*/

typedef enum _SDK_SENSOR_TYPE_
{
    SENSOR_TYPE_OV9712 = 0,   /*      */
    SENSOR_TYPE_OV7725,
    SENSOR_TYPE_AR0130,
    SENSOR_TYPE_AR0330,
    SENSOR_TYPE_HM1375,
    SENSOR_TYPE_MT9P031

} SDK_SENSOR_TYPE;

typedef enum _SDK_STREAM_TYPE_
{
    STREAM_AUDIO_INDEX  		=	0  ,
    STREAM_VIDEO_INDEX_1    	=	1  ,
    STREAM_VIDEO_INDEX_2    	=	2  ,
    STREAM_VIDEO_INDEX_3    	=	3  ,
    STREAM_VIDEO_INDEX_4    	=	4  ,

    STREAM_VIDEO_INDEX_BUT
} SDK_STREAM_TYPE;

//����Ƶ������
typedef struct _sdk_stream_info_s
{
    int ch;
    int sub_ch;
    uint64_t time;
    frame_t frame_head;
    char *frame_addr;

} sdk_stream_info_t;

// �����Ҫ �Ż��ٶ��� ��Ӧ�����¼��ϱ�
typedef struct sdk_event_s
{
    SDK_EVENT_TYPE_E enevt_type;        //�¼�����
    int event_time ;		//����ʱ���ʱ�� ÿ8bit��ʾһ����λ  xxHHMMSS
    int result;            //���  1  start  0 stop
    int res[2];            //���
} sdk_event_t;

typedef struct sdk_pir_event_s
{
	pthread_t 				pir_pthread_read_handle;//�߳�ID
	pthread_t 				pir_pthread_control_handle;//�߳�ID
	unsigned int			alarm_enable; //BIT16��ʾ�����˵ȼ�
	unsigned int			pir_pthread_is_processing; //�߳����б�־λ
    SDK_EVENT_TYPE_E 		event_type;        //�¼�����
    unsigned long 			event_time ;		//����ʱ���ʱ��
    unsigned long 			last_time;	 //��һ�α�����ʱ��
    int 					pir_status; //PIR������ǰ��״̬
    int 					md_status;
	unsigned int 			pir_setting; //������Ϊ0  �������Ϊ1  
    int res[2-1];            //���
}sdk_pri_event_t;

/************/
//�¼��ص�
typedef void (*EventCallback)(void *data); //�¼��ص� �����������  �ƶ���� ����Ҫ���ⲿ�澯����Ϣ
typedef void (*AudioAlertCallback)(); //�������
typedef void (*FrameStatCallback)(void *data); //������Ϣ
typedef void (*AppMessageCallback)(void *data); //�û��ص�
typedef void (*SendstreamCallback)(void *data); //����Ƶ���ݻص�

///struct stream_writeFrame_s;
//typedef uint32_t (*SendstreamCallback)(struct stream_writeFrame_s *writeFrame); //����������

/*------------¼�� �ط�-----------------*/
/*
*¼�����Ͷ���  ��ѯ����Ҳ�����
*/

typedef enum _SDK_RECORD_TYPE
{
    SDK_RECORD_TYPE_ALL 	 	= 0X0,
    SDK_RECORD_TYPE_MANU     	= 0x1,   // �ֶ�
    SDK_RECORD_TYPE_SCHED    	= 0x2,  //   �ų�
    SDK_RECORD_TYPE_MOTION   	= 0x3,  // �ƶ����
    SDK_RECORD_TYPE_ALARM    	= 0x4,  // ��������
    SDK_RECORD_TYPE_AED      	= 0x5,  // �������
    SDK_RECORD_TYPE_BCD      	= 0x6,  // ����
    SDK_RECORD_TYPE_TAMPER   	= 0x7,  //
    SDK_RECORD_TYPE_MOTION_PRE	= 0x8,  // �ƶ���� Ԥ¼��
} SDK_RECORD_TYPE_E;


/*
 * ¼�����
 */
typedef struct sdk_manual_record_s
{
    uint8_t manual_record[MAX_CHANN_NUM];	// �ֶ�¼��
    uint8_t stop_record[MAX_CHANN_NUM];		// ��ֹ¼��
    uint8_t res[MAX_CHANN_NUM];				// ����λ
} sdk_manual_record_t;

/*
 * �ֶ�����(ֹͣ)����������
 */
typedef struct sdk_manual_alarmin_s
{
    uint8_t enable_alarmin[MAX_ALARM_IN_NUM];	// 0:ֹͣ; 1:����(Ĭ��ȫ����)
    uint8_t res[MAX_ALARM_IN_NUM];				// ����λ
} sdk_manual_alarmin_t;

/*
 * �ֶ�����(ֹͣ)�������
 */
typedef struct sdk_manual_alarmout_s
{
    uint8_t enable_alarmout[MAX_ALARM_OUT_NUM];	// 0:ֹͣ(Ĭ��ȫֹͣ); 1:����
    uint8_t res[MAX_ALARM_OUT_NUM];				// ����λ
} sdk_manual_alarmout_t;


/*
 * ¼�񱸷�
 */
typedef enum _SDK_BACKUP_OP
{
    SDK_BACKUP_START = 0x001,		//sdk_record_backup_t
    SDK_BACKUP_PROGRESS,		    //pmsg->chan:���ݽ���
    SDK_BACKUP_BUTT
} SDK_BACKUP_OP_E;

/*
 * ��������ļ���ʽ
 */
typedef enum _SDK_BACKUP_FMT
{
    SDK_BACKUP_FMT_JAV  = 0,     /* jav */
    SDK_BACKUP_FMT_AVI  = 1     /* avi */
} SDK_BACKUP_FMT_E;

typedef struct sdk_record_handle_s
{
    uint32_t  	item_handle[MAX_STOR_FRAGMENT_LEN];
    uint32_t 	item_size;				//�δ�С
    sdk_time_t 	start_time;          	//��ʼʱ��
    sdk_time_t 	end_time;           	//����ʱ��
    uint8_t  	res[4];					//����
} sdk_record_handle_t;

typedef struct sdk_record_backup_s
{
    sdk_record_handle_t item_arr[MAX_BACKUP_ITEM];
    uint8_t item_num;				//ʵ�ʱ��ݶ���
    uint8_t record_type;            //¼������
    uint8_t out_fmt;                //��������ļ���ʽ  SDK_BACKUP_FMT_E
    uint8_t res[1];					//����
} sdk_record_backup_t;
/*
 * ¼��������ӽṹ�壩
 */
typedef struct sdk_record_sched_s
{
    uint8_t is_allday;                              //�Ƿ�ȫ��¼��
    uint8_t record_type;                            //¼������
    uint8_t res[2];                                 //����
    sdk_sched_time_t sched_time[MAX_TIME_SEG_NUM];  //����ʱ���

} sdk_record_sched_t;

/*
 * ¼�����
 */
typedef struct sdk_record_cfg_s
{
    uint8_t enable;                                //������ʱ¼��
    uint8_t record_types;						//����¼������ 0 ��¼�� 1 ȫʱ¼�� 2����¼��
    uint8_t res[3-1];                                 //����
    sdk_record_sched_t record_sched[MAX_WEEK_NUM];  //����ʱ���(0:������; 1:����һ,2:���ڶ�,... ,6:������)

    uint32_t pre_record_time;                       //Ԥ¼ʱ��
    uint32_t record_duration_time;                  //¼����ʱ��

    uint8_t  enable_redundancy;                     //�Ƿ����౸��
    uint8_t  enable_audio;                          //�Ƿ�¼����Ƶ
    uint8_t  res2[2];                                //����

} sdk_record_cfg_t;


/*
 * ¼���¼����
 */
typedef struct sdk_record_item_s
{
    uint8_t item_name[MAX_RECORD_ITEM_LEN]; //��¼����
    uint32_t item_handle[MAX_STOR_FRAGMENT_LEN];   //sizeof(stor_fragment_t)+6��res
    sdk_time_t start_time;                  //��ʼʱ��
    sdk_time_t stop_time;                   //����ʱ��
    uint32_t item_size;                     //���ݴ�С

    uint8_t is_locked;                      //�Ƿ�����
    uint32_t record_type;                    //¼������
    // card no;
} sdk_record_item_t;

/*
 * ¼���ѯ����
 */
typedef struct sdk_record_cond_s
{
    uint8_t channel;              //ͨ��  ��IPC ���� Ĭ�Ͼ���0 ͨ��
    uint8_t res[3];                 //����
    uint32_t record_type;            //¼������  SDK_RECORD_TYPE_E
    sdk_time_t start_time;          //��ʼʱ��
    sdk_time_t stop_time;           //����ʱ��
    // card no;
} sdk_record_cond_t;


/*
 *
 * �طſ���������
 */
typedef enum _SDK_PB_GROUP_CONTROL
{
    SDK_PB_CONTROL_ONNE  = 0x00, 	//
    SDK_PB_CONTROL_PAUSE       , 	// ��ͣ
    SDK_PB_CONTROL_SETP        ,    // ��֡��
    SDK_PB_CONTROL_NORMAL      ,    // ����
    SDK_PB_CONTROL_DRAG        ,    // ��ק
    SDK_PB_CONTROL_FORWARD     ,    // ǰ��
    SDK_PB_CONTROL_BACKWARD    ,    // ����
    SDK_PB_CONTROL_QUERY_TIME  ,	// ��ѯ��ǰ������֡��ʱ�䣬��λ��

    SDK_PB_CONTROL_BUTT
} SDK_PB_GROUP_CONTROL_E;

/*
 *
 * ǰ�������ٶ�ö�� [--------- | ---- -> -> ----]
 */
typedef enum _SDK_PB_GROUP_CONTROL_FORWARD
{
    SDK_PB_CONTROL_FW_NORMAL = 0x00,  				// ����
    SDK_PB_CONTROL_FF_1X,     						// 1����� (FF-fast forward-��ǰ���)
    SDK_PB_CONTROL_FF_2X,    						// 2�����
    SDK_PB_CONTROL_FF_4X,         					// 4�����
    SDK_PB_CONTROL_FF_8X,							// 8�����
    SDK_PB_CONTROL_FF_16X,							// 16�����

    SDK_PB_CONTROL_SF_1_2X,						// 1������ (SF-slow forward-��ǰ����)
    SDK_PB_CONTROL_SF_1_4X,						// 2������
    SDK_PB_CONTROL_SF_1_8X,						// 4������
    SDK_PB_CONTROL_SF_1_16X						// 8������

} SDK_PB_GROUP_CONTROL_FORWARD_E;

/*
 *
 * ���˲����ٶ�ö�� [--- <- <- ---- | ----------]
 */
typedef enum _SDK_PB_GROUP_CONTROL_BACKWARD
{
    SDK_PB_CONTROL_BW_NORMAL = 0x00,  				// ����
    SDK_PB_CONTROL_FB_1X,     						// 1������ (FB-fast backward-�����)
    SDK_PB_CONTROL_FB_2X,   						// 2������
    SDK_PB_CONTROL_FB_4X,         					// 4������
    SDK_PB_CONTROL_FB_8X,							// 8������
    SDK_PB_CONTROL_FB_16X,							// 16������

    SDK_PB_CONTROL_SB_1_2X,						// 1������ (SB-slow backward-�������)
    SDK_PB_CONTROL_SB_1_4X,						// 2������
    SDK_PB_CONTROL_SB_1_8X,						// 4������
    SDK_PB_CONTROL_SB_1_16X						// 8������

} SDK_PB_GROUP_CONTROL_BACKWARD_E;


/*
 * �ط�ͨ���鶨��
 */
typedef struct sdk_pb_group_s
{
    sdk_time_t start_time;             //��ʼʱ��
    sdk_time_t stop_time;              //����ʱ��
    uint32_t main_chann;               //��ͨ����
    uint8_t chann_mask[MAX_CHANN_NUM];//ͨ�����루��·�ط�ʱ��
} sdk_pb_group_t;


/*****************************************/
/*
 * ��־��������
 */
typedef enum _SDK_LOG_OP
{
    SDK_LOG_QUERY = 0x01,  // ��ѯ sdk_log_item_t, sdk_log_cond_t
    SDK_LOG_EMPTY,         // ���(ȫ��)
    SDK_LOG_BACKUP,        // ����
    SDK_LOG_DEL			   // ɾ��(��ʱ���)
} SDK_LOG_OP_E;

/*
 * ��־���Ͷ��壨�����ͣ����֧��32�֣�
 */
typedef enum _LOG_MAJOR_TYPE
{
    LOG_MAJOR_SYSTEM 		= 0x00000001,  //ϵͳ��־
    LOG_MAJOR_ALARM  		= 0x00000002,  //�澯��־
    LOG_MAJOR_OPERATE		= 0x00000004,  //������־
    LOG_MAJOR_NETWORK		= 0x00000008,  //������־
    LOG_MAJOR_PARAM  		= 0x00000010,  //������־
    LOG_MAJOR_EXCEPTION	    = 0x00000020,  //�쳣��־

    LOG_MAJOR_ALL    		= 0xffffffff  //������־
} LOG_MAJOR_TYPE_E;

/*
 * ϵͳ��־������
 */
typedef enum _L_SYSTEM_MINOR_TYPE
{
    L_SYSTEM_MINOR_STARTUP = 0x0001,   //����
    L_SYSTEM_MINOR_SHUTDOWN,           //�ػ�
    L_SYSTEM_MINOR_REBOOT,				//����

    L_SYSTEM_MINOR_ALL     = 0xffff   //����ϵͳ��־
} L_SYSTEM_MINOR_TYPE_E;

/*
 * �澯��־������
 */
typedef enum _L_ALARM_MINOR_TYPE
{
    L_ALARM_MINOR_DI_START = 0x0001,   //����澯����
    L_ALARM_MINOR_DI_STOP ,            //����澯ֹͣ
    L_ALARM_MINOR_MD_START,            //�ƶ����澯����
    L_ALARM_MINOR_MD_STOP,             //�ƶ����澯ֹͣ
    L_ALARM_MINOR_VL_START,			   //��Ƶ��ʧ�澯����
    L_ALARM_MINOR_VL_STOP,			   //��Ƶ��ʧ�澯ֹͣ

    L_ALARM_MINOR_ALL		= 0xffff   //���и澯��־
} L_ALARM_MINOR_TYPE_E;

/*
 * ������־������
 */
typedef enum _L_OPERATE_MINOR_TYPE
{
    L_OPERATE_MINOR_LOGIN = 0x0001	// ��½
                            , L_OPERATE_MINOR_LOGOUT 			// ע��
    , L_OPERATE_MINOR_USER_ADD			// �û�����-����
    , L_OPERATE_MINOR_USER_DEL			// �û�����-ɾ��
    , L_OPERATE_MINOR_USER_MODI			// �û�����-�޸�
    , L_OPERATE_MINOR_SETTIME 			// ����ϵͳʱ��
    , L_OPERATE_MINOR_FORMAT_DISK 		// ��ʽ��Ӳ��
    , L_OPERATE_MINOR_DEFAULT 			// �ָ�Ĭ��
    , L_OPERATE_MINOR_UPGRADE 			// ����
    , L_OPERATE_MINOR_PLAYBACK 			// �ط�
    , L_OPERATE_MINOR_PTZ 				// ��̨����
    , L_OPERATE_MINOR_BACKUP 			// ����
    , L_OPERATE_MINOR_RECORD_START 		// ����¼��
    , L_OPERATE_MINOR_RECORD_STOP 		// ֹͣ¼��
    , L_OPERATE_MINOR_CLR_ALARM 		// �������
    , L_OPERATE_MINOR_TALKBACK_START 	// �Խ���ʼ
    , L_OPERATE_MINOR_TALKBACK_STOP 	// �Խ�����
    , L_OPERATE_MINOR_LOG_DEL			// ɾ����־
    , L_OPERATE_MINOR_LOG_EMPTY			// �����־
    , L_OPERATE_MINOR_LOG_BACKUP		// ������־
    , L_OPERATE_MINOR_MANUAL_RECORD_START 		// �ֶ�����¼��
    , L_OPERATE_MINOR_MANUAL_RECORD_STOP 		// �ֶ�ֹͣ¼��
    , L_OPERATE_MINOR_FORMAT_DISK_U 	// ��ʽ��U��

    , L_OPERATE_MINOR_ALL	= 0xffff	// ���в�����־
} L_OPERATE_TYPE_E;

/*
 * ������־������
 */
typedef enum _L_PARAM_MINOR_TYPE
{
    L_PARAM_MINOR_PARAM_NETWORK = 0x0001 	// �����������
                                  , L_PARAM_MINOR_PARAM_UART 				// ���ڲ�������
    , L_PARAM_MINOR_PARAM_PTZ 				// ��̨��������
    , L_PARAM_MINOR_PARAM_CHAN 				// ͨ����������
    , L_PARAM_MINOR_PARAM_VENC 				// �����������
    , L_PARAM_MINOR_PARAM_TV 				// TV��������
    , L_PARAM_MINOR_PARAM_PIC_ATTR			// ͼ����������
    , L_PARAM_MINOR_PARAM_RECORD			// ¼���������
    , L_PARAM_MINOR_PARAM_MOTION			// �ƶ��������
    , L_PARAM_MINOR_PARAM_VIDEOLOST			// ��Ƶ��ʧ����
    , L_PARAM_MINOR_PARAM_ALARMIN			// ����澯����
    , L_PARAM_MINOR_PARAM_POLL				// ��Ѳ����
    , L_PARAM_MINOR_PARAM_PREVIEW			// Ԥ������
    , L_PARAM_MINOR_PARAM_OVERLAY			// �ڵ���������
    , L_PARAM_MINOR_PARAM_OSD				// OSD����
    , L_PARAM_MINOR_PARAM_COMM				// ��������

    , L_PRARM_MINOR_ALL	= 0xffff			// ���в�����־
} L_PARAM_MINOR_TYPE_E;

/*
 * �쳣��־������
 */
typedef enum _L_EXCEPTION_MINOR_TYPE
{
    L_EXCEPTION_HD_FULL 		= 0x0001,   	//Ӳ����
    L_EXCEPTION_HD_ERROR,           		    //Ӳ�̴���
    L_EXCEPTION_NET_DISCONNECT,		        	//����Ͽ�
    L_EXCEPTION_IP_CONFLICT,			    	//IP��ͻ

    L_EXCEPTION_MINOR_ALL     = 0xffff   	//�����쳣��־
} L_EXCEPTION_MINOR_TYPE_E;

/*
 * ��־��¼����
 */
typedef struct sdk_log_item_s
{
    sdk_time_t  time;                       //ʱ��
    uint32_t    major_type;                 //����LOG_MAJOR_TYPE_E
    uint32_t    minor_type;                 //0x0000:ֱ����ʾdesc���ݣ�����ͨ��L_XXX_MINOR_TYPE_E��������.
    uint32_t    args;                       /*�����Ͳ���(args=0ʱ���ý���,�������minor_type�������ݡ�
    										���minor_type��ͨ������أ�args��ʾͨ����;���minor_type�͸澯��أ�args��ʾ�澯�����)*/
    uint8_t     user[MAX_USER_NAME_LEN];    //�����û�
    uint8_t     ip_addr[MAX_IP_ADDR_LEN];   //�û�IP
    uint8_t     desc[MAX_LOG_DESC_LEN];     //��־����(minor_type=0ʱ��Ч)
} sdk_log_item_t;


/*
 * ��־��ѯ����
 */
typedef struct sdk_log_cond_s
{
    sdk_time_t  begin_time;                 //��ʼʱ��
    sdk_time_t  end_time;                   //����ʱ��
    uint32_t    type;                       //����
    uint8_t     user[MAX_USER_NAME_LEN];    //�����û�
    uint8_t     ip_addr[MAX_IP_ADDR_LEN];   //�û�IP
} sdk_log_cond_t;



/*
 * ������Ϣ����
 */
typedef struct sdk_alarm_info_s
{
    sdk_time_t  time;                   //����ʱ��
    uint32_t    type;                   //��������
    uint32_t    args;                   //��������
    uint8_t     desc[MAX_ALARM_DESC_LEN];//��������
} sdk_alarm_info_t;


/*
 * ���ڲ�������
 */
typedef struct sdk_serial_param_s
{
    uint32_t baud_rate;             //���ڲ����� 115200, 57600, ...
    uint8_t  data_bit;              //����λ 5, 6, 7, 8
    uint8_t  stop_bit;              //ֹͣλ 1, 2
    uint8_t  parity;                //У�� 0:�ޣ�1:��У�� 2:żУ��
    uint8_t  flow_ctl;              //����
} sdk_serial_param_t;

/*
 * ������;����
 */
typedef struct sdk_serial_func_cfg_s
{
    uint8_t type;	// 0: normal, 1: ptz, 2...
    uint8_t res[3];
    sdk_serial_param_t serial_param;
} sdk_serial_func_cfg_t;

/*-------------��������------------------------*/

/*
*���Ͷ�����������
*/
typedef struct _sdk_bin_stream_s

{
    uint32_t type;							//��������������
    uint32_t flag;							//���ı�־
    uint32_t seq;							//�������
    uint32_t size;							//�����ṹ��� size
    uint8_t data[0];						//���Ӷ�����������ʼλ��
} sdk_bin_stream_t;

//SDK_MAIN_MSG_UPGRAD
typedef struct _sdk_upgrad_pkg_info_s
{
    uint32_t upgrad_session;   // ����˷��ظ��ͻ���һ���ػ�ID
    uint32_t total_packet;     //  �ܵİ���
    uint32_t total_len;		  // �����ļ��ܳ���
} sdk_upgrad_pkg_info_t;

/*
 * U�̲�ѯ�������ļ��б�
 */
typedef struct upgrad_pkg_file_s
{
    uint8_t   device_type[16];//�豸����
    uint8_t   ver[16];        //�汾
    uint8_t   date[16];       //����
    uint32_t  size;           //��С
    uint8_t   name[64];       //���� aa.upg
    uint8_t   file_path[128];  //�����ļ�ȫ·�� /tmp/aa.upg
} upgrad_pkg_file_t;


/*
 * �����������̣� SDK_UPGRAD_REQUEST => recv upg_pkg => SDK_UPGRAD_DISK_FILE => SDK_UPGRAD_PROGRESS;
 * U���������� :  SDK_UPGRAD_FIND_FILE => SDK_UPGRAD_DISK_FILE => SDK_UPGRAD_PROGRESS;
 */
typedef enum _SDK_UPGRAD_OP
{
    //������������ļ�
    SDK_UPGRAD_NET_REQUEST = 0x0, // �������� sdk_upgrad_pkg_info_t
    SDK_UPGRAD_NET_RECV_UPG	 	, // ����������sdk_bin_stream
    //��ʼ����������
    SDK_UPGRAD_REQUEST          , //��������	upgrade_packet_t
    SDK_UPGRAD_DISK_FILE        , //�������ڴ����ļ�
    SDK_UPGRAD_MEM_FILE         , //���������ڴ�
    SDK_UPGRAD_PROGRESS         , //��������
    SDK_UPGRAD_FIND_FILE          //U�̲�ѯ�������ļ��б�	upgrad_pkg_file_t
} SDK_UPGRAD_OP_E;



/*
 * ��̨���ò���
 */
/*
*  _0: debug, _1: ptz/normal, _2: rs232, _3 mcu
*  -------------------------, _2: mcu;
*  0: 1
*
*/
typedef struct sdk_ptz_param_s
{

    sdk_serial_param_t comm;                //���ڲ�����gui�̶�ֻ���ô���1
    uint8_t          address;               //��̨��ַ
    uint8_t          protocol;              //��̨Э��SDK_PTZ_PROTOCOL_E
    uint8_t          res[2];
} sdk_ptz_param_t;

/*
 * Ԥ�õ㶨��
 */
typedef struct sdk_preset_s
{
    uint8_t enable;         //�Ƿ�����
    uint8_t no;             //Ԥ�õ��
    uint8_t res[2];         //����
    uint8_t name[32];       //Ԥ�õ�����
} sdk_preset_t;


/*
 * Ԥ�õ㼯��(ÿ��ͨ��һ������)
 */
typedef struct sdk_preset_param_s
{
    uint8_t         num;                       //�����õ�Ԥ�õ����
    uint8_t         res[3];                    //����
    sdk_preset_t    preset_set[MAX_PRESET_NUM];//Ԥ�õ�
} sdk_preset_param_t;


/*
 *DVRʵ��Ѳ�����ݽṹ(ÿ��ͨ��һ��·��)
 */
typedef struct sdk_cruise_param_s
{
    uint8_t enable;                           //�Ƿ�����
    uint8_t res[2];                           //����
    uint8_t no;                               //����Ѳ��·���ĺ���(��ʱû�ã���ʲô��gui��gui��ʲô)
    uint8_t name[32];                         //Ѳ��·������(��ʱû�ã���ʲô��gui��gui��ʲô)
    uint8_t preset[MAX_CRUISE_PRESET_NUM];    //Ԥ�õ�
    uint8_t speed[MAX_CRUISE_PRESET_NUM];     //�ƶ��ٶ�
    uint8_t dwell_time[MAX_CRUISE_PRESET_NUM];//ͣ��ʱ��
} sdk_cruise_param_t;
/**********************************************/



typedef enum _SDK_LANUAGE_TYPE
{
    SDK_LANUAGE_TYPE_CHINA	= 0x00,		// ����
    SDK_LANUAGE_TYPE_ENGLISH= 0x01,		// Ӣ��
    SDK_LANUAGE_TYPE_MAX	= 0xff		 //�����֧����

} SDK_LANUAGE_TYPE_E;

typedef enum _SDK_POWER_HZ_
{
    SDK_POWER_HZ_50HZ	= 0x00,		// 50hz
    SDK_POWER_HZ_60HZ	= 0x01		// 60hz
} SDK_POWER_HZ_E;


/*
 *���ڵ���ԭ���������²����ĸı�һ�²�����������
 */
typedef struct sdk_regional_param_s
{
    uint8_t pow_hz;                           //��ԴƵ��    	0 :50hz   1:60hz
    uint8_t lanuage;                          //����ѡ��   		��ӦSDK_LANUAGE_TYPE_Eö��
    uint8_t in_out_door;                      //����/��ģʽ   	0:����ģʽ 1:����ģʽ
    uint8_t res;                              //����

} sdk_regional_param_t;
/**********************************************/

/*********ֱ��ͨ��IO���Ƶ��豸����*********/
/****************�������ڽ����433
����������mcu �������� ȫ������iodev
*********/
typedef struct sdk_buzzer_param_s
{
    uint8_t buzzer;                           //����������   1:������     0:�ر�
    uint8_t res[3];                           //����
} sdk_buzzer_param_t;

typedef struct sdk_led_param_s
{
    uint8_t led;                           //LED �ȱ��   ��Ӳ��������ȷ��
    uint8_t enable;                      // 0 �ر�  1 ʹ��
    uint8_t res[2];                           //����
} sdk_led_param_t;

typedef struct sdk_iodev_param_s
{
    sdk_buzzer_param_t buzzer_param;
    sdk_led_param_t led_param;

} sdk_iodev_param_t;



typedef struct sdk_upgrade_info_s
{
    int progress;//�������� ����%
    uint8_t old_version[MAX_VER_STR_LEN];		//��һ���汾�汾��
    uint8_t url[MAX_URL_LEN];		            //���������ص�ַ
} sdk_upgrade_info_t;

////////////////////////////////////////////led ״̬20150526
typedef struct
{
    char led_status[MAX_LED_NUM];	 //led_status[0]:   red----1:on 0:off
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
    int	 buzzer_time;  //  0 �� 120 ��

} SMsgAVIoctrlSetBuzzerStatusReq, SMsgAVIoctrlGetBuzzerStatusResp;

typedef struct
{
    int 			result; 	//return 0 if succeed
    unsigned char	reserved[4];
} SMsgAVIoctrlSetBuzzerStatusResp;

////////////////////////////////////////////


typedef struct tagMotionControl
{
    int MotionLevel; // 1~5
    int rsvd[3];
    unsigned long long ullbitsMDstate;   // 1bit mean 1 sec
}MotionControl;



#if 0
typedef enum  _SDK_PTZ_CTRL_E
{
    PTZ_CTRL_STOP					= 0,
    PTZ_CTRL_UP						= 1,
    PTZ_CTRL_DOWN					= 2,
    PTZ_CTRL_LEFT					= 3,
    PTZ_CTRL_LEFT_UP				= 4,
    PTZ_CTRL_LEFT_DOWN				= 5,
    PTZ_CTRL_RIGHT					= 6,
    PTZ_CTRL_RIGHT_UP				= 7,
    PTZ_CTRL_RIGHT_DOWN				= 8,
    PTZ_CTRL_AUTO					= 9,
    PTZ_CTRL_SET_POINT				= 10,
    PTZ_CTRL_CLEAR_POINT			= 11,
    PTZ_CTRL_GOTO_POINT				= 12,

    PTZ_CTRL_SET_MODE_START			= 13,
    PTZ_CTRL_SET_MODE_STOP			= 14,
    PTZ_CTRL_MODE_RUN				= 15,

    PTZ_CTRL_MENU_OPEN				= 16,
    PTZ_CTRL_MENU_EXIT				= 17,
    PTZ_CTRL_MENU_ENTER				= 18,

    PTZ_CTRL_FLIP					= 19,
    PTZ_CTRL_START					= 20,

    PTZ_CTRL_LENS_APERTURE_OPEN			= 21,
    PTZ_CTRL_LENS_APERTURE_CLOSE		= 22,

    PTZ_CTRL_LENS_ZOOM_IN				= 23,
    PTZ_CTRL_LENS_ZOOM_OUT				= 24,

    PTZ_CTRL_LENS_FOCAL_NEAR			= 25,
    PTZ_CTRL_LENS_FOCAL_FAR				= 26,

    PTZ_CTRL_AUTO_PAN_SPEED				= 27,
    PTZ_CTRL_AUTO_PAN_LIMIT				= 28,
    PTZ_CTRL_AUTO_PAN_START				= 29,

    PTZ_CTRL_PATTERN_START				= 30,
    PTZ_CTRL_PATTERN_STOP				= 31,
    PTZ_CTRL_PATTERN_RUN				= 32,

    PTZ_CTRL_SET_AUX					= 33,
    PTZ_CTRL_CLEAR_AUX					= 34,
    PTZ_CTRL_MOTOR_RESET_POSITION		= 35,
    PTZ_CTRL_AUTO_LEFT_RIGHT		= 36,	//����Ѳ��
    PTZ_CTRL_AUTO_UP_DOWN			= 37,	//����Ѳ��
    PTZ_CTRL_AUTO_LEFT_RIGHT_STOP	= 38,	//����Ѳ��
    PTZ_CTRL_AUTO_UP_DOWN_STOP		= 39,	//����Ѳ��
    PTZ_CTRL_AUTO_TRACK				= 40,	//�켣Ѳ��

    PTZ_CTRL_AUTO_LEFT_RIGHT_EX		= 41,	//����Ѳ��(���Զ�ֹͣ)
    PTZ_CTRL_AUTO_UP_DOWN_EX		= 42,	//����Ѳ��(���Զ�ֹͣ)
} SDK_PTZ_CTRL_E;

typedef struct sdk_ptz_cmd_s
{
    unsigned char control;	// PTZ control command, refer to SDK_PTZ_CTRL_E
    unsigned char speed;	// PTZ control speed
    unsigned char point;	// no use in APP so far. preset position, for RS485 PT
    unsigned char limit;	// no use in APP so far.
    unsigned char aux;		// no use in APP so far. auxiliary switch, for RS485 PT
    unsigned char channel;	// camera index
    unsigned char reserve[2];
} sdk_ptz_cmd_t;

#endif

/*************************** �û�������������**************************/
/*****����������ָ��������� reboot��  ��ϲ�����Ϊ GET/SET *****/
/*SDK userComand */

typedef enum _SDK_USER_COMMAND_TYPE
{
    SDK_USRCMD_DEVICE_INFO           = 1 ,//�豸��Ϣ
    SDK_USRCMD_PARAM_FACTORY  		 = 4, //�ָ���������
    SDK_USRCMD_WIFI_INFO   			 = 12,//wifi����
    SDK_USRCMD_REBOOT   			 = 13,//�����豸
    SDK_USRCMD_IMAGE_QUALITY		 = 14,//ͼ������
    SDK_USRCMD_REC_STATUS   		 = 15,//¼���ѯ
    SDK_USRCMD_MOTION_DETE		     = 17,//�ƶ�����ѯ
    SDK_USRCMD_AUDIO_STATUS			 = 22,//��������״̬��ѯ
    SDK_USRCMD_SNAPSHOT				 = 23,//ץ��ͼƬ
    SDK_USRCMD_TIME_INFO			 = 24,//ʱ�����
    SDK_USRCMD_UNDETERMINED			 = 25,//������
    SDK_USRCMD_PIR_STATUS			 = 26,//���ⱨ��״̬
    SDK_USRCMD_PERIPHERAL_SATTUS	 = 27,//�������(��������led�Ƶ�)  ����  34���Լ�������   38�����豨����
    SDK_USRCMD_COLOR_PARAM           = 28,//ɫ�ʲ���
    SDK_USRCMD_AUDIO_DETECT          = 29,//�����������
    SDK_USRCMD_UPGRADE				 = 30,//����(��ʼ���ѯ����)
    SDK_USRCMD_CODE					 = 31,//�������
    SDK_USRCMD_POWER				 = 32,//��ԴƵ��
    SDK_USRCMD_ALARM_AREA			 = 33,//��������  (���г��Ƿ����ƶ��������  ���Ǻ������������ȵ�Ӧ�ó���)
    SDK_USRCMD_ALARM_OUT			 = 34,//�������(����������)
    SDK_USRCMD_ARMING_24			 = 35,//24Сʱ��������
    SDK_USRCMD_ARNING_PLAN			 = 36,//�ų̲�������
    SDK_USRCMD_LANGUAGE				 = 37,//���������
    SDK_USRCMD_ALARM_EXTERNAL		 = 38,//�ⲿ��������
    SDK_USRCMD_GETWIFILIST           = 39,//��ȡwifilist
    SDK_USRCMD_IN_OUT_DOOR		     = 40,//������ģʽ

} SDK_USR_CMD_E;


typedef enum _RECORD_FLAGS
{
	RECORD_NO = 0,
	RECORD_FULLTIME,
	RECORD_ALARM,
	RECORD_NULL
}BUZZER_FLAGS;

typedef enum _SHCEDULE_RECORD_FLAGS
{
	RECORD_OFF = 0,
	RECORD_ON,
}SHCEDULE_FLAGS;

typedef struct _SDK_RECORD_STATUS_
{				
	unsigned int 	pthread_is_processing;
	pthread_mutex_t record_lock;

	unsigned int	record_flags; //¼��״̬ �ɱ���Ĳ�����TUTK�·��Ĳ���������
	unsigned int	record_last_status; //��һ�ε�¼��״̬
	unsigned int	record_alarm_triger; //����¼��ʱ������Ϊ����¼��Ŀ���
	unsigned int    record_alarm_opened; //��ʾstart����

	unsigned int    record_alarm_time; //����¼��ʱ��
	pthread_t  		record_pthread_handle;//�߳̾��
	//wu add it to recorde sched 2016-12-28
	//sdk_record_sched_t record_sched[MAX_WEEK_NUM];	//����ʱ���(0:������; 1:����һ,2:���ڶ�,... ,6:������)

	unsigned int    md_interval_time; 	//�ƶ�����ʱ����  ���ݷ�������ṹ�塿
}RECORD_STATUS;  //0 disable record 		1 record fulltime    2 record alarm


//����ѷ�ṹ��
typedef enum
{
	AWS_FULLTIME = 0,
	AWS_ALARM,
	AWS_NO =255
}AWS_TYPE;

/*typedef struct _sdk_aws_status_
{
	pthread_t 		aws_pthread_handle;//����ѷ�ϴ��߳�ID
	pthread_t 		aws_snap_pthread_handle;//����ץͼ�߳�ID
	unsigned int	aws_pthread_is_processing;
	pthread_mutex_t aws_lock;			//��
	unsigned int 	full_or_alarm;		//ȫʱ�ϴ����Ǳ����ϴ�
	unsigned int 	alarm_trigger;		//���������ϴ�
	unsigned int    snap_flags;		//ץͼ��־λ
	//unsigned int	snap_finish;		//�Ƿ����ץͼ    ���ץͼʱ���ϴ�
	unsigned int 	alarm_time;			//������ʱ�� == ����¼���ʱ��
	unsigned int	current_fps;		//��ǰ֡��     ���Լ����ϴ�����֡
	unsigned int	aws_flags;			
	//BIT16 ��ʾFULLTIMEʱ�Ƿ��ҵ�I֡  BIT17��ʾ����¼��ʱ�Ƿ��ҵ�I֡
	//bit0-15��ʾ����¼��ļ���ֵ
	//BIT 31 ��ʾ������� ��֡�����ϴ���
} aws_status;*/

typedef enum
{
	BUF_EMPTY =0,	//BUF ��������������� ������0
	BUF_HAVE_DATA, //BUF���������������� �����滹δ��
	BUF_FULL		//BUF ����   Ҳ����ָ����ʱ���ѵ�
}AWS_BUF_FLAGS;
typedef enum
{
	STATUS_DAY =0,
	STATUS_NIGHT =1,
	STATUS_NULL		
}AWS_FRAME_STATUS;


typedef struct _sdk_aws_status_
{
	unsigned int	aws_pthread_is_processing;
	pthread_mutex_t aws_lock;			//��
	unsigned int 	full_or_alarm;		//ȫʱ�ϴ����Ǳ����ϴ�
	unsigned int 	alarm_trigger;		//���������ϴ�
	unsigned int    snap_flags;		//ץͼ��־λ
	//unsigned int	snap_finish;		//�Ƿ����ץͼ    ���ץͼʱ���ϴ�
	unsigned int 	alarm_time;			//������ʱ�� == ����¼���ʱ��
	unsigned int	current_fps;		//��ǰ֡��     ���Լ����ϴ�����֡
	unsigned int	aws_flags;			
	//BIT16 ��ʾFULLTIMEʱ�Ƿ��ҵ�I֡  BIT17��ʾ����¼��ʱ�Ƿ��ҵ�I֡
	//BIT18��ʾ����Ƶ����
	//bit0-15��ʾ����¼��ļ���ֵ
	//BIT 31 ��ʾ������� ��֡�����ϴ���
	pthread_t 		aws_video_pthread_handle;//����ѷ�ϴ��߳�ID
	pthread_t 		aws_audio_pthread_handle;//����ѷ�ϴ��߳�ID
	pthread_t 		aws_upload_pthread_handle;//����ѷ�ϴ��߳�ID
	unsigned char *video_buf;
	unsigned int  video_len;
	AWS_BUF_FLAGS video_buf_flags; //�����־λ
	struct timeval  video_time; //�����һ��I֡��ʱ��
	unsigned char  frame_rate; //�����һ��I֡��֡��
	pthread_cond_t aws_cond ; //aws�������� ���� �����߳�֪ͨ�����߳�
	unsigned char  send_finish; //�����̷߳�����ϱ�־λ 0 �ѷ��� 1 δ����
	unsigned int iframe_count;
	AWS_FRAME_STATUS day_or_night;//���컹��ҹ�� 0���� 1ҹ��
	int time_zone;
	void * audio_handle ;
} aws_status;


typedef struct sdk_aws_info_s
{

    uint8_t aws_record_status;
    uint8_t res[3];
} sdk_aws_info_t;


typedef enum _ARM_STATUS
{
	ARM_DISABLE =0,
	ARM_ENABLE
}ARM_STAUS;

typedef enum _LED_STATUS  //����LED�����ȼ�
{
	LED_IS_ENABLE =0, 	// ������ʹ�� ��������ʹ��  �漰��>= OR >  
	LED_NORMAL,       	//�������������	
	LED_ARM,     	 	//������
	LED_MONITOR,  		//�ۿ���Ƶ��
	LED_ALARM_TRIGGER, 	//��������ʱ
	LED_PANIC,			//�ֶ�
	LED_FORCE_CLOSE,	//	ǿ�ƹر� 
	LED_NO_WIFI,		//û���������� AP
	LED_WIFI_CONFIGING,  //WIFI ������
	LED_RESTART,		//������
	LED_ALARM_MONITOR=24 // ��������ʱ�Ƿ��ڹۿ�״̬
	//LED_ALARM_AND_MONITOR=25 // ��������ʱ,	���ڹۿ�״̬
}LED_STATUS;
typedef enum _BUZZER_STATUS
{
	BUZZER_IS_ENABLE =0,//������ ʹ��  ��������ʹ�� �漰��IF�жϵ�>= OR >  
	BUZZER_ENABLE_NO_BEEP,//����
	BUZZER_ENABLE_BEEP,  //��������
	BUZZER_TESTING		//�ֶ�ǿ��
}BUZZER_STATUS;
typedef struct _led_buzzer_info_
{
	pthread_t 		led_buzzer_pthread_pid;//�߳�ID
	unsigned int	led_buzzer_pthread_is_processing;
	pthread_mutex_t 	led_buzzer_lock;
	ARM_STAUS  arm_status; //�Ƿ񲼷�
	unsigned int led_status;//LED��״̬
	unsigned char led_time; //led ʱ��
	BUZZER_STATUS buzzer_status; //��������״̬ //����״̬ OR ����״̬
	unsigned char buzzer_time; //���������ʱ��
}LED_BUZZER_INFO;

#ifdef __cplusplus
}
#endif

#endif //__sdk_struct_h__
