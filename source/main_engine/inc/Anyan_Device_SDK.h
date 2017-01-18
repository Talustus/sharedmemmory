/********************************************************************************************

			   ��Ȩ���� (C), 2001-2014, �Ϻ�����͵��ӿƼ����޹�˾

*********************************************************************************************
			   �� �� ��   : Anyan_Device_SDK.h
			   �� �� ��   : 1.0.0.1
			   ��    ��   : �ϳ���
			   ��������   : 2014��8��29��
			   ��������   : �����豸SDK��API�ӿ�ͷ�ļ�
			   �޸���ʷ   :
					1��	��    ��   : 2014��8��29��
						��    ��   : �ϳ���
						�޸�����   : �����ļ�
					2��	��    ��   : 2015��2��10��
						��    ��   : �ϳ���
						�޸�����   : �ӿڵ������޸������ʶ���
						
					3��	��    ��   : 2015��3��11��
						��    ��   : �ϳ���
						�޸�����   : �ӿڵ���,ȥ����֡��ŵȷ����ֶ�.��֡����
*********************************************************************************************/
#ifndef __ANYAN_DEVICE_SDK_H__
#define __ANYAN_DEVICE_SDK_H__

typedef char  				int8;
typedef short 				int16;
typedef int					int32;

typedef unsigned char 		uint8;
typedef unsigned short 		uint16;

typedef unsigned int  		uint32;
typedef unsigned long long 	uint64;

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

	/*I ֡ P֡ ��Ƶ֡���Ͷ���*/
#define  	CH_I_FRM    			0
#define  	CH_P_FRM    			1
#define  	CH_AUDIO_FRM			2

/*û�ж�Ӧ���ʿ�������ӽ���һ��*/
#define  	UPLOAD_RATE_1       	384 	
#define  	UPLOAD_RATE_2       	500		
#define  	UPLOAD_RATE_3       	700		
#define  	UPLOAD_RATE_4       	1000		

