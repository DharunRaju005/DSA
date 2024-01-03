#include<stdio.h>

void swap(int* nums,int i,int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}
void heapify(int *nums,int numsSize,int i){
    int large=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<numsSize && nums[left]<nums[large]){
        large=left;
    }
    if(right<numsSize && nums[right]<nums[large]){
        large=right;
    }
    if(large!=i){
        swap(nums,i,large);
        heapify(nums,numsSize,large);
    }
}
void heapsort(int *nums,int numsSize){
    for(int i=numsSize/2-1;i>=0;i--){
        heapify(nums,numsSize,i);
    }
    for(int i=numsSize-1;i>=0;i--){
        swap(nums,i,0);
        heapify(nums,i,0);
    }
}
int main(){
    int nums[5]={1,2,3,4,5};
    heapsort(nums,5);
    for(int i=0;i<5;i++){
        printf("%d ",nums[i]);
    }
}