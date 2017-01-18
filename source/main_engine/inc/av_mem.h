#ifndef __av_mem_h__
#define __av_mem_h__

#include "pthread.h"
#include "streamlib.h"




#define STREAM_TWO_STREAM	(2)

#define STREAM_ALIGN_ENABLE
#define STREAM_ALIGN_SIZE (4)

typedef struct __stream_index_t
{
	char frame_type;	                  /* i֡ p֡ ��Ƶ GPS */
	char consume_type; 	                  /* Ԥ¼ ����¼��ֹͣ */
	char nuse[2];		                  /* ch */
	int time;
	/* int tim_ms; */
	int frame_pos; 		                  /* ֡��buf�е�λ�� */
	int frame_end;		                  /* frame len  = frame head + size */ /* cpǰ�� */
	int contrl_type;                      /* alarm move */  
	/*int frame_no;*/
	int data_circle_no;  	              /* ��ǰ֡��buf�ĵڼ����ϵ����� */
	int index_circle_no;
	/* int set_nal_num; */	              /* �����ֱ��ʷ����õ�nal�� unuse*/
	int nal_num;		                  /* ��ǰ֡ʵ�ʵ�nal �� */	
	int nal_size[STREAM_MAX_NAL_NUM];/* nal����ռ� nal��֡�е�λ�ö�̬���� */
}stream_index_t;


typedef struct __stream_rpos_t  /* ��buf���������� */
{

	int index_start_pos;        /* ȡ֡������ʼλ�� */  
	int index_end_pos;          /* ȡ֡��������֡λ��*/	
	int index_circle_no;        /* ������ʼ֡�Ļ��� ���绷 */
	int index_num;              /* �ܵ������ڵ���� */
	int index_block_pos;        /* */
	int index_count;            /*ȡ���ʱ���ã�����ȡ��count��֡*/
    stream_index_t *p_stream_index;/* ������ʼ��ַ */

	int data_start_pos;         /* ȡ֡���ݿ�ʼλ�� */ 
	int data_end_pos;           /* ȡ֡���ݽ���λ�� */
	int data_circle_no;         /*  */

	char *p_buf_data;           /* ������ʼ��ַ */
    int change_count;
    unsigned int last_vframe_no;	// channel buffer��������Ƶ֡���
	unsigned int last_aframe_no;	// channel buffer��������Ƶ֡���    
}stream_rpos_t;

/* ----------------------------------------------------------- */

typedef struct _alignstream_t
{
    int data_len;
    int data_num;
    int wpos;
    int circle;
    char **data;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}alignstream_t;

typedef struct  _alignstream_rpos_t
{
    int rpos;
    int circle;
}alignstream_rpos_t;


/* --------------------- �䳤����Ƶ֡�ڴ���� ---------------------- */


int av_stream_avRegister(const stream_manage_t *p_stream_manage);
int av_stream_init();
int avstream_destroy();


int av_stream_sendFrameToPool(int ch, int ch_type, frame_t *frame);
int av_stream_sendFrameToPoolEx(int ch, int ch_type, frame_head_t *frame_head,char *frame_addr);

int av_stream_writeFrameToPool(stream_writeFrame_t *writeFrame);

int av_stream_getLastPos(int ch, int ch_type, stream_rpos_t *rpos);       /* ����֡λ�� */
int av_stream_getStartPos(int ch, int ch_type, stream_rpos_t *rpos);       /* Ԥ¼����� */
int av_stream_getOneFrame(int ch, int ch_type, int real_frame_diff, stream_rpos_t *rpos);	/* ȡһ֡����ǰ�����ݰ�ȫλ�ü��͵��� */
typedef struct stream_getOneIn_s
{
    int ch;
    int ch_type;
    int real_frame_diff;
    int change_iGetNum;     /* ʵʱ������I֡��ȡ����֡�� */
}stream_getOneIn_t;
int av_stream_getOneFrame2(stream_getOneIn_t *getOneIn, stream_rpos_t *rpos);	/* ȡһ֡����ǰ�����ݰ�ȫλ�ü��͵��� */

int av_stream_getBlock(int ch, int ch_type, int size, stream_rpos_t *rpos); /* ��֡�߽���� ����>=size ֮ǰ����ȫλ�õ����� ����Ч�Լ�� ¼��lseek ����Ч֡λ�� */
int av_stream_dataVailCheck(int ch, int ch_type, stream_rpos_t *rpos); /* �ж�������û�з������� */

void av_stream_StreamBroadcast(int channel, int ch_type);
void av_stream_StreamWaiting(int channel, int ch_type);

typedef struct st_pic_parm_s {
    unsigned int  sync_flags;
    unsigned int  sps_size; /* sps size */
    unsigned int  pps_size; /* pps size */
    unsigned char sps[64];  /* without start code */
    unsigned char pps[64];  /* without start code */
}st_pic_parm_t;
int av_stream_getPicParm(int ch, int ch_type, st_pic_parm_t *parm);

/* --------------------- ���������ڴ���� ---------------------- */

int alignstream_alloc(int data_len, int data_num, alignstream_t **alignstream);
void alignstream_free(alignstream_t *alignstream);

int alignstream_sendToPool(alignstream_t *alignstream, void *data);
int alignstream_getFromPool(alignstream_t *alignstream, void **data, alignstream_rpos_t *rpos);

int alignstream_wait(alignstream_t *alignstream);
int alignstream_broadcast(alignstream_t *alignstream);
//
int alignstream_getLastPos(alignstream_t *alignstream, alignstream_rpos_t *rpos);




#define GET_LAST_IFRAME     /* Ҫ����Ӧ��i ֡��ȫ����п����Ѿ��������� */
#ifdef GET_LAST_IFRAME
int av_stream_getLastIPos(int ch, int ch_type, stream_rpos_t *rpos);
#endif

#endif/*__av_mem_h__*/

