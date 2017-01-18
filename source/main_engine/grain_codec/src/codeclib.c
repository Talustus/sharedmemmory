#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "gmlib.h"
#include "video/video.h"
#include "sdk_struct.h"
#include "log.h"
/*
*�⼶ȫ�ֱ���
*/

//�¼��ص�����
EventCallback		mEventCallback = NULL; //�¼��ص�
SendstreamCallback	mVideoStreamCB = NULL;  //��Ƶ�ص�
SendstreamCallback  mAudioStreamCB = NULL;  //��Ƶ�ص�
SendstreamCallback	mPicStreamCB = NULL;   //ץ��ͼƬ�ص� ��ʱû��ʹ��



sdk_a_frame_info_t  g_audio_info=
{
    .encode_type =SDK_AUDIO_FORMAT_G711A,        //�������� 1: G711A SDK_AUDIO_CODEC_FORMAT_E
    .samples = SDK_AUDIO_SAMPLE_R8K,            //����Ƶ�� 0: 8000, SDK_AUDIO_SAMPLE_RATE_E
    .bits  = SDK_AUDIO_SAMPLE_WIDTH_16,               //λ��    SDK_AUDIO_SAMPLE_WIDTH_E
    .channels = 1,           //ͨ����

};

//��ȡ����������������
int  sdk_av_get_sys_capability()
{
    return 0;
}
//��ȡ����ͨ���ı�����Ϣ
int sdk_av_get_video_info(int video_ch,sdk_v_frame_info_t *video_info)
{
    return 0;
}
//��ȡ����ͨ������Ƶ��Ϣ
int sdk_av_get_audio_info(int audio_ch,sdk_a_frame_info_t	*dudio_info)
{
    return 0;
}

int sdk_av_init_sys_callback(EventCallback EventCB,
                             SendstreamCallback	VideoStreamCB,
                             SendstreamCallback	AudioStreamCB,
                             SendstreamCallback	PicStreamCB)
{
    int ret = -1 ;
    if(EventCB )
    {
        mEventCallback = EventCB;
        ret = 0 ;
    }
    if(VideoStreamCB)
    {
        mVideoStreamCB =  VideoStreamCB;
        ret = 0 ;
    }
    if(AudioStreamCB)
    {
        mAudioStreamCB =  AudioStreamCB;
        ret = 0 ;
    }
    if(PicStreamCB)
    {
        mPicStreamCB =  PicStreamCB;
    }
    return 0;
}

int sdk_av_sys_init(int sensor_type,int total_sub_ch,sdk_encode_t *pencode_info)
{
	
	warning("GRAIN_CODEC ------------------------->V-0.0.1\n");
    if(!pencode_info)
    {
        error("pencode_info == NULL \n");
        assert(0); //ֱ���ж�
        return -1;

    }
    int sub_ch;
    int max_ch = (total_sub_ch > MAX_VIDEO_STREAM_NUM)?MAX_VIDEO_STREAM_NUM : total_sub_ch;
    sdk_av_enc_t *pav_info = NULL;
    sdk_vda_codec_cfg_t motion_cfg;
    
    video_sys_init();
	warning("GRAIN_CODEC -------------------------0000max_ch:%d \n",max_ch);
    for(sub_ch = 0 ; sub_ch < max_ch ; sub_ch++)
    {
        pav_info = &pencode_info->av_enc_info[sub_ch];
        video_enc_init(sub_ch, pav_info);
    }
	sync();
	warning("GRAIN_CODEC -------------------------1111111111111 \n");
	//��ʱ������Ƶ
    audio_enc_init(1, &pencode_info->av_enc_info[0]);//��ʼ����Ƶ����
	audio_dec_init(1, &pencode_info->av_enc_info[0]);//��ʼ����Ƶ����

    return 0;
}

int sdk_av_sys_uninit()
{
	printf("sdk_av_sys_uninit   1111\n");
    video_enc_uninit(0);
	
	printf("sdk_av_sys_uninit 22222\n");
    video_enc_uninit(1);
	printf("sdk_av_sys_uninit   33333\n");

    video_enc_uninit(2);

	printf("sdk_av_sys_uninit   44444\n");
    video_uninit_osd(3);

	printf("sdk_av_sys_uninit 55555\n");
    video_uninit_motion(1);

	printf("sdk_av_sys_uninit   66666\n");
    video_snap_unint(0);
	printf("sdk_av_sys_uninit   77777\n");

    audio_enc_uninit();
	printf("sdk_av_sys_uninit    888888\n");
    video_sys_uninit();
	printf("sdk_av_sys_uninit 9999999\n");

    return 0;
}

//�������з���
int sdk_av_server_start()
{
    video_server_start();   //�������

	printf("audio thread start now\n");
	audio_server_start();		//��Ƶ
	audio_dec_start();
	
    video_osd_server_start(); //OSD��ʾ
    video_motion_server_start(); //�ƶ����
    //audio_detection_server_start();//�������
	video_snap_init(0,NULL);
	//ICUTģʽת���߳�����
	//I_CUT_MONITER();

	//wch add
	isp_config_start();

	hw_control_init();
    return 0;
}


