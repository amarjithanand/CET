 #include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *ln;
};
struct cll
{
    struct node *h;
};
void insertStart(struct cll *cl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    if(cl->h==NULL){
        t->ln=t;
        cl->h=t;
    }
    struct node *ptr;
    ptr=cl->h;
    while(ptr->ln!=NULL){
        ptr=ptr->ln;
    }
    ptr->ln=t;
    t->ln = cl->h;
    cl->h= t;
}

void insertMiddle(struct cll *cl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item,value;
    printf("\nAfter Which element to be the item is to placed  : ");
    scanf("%d", &value);
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    struct node *ptr =cl->h;
    printf("%d",ptr->data);
    while(ptr!=NULL)
    {
        if(ptr->data==value)
        {
            break;
        }
        else{
            ptr=ptr->ln;
        }
    }
    if(ptr==NULL){
        printf("\nNo such Item Found in the list");
    }
    else{
        t->ln=ptr->ln;
        ptr->ln=t;
    }
}
void insertEnd(struct cll *cl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    t->ln=NULL;
    if(cl->h==NULL){
        t->ln=t;
        cl->h=t;
    }
    else{
        struct node *ptr=cl->h;
        while(ptr->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        t->ln=cl->h;
        ptr->ln=t;
    }
}
void traverse(struct cll *cl)
{
    struct node *ptr =cl->h;
    while(ptr!=NULL)
    {
       printf("%d\n",ptr->data);
       ptr=ptr->ln;
    }
}
void deleteFirst(struct cll *cl){
    if(cl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        int item;
        item =cl->h->data;
        printf("\n%d is removed",item);
        struct node *ptr;
        while(ptr->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        ptr->ln=cl->h->ln;
        cl->h=cl->h->ln;
    }
}
void deleteMiddle(struct cll *cl){
    if(cl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        int item;
        printf("\nEnter the item to be delete : ");
        scanf("%d",&item);
        struct node *ptr=cl->h;
        while(ptr->ln!=NULL)
    {
        if(ptr->ln->data==item)
        {
            ptr->ln=ptr->ln->ln;
        }
        else{
            ptr=ptr->ln;
        }
    }
    }
}
void deleteEnd(struct cll *cl){
    if(cl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        struct node *ptr=cl->h;
        while(ptr->ln->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        ptr->ln=ptr->ln->ln;
    }
}
int main()
{
    int ch;
    struct cll cl;
    cl.h = NULL;
    do{ printf("\nMENU\n1. Insert at Start\n2. Insert at Middle\n3. Insert at End\n4. Delete from front\n5. Delete from middle\n6. Delete from End\n7. Traversal\n8. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertStart(&cl);
            break;
            case 2: insertMiddle(&cl);
            break;
            case 3: insertEnd(&cl);
            break;
            case 4: deleteFirst(&cl);
            break;
            case 5: deleteMiddle(&cl);
            break;
            case 6: deleteEnd(&cl);
            break;
            case 7: traverse(&cl);
            break;
        }
    }while(ch<8);
    return 0;
}
