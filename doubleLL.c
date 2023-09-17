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
    if(tail==NULL){
        tail=head;
    }
    head=new_node;
}

void insertend(int item){
    
    if(head==NULL){
        insertbeg(item);
        return;
    }
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
        return;
    }
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->nxt;
    }
    new_node->data=item;
    new_node->nxt=temp->nxt->nxt;
    new_node->prev=temp;
    new_node->nxt->prev=new_node;
    temp->nxt=new_node;
}

void delstart(){
    temp=head;
    temp->nxt->prev=NULL;
    head=temp->nxt;
    free(temp);
}

void delend(){
    temp=head;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->prev->nxt=NULL;
    tail=temp->prev;
    free(temp);
}

void delrandom(int pos){
    temp=head;
    if(pos==1){
        delstart(); 
        return;
        }
    for(int i=1;i<=pos ;i++){
        temp=temp->nxt;
    }
    temp->prev->nxt=temp->nxt;
    temp->nxt->prev=temp->prev;
}

void search(int item){
    int c=0,flg=0;
    temp=head;
    while(temp!=NULL){
        c++;
        if(temp->data==item){
            printf("Data %d is Found!! at Pos %d\n",item,c);
            flg=1;
            return;
        }
        temp=temp->nxt;
    }
    if(flg==0){
        printf("Not Found!!!\n");
    }
}

void len(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->nxt;
    }
    printf("The length of Linked List is %d\n",count);
}


void display(){
     temp=head;
     //printf("---%d--\n",temp->data);
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
    printf("\n");
}

int main(){
    insertrandom(1,34);
    delend();
    insertbeg(2);
    search(25);
    display();
    len();
    // delrandom(1);
    // //display();
    // delstart();
    
    // display();
    // delend();
    
}