int sdk_av_server_stop()
{
	printf("sdk_av_server_stop   111\n");
    video_osd_server_stop();
	printf("sdk_av_server_stop   222\n");
    video_motion_server_stop();
	printf("sdk_av_server_stop   333\n");
    video_server_stop();
	printf("sdk_av_server_stop   4444\n");
    audio_server_stop();
	printf("sdk_av_server_stop   55555\n");
	sdk_av_sys_uninit();
	printf("sdk_av_server_stop   66666\n");
    return 0;
}

//�������
int sdk_av_set_encode_param(int ch,sdk_av_enc_t *pav_enc)
{
    return video_set_enc_attr(ch,pav_enc);
}

//�ƶ��������
int sdk_av_set_motion_param(int ch,sdk_vda_codec_cfg_t *motion_cfg)
{
    return  video_set_motion_attr(ch,motion_cfg);
}

//osd ����
int sdk_av_set_osd_param(int ch,sdk_osd_cfg_t *osd_cfg)
{
    return video_set_osd_attr(ch, osd_cfg);
}

int sdk_av_set_attr_param(int ch,sdk_image_attr_t *attr_cfg)
{
	return video_set_attr_param(ch, attr_cfg);
}
int sdk_av_set_record_osd(int flag)
{
	return video_set_osd_recod_flag(flag);
}
//����osd����ʱ��
int sdk_set_time_zone(int time_zone)
{
	return video_set_osd_time_zone(time_zone);
}


//����Ȥ����
int sdk_av_set_roi_param(int ch,sdk_roi_cfg_t *roi_cfg)
{
    return video_set_roi_attr(ch,roi_cfg );
}

//3D����
int sdk_av_set_3di_param(int ch,sdk_3di_cfg_t * p3di_cfg)
{
    return video_set_3di_attr(ch,  p3di_cfg);
}

//ǿ��I֡
int sdk_av_request_i_frame(int ch)
{
    return video_force_i_frame(ch);
}

//ץ�� �������� ������ܻ������ºϼ�һ�� ��Ȼ̫����
int sdk_av_snap(int ch,sdk_snap_info_t *snap_info,char *path)
{
    return video_snap_process(ch,snap_info,path);
    //return 0;
}

extern av_info_t	g_av_info;
inline int sdk_audio_play(int audio_type,const char *audio_data,int date_len)
{
	int ret;
	int bfcount;
	static char dec_buf[1024] = {0};
	memset(dec_buf, 0, 1024);

	bfcount = G711ADec((unsigned char*)audio_data, (short *)dec_buf,date_len);
	gm_dec_multi_bitstream_t multi_bs[1];


	multi_bs[0].bindfd = g_av_info.audio_info[1].audio_fd;
	multi_bs[0].bs_buf = dec_buf;
	multi_bs[0].bs_buf_len = bfcount;

	if ((ret = gm_send_multi_bitstreams(multi_bs, 1, 500)) < 0)
	{
		warning("<send bitstream fail(%d)!>\n", ret);
		return -1;
	}
	//warning("audio_playback .....................> end	\n");
	return 0;
}

//����ת
int sdk_av_mirror_param(int ch,sdk_mirror_flip_cfg_t *ongoing, sdk_mirror_flip_cfg_t *desired)
{
	int h_rotation_enable = (ongoing->mirror) ^ (desired->mirror);
	int v_rotation_enable = (ongoing->flip) ^ (desired->flip);

	warning("h_rotation_enable=%d, v_rotation_enable=%d\n", h_rotation_enable, v_rotation_enable);
	return av_mirror_param(ch, h_rotation_enable, v_rotation_enable);
}


//��Դ���� 0:60 hz    1:50hz
int sdk_sensor_powerhz_param(int power_hz)
{
	 return sensor_power_hz_param(power_hz);
}

int sdk_init_gpio()
{	
	return init_gpio();
}

int sdk_init_ISP()
{
	return ov9715_init();
}

int sdk_gpioEx_defpin(int gpiopin, int direction) //set dir about gpio pin
{
	return gpioEx_defpin(gpiopin, direction);
}

void sdk_gpioEx_set(int gpiopin) //set 1 
{
	gpioEx_set(gpiopin);
}

void sdk_gpioEx_clear(int gpiopin)//set 0
{
	gpioEx_clear(gpiopin);
}

int sdk_gpioEx_read(int gpiopin)//read gpio pin value
{
	return gpioEx_read(gpiopin);
}

//ǿ�ƹرպ����
int g_force_close_infrared = 0;
int sdk_set_infrared_status(int infrared_status )
{
	g_force_close_infrared = (infrared_status == 0 ? 0 :1);
 	return 0;
}
//end
int sdk_get_icut_delay()
{	
 	return get_icut_delay();
}





