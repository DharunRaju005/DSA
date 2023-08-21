//1.Searching element in Array

// #include<stdio.h>
// int main(){
//     int a[5]={1,2,3,4,5};
//     printf("Entr the the element");
//     int n;
//      int flg=0;
//     scanf("%d",&n);
//     for(int i=0;i<5;i++){
//         if(n==a[i]){
           
//             flg++;
//             printf("Found!!");
//             break;
//         }
//     }
//     if(flg==0){
//         printf("Not Found o_o");
//     }
// }


//2.Inserting,removing,len
// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     int *nums=(int*)malloc(sizeof(int)*5);
//     int pos;
//     int ele;
//     scanf("%d",&pos);
//     scanf("%d",&ele);
//     void insert(int*nums,int pos,int ele){
//         nums=(int*)realloc(nums,sizeof(int)*6);
//         for(int i=5;i>=pos;i--){
//             nums[i]=nums[i-1];
//         }
//         nums[pos-1]=ele;
//         for(int i=0;i<6;i++){
//             printf("%d ",nums[i]);
//         }
//     }
//     void del(int*nums,int pos){
//         for(int i=pos-1;i<6;i++){
//             nums[i]=nums[i+1];
//         }
//        for(int i=0;i<5-1;i++){
//             printf("%d ",nums[i]);
//         }
        
//     }
//     for(int i=0;i<5;i++){
//         scanf("%d",&nums[i]);
//     }
//     insert(nums,pos,ele);
//     printf("\nDeleted\n");
//     del(nums,pos);
//     int len=0;
//     printf("\nSize of array");
//     for(int i=0;i<5;i++){
//         len++;
//     }
//     printf(":%d",len);    
// }

// //3.Fib
// #include<stdio.h>
// #include<stdlib.h>
//  int fib(int a){
//         if(a==0){
//             return 0;
//             }
//         else if(a==1){
//             return 1;
//         }
//         else{
//             return fib(a-1)+fib(a-2);
//         }
//         }
// int* fn(int n){
   
//     int *ans=(int*)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++){
//         ans[i]=fib(i);
//     }
//     return ans;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     printf("%d\n",n);
//     int *fin=fn(n);
//     for(int i=0;i<n;i++){
//         printf("%d ",fin[i]);
//     }
    
// }

// //4.Sorting using bubble sort
// #include<stdio.h>
// int main(){
//     int n=5;
//     int nums[5]={1,2,3,4,5};
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(nums[j]<nums[j+1]){
//                 int temp=nums[j];
//                 nums[j]=nums[j+1];
//                 nums[j+1]=temp;
//             }

//         }
//     }
//     for(int i=0;i<5;i++){
//         printf("%d ",nums[i]);
//     }
// }


//Sorting using insertion sort
// #include<stdio.h>
// int main(){
//     int n=5;
//     int nums[5]={7,2,3,4,5};
//     for(int i=0;i<5;i++){
//         int key=nums[i];
//         int j=i-1;
//         while (j >= 0 && nums[j] > key) {
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = key;
//     }
//     for(int i=0;i<5;i++){
//        printf("%d ",nums[i]);
//      }
//     }

//5.Retrieve a numerical array from an alphanumeric array

//  #include<stdio.h>
//  #include<string.h>
//  #include<ctype.h>
//  int main(){

//      char a[5][20]={"Dhar12un","1a","6hd","gdsh2","hhds"};
//      for(int i=0;i<5;i++){
//          for(int j=0;j<strlen(a[i]);j++){
//             int c=0;
//              if(isdigit(a[i][j])){
//                  printf("%c",a[i][j]);

//              }
//          }
//              printf(" ");
//      }
//  }
