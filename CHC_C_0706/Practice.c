// Main의 ary1{10,20,30,40},ary2{50,40,30,20,10},ary3{5,15,25}, ary4{1,2,3}를
// PrintMax 함수에서 최대값, 최소값을 출력할 수 있게 하세요
// int* ptr3[4]를 활용하기
// 최대값, 최소값의 인덱스 또한 출력할 수 있다면 해보기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void PrintMax(int** ptr2, int size, int* cols){
   int Max = -9999;
   int Min = 9999;
   int MaxIIndex = 0; int MaxJIndex = 0;
   int MinIIndex = 0; int MinJIndex = 0;

   for(int i=0;i<size;i++)
   {
      for(int j=0;j<*(cols+i);j++)
      {
         int value = *(*(ptr2+i)+j);
         if(value > Max){
            Max = value;
            MaxIIndex = i;
            MaxJIndex = j;
         }
      }
      
   }
   for(int i=0;i<size;i++)
   {
      for(int j=0;j<*(cols+i);j++)
      {
         int value = *(*(ptr2+i)+j);
         if(value < Min){
            Min = value;
            MinIIndex = i;
            MinJIndex = j;
         }
         
      }
      
   }
   printf("Max : %d\n", Max);
   printf("Min : %d\n", Min);
   printf("MaxIndex : [%d][%d]\n", MaxIIndex,MaxJIndex);
   printf("MinIndex : [%d][%d]\n", MinIIndex,MinJIndex);
}
    
int main(){
   int ary1[4] = {10,20,30,40};
   int ary2[5] = {50,40,30,20,10};
   int ary3[3] = {5,15,25};
   int ary4[3] = {1,2,3};
   int* ptr3[4] = {ary1,ary2,ary3,ary4};
   int cols[4] = {4,5,3,3};
   PrintMax(ptr3,3,cols);
}


























