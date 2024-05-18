

#include <linux/module.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/kernel.h> /* add for log */
#include <linux/ctype.h> /* add for tolower */
#include <linux/slab.h>
#include <linux/jhash.h> /* add for jhash */

#include "nf_hn_common.h"

const char *strfind(const char *s1, const char *s2)
{
	register const unsigned char *s = (unsigned char *)s1;
	register const unsigned char *p = (unsigned char *)s2;

	do {
		if (!*p)
			return (const char *)s1;
		if (*p == *s || tolower(*p) == tolower(*s)) {
			++p;
			++s;
		} else {
			p = s2;
			if (!*s)
				return NULL;
			s = ++s1;
		}
	} while (1);
}

const char *strfindpos(const char *s1, const char *s2, int len)
{
	register const unsigned char *s = (unsigned char *)s1;
	register const unsigned char *p = (unsigned char *)s2;

	do {
		if (!*p)
			return (const char *)s1;
		if (*p == *s || tolower(*p) == tolower(*s)) {
			++p;
			++s;
		} else {
			p = s2;
			if (!*s || len == 0)
				return NULL;
			s = ++s1;
			len--;
		}
	} while (1);
}

const char *strfinds2(const char *s1, const char *s2, int s2l)
{
	register const unsigned char *s = (unsigned char *)s1;
	register const unsigned char *p = (unsigned char *)s2;

	do {
		if (p  == (const unsigned char *) s2 + s2l || !*p)
			return (const char *)s1;
		if (*p == *s || tolower(*p) == tolower(*s)) {
			++p;
			++s;
		} else {
			p = (const unsigned char *)s2;
			if (!*s)
				return NULL;
			s = (const unsigned char *) ++s1;
		}
	} while (1);
}

const char *substring(const char *src, const char *f, const char *s, int *l)
{
	/* "k=<xxx>"  f="k=<"  s=">" ret="xxx" */
	const char *pf = NULL;
	const char *ps = NULL;
	const char *ret = NULL;
	int datalen = *l;
	int flen = strlen(f);

	*l = 0;
	if (flen == 0 || strlen(s) == 0)
		return NULL;

	pf = strfindpos(src, f, datalen);
	if (NULL == pf)
		return NULL;

	ps = strfindpos(pf + flen, s, datalen - (pf + flen - src));
	if (NULL == ps)
		return NULL;

	ret = pf + strlen(f);
	*l = ps - ret;
	return ret;
}

void byte_to_hex(const void *pin, int ilen, void *pout, int olen)
{
	char hex[] = "0123456789ABCDEF";
	int i = 0;
	unsigned char *input = (unsigned char *)pin;
	unsigned char *output = (unsigned char *)pout;

	if (ilen <= 0 || olen <= 1)
		return;
	for (i = 0; i < ilen; i++) {
		if (i * 2 + 1 > olen-1)
			break;
		output[i * 2] = hex[input[i] / 16];
		output[i * 2 + 1] = hex[input[i] % 16];
	}
	if (i * 2 <= olen)
		output[i * 2] = 0;
	else
		output[(i - 1) * 2 + 1] = 0;

}

unsigned char hex_string_to_value(unsigned char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else if (ch >= 'A' && ch <= 'F')
		return (ch - 'A') + 10;
	else if (ch >= 'a' && ch <= 'f')
		return (ch - 'a') + 10;
	return 0;
}

void hex_to_byte(const void *pin, int inlen, void *pout, int olen)
{
	int i = 0;
	int j = 0;
	unsigned char *input = (unsigned char *)pin;
	unsigned char *output = (unsigned char *)pout;
	int n = inlen / 2;

	output[0] = 0;
	if (olen < inlen / 2 || inlen <= 1)
		return;

	for (i = 0; i < n; i++) {
		output[i] = 0;
		for (j = 0; j < 2; j++) {
			output[i] += hex_string_to_value(input[i * 2 + j]);
			if (j == 0)
				output[i] *= 16;
			}
		}
}

