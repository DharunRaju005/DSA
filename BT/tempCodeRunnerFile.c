#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node*right;
};
struct node* root=NULL;
struct node* suc=NULL;
int count=1;

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* helpInsert(int data,struct node*node){
    if(node==NULL){
        return createNode(data);
    }else{
        if(data>node->data){
            node->right=helpInsert(data,node->right);
        }
        else{
            node->left=helpInsert(data,node->left);
        }
    }
    return node;
}

void insert(int data){
        root=helpInsert(data,root);
}

struct node* helpSearch(int data,struct node*node){
    if(node==NULL){
        return NULL;
    }
    if(node->data==data){
        return node;
    }
    else{
        if(node->data>data){
            return helpSearch(data,node->left);
        }
        return helpSearch(data,node->right);
    }
}

void search(int data){
    struct node*temp= helpSearch(data,root);
    //printf("%d----",temp->data);
    if(temp!=NULL){
        printf("%d is Found \n",temp->data);
        return;
    }
    printf ("%d is not found\n",data);
}

struct node* minSucc(struct node*node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}

struct node*helpInOrderSucc(int data,struct node*node,struct node*suc){
    if(node==NULL){
        return suc;
    }
    if(node->data==data && node->right!=NULL){
        return minSucc(node->right);
    }
    else if(node->data>data){
        //suc=node;
        return helpInOrderSucc(data,node->left,suc);
    }
    else{
        return helpInOrderSucc(data,node->right,suc);
    }
    //return suc;

}   

struct node*inOrderSucc(int data){
    return helpInOrderSucc(data,root,suc);
}

struct node* retParent(struct node*node){
    if(node==root || node==NULL){
        return NULL;
    }
    struct node*temp=root;
    while(temp->left!=node && temp->right!=node){
        if(temp->data>node->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return temp;
}

struct node* helpDelete(int data, struct node* node) {
    if (node==NULL) {
        return node; 
    }
    if (data<node->data) {
        node->left = helpDelete(data, node->left);
    } else if (data > node->data) {
        node->right = helpDelete(data, node->right);
    } else {
        
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL; 
        }
        
        else if (node->left != NULL && node->right != NULL) {
            struct node* successor = minSucc(node->right);
            node->data = successor->data;
            node->right = helpDelete(successor->data,node->right);
        }
        
        else {
            struct node* temp = node;
            if (node->left != NULL) {
                node=node->left;
            } else {
                node=node->right;
            }
            free(temp);
        }
    }

    return node;
}


void delete(int data){
    root=helpDelete(data,root);
}




void helpDisplay(struct node*node){
    if(node==NULL){
        return;
    }
    helpDisplay(node->left);
    printf("%d ",node->data);
    helpDisplay(node->right);
}

void display(){
    helpDisplay(root);
}

bool checkSkew(struct node* node){
    if(node==NULL){
        return true;
    }
    if((node->left!=NULL && node->right!=NULL) ){
        return false;
    }
    struct node* left=node->left;
    if(left!=NULL){
        while(left!=NULL){
        if(left->right!=NULL){
            return false;
        }
        left=left->left;
    }
    }
    
    struct node* right=node->right;
    
    if(right!=NULL){
        while(right!=NULL){
            if(right->left!=NULL){
                return false;
            }
            right=right->right;
        }
    }
    return true;
}





int main(){
    int nums[]={10,12,11};
    for(int i=0;i<5;i++){
        insert(nums[i]);
    }
    printf("\n");
    display();
    //retParent(3);
    printf("\n");
    printf("------");
    delete(1);
     printf("------");
    display();
    printf("\n");
    search(2);
    //printf("%d",inOrderSucc(23)->data);
    bool ans=checkSkew(root);
    if(ans){
        printf("True");
    }
    else{
        printf("false");
    }

}


