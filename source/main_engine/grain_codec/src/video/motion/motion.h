#ifndef __MOTION_H__
#define __MOTION_H__



//�����ƶ������Ϣ
typedef struct _motion_handle_s
{
	int motion_init ; //��ʼ����־
	int motion_enable; //���ʹ��
	int motion_fd; //���ò����ľ��
	
	int max_width; //�ƶ����Ŀ�
	int max_height;//�ƶ����ĸ�
	
	pthread_t  motion_thread_id;

}motion_handle_t;



#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */





#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif
