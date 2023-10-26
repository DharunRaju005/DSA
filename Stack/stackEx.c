#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* nxt;
};

struct node* head = NULL;
int count = 0;
int n;

struct node* createNode(int item) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->nxt = NULL;
    return new_node;
}

void stackpush(int data) {
    if (n > count) {
        struct node* new_node = createNode(data);
        new_node->nxt = head;
        head = new_node;
        count++;
    } else {
        printf("Stack is Full\n");
    }
}

int stackpop() {
    if (count == 0) {
        printf("The stack is empty!!\n");
        return -1; // Return some error value
    } else {
        int data = head->data;
        struct node* temp = head;
        head = head->nxt;
        free(temp);
        count--;
        return data;
    }
}

void display(struct node* current) {
    if (current == NULL) {
        printf("The Stack is empty\n");
        return;
    }
    display(current->nxt);
    printf("%d ", current->data);
}

int main() {
    n = 100; 
    char s[] = "12 110 -"; 
    char* str = strtok(s, " ");

    while (str != NULL) {
        if (strcmp(str, "+") == 0) {
            int a = stackpop();
            int b = stackpop();
            stackpush(b + a);
        } else if (strcmp(str, "-") == 0) {
            int a = stackpop();
            int b = stackpop();
            stackpush(b - a);
        } else if (strcmp(str, "*") == 0) {
            int a = stackpop();
            int b = stackpop();
            stackpush(b * a);
        } else if (strcmp(str, "/") == 0) {
            int a = stackpop();
            int b = stackpop();
            if (a == 0) {
                printf("Division by zero\n");
                return 1; 
            }
            stackpush(b / a);
        } else {
            stackpush(atoi(str)); 
        }

        str = strtok(NULL, " "); 
    }

    printf("Final Result: %d\n", stackpop());

    return 0;
}
