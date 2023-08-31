// //Creating a singly linked list

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node*nxt;
// };
// int main(){
//     struct node* head=NULL;
//     struct node* temp=NULL;
//     int data;
//     int choice=1;
//     while(choice){
//         struct node* newnode=(struct node*)malloc(sizeof(struct node));
//         printf("Entr the data \n");
//         scanf("%d",&newnode->data);
//         newnode->nxt=0;
//         if(head==NULL){
//         head=temp=newnode;
//         }
//         else{
//         temp->nxt=newnode;
//         temp=newnode;
//         }
//         printf("Enter 1 to continue and 0 to break \n");
//         scanf("%d",&choice);
//     }
//     temp=head;
//     while(temp!=0){
//         printf("%d ",temp->data);
//         temp=temp->nxt;
//     }
// }

// //Inserting elemennts in singly linked list


// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node*nxt;
// };

// void insertbeginning(struct node** head,int data){
//     struct node*new_node=(struct node*)malloc(sizeof(struct node));
//     new_node->data=data;
//     new_node->nxt=*head;
//     *head=new_node;
// }
// void insertrandom(struct node* head,int pos,int newdata){
//      struct node*new_node=(struct node*)malloc(sizeof(struct node));
//      new_node->data=newdata;
//      struct node* temp=head;
//      for(int i=1;i<pos-1 &&  temp!=0;i++){
//             temp=temp->nxt;
//      }
//      if(temp==0){
//         printf("Out of range!!\nEnter the valid position");
//      }
//      new_node->nxt=temp->nxt;
//      temp->nxt=new_node;
// }
// int main(){
//     struct node* head=NULL;
//     struct node* temp=NULL;
//     int data,pos,newdata;
//     int choice=1;
//     while(choice){
//         struct node* newnode=(struct node*)malloc(sizeof(struct node));
//         printf("Entr the data \n");
//         scanf("%d",&newnode->data);
//         newnode->nxt=0;
//         if(head==NULL){
//             head=temp=newnode;
//         }
//         else{
//             temp->nxt=newnode;
//             temp=newnode;
//         }
//         printf("Enter 1 to continue and 0 to break  :");
//         scanf("%d",&choice);
//     }
//     temp=head;
//     while(temp!=0){
//         printf("%d ",temp->data);
//         temp=temp->nxt;
//     }
//     printf("\nEntr the position    :");
//     scanf("%d",&pos);
//     printf("Entr the data to be inserted!   :" );
//     scanf("%d",&newdata);
//     if(pos==1){
//         insertbeginning(&head,newdata);
//     }
//     else{
//     insertrandom(head,pos,newdata);
//     }
//     temp=head;
//       while(temp!=0){
//         printf("%d ",temp->data);
//         temp=temp->nxt;
//     }   
// }


//Deleting elements in single linked list

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node* nxt;
// };
// void delete(struct node** head,int pos){
//     struct node*temp=*head;
//     struct node*right;
//     if(pos==1){
//         *head=temp->nxt;
//         return ;
//     }   
//     for(int i=1;i<pos-1;i++){
//         temp=temp->nxt;
//     }
//     if(temp->nxt==NULL){
//         printf("Out of Range\n");
//         return;
//     }
//     right=temp->nxt->nxt;
//     temp->nxt=right;
    
    
// }
// int main(){
//     struct node* head=NULL;
//     struct node* temp=NULL;
//     int pos,data;
//     int choice=1;
//     while(choice){
//         struct node* new_node=(struct node*)malloc(sizeof(struct node));
//         printf("Entr the data: \n");
//         scanf("%d",&new_node->data);
//         new_node->nxt=NULL;
//         if(head==NULL){
//             head=temp=new_node;
//         }
//         else{
//             temp->nxt=new_node;
//             temp=new_node;
//         }
//         printf("Entr the choice: ");
//         scanf("%d",&choice);
//     }
//     temp=head;
//     while(temp!=NULL){
//         printf("%d ",temp->data);
//         temp=temp->nxt;
//     }
//     printf("\nEntr the pos to delete    :");
//     scanf("%d",&pos);
//     delete(&head,pos);
//     temp =head;
//     while(temp!=NULL){
//         printf("%d ",temp->data);
//         temp=temp->nxt;
//     }
   
// }


//4.Without the creation of linkedList
// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node*nxt;
// };
// struct node*head=NULL;
// struct node*temp=NULL;

// void insertbeg(int item){
//     struct node*new_node=(struct node*)malloc(sizeof(struct node));
//     new_node->nxt=NULL;
//     new_node->data=item;
//     temp=head;
//     if(head==NULL){
//         head=temp=new_node;
//     }
//     else{
//         new_node->nxt=temp;
//         head=new_node;
//     }
// }

// void insertend(int item){
//     struct node*new_node=(struct node*)malloc(sizeof(struct node));
//     new_node->data=item;
//     new_node->nxt=NULL;
//     struct node*end=NULL;
//     struct node*use=NULL;
//     end=head;
//     while(end->nxt!=0){
//         end=end->nxt;
//     }
//     end->nxt=new_node;
// }

// void insertrandom(int pos,int data){
//     struct node*new_node=(struct node*)malloc(sizeof(struct node));
//     new_node->data=data;
//     new_node->nxt=NULL;
//     struct node*position=NULL;
//     struct node*p1=head;
//     if(pos==1){
//         insertbeg(data);
//     }
//     else{
//     for(int i=1;i<pos-1 && p1!=NULL;i++){
//         position=p1;
//         p1=p1->nxt;
//     }
//     }
//     new_node->nxt=p1->nxt;
//     p1->nxt=new_node;
// }

// void display(){
//     struct node*dis=NULL;
//     dis=head;
//     while(dis!=0){
//         printf("%d ",dis->data);
//         dis=dis->nxt;
//     }
// }
// int main(){
//     insertbeg(2);
//     insertbeg(10);
//     insertend(20);
//     insertrandom(4,50);
//     insertrandom(1,50);
//     display();
// }

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*nxt;
};
struct node*head=NULL;
struct node*temp=NULL;

void insertbeg(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->nxt=NULL;
    new_node->data=item;
    temp=head;
    if(head==NULL){
        head=temp=new_node;
    }
    else{
        new_node->nxt=temp;
        head=new_node;
    }
}

void insertend(int item){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->nxt=NULL;
    struct node*end=NULL;
    struct node*use=NULL;
    end=head;
    while(end->nxt!=0){
        end=end->nxt;
    }
    end->nxt=new_node;
}

void insertrandom(int pos,int data){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->nxt=NULL;
    struct node*position=NULL;
    struct node*p1=head;
    if(pos==1){
        insertbeg(data);
    }
    else{
    for(int i=1;i<pos-1 && p1!=NULL;i++){
        position=p1;
        p1=p1->nxt;
    }
    }
    new_node->nxt=p1->nxt;
    p1->nxt=new_node;
}

void delstart(){
    struct node*del=head;
    head=head->nxt;
    free(del);
}

void delend(){
    struct node*del=head;
    while(del->nxt->nxt!=NULL){
        del=del->nxt;
    }
    struct node*del1=del->nxt;
    free(del1);
    del->nxt=NULL;
}

void display(){
    struct node*dis=NULL;
    dis=head;
    while(dis!=0){
        printf("%d ",dis->data);
        dis=dis->nxt;
    }
}
int main(){
    insertbeg(2);
    insertbeg(10);
    insertend(20);
    insertend(20);
    insertrandom(4,50);
    insertrandom(2,50);
    display();
    printf("\n");
    delstart();
    display();
    printf("\n");
    delend();
    display();
}