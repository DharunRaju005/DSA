#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=-1;

void stackpush(int* nums,int data,int len){
    if(count==len){
        printf("Stack is full\nso the gn element %d cannot be added\n",data);
        return;
    }
        nums[++count]=data;
    }

void stackpop(int* nums,int len){
    if(count==-1){
        printf("the stack is empty\n");
        return;
    }
    //*len-=1;
    count=count-1;   
}

void peek(int* nums){
    printf("Peek element in the stack is %d \n",nums[count]);
}

void display(int* nums){
     for(int i=count;i>=0;i--){
         printf("%d ",nums[i]);
     }
     printf("\n");
}

int main(){
    int n=6;
    int* nums=(int*)malloc(sizeof(int)*n);
    //memset(nums, -1, sizeof(nums));
    // stackpush(nums,5,n);
    // stackpush(nums,15,n);
    // stackpush(nums,15,n);
    // stackpush(nums,28,n);
    // stackpush(nums,15,n);
    // stackpush(nums,35,n);
    // stackpop(nums,n);
    //  stackpop(nums,n);
    //  stackpop(nums,n);
    //  stackpop(nums,n);
    //  stackpop(nums,n);
    //  stackpop(nums,n);
    //  stackpop(nums,n);
    stackpush(nums,90,n);
    stackpush(nums,90,n);
    stackpush(nums,20,n);
   // printf("%d",count);
     stackpush(nums,91,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpush(nums,23,n);
     stackpush(nums,2,n);
     stackpush(nums,3,n);
     stackpush(nums,30,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpop(nums,n);
     stackpush(nums,45,n);
     stackpush(nums,4,n);
     //stackpop(nums,n);
     display(nums);
     peek(nums);
     //stackpop(nums,n);
}
