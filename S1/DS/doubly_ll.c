#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
struct dll{
    struct node *h;
};
void insStart(struct dll *dl){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the Item :");
    scanf("%d",&item);
    t->data=item;
    t->prev=NULL;
    t->next=dl->h;
    if(dl->h!=NULL)
    {
        dl->h->prev=t;
    }
    dl->h=t;
}
void insEnd(struct dll *dl){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    int item;
    printf("\nEnter the Item :");
    scanf("%d",&item);
    t->data=item;
    t->next=NULL;
    if(dl->h==NULL)
    {
        dl->h=t;
        t->prev=NULL;
        return;
    }
    else{
        struct node *ptr=dl->h;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=t;
        t->prev=ptr;
    }
}
void insMiddle(struct dll *dl){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    int item,pos;
    printf("\nEnter the Item :");
    scanf("%d",&item);
    t->data=item;
    printf("\nEnter the element which comes just before this element :");
    scanf("%d",&pos);
    struct node *ptr;
    ptr=dl->h;
    while(ptr!=NULL && ptr->data!=pos)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("\nNo such item found in the list!!!");
        return;
    }
    else{
        t->next=ptr->next;
        t->prev=ptr;
        if(ptr->next!=NULL){
            ptr->next->prev=t;
        }
        ptr->next=t;
    }
}
void delFirst(struct dll *dl)
{
    if(dl->h==NULL)
    {
        printf("\nUNDERFLOW!!!");
    }
    struct node *ptr=dl->h;
    dl->h=dl->h->next;
    if(dl->h!=NULL){
        dl->h->prev=NULL;
    }
    free(ptr);
}
void delEnd(struct dll *dl)
{
    if(dl->h==NULL)
    {
        printf("\nUNDERFLOW!!!");
        return;
    }
    struct node *ptr=dl->h;
    if(ptr->next==NULL){
        dl->h=NULL;
        free(ptr);
        return;
    }
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
}
void delMiddle(struct dll *dl)
{
    if(dl->h==NULL){
        printf("\nUNDERFLOW!!!");
        return;
    }
    int pos;
    printf("\nEnter the element to be deleted from the list :");
    scanf("%d",&pos);
    struct node *ptr=dl->h;
    while (ptr!=NULL && ptr->data!=pos)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("\nNo such item found in the list!!!");
        return;
    }
    if(ptr->prev!=NULL){
        ptr->prev->next=ptr->next;
    }
    else{
        dl->h=ptr->next;
    }
    if(ptr->next!=NULL){
        ptr->next->prev=ptr->prev;
    }
    free(ptr);
}
void forwardTraversal(struct dll *dl)
{
    if(dl->h==NULL){
        printf("\nNO ELEMENTS TO TRAVERSE");
        return;
    }
    struct node *ptr = dl->h;
    while (ptr!=NULL)
    {
        printf("  %d  |",ptr->data);
        ptr=ptr->next;
    }
}
void backwardTraversal(struct dll *dl)
{
    if(dl->h==NULL){
        printf("\nNO ELEMENTS TO TRAVERSE");
        return;
    }
    struct node *ptr = dl->h;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while (ptr!=NULL)
    {
        printf("  %d  |",ptr->data);
        ptr=ptr->prev;
    }

}
int main(){
int ch;
    struct dll dl;
    dl.h = NULL;
    do{ printf("\nMENU\n1. Insert at Start\n2. Insert at Middle\n3. Insert at End\n4. Delete from front\n5. Delete from middle\n6. Delete from End\n7. Forward Traversal\n8. Backward Traversal\n9. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insStart(&dl);
                    break;
            case 2: insMiddle(&dl);   
                    break;
            case 3: insEnd(&dl);
                    break;
            case 4: delFirst(&dl);
                    break;
            case 5: delMiddle(&dl);
                    break;
            case 6: delEnd(&dl);
                    break;
            case 7: forwardTraversal(&dl);
                    break;
            case 8: backwardTraversal(&dl);
                    break;
        }
    }while(ch<9);
    return 0;
}