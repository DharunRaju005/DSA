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
            array=(int*)realloc(array,sizeof(int)*size*3);
            size=size*3;
            for(int j=count;j<=size;j++){
                array[j]=-1;        
            }
        }
    }
}

void delete(int item,int index){
    
    if(index>size){
        return;
    }
    delete(item,2*index+1);
    if(array[index]==item){
        array[index]=-1;
    }
    delete(item,2*index+2);
}

bool search(int item,int index){
    if(index>size){
        return false;
    }
    if(array[index]==item){
        return true;
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
    if(index>size){
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
    int nums[5]={5,2,3,6,7};
    for(int i=0;i<5;i++){
        insert(nums[i]);
    }
    insert(1);
    insert(9);
    insert(4);
    insert(15);
    insert(14);
    print(0);
    printf("\n");
    delete(1,0);
    delete(7,0);
    print(0);
    if(search(10,0)){
        printf("True");
    }
    else{
        printf("false");
    }
    
}