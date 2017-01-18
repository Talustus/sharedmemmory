#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>

#if 0
#include "sdk_struct.h"
#include "baidu.h"

#include "streamlib.h"
#include "log.h"





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


//st_stream_getLastPos(0, 0, &rpos);
static stream_rpos_t g_stream_handle[2];
static ST_HDL g_audio_handle;
static ST_HDL g_video_handle;


static  int audio_priority = 0;
static ST_HDL audio_stream_hdl;//��Ƶֻ��һ��ͨ��   ��ͨ��  

static int32_t open_ls_stream(media_handle m, int32_t channel, int32_t level, void *media_info)
{
    if(m == NULL || channel > 2)
        return -1;

	g_video_handle = sdk_stream_Open(1);//ȡ��һ·720p��  ���Ƶ�1M������
	
	g_audio_handle = sdk_stream_Open(0);//0ͨ��������Ƶ  ����Ƶ��
    //baidu_server_media_set_u(m, (void *)(stream_hdl));

	 // baidu_server_media_set_u(m, (void *)(audio_stream_hdl));

    info(">>>>>>>>>>>>>>> open_ls_stream g_video_handle:%d  audio_stream_hdl:%d \n",g_video_handle,g_audio_handle);

   // memset(&g_audio_handle,0,sizeof(stream_rpos_t));
   // st_stream_getLastPos(0, 0, &g_audio_handle);
   // baidu_server_media_set_u(m, (void *)(&g_audio_handle));
    return 0;
}

static int32_t play_ls_stream(media_handle m,int32_t channel)
{
    ST_HDL stream_hdl = (ST_HDL)baidu_server_media_get_u(m);
    info(">>>>>>>>>>>>>>> pull_ls_stream start!!!!stream_hdl:%d  \n",stream_hdl);
    return 0;
}

//�ͷ���Դ
static void close_ls_stream(media_handle m,int32_t channel)
{
    ST_HDL stream_hdl = (ST_HDL)baidu_server_media_get_u(m);
	sdk_stream_Close(g_video_handle);

	sdk_stream_Close(g_audio_handle);
	
    return 0;
}


/*********/
static int32_t pull_ls_stream(media_handle m,int32_t channel, char **frame_buff)
{
    int ret;
    sdk_frame_t *frame_head = NULL;
	char *buf =NULL;
    ST_HDL stream_hdl = (ST_HDL)baidu_server_media_get_u(m);
	
	
    if((!audio_priority) &&(*frame_buff = sdk_stream_ReadOneFrame(g_video_handle))&&(*frame_buff))
    {
        return 0;
    }
    if((*frame_buff = sdk_stream_ReadOneFrame(g_audio_handle))&&(*frame_buff))
    {
		audio_priority  = 1; //˵������Ƶ
        return 0;
    }
    audio_priority = 0;
    return -1;
}

static int32_t get_ls_stream(media_handle m,int32_t channel, char *frame_buff)
{
    int ret;
    sdk_frame_t *frame_head = NULL;
    sdk_frame_t *frm = (sdk_frame_t *)frame_buff;
	info("get audio frame_type:%d frame_size:%d \n",frm->frame_type,frm->frame_size);
	if(frm->frame_type == SDK_AUDIO_FRAME_A)
		return adapt_audio_play(0, frm->data, frm->frame_size);

	return -1;
}
//һ������Ϣ��� һ������Ƶ���Ĵ���
int adapt_baidu_init(sdk_msg_dispatch_cb msg_cb,void *stream_handle)
{
    int ret;
    //��ʼ��
    baidu_server_init(msg_cb);

    //ʵʱ���ӿ�
    baidu_ls_avs_ops ls;
    ls.open  = open_ls_stream;
    ls.play  = play_ls_stream;
    ls.pull  = pull_ls_stream;
    ls.close = close_ls_stream;
	ls.get= get_ls_stream;

    baidu_server_reg_avs_ops(&ls, NULL);

    baidu_server_start();	/* �������� */
//����ʹ��
	//init_write_fd();
    return 0;
}
int adapt_baidu_stop()
{
    baidu_server_stop();	/* �������� */
    return 0;
}


// 1 ������  0 δ����
int adapt_baidu_get_net_status()
{
    return baidu_get_connect_status();
}
int adapt_baidu_set_stream_ch(int channel)
{
    return baidu_set_stream_ch(channel);

}

int adapt_baidu_set_rec_status(int rec_status)
{
    return baidu_set_rec_status(rec_status);
}
int adapt_baidu_set_audio_status (int audio_eanble)
{

    return baidu_set_audio_status (audio_eanble);

}
//��Ƶֹͣʱ�� ����������
int adapt_baidu_set_video_status (int video_eanble)
{
    return baidu_set_video_status ( video_eanble);

}
int adapt_baidu_upload_file (const char *path,const char * file_name,const char *target_path)
{
    return baidu_upload_file(path,file_name,target_path);
}


#else
#define adapt_baidu_init(arg...)      (0)
#define adapt_baidu_set_stream_ch(arg...)      (0)
#define adapt_baidu_set_rec_status(arg...)          (0)
#define adapt_baidu_set_audio_status(arg...)  (0)
#define adapt_baidu_set_video_status(arg...)   (0)
#define adapt_baidu_upload_file(arg...)      (0)


#endif


