/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * fl_public.c
 *
 * public func
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "fl_type.h"
#include "fl_define.h"
#include "fl_rae_struct.h"
#include "fl_public.h"

static uint32_t const g_bitset_32[] = {
	0x80000000, 0x40000000, 0x20000000, 0x10000000,
	0x08000000, 0x04000000, 0x02000000, 0x01000000,
	0x00800000, 0x00400000, 0x00200000, 0x00100000,
	0x00080000, 0x00040000, 0x00020000, 0x00010000,
	0x00008000, 0x00004000, 0x00002000, 0x00001000,
	0x00000800, 0x00000400, 0x00000200, 0x00000100,
	0x00000080, 0x00000040, 0x00000020, 0x00000010,
	0x00000008, 0x00000004, 0x00000002, 0x00000001
};

static uint32_t const g_bitset_16[] = {
	0x8000, 0x4000, 0x2000, 0x1000, 0x0800, 0x0400, 0x0200, 0x0100,
	0x0080, 0x0040, 0x0020, 0x0010, 0x0008, 0x0004, 0x0002, 0x0001
};

void rsa_write_len(struct str_pae *pae_ctx, uint32_t n_wordlen)
{
	pae_ctx->mod_word_len = n_wordlen;
}

void rsa_write_param(struct str_pae *pae_ctx, uint32_t n_param)
{
	pae_ctx->mod_param = n_param;
}

/*
 * ��������: check_allzero
 * ��������: �жϻ������Ƿ�ȫ0
 * �������:	uint32_t *buf,���жϵĻ�����ָ��,
 * 			uint32_t lenbyword,����ֳ���,
 * �������:	N/A
 * ����ֵ:	1 - ������Ϊȫ��,0 - ��������Ϊȫ��
 */
uint16_t check_allzero(uint32_t *buf, uint32_t lenbyword)
{
	uint32_t i;

	for (i = 0; i < lenbyword; i++)
		if (buf[i] != 0)
			return 0;
	return 1;
}

/*
 * ��������: nn_words
 * ��������: ���ش���a����Ч�����ֳ���,
 * �������:
 * 			uint32_t *a,������������ʼָ��
 * 			uint16_t words,����������ܵ��ֳ���
 * �������:
 * 			uint16_t, ��Ч�����ֳ���,���Ϊȫ��,������Ч����=1
 */
static uint16_t nn_words(uint32_t *a, uint16_t words)
{
	uint16_t i;
	uint16_t j;

	uint8_t flag = 0x00;

	j = words;

	for (i = 0; i < words; i++) {
		flag = (flag | (*(a + i) != 0));
		j = j - (0x01 - flag);
	}
	return j;
}

/*
 * ��������: nn_cmpbignumber_word
 * ��������: ��Ч�ֽ���ͬ�Ĵ����ȽϺ���,���ݸ�ʽ,
 * 			 16����,���ݻ�����Ϊ��Ȼ˳��
 * �������:
 * 			uint32_t *a,����a��������ʼָ��
 * 			uint32_t *b,����b��������ʼָ��
 * 			uint16_t bytes,����������ܵ��ֽڳ���
 * �������:
 * 			return value:0 - a=b; 1 - a>b; 2 - a<b
 */
uint16_t nn_cmpbignumber_word(uint32_t *a, uint32_t *b, uint16_t words)
{
	uint16_t i;
	uint16_t cnt1;
	uint16_t cnt2;

	cnt1 = 0;
	cnt2 = 0;

	for (i = 0; i < words; i++) {
		cnt1 = ((cnt1 | (*(a + i) > *(b + i))) & (cnt2 == 0));
		cnt2 = ((cnt2 | (*(a + i) < *(b + i))) & (cnt1 == 0));
	}
	return cnt1 + cnt2 + cnt2;
}

/*
 * ��������: nn_cmp_word
 * ��������: �����ȽϺ��������ݸ�ʽ,16����,���ݻ�����Ϊ��Ȼ˳��
 * �������:
 * 			uint32_t *a,����a��������ʼָ��
 * 			uint16_t awords,�������a���ܵ��ֳ���
 * 			uint32_t *b,����b��������ʼָ��
 * 			uint16_t bwords,�������b���ܵ��ֳ���
 * �������:
 * 			return value:0 - a=b; 1 - a>b; 2 - a<b-
 */
