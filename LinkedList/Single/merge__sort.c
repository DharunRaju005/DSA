#include<stdio.h>
#include<stdlib.h>
struct node{
    int num;
    struct node*nxt;
};

struct node*head1=NULL;
struct node*head2=NULL;
struct node*temp=NULL;
struct node*temp1=NULL;
struct node*temp2=NULL;
void CreateNode(struct node** head,int c){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    
    newNode->nxt=NULL;
    newNode->num=c;
    
    if(*head==NULL){
        temp=*head=newNode;
    }
    else{
        newNode->nxt=temp;
        temp=newNode;
        *head=newNode;
    }
}
struct node* merge(struct node*l1,struct node*l2){
    struct node dummy;
    struct node* tail=&dummy;
    while(l1 && l2){
        if(l1->num>l2->num){
            tail->nxt=l1;
            l1=l1->nxt;
        }
        else{
            tail->nxt=l2;
            l2=l2->nxt;
        }
        tail=tail->nxt;
    }
    if(l1){
        tail->nxt=l1;
    }else{
        tail->nxt=l2;
    }
    return dummy.nxt;
}



void display(struct node*head){
    temp=head;
     //printf("---%d--\n",temp->nxt->num);
    while(temp!=NULL){
         printf("%d ",temp->num);
         temp=temp->nxt;
     }
     printf("\n");
}


int main(){
    printf("Entr the LL 2 data\n");
    int loop=1;
    int c,p;
    while(loop){
        printf("Entr the data\n");
        scanf("%d",&c);
        CreateNode(&head1,c);
        printf("Want to Entr data\n");
        scanf("%d",&loop);
    }
    display(head1);
    loop=1;
    printf("Entr the LL 2 data\n");
    while(loop){
        printf("Entr the data\n");
        scanf("%d",&c);
        CreateNode(&head2,c);
        printf("Want to Entr data\n");
        scanf("%d",&loop);
    }
    display(head2);
    display(merge(head1,head2));


}