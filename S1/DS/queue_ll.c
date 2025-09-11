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

void enqueue(struct sll *sl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    t->ln=NULL;
    if(sl->h==NULL){
        sl->h=t;
    }
    else{
        struct node *ptr=sl->h;
        while(ptr->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        ptr->ln=t;
    }
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
void dequeue(struct sll *sl){
    if(sl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        int item;
        item =sl->h->data;
        printf("\n%d is removed",item);
        sl->h=sl->h->ln;
        free(sl->h);
    }
}

int main()
{
    int ch;
    struct sll sl;
    sl.h = NULL;
    do{ printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue(&sl);
            break;
            case 2: dequeue(&sl);
            break;
            case 3: traverse(&sl);
            break;
        }
    }while(ch<4);
    return 0;
}
