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

// Enqueue Function
void enqueue(int queue[V], int *front, int *rear, int item) {
    if (*rear == V - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    (*rear)++;
    queue[*rear] = item;
}

// Dequeue Function
int dequeue(int queue[V], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        (*front)++;
    }
    return item;
}

// isEmpty Function
int isEmpty(int front) {
    return (front == -1);
}

// BFS function
void breadthFirst(int graph[V][V], int start) {
    int visited[V] = {0};
    int queue[V];
    int front = -1, rear = -1;

    visited[start] = 1;
    enqueue(queue, &front, &rear, start);

    printf("\nBFS Traversal: ");

    while (!isEmpty(front)) {
        int v = dequeue(queue, &front, &rear);
        printf("%d ", v);

        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, &front, &rear, i);
            }
        }
    }
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

    breadthFirst(graph, 0);
}
