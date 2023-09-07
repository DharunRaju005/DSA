//1 Creating a singly linked list

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

// 2.Inserting elemennts in singly linked list


// #include<stdio.h>
// #include<stdlib.h>
// #include "insertExtern.c"
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


//3.Deleting elements in single linked list

// #include<stdio.h>
// #include<stdlib.h>
// #include "deleteExtern.c"
// void delete(struct node** head,int pos){
//    struct node*temp=*head;
//    struct node*right;
//    if(pos==1){
//        *head=temp->nxt;
//        return ;
//    }   
//    for(int i=1;i<pos-1;i++){
//        temp=temp->nxt;
//    }
//    if(temp->nxt==NULL){
//        printf("Out of Range\n");
//        return;
//    }
//    right=temp->nxt->nxt;
//    temp->nxt=right;
// }


//4.Without the creation of linkedList
//#include<stdio.h>
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


//5 Menu driven program
//  #include<stdio.h>
//  #include<stdlib.h>

//  struct node{
//      int data;
//      struct node*nxt;
//  };
//  struct node*head=NULL;
//  struct node*temp=NULL;

//  void insertbeg(int item){
//      struct node*new_node=(struct node*)malloc(sizeof(struct node));
//      new_node->nxt=NULL;
//      new_node->data=item;
//      temp=head;
//      if(head==NULL){
//          head=temp=new_node;
//      }
//      else{
//          new_node->nxt=temp;
//          head=new_node;
//      }
//  }

//  void insertend(int item){
//      struct node*new_node=(struct node*)malloc(sizeof(struct node));
//      new_node->data=item;
//      new_node->nxt=NULL;
//      struct node*end=NULL;
//      struct node*use=NULL;
//      end=head;
//      while(end->nxt!=0){
//          end=end->nxt;
//      }
//      end->nxt=new_node;
//  }

//  void insertrandom(int pos,int data){
//      struct node*new_node=(struct node*)malloc(sizeof(struct node));
//      new_node->data=data;
//      new_node->nxt=NULL;
//      struct node*position=NULL;
//      struct node*p1=head;
//      if(pos==1){
//          insertbeg(data);
//      }
//      else{
//      for(int i=1;i<pos-1 && p1!=NULL;i++){
//          position=p1;
//          p1=p1->nxt;
//      }
//      }
//      new_node->nxt=p1->nxt;
//      p1->nxt=new_node;
//  }

//  void delstart(){
//      struct node*del=head;
//      head=head->nxt;
//      free(del);
//  }

//  void delend(){
//      struct node*del=head;
//      while(del->nxt->nxt!=NULL){
//          del=del->nxt;
//      }
//      struct node*del1=del->nxt;
//      free(del1);
//      del->nxt=NULL;
//  }

//  void delrandom(int pos){
//      if(pos==1){
//          delstart();
//      }
//      else{
//      struct node*del=head;
//      for(int i=1;i<pos-1 && del->nxt!=0;i++){
//          del=del->nxt;
//      }
//      struct node*del1=del->nxt->nxt;
//      struct node*tem=del->nxt;
//      //del->nxt=del1;
//      //free(tem);
//      del->nxt=del->nxt->nxt;
//      free(del->nxt);
//      }
//  }

//  void search(int item){
//      struct node*temp=head;
//      int pos=1;
//      while(temp!=0){
//          if(temp->data==item){
//              printf("Found!!\nAt position %d \n",pos);
//          }
//          pos++;
//          temp=temp->nxt;
//      }
//  }

//  void len(){
//          struct node*dis=NULL;
//          dis=head;
//          int count=0;
//          while(dis!=0){
//              count++;
//              dis=dis->nxt;
//          }
//          printf("Length of Linked list :%d\n",count);
//  }


//  void display(){
//      struct node*dis=NULL;
//      dis=head;
//      while(dis!=0){
//          printf("%d ",dis->data);
//          dis=dis->nxt;
//      }
//      printf("\n");
//  }

//  int main(){
//      int loop=1,choice,item;
//      while(loop){
//          printf("Entr 1 to insert beginning\nEntr 2 to insert at end\nEntr 3 to insert at random\nEntr 4 to delstart\nEntr 5 to delete at end\nEntr 6 to delete at random position\nEntr 7 to find the length\nEntr 8 to SearchElement\nEntr 9 to display\n");
//          printf("Entr the choice : ");
//          scanf("%d",&choice);
         
//          if(choice==1){
//              printf("Entr the data");
//              scanf("%d",&item);
//              insertbeg(item);
//          }
//          else if(choice==2){
//               printf("Entr the data");
//               scanf("%d",&item);
//               insertend(item);
//          }
//          else if(choice==3){
//                  int pos;
//                  printf("Entr the data;");
//                  scanf("%d",&item);
//                  printf("Entr the position");
//                  scanf("%d",&pos);
//                  insertrandom(pos,item);
//          }
//          else if(choice==4){
//              delstart();
//          }
//          else if(choice==5){  
//              delend();
//          }
//          else if(choice==6){
//              int pos;
//              printf("Entr the position\n");
//              scanf("%d",&pos);
//              delrandom(pos);
//          }
//          else if(choice==7){
//              len();
//          }
//          else if(choice==8){
//              printf("Entr the element to search\n");
//              scanf("%d",&item);
//              search(item);
//          }
//          else{
//          display();
//          }
//          printf("Entr 1 to continue or 0 to end: ");
//          scanf("%d",&loop);
//     } 
//  }

// //DoubleLinkedList
