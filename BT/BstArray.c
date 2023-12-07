#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int size=10,count=1;
int* array;
void insert(int num){
    int i=0;
    count++;
    if(array[0]==-1){
        array[0]=num;
        return;
    }
    while(i<size){
        if(array[i]>num){
            if(array[2*i+1]==-1){
                array[2*i+1]=num;
                return;
            }
            i=2*i+1;
        }
        else if(array[i]<num){
            if(array[2*i+2]==-1){
                array[2*i+2]=num;
                return;
            }
            i=2*i+2;
        }
        if(2*i+1>=size || 2*i+2>=size){
            size=2*i+1;
            array=(int*)realloc(array,sizeof(int)*size);
            for(int j=count;j<=size;j++){
                array[j]=-1;        
            }
        }
    }
}

int inOrderSucc(int index){
    while(array[2*index+1]!=-1 && 2*index+1<size){
        index=2*index+1;
    }
    return index;
}

int inOrderPre(int index){
    while(array[2*index+2]!=-1 && 2*index+2<size){
        index=2*index+2;
    }
    return index;
}

void delete(int index){
    if((array[2*index+1]==-1 && array[2*index+2]==-1) || 2*index+2<size || 2*index+1<size){
        array[index]=-1;
        return;
    }
    else if(array[2*index+2]!=-1){
        int inOrderSuc=inOrderSucc(2*index+1);
        int temp=array[index];
        array[index]=array[inOrderSuc];
        array[inOrderSuc]=temp;
        return delete(inOrderSuc);
    }
    else{
        int inOrderPred=inOrderPre(2*index+2);
        int temp=array[index];
        array[index]=array[inOrderPred];
        array[inOrderPred]=temp;
        return delete(inOrderPred);
    }

}

int search(int item,int index){
    if(index>size){
        return -1;
    }
    if(array[index]==item){
        return index;
    }
    else{
        if(item<array[index]){
            return search(item,2*index+1);
        }
        else{
            return search(item,2*index+2);
        }
    }
}

void print(int index){
    if(index>=size){
        return;
    }
    print(2*index+1);
    if(array[index]!=-1){
        printf("%d " ,array[index]);
    }
    print(2*index+2);
}


int main(){
    array=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<10;i++){
        array[i]=-1;
    }
    int nums[5]={2,4,5,3};
    for(int i=0;i<4;i++){
        insert(nums[i]);
    }
    // printf("--%d ",search(4,0));
    print(0);
   delete(search(4,0));
   printf("\n");
   //delete()
   print(0);
  // printf("dhariun");
    
   // 
   // print(0);
    // insert(1);
    // insert(9);
    // insert(4);
    // insert(15);
    // insert(14);
    // print(0);
    // printf("\n");
    // delete(1,0);
    // delete(7,0);
    // print(0);
    // if(search(10,0)){
    //     printf("True");
    // }
    // else{
    //     printf("false");
    // }
    
}