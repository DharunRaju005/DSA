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

struct node* min(struct node*node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}


struct node* del(struct node* root,int d) {
    if (root == NULL) {
        return root;
    } else if (d < root->data) {
        root->left = del(root->left, d);
    } else if (d > root->data) {
        root->right = del(root->right, d);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left && root->right) {
            struct node* temp = min(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        } else {
            struct node* temp;
            if (root->left == NULL) {
                temp = root;
                root = root->right;
            } else {
                temp = root;
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
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



int main(){
    int nums[6]={1,4,2,7,3,5};
    for(int i=0;i<6;i++){
        insert(nums[i]);
    }
    display();
    printf("\n");
    del(root,1);
    display();
}