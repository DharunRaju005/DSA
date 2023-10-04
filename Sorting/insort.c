#include<stdio.h>
void swap(int nums[],int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
int main(){
    int n=5;
    int nums[]={1,2,3,4,5};
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(nums[j]>nums[j-1]){
                swap(nums,j,j-1);
            }
            else{
                break;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",nums[i]);
    }
}

    