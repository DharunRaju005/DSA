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
  int checkLen(){
          if(head==NULL){
            printf("Linked list isn't created\n");
            return 0;
          }
          temp=head;
          int count=0;
          while(temp!=0){
              count++;
              temp=temp->nxt;
          }
          
          return count;
  }
void insertbeg(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->prev=NULL;
    new_node->data=item;
    if(head==NULL){
    new_node->nxt=NULL;
    }
    if(tail==NULL){
        tail=new_node;
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
    int length=checkLen();
    if((length+1)<=pos){
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
    else{
         printf("Position doesn't exit\n");
    }
}

void delstart(){
    int length=checkLen();
        if(length==0){
            return;
            }
    temp=head;
    temp->nxt->prev=NULL;
    head=temp->nxt;
    free(temp);
}

void delend(){
    int length=checkLen();
    if(length==0){
        return;
    }
    else if(length==1){
        free(head);
        head=NULL;
        tail=NULL;
        return;
    }
    else if(length>1){
    temp=head;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->prev->nxt=NULL;
    tail=temp->prev;
    free(temp);
}
}

void delrandom(int pos){
    int len=checkLen();
    if(len==0){
        return;
    }
    if(pos<=(len+1)){
        if(pos==1){
            delstart();
        }
        else{
        temp=head;
        for(int i=1;i<=pos ;i++){
        temp=temp->nxt;
    }
    temp->prev->nxt=temp->nxt;
    temp->nxt->prev=temp->prev;
    }
    }
    else{
        printf("Position doesn't exit\n");
    }
}

void search(int item){
    int len=checkLen();
    if(len==0){
        return;
    }
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
    if(head==NULL){
        printf("Linked List is Emt!!!\nLength - 0\n");
        return;
    }
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->nxt;
    }
    printf("The length of Linked List is %d\n",count);
}

void display(){
           if(head==NULL){
            printf("Linked List is Emt!!!\n");
            return;
          }
            int length=checkLen();
            if(length==0){
                return;
        }
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
    // delstart();
    // insertrandom(8,34);
    insertbeg(23);
    // insertend(21);
    // delrandom(5);
    // delstart();
    // delrandom(1);
    search(4);
    // display();
    delend();
    delend();
    display();
    // insertbeg(2);
    // search(25);
    
    // len();
    // delrandom(1);
    // //display();
    // delstart();
    
    // display();
    // delend();
    
}