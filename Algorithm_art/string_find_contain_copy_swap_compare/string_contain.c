#include <stdio.h>
#include <stdlib.h>
#include "lib/lib.h"
/***method one***********
*just loop the both strings for compare 
*and the o(n) = m * n
*contain_string(const char *src, const char *dest)
*src is the target string 
*dest is the example string
************************/
int contain_element_of_string(const char *src, const char *dest)
{
	char *src_ptr = NULL;
	char *dest_ptr = NULL;
	int flag = 0;
	if (NULL == src ) {
		fprintf(stderr, "the src is NULL !\n");
		exit(1);
	}
	
	if (NULL == dest) {
		fprintf(stderr, "the dest is NULL !\n ");
		exit(1);
	}
	
	dest_ptr = dest;
	while(*dest_ptr != '\0') {
		src_ptr = src;
		while(*src_ptr != '\0') {
			if(*src_ptr == *dest_ptr) {
				break;
			}
			if(src_ptr - src == strlen(src))
			{
				flag = 1;
			}
			src_ptr++;
		}
		dest_ptr++;
	}
	return flag;
}




/***method one***********
* sort the src and desc string with quick_sort
*just 
************************/
int contain_element_of_string(const char *src, const char *dest)
{
	char *src_ptr = NULL;
	char *dest_ptr = NULL;
	char *src_ptr_p = NULL;
	char *dest_ptr_p = NULL;
	int len_src = 0;
	int len_dest = 0;
	src_ptr = calloc(strlen(src) + 1, sizeof(char));

	if(NULL == src_ptr) {
		return -1;
	}

	dest_ptr = calloc(strlen(src) + 1, sizeof(char));

	if(NULL == dest_ptr) {
		return -1;
	}
	
	len_src = strlen(src);
	len_dest = strlen(dest);
	strcpy(src_ptr, src);
	strcpy(dest_ptr, dest);

	quick_sort_for_char(src_ptr);
	quick_sort_for_char(dest_ptr);
	
	src_ptr_p = src_ptr;
	dest_ptr_p = dest_ptr;

	while(*src_ptr_p != '\0') {
		while(*dest_ptr_p != '\0') {
			if(strcmp(*src_ptr_p, *dest_ptr_p) != 0) {
				break;
			}
			*dest_ptr_p++;
		}
		if(src_ptr_p - src_ptr < len_dest ){
			return -1;
		}
		*src_ptr_p++;
	}
	
	return 0;
	free(src_ptr);
	free(dest_ptr);

}

//-----------------------------------------------------------

int CompareString(char *LongString, char *ShortString)
{
	int i = 0;
	int j	= 0;
	int ls_len = strlen(LongString);
	int ss_len = strlen(ShortString);
	for (i = 0; i < ls_len; i++)
	{
		for(j = 0; j < ss_len; j++)
		{
			if (LongString[i] == ShortString[j])
			{
				break;
			}
		}
		if (j == ls_len)
		{
			printf("false\n");
			break;
		}
	}
	printf("true\n");
	return 1;
}


//------------------------
第二种方法是使用快排，把两个字符串排出有序串 
然后再用类似于第一种的方法查找
O(m log m) + O(n log n) + O(m + n) 

//--------------------------------------
采用计数排序o(n + m)

void CounterSort(char *str, char *help_str)
{
	int help[26] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int len = strlen(str);
	for (i = 0; i < len; i++)
	{
		int index = str[i] - 'A';
		help[index]++;
	}

	for (j = 1; j < 26; j++)
	{
		help[j] += help[j - 1];
	}
	for (k = len - 1; k >= 0; k--)
	{
		int index = str[k] - 'A';
		int pos = help[index] - 1;
		help_str[pos] = str[k];
		help[index]--;
	}
}

void Compare(char *long_str, char *short_str)
{
	int pos_long = 0;
	int pos_short = 0;
	int len_long = strlen(long_str);
	int len_short = strlen(short_str);
	while(pos_short < len_short && pos_long < len_long)
	{
		while(long_str[pos_long] < short_str[pos_short] && pos_long < len_long -1)
			pos_leng++;
		while(short_str[len_short] == short_str[pos_short + 1])
				pos_short++;
		if (long_str[pos_long] != short_str[pos_short])
				break;
		pos_long++;
		pos_short++;
	}
	if (pos_short == len_short)
		printf("true\n");
	else
		printf("false\n");
}
int main()
{
	char strOne[] = "ABCDAK";
	char strTwo[] = "A";
	char *ptr_one = strOne;
	char *ptr_two = strtwo
	
	CounterSort(strOne, ptr_one);
	CounterSort(strTwo, ptr_two);
	Compare(ptr_one, ptr_two);
	return 0;
}
/*第三种方法是O（n+m）的hashtable
 *hash[26]，先全部清零，然后扫描短的字符串，若有相应的置1
 *计算hash[26]中1的个数，然后计为m
 *扫描长字符串的每一个字符a，若原来hash[a] == 1，则修改hash[a] = 0,并将m减1，若hash[a] == 0，则不做处理
 *若m == 0 或者扫描结束，推出循环
 */
 

int contain_string(const char *dest, const char *src )
{
	int hash[26] = {0};
	char *p_dest = NULL;
	char *p_src = NULL;
	char sum = 0;
	if (NULL == dest || NULL == src)
	{
		return -1;
	}

	p_dest = dest;
	p_src = src;

	while(*p_src != '\0') 
	{
		int index = *p_src - 'A';

		if (hash[index] == 0)
		{
			hash[index] = 1;
			sum++;
		}
		p_src++;
	}


	while(*p_src != '\0')
	{
		int index = *p_src - 'A';

		if(hash[index] == 1)
		{
			hash[index] = 0;

			num--;
			if (num == 0)
				break;
		}
	}

	if(num == 0)
		return 0;
	else
		return -1;
	return 0;
}
