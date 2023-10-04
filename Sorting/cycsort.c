#include<stdio.h>
void swap(int nums[],int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
int main(){
    int n=5;
    int nums[]={5,2,3,4,1};
    int i=0;
    while(i<n){
        int correct=nums[i]-1;
        if(nums[i]!=correct){
            swap(nums,i,correct);
        }
        i++;
    }
        for(int i=0;i<5;i++){
        printf("%d ",nums[i]);
    }
}