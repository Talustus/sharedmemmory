
#ifndef __baidu_h__
#define __baidu_h__

#include "main.h"
#ifdef __cplusplus
extern "C" {
#endif


#define RD_SUCCESS		0
#define RD_FAILED		  1
#define RD_INCOMPLETE	2
#define PACKET_SIZE 1024*1024

typedef  void* media_handle;

/* �豸�����ӿ� */
typedef struct _baidu_device_ops
{
	int (*get_param)(int param_id, int channel, void *param, void *user); /* ��ȡ�豸���� */
	int (*set_param)(int param_id, int channel, void *param, void *user); /* �����豸���� */
}baidu_device_ops;

/* ʵʱ���ӿ� */
typedef struct _baidu_ls_avs_ops
{
    int32_t (*open)(media_handle m, int32_t channel, int32_t level, void *media_info);/* �� */
    int32_t (*play)(media_handle m,int32_t channel);                                     /* ���� */
    int32_t (*ctrl)(media_handle m, uint32_t cmd, void *data);           /* ���� */
    void    (*close)(media_handle m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_handle m, int32_t channel,char **frm);                          /* ���� */
    int32_t (*get)(media_handle m, int32_t channel,char *frm);     /* ���������Ϊ�������Խ�*/
}baidu_ls_avs_ops;

/* ��ʷ���ӿ� */
typedef struct _baidu_hs_avs_ops
{
    int32_t (*open)(media_handle m, int32_t channel, int32_t level
                    , int32_t type, uint8_t *start_time, uint8_t *end_time
                    , uint8_t *property, void *mi);                 /* �� ʱ���ʽ:YYYYMMDDHHMMSS */
    int32_t (*play)(media_handle m,int32_t channel);                                     /* ��ʼ */
    int32_t (*pause)(media_handle m,int32_t channel);                                    /* ��ͣ */
    int32_t (*lseek)(media_handle m, uint32_t ts);                       /* ��λ */
    void    (*close)(media_handle m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_handle m, int32_t channel,sdk_frame_t *frm);                       /* ���� */
}baidu_hs_avs_ops;

/* SDK �ӿڶ��� */
int baidu_server_init(sdk_msg_dispatch_cb msg_cb);
int baidu_server_uninit();


int baidu_server_reg_device_ops(baidu_device_ops *ops);        /* ע���豸�����ӿ�*/
int baidu_server_reg_avs_ops(baidu_ls_avs_ops *ls, baidu_hs_avs_ops *hs);/* ע����ý��ӿ� */

int baidu_server_start();	/* �������� */
int baidu_server_stop();

int baidu_server_submit(int parm_id, int channel, void *parm);             /* �ϱ���Ϣ�ӿ� */

int baidu_set_property(); //���ðٶȵ�����
int baidu_upload_file(const char *path,const char *file_name,const char *target_path); //ץ��ͼƬ�ϴ�

#ifdef __cplusplus
}
#endif

#endif //__baidu_h__

