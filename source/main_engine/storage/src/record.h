

#ifndef __RECORD_H__
#define __RECORD_H__

#include	<semaphore.h>
#include	<pthread.h>

typedef struct _record_work_t_
{
	pthread_mutex_t record_normal_mutex;  //����¼����
	pthread_mutex_t record_event_mutex;	  //�¼�¼����
	pthread_t	g_record_thread_id;		  //����¼���߳�
	pthread_t   g_event_thread_id;

	char g_normal_status;   		      // 1: ��ʾ����¼��0: ֹͣ����¼��
 	char g_event_status ;  		          // 1 : ��ʾʱ��¼�� 0 : ֹͣ�¼�¼��
	int g_event_duration;			      // ��¼�¼�¼��ʱ��
	int g_normal_duration;		          // ��¼����¼��ʱ�� 
	unsigned char  record_time_zone;				  //ntpʱ������
	unsigned char  record_time_zone_pre;				  //��¼֮ǰ��ʱ��

	SDK_RECORD_TYPE_E g_current_record_type;//¼������
}record_work_t;

extern record_work_t g_record_work_t;



typedef struct _record_manage_t
{
    
	int	channel;		
	
	int	record_type; // ¼������
	int	record_switch_time; //��λ����	 ¼��ʱ��
	int	record_ctl_flag; //¼����Ʊ�־λ start stop  write create 
	void *record_handle;
            
    //int (*send_msgToMainCB)(struct st_msg_s* msg);
   // int (*getBlockStar)();
}record_manage_t;


int st_record_initRecord();
int st_record_deinitRecord();

int st_record_startRecordThread();
int st_record_stopRecordThread();

int st_record_startRecordStream();
int st_record_stopRecordStream();

#endif	//__RECORD_H__

