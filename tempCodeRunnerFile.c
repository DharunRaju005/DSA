#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* nxt;
};
void delete(struct node* head,int pos){
    struct node*temp=head;
    struct node*right;
    for(int i=0;i<pos-1;i++){
        temp=temp->nxt;
    }
    right=temp->nxt->nxt;
    temp->nxt=right;
    
}
int main(){
    struct node* head=NULL;
    struct node* temp=NULL;
    int pos,data;
    int choice=1;
    while(choice){
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        printf("Entr the data: \n");
        scanf("%d",&new_node->data);
        new_node->nxt=NULL;
        if(head==NULL){
            head=temp=new_node;
        }
        else{
            temp->nxt=new_node;
            temp=new_node;
        }
        printf("Entr the choice: ");
        scanf("%d",&choice);
    }
    temp =head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("Entr the pos to delete:\n");
    scanf("%d",&pos);
    delete(head,pos);
    temp =head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
   
}