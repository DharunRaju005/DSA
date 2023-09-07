#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* nxt;
};
struct node*head=NULL;
struct node*temp;
struct node*tail=NULL;
void insertbeg(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    
    new_node->prev=NULL;
    new_node->data=item;
    if(head==NULL){
    new_node->nxt=NULL;
    }
    else{
    new_node->nxt=head;
    new_node->nxt->prev=new_node;
    //printf("%d",new_node->prev->data);
    // new_node->nxt=NULL;
    }
    head=new_node;
    
    
}

void insertend(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->nxt=new_node;
    new_node->nxt=NULL;
    new_node->data=item;
    new_node->prev=temp;
    tail=new_node;
    //printf("%d--\n",tail->data);
}

void insertrandom(int pos,int item){
    if(pos==1){
        insertbeg(item);
    }
}

void display(){
     temp=head;
     while(temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->nxt;
     }
    printf("\nUsing Previous Node\n");
    temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }

}

int main(){
    insertbeg(25);
    insertbeg(2);
    insertbeg(5);
    insertbeg(21);
    insertend(3);
    insertend(45);
    insertend(10);
    insertend(19);
    insertbeg(11);
    display();
}