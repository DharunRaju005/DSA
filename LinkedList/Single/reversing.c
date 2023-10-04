#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* nxt;
};
struct node*nxt=NULL;
struct node*head=NULL;
struct node*temp=NULL;

void CreateNode(struct node**head,int data){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->nxt=NULL;
    if(*head==NULL){
        *head=temp=newNode;
    }
    else{
        newNode->nxt=temp;
        *head=newNode;
        temp=newNode;
    }
}

void display(){
    temp=head;
    //printf("%d ",head->data);
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("\n");
}

int main(){
    int loop=1;
    while(loop){
        printf("Entr the data :");
        int data;
        scanf("%d",&data);
        CreateNode(&head,data);
        scanf("%d",&loop);
    }
    printf("Origin data\n");
    display();
    temp=head;
    head=NULL;
    while(temp!=NULL){
        nxt=temp->nxt;
        temp->nxt=head;
        head=temp;
        temp=nxt;
    }
    printf("Reversed data\n");
    display();
    
}


