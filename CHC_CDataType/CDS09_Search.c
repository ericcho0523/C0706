// CDS09_Search.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE INT_MAX
#define ARYSIZE 1000
#define ASC 0   // 오름차순
#define DESC 1  // 내림차순
#define UNK -1  // UNKnown 현재 상태를 알 수 없음

// =======================================================
// < 구 조 체 >
// =======================================================

typedef struct Array{
    int ary[ARYSIZE];
    int size;
    int type; // 0이면 오름차순, 1이면 내림차순 정렬되어있음
}Array;
// =======================================================
// < 전 역 함 수 >
// =======================================================
void LinearSearch(){
    int ary[100000]={0};
    int size = 100000;
    // ary에 1부터 순서대로 데이터 넣기.
    // 특정값이 몇번째에 있니?
    for(int i=0; i<size; i++)
        ary[i] = i+1;
    clock_t start, end;
    start = clock();
    // -------------------------------------------
    // 선형 검색
    printf("< Start > \n");
    int target = 67000;
    for(int i=0; i<size; i++){
        if(ary[i] == target){
            printf("Location : %d\n", i);
            break;
        }
    }
    // -------------------------------------------
    end = clock();
    printf("Clock : %.3lf\n", (double)(end-start));
}

void InitArray(Array* ary){
    ary->size = ARYSIZE;
    for(int i=0; i<ARYSIZE; i++){
        ary->ary[i] = rand()%ARYSIZE+1; // 1~1000 랜덤값
    }
    ary->type = UNK;
    
}

void BubbleSort(Array* ary, int type){
    for(int i=0; i < ary->size - 1; i++){
        // 점점 횟수가 줄어들게 조정
        for(int j=0; j< ary->size-1-i; j++){
            // 오름차순 ASC, 내림차순 DESC 에 따라 부등호가 다름
            if(type==ASC){
                // 왼쪽이 오른쪽보다 크다면...
                if(ary->ary[j] > ary->ary[j+1]){
                    // 교환
                    int temp = ary->ary[j+1];
                    ary->ary[j+1] = ary->ary[j];
                    ary->ary[j] = temp;
                }
                ary->type = ASC;
            }else if(type==DESC){
                // 왼쪽이 오른쪽보다 작다면...
                if(ary->ary[j] < ary->ary[j+1]){
                    // 교환
                    int temp = ary->ary[j+1];
                    ary->ary[j+1] = ary->ary[j];
                    ary->ary[j] = temp;
                }
                ary->type = DESC;
            }else{
                // 잘못된 값을 입력하면->본인이 스스로 규칙 정하기(ASC)
                BubbleSort(ary, ASC); // 재귀함수
                return;
            }

        }
    }
}

void PrintArray(Array* ary){
    printf("----------------\n");
    for(int i=0; i<ary->size; i++){
        printf("%d ", ary->ary[i]);
    }
    printf("\n----------------\n");
}

// 이진검색
// 정렬이 안 되어있으면, 강제 정렬 시키기
void BinarySearch(Array* ary, int target){
    // 정렬 여부 확인하기
    if(ary->type==ASC){
        int left  = 0;
        int right = ary->size-1;
        for(;1;){
            if(left>right){
                printf("Not Found...\n");
                return;
            }
            int mid = (left+right)/2 ; // 인덱스

            if(ary->ary[mid] == target){
                printf("Found! %d Index\n", mid);
                return;
            }
            else if(ary->ary[mid] < target) 
                left = mid+1;
            else                 
                right = mid-1;
        }
    }
    else if(ary->type==DESC){
        int left  = 0;
        int right = ary->size-1;
        for(;1;){
            if(left>right){
                printf("Not Found...\n");
                return;
            }
            int mid = (left+right)/2 ; // 인덱스

            if(mid == target){
                printf("Found! %d Index\n", mid);
                return;
            }
            else if(mid > target) left = mid+1;
            else                  right = mid-1;
        }
    }
    else{ //ary->type -> UNK
        // 강제로 오름차순 정렬 시킨 후 다시 검색
        printf("Not Sorted.. Force Asc Sort\n");
        Sleep(1000);
        BubbleSort(ary,ASC);
        printf("Asc Sort Complete\n");
        printf("Start Search ASC\n");
        Sleep(2000);
        BinarySearch(ary, ASC);
    }
}

// 리팩토링(Refactorying)이란??
// 기존의 알고리즘의 결과는 동일하되
// 시간복잡도를 줄이거나, 코드를 줄이거나, 효율적으로 변경하는
// 일련의 과정들 = 최적화
// ★★ 절 대 처음부터 리팩토링 하지말고, 1순위는 "완성" 먼저 ★★

// =======================================================
int main(){
    srand(time(NULL));
    // 이진 검색 - Binary Search
    // 타겟이 있을 범위를 반으로 줄여 가면서(log)
    // 원하는 값이 있는지 찾는 방법
    // 반으로 줄이기 위해서는 정렬이 반드시 되어있어야함
    // ----------------------------------------------
    // 간단한 정렬 방법 - 버블정렬(Bubble Sort) -> 함수
    Array ary;
    InitArray(&ary);
    ary.ary[3] = 10;
    ary.ary[4] = 100;
    ary.ary[5] = 1000;
    BubbleSort(&ary, ASC);
    PrintArray(&ary);
    BinarySearch(&ary, 1);

}// ======================================================