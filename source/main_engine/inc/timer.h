


#ifndef __TIMER_H__
#define __TIMRE_H__

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


// ���º궨��Ϊtimer_ioctrl()��cmd����
typedef enum {
  	TIMER_CMD_GETTMCOUNT = 0x00 		// ��ȡ��ǰ�����ļ���������
  ,	TIMER_CMD_GETTMPASST 				// ��ȡ��ǰ��ʱ���Ѿ�������ʱ��(ms)
  ,	TIMER_CMD_GETTMREACH 				// ��ȡ��ǰ��ʱ���뵽���ʱ��(ms)
  , TIMER_CMD_RESET_STARTTIME  			// �������õ�ǰ��ʱ���Ŀ�ʼʱ��(ms)
  ,	TIMER_CMD_BUIT
} TIMER_CMD;

typedef int (*timer_cb)(void *param);

/*************************************************************
* �������ܣ���ʼ��һ����ʱ��(����ģ���ʼ��һ�μ���)
* �����������
* �����������
* ����ֵ  ��>0-�ɹ�; <0-ʧ��
*************************************************************/
int timer_init();


/*************************************************************
* �������ܣ�����һ����ʱ��
* ���������once:     -1:ѭ����ʱ��N(N>0):����N�κ�ֹͣ
            interval: ��ʱ��ʱ��������λ������
            func:     ��ʱ���ص�����
            param:�ص���������
* �����������
* ����ֵ  ��>0-�ɹ�����ʾ��ʱ�������<=0-�������
*************************************************************/
int timer_start(int run_time, int interval, char *cb_func_name, timer_cb func, void *param);


/*************************************************************
* �������ܣ�TIMER����
* ���������handle: TIMER�����
            cmd: ���
            channel: ͨ���ţ��˴���Ч
            param�����������
            size_of_param: param���ȣ��ر����GET����ʱ���������Ӧ���жϻ������Ƿ��㹻
* ���������param�����������
* ����ֵ  ��>=0-�ɹ���<0-�������
*************************************************************/
int timer_ioctrl(int handle, int cmd, int channel, void* param, int size_of_param);


/*************************************************************
* �������ܣ�ֹͣһ����ʱ��
* ���������handle: ��ʱ�����
* �����������
* ����ֵ  ��>=0-�ɹ���<0-ʧ��
*************************************************************/
int timer_stop(int handle);

#endif // __TIMER_H__

