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