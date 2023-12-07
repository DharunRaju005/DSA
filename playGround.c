#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node*next;
};

struct node*sp=NULL;
struct node*head=NULL;
struct node*temp=NULL;

struct node* createNode(int item){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=NULL;
    return newNode;
}

void stackPush(int item){
    struct node*newNode=createNode(item);
    if(head==NULL){
        head=temp=sp=newNode;
    }
    else{
        sp->next=newNode;
        sp=newNode;
    }
}

int stackPop(){
    if(sp==NULL){
        return 0;
    }
    if(head->next==NULL){
        int data=head->data;
        head=sp=NULL;
        return data;
    }
    temp=head;
    while(temp->next!=sp){
        temp=temp->next;
    }
    printf("inside pop %d--\n",temp->data);
    sp=temp;
    temp->next=NULL;
    int data=temp->data; 
    return data;

}

void display(struct node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    
}

void expEval(char* exp){
    char* str=strtok(exp," ");
    while(str!=NULL){
        printf("%s\n",str);
        if(strcmp(str,"+")==0){
            printf("/nbefore");display(head);
            printf("/n");
            int a=stackPop();
            display(head);
            int b=stackPop();
            printf("%d--\n",b);
            stackPush(b+a);
        }
        else if(strcmp(str,"-")==0){
            int a=stackPop();
            int b=stackPop();
            stackPush(b-a);
        }
        else if(strcmp(str,"*")==0){
            int a=stackPop();
            int b=stackPop();
            stackPush(b*a);
        }
        else if(strcmp(str,"/")==0){
            int a=stackPop();
            int b=stackPop();
            stackPush(b/a);
        }
        else{
            stackPush(atoi(str));
        }
        str=strtok(NULL," ");
    }
}
int main(){
    int nums[]={1,2,3,4,5};
    // for(int i=0;i<5;i++){
    //     stackPush(nums[i]);
    // }
    // display(head);
    // printf("--%d--\n",stackPop());
    // display(head);
    char s[]="21 14 +";

    expEval(s);
    display(head);
}