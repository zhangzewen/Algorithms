#include "Tire.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define UPPER(x) (x - 32)
#define LOWER(x) (x + 32)
#define IS_UPPER(x) (65 <= x && x <= 90)
#define IS_LOWER(x) (97 <= x && x <= 122)

struct node* create_node()
{
    struct node* new = NULL;
    new = (struct node*)malloc(sizeof(struct node));
    if (NULL == new) {
        return NULL;
    }
    new->ch = '\0';
    new->count = 1;
    new->child = (struct node**)malloc(sizeof(struct node**) * 26);
    if (NULL == new->child) {
        free(new);
    }
    memset(new->child, 0, sizeof(struct node**) * 26);
    return new;
}

void node_free(struct node** node)
{
    if (NULL == *node) {
        return ;
    }
    int index = 0;

    for(index = 0; index < 26; index++) {
        if ((*node)->child[index]) {
            free((*node)->child[index]);
        }
    }
    free((*node)->child);

    free(*node);
    *node = NULL;
}


int addText(struct node* root, char* str)
{
    if (NULL == str) {
        return 0;
    }

    char* ptr = str;
    struct node* nodeptr = root;
    while(*ptr != '\0') {
        int index = 0;
        if (IS_LOWER(*ptr)) {
            index = *ptr - 97;
        } else {
            index = *ptr - 65;
        }
        if (NULL == nodeptr->child[index]) {
            struct node* tmp = create_node();
            if (NULL == tmp) {
                return -1;
            }
            tmp->ch = index + 97;
            nodeptr->child[index] = tmp;
        } else {
            nodeptr->child[index]->count++;
        }
        ptr++;
        nodeptr = nodeptr->child[index];
    }
    return 0;
}

int searchText(struct node* root, char* str)
{
    if (NULL == str) {
        return 0;
    }
    char* ptr = str;
    struct node* nodeptr = root;
    while (*ptr != '\0') {
        int index = 0;
        if (IS_LOWER(*ptr)) {
            index = *ptr - 97;
        } else {
            index = *ptr - 65;
        }
        if (NULL == nodeptr->child[index]) {
            return 0;
        }
        ptr++;
        nodeptr = nodeptr->child[index];
    }
    return nodeptr->count;
}


