#include <stdio.h>
#include <stdlib.h>

/***method one***********
*just loop the both strings for compare 
*and the o(n) = m * n
*contain_string(const char *src, const char *dest)
*src is the target string 
*dest is the example string
************************/
int contain_string(const char *src, const char *dest)
{
	char *src_ptr = NULL;
	char *dest_ptr = NULL;
	if (NULL == src ) {
		fprintf(stderr, "the src is NULL !\n");
		exit(1);
	}
	
	if (NULL == dest) {
		fprintf(stderr, "the dest is NULL !\n ");
		exit(1);
	}
	
	src_ptr = src;
	
	while(*src_ptr != '\0') {
		dest_ptr = dest;
		while(*dest_ptr != '\0') {
			if(*dest_ptr == *src_ptr)
		}
	}
	while(src_ptr)	
}




/***method one***********
* sort the src and desc string with quick_sort
*just 
*
*
*
*
*
*
*

************************/
