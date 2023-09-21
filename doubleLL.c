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
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=item;
    if(head==NULL){
    newNode->nxt=NULL;
    }
    if(tail==NULL){
        tail=newNode;
    }
    else{
    newNode->nxt=head;
    newNode->nxt->prev=newNode;
    //printf("%d",newNode->prev->data);
    // newNode->nxt=NULL;
    }
   
    head=newNode;
}

void insertend(int item){
    
    if(head==NULL){
        insertbeg(item);
        return;
    }
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->nxt=newNode;
    newNode->nxt=NULL;
    newNode->data=item;
    newNode->prev=temp;
    tail=newNode;
    //printf("%d--\n",tail->data);
}

void insertrandom(int pos,int item){
    int length=checkLen();
    if((length+1)>=pos){
        if(pos==1){
            insertbeg(item);
            return;
        }
        struct node*newNode=(struct node*)malloc(sizeof(struct node));
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->nxt;
        }
        newNode->data=item;
        newNode->nxt=temp->nxt->nxt;
        newNode->prev=temp;
        newNode->nxt->prev=newNode;
        temp->nxt=newNode;
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
    
    insertrandom(4,32);
    

    // insertend(21);
    // delrandom(5);
    // delstart();
    // delrandom(1);
    //search(4);
    // display();
    // delend();
    // delend();
    // display();
    // insertbeg(2);
    // search(25);
    
    // len();
    // delrandom(1);
    // //display();
    // delstart();
    
    // display();
    // delend();
    
}