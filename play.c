#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node*next;
};

struct node *tos = NULL;

void push(struct node *node)
{
    if (tos == NULL)
    {
        tos = node;
        tos->next = NULL;
    }
    else
    {
        node->next = tos;
        tos = node;
    }
}

struct node *pop()
{
    if (tos == NULL)
    {
        return NULL;
    }

    struct node *popped = tos;
    tos = tos->next;
    popped->next = NULL;
    return popped;
}

bool isEmpty(){
    if(tos==NULL){
        return true;
    }
    return false;
}


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

    // void inOrder(struct node*temp){
    //     if(temp==NULL){
    //         return;
    //     }
    //     //left->root->data
    //     inOrder(temp->left);
    //     printf("%d ",temp->data);
    //     inOrder(temp->right);
    // }

    void inOrderIterative(struct node*root){
        if(root==NULL){
            return ;
        }
        struct node*current=root;
        while(true){
            while(current!=NULL){
                push(current);
                current=current->left;
            }
            if(current==NULL && !isEmpty()){
                struct node*poped=pop();
                printf("%d ",poped->data);
                current=current->right;
            }
            else{
                break;
            }
        }

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

    
    int data[]={1,2,3,4,5};
    size=5;
    root=createNode(0,data);
    printf("InOrder Traversal\n");
    inOrderIterative(root);
    printf("\n");
    printf("PreOrder Traversal\n");
    preOrder(root);
    printf("\n");
    printf("PostOrder Traversal\n");
    postOrder(root);

}

