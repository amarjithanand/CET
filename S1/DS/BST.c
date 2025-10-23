#include<stdio.h>

struct node{
    int data;
    struct node *right,*left;
};
struct bst{
    struct node *root;
};
void insert_bst(struct node *t){
    int value;
    struct node *ptr = t;
    printf("Enter the data you want to insert :");
    scanf("%d",&value);
    if(ptr->data==NULL){
        ptr->data=value;
    }
    else if(value < ptr->data){
        ptr = ptr->left;
        insert_bst(ptr);
    }
    else if(value > ptr->data){
        ptr = ptr -> right;
        insert_bst(ptr);
    }
    else{
        printf("The data inserted already existed in tree!!");
    }
}