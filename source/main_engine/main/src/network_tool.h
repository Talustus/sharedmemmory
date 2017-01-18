/*
 * Copyright : (C) 2011 santachi corp.
 * Filename : network_tool.h 
 * Discription : server for windows-search-tool utility.
 * Created : quewh 2011/03/24
 * Modified :   
 */
#ifndef _NETWORK_TOOL_H_
#define _NETWORK_TOOL_H_

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#endif

#define MSG_HOSTNAME_LEN 24
#define MSG_MAC_ADDR_SIZE 24
#define MSG_IP_SIZE 16
#define MSG_VERSION_LEN 24

#define MSG_DATA_LEN (100*1024)

#define  AMBAR_MAX_ADDR_SIZE		4 
#define	 AMBAR_VERSION_LEN		24
#define  AMBAR_MAX_OVERLAY_NUM		4
//��Ϣ
typedef struct __msg_head_t
{
	unsigned short msg_type; //��Ϣ����
	unsigned short msg_subtype; //��Ϣ������
	unsigned int msg_size; //��Ϣ����	
	unsigned char ack_flag; //ȷ�ϱ�־
	unsigned char reserved[3];
}msg_head_t;

typedef struct __net_msg_t
{
	msg_head_t msg_head; //��Ϣͷ
	char msg_data[MSG_DATA_LEN]; //��Ϣ����
}net_msg_t;

/* �������� */
typedef struct __ambar_network_config_t
{
	uint16_t	port_num;	/* �˿ں�,��Χ:8000-50000 */
	uint8_t		protocal_type;
	uint8_t		dhcp_flag;	/* dhcp ʹ�ܱ�־,0: ��ֹ, 1, ʹ�� */
	uint8_t		ip_addr[AMBAR_MAX_ADDR_SIZE];
	uint8_t		net_mask[AMBAR_MAX_ADDR_SIZE];
	uint8_t		def_gateway[AMBAR_MAX_ADDR_SIZE];
	uint8_t		broad_addr[AMBAR_MAX_ADDR_SIZE];
	uint8_t		mac_addr[20];
	uint8_t		first_dns_addr[AMBAR_MAX_ADDR_SIZE];	/* ��DNS */
	uint8_t		second_dns_addr[AMBAR_MAX_ADDR_SIZE];	/* ����DNS */
	uint16_t		dns_manu_flag;	/* dns ��ñ�־,0: �Զ����, 1: �ֶ�����*/
	uint16_t		web_port;	/* web �˿����� */
	uint8_t		unused[2];
	uint8_t		used_gateway;   /* 0:ʹ��eth0������   1:ʹ��eth2������*/
	uint8_t		is_enable_wireless; /* �Ƿ�ʹ����������  1: ʹ��  0:���� */
	uint8_t         ip_addr_eth2[AMBAR_MAX_ADDR_SIZE];/* ��������IP */
	uint8_t         net_mask_eth2[AMBAR_MAX_ADDR_SIZE];/* ����mask */
	uint8_t         def_gateway_eth2[AMBAR_MAX_ADDR_SIZE];/* �������� */
	uint8_t         broad_addr_eth2[AMBAR_MAX_ADDR_SIZE];/* ���߶ಥ */
	uint8_t         mac_addr_eth2[20];/* ����mac */
}network_config_t;


