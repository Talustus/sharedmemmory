#ifndef __GRD_AVI_API_H__
#define __GRD_AVI_API_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <string.h>
#include "avi_typedef.h"
#include "avi_common.h"



/**********************************************************************
�������������SD���洢�ռ䣬�����ļ���дAVIͷ��Ϣ
��ڲ�����AviFile *avi_file, AVI�ļ��Ŀ��ƾ��
          AviInitParam *param, ����Ĳ�����Ϣ
����ֵ�� 0: ��������
        <0: ���󷵻�         
**********************************************************************/
extern int avi_record_open(AviFile *avi_file);


/**********************************************************************
������������AVI�ļ���д��һ֡����
��ڲ�����AviFile *avi_file:  AVI�ļ��Ŀ��ƾ��
          AviInitParam *param, ����Ĳ�����Ϣ
          unsigned char *data:  д������ݵĵ�ַ
          int length: д������ݵĳ���
          int intra: 1,��ʾΪ�ؼ�������;0��ʾ��Ϊ�ؼ�������
          
����ֵ�� 0: ��������
        <0: ���󷵻�
**********************************************************************/
extern int avi_record_write(AviFile *avi_file,
                                char *data, 
                                int length, 
                                int intra,
                                struct timeval *pTimeval);


/**********************************************************************
����������������AVI�ļ�Ϊ���ո�ʽ�����ر��ļ����ͷ��ڴ�
��ڲ�����AviFile *avi_file:  AVI�ļ��Ŀ��ƾ��         
����ֵ�� 0: ��������
        <0: ���󷵻�       
**********************************************************************/
extern  int avi_record_close(AviFile *avi_file);


/**********************************************************************
�طŲ��ֽӿں���ʹ��������
1������ avi_pb_open ��Ҫ���ŵ�avi�ļ�,�ļ���Ϊfile_name��
2������ avi_pb_seek_by_percent ���� avi_pb_seek_by_time ��λ������ʼλ�ã�
   �����ʹ����2����������Ĭ�ϴ�ͷ��ʼ���š�
3������ set_frame_info ȥ���� avi֡���ݿ��ƾ�� AviFrameInfo
4������ avi_pb_set_speed ȥ���ò����ٶȣ���ʹ���򲥷��ٶ�Ĭ��Ϊ1���١�
5��ѭ������ avi_pb_get_frame ȥ�õ�ÿһ֡���ݡ�����ֵΪ1003�򲥷ŵ���ĩβ��
6������ avi_pb_close ������
ע��: ������һ���߳̽��лط�ʱ���Իط��ٶȵĲ���(avi_pb_set_speed)��
����һ���߳���(һ�������߳�)��2���̶߳� avi_pb_speed �Ĳ����ǻ���ġ�
**********************************************************************/
/**********************************************************************
����������ͨ����AVI�ļ���Ϣ���õ����Ŀ��ƾ���Ͳ�����Ϣ
��ڲ�����char *file_name: Ҫ�򿪵��ļ�·����    
          AviFile *avi_file: avi�ļ��Ŀ��ƾ��
          AviInitParam *param: avi�ļ��еĲ�����Ϣ
����ֵ��  <0: ����
           0: ����        
**********************************************************************/
extern int avi_pb_open(char *file_path, AviPBHandle *pPBHandle);

/**********************************************************************
����������ͨ��AVI�ļ��Ŀ��ƾ���Ͳ�����Ϣ, ������ðٷֱ�λ���ǵڼ�֡
          ���ݣ������µ� AviFrameInfo �� no ������
��ڲ�����AviFile *avi_file: avi�ļ��Ŀ��ƾ��
          AviInitParam *param: avi�ļ��еĲ�����Ϣ
          int percent: �ٷֱȣ���25%��percent = 25
          AviFrameInfo *p_frame: avi�ļ���֡���ݵĿ��ƾ��
����ֵ��  <0: ����
           0: ����        
**********************************************************************/
extern int avi_pb_seek_by_percent(AviFile *avi_file, AviInitParam *param, int percent, AviPBHandle *pPBHandle);

