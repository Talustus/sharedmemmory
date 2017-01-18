#ifndef __GRD_MMC_API_H__
#define __GRD_MMC_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <time.h> 
#include <assert.h>
#include <sys/vfs.h>
#include <dirent.h>  
#include <sys/stat.h>  
#include <sys/mount.h>  
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>

#include "storage.h"
//#include "typedef.h"
extern int g_sd_tats;

#define GRD_SD_PATHNAME             			"/dev/mmcblk[0-9]"
//#define GRD_SD_PARTITION_PATHNAME   		"/dev/mmcblk[0-9]p[0-9]"
#define GRD_SD_PARTITION_PATHNAME   		"/dev/mmcblk0"
//#define GRD_SD_MOUNT_POINT          			"/mnt/sd_card"
#define GRD_SD_PATHNAME_0           			"/dev/mmcblk0"
#define GRD_SD_PARTITION_PATHNAME_0 		"/dev/mmcblk0p1"



#define PRINT_ERR() printf("<<< File: %s, Line: %d, Function: %s >>>\n", __FILE__, __LINE__, __FUNCTION__)

#define PRINT_ERR_MSG(fmt, args...) \
            printf("[File: %s, Line: %d, Function: %s ]  " fmt "\n", \
                    __FILE__, __LINE__, __FUNCTION__, ##args)

#define PRINT_ERR_INFO(fmt, args...) printf(fmt, ##args)

#define PRINT_INFO(fmt, args...) printf(fmt, ##args)

/*
 *  pic_info ͼƬ��Ϣ��ͼƬ����ʱ������ YYYYMMDDHHMMSS.jpg
 */
typedef struct _time_t_
{
   unsigned short year;
    unsigned char mon;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
}_time_t;

typedef struct _pic_info
{	
	int count;   //ͼƬ������
	_time_t pic_num[0];
}pic_info;

/**********************************************************************
�����������ж���Ҫ�޸����ļ�·�����Ƿ�����Զ���ĸ�ʽ
��ڲ�����char *file_path: ��Ҫ�޸����ļ�·����
����ֵ��  1: ����
          0: ������
**********************************************************************/
extern int is_fix_format_path(char *file_path);

/**********************************************************************
�����������ж�·�����Ƿ�����Զ���ĸ�ʽ
��ڲ�����char *str: ��Ҫ�жϵ�·����
����ֵ��  1: ����
          0: ������
**********************************************************************/
extern int is_avi_dir_format(char *str);

/**********************************************************************
�����������ж��ļ����Ƿ�����Զ���ĸ�ʽ
��ڲ�����char *str: ��Ҫ�жϵ��ļ���
����ֵ��  1: ����
          0: ������
**********************************************************************/
extern int is_avi_file_format(char *str);

/**********************************************************************
�����������ж��ļ�·�����Ƿ�����Զ���ĸ�ʽ
��ڲ�����char *file_path: ��Ҫ�жϵ��ļ�·����
����ֵ��  1: ����
          0: ������
**********************************************************************/
extern int is_avi_file_path_format(char *str);



/**********************************************************************
����������mount sd��
��ڲ�������
����ֵ��  <0: ����
          0 : ����
**********************************************************************/
extern int grd_sd_mount(void);

/**********************************************************************
����������reumount sd��
��ڲ�������
����ֵ��  <0: ����
          0 : ����
**********************************************************************/
extern int grd_sd_remount(void);

/**********************************************************************
����������umount sd��
��ڲ��������ؽڵ�
����ֵ��-1 : ����
          0 : ����
**********************************************************************/
int grd_sd_umount(const char * mount_point);


/**********************************************************************
�����������ж�sd���Ƿ�mount��
��ڲ�������
����ֵ��  1: ��mount��
          0: û�б�mount��
**********************************************************************/
extern int grd_sd_is_mount(void); // if sd card is mounted, return 1; else return 0


/**********************************************************************
�����������ҵ����ϵ�avi�ļ��������ϵ�avi�ļ���Ȼ��ɾ�����ļ���
          ��������ϵ�avi�ļ�����û���ҵ�avi�ļ�����ɾ�����ļ��С�
          ����Ҳ������ϵ�avi�ļ��У��򷵻�0
��ڲ�������          
����ֵ��  1: �ɹ�,ɾ�������ϵ��ļ��������ϵ��ļ��У���������
          0: ʧ�ܣ��Ҳ������ϵ��ļ��У�û�н���ɾ������        
**********************************************************************/
extern int grd_sd_del_oldest_avi_file(void);

/**********************************************************************
������������⵽SD�������Զ����أ���sd��������С��30M
                           ʱ�����Զ�ɾ����ɵ���Ƶ��
��ڲ����� ��
����ֵ��      ��
**********************************************************************/

void sd_card_detecte_thread();

int is_jpg_pic_format(char * file_name);
int st_find_car_picture(const char * file_path, pic_info * pic_infomat);

/**********************************************************************
������������� SD ���Ƿ����
��ڲ�������
����ֵ�� 0 :  sd �����ڣ� -1  sd ��������
      
**********************************************************************/

int get_sd_stats(void);
int get_mmc_devname(char *pDevname, int iMaxsize);


#ifdef __cplusplus
}
#endif

#endif /* __GRD_MMC_API_H__ */

