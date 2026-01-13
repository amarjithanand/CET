#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int n;

void findInDegree()
{
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }
}
void topologicalSorting()
{
    int count = 0;
    int queue[MAX], front = 0, rear = -1;
    findInDegree();
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }
    while (front<=rear)
    {
        int u = queue[front++];
        printf("%d\t", u + 1);
        count++;
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
            {
                queue[++rear] = v;
            }
            }
            
        }
    }

    if (count != n)
    {
        printf("A cycle is formed, so topological sorting cannot performed!!");
    }
}
int main()
{
    int edge, u, v;
    printf("Enter the number of the vertices :");
    scanf("%d", &n);
    printf("Enter the number of the edges :");
    scanf("%d", &edge);
    printf("Enter the edges (u,v):");
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u - 1][v - 1] = 1;
    }
    topologicalSorting();
    return 0;
}
