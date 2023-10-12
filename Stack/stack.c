#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*nxt;
};

struct node*sp;
struct node*head=NULL;
struct node*temp=NULL;
struct node*tail=NULL;
int n;
int count;


struct node* createNode(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->nxt=NULL;
    sp=new_node;
    temp=head;
    return new_node;
  }

void stackpush(int data){
    if(n>count){
      if(head==NULL){
        struct node*new_node=createNode(data);
        if(head==NULL){
            head=temp=new_node;

      }
      else{
          new_node->nxt=temp;
          head=new_node;
      }
      count++;
      return;
      }
      struct node*new_node=createNode(data);
      while(temp->nxt!=0){
          temp=temp->nxt;
      }
      temp->nxt=new_node;
      count++;
    }
    else{
        printf("Stack is Full");
    }

}

int stackpop(){
    if(count==1){
        int data=head->data;
        temp = head;
        free(temp);
        head=NULL;
        count--;
        return data;

    }
    temp=head;
    while(temp->nxt->nxt!=NULL){
          temp=temp->nxt;
      }
      struct node*del1=temp->nxt;
      int ret = del1 -> data;
      free(del1);
      temp->nxt=NULL;
      count--;
      return ret;
}

void peek(){
    printf("----%d---\n",sp->data);
}

void display(struct node*head){
    if(head==NULL){
        return;
    }
    display(head->nxt);
    printf("%d ",head->data);
    
    
}

int main(){
    n=10;
    char str[]="12+47*/";
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!='+' && str[i]!='-' && str[i]!='*'&& str[i]!='/'){
            stackpush(str[i]-48);
        }
        if(str[i]=='+'){
            int a=stackpop();
            int b=stackpop();
            stackpush(b+a);
        }
        
        else if(str[i]=='-'){
            int a=stackpop();
            int b=stackpop();
            stackpush(b-a);
        }

        else if(str[i]=='*'){
             int a=stackpop();
            int b=stackpop();
            stackpush(a*b);
        }

        else if(str[i]=='/'){
            int a=stackpop();
            int b=stackpop();
            stackpush(a/b);
        }
        display(head);
        printf("\n");
    }

    stackpop();
    //int n;
    count=0;
    // scanf("%d",&n);
   stackpush(5);
   stackpush(35);
   stackpush(54);
   stackpush(54);
   display(head);
    // //stackpop();
    // peek();
    // //display(head);
    // stackpush(26);
    //display(head);
}
