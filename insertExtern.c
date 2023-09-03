#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*nxt;
};
int main(){
  struct node* head=NULL;
  struct node* temp=NULL;
  int data,pos,newdata;
  int choice=1;
  while(choice){
      struct node* newnode=(struct node*)malloc(sizeof(struct node));
      printf("Entr the data \n");
      scanf("%d",&newnode->data);
      newnode->nxt=0;
      if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->nxt=newnode;
        temp=newnode;
    }
    printf("Enter 1 to continue and 0 to break  :");
    scanf("%d",&choice);
}
temp=head;
while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->nxt;
}
   printf("\nEntr the position    :");
   scanf("%d",&pos);
   printf("Entr the data to be inserted!   :" );
   scanf("%d",&newdata);
   if(pos==1){
       insertbeginning(&head,newdata);
   }
   else{
   insertrandom(head,pos,newdata);
   }
   temp=head;
    while(temp!=0){
      printf("%d ",temp->data);
      temp=temp->nxt;
  }   
}