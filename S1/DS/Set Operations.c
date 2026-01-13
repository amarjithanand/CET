#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int item,a[MAX],parent[MAX],i=-1;
void make_set()
{
    i++;
    printf("Enter the item :");
    scanf("%d",&item);
    a[i]=item;
    parent[i]=item;
    if(i==4){
        printf("ITEMS   : ");
        for(int j=0;j<=i;j++){
        printf("|  %d  |",a[j]);
    }
    printf("\n");
    printf("PARENTS : ");
     for(int j=0;j<=i;j++){
        printf("|  %d  |",parent[j]);
    }
    }
    
}
int find_set(int key){
    int j;
    for(j=0;j<=i;j++){
        if(a[j]==key)
        {
            break;
        }
    }
    if(a[j]==parent[j])
        return parent[j];
    else
        return find_set(parent[j]);
}
void union_set(){
    int u1,u2,p,q;
    printf("Enter the elements to be union :");
    scanf("%d%d",&u1,&u2);
    int x =find_set(u1);
    int y=find_set(u2);
    if(x!=y){
        for(int j=0;j<=i;j++){
        if(parent[j]==x)
            p=j;
        }
        for(int j=0;j<=i;j++){
            if(parent[j]==y)
                q=j;
        }
    parent[q]=parent[p];
    }
}
void main(){
    make_set();
    make_set();
    make_set();
    make_set();
    make_set();
    union_set();
    union_set();
    int y=find_set(4);
    printf("%d",y);
     printf("ITEMS  : ");
        for(int j=0;j<=i;j++){
        printf("|  %d  |",a[j]);
    }
    printf("\n");
    printf("PARENTS : ");
     for(int j=0;j<=i;j++){
        printf("|  %d  |",parent[j]);
    }
    
}
