#ifndef ALGORITHMS_ADJACENCY_LIST_H
#define ALGORITHMS_ADJACENCY_LIST_H

/*
 * idea  from http://www.geeksforgeeks.org/graph-and-its-representations/
*/

struct AdjListNode
{
    int point;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode* head;
};


struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void delAdjListNode(struct AdjListNode* head, int dest);
void freeAdjList(struct AdjListNode** head);
void delEdge(struct Graph* graph, int src, int dest);
void freeGraph(struct Graph** graph);


#endif  //  ALGORITHMS_ADJACENCY_LIST_H
