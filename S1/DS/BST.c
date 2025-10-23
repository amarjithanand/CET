#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right,*left;
};
struct bst{
    struct node *root;
};
void insert_bst(struct node **t,int value) {

    if (*t == NULL) {
        *t = (struct node *)malloc(sizeof(struct node));
        (*t)->data = value;
        (*t)->left = (*t)->right = NULL;
    } 
    else if (value < (*t)->data) {
        insert_bst(&(*t)->left,value);
    } 
    else if (value > (*t)->data) {
        insert_bst(&(*t)->right,value);
    } 
    else {
        printf("The data already exists in the tree!!");
    }
}
void delete_bst(struct node **t,int key){
    struct node *temp,*parent,*succ;

    if(*t==NULL){
        printf("Tree is empty!!");
        return;
    }

    if(key<(*t)->data){
        delete_bst(&(*t)->left,key);
    }
    else if(key>(*t)->data){
        delete_bst(&(*t)->right,key);
    }
    else{
        if((*t)->left==NULL && (*t)->right==NULL){
            free(*t);
            *t = NULL;
        }

        else if((*t)->left==NULL || (*t)->right==NULL){
            if((*t)->left!=NULL){
                temp = (*t)->left;
            }
            else{
                temp = (*t)->right;
            }
            free(*t);
            *t = temp;
        }

        else{
            succ = (*t)->right;
            while(succ->left != NULL){
                succ = succ->left;
            }
            (*t)->data = succ->data;

            delete_bst(&(*t)->right, succ->data);
        }
    }
}

void preorder(struct node *t){
    printf("%d\n",(t)->data);
    if((t)->left!=NULL){
        preorder((t)->left);
    }
    if((t)->right !=NULL){
        preorder((t)->right);
    }
}

void inorder(struct node *t){
    if((t)->left!=NULL){
        inorder((t)->left);
    }
    printf("%d\n",(t)->data);
    if((t)->right !=NULL){
        inorder((t)->right);
    }
}
void postorder(struct node *t){
    if((t)->left!=NULL){
        postorder((t)->left);
    }
    if((t)->right !=NULL){
        postorder((t)->right);
    }
    printf("%d\n",(t)->data);
}

int main() {
    struct node *root = NULL;
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display (Preorder)\n4. Display (Inorder) \n5. Display (Postorder) \n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            int value;
            printf("Enter the data you want to insert: ");
        scanf("%d", &value);
                insert_bst(&root,value);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_bst(&root, key);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            default:
                return 0;
        }
    }
}
