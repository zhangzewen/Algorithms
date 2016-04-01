#ifndef ALGORITHMS_TIRE_H
#define ALGORITHMS_TIRE_H

struct node
{
    char ch;
    int count;
    struct node** child;
};


struct node* create_node();
void node_free(struct node** node);
int addText(struct node* root, char* str);
int searchText(struct node* root, char* str);
int searchPrev(struct node* root, char* str);
int searchSuffix(struct node* root, char* str);

#endif