uint16_t nn_cmp_word(uint32_t *a, uint16_t awords,
		uint32_t *b, uint16_t bwords)
{
	uint16_t len1;
	uint16_t	len2;

	len1 = nn_words(a, awords);
	len2 = nn_words(b, bwords);
	if (len1 > len2)
		return 1;
	else if (len1 < len2)
		return 2;
	else
		return (nn_cmpbignumber_word(a + awords - len1,
			b + bwords - len2, len1));
}

uint32_t bn_getlenbyword(uint32_t *a, uint32_t nlen)
{
	uint32_t i;

	for (i = 0; i < nlen; i++)
		if (a[i] != 0)
			return i;

	return 0;
}

/*
 * ��������: cmp_bn
 * ��������: �Ƚϴ�����С
 * �������:	uint32_t *a,����aָ��,
 * 			uint32_t *b,����bָ��,
 * 			uint32_t lenbyword,�����ֳ���
 * ����ֵ:	0:a=b; 1:a>b; 2:a<b.-
 */
uint16_t cmp_bn(uint32_t *a, uint32_t *b, uint32_t lenbyword)
{
	return nn_cmp_word(a, lenbyword, b, lenbyword);
}

/*
 * ��������: check_klown
 * ��������: ��֤k,1<=k<n
 * �������:	uint32_t *kBuf,k�Ļ�����ָ��
 * 			uint32_t *n_bufuf,n�Ļ�����ָ��
 * 			uint32_t lenbyword,ģ���ֳ���
 * �������:	k����kBufָ��Ļ�����,1<=k<n
 * ����ֵ:	1 - ����1<=k<n,
 * 			0 - ������1<=k<n
 */
uint16_t check_klown(uint32_t *k_bufuf, uint32_t *n_bufuf, uint32_t lenbyword)
{
	if (check_allzero(k_bufuf, lenbyword) == 1)
		return 0;

	if (cmp_bn(k_bufuf, n_bufuf, lenbyword) == 2)
		return 1;

	return 0;
}

/*
 * ��������: rsa_write_ram
 * ��������: дָ�����ݵ�RSAָ����ַ��Ram
 * �������:	struct str_pae *pae_ctx, pae�ṹ��ָ��
 * 			uint32_t RamAddr,RSARam�ĵ�ַ,ΪWORD��ַ
 * 			uint32_t RamValue,Ҫд�������
 * �������:	N/A
 * ������λ��:-
 */
void rsa_write_ram(struct str_pae *pae_ctx,
		uint32_t ram_addr, uint32_t n_value)
{
	pae_ctx->pae_ram[ram_addr] = n_value;
}

/*
 * ��������: dma_wr_allxdata
 * ��������: дXdata Ram�ռ�ȫ��ͬ������
 * �������:	uint32_t n_value, Ҫд�����������
 * 			uint32_t ptr_xram, Ҫд���Xdata Ram��ʼ��ַ
 * 			uint32_t len,Ҫд����ֳ���
 * �������:	N/A
 * ������λ��:
 */
void dma_wr_allxdata(uint32_t n_value, uint32_t *ptr_xram, uint32_t nlenbyword)
{
	uint32_t i;

	for (i = 0; i < nlenbyword; i++)
		*(ptr_xram + i) = n_value;
}

/*
 * ��������: dma_xdata2xdata
 * ��������: Xdata��Xdata�����ݰ��Ʋ���
 * �������:	uint32_t *ptrxramsrc,�ⲿ�洢��Դ��ַ
 * 			uint32_t *ptrXramDest,Ҫд��������ⲿ�洢��Ŀ�ĵ�ַ
 * 			uint32_t nlenbyword,Ҫ�������ݵ��ֳ���
 * �������:	N/A-
 */
