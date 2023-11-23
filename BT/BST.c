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
            return NULL;  
        }
        
        else if (node->left != NULL && node->right != NULL) {
            struct node* successor = inOrderSucc(data);
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
    helpDelete(data,root);
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



int main(int argc,char* argv[]){
    int loop=1;
    int choice;
    while(loop){
        printf("\nEntr 1 to insert\nEntr 2 to delete\nEntr 3 to search\nEntr 4 to display\n");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            scanf("%d",&data);
            insert(data);
        }
        else if(choice==2){
            int del;
            printf("Entr the data to be deleted");
            scanf("%d",&del);
            delete(del);
            }
        
        else if(choice==3){
            int s;
            printf("Entr the data to be searched");
            scanf("%d",&s);
            delete(s);
            }
        
        else if(choice==4){

            display();
            printf("\n");
            }
        printf("Entr 0 to break");
        scanf("%d",&loop);
        }   
         
}