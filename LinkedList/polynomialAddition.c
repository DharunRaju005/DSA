#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int coeff;
    int pow;
    struct node*nxt;
};

struct node*head1=NULL;
struct node*head2=NULL;
struct node*temp=NULL;
struct node*temp1=NULL;
struct node*temp2=NULL;
void CreateNode(struct node** head,int c,int p){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->nxt=NULL;
    newNode->coeff=c;
    newNode->pow=p;
    if(*head==NULL){
        temp=*head=newNode;
    }
    else{
        newNode->nxt=temp;
        temp->prev=newNode;
        temp=newNode;
        *head=newNode;
    }
}

void display(struct node*head){
    temp=head;
     //printf("---%d--\n",temp->nxt->coeff);
    while(temp!=NULL){
         printf("%dx^%d ",temp->coeff,temp->pow);
         temp=temp->nxt;
     }
     printf(" = 0");
     printf("\n");
}


int main(){
    printf("Entr the Polynomial 1 data\n");
    int loop=1;
    int c,p;
    while(loop){
        printf("Entr the coeff and pow\n");
        scanf("%d %d",&c,&p);
        CreateNode(&head1,c,p);
        printf("Want to Entr data\n");
        scanf("%d",&loop);
    }
    display(head1);
    loop=1;
    printf("Entr the Polynomial 2 data\n");
    while(loop){
        printf("Entr the coeff and pow\n");
        scanf("%d %d",&c,&p);
        CreateNode(&head2,c,p);
        printf("Want to Entr data\n");
        scanf("%d",&loop);
    }
    display(head2);
    
    temp2=head2;
    while(temp2!=NULL){
        int flg=0;
        temp1=head1;
        while(temp1!=NULL){
            if(temp1->pow==temp2->pow){
                temp1->coeff=temp1->coeff+temp2->coeff;
                flg=1;
                break;
            }
            else{
                temp1=temp1->nxt;
        }
        }
        if(flg==0){
            struct node*newNode=(struct node*)malloc(sizeof(struct node));
            newNode->pow=temp2->pow;
            newNode->coeff=temp2->coeff;
            newNode->nxt=head1;
            head1=newNode;
        }
        temp2=temp2->nxt;
    }

    display(head1);
}