//error code
#define     LICENSE_FILE_ERR        1

	typedef struct
	{
		int 		block_nums;						/*���ٵĻ�������������λ��8k*block_nums*/
		char 		channel_num;						/*ͨ������*/
		uint16		max_rate;						/*�������*/
		uint16		min_rate;						/*��С����*/
		char		ptz_ctrl;						/*�Ƿ�֧��ptz���� 0 ��֪֧��, 1 ֻ֧��֧����������, 2 ֧���������Һͱ佹 */
		char 		dev_type;						/*�豸����0 δ֪ 1 dvr, 2 nvr, 3 ipc */

		char    	mic_flag;						/*�Ƿ���ʰ���� 0 û��, 1 ��*/
		char    	can_rec_voice;					/*���Խ�����Ƶ 0 ��֧��, 1 ֧��*/
		char        hard_disk;						/*�Ƿ���Ӳ��  0 û��, 1 ��*/
		char		*p_rw_path;						/*�ɶ�д·��,���sn,���ļ���*/

		char		audio_type;						/*��Ƶ���� 0-16 0:aac 1:g711_a 2:g711_u*/
		char 		audio_chnl;						/*��Ƶͨ��,��ͨ�� 1, ˫ͨ�� 2 */
		uint16      audio_smaple_rt;					/*��Ƶ������*/
		uint16      audio_bit_width;					/*λ��*/

        uint8       use_type;                        /*�豸ʹ�����ͣ�0�����������豸��1�������豸��2����ʾ�豸�� Ĭ��0��*/
		uint8       Reserved[19];						/*Ԥ���ֶ�*/
	}
	Dev_Attribut_Struct;

	typedef struct
	{
		int 		channelnum;						/*ͨ����*/
		uint16  	bit_rate;						/*����*/
		uint16  	frm_type;						/*֡���� I P */
		
		uint32  	frm_id;							/*֡����ˮ�����е� 2015/3/11 ����ֶ���Ч.���账��������*/
		uint32  	frm_av_id;						/*֡������ˮ��i ֡����P֡������Ƶ֡. 2015/3/11 ����ֶ���Ч.���账��������*/

		uint32  	frm_ts;							/*ʱ��� ms*/
		char 		*pdata;							/*����*/
		uint32  	frm_size;						/*֡��С*/
	}
	Stream_Event_Struct;
	
	typedef struct
	{
		int 		channelnum;						/*ͨ����*/
		uint16  	bit_rate;						/*����*/
		uint32  	ts_ts;							/*֡���� ��ʼʱ��� */
		uint32 		offset;							/*ƫ��*/
		uint32 		length;
		uint8   	*ts_data;
		uint32 		ts_size;							//�����ļ���С
		uint32 		ts_duration;						//����ʱ�䳤��    	
	}
	Stream_History_Struct;
	
	typedef  enum
	{
		VIDEO_CTRL,									/*�򿪹ر�*/
		HISTORY_CTRL,								/*��ʷ��Ƶ�ϴ�*/
		AUDIO_CTRL,									/*��Ƶ����,��(�ϴ�),�ر�*/

		TALKING_CTRL,								/*�Ի�����*/

		CAPTURE_PICTURE_CTRL,						/*ץ�Ŀ���,�¼�,��ʱ,�û�*/
			

		PTZ_CTRL,									/*��̨��������Զ������ο�����*/
		PTZ_SET_PRE_LOCAL,							/*����Ԥ�õ�*/
		PTZ_CALL_PRE_LOCAL,							/*����Ԥ�õ�*/
		PTZ_SET_WATCH_LOCAL,							/*���ÿ���λ	*/
		PTZ_SET_CRUISE,								/*����Ѳ��*/
		PTZ_SET_MODE,								/*�ֶ�,����λ,Ѳ��*/

		ALARM_CTRL,									/*��������*/

		DEVICE_PARAM_GET,							/*��ȡ�豸����*/
		DEVICE_PARAM_SET,							/*�����豸����*/

		TIME_SYN,									/*Уʱ*/
		ERROR_INFO,									/*������Ϣ*/
		//TBD
	}CMD_ITEMS;

	typedef struct
	{
		int   		channel;							/*ͨ��*/
		CMD_ITEMS	cmd_id;							/*����id�ο�CMD_ITEMS*/
		char		cmd_args[20];						/*����Я��������������μ��ĵ�*/
	}
	CMD_PARAM_STRUCT;

	typedef  enum
	{
		MOVE_DETECT = 0x0004,						/*�ƶ����*/
		VIDEO_LOST = 0x0008,							/*��Ƶ��ʧ*/
		VIDEO_SHELTER = 0x0010,						/*��Ƶ�ڵ�*/		
		//TBD
	}ALARM_TYPE;

	typedef struct
	{
		char     MAC[17 + 1];							/*MAC ��ַ*/
		uint32   OEMID;								/*OEM ID*/
		char     SN[16+1];								/*sn���к�*/
		char     OEM_name[2+1];						    /*����OEM����,������ݲ�ͬ�����ɰ���ƽ̨ͳһ�ṩ*/
		char     Model[64 + 1];                       /*�豸�ͺ�*/
		char     Factory[255 + 1];                    /*��������(���磬����͡��������ӡ��󻪵�)*/
	}
	Dev_SN_Info;

	typedef struct
	{
		uint8		channel_index;			//ͨ��
		uint8		brightness;				// ����
		uint8		saturation;				//���Ͷ�
		uint8		Contrast;				//�Աȶ�
		uint8		tone;					//ɫ��
	}ULK_Video_Param_Ack;// ͼ������ϴ�
	typedef struct
	{
		uint8		channel_index;			//ͨ��
		uint8		rate_index;				// �������� 0 �� 1 ��
		uint16		bit_rate;				//����
		uint16		frame_rate;				//֡��
		uint16		video_quality;			//ͼ������ >0 ԽСԽ��
	}ULK_Video_Encode_Param_Ack;// ͼ���������ϴ�

	typedef struct
	{
		uint8		channel_index;
		uint16		rate;
		uint32		ts_ts;
		uint32		ts_size;
		uint32		ts_duration;
	}ULK_Hist_Rslt_Ack;// �豸 �� ������

	/*
		��������ģʽ �����ô˺�����������ģʽ��ͬʱ������־�ļ�����������־�ļ��������ļ���������:/tmp/ulk.log
		log_file_full_name:��־�ļ�·��+�ļ���
	
		function	: enable time synchronous
		parameter : 
		note		:
	*/
	void 			Ulu_SDK_Enable_Debug(const char *log_file_full_name);
	
	/*
		�����Զ�ʱ��ͬ��.Ĭ���ṩ�˴˹���
		function	: enable time synchronous
		parameter : 
		note		:
	*/
	void 			Ulu_SDK_Enable_AutoSyncTime(void);
	/*
		��ֹ�Զ�ʱ��ͬ��
		function	: disable time synchronous
		parameter : 
		note		:
	*/
	void			Ulu_SDK_Disable_AutoSyncTime(void);
		

	/*
		����OEM Info,�����ڴ������Լ��ĳ��������豸�ͺš�����ID������������Ϣ
		function	: set oem info and regist device to server.it will creat a new device id.
		parameter : 
		note		:
	*/
	void 			Ulu_SDK_Set_OEM_Info(Dev_SN_Info  *Oem_info);

	/*
		��ʼ������,Ϊ֡���ٻ�����.. 0�ɹ� -1ʧ��
		function	: initial and allocate memory for sdk.
		parameter : 
		note		:
	*/
	int  			Ulu_SDK_Init(Dev_Attribut_Struct  *attr);

	/*
		�ͷ�֡���ٻ�����,����ʱ���ô˺���
		function	:  release the memory that Ulu_SDK_Init has allocated.
		parameter : 
		note		: 
	*/
	void 			Ulu_SDK_DeInit(void);

	/*
		����ͼ���С
		function	:  send video size before upload video data.
		parameter : 
		note		: 

	*/
	void 			Ulu_SDK_Set_Video_size(int width, int height);

	/*
		�����ӿڻص�����ԭ�Ͷ���
		function	: interact function prototype defined ,Ulu_SDK_Set_Interact_CallBack
		parameter : 
		note		: 
	*/
	typedef   		void(*Interact_CallBack)(CMD_PARAM_STRUCT *args);

	/*
		���ûص���������

		function	: set Interact callback function and receive server command.
		parameter : 
		note		: 
	*/
	void 		    Ulu_SDK_Set_Interact_CallBack(Interact_CallBack callback_fun);

	/*
		��Ƶ�������ϱ�,����֡�ϱ�..I֡,P֡,��Ƶ֡��...
		���� -4:�������쳣  -3:ͨ����Χ���� -2:ͨ�������� -1:��ʾû�н�����������.> 0 ������ʾ������ʹ������
		
		function	: send	video/audio fram date to server.
		parameter : 
		note		:
	*/
	int 			Ulu_SDK_Stream_Event_Report(Stream_Event_Struct *pEvent);

	/*	�����ϴ�
		function	: send  alarm infomation .
		parameter : 
		note		: 
	*/
	void 			Ulu_SDK_Alarm_Upload(ALARM_TYPE  alarm_type);

	/*	ͼ������ϴ� 
		function	: send  video infomation .
		parameter :
		note		: it is no complete.	
	*/
	void 			Ulu_SDK_Param_Vedio_Upload(ULK_Video_Param_Ack  *video_param);
	/*
		ͼ���������ϴ�		
		function	: send  video encode type .
		parameter :
		note		: it is no complete.
	*/
	void 			Ulu_SDK_Code_Param_Vedio_Upload(ULK_Video_Encode_Param_Ack  *video_param);	

	/*��ȡ����ϴ������ٶ�
	send_speed 	�������ݵ��ٶ�
	send_ok_speed  ʵ�ʷ��ͳɹ����ٶ�
	ע:��������4s�ڵ�����ͳ��byte

	 function	:  get the recently send speed .
	 parameter: 
	 		   send_speed ->you have sent all date in 4s
	 		   send_ok_speed->the data have been sent successfully in 4s
	*/
	void 			Ulu_SDK_Get_Upload_Speed(uint32 *send_speed, uint32 *send_ok_speed);	
	/*
		��ȡ������������״̬
		 1 -> ��������, -2 �������� -1 û������
		function	:this function is  used to get the connected status that device with server
		parameter: 
		note		:
	*/
	int  			Ulu_SDK_Get_Connect_Status(void);

	/*��������������NVR���*/
	/*��ʷ��Ƶ���ͺ���	
	ע:�˺�������������,
	���� -2 ���� -1��ʾû������,> 0 ������ʾ������ʹ������
	history video send.
	return:  -2 err.  -1 no connections. > 0 the number of buffer block used.

	note:this function is only used in NVR device  and it is no complete, 
	it is blocked.
	*/
	int  			Ulu_SDK_History_Frame_Upload(Stream_History_Struct *pEvent);
	/*��ʷ��Ƶ��ѯ����ϴ�
	function	:send the result that search history video on NVR device.
	note		:this function is only used in NVR device and it is no complete.
	*/
	int 			Ulu_SDK_History_Srch_Rslt_Ack(ULK_Hist_Rslt_Ack *hist_Rslt);

	/*���Ź���ʼ��,�����ⲿ���������Ƿ�������*/
	int 			Ulu_SDK_Watchdog_init(void);

	/*��ȡ����״̬�������,
		����1��ʾ����,0 ��ʾ�쳣,
		��̼������ > 15s ,<15s û������.������ֱ�ӷ���1
		*/
	int 			Ulu_SDK_Get_ulu_net_status(void);

	/*������ULUCU SDK�ṩ�Ĺ��ܺ�����������ʹ�ã�����Ҳ�����Լ�ʵ�ֶ�Ӧ�ĺ�����*/
	/*CRC32���㺯��*/
	uint32 		    Ulu_SDK_Calc_CRC32(uint8 *data, uint32 datalen);
	/*CRC8���㺯��*/
	uint8 			Ulu_SDK_Calc_CRC8(uint8 *PData, uint32 Len);
	/*��ȡϵͳʱ���.���뵥λ*/
	uint64 			Ulu_SDK_GetTickCount(void);
	
	/*��ȡ�豸ID��Ϣ*/
	char*			Ulu_SDK_Get_Device_ID(void);
	

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ANYAN_DEVICE_SDK_H__ */

