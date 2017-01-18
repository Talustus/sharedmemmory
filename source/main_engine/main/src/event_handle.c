/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, bingchuan

 ******************************************************************************
  �� �� ��   : event_handle.c
  �� �� ��   : v1.0
  ��    ��   : bingchuan
  ��������   : 2015��6��1��
  ��������   : �����жϲ���ʱ�䣬�Լ��¼�������������Ӧ����
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��6��1��
    ��    ��   : bingchuan
    �޸�����   : �����ļ�

******************************************************************************/
#include "sdk_struct.h"

#include "log.h"

#define 	DETECT_INTERVAL_TIME    5   //������Сʱ����Ϊ5��

extern RECORD_STATUS record_status;


//����ĺ�����������ʱ����жϵ�


//��962 ������ ��������Ҳ�кܶ������  �����̸�  �𾯵���Ϣ  ��Ҫ�����ж�
//Ŀǰͳһ��Ϊ���뱨��ʹ��


//�ж��ǲ����ڲ���ʱ�����
static int _sched_calc(time_t now
                       , int year, int month, int day
                       , sdk_day_time_t *_sched)
{
    int detect_flag;
    time_t start, end;
    detect_flag = 0;


    if(_sched->start_hour == _sched->stop_hour
            && _sched->start_min == _sched->stop_min)
    {
        return detect_flag;
    }
    start = os_make_time(year, month, day
                         ,_sched->start_hour
                         ,_sched->start_min
                         ,0);

    end  = os_make_time(year, month, day
                        ,_sched->stop_hour
                        ,_sched->stop_min
                        ,59);
    if(start < end)
    {
        if(now >= start && now <= end)
        {
            detect_flag=1;
        }
    }

    return detect_flag;
}

/*****************************************************************************
 �� �� ��  : event_sched_motion
 ��������  : ����Ƿ��ڲ���ʱ�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : 0:��ʾ�ڼ�ⷶΧ��  -1:��ʾ���ܲ���
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��6��2��
    ��    ��   : bingchuan
    �޸�����   : �����ɺ���

*****************************************************************************/
static  int event_sched_check(sdk_sched_time_t *psched_time, time_t *prev_occur_time)
{
    uint32_t 		in_sched_flags = 0;
    uint32_t        def_signal_value = 0;                  //Ĭ���ź�ֵ
    uint32_t        interval_time   = DETECT_INTERVAL_TIME;//���Ʊ�����Сֹͣʱ��
    int time_seg_num = 0;
    unsigned int weekday, year, month, day;

    sdk_sched_time_t sched_time = *psched_time;

    if(!sched_time.enable)
        return -1;
	info("000000000000000000\n");
    interval_time  = (sched_time.interval_time >=  DETECT_INTERVAL_TIME)? sched_time.interval_time : DETECT_INTERVAL_TIME;    //���Ʊ�����Сֹͣʱ��

    time_t now_time = time(NULL);

    //ʱ����û���
    if(now_time - *prev_occur_time  <  interval_time)
        return -1;
	
	info("111111111111111111\n");
    //���ݲ�����ʽ�жϲ���ʱ���  ĿǰĬ���ǰ����ܲ���
    //if(sched_time.plan_flag == 1)

    os_local_time(now_time, &year, &month, &day, NULL, NULL, NULL, &weekday);
    info("======= %04d-%02d-%02d-%02d \n",year, month, day, weekday);

    for (time_seg_num=0; time_seg_num <4; time_seg_num++)
    {
        if (sched_time.week_sched.week_sched_info[weekday][time_seg_num].enable)
        {
            in_sched_flags = _sched_calc(now_time, year, month, day, &sched_time.week_sched.week_sched_info[weekday][time_seg_num]);
            if (in_sched_flags)
                break;
        }
    }
	info("22222222222222222\n");
    if(1 == in_sched_flags)
    {
        *prev_occur_time = now_time;
		
		info("333333333333333333333333\n");
        return 0;
    }
    else
    {
		info("4444444444444444444444444\n");
        return -1;
    }

}
#if 0
//#include "tutk.h"
//////////////////////////0708
typedef struct tag_BUZZER_PRA
{
	int  buzzer_flag; // buzzer_status ----1:sound 0:off
    int	 buzzer_time;  //  0 �� 120 ��
    int	 buzzer_event;  //  0 �� 120 ��

} REMOTE_BUZZER_PRA;


///////////////////////
#endif
#include "tutk.h"
extern LED_BUZZER_INFO  led_buzzer_info; 

