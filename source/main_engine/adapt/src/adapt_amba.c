/*
 * =====================================================================================
 *
 *       Filename:  adapt_grain.c
 *
 *    Description:  ambarella����������
 *
 *        Version:  1.0
 *        Created:  2015��01��31�� 00ʱ15��05��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bingchuan
 *        Company:
 *
 * =====================================================================================
 */
 #if 0
#ifdef _AMBARELA_

#include "wrapper.h"
#include "log.h"
#include "adapt.h"

#ifdef _NO_CODEC
#define sdk_codec_register(arg...)      (0)
#define sdk_codec_init(arg...)          (0)
#define sdk_codec_dispatch_msg(arg...)  (0)
#define sdk_codec_getChMdStat(arg...)   (0)
#define sdk_codec_req_snap(arg...)      (0)
#define sdk_codec_getChVloss(arg...)    (0)
#define sdk_codec_forceIFrame(arg...)   (0)
#define sdk_codec_setAudioAo(arg...)	(0)
#endif
#if 0
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

#endif
//������ϵͳ��ʼ��
int adapt_av_init(EventCallback EventCB,
                  SendstreamCallback	VideoStreamCB,
                  SendstreamCallback	AudioStreamCB,
                  SendstreamCallback	PicStreamCB)
{
    int ret = -1;
    sdk_sys_cfg_t sys_cfg;
    sdk_encode_t encode_info;
    warning("1111111111111111111 \n");
    memset(&sys_cfg, 0, sizeof(sdk_sys_cfg_t));
    adapt_param_get_sys_cfg(&sys_cfg);
    warning("2222222222222 \n");

    //����ע��ص����� ʵ����Ƶ��Ƶ��  �¼��Ĵ���
    sdk_av_init_sys_callback( EventCB,
                              VideoStreamCB,
                              AudioStreamCB,
                              PicStreamCB);

    sdk_av_enc_t av_enc[4];
    memset(&av_enc,0,sizeof(sdk_av_enc_t));
	//������Ӧ���޸�ȫ�ֱ��� av_enc  �ص��� bitrate  �� frame_rate
 
    av_enc[0].resolution =SDK_VIDEO_RESOLUTION_1080p;     //SDK_VIDEO_RESOLUTION_E
    av_enc[0].bitrate_type = SDK_BR_CBR;   //��������  SDK_VIDEO_BR_TYPE_E
    av_enc[0].pic_quilty = 0;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    av_enc[0].frame_rate = 25;     //����֡��1-25(PAL)/30
    av_enc[0].gop = 25;            //I ֡���1-200
    av_enc[0].video_type = 0;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    av_enc[0].audio_enc = 0;      //���ӱ����ʽ0:G711A
    av_enc[0].mix_type = 1;       //����Ƶ��: 0, ��Ƶ��: 1.
    av_enc[0].bitrate = 2048;       //�������� 32kbps-16000kbps
    av_enc[0].level = 0;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    av_enc[0].h264_ref_mod = 0;   //h264����֡�ο�ģʽ

    av_enc[1].resolution =SDK_VIDEO_RESOLUTION_720p;     //SDK_VIDEO_RESOLUTION_E
    av_enc[1].bitrate_type = SDK_BR_CBR;   //��������  SDK_VIDEO_BR_TYPE_E
    av_enc[1].pic_quilty = 0;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    av_enc[1].frame_rate = 25;     //����֡��1-25(PAL)/30
    av_enc[1].gop = 25;            //I ֡���1-200
    av_enc[1].video_type = 0;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    av_enc[1].audio_enc = 0;      //���ӱ����ʽ0:G711A
    av_enc[1].mix_type = 1;       //����Ƶ��: 0, ��Ƶ��: 1.
    av_enc[1].bitrate = 2048;       //�������� 32kbps-16000kbps
    av_enc[1].level = 0;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    av_enc[1].h264_ref_mod = 0;   //h264����֡�ο�ģʽ
#if 1
	av_enc[2].resolution =SDK_VIDEO_RESOLUTION_VGA;     //SDK_VIDEO_RESOLUTION_E
    av_enc[2].bitrate_type = SDK_BR_CBR;   //��������  SDK_VIDEO_BR_TYPE_E
    av_enc[2].pic_quilty = 0;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    av_enc[2].frame_rate = 25;     //����֡��1-25(PAL)/30
    av_enc[2].gop = 25;            //I ֡���1-200
    av_enc[2].video_type = 0;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    av_enc[2].audio_enc = 0;      //���ӱ����ʽ0:G711A
    av_enc[2].mix_type = 1;       //����Ƶ��: 0, ��Ƶ��: 1.
    av_enc[2].bitrate = 800;       //�������� 32kbps-16000kbps
    av_enc[2].level = 0;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    av_enc[2].h264_ref_mod = 0;   //h264����֡�ο�ģʽ
#else
	av_enc[2].resolution =SDK_VIDEO_RESOLUTION_720p;     //SDK_VIDEO_RESOLUTION_E
    av_enc[2].bitrate_type = SDK_BR_CBR;   //��������  SDK_VIDEO_BR_TYPE_E
    av_enc[2].pic_quilty = 0;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    av_enc[2].frame_rate = 25;     //����֡��1-25(PAL)/30
    av_enc[2].gop = 25;            //I ֡���1-200
    av_enc[2].video_type = 0;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    av_enc[2].audio_enc = 0;      //���ӱ����ʽ0:G711A
    av_enc[2].mix_type = 1;       //����Ƶ��: 0, ��Ƶ��: 1.
    av_enc[2].bitrate = 1024;       //�������� 32kbps-16000kbps
    av_enc[2].level = 0;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    av_enc[2].h264_ref_mod = 0;   //h264����֡�ο�ģʽ

#endif
    av_enc[3].resolution =SDK_VIDEO_RESOLUTION_QVGA;     //SDK_VIDEO_RESOLUTION_E
    av_enc[3].bitrate_type = SDK_BR_CBR;   //��������  SDK_VIDEO_BR_TYPE_E
    av_enc[3].pic_quilty = 0;     //��������0-��ã�1-�κã�2-�Ϻã�3-һ�㣬4-�ϲ5-��
    av_enc[3].frame_rate = 25;     //����֡��1-25(PAL)/30
    av_enc[3].gop = 25;            //I ֡���1-200
    av_enc[3].video_type = 0;      //��Ƶ�����ʽ0--h264 1--MJPEG 2--JPEG  SDK_VIDEO_FORMAT_E
    av_enc[3].audio_enc = 0;      //���ӱ����ʽ0:G711A
    av_enc[3].mix_type = 1;       //����Ƶ��: 0, ��Ƶ��: 1.
    av_enc[3].bitrate = 2048;       //�������� 32kbps-16000kbps
    av_enc[3].level = 0;          //����ȼ���h264: 0--baseline, 1--main, 2--high;
    av_enc[3].h264_ref_mod = 0;   //h264����֡�ο�ģʽ
    sdk_av_sys_init(0, 4, av_enc);

    warning("4444444444444 \n");


//�Ƿ�Ӧ����������ӳ�ʼ���ƶ����
	
    return 0;
}

