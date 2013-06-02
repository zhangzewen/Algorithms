#ifndef _SKIPLIST_INCLUDED_H_
#define _SKIPLIST_INCLUDED_H_


typedef struct SkipList_node_st *SkipList_node_t;
typedef struct SkipList_st *SkipList_t;

struct SkipList_node_st{
	void *data;
	int top_level;
	struct list_head level[];
};


struct SkipList_st{
	struct SkipList_node_t next;	
}

SkipList_node_t SkipList_node_malloc()
{
	SkipList_node_t	node = NULL;
	
	node = (SkipList_node_t) malloc(sizeof(struct SkipList_node_st));
	
	if(NULL == node) {
		return NULL;
	}
	
	
}

SkipList_t SkipList_malloc()
{
	
}

void SkipList_free(SkipList_node_t node)
{
	
}


#endif
