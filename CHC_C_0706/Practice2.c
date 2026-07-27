// Practice2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
void InitAry(int *ptr,int size){
    for(int i=0;i<size;i++){
        *(ptr+i) = i+1;
    }
}
void Print2Ary(int *ptr, int size){
    for(int i=0;i<size;i++){
        printf("%d ",*(ptr+i)*2);
    }
}

int main(){
    int ary[30]={0};
    InitAry(ary,30);
    Print2Ary(ary,30);

}