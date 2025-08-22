#include<stdio.h>
#define MAX 10

int stack[MAX];
int top=-1;
void push();
void pop();
void traverse();

void push(){
    if(top==MAX-1)
    {
        printf("Overflow Error!!!");
    }
    else{
        int item;
        printf("Enter the item :");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
void pop(){
    if(top==-1)
    {
        printf("Underflow Error!!!");
    }
    else{
        int item=stack[top];
        top--;
        printf("%d is removed",item);
    }
}
void traverse(){
    if(top==-1)
    {
        printf("Stack is empty!!!");
    }
    else{
        int i;
        for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int ch;
    do{
        printf("\nMENU\n1. Push\n2.Pop\n3.Traverse\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: traverse();
            break;
            default: break;
        }
    }while(ch<4&&ch>0);
return 0;
}