void dma_xdata2xdata(uint32_t *ptrxramsrc, uint32_t *ptrxramdest,
		uint32_t nlenbyword)
{
	uint32_t i;

	for (i = 0; i < nlenbyword; i++)
		*ptrxramdest++ = *ptrxramsrc++;
}

void get_u32_be(uint32_t *pt_n, uint8_t *b, uint32_t offset)
{
	*pt_n = (((uint32_t) b[offset]) << 24) |
		(((uint32_t) b[offset + 1]) << 16) |
		(((uint32_t) b[offset + 2]) <<  8) |
		(((uint32_t) b[offset + 3]));
}

void put_u32_be(uint32_t n, uint8_t *b, uint32_t offset)
{
	b[offset] = (uint8_t) (n >> 24);
	b[offset + 1] = (uint8_t) (n >> 16);
	b[offset + 2] = (uint8_t) (n >>  8);
	b[offset + 3] = (uint8_t) (n);
}

void dma_xdataword2xdatabyte(uint32_t *ptr_xram_src,
		uint8_t *ptr_xram_dest, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t temp;

	for (i = 0; i < nlenbyword; i++) {
		temp = *(ptr_xram_src++);
		put_u32_be(temp, ptr_xram_dest, i * 4);
	}
}

void dma_xdatabyte2xdataword(uint8_t *ptrxramsrc,
		uint32_t *ptrxramdest, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t temp;

	for (i = 0; i < nlenbyword; i++) {
		get_u32_be(&temp, ptrxramsrc, i * 4);
		*(ptrxramdest++) = temp;
	}
}

/*
 * ��������: dma_wr_allblock
 * ��������: Rsa ram������дΪ��ͬ����ֵ
 * �������:	struct str_pae *pae_ctx, pae�ṹ��ָ��
 * 			uint32_t n_value,Ҫд�������ֵ
 * 			uint32_t ptr_rsaram,Ҫд���Rsaram��ʼĿ�ĵ�ַ
 * 			uint32_t nlenbyword,Ҫ�������ݵ��ֳ���
 * ����ֵ:	N/A-
 */
void dma_wr_allblock(struct str_pae *pae_ctx,
		uint32_t n_value, uint32_t ptr_rsaram, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t *ptr1;

	ptr1 = pae_ctx->pae_ram + ptr_rsaram;
	for (i = 0; i < nlenbyword; i++)
		*(ptr1++) = n_value;
}

/*
 * ��������: dma_xdata_byte2rsa
 * ��������: Xdata��Rsa ram������Byte���Ʋ���
 * �������: struct str_pae *pae_ctx, pae�ṹ��ָ��
 * 			uint8_t * ptr_xram,Ҫ����������ⲿ�洢��Դ��ַ
 * 			uint32_t rsa_ramoffset,Ҫ�����RsaramĿ�ĵ�ַ
 * 			uint32_t nlenbyword,Ҫ�������ݵ��ֳ���
 * ����ֵ:	N/A-
 */
void dma_xdata_byte2rsa(struct str_pae *pae_ctx, uint8_t *ptr_xram,
		uint32_t rsa_ramoffset, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t templ;
	uint32_t *ptr1;

	ptr1 = pae_ctx->pae_ram + rsa_ramoffset + nlenbyword - 1;
	for (i = 0; i < nlenbyword; i++) {
		get_u32_be(&templ, ptr_xram, i * 0x04);
		*(ptr1--) = templ;
	}
}

/*
 * ��������: dma_xdata2rsa
 * ��������: Xdata��Rsa ram�����ݰ��Ʋ���
 * �������: struct str_pae *pae_ctx, pae�ṹ��ָ��
 * 			uint32_t *ptrxram,Ҫ����������ⲿ�洢��Դ��ʼ��ַ
 * 			uint32_t rsaramoffset,Ҫ�����Rsaram��ʼĿ�ĵ�ַ
 * 			uint32_t nlenbyword,Ҫ�������ݵ��ֳ���
 * ����ֵ:	N/A
 */
