// CDS10_Search2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define ASC INT_MIN
#define DESC INT_MAX
#define UNK 19940110

// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct Array{
    int* ary; // 동적배열
    int size; // 사이즈
    int type; // ASC,DESC,UNK
}Array;
// ===============================================================
// < 전 역 함 수 >
// ===============================================================

// 구조체를 넘겨받아, 직접 배열을 만들어 넣어주는
void InitArray(Array* mainAry, int size){
    // 0. 이미 배열이 있을 경우, free로 해제하고 아래 진행
    if(mainAry->ary != NULL){
        free(mainAry->ary);
        mainAry->ary = NULL; // 안전하게!
        mainAry->size = 0;
    }
    // 1. 배열을 size만큼 크기로 만들기
    mainAry->ary = (int*)malloc(size * sizeof(int));
    // 2. size를 size로 설정하기
    mainAry->size= size;
    // 3. 모든 요소에 랜덤값 1~100의 값을 넣기
    for(int i=0;i<size;i++){
        mainAry->ary[i] = rand()%100+1;
    }
    mainAry->type = UNK;
}

// 모든 요소들에 대해 출력하는 PrintArray 함수
void PrintArray(Array* mainAry){
    printf("------------------------\n");
    for(int i=0;i<mainAry->size;i++){
        printf("%d ",mainAry->ary[i]);
    }
    printf("\n------------------------\n");
}

// 교환함수
void Swap(int* x, int* y){
    int temp = *x   ;
    *x       = *y   ;
    *y       = temp ;
}
// 모든 요소를 오름차순 또는 내림차순으로 정렬하는 SortArray 함수(선택)
// ASC 오름차순(기본값), DESC 내림차순
void SortArray(Array* mainAry, int type){
    // ---------------------------------------------------
    // 정렬 기준이 제대로 잡히지 않음
    // ---------------------------------------------------
    if(type != ASC && type != DESC){
        // 정렬기준 제대로 안 적어준 것...
        printf("Sort Type Undefined > Asc!\n");
        SortArray(mainAry, ASC);
        return;
    }
    // ---------------------------------------------------
    // 정렬 기준이 제대로 잡힌 경우 -> ASC/DESC중 하나
    // ---------------------------------------------------
    for(int i=0;i<mainAry->size-1;i++){
        int maxIndex = i;
        int minIndex = i;
        for(int j=i+1; j<mainAry->size;j++){
            if(type==ASC){
                if(mainAry->ary[j] > mainAry->ary[maxIndex]){
                    minIndex = j;
                }
            }else{
                if(mainAry->ary[j] < mainAry->ary[minIndex]){
                    maxIndex= j;
                }
            }
            
        }
        // 반복문 끝 -> 최대값 또는 최소값의 위치가 정해짐 > Swap
        if(type == ASC){
        Swap(&mainAry->ary[i], &mainAry->ary[minIndex]);
        }else{
        Swap(&mainAry->ary[i], &mainAry->ary[maxIndex]);
        }
    }
  // 진짜 ㄹㅇ 반복문 모두 끝났으면 ary->type 변경 필요
  if(type==ASC){
    mainAry->type = ASC;
  }else{
    mainAry->type = DESC;
  }

}
// 뒤집기 ArrayReverse
// ASC인 상태면 DESC
// DESC인 상태면 ASC
// 그 외의 경우 -> 진짜 ㄹㅇ 뒤집기
void ArrayReverse(Array* mainAry){
    // 1. 현재 mainAry의 type이 ASC 인경우
    if(mainAry->type == ASC){
        SortArray(mainAry,DESC);
    }
    // 2. 현재 mainAry의 type이 DESC 인경우
    else if(mainAry->type == DESC){
        SortArray(mainAry,ASC);
    }
    // 3. 그 외의 경우
    else{
        // 원본에 해당하는 크기만큼 임시 배열 생성 
        int* temp = (int*)malloc(mainAry->size * sizeof(int));  
        // 모든 데이터를 거꾸로, temp는 순서대로 저장
        // temp의 데이터를 원본에 순서대로 저장하면 뒤집어짐
        // 임시배열 소멸
        free(temp);
    }
    

}


// ===============================================================
int main(){
    srand(time(NULL));
    Array ary = {0};
    InitArray(&ary,10);
    PrintArray(&ary);
    SortArray(&ary, DESC);
    PrintArray(&ary);
    ArrayReverse(&ary);

} // ===============================================================

