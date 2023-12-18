/*
 * ��Ȩ���� (c) ��Ϊ�������޹�˾ 2012-2018
 * ����˵��   : wlan��Ʒ���궨�壬���滮�ָ���ģ���spec�Ķ���
 *              ���¼ӹ����˸����������ģ�飬��Ҫ�ҷ�
 *              �����涨��WiTP MPW0 + 5115H�İ汾
 * ����       : ������
 * ��������   : 2012��9��26��
 */

#ifndef __PLATFORM_SPEC_H__
#define __PLATFORM_SPEC_H__

/* ����ͷ�ļ����� */
#include "oal_types.h"
#if ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102_HOST))
#include "platform_spec_1102.h"
#elif ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_HOST))
#include "platform_spec_1102a.h"
#elif ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_HOST))
#include "platform_spec_1103.h"
#endif

#endif /* end of wlan_spec.h */
