/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, bingchuan

 ******************************************************************************
  �� �� ��   : video.h
  �� �� ��   : v1.0
  ��    ��   : 9527
  ��������   : 2014��7��24��
  ��������   : video.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��7��24��
    ��    ��   : 9527
    �޸�����   : �����ļ�

******************************************************************************/


#ifndef __VIDEO_H__
#define __VIDEO_H__

#include "sdk_struct.h"
#include <stdint.h>


#define AUDIO_BITSTREAM_LEN       12800


#define CAP_PATH_NUM        4
#define ENC_TRACK_NUM       4

#define OSD_PALETTE_COLOR_AQUA              0xCA48CA93        /* YCrYCb */
#define OSD_PALETTE_COLOR_BLACK             0x10801080
#define OSD_PALETTE_COLOR_BLUE              0x296e29f0
#define OSD_PALETTE_COLOR_BROWN             0x51A1515B
#define OSD_PALETTE_COLOR_DODGERBLUE        0x693F69CB
#define OSD_PALETTE_COLOR_GRAY              0xB580B580
#define OSD_PALETTE_COLOR_GREEN             0x5151515B
#define OSD_PALETTE_COLOR_KHAKI             0x72897248
#define OSD_PALETTE_COLOR_LIGHTGREEN        0x90229036
#define OSD_PALETTE_COLOR_MAGENTA           0x6EDE6ECA
#define OSD_PALETTE_COLOR_ORANGE            0x98BC9851
#define OSD_PALETTE_COLOR_PINK              0xA5B3A589
#define OSD_PALETTE_COLOR_RED               0x52F0525A
#define OSD_PALETTE_COLOR_SLATEBLUE         0x3D603DA6
#define OSD_PALETTE_COLOR_WHITE             0xEB80EB80
#define OSD_PALETTE_COLOR_YELLOW            0xD292D210

typedef struct resolution_map_s
{
	uint8_t id;
	uint16_t width;
	uint16_t height;
}resolution_map_s;


/******************************************/
typedef struct video_info_t
{
    void *capture_object;
    void *video_object;
    int  video_fd;
	int  video_type; ///SDK_VIDEO_FORMAT_E
	int  video_width;
	int  video_height;
	int  frame_rate ;
	int  video_buf_len;
	char *video_buf;
} video_info_t;

typedef struct audio_info_s
{
	void *grab_object;
	void *audio_object;
	void *file_object;
	void *render_object;
	int  audio_fd;
	//int  audio_fd2;
	int  audio_buf_len;
	char *audio_buf;

} audio_info_t;

typedef struct av_info_s
{
    void *video_groupfd; //������
    void *audio_groupfd; //��Ƶ�� ����
    void *audio_groupfd2; //��Ƶ�� ����
    video_info_t  video_info[MAX_VIDEO_STREAM_NUM];
	audio_info_t  audio_info[2];	 // 0 ������ 1 ������
    int max_video_stream_num;			 // ��ǰϵͳϵͳ֧�ֵ����ͨ����
    int max_audio_stream_num;			 // ��ǰϵͳϵͳ֧�ֵ����ͨ����
    int reserved[5];         ///< Reserved words
} av_info_t;

typedef struct av_sys_info_s
{
    int stream_num ; //�������Ŀ
    SDK_AUDIO_CODEC_FORMAT_E    audio_format; //��Ƶ�����ʽ
    SDK_VIDEO_STANDARD_E  video_standard;    /* ��Ƶ��ʽ N P */ 
    int max_ch;			 // ϵͳ֧�ֵ����ͨ����
    int reserved[5];         ///< Reserved words
} av_sys_info_t;

typedef struct tagRGBQUAD
{
    char rgbBlue;
    char rgbGreen;
    char rgbRed;
    char rgbReserved;
} RGBQUAD;

typedef struct _osd_clut_s {
	unsigned char v;
	unsigned char  u;
	unsigned char  y;
	unsigned char  alpha;
} osd_clut_t;





#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

extern int video_stream_cb();
extern int video_sys_init();
extern int video_sys_uninit();
extern int video_enc_init(int ch,sdk_av_enc_t *pav_enc);
extern int video_enc_uninit(int ch);

extern int  video_server_start();
extern int  video_server_stop();

//ץ��
extern int  video_snap_start();
extern int  video_snap_stop();

//ǿ��I֡
extern int video_force_i_frame(int ch);

//���ñ������
extern int video_set_enc_attr(int ch,sdk_av_enc_t *pav_enc);

//��Ƶ�ڵ���������
extern int video_set_overlay_attr(int ch);
//�ƶ���ⱨ����������
extern int video_set_motion_attr(int ch,sdk_vda_codec_cfg_t *motion_cfg);
//����Ȥ��������
extern int video_set_roi_attr(int ch,sdk_roi_cfg_t *roi_cfg );

