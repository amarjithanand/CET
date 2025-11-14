#include<stdio.h>
#define MAX 10
#define INF 9999

int main(){
    int n;
    int cost[MAX][MAX];
    int visited[MAX]={0};
    int a,b,min,edge=0,total_cost=0;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter the cost matrix of the graph :");
    for(int i = 0; i< n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j] = INF;
            }
        }
    }

    visited[0] = 1;
    while(edge<n-1){
        min = INF;
        for(int i = 0; i <n; i++){
            if(visited[i]){
                for(int j = 0; j< n; j++){
                    if(!visited[j]&&cost[i][j]<min){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }    
            }
        }
        printf("%d - %d : %d",a,b,min);
        total_cost += min;
        edge++;
        visited[b]=1;
    }
    printf("Total cost = %d",total_cost);
    return 0;
}