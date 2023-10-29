#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char data[100];
    struct node*left;
    struct node*right;
    struct node*next;
};
struct node*tos=NULL;

struct node* createNode(char str[]){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data,str);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void push(struct node* node){
    if(tos==NULL){
        tos=node;
        tos->next=NULL;
    }
    else{
        node->next=tos;
        tos=node;
    }
}

struct node*pop(){
    if(tos==NULL){
        return NULL;
    }

    struct node*popped=tos;
    tos=tos->next;
    popped->next=NULL;
    return popped;
}

void inOrder(struct node*temp){
    if(temp==NULL){
        return;
    }
    //printf("%s+++\n",temp->data);
    inOrder(temp->left);
    printf("%s ",(temp->data));
    inOrder(temp->right);
}

void convertPostfix(char*s){
    struct node*node;
    char*str=strtok(s," ");
    while(str!=NULL){
        if(strcmp(str,"+")==0 ||strcmp(str,"-")==0 ||strcmp(str,"*")==0 ||strcmp(str,"/")==0){
            node=createNode(str);
            node->right=pop();
            node->left=pop();
            push(node);
        }
        else{
            node=createNode(str);
            //printf("%s ",node->data);
            push(node);
        }
        str=strtok(NULL," ");
    }
}

int evalTree(struct node* temp){
    // if(temp==NULL){
    //     return 0;
    // }
    if(temp->left==NULL && temp->right==NULL){
        return atoi(temp->data);
    }
    int left=evalTree(temp->left);
    int right=evalTree(temp->right);
    if(strcmp(temp->data,"+")==0){
        return left+right;
    }
    if(strcmp(temp->data,"-")==0){
        return left-right;
    }
    if(strcmp(temp->data,"*")==0){
        return left*right;
    }
    else{
        return left/right;
    }
}




int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Entr the valid input");
        return 0;
    }
    //char s[]="12 3 *";
    char* s=argv[1];
    convertPostfix(s);
    inOrder(tos);
    printf("\n");
    printf("%d",evalTree(tos));

    
}
