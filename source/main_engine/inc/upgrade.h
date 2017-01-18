
#ifndef __upgrade_h__
#define __upgrade_h__

#include <stdint.h>

#define UPG_T_UBOOT     "uboot"
#define UPG_T_IMAGE     "image"
#define UPG_T_CRAMFS    "cramfs"
#define UPG_T_JFFS2     "jffs2"
#define UPG_T_UBIFS     "ubifs"
#define UPG_T_FILE      "file"
#define UPG_T_PARM_FILE "parm"


#define UPG_P_MTD0      "/dev/mtd0"
#define UPG_P_MTD5      "/dev/mtd5"

/*
 * �����ļ���Ϣ����
 */
typedef struct upgrade_file_s {
    uint8_t     name[64];    //�ļ���
    uint8_t     type[16];    //�ļ�����
    uint8_t     ver[16];     //�汾
    uint32_t    addr;        //�ļ���ַ
    uint32_t    size;        //�ļ���С
    uint8_t     dst_path[32];//Ŀ��·��
    uint32_t    crc32;       //�ļ�����CRCУ��
}upgrade_file_t;

/*
 * ��������Ϣ����
 */
typedef struct upgrade_packet_s {
    uint32_t  crc32;         //������ϢCRCУ��(upgrade_packet_t+N*upgrade_file_t)
    uint8_t   device_type[16];//�豸����
    uint8_t   ver[16];       //�汾
    uint8_t   date[16];      //����
    uint32_t  file_num;      //�ļ�����
    uint32_t  size;          //��������С(N*upgrade_file_t + file[N].size)
    uint32_t  ex_addr;       //��չͷ��ַ
    upgrade_file_t file[0];  //�ļ���Ϣ
}upgrade_packet_t;


typedef int(upgrade_fun_t)(int status, void *args);

/*
 * ��ʼ��
 */
int upgrade_init(char *device_type, char *ver, int *upgrade_mode, upgrade_fun_t *func, void *args);

int upgrade_deinit(void);


/*
 * ��ʼ����
 */
int upgrade_start(char *buf, int is_file);

/*
 * ��ѯ����״̬
 */
// ��ȡ��������
int upgrade_get_status(void);
// ��ѯ�Ƿ���������
int upgrade_tid_runing(void);
// ������������
int upgrade_set_percent(int up_percent);

/*
 * ���������������Ϣ;
 */
int upgrade_check(char *buf, int is_file);

/*
 * ֻ���������ͷ�������ļ���Ϣ;
 */
int upgrade_check_pkg_head(char *buf, int is_file);




#endif //__upgrade_h__
