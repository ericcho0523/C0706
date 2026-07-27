// C15_PoinerArray2.c // 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 함수 자리 >
// ===============================================================
// 1차원 배열을 넘겨받으면, 랜덤값 1~9를 채우는 함수 구현
void InitArray(int* ary, int size){
    for(int i=0; i<size;i++){
        *(ary+i) = rand()%9+1;
    }
}
void InitPAry(int** ptrs, int size, int* cols){
    for(int i=0;i<size;i++){
        int* ary = *(ptrs+i);
        int arySize = *(cols+i);

        InitArray(ary, arySize);
    }
}
void PrintPAry(int* ptrs[],int size,int cols[]){
    // 넘겨받은 포배 안에 있는 모든 요소들을 출력할 것
    for(int i=0; i<size;i++){
        for(int j=0;j<cols[i]; j++){
            printf("%2d ",ptrs[i][j] ) ;
        }
        printf("\n");

    }
}
// 어려운 버전으로 void PrintPAry 를 void PrintPAry2 로만들기
void PrintPAry2(int** ptrs, int size, int* cols){
    for(int i=0; i<size; i++){
        for(int j=0;j< (*cols+i); j++){
            printf("%2d ", *( *(ptrs+i) +j));
        }
    }
}
// -----------------------------------
void InitArray2(int* ptrs[], int size, int cols2[]){
    // 1~20랜덤값 세팅
    for(int i=0; i<size; i++){
        int originSize = cols2[i];
        for(int j=0; j<originSize; j++){
            ptrs[i][j] = rand()%20+1;
        }
    }
}
void PrintArray2(int* ptrs[], int size, int cols[]){
    for(int i=0; i<size; i++){
        int originSize = cols[i];
        for(int j=0; j<originSize; j++){
            printf("%2d ",ptrs[i][j]);
        }
        printf("\n");
    }
}
// -----------------------------------------------------
void Quiz1(int** ptrs, int size, int* cols3){
    for(int i=0;i<size;i++){
        for(int j=0; j<*(cols3+i); j++){
            // *(*(ptrs+i) + j); // ptrs[i][j]
            printf("%2d ",*(*(ptrs+i) + j));
        }
    
    }
}
// --------------------------------------------------------
void Quiz2(int** ptrs, int size, int* cols){
    int Max = -9999;
    int Min =  9999;
    int maxIIndex=0, maxJIndex=0;
    int minIIndex=0, minJIndex=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0; j<*(cols+i); j++)
        {
            int val = *(*(ptrs+i) + j);
            if(val > Max)
            {
                Max = val;
                maxIIndex = i;
                maxJIndex = j;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0; j<*(cols+i); j++)
        {
            int val = *(*(ptrs+i) + j);
            if(val < Min)
            {
                Min = val;
                minIIndex = i;
                minJIndex = j;
            }
        }
    }
    // -------------------
    printf("%d %d\n", Max, Min);
    printf("%d %d\n", maxIIndex, minIIndex);

}
// ===============================================================
int main(){
    srand(time(NULL));
    // --------------------------------------------------
    int ary1[4]={0};
    int ary2[2]={0};
    int ary3[6]={0};
    int* ptrs[3] = {ary1, ary2, ary3};
    int cols[3] = {sizeof(ary1)/4,sizeof(ary2)/4,sizeof(ary3)/4};
    InitPAry(ptrs,3, cols);
    PrintPAry(ptrs,3, cols);
    // ---------------------------------------------------
    int ary4[7] = {0};
    int ary5[6] = {0};
    int ary6[5] = {0};
    int ary7[4] = {0};
    int cols2[4] = {7,6,5,4};
    int* ptrs2[4] ={ary4, ary5, ary6, ary7};
    InitArray2(ptrs2, 4, cols2);
    PrintArray2(ptrs2, 4, cols2);
    // ary4~7에 랜덤값 1~20을 넣는 InitArray2
    // 모든 요소를 출력하는 PrintArray2를 만드세요 
    // ----------------------------------------
    // Main의 ary1{1,2,3}, ary2{4,5,6,7}, 
    // ary3{8,9}를 PrintAll 함수가 모두 출력
    // int* ptr2[3]을 활용하기
    int quiz1[3] = {1,2,3};
    int quiz2[4] = {4,5,6,7};
    int quiz3[2] = {8,9};
    int* ptrs3[3] = {quiz1, quiz2, quiz3};
    int  cols3[3] = {3,4,2};
    Quiz1(ptrs3, 3, cols3);
    // ---------------------------------
    int a1[4] =    {10,20,30,40};
    int a2[5] = {10,20,30,40,50};
    int a3[3] =        {5,15,25};
    int a4[3] =          {1,2,3};
    int* ptrs4[4] = {a1, a2, a3, a4};
    int cols4[4] = {4,5,3,3};
    Quiz2(ptrs4, 4, cols4);


    
    

}// -=============================================================
/* ---------------------------------------------------------------
< 포인터배열의 진짜 사용처 >
이차원배열을 관리할 순 있지만, 추후 배울
"배열 포인터"가 2차원 배열을 관리함.
=> 서로 길이가 다른 배열을 관리할 때 사용

-------------------------------------------------------------------*/  