char dec2hex(short int c)
{
	if (0 <= c && c <= 9) {
		return c + '0';
	} else if (10 <= c && c <= 15) {
		return c + 'A' - 10;
	} else {
		return -1;
	}
}

int urlencode(char* url, int buf_len)
{
	int i = 0;
	int len = strlen(url);
	int res_len = 0;
	char res[1024] = {0};

	for (i = 0; i < len; ++i) {
		char c = url[i];

		if (res_len > 1019) {
			pr_info("hnad: error EOK %s %d", __func__, __LINE__);
			return -1;
		}

		if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') ||
				('A' <= c && c <= 'Z') || c == '.') {
			res[res_len++] = c;
		} else {
			int i0;
			int i1;
			int j = (short int)c;
			if (j < 0)
				j += 256;

			i1 = j / 16;
			i0 = j - i1 * 16;
			res[res_len++] = '%';
			res[res_len++] = dec2hex(i1);
			res[res_len++] = dec2hex(i0);
		}
	}

	res[res_len] = '\0';
	if (strlen(res) > buf_len - 1) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		return -1;
	}

	if (strncpy_s(url, strlen(res) + 1, res, strlen(res)) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		return -1;
	}
	return 0;
}

u64 get_cur_time(void)
{
	u64 ret = (u64)jiffies;

	ret = div_u64(ret*1000, HZ);
	return ret;
}

/* remove the blank char from the right, fill with \0 */
static void right_trim(char *p, int len)
{
	char *pos = p + len - 1;

	while (pos >= p) {
		if (*pos == ' ' || *pos == '\t' || *pos == '\f' ||
				*pos == '\v' || *pos == '\0' || *pos == 160 ||
				*pos == '\r' || *pos == '\n')
					*pos = 0;
		else
			break;
		pos--;
	}
}

/* remove the blank char from the left */
const char *left_trim(const char *p)
{
	const char *pos = p;

	while (*pos != 0) {
		if (*pos == ' ' || *pos == '\t' || *pos == '\f' ||
				*pos == '\v' || *pos == '\0' || *pos == 160 ||
				*pos == '\r' || *pos == '\n')
			pos++;
		else
			break;
	}
	return pos;
}

char *get_url_path(const char *data, int datalen)
{
	int uplen = datalen;
	char *temurl;
	const char *temurl1;
	char *temp;
	const char *urlpath = substring(data, " ", " HTTP", &uplen);

	if (uplen == 0) {
		pr_info("hnad:upath ul=%d hl=%d\n", uplen, datalen);
		return NULL;
	}

	temurl = kmalloc(uplen + 1, GFP_ATOMIC);
	if (temurl == NULL)
		return NULL;

	if (memcpy_s(temurl, uplen + 1, urlpath, uplen) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temurl);
		return NULL;
	}
	temurl[uplen] = 0;
	right_trim(temurl, strlen(temurl));
	temurl1 = left_trim(temurl);

	temp = kmalloc(uplen + 65, GFP_ATOMIC);
	if (temp == NULL) {
		kfree(temurl);
		return NULL;
	}
	if (snprintf_s(temp, uplen + 65, uplen + 64, "%s", temurl1) < 0) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temurl);
		kfree(temp);
		return NULL;
	}
	uplen = strlen(temurl1);
	temp[uplen] = 0;
	kfree(temurl);
	return temp;
}

