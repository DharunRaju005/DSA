//Creating a Single Circular Linked list 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
   int data;
   struct node *nxt;
}node;
int main(){
   node *head,*new_node,*temp=NULL;
   head=NULL;
   int choice=1;
   while(choice){
      new_node=(node*)malloc(sizeof(node));
      printf("Entr the data");
      scanf("%d",&new_node->data);
      new_node->nxt=head;
      if(head==NULL){
         head=temp=new_node;
      }
      else{
         temp->nxt=new_node;
         temp=new_node;
      }
      printf("entr 0 r 1");
      scanf("%d",&choice);
   }  
      temp->nxt=head;
      temp=head;
      printf("Circular Linked List: \n");
      while(temp!=0){
         printf("%d\t",temp->data);
         temp=temp->nxt; 
         if(temp==head){
            break;
         }
      }
}