//����ʼ��
int adapt_av_deinit(void)
{
    sdk_av_sys_uninit();
    return 0;
}

//��������
int adapt_av_server_start()
{
    int ret = 0;
    int i = 0 ;
    //�����������
    ret =  sdk_av_server_start();

    /*
    * ��˽�ڵ�����
    *
    */
    sdk_overlay_cfg_t overlay_cfg;
    memset(&overlay_cfg,0,sizeof(sdk_overlay_cfg_t));
    overlay_cfg.enable = 1;
    overlay_cfg.mask = 0xF;
    overlay_cfg.max_num = 4;
    for(i = 0 ; i < 4 ; i++)
    {
        overlay_cfg.area[i].x = 200 + i*100;
        overlay_cfg.area[i].y = 200 + i *50;
        overlay_cfg.area[i].width = 256;
        overlay_cfg.area[i].height = 256;

    }
    sdk_av_set_overlay_param(0,&overlay_cfg);
    /*
    *OSD��ʾ����
    *
    */
    sdk_osd_cfg_t osd_cfg;
    memset(&osd_cfg,0,sizeof(sdk_osd_cfg_t));

    osd_cfg.osd_invert_color = 0; // ����ɫ
    osd_cfg.time_color = 0;	//ʱ����ʾ��ɫ
    osd_cfg.chann_name_color = 0; //ͨ����Ϣ��ʾ��ɫ

    for(i = 0 ; i < 4 ; i++)
    {
        //OSDʱ��
        osd_cfg.time.pos.x = 20;            //λ��
        osd_cfg.time.pos.y = 20;
        osd_cfg.time.valid =1;          // ��ǰ�����Ƿ���Ч
        osd_cfg.time.font = 1;           // ��������
        osd_cfg.time.format = 1;         // ��ʾ��ʽ
        //osd_cfg.time.str_len;        // �ַ�������
        //osd_cfg.time.str[MAX_OSD_STR_LEN];//ascii+gb2312�ַ���

        //OSDͨ������
        if(i == 1||i == 3)//640*480
        {
            osd_cfg.chann_name.pos.x = 20;            //λ��
            osd_cfg.chann_name.pos.y = 440;            //λ��

        }
        else
        {
            osd_cfg.chann_name.pos.x = 20;            //λ��
            osd_cfg.chann_name.pos.y = 680;            //λ��
        }
        osd_cfg.chann_name.valid =1;          // ��ǰ�����Ƿ���Ч
        osd_cfg.chann_name.font = 1;           // ��������
        osd_cfg.chann_name.format = 1;         // ��ʾ��ʽ
        
        osd_cfg.chann_name.str_len =strlen("����������޹�˾");        // �ַ�������
        memcpy(osd_cfg.chann_name.str,"����������޹�˾",osd_cfg.chann_name.str_len);//ascii+gb2312�ַ���
        //�������� ����ͼƬ��Ϣ
        if(i == 1) //640*480
        {
           osd_cfg.ext_info.pos.x = 500;            //λ��
           osd_cfg.ext_info.pos.y = 300;

        }
        else
        {
            osd_cfg.ext_info.pos.x = 1100;            //λ��
            osd_cfg.ext_info.pos.y = 580;
        }
        osd_cfg.ext_info.valid =1;          // ��ǰ�����Ƿ���Ч
        osd_cfg.ext_info.font = 1;           // ��������
        osd_cfg.ext_info.format = 1;         // ��ʾ��ʽ
        
        //osd_cfg.ext_info.str_len =strlen("����������޹�˾");        // �ַ�������
       // memcpy(osd_cfg.ext_info.str,"����������޹�˾",osd_cfg.chann_name.str_len);//ascii+gb2312�ַ���

        sdk_av_set_osd_param(i, &osd_cfg);
    }

	//�����ƶ����  sdk_vda_codec_cfg_t
    adapt_param_get_motion_cfg(0,&motion_cfg);//��ʼ���������ƶ����
    motion_init(&(motion_cfg.codec_vda_cfg));
    motion_server_start();
//�����������

    adapt_param_get_audio_detect_param(&audio_detect_cfg);//��ʼ���������ƶ����
    audio_detect_init(&audio_detect_cfg);
    audio_detect_start();
    return ret;
}
int adapt_av_server_stop()
{
	return sdk_av_server_stop();
}
/************���ܺ���*********************************/