char *add_refer_for_data(const char *data, int datalen, char *url)
{
	int ref_len = datalen;
	char *temref = NULL;
	const char *temref1 = NULL;
	char *temref2 = NULL;
	char *temp = NULL;
	const char *refer = substring(data, "Referer:", "\n", &ref_len);
	int url_len = strlen(url);

	if (ref_len == 0) {
		pr_info("hnad: add_refer_for_data, no Referer in HTTP\n");
		return url;
	}

	temref = kmalloc(ref_len + 1, GFP_ATOMIC);
	if (temref == NULL) {
		return url;
	}
	if (memcpy_s(temref, ref_len + 1, refer, ref_len) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temref);
		return url;
	}
	temref[ref_len] = 0;

	right_trim(temref, strlen(temref));
	temref1 = left_trim(temref);
	ref_len = strlen(temref1);
	pr_info("hnad: %s referer:%s", __func__, temref1);

	temref2 = kmalloc(ref_len + 256, GFP_ATOMIC);
	if (temref2 == NULL) {
		kfree(temref);
		return url;
	}
	if (memcpy_s(temref2, ref_len + 256, temref1, ref_len) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		goto out;
	}
	temref2[ref_len] = 0;

	if (urlencode(temref2, ref_len + 256) != 0) {
		goto out;
	}
	ref_len = strlen(temref2);

	temp = kmalloc(url_len + ref_len + 33, GFP_ATOMIC);
	if (temp == NULL) {
		goto out;
	}
	if (snprintf_s(temp, url_len + ref_len + 33, url_len + ref_len + 32,
		"%s&__PARAM_REFERER__=%s", url, temref2) < 0) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temp);
		goto out;
	}

	kfree(url);
	url = temp;
out:
	kfree(temref);
	kfree(temref2);
	return url;
}

/* return : http://xxx.com/yyy */
char *get_url_form_data(const char *data, int datalen)
{
	int uplen = datalen;
	int hlen = datalen;
	char *temurl;
	char *temhost;
	const char *temurl1;
	const char *temhost1;
	char *temp;
	const char *urlpath = substring(data, " ", " HTTP", &uplen);
	const char *host = substring(data, "Host:", "\n", &hlen);

	if (uplen == 0 || hlen == 0) {
		pr_info("hnad:upath ul=%d hl=%d\n", uplen, hlen);
		return NULL;
	}

	if (strfindpos(urlpath, "http://", 10)) {
		const char *urltem = left_trim(urlpath);
		int len = uplen - (urltem - urlpath);

		if (len > 0) {
			temurl = kmalloc(len + 1, GFP_ATOMIC);
			if (temurl == NULL)
				return NULL;

			if (memset_s(temurl, len + 1, 0, len + 1) != EOK) {
				pr_info("hnad: error EOK %s %d", __func__, __LINE__);
				kfree(temurl);
				return NULL;
			}
			if (memcpy_s(temurl, len + 1, urltem, len) != EOK) {
				pr_info("hnad: error EOK %s %d", __func__, __LINE__);
				kfree(temurl);
				return NULL;
			}
			return temurl;
		}
	}

	temurl = kmalloc(uplen + 1, GFP_ATOMIC);
	if (temurl == NULL)
		return NULL;
	temhost = kmalloc(hlen + 1, GFP_ATOMIC);
	if (temhost == NULL) {
		kfree(temurl);
		return NULL;
	}

	if (memcpy_s(temurl, uplen + 1, urlpath, uplen) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temhost);
		kfree(temurl);
		return NULL;
	}
	temurl[uplen] = 0;
	if (memcpy_s(temhost, hlen + 1, host, hlen) != EOK) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temhost);
		kfree(temurl);
		return NULL;
	}
	temhost[hlen] = 0;
	right_trim(temurl, strlen(temurl));
	temurl1 = left_trim(temurl);

	right_trim(temhost, strlen(temhost));
	temhost1 = left_trim(temhost);
	temp = kmalloc(uplen + hlen + 65, GFP_ATOMIC);
	if (temp == NULL) {
		kfree(temhost);
		kfree(temurl);
		return NULL;
	}

	if (snprintf_s(temp, uplen + hlen + 65, uplen + hlen + 64, "http://%s%s", temhost1, temurl1) < 0) {
		pr_info("hnad: error EOK %s %d", __func__, __LINE__);
		kfree(temhost);
		kfree(temurl);
		kfree(temp);
		return NULL;
	}
	kfree(temhost);
	kfree(temurl);
	return temp;
}

unsigned int get_hash_id(int uid)
{
	unsigned int  hid = jhash_3words(uid, 0, 0, 1005);

	hid %= MAX_HASH;
	return hid;
}

