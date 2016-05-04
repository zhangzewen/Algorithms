/*
 * from http://www.geeksforgeeks.org/graph-and-its-representations/
*/

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <iostream>
#include "AdjList.h"

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->point = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct  Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    int i = 0;
    for (; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    if (NULL == graph->array[src].head) {
        graph->array[src].head = newAdjListNode(src);
    }

    if (NULL == graph->array[dest].head) {
        graph->array[dest].head = newAdjListNode(dest);
    }

    struct AdjListNode* newNode= newAdjListNode(dest);
    newNode->next = graph->array[src].head->next;
    graph->array[src].head->next = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head->next;
    graph->array[dest].head->next = newNode;
}


void delAdjListNode(struct AdjListNode* head, int dest)
{
    if (NULL == head) {
        return;
    }
    struct AdjListNode* current = head->next;
    struct AdjListNode* prev = head;
    while(current && current->point != dest) {
        prev = current;
        current = current->next;
    }

    if (NULL == current) {
        return;
    }

    prev->next = current->next;
    free(current);
    current = NULL;
}
void freeAdjList(struct AdjListNode** head)
{
    if (NULL == *head) {
        return;
    }

    struct AdjListNode* tmp = (*head)->next;
    while(tmp) {
        (*head)->next = tmp->next;
        free(tmp);
        tmp = (*head)->next;
    }

    free(*head);
    *head = NULL;

}

void delEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* head = graph->array[src].head;
    delAdjListNode(head, dest);
    head = graph->array[dest].head;
    delAdjListNode(head, src);
}

void printGraph(struct Graph* graph)
{
    int v = 0;
    for (; v < graph->V; v++) {
        struct AdjListNode* pCrawl = graph->array[v].head->next;
        printf("\n Adjacency list of vertex %d\n head", v);
        while(pCrawl) {
            printf("->%d", pCrawl->point);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


void freeGraph(struct Graph** graph)
{
    if (NULL == *graph) {
        return;
    }
    int i = 0;
    for (; i < (*graph)->V; i++) {
        freeAdjList(&((*graph)->array[i].head));
    }
    free((*graph)->array);
    free(*graph);
    *graph = NULL;
}

void BFS(struct Graph* graph, int i)
{
    //染白
    std::map<int, COLOR> colormap;
    std::map<int, int> distancemap;
    std::map<int, AdjListNode*> parentmap;
    colormap.clear();
    distancemap.clear();
    parentmap.clear();

    if (i > graph->V) {
        return ;
    }

    struct AdjListNode* relateVectors = graph->array[i].head->next;
    while(relateVectors) {
        colormap.insert(std::make_pair(relateVectors->point, WHITE));
        distancemap.insert(std::make_pair(relateVectors->point, -1));
        parentmap.insert(std::make_pair(relateVectors->point, static_cast<AdjListNode*>(0)));
        relateVectors = relateVectors->next;
    }
    colormap.insert(std::make_pair(i, GRAY));
    distancemap.insert(std::make_pair(i, 0));
    parentmap.insert(std::make_pair(i, static_cast<AdjListNode*>(0)));
    std::queue<int> Queue;
    Queue.push(i);
    while (!Queue.empty()) {
        int point = Queue.front();
        Queue.pop();
        struct AdjListNode* relateVectors = graph->array[point].head->next;
        while(relateVectors) {
            if (colormap[relateVectors->point] == WHITE) {
                colormap[relateVectors->point] = GRAY;
                distancemap[relateVectors->point] = distancemap[point] + 1;
                parentmap[relateVectors->point] = graph->array[point].head;
                Queue.push(relateVectors->point);
            }
            relateVectors = relateVectors->next;
        }
        colormap[point] = BLACK;
        std::cout << point << std::endl;
    }
}
