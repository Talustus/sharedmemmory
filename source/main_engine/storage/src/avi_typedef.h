#ifndef __GRD_AVI_TYPEDEF_H__
#define __GRD_AVI_TYPEDEF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <semaphore.h>
#include "storage.h"

/* AVI flag, defined by aviriff.h */
#define AVIF_HASINDEX        0x00000010 //����AVI�� ������һ��index��
#define AVIF_MUSTUSEINDEX    0x00000020 //����Ӧ�ó�����Ҫʹ��index�������������ϵ�˳�����������ݵ�չ��˳�����磬�ñ�־�������ڴ���һ���༭�õ�֡�б�
#define AVIF_ISINTERLEAVED   0x00000100 //����AVI�� ���ǽ���ġ�
#define AVIF_TRUSTCKTYPE     0x00000800 // Use CKType to find key frames
#define AVIF_WASCAPTUREFILE  0x00010000 //�������ļ���һ�����ڲ���ʵʱ��Ƶ�ģ����ر�����AVI �� �������һ���ļ������˸ñ�־�����û�д���ļ�֮ǰ��Ӧ�ó���Ӧ�÷������棬��Ϊ�û����ܻ�Ը��ļ�������Ƭ����
#define AVIF_COPYRIGHTED     0x00020000 //����AVI�� �������˰�Ȩ���ݺ��������������˸ı�־��������������Ը����ݽ��п�����

#define INDEX_ARRAY_MAX_NUMBER  2048  //���������Ĵ�С
/* record mode */
#define RECORD_FIXED_SIZE         0X1
#define RECORD_FIXED_DURATION     0X2
#define RECORD_DELETE_OLD_FILES   0X4

#define RECORD_IS_FIXED_SIZE(x)          (x&0x1)
#define RECORD_IS_FIXED_DURATION(x)      (x&0x2)
#define RECORD_IS_DELETE(x)              (x&0x4)

#define FALSE   0               /* values of boolean */
#define TRUE    1

/* FOURCC */
#define MAKE_FOURCC(a,b,c,d)         (int)((a)|(b)<<8|(c)<<16|(d)<<24)

//video
#define AVI_TYPE_H264     MAKE_FOURCC('H','2','6','4')
#define AVI_TYPE_MPEG4    MAKE_FOURCC('D','I','V','X')
#define AVI_TYPE_MJPEG    MAKE_FOURCC('M','J','P','G')
#define AVI_TYPE_GMTAG    MAKE_FOURCC('G','M','T','G')
//audio
#define AVI_TYPE_PCM      MAKE_FOURCC('P','C','M',' ')
#define AVI_TYPE_MP3      MAKE_FOURCC('M','P','E','G')

#define NORMAL_RECORD_INDEX_TXT		"normal_record_index.txt"
#define EVENT_RECORD_INDEX_TXT		"event_record_index.txt"

//======================================================//
typedef struct tagAviInitParam {
    int bps;
    int fps;
    int width;
    int height;
    int codec_type;
    int type;
    int fcctype;

	int a_enc_type; // 0 a-law; 1 u-law
    int a_chans;    /* Audio channels, 0 for no audio */
    int a_rate;     /* Rate in Hz */
    int a_bits;     /* bits per audio sample */

    int ch_num;
    int mode;
    int size_m;
    int duration;
    char start[20];
} AviInitParam;

/* AVI Datastruct */
typedef struct AviFileTag {
    FILE    *file;   // avi  ���ļ����
    char   filename[128];
    FILE *idxfile;	// record frame index info
    char idxfilename[48];

	//�ļ�״̬����
	int new_flag ;

	//���ݻ������Ĺ���
	//char   *buf_addr;
	int 	event_buf_flag;//�¼�¼�񻺳�����־λ
	int 	normal_buf_flag; //����¼�񻺳�����־λ
	int   	buf_len;
	int    buf_index;//����Ƶ֡ д��ļ�����
	int	   buf_offset;//�����ڻ�������ƫ��

	//�ڲ�ʹ��
    int    data_offset;
    int    video_count;//��Ƶ֡������
    int    audio_bytes;
	int    audio_count;

    //index   �ڲ������Ĺ���
    int    index_count;   //real index count
    //int    *idx_array;
    int    idx_array[INDEX_ARRAY_MAX_NUMBER];
	
	//���Ի���������
    int    idx_array_count;
	int    pre_index_pos;  // ��¼��һ��д������ƫ�Ƶ�ַ

	
    unsigned int     duration;

 //��¼��ǰ�ļ��� ¼������ ��ֹʱ��
    int record_type;
    INDEX_NODE file_info;

//Ϊ�˽ӿڼ�  ����������ҷ����ڲ�����
  AviInitParam init_param;

}AviFile;


