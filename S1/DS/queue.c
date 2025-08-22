#include<stdio.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;
void ins();
void del();
void traverse();

void ins(){
    if(rear==MAX-1)
    {
        printf("Overflow Error!!!");
    }
    else{
        if(front==-1)
            front++;
        int item;
        printf("Enter the item :");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
    }
}
void del(){
    if(front==-1)
    {
        printf("Underflow Error!!!");
    }
    else{
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
        int item=queue[front];
        front++;
        printf("%d is removed",item);
        }
    }
}
void traverse(){
    if(front==-1)
    {
        printf("Queue is empty!!!");
    }
    else{
        int i;
        for(i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    int ch;
    do{
        printf("MENU\n1. Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: ins();
            break;
            case 2: del();
            break;
            case 3: traverse();
            break;
        }
    }while(ch<4);
return 0;
}
