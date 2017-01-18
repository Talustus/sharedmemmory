#ifndef __tutk_h__
#define __tutk_h__

#include "main.h"
#include "storage.h"
#ifdef __cplusplus
extern "C" {
#endif


#define RD_SUCCESS		0
#define RD_FAILED		  1
#define RD_INCOMPLETE	2
#define PACKET_SIZE 1024*1024

typedef  void* media_handle;

typedef struct
{
    char guid[21];
    char ViewAccount[32];
    char ViewPassword[32];
    int  tutk_enable;
    int  quality;
    char reserv[128]; //����
} TUTK_INFO;

/*typedef enum _ARM_STATUS
{
		ARM_DISABLE =0,
		ARM_ENABLE
}ARM_STAUS;
typedef enum _LED_STATUS
{
		LED_DISABLE =0,
		LED_ENABLE_GREEN,
		LED_ENABLE_GREEN_FLASH,
		LED_ENABLE_BLUE,
		LED_ENABLE_BLUE_FLASH,
		LED_ENABLE_RED,
		LED_ENABLE_RED_FLASH
}LED_STAUS;*/
/*typedef enum _LED_STATUS  //����LED�����ȼ�
{
		LED_IS_ENABLE =0, 	// ������ʹ�� ��������ʹ��  �漰��>= OR >  
		LED_NORMAL,       	//�������������	
		LED_ARM,     	 	//������
		LED_MONITOR,  		//�ۿ���Ƶ��
		LED_ALARM_TRIGGER, 	//��������ʱ
		LED_PANIC,			//�ֶ�
		LED_FORCE_CLOSE,	//	ǿ�ƹر� 
		LED_NO_WIFI,		//û���������� AP
		LED_RESTART			//������
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
*/
typedef struct _tutk_media_info
{
	int video_current_chn;
	void  * video_handle;
	void  * audio_handle;
}media_info;

/* �豸�����ӿ� */
typedef struct _tutk_device_ops
{
	int (*get_param)(int param_id, int channel, void *param, void *user); /* ��ȡ�豸���� */
	int (*set_param)(int param_id, int channel, void *param, void *user); /* �����豸���� */
}tutk_device_ops;

/* ʵʱ���ӿ� */
typedef struct _tutk_ls_avs_ops
{
	unsigned int encode_current_chn;//��ʾ��ǰȡ�Ǹ�ͨ������Ƶ��
    int32_t (*open)(media_info *m, int32_t channel, int32_t level, void *media_info);/* �� */
    int32_t (*ctrl)(media_info *m, uint32_t cmd, void *data);           /* ���� */
    void    (*close)(media_info *m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_info *m, int32_t channel,char **frm);                          /* ���� */
	//tutk �������ǵ����̴߳����
	int32_t (*open_audio)(media_info *m, int32_t channel, int32_t level, void *media_info);/* �� */
    void    (*close_audio)(media_info *m,int32_t channel);                                    /* �ر� */
    int32_t (*pull_audio)(media_info *m, int32_t channel,char **frm);                          /* ���� */

	//���ӶԽ�����
	int32_t (*play_start)(media_info*  m,int32_t channel);  /* ���ſ�ʼ */
	int32_t (*send_audio)(media_info *m, int32_t channel,char *audio_buf,int32_t audio_len);     /* ���������Ϊ�������Խ�*/
    int32_t (*play_stop)(media_info*  m,int32_t channel);     /* ���Ž��� */                                 /* ���� */
}tutk_ls_avs_ops;

/* ��ʷ���ӿ� */
typedef struct _tutk_hs_avs_ops
{
    int32_t (*open)(media_handle m, int32_t channel, int32_t level
                    , int32_t type, uint8_t *start_time, uint8_t *end_time
                    , uint8_t *property, void *mi);                 /* �� ʱ���ʽ:YYYYMMDDHHMMSS */
    int32_t (*play)(media_handle m,int32_t channel);                                     /* ��ʼ */
    int32_t (*pause)(media_handle m,int32_t channel);                                    /* ��ͣ */
    int32_t (*lseek)(media_handle m, uint32_t ts);                       /* ��λ */
    void    (*close)(media_handle m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_handle m, int32_t channel,sdk_frame_t *frm);                       /* ���� */
}tutk_hs_avs_ops;

/* SDK �ӿڶ��� */
int tutk_server_init(sdk_msg_dispatch_cb msg_cb);
int tutk_server_uninit();


int tutk_server_reg_device_ops(tutk_device_ops *ops);        /* ע���豸�����ӿ�*/
int tutk_server_reg_avs_ops(tutk_ls_avs_ops *ls, tutk_hs_avs_ops *hs);/* ע����ý��ӿ� */

int tutk_server_start();	/* �������� */
int tutk_server_stop();
int tutk_server_restart();	/* ������������ */


int tutk_server_submit(int parm_id, int channel, void *parm);             /* �ϱ���Ϣ�ӿ� */

int tutk_upload_file(const char *path,const char *file_name); //ץ��ͼƬ�ϴ�

#ifdef __cplusplus
}
#endif

#endif //__baidu_h__