void dma_xdata2rsa(struct str_pae *pae_ctx, uint32_t *ptrxram,
		uint32_t rsaramoffset, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t *ptr1;

	ptr1 = pae_ctx->pae_ram + rsaramoffset + nlenbyword - 1;

	for (i = 0; i < nlenbyword; i++)
		*(ptr1--) = ptrxram[i];
}

/*
 * ��������: dma_rsa2xdata
 * ��������: Rsa ram��Xdata������WORD���Ʋ���
 * �������:	struct str_pae *pae_ctx, pae�ṹ��ָ��
 * 			uint32_t rsa_ram_offset,Ҫ�����RsaramԴ��ʼ��ַ
 * 			uint32_t *ptrxram,Ҫ����������ⲿ�洢����ʼĿ�ĵ�ַ
 * 			uint32_t nlenbyword,Ҫ�������ݵ��ֳ���
 * ����ֵ:	N/A-
 */
void dma_rsa2xdata(struct str_pae *pae_ctx,
		uint32_t rsa_ram_offset, uint32_t *ptrxram, uint32_t nlenbyword)
{
	uint32_t i;
	uint32_t *ptr1;

	ptr1 = pae_ctx->pae_ram + rsa_ram_offset + nlenbyword - 1;
	for (i = 0; i < nlenbyword; i++)
		ptrxram[i] = *(ptr1--);
}

uint32_t rsa_getmodparam(uint32_t n0)
{
	uint32_t temp;
	uint32_t u;
	uint32_t v;
	uint32_t q;
	uint32_t r;
	uint32_t x1;
	uint32_t x2;
	uint32_t x;
	uint32_t i;

	u  = n0;
	v  = 0;
	x1 = 1;
	x2 = 0;
	for (i = 0; i < 64; i++) {
		if (u == 0)
			break;
		if (v == 0) {
			temp = WORD_MASK_VALUE;
			q = temp / u;
			if (temp % u == u - 1)
				q = q + 1;
		} else {
			q = v / u;
		}
		r = v - q * u;
		x = x2 - q * x1;
		v = u;
		u = r;
		x2 = x1;
		x1 = x;
	}

	if (v == 1) {
		x2 = 0 - x2;
		return x2;
	}
	return 0;
}

uint32_t nn_lshift_word_cmp1(uint32_t *b, uint32_t lenbyword,
		uint32_t shiftword1, uint32_t shift_bits)
{
	uint32_t n_carry;

	n_carry = 0;
	if (shiftword1 < lenbyword)
		n_carry = b[shiftword1]>>(WORD_BITS - shift_bits);

	return n_carry;
}

/*
 * ��������: nn_lshift_word
 * ��������: ���������ƺ���,���� a = b * 2^s
 * �������:
 * 			uint32_t * a,����Ĵ�����������ָ��
 * 			uint32_t * b,������������ָ��
 * 			uint32_t lenbyword,���������ֳ�
 * 			uint32_t s,��Ҫ��λ�Ĵ���
 */
void nn_lshift_word(uint32_t *a, uint32_t *b, uint32_t lenbyword, uint32_t s)
{
	uint32_t i;
	uint32_t shiftword1;
	uint32_t shiftword2;
	uint32_t temp;
	uint32_t n_carry;
	uint32_t shift_bits;

	if (s == 0) {
		if (a != b)
			for (i = 0; i < lenbyword; i++)
				a[i] = b[i];
		return;
	}

	shiftword1 = s / WORD_BITS;
	shift_bits   = s % WORD_BITS;

	if (shiftword1 > 0)
		for (i = 0; i < shiftword1; i++)
			a[lenbyword - 1 - i] = 0;
	if (shift_bits > 0) {
		n_carry = 0;
		shiftword2 = lenbyword - shiftword1;
		if (shiftword2 > 0) {
			for (i = 0; i < shiftword2; i++) {
				n_carry = nn_lshift_word_cmp1(b, lenbyword,
					shiftword1 + i + 1, shift_bits);
				temp = b[shiftword1 + i] << shift_bits;
				a[i] = temp | n_carry;
			}
		}
	} else {
		shiftword2 = lenbyword - shiftword1;
		if (shiftword2 > 0) {
			for (i = 0; i < shiftword2; i++) {
				temp = b[shiftword1 + i];
				a[i] = temp;
			}
		}
	}
}

