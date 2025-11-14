#include<stdio.h>
#define MAX 10

int parent[MAX];

int find(int i){
    while(parent[i]!=i){
        i = parent[i];
    }
    return i;
}

void unionSet(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main(){
    int n, e;
    int u,v,w;
    int min,a,b;
    int cost = 0;
    int edgesAccepted = 0;
    int weight[MAX][3];

    printf("Enter the number of vertex :");
    scanf("%d",&n);
    printf("Enter the number of edges :");
    scanf("%d",&e);

    printf("Enter the edges :(u,v,weight)");
    for(int i = 0;i<e;i++){
        scanf("%d%d%d",&weight[i][0],&weight[i][1],&weight[i][2]);
    }

    for(int i = 0;i<n;i++){
        parent[i]=i;
    }

    while(edgesAccepted<n-1){
        min =9999;

        for(int i = 0 ; i < e ; i++ ){
            if(weight[i][2]<min){
                min = weight[i][2];
                a = weight[i][0];
                b = weight[i][1];
                u = i;
            }
        }

        int set_a = find(a);
        int set_b = find(b);

        if(set_a!=set_b){
            printf("%d --- %d --weight--> %d",a,b,min);
            cost+=min;
            edgesAccepted++;
            unionSet(set_a,set_b);
        }
        weight[u][2]=9999;
    }
    printf("Minimum cost = %d",cost);
    return 0;
}