//ǿ��I֡
int adapt_av_force_i_frame(int ch)
{
    // return sdk_codec_forceIFrame(ch, sub_ch);
    return  sdk_av_request_i_frame(ch);
}



// ͬһʱ��ֻ֧��һ����Ƶ���
int adapt_av_audio_control(sdk_msg_t *pmsg)
{
    static int _old_ao_mode = -1;
    static int _is_create_dec_ch = 0;
    int oper = pmsg->args;
    int _ao_dev = 0;
    int _ao_mode = 0;
    int _ao_preview_ch = 0;
    int ret = 0;



    pmsg->size = 0;
    return 0;

_error:
    pmsg->size = 0;
    return -1;
}



int adapt_av_capability_info(sdk_msg_t *pmsg)
{
    int _ch = pmsg->chann;
    if(_ch < 0 || _ch >= MAX_CHANN_NUM)
    {
        error("Invalid ch!\n");
        return -1;
    }


    return 0;
}
/***************���ò���****************************/
int adapt_av_encode_cfg(sdk_msg_t *pmsg)
{
    int ret = 0;
    int ch =  (pmsg->chann >> 16)|0xFFFF;
    int sub_ch = pmsg->chann|0xFFFF;

    printf("adapt_av_encode_cfg ch:%d sub_ch:%d \n",ch,sub_ch);

    sdk_av_enc_t *av_enc = (sdk_encode_t*)pmsg->data;
    //sdk_encode_t *p_enc_cfg = (sdk_encode_t*)pmsg->data;

    if(pmsg->args == SDK_PARAM_SET)
    {
        ret = sdk_av_set_encode_param(ch,av_enc);
    }

    return ret;
}