uint32_t check_bits_in_word(uint32_t a, uint32_t *p_s)
{
	uint32_t j;
	uint32_t b_find_one;

	b_find_one = 0;

	for (j = 0; j < WORD_BITS; j++) {
		if ((a & g_bitset_32[j]) == 0) {
			(*p_s) += 1;
		} else {
			b_find_one = 1;
			break;
		}
	}
	return b_find_one;
}

/*
 * ��������: compute_leadzero_num
 * ��������: ����a���λ0�ĸ���
 * �������:	uint32_t *a,������������ָ��(���ݸ�ʽ��Ȼ˳��),aΪ����ֵ
 * 			uint32_t lenbyword,���ݵ��ֳ���
 * ����ֵ:
 * 			uint32_t, a���λ0�ĸ���
 */
uint32_t compute_leadzero_num(uint32_t *a, uint32_t lenbyword)
{
	uint32_t i;
	uint32_t s;
	uint32_t b_find_one;

	s = 0;

	for (i = 0; i < lenbyword; i++) {
		if (a[i] == 0)
			s = s + WORD_BITS;
		else
			b_find_one = check_bits_in_word(a[i], &s);
		if (b_find_one == 1)
			break;
	}
	return s;
}

void euclid_one_round(struct str_pae *pae_ctx, uint32_t *u, uint32_t *v,
		uint32_t *r, uint32_t *s, uint32_t n_wordlen)
{
	uint32_t v1[RSA_HALF_WORD_LEN_MAX];
	uint32_t v2[RSA_HALF_WORD_LEN_MAX];
	uint32_t n_leadzero_u;
	uint32_t n_leadzero_v;
	uint32_t n_shift;
	uint32_t i;

	n_leadzero_u = compute_leadzero_num(u, n_wordlen);
	n_leadzero_v = compute_leadzero_num(v, n_wordlen);
	if (n_leadzero_u == n_leadzero_v) {
		dma_xdata2rsa(pae_ctx, u, PAE_RAM_BLOCK1, n_wordlen);
		dma_xdata2rsa(pae_ctx, v, PAE_RAM_BLOCK2, n_wordlen);
		rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x02);
		dma_rsa2xdata(pae_ctx, PAE_RAM_BLOCK1, u, n_wordlen);
		dma_xdata2rsa(pae_ctx, r, PAE_RAM_BLOCK1, n_wordlen);
		dma_xdata2rsa(pae_ctx, s, PAE_RAM_BLOCK2, n_wordlen);
		rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x02);
		dma_rsa2xdata(pae_ctx, PAE_RAM_BLOCK1, r, n_wordlen);
	} else {
		n_shift = (n_leadzero_v - n_leadzero_u);
		nn_lshift_word(v1, v, n_wordlen, n_shift - 1);
		nn_lshift_word(v2, v1, n_wordlen, 1);
		if (nn_cmpbignumber_word(u, v2, n_wordlen) != 0x02) {
			dma_xdata2rsa(pae_ctx, u, PAE_RAM_BLOCK1, n_wordlen);
			dma_xdata2rsa(pae_ctx, v2, PAE_RAM_BLOCK2, n_wordlen);
			rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x02);
			dma_rsa2xdata(pae_ctx, PAE_RAM_BLOCK1, u, n_wordlen);
			dma_xdata2rsa(pae_ctx, s, PAE_RAM_BLOCK1, n_wordlen);
			for (i = 0; i < n_shift; i++) {
				rsa_command(pae_ctx, RSA_ADD, 0x01, 0x01, 0x01);
				rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x00);
			}
		} else {
			dma_xdata2rsa(pae_ctx, u, PAE_RAM_BLOCK1, n_wordlen);
			dma_xdata2rsa(pae_ctx, v1, PAE_RAM_BLOCK2, n_wordlen);
			rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x02);
			dma_rsa2xdata(pae_ctx, PAE_RAM_BLOCK1, u, n_wordlen);
			dma_xdata2rsa(pae_ctx, s, PAE_RAM_BLOCK1, n_wordlen);
			for (i = 0; i < n_shift - 1; i++) {
				rsa_command(pae_ctx, RSA_ADD, 0x01, 0x01, 0x01);
				rsa_command(pae_ctx, RSA_SUB, 0x01, 0x01, 0x00);
			}
		}
		dma_xdata2rsa(pae_ctx, r, PAE_RAM_BLOCK2, n_wordlen);
		rsa_command(pae_ctx, RSA_SUB, 0x01, 0x02, 0x01);
		dma_rsa2xdata(pae_ctx, PAE_RAM_BLOCK1, r, n_wordlen);
	}
}

