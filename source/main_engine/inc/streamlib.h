/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, bingchuan

 ******************************************************************************
  �� �� ��   : streamlib.h
  �� �� ��   : v1.0
  ��    ��   : bingchuan
  ��������   : 2015��1��31��
  ��������   : streamlib.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��1��31��
    ��    ��   : bingchuan
    �޸�����   : �����ļ�

******************************************************************************/


#ifndef __STREAMLIB_H__
#define __STREAMLIB_H__

#include "sdk_global.h"
#include "sdk_struct.h"

#define SDK_STREAM_SIGNAL_STREAM  (1)
#define SDK_STREAM_TWO_STREAM     (2)

#define STREAM_MAX_FRAME_SIZE     (512*1024)
#define STREAM_MAX_NAL_NUM 	      (16) 

typedef enum _STREAM_FRAME_TYPE_E
{
	STREAM_I_FRAME_TYPE = 1,
	STREAM_P_FRAME_TYPE,
	STREAM_B_FRAME_TYPE,
	STREAM_A_FRAME_TYPE, 
}STREAM_FRAME_TYPE_E;

//typedef sdk_frame_t frame_t;
typedef sdk_frame_t frame_head_t;

typedef  void* ST_HDL;
typedef  void* POOL_HDL;   // �ڴ�ռ���
typedef  void* EV_HDL;		 //ʱ����


typedef struct _stream_ch_info_t
{
	int total_space;
	int index_num;
	int max_frame_size;
}stream_ch_info_t;

typedef struct __stream_manage_t
{
	int ch_num;					                                    /* �豸ͨ���� ����GPS ������ͨ���Ż� */
	int two_stream;					                                /* ˫������־ 1��ʾֻ��������, 2˫���� */
	int max_frame_size;				                                /* ���֡���ݳ��� */
	int (*get_ch_streamInfoCB)(int ch, int ch_type
			, stream_ch_info_t *ch_stream_info); 	                /* ��ȡû��ͨ�������õ��������������˷���ռ� Ϊ��ʱ����Ĭ��ֵ */
	//int (*get_g_video_resolutionCB)(int ch, int ch_type);         /* �ɲɼ����ṩ�ӿ� */
	//int (*get_audio_infoCB)(int ch, audio_encode_t *audio_encode);/* �ɲɼ����ṩ�ӿ� */
	int (*get_recordStatCB)(int ch, int ch_type);                   /* �����ṩ ��ȡ¼��״̬��¼����ṩ�ӿ� */
	int (*force_iFrameCB)(int ch, int ch_type);                     /* ǿ��I֡*/
	int (*get_contrlTypeCB)(int ch); //int ch_type);                /* Ŀǰ��ʾ��¼��������ֹͣ��־ */
}stream_manage_t;

typedef struct stream_writeFrame_s
{
	int ch;
	int ch_type;
	int frame_len; /*����֡ͷ */
	
	int time;
    int time_us;
	int frame_type;
    int nal_num;                     	//nal-------------------��ǰ֡nal��
    int nal_size[STREAM_MAX_NAL_NUM];	//nal-------------------ÿ��nal�ĳ���
    void *userdata;
	int (*userfillfun)(void *_handle, int size, char *buf);
}stream_writeFrame_t;

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/* --------------------- �䳤����Ƶ֡�ڴ���� ---------------------- */
/*
��������:
1  һ����ͨ�� ���Էֶ����ͨ����Ŀǰ����ͨ��  ��ͨ�� ֮��
2  ��Ƶ��ͨ�� ��ͨ��(0):�߷ֱ���ͼ��   ��ͨ��(1):�ͷֱ���ͼ��
3  ��Ƶ������ͨ����Ϊ��Ƶ���뻺����  ��ͨ����Ϊ��Ƶ���뻺����
4 ��0ͨ�� ��Ϊ��Ƶ��ʹ�ã���1ͨ����Ϊ��Ƶ��ʹ��
*/

/*****************************************************************************
 �� �� ��  : sdk_stream_init
 ��������  : ��ʼ�����⣬����������·��
 �������  : const stream_manage_t *p_stream_manage  
 �������  : ��
 �� �� ֵ  : extern
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int sdk_stream_init(const stream_manage_t *p_stream_manage);
extern int sdk_stream_destroy();

//Note:
// ch=1 ----- VIDEO 
// ch=0 ----- AUDIO 
/*****************************************************************************
 �� �� ��  : sdk_stream_Open
 ��������  : ��Ԥ¼��ͨ��
 �������  : int ch      ��ͨ���� 
             int ch_type  0 ������  1 ������
             int pre_sec Ԥ¼�����������10��
 �������  : ��
 �� �� ֵ  : ������ͨ�����
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern ST_HDL  sdk_stream_Open_Pre(int ch,int ch_type,int pre_sec);


/*****************************************************************************
 �� �� ��  : sdk_stream_Open
 ��������  : ����ͨ��
 �������  : int ch      ��ͨ���� 
             int ch_type  0 ������  1 ������
 �������  : ��
 �� �� ֵ  : ������ͨ�����
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern ST_HDL sdk_stream_Open(int ch,int ch_type);//CH=1 ��ʾVIDEO ch=0��ʾAUDIO 
extern int sdk_stream_Close(ST_HDL  handle);


/*****************************************************************************
 �� �� ��  : sdk_stream_ReadOneFrame
 ��������  : ˳���ȡ����һ֡����
 �������  : ST_HDL  handle   :�����
 �������  : ��
 �� �� ֵ  : extern
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern char *sdk_stream_ReadOneFrame(ST_HDL  handle);


/*****************************************************************************
 �� �� ��  : sdk_stream_ReadNewFrame
 ��������  : ��ȡ��ǰ�������µ�һ֡����
 �������  : ST_HDL  handle  
 �������  : ��
 �� �� ֵ  : extern
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern char *sdk_stream_ReadNewFrame(ST_HDL  handle);


/*****************************************************************************
 �� �� ��  : sdk_stream_WriteFrameCB
 ��������  : ����ͨ��д���ݵĻص�����
 �������  : stream_writeFrame_t *writeFrame  
 �������  : ��
 �� �� ֵ  : extern
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int sdk_stream_WriteFrameCB(stream_writeFrame_t *writeFrame);



/*****************************************************************************
 �� �� ��  : sdk_stream_WriteOneFrame
 ��������  : ������д����
 �������  : int ch   ����ͨ����        
             int ch_type   0:������  1:������   
             frame_t * frame  
 �������  : ��
 �� �� ֵ  : extern
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��5��22��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
extern int sdk_stream_WriteOneFrame(int ch,int ch_type, frame_t * frame);
extern int sdk_stream_WriteOneFrameEx(int ch, int ch_type, frame_head_t *frame_head,char *frame_addr);



/* --------------------- ���������ڴ���� ---------------------- */

extern POOL_HDL sdk_pool_init(int data_len, int data_num);
extern void sdk_pool_uninit(POOL_HDL handle);
extern int sdk_event_wait(POOL_HDL handle);
extern int sdk_event_broadcast(POOL_HDL handle);
extern int sdk_event_send_to_pool(POOL_HDL handle,void *data);
extern EV_HDL sdk_get_event_handle(POOL_HDL handle);
extern int sdk_get_one_event(POOL_HDL handle,EV_HDL event,void **data);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __STREAMLIB_H__ */