int adapt_av_motion_cfg(sdk_msg_t *pmsg)
{
    int ret = 0;
    int ch =  (pmsg->chann >> 16)|0xFFFF;
    int sub_ch = pmsg->chann|0xFFFF;

    printf("adapt_av_motion_cfg ch:%d sub_ch:%d \n",ch,sub_ch);
    sdk_vda_codec_cfg_t motion_cfg;
    sdk_vda_codec_cfg_t *pmotion = (sdk_vda_codec_cfg_t*)pmsg->data;
    if(pmsg->args == SDK_PARAM_SET)
    {
        memset(&motion_cfg, 0, sizeof(sdk_vda_codec_cfg_t));
        memcpy(&motion_cfg, pmotion, sizeof(sdk_vda_codec_cfg_t));
		adapt_param_set_motion_cfg(0, &motion_cfg);
        ret = sdk_av_set_motion_param(0,&motion_cfg);
    }
    return ret ;
}


//OSD ����
int adapt_av_osd_cfg(sdk_msg_t *pmsg)
{
    int ret = 0;
    int ch =  (pmsg->chann >> 16)|0xFFFF;
    int sub_ch = pmsg->chann|0xFFFF;

    printf("adapt_av_osd_cfg ch:%d sub_ch:%d \n",ch,sub_ch);
    sdk_osd_cfg_t osd_cfg;
    sdk_osd_cfg_t *posd = (sdk_vda_codec_cfg_t*)pmsg->data;
    if(pmsg->args == SDK_PARAM_SET)
    {
        memset(&osd_cfg, 0, sizeof(sdk_osd_cfg_t));
        memcpy(&osd_cfg, posd, sizeof(sdk_osd_cfg_t));
        ret = sdk_av_set_osd_param(0,&osd_cfg);
    }
    return ret ;
}
//��Ƶ�ڵ� ����
int adapt_av_overlay_cfg(sdk_msg_t *pmsg)
{
    sdk_overlay_cfg_t *p_cover = (sdk_overlay_cfg_t *)pmsg->data;
    int ch = pmsg->chann;

    if(ch < 0 || ch >= MAX_CHANN_NUM)
    {
        error("ch error!\n");
        return -1;
    }
    printf("adapt_codec_overlay_cfg ch = %d \n",ch);
    return 0;   /////sdk_codec_set_ch_cover(ch, p_cover);
}
int adapt_av_snap(int ch,sdk_snap_info_t *snap_info,char *path)
{
    if(ch < 0 || ch >= MAX_CHANN_NUM || NULL == snap_info)
        return -1;
    return sdk_av_snap(ch,snap_info,path);
}
int adapt_audio_play(int audio_type,const char *audio_data,int date_len)
{
    return sdk_audio_play(audio_type,audio_data,date_len);
}

