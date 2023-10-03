#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int row;
    int col;
    struct node*nxt;
};
struct node*head=NULL;
struct node*temp=NULL;

void createNewNode(int data,int r,int c){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->row=r;
    newNode->col=c;
    newNode->nxt=NULL;
    if(head==NULL){
        temp=head=newNode;
    }
    else{
        newNode->nxt=temp;
        temp=newNode;
        head=newNode;
    }
}
int main(){
    int r,c;
    printf("Entr the row and col count\n");
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int temp;
            printf("Entr the data");
            scanf("%d",&temp);
            if(temp!=0){
                createNewNode(temp,i,j);
            }
        }
    }
    temp=head;
    while(temp!=NULL){
        printf("Data:%d Row: %d Col: %d\n",temp->data,temp->row,temp->col);
        temp=temp->nxt;
    }

}