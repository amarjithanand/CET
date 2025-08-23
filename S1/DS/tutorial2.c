#include<stdio.h>
#include<string.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;


void ins(char a){
    if(rear==MAX-1)
    {
        printf("Overflow Error!!!");
    }
    else{
        if(front==-1)
            front++;
        int item;
        item=a;
        rear++;
        queue[rear]=item;
    }
}
int main()
{
    char str[MAX],str1[MAX];
    printf("\nEnter the string :");
    scanf("%s",(str));
    for(int i= strlen(str)-1;i>-1;i--)
    {
        ins(str[i]);
    }
    for(int i=front;front<=rear+1;i++){
        str1[i]=queue[front];
        front++;
    }
if(!strcmpi(str,str1))
    printf("String is palindrome!!!");
else
    printf("String is not palindrome!!!");

return 0;
}
