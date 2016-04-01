#include "AdjList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    printf("\n=======================\n");
    delEdge(graph, 1, 4);
    printGraph(graph);
    return 0;
}
