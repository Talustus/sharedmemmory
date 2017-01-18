/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, bingchuan

 ******************************************************************************
  �� �� ��   : g711.h
  �� �� ��   : v1.0
  ��    ��   : bingchuan
  ��������   : 2015��3��28��
  ��������   : g711.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��3��28��
    ��    ��   : bingchuan
    �޸�����   : �����ļ�

******************************************************************************/


#ifndef __G711_H__
#define __G711_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


extern int G711ADec(unsigned char* pSrc, short* pDst, int len);
extern int G711AEnc(short* pSrc, unsigned char* pDst, int len);
extern int G711UDec(unsigned char* pSrc, short* pDst, int len);
extern int G711UEnc(short* pSrc, unsigned char* pDst, int len);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __G711_H__ */
