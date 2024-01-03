#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
    int height;
};

int height(struct node* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}

struct node* createNode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=newnode->right=NULL;
    newnode->data=data;
    newnode->height=1;
    return newnode;
}

/*Right-Right case
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4

*/
struct node* leftRotate(struct node* z){
        struct node* y=z->right;
        struct node* T2=y->left;
        y->left=z;
        z->right=T2;

        z->height=fmax(height(z->left),height(z->right))+1;
        y->height=fmax(height(y->left),height(y->right))+1;

        return y;
}

/*Left-Left Case
T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
*/

struct node *rightRotate(struct node *z) 
{ 
    struct node *y = z->left; 
    struct node *T3 = y->right; 
  
    y->right = z; 
    z->left = T3;
 
    z->height = fmax(height(z->left), 
                    height(z->right)) + 1; 
    y->height = fmax(height(y->left), 
                    height(y->right)) + 1; 
  
    // Return new root 
    return y; 
} 

int checkBalance(struct node* node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

struct node* insert(struct node* node,int data){
    if(node==NULL){
        return createNode(data);
    }
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
    else{
        return node;
    }

    node->height=fmax(height(node->left),height(node->right))+1;

    int balance=checkBalance(node);

    //left left case
    if (balance > 1 && data < node->left->data) 
        return rightRotate(node); 

     // Right Right Case 
    if (balance < -1 && data > node->right->data) 
        return leftRotate(node);
    
    // Right Left case
    if (balance < -1 && data < node->right->data){ 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    }

    //Left Right case
    if (balance > 1 && data > node->left->data){ 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    }
    return node;
}

void inOrder(struct node *root){ 
    if (root==NULL) {
        return;
    } 
    printf("%d ", root->data); 
    inOrder(root->left); 
    inOrder(root->right); 
} 


int main() 
{ 
  struct node *root = NULL; 
  
  /* Constructing tree given in the above figure */
  root = insert(root, 10); 
  root = insert(root, 20); 
  root = insert(root, 30); 
  root = insert(root, 40); 
  root = insert(root, 50); 
  root = insert(root, 25); 
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */
  
  printf("Inorder traversal of the constructed AVL"
         " tree is \n"); 
  inOrder(root); 
  
  return 0; 
} 