uint8_t generate_z(uint32_t *z, uint32_t *u, uint32_t *v,
		uint32_t *r, uint32_t *s, uint32_t n_wordlen)
{
	uint32_t v1[RSA_HALF_WORD_LEN_MAX];
	uint32_t v2[RSA_HALF_WORD_LEN_MAX];
	uint8_t  b_u_cmp;
	uint8_t  b_v_cmp;

	dma_wr_allxdata(0, v1, n_wordlen);
	v1[n_wordlen - 1] = 0x01;
	dma_wr_allxdata(0, v2, n_wordlen);

	b_u_cmp = (uint8_t)nn_cmpbignumber_word(u, v1, n_wordlen);
	b_v_cmp = (uint8_t)nn_cmpbignumber_word(v, v2, n_wordlen);
	if ((b_u_cmp == 0x00) && (b_v_cmp == 0x00)) {
		dma_xdata2xdata(r, z, n_wordlen);
		return 0;
	}
	b_u_cmp = (uint8_t)nn_cmpbignumber_word(u, v2, n_wordlen);
	b_v_cmp = (uint8_t)nn_cmpbignumber_word(v, v1, n_wordlen);
	if ((b_u_cmp == 0x00) && (b_v_cmp == 0x00)) {
		dma_xdata2xdata(s, z, n_wordlen);
		return 0;
	}
	return 1;
}

/*
 * ��������:bignum_modinv_soft
 * ��������: ���շת���������ģ��,z=x^(-1) %m
 *
 * Input:
 *		struct str_pae *pae_ctx, pae�ṹ��ָ��
 *		uint32_t *z, �������ָ��
 *		uint32_t *x, ��������ָ��, X �� [1, M-1] and M
 *      uint32_t *m, ģָ��
 *      uint32_t n_wordlen, ����ģ�ֳ�
 *
 * Output:
 *		0 - ������ȷ, 1 - �������,ģ�治����
 */
uint8_t bignum_modinv_soft(struct str_pae *pae_ctx,
		uint32_t *z, uint32_t *x, uint32_t *m, uint32_t n_wordlen)
{
	uint32_t u[RSA_HALF_WORD_LEN_MAX];
	uint32_t v[RSA_HALF_WORD_LEN_MAX];
	uint32_t r[RSA_HALF_WORD_LEN_MAX];
	uint32_t s[RSA_HALF_WORD_LEN_MAX];
	uint8_t  b_u_cmp;
	uint8_t  b_v_cmp;
	uint32_t i;

	dma_xdata2xdata(m, u, n_wordlen);
	dma_xdata2xdata(x, v, n_wordlen);
	dma_wr_allxdata(0, r, n_wordlen);
	dma_wr_allxdata(0, s, n_wordlen);
	s[n_wordlen - 1] = 0x01;

	rsa_write_len(pae_ctx, n_wordlen);
	dma_xdata2rsa(pae_ctx, m, PAE_RAM_BLOCK0, n_wordlen);

	for (i = 0; i < n_wordlen * 64; i++) {
		b_u_cmp = check_allzero(u, n_wordlen);
		b_v_cmp = check_allzero(v, n_wordlen);
		if ((b_u_cmp == 1) || (b_v_cmp == 1))
			break;
		if (nn_cmpbignumber_word(u, v, n_wordlen) == 0x01)
			euclid_one_round(pae_ctx, u, v, r, s, n_wordlen);
		else
			euclid_one_round(pae_ctx, v, u, s, r, n_wordlen);
	}
	return generate_z(z, u, v, r, s, n_wordlen);
}