typedef struct __sys_config_t
{
	unsigned int	dev_type;	/* �豸���� ���ַ��� �˷���ΪHisi3511 �������� Hisi3510 */
	unsigned int	sub_type;	/* �豸������ �������ù������� �豸�˴����ݲ��������жϴ��� */
	uint8_t		chip_num;
	uint8_t		channel_num;
	uint8_t		prober_num;
	uint8_t		output_num;
	uint8_t		serial_num;
	uint8_t		ccd_enable:1;		/* ccd��ͷʹ����� */
	uint8_t		ptz_serial_type:1;	/* 0:��̨���ƵĴ��ڲ������� 1����̨���ƵĴ������ڹ̶� �������� */
	uint8_t		ptz_serial_no:6;	/* ��̨����ʹ�õĹ̶����ں� */
	uint8_t		adchip_type;		/* 0:no ad chip 1:tvp5150  2:TW2815 */
	uint8_t		flat_type;
	uint8_t		resolv_capable_m[16]; 
				/* 	�豸��ͨ�������� ������ 
				 *	bit0:PIC_RESOLUTION_QCIF bit1:PIC_RESOLUTION_CIF bit2:PIC_RESOLUTION_HD1 bit3:PIC_RESOLUTION_D1 
				 *	bit4:PIC_RESOLUTION_MD1 bit5:PIC_RESOLUTION_QVGA bit6:PIC_RESOLUTION_VGA bit7:HI_SXGA */
	uint8_t		resolv_capable_s[16]; 
				/* 	�豸��ͨ�������� ������ 
				 *	bit0:PIC_RESOLUTION_QCIF bit1:PIC_RESOLUTION_CIF bit2:PIC_RESOLUTION_HD1 bit3:PIC_RESOLUTION_D1 
				 *	bit4:PIC_RESOLUTION_MD1 bit5:PIC_RESOLUTION_QVGA bit6:PIC_RESOLUTION_VGA bit7:HI_SXGA */
	uint8_t		ds_enable_flag:1;	/* ˫����ʹ�� */
	uint8_t		D1_type:1;		/* 0:704*576 1:720*576 */
	uint8_t		product_type:1;		/* 0:DVS 1:CAR DVR*/
	uint8_t		dvr_type:5;		/* 0:not config 1:CAR DVR 2:PUB DVR*/	
	uint8_t		resolv_capable_m1[16];
				/* 	�豸��ͨ�������� ������ 
				 *	bit0:PIC_RESOLUTION_XXGA */
	uint8_t		resolv_capable_s1[16];
				/* 	�豸��ͨ�������� ������ 
				 *	bit0:PIC_RESOLUTION_XXGA  */
	uint8_t		cmos_enable;/*cmos��ͷʹ�����*/
	uint8_t		encode_format;/*�����ʽ  0��PAL  1��N*/
	uint8_t		language;/*����  0��Ӣ��  1������*/
	uint8_t		unused2[4];
}sys_config_t;
typedef struct _msg_broadcast_t
{
	int server_type; //�豸����
	int port_no; //�����˿�
	int net_type; //��������
	char host_name[MSG_HOSTNAME_LEN]; //�豸��
	char mac_addr[MSG_MAC_ADDR_SIZE]; //MAC��ַ
	char ip_addr[MSG_IP_SIZE]; //IP��ַ
	char net_mask[MSG_IP_SIZE]; //��������
	char gw_addr[MSG_IP_SIZE]; //���ص�ַ
	char version[MSG_VERSION_LEN];
	unsigned int port_offset; //�˿�ƫ��
	char first_dns_addr[MSG_IP_SIZE]; //��ѡDNS��ַ
	char second_dns_addr[MSG_IP_SIZE]; //����DNS��ַ
	unsigned short dns_manu_flag; //dns �ֶ���־: 1: enable, 0: disable
	unsigned short web_port; //web �˿�
	char dhcp_flag; //dhcp ʹ�ܱ�־: 1:enable, 0: disable
	char gw_devtype; //0:ʹ�ô�����Ĭ������ 1��ûʹ�ô�������Ĭ������
	char unused[2];
	char device_type[MSG_VERSION_LEN];                //��Ʒ�ͺ�
	sys_config_t	sys_config;	
}msg_broadcast_t;

typedef struct _msg_broadcast_modify_info_t
{
	int src_server_type; 
	int src_port_no;
	int src_net_type;
	char src_host_name[MSG_HOSTNAME_LEN];
	char src_mac_addr[MSG_MAC_ADDR_SIZE];
	char src_ip_addr[MSG_IP_SIZE];
	char src_mask_addr[MSG_IP_SIZE]; 
	char src_gw_addr[MSG_IP_SIZE];
	char src_version_no[MSG_VERSION_LEN];
	int src_port_offset;

	int dst_server_type; 
	int dst_port_no;
	int dst_net_type;
	char dst_host_name[MSG_HOSTNAME_LEN];
	char dst_mac_addr[MSG_MAC_ADDR_SIZE];
	char dst_ip_addr[MSG_IP_SIZE];
	char dst_mask_addr[MSG_IP_SIZE]; 
	char dst_gw_addr[MSG_IP_SIZE];
	char dst_version_no[MSG_VERSION_LEN];
	int dst_port_offset;

	char src_first_dns_addr[MSG_IP_SIZE]; //��ѡDNS��ַ
	char src_second_dns_addr[MSG_IP_SIZE]; //����DNS��ַ
	unsigned short src_dns_manu_flag; //dns �ֶ���־: 1: enable, 0: disable
	unsigned short src_web_port; //web �˿�

	char dst_first_dns_addr[MSG_IP_SIZE]; //��ѡDNS��ַ
	char dst_second_dns_addr[MSG_IP_SIZE]; //����DNS��ַ
	unsigned short dst_dns_manu_flag; //dns �ֶ���־: 1: enable, 0: disable
	unsigned short dst_web_port; //web �˿�
	char dst_dhcp_flag; //dhcp ʹ�ܱ�־: 1:enable, 0: disable
	char unused[3];
}msg_broadcast_modify_info_t;



typedef struct _msg_broadcast_reset_t
{
	int server_type; //�豸����
	int port_no; //�����˿�
	int net_type; //��������
	char host_name[MSG_HOSTNAME_LEN]; //�豸��
	char mac_addr[MSG_MAC_ADDR_SIZE]; //MAC��ַ
	char ip_addr[MSG_IP_SIZE]; //IP��ַ
	char net_mask[MSG_IP_SIZE]; //��������
	char gw_addr[MSG_IP_SIZE]; //���ص�ַ
	char version[MSG_VERSION_LEN];
	unsigned int port_offset; //�˿�ƫ��
}msg_broadcast_reset_t;

int st_net_startNetworktool(void);
int st_net_stopNetworktool(void);

#endif