#ifndef HAVE_AVIMAINHEADER
#define HAVE_AVIMAINHEADER
typedef struct tagAviMainHeader {
    int  fcc;
    int  cb;
    int  dwMicroSecPerFrame;
    int  dwMaxBytesPerSec;
    int  dwPaddingGranularity;
    int  dwFlags;
    int  dwTotalFrames;
    int  dwInitialFrames;
    int  dwStreams;
    int  dwSuggestedBufferSize;
    int  dwWidth;
    int  dwHeight;
    int  dwReserved[4];
} AviMainHeader;
#endif

#ifndef HAVE_AVISTREAMHEADER
#define HAVE_AVISTREAMHEADER
typedef struct tagAviStreamHeader {
     int  fcc;
     int  cb;
     int  fccType;
     int  fccHandler;
     int  dwFlags;
     short int   wPriority;
     short int   wLanguage;
     int  dwInitialFrames;
     int  dwScale;
     int  dwRate;
     int  dwStart;
     int  dwLength;
     int  dwSuggestedBufferSize;
     int  dwQuality;
     int  dwSampleSize;
     struct {
         short int left;
         short int top;
         short int right;
         short int bottom;
     }  rcFrame;
} AviStreamHeader;
#endif

#ifndef HAVE_BITMAPINFOHEADER
#define HAVE_BITMAPINFOHEADER
typedef struct tagBitMapInfoHeader{
  int   biSize;
  int   biWidth;
  int   biHeight;
  short int   biPlanes;
  short int   biBitCount;
  int   biCompression;
  int   biSizeImage;
  int   biXPelsPerMeter;
  int   biYPelsPerMeter;
  int   biClrUsed;
  int   biClrImportant;
} BitMapInfoHeader;
#endif

#ifndef HAVE_RGBQUAD
#define HAVE_RGBQUAD
typedef struct tagRGBQuad {
  unsigned char    rgbBlue;
  unsigned char    rgbGreen;
  unsigned char    rgbRed;
  unsigned char    rgbReserved;
} RGBQuad ;
#endif

#ifndef HAVE_BITMAPINFO
#define HAVE_BITMAPINFO
typedef struct tagBitmapInfo {
  BitMapInfoHeader bmiHeader;
  //RGBQuad          bmiColors[1];
} BitmapInfo;
#endif

#ifndef HAVE_WAVEFORMATEX
#define HAVE_WAVEFORMATEX
typedef struct tagWaveFormateX{
  short int  wFormatTag;
  short int  nChannels;
  int nSamplesPerSec;
  int nAvgBytesPerSec;
  short int  nBlockAlign;
  short int  wBitsPerSample;
  short int  cbSize;
} WaveFormateX;
#endif

#ifndef HAVE_AUDIOFORMATEX
#define HAVE_AUDIOFORMATEX
typedef struct tagAudioFormateX{
  short int  wFormatTag;
  short int  nChannels;
  int nSamplesPerSec;
  int nAvgBytesPerSec;
  short int  nBlockAlign;
  short int  wBitsPerSample;
  short int  cbSize; 
} __attribute__ ((packed)) AudioFormateX;
#endif


#ifndef HAVE_AVIINDEX
#define HAVE_AVIINDEX
typedef struct tagAviIndex {
  int   dwChunkId;
  int   dwFlags;
  int   dwOffset;
  int   dwSize;
} AviIndex;
#endif

typedef union AviStreamFormatTag {
    BitmapInfo    video_format;
    WaveFormateX  audio_format;
}AviStreamFormat;





