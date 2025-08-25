#include<stdio.h>
#include<string.h>
#define MAX 10

char stack[MAX];
int top=-1;
void push(char);
void pop();

void push(char a){
    char item = a;
    if(top==MAX-1)
    {
        printf("\nOverflow Error!!!");
    }
    else{
        top++;
        stack[top]=item;
    }
}
void pop(){
    char str1[MAX];
        for(int i=0;top>-1;i++){
            str1[i]=stack[top];
            top--;
        }        
    printf("\n%s",str1);
}

int main()
{
    char str[MAX];
    printf("\nEnter the string :");
    scanf("%s",(str));
    for(int i= 0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    pop();
return 0;
}
