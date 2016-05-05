#include "AdjList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int V = 4;
    struct Graph* graph = createGraph(V, true, false);
    //addEdge(graph, 5, 2);
    //addEdge(graph, 5, 0);
    //addEdge(graph, 4, 0);
    //addEdge(graph, 4, 1);
    //addEdge(graph, 2, 3);
    //addEdge(graph, 3, 1);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    printGraph(graph);
    printf("\n=======================\n");
    BFS(graph, 5);
    printf("\n=======================\n");
    DFS(graph);
    printf("\n=======================\n");

    topologicalSort(graph);
    freeGraph(&graph);
    return 0;
}