/**********************************************************************
����������ͨ��AVI�ļ��Ŀ��ƾ���Ͳ�����Ϣ, ������ö�λʱ���ǵڼ�֡
          ���ݣ������µ� AviFrameInfo �� no ������
��ڲ�����AviFile *avi_file: avi�ļ��Ŀ��ƾ��
          AviInitParam *param: avi�ļ��еĲ�����Ϣ
          char *seek_time: ͨ��ʱ���ڽ������ж�λ
          AviFrameInfo *p_frame: avi�ļ���֡���ݵĿ��ƾ��
����ֵ��  <0: ����
           0: ����        
**********************************************************************/
extern int avi_pb_seek_by_time(AviFile *avi_file, AviInitParam *param, char *seek_time, AviPBHandle *pPBHandle);

/**********************************************************************
����������ͨ��AVI�ļ��Ŀ��ƾ���Ͳ�����Ϣ��������֡���ݵĿ��ƾ��
��ڲ�����AviFile *avi_file: avi�ļ��Ŀ��ƾ��
          AviInitParam *param: avi�ļ��еĲ�����Ϣ
          AviFrameInfo *p_frame: avi�ļ���֡���ݵĿ��ƾ��
����ֵ��  ��        
**********************************************************************/
//extern void set_frame_info(AviFile *avi_file, AviInitParam *param, AviFrameInfo *p_frame);

/**********************************************************************
������������ӡ��avi�ļ���֡�������ڵ�avi�ļ��е���Ϣ
��ڲ�����AviPBHandle *pPBHandle: avi�ļ���֡���ݵĿ��ƾ��
����ֵ��  ��        
**********************************************************************/
extern void print_pb_handle(AviPBHandle *pPBHandle);

/**********************************************************************
������������ӡ��avi�ļ���֡���ݵ���Ϣ
��ڲ�����AviPBHandle *pPBHandle: avi�ļ���֡���ݵĿ��ƾ��
����ֵ��  ��        
**********************************************************************/
extern void print_frame_node(AviPBHandle *pPBHandle);

/**********************************************************************
����������ͨ��AVI�ļ��Ŀ��ƾ���Ͳ�����Ϣ, ������ö�λʱ���ǵڼ�֡
          ���ݣ������µ� AviFrameInfo �� no ������
��ڲ�����AviFrameInfo *p_frame: avi�ļ���֡���ݵĿ��ƾ��
          char *pBuff: ��û�����λ��ָ���������
          int *pSize: �õ���֡���ݵĴ�С
����ֵ��  <0: ����
           0: ����  
          GRD_NET_NOMOREFILE: ���Ž���(ֵΪ1003) 
**********************************************************************/
extern int avi_pb_get_frame(AviPBHandle *pPBHandle, char *pBuff, int *pSize);

/**********************************************************************
��������������avi�ļ����ŵ��ٶȣ�Ŀǰֻ֧�ֿ��
��ڲ�����int speed: �����ٶȣ��� 1,2,4,8,16,32
����ֵ��  <0: ����
           0: ����        
**********************************************************************/
extern int avi_pb_set_speed(int speed);

/**********************************************************************
�����������ر�֡���ݵĿ��ƾ��
��ڲ�����AviFrameInfo *p_frame: avi�ļ���һ֡���ݵĿ��ƾ��
����ֵ��  <0: ����
           0: ����        
**********************************************************************/
extern int avi_pb_close(AviPBHandle *pPBHandle);


/**********************************************************************
��������������6����ֻ��԰��նԽ�      
**********************************************************************/
extern int avi_pb_start(void);
extern int avi_pb_restart(AviPBHandle *pPBHandle);
extern int avi_pb_pause(void);
extern int avi_pb_get_pos(AviPBHandle *pPBHandle);
extern int avi_pb_set_pos(AviPBHandle *pPBHandle, int *pTimePos);
extern int avi_pb_get_time(AviPBHandle *pPBHandle,  struct tm *p_nowtime);
extern int avi_get_frame_loop(AviPBHandle *pPBHandle, char *p_buff, int *p_size);


/**********************************************************************
�����������޸�sd�������е�δ¼��ɵ�avi�ļ�        
��ڲ�������          
����ֵ��  ��       
**********************************************************************/
extern void fix_all_avi_file(void);


/**********************************************************************
�������������ݲ�����ӡ��������ʾ.
��ڲ�����int ret: avi_record_open,avi_record_write,avi_record_close
                   �ķ���ֵ��Ϊ����
����ֵ����
**********************************************************************/
//extern  void avi_print_err(int ret);

#ifdef __cplusplus
}
#endif

#endif /* __GRD_AVI_API_H__ */

