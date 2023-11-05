#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node*right;
};
struct node* root=NULL;
struct node* suc=NULL;

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* helpInsert(int data,struct node*node){
    if(node==NULL){
        return createNode(data);
    }else{
        if(data>node->data){
            node->right=helpInsert(data,node->right);
        }
        else{
            node->left=helpInsert(data,node->left);
        }
    }
    return node;
}

void insert(int data){
        root=helpInsert(data,root);
}

struct node* helpSearch(int data,struct node*node){
    if(node==NULL){
        return NULL;
    }
        if(node->data==data){
        return node;
    }
    else{
        if(node->data>data){
            return helpSearch(data,node->left);
        }
        return helpSearch(data,node->right);
    }
}

void search(int data){
    struct node*temp= helpSearch(data,root);
    //printf("%d----",temp->data);
    if(temp!=NULL){
        printf("%d is Found \n",temp->data);
        return;
    }
    printf ("%d is not found\n",data);
}

struct node* minSucc(struct node*node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}

struct node*helpInOrderSucc(int data,struct node*node,struct node*suc){
    if(node==NULL){
        return suc;
    }
    if(node->data==data && node->right!=NULL){
        return minSucc(node->right);
    }
    else if(node->data>data){
        //suc=node;
        return helpInOrderSucc(data,node->left,suc);
    }
    else{
        return helpInOrderSucc(data,node->right,suc);
    }
    //return suc;

}

struct node*inOrderSucc(int data){
    return helpInOrderSucc(data,root,suc);
}

