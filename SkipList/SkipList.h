#ifndef __SKIPLIST_H
#define __SKIPLIST_H

#define SKIPLIST_MAXLEVEL 8 

typedef struct skiplist_node_st skiplist_node_t;
typedef struct skiplist_level_st skiplist_level_t;
typedef struct skiplist_st skiplist_t;

struct skiplist_node_st {
    double score;
    struct skiplist_node_st *backward;
    struct skiplist_level_st {
        struct skiplist_node_st *forward;
    }level[];
};

struct skiplist_st {
    struct skiplist_node_st *header, *tail;
    unsigned long length;
    int level;
};


skiplist_t *skiplist_create(void);

void skiplist_destroy(skiplist_t *sl);

skiplist_node_t *skiplist_insert(skiplist_t *sl, double score);

int skiplist_delete(skiplist_t *sl, double score);

int skiplist_find(skiplist_t *sl, double score);

void Print(skiplist_t *sl);

#endif

