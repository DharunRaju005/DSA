#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int size;
struct node* root=NULL;
struct node* leaf=NULL;
struct node* createNode(int indx,int*data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
        if(indx>=size){
            return NULL;
        }
        newNode->data=data[indx];
        //int dat=data[indx];
        newNode->left=createNode(2*indx+1,data);
        newNode->right=createNode(2*indx+2,data);
        return newNode;
    }

    void inOrder(struct node*temp){
        if(temp==NULL){
            return;
        }
        //left->root->data
        inOrder(temp->left);
        printf("%d ",temp->data);
        inOrder(temp->right);
    }

    void preOrder(struct node*temp){
        if(temp==NULL){
            return;
        }
        //root->left->right
        printf("%d ",temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }

    void postOrder(struct node*temp){
        if(temp==NULL){
            return;
        }
        //left->right->root
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ",temp->data);
    }

int main(){
    // size=argc-1;
    // int data[size];
    // printf("Given data\n");
    // for(int i=1;i<argc;i++){
    //     data[i-1]=atoi(argv[i]);
    // }
    // for(int i=1;i<argc;i++){
    //     printf("%d ",data[i-1]);
    // }
    // printf("\n");
    
    int data[]={1,2,3,4,5};
    size=5;
    root=createNode(0,data);
    printf("InOrder Traversal\n");
    inOrder(root);
    printf("\n");
    printf("PreOrder Traversal\n");
    preOrder(root);
    printf("\n");
    printf("PostOrder Traversal\n");
    postOrder(root);

}

