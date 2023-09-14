
//Linear search recursion

// #include<stdio.h>
// #include<stdbool.h>

//  bool linearSearch(int* a,int size,int find){
//     if(size==0){
//         return false;
//     }
//     else if(a[size-1]==find){
//         return true;
//     }
//     else{
//         size--;
//         return linearSearch(a,size,find);
//     }

// }
// int main(){
//     int a[5]={1,2,3,4,5};
//     printf("%d",linearSearch(a,5,3));

// }



//Binary Serach using recurson

// int bis(int a[],int size,int left,int right,int find){
//     if(left<=right){
//         int mid=left+((right-left)/2);
//         if(a[mid]==find){
//             return a[mid];
//         }
//         else if(a[mid]>find){
//             right=mid-1;
//         }
//         else if(a[mid]<find){
//             left=mid+1;
//         }
//     }
//     return bis(a,size,left,right,find);
// }


// #include<stdio.h>
// int main(){
// int a[5]={1,2,3,4,6};
// int ans=0;
// int right=4,left=0,size=5,find=4;
// ans=bis(a,size,left,right,find);
// printf("%d",ans);
// }




//bubble sort using recursive

// void bubble(int*a,int size){
//     if(size==1){
//         return;
//     }
//     for(int i=0;i<size-1;i++){
//         if(a[i]<a[i+1]){
//             int *temp=a[i];
//             (a[i])=a[i+1];
//             a[i+1]=temp;
//         }
//     }
//     size--;
//     return bubble(a,size);
// }

// #include <stdio.h>
// int main()
// {
//     int a[5]={6,5,8,3,2};
//     int size=sizeof(a)/sizeof(a[0]);
//     bubble(a,size);
//     for(int i=0;i<size;i++){
//         printf("%d ",a[i]);
//     }
// }


 
// //insertion using recursion

// #include<stdio.h>
// static int x;

// void insertion(int* ans,int size){
    
//     if(size==1){
//         return;
//     }
//     int key=ans[x-size+1];
//     int j=x-size;
//     while(ans[j]>key && j>=0){
//         ans[j+1]=ans[j];
//         j--;
//     }
//     ans[j+1]=key;
//     return insertion(ans,--size);
// }
// int main(){
//     x=5;
    
//     int nums[5]={4,8,1,7,3};
//     insertion(nums,5);
//     for(int i=0;i<5;i++){
//         printf("%d ",nums[i]);
//     }
// }

