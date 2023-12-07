#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
      while(temp->nxt!=NULL){
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
    if(count==0){
        printf("The stack is empty!!\n");
    }
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
        //printf("The Stack is empty\n");
        return;
    }
    display(head->nxt);
    printf("%d ",head->data);
}

void evalEx(char s[]){
 char *str=strtok(s," ");
    while(str!=NULL){
        
        // if(strcmp(str,"+")!=0 && strcmp(str,"-")!=0 && strcmp(str,"*")!=0 && strcmp(str,"/")!=0){
        //     stackpush(atoi(str));
        // }
        if(strcmp(str,"+")==0){
            int a=stackpop();
            int b=stackpop();
            stackpush(b+a);
        }
        
        else if(strcmp(str,"-")==0){
            int a=stackpop();
            int b=stackpop();
            stackpush(b-a);
        }

        else if(strcmp(str,"*")==0){
             int a=stackpop();
            int b=stackpop();
            stackpush(a*b);
        }

        else if(strcmp(str,"/")==0){
            int a=stackpop();
            int b=stackpop();
            stackpush(b/a);
        }
        else{
            stackpush(atoi(str));
        }

        str=strtok(NULL," ");
    }
}

int main(){
    n=10;
    char s[]="12 13 +";
    evalEx(s);
   

    display(head);
    int n=10;
//      count=0;
//      stackpop();
// //     // scanf("%d",&n);
//     stackpush(5);
//     stackpush(35);
//     stackpop();
//     stackpop();
//     display(head);
//     stackpop();

//    stackpush(54);
//    stackpush(54);
//    display(head);
//    printf("\n");
//     // //stackpop();
//     // peek();
//     // //display(head);
//     stackpush(26);
    //display(head);
}
