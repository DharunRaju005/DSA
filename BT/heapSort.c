#include<stdio.h>

void swap(int* nums,int i,int large){
    int temp=nums[i];
    nums[i]=nums[large];
    nums[large]=temp;
    
}

void heapify(int* nums,int numsSize,int i){
    int large=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<numsSize && nums[left]>nums[large]){
        large=left;
    }
    if(right<numsSize && nums[right]>nums[large]){
        large=right;
    }
    if(large!=i){
        swap(nums,i,large);
        heapify(nums,numsSize,large);
    }

}

    void heapSort(int* nums,int numsSize){
        for(int i=numsSize/2-1;i>=0;i--){
            heapify(nums,numsSize,i);
        }

        for(int i=numsSize-1;i>=0;i--){
            swap(nums,0,i);
            heapify(nums,i,0);
        }
    }

    int main(int argc,char* argv[]){
        int nums[argc-1];
        for(int i=1;i<argc;i++){
            nums[i-1]=atoi(argv[i]);
        }
        
        heapSort(nums,argc-1);
        for(int i=0;i<argc-1;i++){
            printf("%d ",nums[i]);
        }
    }