//osd ����
extern int video_set_osd_attr(int ch,sdk_osd_cfg_t *osd_cfg);
extern int video_get_osd_attr(int ch);


//ץ�ĺ���
extern int video_snap_init(int ch,SendstreamCallback snap_callback);
extern int video_snap_unint(int ch);
extern int video_snap_process(int ch,sdk_snap_info_t *snap_info,char *path);//


#if 0
//===========================================================
//sensor �ӿ�
//
//
//
//===========================================================

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_type
 ��������  : ��ȡsensor����
 �������  : ��
 �������  : ��
 �� �� ֵ  : sensor����
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_get_type();

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_supp_ima
 ��������  : ��ȡsensor֧�ֵ�ͼ������ѡ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : sensor֧�ֵ�ͼ������ѡ���
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
unsigned int  hi_av_sns_get_supp_ima();

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_supp_3a
 ��������  : ��ȡsensor֧�ֵ�3a����ѡ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : sensor֧�ֵ�3a����ѡ���
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
unsigned int	hi_av_sns_get_supp_3a();

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_ima_size
 ��������  : ��ȡsensor�ɼ���Ƶ�ֱ���
 �������  : HI_U16 *pU16W  ��Ƶ�ɼ����
             HI_U16 *pU16H  ��Ƶ�ɼ��߶�
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_get_ima_size(int nSnsType, HI_U16 *pU16W, HI_U16 *pU16H);

