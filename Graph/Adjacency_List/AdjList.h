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
    bool directed; //有向还是无向
    bool acyclic; //无环还是有环
    struct AdjList* array;
};

typedef enum{
    WHITE = 0,
    GRAY,
    BLACK
}COLOR;

struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V, bool directed = false, bool acyclic = false);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void delAdjListNode(struct AdjListNode* head, int dest);
void freeAdjList(struct AdjListNode** head);
void delEdge(struct Graph* graph, int src, int dest);
void freeGraph(struct Graph** graph);
void BFS(struct Graph* graph, int i);
void DFS(struct Graph* graph);
void topologicalSort(Graph* graph);


#endif  //  ALGORITHMS_ADJACENCY_LIST_H
