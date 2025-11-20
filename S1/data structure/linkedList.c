#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *ln;
};
struct sll{
    struct node *h;
};
void insFirst(struct sll *sl){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    int item;
    printf("Enter the data to be inserted :");
    scanf("%d",&item);
    t->data = item;
    t->ln = sl->h;
    sl->h= t->ln;
}

void insMiddle(struct sll *sl){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item,value;
    printf("Enter the data to be inserted :");
    scanf("%d",&item);
    printf("Enter the element that preceeds the item :");
    scanf("%d",&value);
    struct node *ptr = sl->h;
    while (ptr->ln!= NULL){
        if(ptr->data==value){
            break;
        }
        else{
            ptr = ptr->ln;
        }
    }
    if(ptr == NULL){
        printf("The item doesnt found in the list!!");
        return;
    }
    else{
        t->ln = ptr->ln;
        ptr->ln =  t;
    }
}
void insEnd(struct sll *sl){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter the item to be inserted :");
    scanf("%d",&item);
    t->data = item;
    t->ln = NULL;
    if (sl->h==NULL)
    {
        sl->h = t;
    }
    struct node *ptr = sl->h;
    while(ptr->ln!=NULL){
        ptr = ptr->ln;
    }
    ptr->ln = t;
}
void traverse(struct sll *sl){
    if (sl->h==NULL)
    {
        printf("No items!!");
        return;
    }
    struct node *ptr = sl->h;
    while(ptr->ln!=NULL){
        printf("%d",ptr->data);
        ptr = ptr->ln;
    }

}
void deleteFirst(struct sll *sl)
{
    if (sl->h==NULL){
        printf("No item to delete!!!");
        return;
    }
    printf("%d is removed!!!", sl->h->data);
    sl->h = sl->h->ln;         
}
void deleteMiddle(struct sll *sl){
    int item;
    if (sl->h==NULL){
        printf("No item to delete!!!");
        return;
    }
    printf("Enter the data to be delete :");
    scanf("%d",&item);
}