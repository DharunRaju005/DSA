#include<stdio.h>
#include<stdlib.h>
int size;
int count;

struct node{
    int data;
    struct node*nxt;
};

struct node*head=NULL;
struct node*temp;
struct node*rptr=NULL;
struct node*fptr=NULL;


void enqueue(int data){
    count++;
    if(size<count){
        printf("The gn Que cannot accomadate this data %d since Q is Full\n",data);
        count--;
        return;
    }
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    
    newNode->data=data;
    newNode->nxt=NULL;
    if(head==NULL){

        rptr=fptr=temp=head=newNode;
        return;
    }
    else{
        temp->nxt=newNode;
        
    }
    rptr=temp=newNode;
}

void dequeue(){
    if(size==0){
        printf("The gn Que cannot accomadate this data %d \nQ is empty\n");
        return;
    }
    if(head==NULL){
        printf("The Q is Empty\n");
        return;
    }
    count--;
    temp=head->nxt;
    fptr=temp;
    free(head);
    head=temp;
}

void front(){
    if(fptr!=NULL){
        printf("Data at front is %d\n",fptr->data);
        return;
    }
    printf("The queue is Empty\n");
}

void rear(){
    if(rptr==NULL){
        printf("The Q is Empty\n");
        return;
    }
    // temp=head;
    // while(temp->nxt!=NULL){
    //     temp=temp->nxt;
    // }
    printf("Data at rear is %d\n",rptr->data);
}

void isEmpty(){
    if(head==NULL){
        printf("TRUE\n");
        return;
    }
    printf("FALSE\n");
}

void isFull(){
    if(count==size || size==0){
        printf("Isfull\n");
        return;
    }
    printf("not full\n");
}

void calsize(){
    printf("Size of the Q %d\n",count);
}

void display(){
    if(head==NULL){
        printf("Q is not Created\n");
        return;
    }
    temp=head;
    int tem=size;
    while(temp && tem){
        printf("%d ",temp->data);
        temp=temp->nxt;
        --tem;
    }
    printf("\n");
}
int main(){
    int count=0;
    scanf("%d",&size);
    //enqueue(4);
    enqueue(45);
    rear();
    
    front();
    dequeue();
    enqueue(4);
    enqueue(45);
    enqueue(5);
    enqueue(51);
    isFull();
    display();
     dequeue();
     dequeue();
     dequeue();
     dequeue();
     isFull();
     display();
     calsize();
     enqueue(15);
     display();
    // display();
    rear();
    front();
    calsize();
    isEmpty();
    isFull();

}