struct node* retParent(struct node*snode){
    if(snode==root || snode==NULL){
        return NULL;
    }
    struct node*temp=root;
    while(temp->left!=snode && temp->right!=snode){
        //printf("%d ...",temp -> data);
        if(temp->data<snode->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        //printf("%d ...",temp -> data);
    }
     //printf("%d-----\n",temp->data);
    return temp;
}


void helpDelete(int data,struct node*node){

    if(node==root){

        if(node->left==NULL && node->right==NULL){
			root=NULL;
            free(node);

        }
        else if(node->left!=NULL && node->right!=NULL){
            //puts("ppp");
            struct node* succssor=inOrderSucc(data);

           // printf("%d +++++",succssor -> data);
            struct node*parent=retParent(succssor);
            //printf("%d +++++",parent -> data);
            //printf("----%d-----\n",parent->data);
            node->data=succssor->data;

            if(parent->right==succssor){
                parent->right=NULL;
            }
            else{
                parent->left=NULL;
            }
            free(succssor);

            //temp->right=helpDelete(succssor->data,temp->right);
           //free(succssor);
            //return temp;
        }
        else if(node->left!=NULL){
            root=node->left;
            free(node);

        }
        else{
            root=root->left;
        }
    }
    else{

    struct node* temp=helpSearch(data,root);

    //deleting node is a leaf node
        //puts("qqq");
    if(temp->left==NULL && temp->right==NULL){

        struct node* parent=retParent(temp);
        if(parent->right==temp){
            parent->right=NULL;
        }
        else{
            parent->left=NULL;
        }
            //puts("rrr");
        free(temp);
        //return true;
    }

    //deleting node has 2 children
    else if(temp->left!=NULL && temp->right!=NULL){
            //puts("ppp");
            struct node* succssor=inOrderSucc(data);

           // printf("%d +++++",succssor -> data);
            struct node*parent=retParent(succssor);
            //printf("%d +++++",parent -> data);
            //printf("----%d-----\n",parent->data);
            temp->data=succssor->data;

            if(parent->right==succssor){
                parent->right=NULL;
            }
            else{
                parent->left=NULL;
            }
            free(succssor);
            return;
            //temp->right=helpDelete(succssor->data,temp->right);



           //free(succssor);
            //return temp;
    }

    //if one child
    else if(temp->left!=NULL && temp->right==NULL){
        //puts("ooo");
        temp->data=temp->left->data;
        free(temp->left);
        temp->left=NULL;
        return;
        //return true;
    }

    else if(temp->right!=NULL && temp->left==NULL){
        //puts("qqwp");
        temp->data=temp->right->data;
        free(temp->right);
        temp->right=NULL;
        return;
        //return true;
    }
        //puts("plllllp");
   // return temp;
    //return succssor;
    // while(node->data!=data){
    //     if(node)
    }
}

//     struct node* helpDelete(int data, struct node* node) {
//     if (node==NULL) {
//         return node;
//     }
//     if (data<node->data) {
//         node->left = helpDelete(data, node->left);
//     } else if (data > node->data) {
//         node->right = helpDelete(data, node->right);
//     } else {

//         if (node->left == NULL && node->right == NULL) {
//             free(node);
//             return NULL;
//         }

//         else if (node->left != NULL && node->right != NULL) {
//             struct node* successor = inOrderSucc(data);
//             node->data = successor->data;
//             node->right = helpDelete(successor->data,node->right);
//         }

//         else {
//             struct node* temp = node;
//             if (node->left != NULL) {
//                 node=node->left;
//             } else {
//                 node=node->right;
//             }
//             free(temp);
//         }
//     }

//     return node;
// }


void delete(int data){
    helpDelete(data,root);
}




void helpDisplay(struct node*node){
    if(node==NULL){
        return;
    }
    helpDisplay(node->left);
    printf("%d ",node->data);
    helpDisplay(node->right);
}

void display(){
    helpDisplay(root);
}



int main(){
    int nums[]={1,10,3,23,2,5,21,25};
    for(int i=0;i<8;i++){
        insert(nums[i]);
    }
    printf("\n");
    display();
    //retParent(3);
    printf("\n");
    delete(1);
    display();
    printf("\n");
    search(2);
    printf("%d",inOrderSucc(23)->data);

}


// // C code to convert infix to postfix expression

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_EXPR_SIZE 100

// // Function to return precedence of operators
// int precedence(char operator)
// {
// 	switch (operator) {
// 	case '+':
// 	case '-':
// 		return 1;
// 	case '*':
// 	case '/':
// 		return 2;
// 	case '^':
// 		return 3;
// 	default:
// 		return -1;
// 	}
// }

// // Function to check if the scanned character 
// // is an operator
// int isOperator(char ch)
// {
// 	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
// 			|| ch == '^');
// }

// // Main functio to convert infix expression
// // to postfix expression
// char* infixToPostfix(char* infix)
// {
// 	int i, j;
// 	int len = strlen(infix);
// 	char* postfix = (char*)malloc(sizeof(char) * (len + 2));
// 	char stack[MAX_EXPR_SIZE];
// 	int top = -1;

// 	for (i = 0, j = 0; i < len; i++) {
// 		if (infix[i] == ' ' || infix[i] == '\t')
// 			continue;
	
// 		// If the scanned character is operand
// 		// add it to the postfix expression
// 		if (isalnum(infix[i])) {
// 			postfix[j++] = infix[i];
// 		}
	
// 		// if the scanned character is '('
// 		// push it in the stack
// 		else if (infix[i] == '(') {
// 			stack[++top] = infix[i];
// 		}
	
// 		// if the scanned character is ')'
// 		// pop the stack and add it to the 
// 		// output string until empty or '(' found
// 		else if (infix[i] == ')') {
// 			while (top > -1 && stack[top] != '(')
// 				postfix[j++] = stack[top--];
// 				top--;
// 		}
	
// 		// If the scanned character is an operator
// 		// push it in the stack
// 		else if (isOperator(infix[i])) {
// 			while (top > -1
// 				&& precedence(stack[top])
// 						>= precedence(infix[i])){
// 				postfix[j++] = stack[top--];
//                 }
// 			stack[++top] = infix[i];
// 		}
// 	}

// 	// Pop all remaining elements from the stack
// 	while (top > -1) {
// 		if (stack[top] == '(') {
// 			return "Invalid Expression";
// 		}
// 		postfix[j++] = stack[top--];
// 	}
// 	postfix[j] = '\0';
// 	return postfix;
// }

// // Driver code
// int main()
// {
// 	char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

// 	// Function call
// 	char* postfix = infixToPostfix(infix);
// 	printf("%s\n", postfix);
// 	free(postfix);
// 	return 0;
// }
