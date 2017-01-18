#ifndef _HI_RTSP_GLOBAL_H_
#define _HI_RTSP_GLOBAL_H_

/*
* Copyright (c) 2010
* All rights reserved.
* 
* filename:hi_rtsp_global.h
* 
* func:���ļ�ʵ���˶�rtsp �ĳ�ʼ����rtsp �ص���������
* 
* author : hi
* createdate: 2011-01-27
*
* modify list: 
* 
*/
//#include "rtsp_struct.h"

#ifdef __cplusplus
extern "C" {
#endif 

#pragma pack(push, 4)

#define SUCCESS  0
#define FAILURE  (-1)

#define RTSP_SUPPORT_EXT 1 //֧��rtp ��չ����
#define RTSP_MAX_NAL_NUM 8

//+++++++++++++rongp add+++++++++++++++++//
#define MUL_VIDEO_UDP_ADDR              "239.1.1.10"
#define MUL_AUDIO_UDP_ADDR              "239.1.1.11"
//+++++++++++++rongp add end+++++++++++++++++//

/*RTP Payload type define*/
typedef enum _RTP_PT_E_
{
    RTP_PT_ULAW             = 0,        /* mu-law  PCMU*/
    RTP_PT_GSM              = 3,        /* GSM */
    RTP_PT_G723             = 4,        /* G.723 */
    RTP_PT_ALAW             = 8,        /* a-law  PCMA*/
    RTP_PT_G722             = 9,        /* G.722 */
    RTP_PT_S16BE_STEREO     = 10,       /* linear 16, 44.1khz, 2 channel */
    RTP_PT_S16BE_MONO       = 11,       /* linear 16, 44.1khz, 1 channel */
    RTP_PT_MPEGAUDIO        = 14,       /* mpeg audio */
    RTP_PT_JPEG             = 26,       /* jpeg */
    RTP_PT_H261             = 31,       /* h.261 */
    RTP_PT_MPEGVIDEO        = 32,       /* mpeg video */
    RTP_PT_MPEG2TS          = 33,       /* mpeg2 TS stream */
    RTP_PT_H263             = 34,       /* old H263 encapsulation */
                            
   
    RTP_PT_H264             = 96,       /* */
    RTP_PT_G726             = 97,       /* */
	RTP_PT_AAC              = 96, 
	RTP_PT_ADPCM			= 99,
	
    RTP_PT_INVALID          = 127
}RTP_PT_E;

typedef enum _RTSP_MSG_NOTIFY_
{
	RTSP_MSG_PREVIEW_LINK		= 0x1,
	RTSP_MSG_PREVIEW_UNLINK  	= 0x2,
}RTSP_MSG_NOTIFY;


typedef enum _RTSP_CODEC_TYPE_
{
  RTSP_CODEC_UNKNOWN = 0,

  RTSP_VIDEO_CODEC_START = 10,
  RTSP_VIDEO_H264,
  RTSP_VIDEO_MPEG4,
  RTSP_VIDEO_MJPEG,
  RTSP_VIDEO_END,

  RTSP_AUDIO_CODEC_START = 20,
  RTSP_AUDIO_G711A,
  RTSP_AUDIO_G711U,
  RTSP_AUDIO_CODEC_END
} RTSP_CODEC_TYPE;

typedef enum _HI_RTSP_GET_TYPE
{
    RTSP_PREV_TYPE = 0,     //Ԥ����ȡ��ʽ ��Ƶ֡�����µ�֡��ȡ����Ƶ֡��ȵ����µ�֡ΪI֡
    RTSP_REC_TYPE     ,     //¼���ȡ��ʽ����Ƶ��ָ����ʱ��ǰ��I֡��ʼ���� 
    RTSP_NEWEST_I_TYPE,    //����I֡
}HI_RTSP_GET_TYPE;

typedef enum _HI_RTSP_FRAME_TYPE_
{
  RTSP_UNKNOWN_FRAME = 0,
  RTSP_I_FRAME,
  RTSP_P_FRAME,
  RTSP_B_FRAME,
  RTSP_AUDIO_FRAME,
  RTSP_GENERIC_FRAME,  
} RTSP_FRAME_TYPE;

typedef struct _RTSP_MEDIA_INFO_
{
  RTSP_CODEC_TYPE eVideoType;                 /* ��Ƶ�������ͣ�ȡֵ��Χ�ο� av_type_t ���� */
  unsigned short     u16Width;                   /* ��Ƶ���                                  */
  unsigned short     u16Height;                  /* ��Ƶ�߶�                                  */
  unsigned long      u32Quality;                 /* ��Ƶ����                                  */
  unsigned long      u32AvgBit;                  /* �������ʣ���λ: λ/��                     */ 
  unsigned long      u32Samples;                /* �������ʣ���λ: HZ, �� 90000 HZ           */
  unsigned long      u32FrameRate;              /* ֡��, ��� 255 ֡/��                      */
  RTSP_CODEC_TYPE eAudioType;
  unsigned long      u32AudioBit;
  unsigned long      u32AudioSample;
} RTSP_MEDIA_INFO, *LP_RTSP_MEDIA_INFO;

typedef struct _RTSP_AV_DATA_
{
  unsigned long            u32Index;                  /* ���ݱ�ţ����: ֡��  */
  unsigned long            u32Latest;                 /* ���µ�֡��             */
  RTSP_CODEC_TYPE       eType;                      /* ���ݱ�������            */       
  unsigned long            u32NalLen[RTSP_MAX_NAL_NUM];
  unsigned char            u8IFrame;
  unsigned char            u8Res[3];
  unsigned long            u32Size;                   /* data �е����ݴ�С     */
  char                     *data;                     /* ���ݻ���              */
  unsigned long long       u64TimeStamp;              /* ���ݵ�ʱ���         */  
  unsigned short           u16Width;
  unsigned short           u16Height;
} RTSP_AV_DATA, *LPRTSP_AV_DATA;

typedef struct _RTP_EX_DATA_
{
  unsigned long  magic_no;        // 0x0132DCA9 -- 20110505
  unsigned long  frame_num;       // ֡��
  unsigned long  frame_type;      // j_frame_type_t
  unsigned long  codec;           // j_codec_type_t
  unsigned short width;           // ���
  unsigned short height;          // �߶�
  long           timestamp_sec;   // ʱ�������
  long           timestamp_usec;  // ʱ�����΢��
  long           size;            // frame lens
}RTP_EX_DATA, *LPRTP_EX_DATA;
#if 0
typedef  void* media_handle;

/* �豸�����ӿ� */
typedef struct _media_device_ops
{
	int (*get_param)(int param_id, int channel, void *param, void *user); /* ��ȡ�豸���� */
	int (*set_param)(int param_id, int channel, void *param, void *user); /* �����豸���� */
}baidu_device_ops;

/* ʵʱ���ӿ� */
typedef struct _media_ls_avs_ops
{
    int32_t (*open)(media_handle m, int32_t channel, int32_t level, void *media_info);/* �� */
    int32_t (*play)(media_handle m,int32_t channel);                                     /* ���� */
    int32_t (*ctrl)(media_handle m, uint32_t cmd, void *data);           /* ���� */
    void    (*close)(media_handle m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_handle m,int32_t channel, char **frm);                          /* ���� */
}media_ls_avs_ops;

/* ��ʷ���ӿ� */
typedef struct _media_hs_avs_ops
{
    int32_t (*open)(media_handle m, int32_t channel, int32_t level
                    , int32_t type, uint8_t *start_time, uint8_t *end_time
                    , uint8_t *property, void *mi);                 /* �� ʱ���ʽ:YYYYMMDDHHMMSS */
    int32_t (*play)(media_handle m,int32_t channel);                                     /* ��ʼ */
    int32_t (*pause)(media_handle m,int32_t channel);                                    /* ��ͣ */
    int32_t (*lseek)(media_handle m, uint32_t ts);                       /* ��λ */
    void    (*close)(media_handle m,int32_t channel);                                    /* �ر� */
    int32_t (*pull)(media_handle m, int32_t channel,sdk_frame_t *frm);                       /* ���� */
}media_hs_avs_ops;

#endif

typedef void * RTSP_AV_HDL;
//�û����ص�
typedef int (*LogFun)(int level, const char *fName, const char *func, int nLine, const char *fmt,...);

typedef RTSP_AV_HDL (openStream)(int nCh, int nStreamNo, RTSP_MEDIA_INFO *pMediaInfo);

typedef int (requestIDRCb)(RTSP_AV_HDL pHdl);

typedef int (getVideoStream)(RTSP_AV_HDL pHdl, RTSP_AV_DATA *pData);

typedef int (getAudioStream)(RTSP_AV_HDL pHdl, RTSP_AV_DATA *pData);

typedef int (setPlayType)(RTSP_AV_HDL pHdl, int nType);
    
typedef int (closeStream)(RTSP_AV_HDL pHdl);

typedef int (msgCb)(RTSP_MSG_NOTIFY eMsgNotify, int nCh, int nStreamType, char *pPar);

typedef int (checkUserCb)(char *szUser, char *szPsw, int nGetPsw);

typedef int (checkAudioEnable)(int channel);

typedef struct _RTSP_PLAY_CB_
{
    checkUserCb         *funcCheckUser;
    msgCb               *funcMsg;
    openStream          *funcOpenStream;
    closeStream         *funcCloseStream;
    requestIDRCb        *funcIdrCb;
    setPlayType         *funcSetPlayType;
    getVideoStream      *funcGetVideoStream;
    getAudioStream      *funcGetAudioStream;
    checkAudioEnable    *funcCheckAudioEnable;
	LogFun				 *funcWriteLog;
}RTSP_PLAY_CB, *LP_RTSP_PLAY_CB;

typedef struct _RTSP_CFG_
{
    int     nMaxCh;             //�豸֧�ֵ���Ƶ���ͨ����
    int     nStreamNum;         //�豸һ��ͨ��֧�ֵ��������� (1.������ 2.˫���� 3.������ �Դ�����)
    int     nRtspPort;          //rtsp ����˿�Ĭ��Ϊ554
    int     bUseAuth;           //�Ƿ�����У�� 0 ������ 1����
    int     bRtspMode;          // rtsp����ģʽ 0 �����ϴ���Ƶ 1 �����ϴ���Ƶ
    int     nRes[4];
}RTSP_CFG, *LP_RTSP_CFG;
//============================================================================
//����:hi_rtsp_start 
//
//����:����rtsp ����
//
//HI_RTSP_CFG     *pCft
//
//HI_RTSP_PLAY_CB *pPlayCb
//=============================================================================
int		sdk_rtsp_start(RTSP_CFG *pCfg, RTSP_PLAY_CB *pPlayCb);

//============================================================================
//����:hi_rtsp_stop 
//
//����:ֹͣrtsp ����
//
//=============================================================================
int		sdk_rtsp_stop();

extern RTSP_PLAY_CB	     gRtspPlayCb;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif 

#endif