/*****************************************************************************
 �� �� ��  : hi_av_sns_set_ima_size
 ��������  : ����sensor�ɼ���Ƶ�ֱ���
 �������  : HI_U16 u16W  ��Ƶ�ɼ���
             HI_U16 u16H  ��Ƶ�ɼ���
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_set_ima_size(int nSnsType, HI_U16 u16W, HI_U16 u16H);

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_default_ima
 ��������  : ��ȡĬ��ͼ������
 �������  : int nPort       ��Ƶ�ɼ�LENS           
             HI_DEV_IMA_CFG_S *pImaCfg  ָ��ͨ��ͼ�����Խṹ��ָ��
 �������  : HI_DEV_IMA_CFG_S *pImaCfg  ָ��ͨ��ͼ�����Խṹ��ָ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/    
int	    hi_av_sns_get_default_ima(int nPort, int nSnsType, int nMachineType, HI_DEV_IMA_CFG_S *pImaCfg);

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_default_3a
 ��������  : ��ȡĬ��3a����
 �������  : int nPort      ��Ƶ�ɼ�LENS             
             HI_DEV_3A_CFG_S *p3ACfg  ָ��ͨ��3a���Խṹ��ָ��
 �������  : HI_DEV_3A_CFG_S *p3ACfg  ָ��ͨ��3a���Խṹ��ָ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_get_default_3a(int nPort, int nSnsType, int nMachineType, HI_DEV_3A_CFG_S *p3ACfg);

/*****************************************************************************
 �� �� ��  : hi_av_sns_check_ima
 ��������  : ���ͼ������ֵ
 �������  : int nPort         ��Ƶ�ɼ�LENS            
             HI_DEV_IMA_CFG_S *pImaCfg   ��Ҫ��������ֵ
             HI_DEV_IMA_MASK_E eImaMask  ��Ҫ����������
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_check_ima(int nPort, int nSnsType, int nMachineType, HI_DEV_IMA_CFG_S *pImaCfg, HI_DEV_IMA_MASK_E u32Mask);

/*****************************************************************************
 �� �� ��  : hi_av_sns_check_3a
 ��������  : ���3a����ֵ
 �������  : int nPort      ��Ƶ�ɼ�LENS              
             HI_DEV_3A_CFG_S *p3ACfg   ��Ҫ��������ֵ
             HI_DEV_3A_MASK_E e3AMask  ��Ҫ����������
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_check_3a(int nPort, int nSnsType, int nMachineType, HI_DEV_3A_CFG_S *p3ACfg, HI_DEV_3A_MASK_E u32Mask);

/*****************************************************************************
 �� �� ��  : hi_av_sns_set_ima
 ��������  : ����ͼ������
 �������  : int nPort     ��Ƶ�ɼ�LENS               
             HI_DEV_IMA_CFG_S *pImaCfg  ��Ҫ���õ�����ֵ
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int     hi_av_sns_set_ima(int nPort, HI_DEV_IMA_CFG_S *pImaCfg);

/*****************************************************************************
 �� �� ��  : hi_av_3a_ircut_switch
 ��������  : ����������ģʽʱ����һЩ3a������Ϊһ�����ģʽ�µ��ض�ֵ�� 
 �������  : int nDayStatus            
             HI_DEV_3A_CFG_S * p3ACfg  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��8��24��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_3a_ircut_switch(int nDayStatus, int nColor, HI_DEV_3A_CFG_S * p3ACfg);

/*****************************************************************************
 �� �� ��  : hi_av_ima_ircut_switch
 ��������  : ����������ģʽʱ����һЩͼ�������Ϊһ�����ģʽ�µ��ض�ֵ��
 �������  : int nSensor                   
             int nDayStatus                
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��8��21��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_ima_ircut_switch(int nDayStatus, HI_DEV_IMA_CFG_S * pImaCfg, HI_DEV_3A_CFG_S  * p3ACfg);

/*****************************************************************************
 �� �� ��  : hi_av_sns_set_3a
 ��������  : ����3a����
 �������  : int nPort     ��Ƶ�ɼ�LENS               
             HI_DEV_3A_CFG_S *p3ACfg  ��Ҫ���õ�����ֵ
 �������  : ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int     hi_av_sns_set_3a(int nPort, HI_DEV_3A_CFG_S *pImaCfg);

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_supp_size
 ��������  : ��ȡsensot֧�ֵĲɼ���С
 �������  : int nPort      ��Ƶ�ɼ�LENS                  
             int nStreamType    ��Ƶ��������: ����������������������          
             int nIndex         ֧�ֱַ��ʵ����к�          
             HI_SUPP_IMA_SIZE *pSuppSize  �ֱ��ʽṹ��
 �������  : HI_SUPP_IMA_SIZE *pSuppSize  �ֱ��ʽṹ��
 �� �� ֵ  : �ɹ�����0��ʧ�ܷ���-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_get_supp_size(int nPort, int nStreamType, int nIndex, int nSnsType, HI_SUPP_IMA_SIZE *pImaSize);

/*****************************************************************************
 �� �� ��  : hi_av_sns_get_frame_rate
 ��������  : ��ȡsensor֡��
 �������  : ��
 �������  : ��
 �� �� ֵ  : sensor֡��
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��1��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int	    hi_av_sns_get_frame_rate(int nSnsType, int nStand);

/*****************************************************************************
 �� �� ��  : hi_av_sns_check_change_lib
 ��������  : ���sensor���Ƿ���Ҫ���¼���
 �������  : int nWdrStatus  
 �������  : ��
 �� �� ֵ  : ��Ҫ���¼��ط���1������Ҫ���¼��ط���0��������-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��2��13��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int     hi_av_sns_check_change_lib(int nSnsType,int nWdrStatus);

/*****************************************************************************
 �� �� ��  : hi_av_isp_IrisTrig_Start
 ��������  : �����Զ���ȦУ�����ܡ�
 �������  :     0:�������Զ���ȦУ������0: �����Զ���ȦУ����
 �������  : ��
 �� �� ֵ  :    HI_SUCCESS
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��3��23��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_isp_IrisTrig(IrisTrigCb IrisResiveCb);


/*****************************************************************************
 �� �� ��  : hi_av_isp_DetectPix_Start
 ��������  : ���������⹦�ܡ�
 �������  : DetectPixelCb
 �������  : ��
 �� �� ֵ     :   HI_SUCCESS
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��3��23��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_isp_DetectPix(DetectPixelCb DetectPixCb);

/*****************************************************************************
 �� �� ��  : hi_av_isp_GetIspStatus
 ��������  : ��ȡISP״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��7��9��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_isp_GetIspStatus();

/*****************************************************************************
 �� �� ��  : hi_av_set_wdr_type
 ��������  : ����sensorWDRֵ
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��11��15��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_set_wdr_type(HI_S32 s32SnsType, int nWdrValue);

#ifdef HI3518_ARCH
/*****************************************************************************
 �� �� ��  : hi_av_get_rotate
 ��������  : ��ȡͼ����ת����ֵ
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��11��15��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_get_rotate(int nViCh);

#endif

/*****************************************************************************
 �� �� ��  : hi_av_sys_set_size
 ��������  : ���ñ����֧�ֵ����������������ߡ�
 �������  : int nCapW  ����ͨ���Ŀ�
             int nCapH  ����ͨ���ĸ�
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��26��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_sys_set_size(int nCapW, int nCapH);

/*****************************************************************************
 �� �� ��  : hi_av_sys_get_size
 ��������  : ��ȡ�����֧�ֵ����������������ߡ�
 �������  : int nCapW  ����ͨ���Ŀ�
             int nCapH  ����ͨ���ĸ�
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��26��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int hi_av_sys_get_size(int *pS32W, int *pS32H);

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VIDEO_H__ */
