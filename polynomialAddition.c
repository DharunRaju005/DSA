#include<stdio.h>
#include<stdlib.h>
struct node{
    int num;
    int pow;
    struct node*nxt;
};
struct node*head=NULL;
struct node*head1=NULL;
struct node*temp=NULL;
struct node*temp1=NULL;
struct node* createNode1(int number,int power ){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->num=number;
    newNode->pow=power;
    newNode->nxt=NULL;
    if(head==NULL){
        head=temp=newNode;
    }
    else{
        temp->nxt=newNode;
    }
    return newNode;
  }

struct node* createNode2(int number,int power ){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->num=number;
    newNode->pow=power;
    newNode->nxt=NULL;
    if(head1==NULL){
        head1=temp=newNode;
    }
    else{
        temp->nxt=newNode;
    }
    return newNode;
  }
int main(){
    int loop=1;
    int c1=0;
    int c2=0;
    printf("Data for the 1st eqn!!!\n");
    while(loop){
        c1++;
        int n,p;
        printf("Entr the number and its power\n");
        scanf("%d %d",&n,&p);
        struct node*NewNode=createNode1(n,p);
        printf("Want to enter data???\n");
        scanf("%d",&loop);
    }
    //temp=head;
    // while(temp!=NULL){
    //     printf("%d %d\n",temp->num,temp->pow);
    //     temp=temp->nxt;
    // }
    loop=1;
    printf("Data for the 2nd eqn!!!\n");
    while(loop){
        c2++;
        int n,p;
        printf("Entr the number and its power\n");
        scanf("%d %d",&n,&p);
        struct node*newNode=createNode2(n,p);
        if(head!=NULL){
            temp->nxt=newNode;
        }
        printf("Want to enter data???\n");
        scanf("%d",&loop);
    }
    //temp=head1;
    // while(temp!=NULL){
    //     printf("%d %d\n",temp->num,temp->pow);
    //     temp=temp->nxt;
    // }
    temp=head;
    temp1=head;
    for(int i=0;i<c1;i++){
        temp=head;
        int flg=1;
        for(int j=0;j<c2;j++){
            if(temp->pow==temp1->pow){
                flg++;
                temp->num=(temp->num)+temp1->num;
            }
            if(flg!=1){
                break;
            }
            temp1=temp1->nxt;
        }
        if(flg==1){
            struct node*NewNode=(struct node*)malloc(sizeof(struct node));
            NewNode->num=temp->num;
            NewNode->pow=temp->pow;
            NewNode->nxt=head;
            head=NewNode;
        }
        temp=temp->nxt;
    }
    temp=head;


    
}