//ȫ�ֱ���ˢ��
int adapt_codec_encode_cfg(sdk_msg_t *pmsg)
{
	int i,ret;
	sdk_encode_t *enc_cfg = (sdk_encode_t *)pmsg->data;
	for(i=0;i<SDK_ENC_IDX_ALL;i++)
	{
		ret = sdk_av_set_encode_param(i,&(enc_cfg->av_enc_info[i]));//д�����
	}
    return ret;
}

int adapt_av_md_status( uint32_t *status )
{
    return 0;
}
int adapt_audio_detect_cfg( sdk_msg_t *pmsg )
{
  	//����ͬ���������
  	sdk_audio_detect_cfg_t *audio_detect_cfg= (sdk_audio_detect_cfg_t *)pmsg->data;
  	sdk_audio_set_detect_param(audio_detect_cfg);
    return 0;
}
#endif

#if 0 //add by zw
//�ƶ���� ����
int adapt_av_md_status(uint32_t *status)
{
    int i = 0;
    int ch_num = adapt_param_get_ana_chan_num();

    return 0;
}
//�����ڵ�
int adapt_av_od_status(uint32_t *status)
{
    int i = 0;
    int ch_num = adapt_param_get_ana_chan_num();
    return 0;
}
//��Ƶ��ʧ
int adapt_av_lost_status(uint32_t *status)
{

    return 0;
}



//������Ӻ����޸�sensor��ֵ add by zw ���ò�����Ҫ�������޸���Ϻ�ſ��Խ���
int adapt_av_set_image_attr(sdk_msg_t *pmsg)
{
    int ch = pmsg->chann;
    if(ch < 0 || ch >= MAX_CHANN_NUM)
    {
        error("Invalid ch!\n");
        return -1;
    }

    ///sdk_image_attr_t *p_image = (sdk_image_attr_t *)pmsg->data;
    return 0;///sdk_codec_set_image_attr(ch, p_image);
}

int adapt_av_set_3a_attr(sdk_msg_t *pmsg)
{
    int ch = pmsg->chann;
    if(ch < 0 || ch >= MAX_CHANN_NUM)
    {
        error("Invalid ch!\n");
        return -1;
    }

    //sdk_3a_attr_t *p3a_attr = (sdk_3a_attr_t *)pmsg->data;
    return 0;//sdk_codec_set_3a_attr(ch, p3a_attr);
}
/*******************************/
int adapt_av_get_def_3a_attr(int ch ,sdk_3a_attr_t *p3a_attr)
{
    if(ch < 0 || ch >= MAX_CHANN_NUM || NULL == p3a_attr)
    {
        error("Invalid ch!\n");
        return -1;
    }

    ////sdk_3a_attr_t *p3a_attr = (sdk_3a_attr_t *)pmsg->data;
    return 0;// sdk_codec_get_def_3a_attr(ch, p3a_attr);
}
int adapt_av_get_def_image_attr(int ch ,sdk_image_attr_t *pimage_attr)
{
    if(ch < 0 || ch >= MAX_CHANN_NUM || NULL == pimage_attr )
    {
        error("Invalid ch!\n");
        return -1;
    }

    ////sdk_image_attr_t *pimage_attr = (sdk_image_attr_t *)pmsg->data;
    return 0;//sdk_codec_get_def_image_attr(ch, pimage_attr);
}
/*******************************/



}

#endif


#endif /*_AMBARELLA_*/