int pir_event_handle_motion()
{
    sdk_motion_cfg_t motion_cfg;
    sdk_alarm_handle_t alarm_handle;                            //��������
    memset(&motion_cfg,0,sizeof(sdk_motion_cfg_t));
    memset(&alarm_handle,0,sizeof(sdk_alarm_handle_t));
    adapt_param_get_motion_cfg(0, &motion_cfg);

	printf("%d\n",motion_cfg.alarm_handle.record_enable);
	printf("beep_enable=%d beep_time=%d\n",motion_cfg.alarm_handle.beep_enable,motion_cfg.alarm_handle.beep_time);

    //��������  ��������ʱ
    alarm_handle = motion_cfg.alarm_handle;
    //¼��
    if( alarm_handle.record_enable)
    {
		record_status.record_alarm_triger |= 1; //���ñ���¼��

    }

    //�������
    alarm_handle.alarm_out_enable = 1;

    //��������
    alarm_handle.beep_enable = 1;
	//����LED BUZZER
	 pthread_mutex_lock(&led_buzzer_info.led_buzzer_lock); 
	led_buzzer_info.led_status 		|= (1 << LED_ALARM_TRIGGER);
	led_buzzer_info.buzzer_status 	|= (1 <<BUZZER_ENABLE_BEEP);
	 pthread_mutex_unlock(&led_buzzer_info.led_buzzer_lock); 
	
	//ץ��ͼƬ
	//�����ʼ�
    // ����PTZ

}

//�ƶ����
int event_handle_motion(sdk_event_t *event_obj)
{
    sdk_motion_cfg_t motion_cfg;
    static time_t prev_occur_time = 0; //��¼��һ�η����¼���ʱ��
    sdk_alarm_handle_t alarm_handle;                            //��������

    memset(&motion_cfg,0,sizeof(sdk_motion_cfg_t));
    memset(&alarm_handle,0,sizeof(sdk_alarm_handle_t));

    adapt_param_get_motion_cfg(0, &motion_cfg);
	//////////////////////////////////////////
	#if 0
	printf("%d\n",motion_cfg.alarm_handle.email_enable);
	printf("%d\n",motion_cfg.alarm_handle.record_enable);
	printf("%d\n",motion_cfg.alarm_handle.snap_enable);
	printf("%d\n",motion_cfg.alarm_handle.alarm_out_time);
	printf("%d\n",motion_cfg.alarm_handle.beep_enable);
	printf("%d\n",motion_cfg.alarm_handle.beep_time);
	printf("%d\n",motion_cfg.sched_time.enable);
	printf("%d\n",motion_cfg.sched_time.plan_flag);
	printf("%d\n",motion_cfg.sched_time.interval_time);
	printf("%d\n",motion_cfg.codec_vda_cfg.area[0].x);
	printf("%d\n",motion_cfg.codec_vda_cfg.area[0].y);
	printf("%d\n",motion_cfg.codec_vda_cfg.area[0].width);
	printf("%d\n",motion_cfg.codec_vda_cfg.area[0].height);
	printf("%d\n",motion_cfg.codec_vda_cfg.enable);
	printf("%d\n",motion_cfg.codec_vda_cfg.mask);
	printf("%d\n",motion_cfg.codec_vda_cfg.mode);
	printf("%d\n",motion_cfg.codec_vda_cfg.res);
	printf("%d\n",motion_cfg.codec_vda_cfg.sensitive);
	#endif
	//////////////////////////////////////////

    if(0 == motion_cfg.codec_vda_cfg.enable || 0 >  event_sched_check(&motion_cfg.sched_time,&prev_occur_time))
    {
		info("motion_cfg.codec_vda_cfg.enable=%d\n",motion_cfg.codec_vda_cfg.enable);
        info("motion comming ,but not pass!!! \n");
        return -1;
    }
    //��������  ��������ʱ
    alarm_handle = motion_cfg.alarm_handle;
    //¼��
    #if 1
    if( alarm_handle.record_enable)
    {
    	//if(record_status.record_last_status	== RECORD_ALARM)
    	if(record_status.record_flags == RECORD_ALARM)
    	{
    		pthread_mutex_lock(&record_status.record_lock);
			record_status.record_alarm_triger |= 1; //���ñ���¼��
			pthread_mutex_unlock(&record_status.record_lock);
    	}

    }
	#endif

#if 1
    //�������
    alarm_handle.alarm_out_enable = 1;
	
	printf("========alarm_handle.alarm_out_enable11111\n");
    if(alarm_handle.alarm_out_enable)
    {
    }
    //��������
    alarm_handle.beep_enable = 1;

	//����LED BUZZER
	 pthread_mutex_lock(&led_buzzer_info.led_buzzer_lock); 
	led_buzzer_info.led_status 		|= (1 << LED_ALARM_TRIGGER);
	led_buzzer_info.buzzer_status 	|= (1 << BUZZER_ENABLE_BEEP);
	 pthread_mutex_unlock(&led_buzzer_info.led_buzzer_lock); 
	
	//ץ��ͼƬ
	if(alarm_handle.snap_enable)
	{
		#if 0
		sdk_snap_info_t snap_info;
		snap_info.width = 1280;
		snap_info.height = 720;
		sdk_av_snap(0,&snap_info,"/mnt/nfs/motion_event.bmp");
		#endif
	}
	
	//�����ʼ�
	if(alarm_handle.email_enable)
	{

	}
    // ����PTZ
    #if 0
    if (alarm_handle.ptz_enable)
    {

    }
	#endif
#endif
}

/**************************************************/

static event_sched_alarm_in()
{


}

/****************************/
//�¼�����

//�澯����
int event_handle_alarm_in(sdk_event_t *event_obj)
{


}

//����������AUDIOALERT
int event_handle_audio_alert(sdk_event_t *event_obj)
{


}



