#include<stdio.h>
int Indx(int nums[],int last){
    int max=0;
    for(int i=0;i<=last;i++){
        if(nums[i]>nums[max]){
            max=i;
        }
    }
    return max;
}

void swap(int nums[],int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }

int main(){
    int n=5;
    int nums[]={1,2,3,4,5};
    for(int i=0;i<n;i++){
        int last=n-i-1;
        int findMax=Indx(nums,last);
        //printf("%d",findMax);
        swap(nums,findMax,last);
    }
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
}

