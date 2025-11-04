#include<stdio.h>
#define V 5

// Creating Adjacency Matrix
void createGraph(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Displaying adjacency Matrix
void displayMatrix(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

// DFS function (recursive)
void depthFirstUtil(int graph[V][V], int visited[V], int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            depthFirstUtil(graph, visited, i);
        }
    }
}

// Wrapper for DFS
void depthFirst(int graph[V][V], int start) {
    int visited[V] = {0};
    printf("\nDFS Traversal: ");
    depthFirstUtil(graph, visited, start);
    printf("\n");
}

void main() {
    int graph[V][V] = {0};

    createGraph(graph, 0, 1);
    createGraph(graph, 0, 2);
    createGraph(graph, 0, 4);
    createGraph(graph, 1, 3);
    createGraph(graph, 2, 3);
    createGraph(graph, 2, 4);
    createGraph(graph, 3, 4);

    printf("Adjacency Matrix:\n");
    displayMatrix(graph);

    depthFirst(graph, 0);
}
