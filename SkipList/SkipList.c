#include "SkipList.h"
#include <stdlib.h>
#include <stdio.h>

skiplist_node_t *skiplist_node_create(int level, double score)
{
    skiplist_node_t * node = NULL;
		node = calloc(1, sizeof(struct skiplist_node_st) + level*sizeof(struct skiplist_level_st));
    node->score = score;
    return node;
}

skiplist_t *skiplist_create(void) {
    int j;
    skiplist_t *sl;

    sl = calloc(1, sizeof(struct skiplist_st));
    sl->level = 1;
    sl->length = 0;
    sl->header = skiplist_node_create(SKIPLIST_MAXLEVEL, 0);
    for(j = 0; j < SKIPLIST_MAXLEVEL; j++) {
        sl->header->level[j].forward = NULL;
    }
    sl->header->backward = NULL;
    sl->tail = NULL;
    return sl;
}

void skiplist_free_node(skiplist_node_t *sn) {
    free(sn);
}

void skiplist_destroy(skiplist_t *sl) {
    skiplist_node_t *node = sl->header->level[0].forward, *next;

    free(sl->header);
    while(node) {
        next = node->level[0].forward;
        skiplist_free_node(node);
        node = next;
    }
    free(sl);
}

int slRandomLevel(void) {
    int level = 1;
    while((rand()&0xFFFF) < (0.5 * 0xFFFF)) 
        level += 1;
    return (level < SKIPLIST_MAXLEVEL) ? level : SKIPLIST_MAXLEVEL;
}

skiplist_node_t *skiplist_insert(skiplist_t *sl, double score) {
    skiplist_node_t *update[SKIPLIST_MAXLEVEL];
    skiplist_node_t *node;

    node = sl->header;
    int i, level;
    for ( i = sl->level-1; i >= 0; i--) {
        while(node->level[i].forward && node->level[i].forward->score < score) {
            node = node->level[i].forward;
        }
        update[i] = node;
    }
    level = slRandomLevel();
    if (level > sl->level) {
        for (i = sl->level; i< level ;i++) {
            update[i] = sl->header;
        }
        sl->level = level;
    }
    node = skiplist_node_create(level, score);
    for (i = 0; i < level; i++) {
        node->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = node;
    }

    node->backward = (update[0] == sl->header? NULL : update[0]);
    if (node->level[0].forward)
        node->level[0].forward->backward = node;
    else
        sl->tail = node;
    sl->length++;
    return node;
}

void skiplist_delete_node(skiplist_t *sl, skiplist_node_t *x, skiplist_node_t **update){
    int i;
    for (i = 0; i < sl->level; i++) {
        if (update[i]->level[i].forward == x) {
            update[i]->level[i].forward = x->level[i].forward;
        }
    }
    if (x->level[0].forward) {
        x->level[0].forward->backward = x->backward;
    } else {
        sl->tail = x->backward;
    }
    while (sl->level > 1 && sl->header->level[sl->level-1].forward == NULL) 
        sl->level--;
    sl->length--;
}

int skiplist_delete(skiplist_t *sl, double score) {
    skiplist_node_t *update[SKIPLIST_MAXLEVEL], *node;
    int i;

    node = sl->header;
    for(i = sl->level-1; i >= 0; i--) {
        while (node->level[i].forward && node->level[i].forward->score < score) {
            node = node->level[i].forward;
        }
        update[i] = node;
    }
    node = node->level[0].forward;
    if (node && score == node->score) {
        skiplist_delete_node(sl, node, update);
        skiplist_free_node(node);
        return 1;
    } else {
        return 0;
    }
    return 0;
}


int skiplist_find(skiplist_t *sl, double score) {
    skiplist_node_t *node;
    int i;

    node = sl->header;
    for (i = sl->level-1; i >= 0 ;i--) {
        while(node->level[i].forward && node->level[i].forward->score < score) {
            node = node->level[i].forward;
        }
    }   
    node = node->level[0].forward;
    if (node && score == node->score) {
        printf("Found %d\n",(int)node->score);
        return 1;
    } else {
        printf("Not found %d\n", (int)score);
        return 0;
    }   
}


void Print(skiplist_t *sl) {
    skiplist_node_t *node;
    int i;
    for (i = 0; i < SKIPLIST_MAXLEVEL; i++) {
        printf("LEVEL[%d]: ", i);
        node = sl->header->level[i].forward;
        while(node) {
            printf("%d -> ", (int)(node->score));
            node = node->level[i].forward;
        }
        printf("NULL\n");
    }
}

