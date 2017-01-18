#ifndef __CODEC_TYPE_H__
#define __CODEC_TYPE_H__

/*
*�������Ŀ����Ϊ�� ľ��Ķ�����  ���Բ������ⲿ�ṹ������
*
*/
#define MAX_CAP_CH_NUM          1 //����ͨ����  ÿ��ͨ�����滹����ͨ��
#define CODEC_MAX_STREAM		3 //�������ĸ���
#define CODEC_MOTION_NUM          4       //ÿ��ͨ������ƶ�����������

typedef struct codec_rect_s{
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
}codec_rect_t;

typedef struct _motion_cfg_s
{
    uint8_t enable;                                             //��������
    uint8_t sensitive;                                          //������(0[���������]----6[���])
    uint8_t res[2];
    uint32_t mask;												//��λ
    codec_rect_t area[CODEC_MOTION_NUM];                            //����
}codec_motion_cfg_t;


#endif
