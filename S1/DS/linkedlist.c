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
void insertStart(struct sll *sl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    t->ln = sl->h;
    sl->h= t;
}

void insertMiddle(struct sll *sl)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item,value;
    printf("\nAfter Which element to be the item is to placed  : ");
    scanf("%d", &value);
    printf("\nEnter the data : ");
    scanf("%d", &item);
    t->data = item;
    struct node *ptr =sl->h;
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
void insertEnd(struct sll *sl)
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
void deleteFirst(struct sll *sl){
    if(sl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        int item;
        item =sl->h->data;
        printf("\n%d is removed",item);
        sl->h=sl->h->ln;
    }
}
void deleteMiddle(struct sll *sl){
    if(sl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        int item;
        printf("\nEnter the item to be delete : ");
        scanf("%d",&item);
        struct node *ptr=sl->h;
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
void deleteEnd(struct sll *sl){
    if(sl->h==NULL)
    {
        printf("\nNo items");
    }
    else{
        struct node *ptr=sl->h;
        while(ptr->ln->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        ptr->ln=NULL;
    }
}
void merge(struct sll *sl)
{
    int ch;
    struct sll sl1;
    sl1.h = NULL;
    do{
        printf("\nMENU for the second linked list \n1. Insert at Start\n2. Insert at Middle\n3. Insert at End\n4. Delete from front\n5. Delete from middle\n6. Delete from End\n7. Traversal\n8. To merge\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertStart(&sl1);
            break;
            case 2: insertMiddle(&sl1);
            break;
            case 3: insertEnd(&sl1);
            break;
            case 4: deleteFirst(&sl1);
            break;
            case 5: deleteMiddle(&sl1);
            break;
            case 6: deleteEnd(&sl1);
            break;
            case 7: traverse(&sl1);
            break;
        }
    }while(ch<8);

    if(sl->h==NULL)
    {
        sl->h=sl1.h;
    }
    else{
        struct node *ptr=sl->h;
        while(ptr->ln!=NULL)
        {
            ptr=ptr->ln;
        }
        ptr->ln=sl1.h;
    }
}
int main()
{
    int ch;
    struct sll sl;
    sl.h = NULL;
    do{ printf("\nMENU\n1. Insert at Start\n2. Insert at Middle\n3. Insert at End\n4. Delete from front\n5. Delete from middle\n6. Delete from End\n7. Traversal\n8. Merge\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertStart(&sl);
            break;
            case 2: insertMiddle(&sl);
            break;
            case 3: insertEnd(&sl);
            break;
            case 4: deleteFirst(&sl);
            break;
            case 5: deleteMiddle(&sl);
            break;
            case 6: deleteEnd(&sl);
            break;
            case 7: traverse(&sl);
            break;
            case 8: merge(&sl);
                    break;
        }
    }while(ch<9);
    return 0;
}