#define ONE_FRAME_BUF_SIZE 500000

typedef struct tagAviFrameNode {
    int frame_type;
    int offset;
    int size;
    struct timeval timestamp;
    char one_frame_buf[ONE_FRAME_BUF_SIZE];
} AviFrameNode;


// for PLAYBACK_AV_SIMULTANEOUS
#ifdef _PLAYBACK_AV_SIMULTANEOUS
#define AVI_PBBUF_VIDEO         0
#define AVI_PBBUF_VIDEOBK       1
#define AVI_PBBUF_AUDIO         2
#define AVI_PBBUF_AUDIOBK       3

typedef struct tagAviPBbuf {
    char *buf;
    int   index_cur;    // (IN)  the index to start to search for the specified frame(A or V)
                        // (OUT) the index of the frame to read next
    int   index;        // �x�������һ��index ����һ��
    int   fileoffset;   //file offset which the buffer corresponds to
    int   buf_pos;
} AviPBbuf;
#endif


typedef struct tagAviPBHandle {
    AviFrameNode node;
    FILE_LIST *list;

    int no;
    int video_no;
    int audio_no;

	float avi_fps;
    int video_width;
    int video_height;

	GRD_VIDEO_ENC_TYPE_E video_type;
	GRD_AUDIO_ENC_TYPE_E audio_type;

    FILE    *file;
    char   file_path[128];

    int    video_count;
    int    audio_count;

    //index
    int    index_count;   //real index count
    int    *idx_array;
    int    idx_array_count;

    //buffer for playback
    char *pb_buf;
    int pb_buf_index;
    int pb_buf_pos;
    uint32_t pb_timetick_tmp;

    int pb_open_flag;

    // for PLAYBACK_AV_SIMULTANEOUS
#ifdef _PLAYBACK_AV_SIMULTANEOUS
    //sem_t  sem_read;
    sem_t  sem_read_video;
    sem_t  sem_read_audio;
    pthread_mutex_t mutex_frame_read;
    pthread_mutex_t mutex_file_read;
    //pthread_t read_thread;
    //int    read_thread_running;
    pthread_t read_v_thread;
    pthread_t read_a_thread;
    int    read_v_thread_running;
    int    read_a_thread_running;

    int     pb_readV_flag;
    int     pb_readA_flag;
    int     pb_seek_flag;
    int     pb_video_end;
    int     pb_audio_end;
    int     pb_videofirst_flag;

    AviPBbuf  pb_buffer[4];
    AviFrameNode audio_node;
#endif
} AviPBHandle;

typedef struct tagAviHeader {
    int fcc_riff;  //RIFF
    int avi_len;
    int fcc_avi;  //AVI

    int fcc_list_hdrl;  //LIST
    int hdrl_len;
    int fcc_hdrl;  //hdrl

    AviMainHeader main_header;

    int fcc_list_strl_video;  //LIST
    int size_strl_video;
    int fcc_strl_video;  //strl
    AviStreamHeader video_header;
    int fcc_strf_video;  //strf
    int size_video_format;
    //AviStreamFormat video_format;
    BitMapInfoHeader bmiHeader;

    int fcc_list_strl_audio;  //LIST
    int size_strl_audio;
    int fcc_strl_audio;  //strl
    AviStreamHeader audio_header;
    int fcc_strf_audio;  //strf
    int size_audio_format;
    AudioFormateX audio_format;

    int fcc_list_movi;
    int movi_len;
    int fcc_movi;
} __attribute__ ((packed)) AviHeader;

#define REC_BUF_SIZE 512*1024

#ifdef _PLAYBACK_AV_SIMULTANEOUS
#define PB_BUF_SIZE  1000000       //1920*1088*1.5  //2000000   // for 1920*1088 h264 file
#else
#define PB_BUF_SIZE  2000000	   //1920*1088*1.5	//2000000   // for 1920*1088 h264 file
#endif
#define PB_ABUF_SIZE 3200
#define AUDIO_ARRAY_SIZE 20000

//ONE_FRAME_NODE frame_node;



#ifdef __cplusplus
}
#endif

#endif /* __GRD_AVI_TYPEDEF_H__ */

