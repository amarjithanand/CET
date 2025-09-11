#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *ln;
};
struct sll
{
    struct node *h;
};
void push(struct sll *sl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    t->ln = sl->h;
    sl->h= t;
}
void traverse(struct sll *sl)
{
    struct node *ptr =sl->h;
    while(ptr!=NULL)
    {
       printf("%d\n",ptr->data);
       ptr=ptr->ln;
    }
}
void pop(struct sll *sl){
    if(sl->h==NULL)
    {
        printf("\nUnderflow");
    }
    else{
        int item;
        item =sl->h->data;
        printf("\n%d is removed",item);
        sl->h=sl->h->ln;
    }
}

int main()
{
    int ch;
    struct sll sl;
    sl.h = NULL;
    do{ printf("\nMENU\n1. Push\n2. Pop\n3.  Traversal\n4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(&sl);
            break;
            case 2: pop(&sl);
            break;
            case 3: traverse(&sl);
            break;
        }
    }while(ch<4);
    return 0;
}