uint8_t rsa_get_leadzero_count(uint32_t n_high)
{
	uint8_t j;
	uint8_t count;

	count = 0;
	for (j = 0; j < WORD_BITS; j++) {
		if ((g_bitset_32[j] & n_high) == 0)
			count++;
		else
			break;
	}

	return count;
}

/* calculate r*r%n */
void rsa_cal_rmultr_modn(struct str_pae *pae_ctx, uint32_t nbitlen)
{
	uint32_t j;
	uint32_t bt_find_one;

	bt_find_one = 0;

	for (j = 0; j < HALF_WORD_BITS; j++) {
		if ((g_bitset_16[j] & nbitlen) == 0) {
			if (bt_find_one == 1)
				rsa_command(pae_ctx, RSA_MULT, BLOCK02, BLOCK02, BLOCK02);
		} else {
			if (bt_find_one == 0) {
				bt_find_one = 1;
			} else {
				rsa_command(pae_ctx, RSA_MULT, BLOCK02, BLOCK02, BLOCK02);
				rsa_command(pae_ctx, RSA_MULT, BLOCK02, BLOCK02, BLOCK01);
			}
		}
	}
	rsa_command(pae_ctx, RSA_SUB, 0x02, 0x02, 0x00);
}

void rsa_calculate_rr_n(struct str_pae *pae_ctx,
		uint32_t *ptr_m, uint32_t n_lenbybit)
{
	uint32_t j;
	uint32_t n_lenbyword;
	uint32_t n0;
	uint32_t w;
	uint32_t modsubcount;
	uint32_t m_high;

	n_lenbyword = n_lenbybit / WORD_BITS;

	rsa_write_len(pae_ctx, n_lenbyword);

	n0 = ptr_m[n_lenbyword - 1];
	w = rsa_getmodparam(n0);
	rsa_write_param(pae_ctx, w);

	dma_xdata2rsa(pae_ctx, ptr_m, PAE_RAM_BLOCK0, n_lenbyword);
	dma_wr_allblock(pae_ctx, WORD_MASK_VALUE, PAE_RAM_BLOCK2,
		n_lenbyword);
	rsa_command(pae_ctx, RSA_SUB, BLOCK02, BLOCK02, BLOCK00);

	dma_wr_allblock(pae_ctx, 0x00, PAE_RAM_BLOCK3, n_lenbyword);
	rsa_write_ram(pae_ctx, PAE_RAM_BLOCK3, 0x01);
	rsa_command(pae_ctx, RSA_ADD, BLOCK02, BLOCK02, BLOCK03);

	m_high = ptr_m[0];

	modsubcount = rsa_get_leadzero_count(m_high);
	if (modsubcount > 0) {
		rsa_write_ram(pae_ctx, PAE_RAM_BLOCK3, 0x00);
		rsa_command(pae_ctx, RSA_ADD, BLOCK03, BLOCK00, BLOCK03);
		for (j = 0; j < modsubcount; j++)
			rsa_command(pae_ctx, RSA_ADD, BLOCK00, BLOCK00, BLOCK00);
		rsa_command(pae_ctx, RSA_ADD, BLOCK02, BLOCK02, BLOCK02);
		dma_wr_allblock(pae_ctx, 0x00, PAE_RAM_BLOCK1, n_lenbyword);
		rsa_command(pae_ctx, RSA_ADD, BLOCK00, BLOCK01, BLOCK03);
		rsa_command(pae_ctx, RSA_SUB, BLOCK01, BLOCK02, BLOCK00);
	} else {
		rsa_command(pae_ctx, RSA_ADD, BLOCK02, BLOCK02, BLOCK02);
		rsa_command(pae_ctx, RSA_SUB, BLOCK01, BLOCK02, BLOCK00);
	}
	rsa_cal_rmultr_modn(pae_ctx, n_lenbybit);
}
