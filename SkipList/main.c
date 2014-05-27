#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SkipList.h"

int main(int argc, char *argv[])
{
	srand((unsigned)time(0));
	int count = 20, i;

	printf("### Function Test ###\n");

	printf("=== Init Skip List ===\n");
	skiplist_t * sl = skiplist_create();
	for ( i = 0; i < count; i++) {
		skiplist_insert(sl,i);
	}   
	printf("=== Print Skip List ===\n");
	Print(sl);

	printf("=== Search Skip List ===\n");
	for (i = 0; i < count; i++) {
		int value = rand()%(count+10);
		skiplist_find(sl, value);
	}   
	printf("=== Delete Skip List ===\n");
	for (i = 0; i < count+10; i+=2) {
		printf("Delete[%d]: %s\n", i, skiplist_delete(sl, i)?"SUCCESS":"NOT FOUND");
	}   
	Print(sl);

	skiplist_destroy(sl);
	sl = NULL;
	return 0;
}
