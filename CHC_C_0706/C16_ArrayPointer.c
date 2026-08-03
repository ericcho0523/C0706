// C16_ArrayPointer.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 함수 자리 >
// ===============================================================
// 넘겨받은 2차원 배열에 모든 요소에 랜덤값 1~9 삽입
// void InitAry(int (*ary2)[5], int row){}
// int* ary -> 배열주소 받을 수 있음
// 배열[5] -> 배열을 5개 만듦.

void InitAry(int ary2[][5], int row){
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            ary2[i][j] = rand()%9+1;
        }
    }
}
// <실습> 알잘딱 이름짓고 구현하고 메인에서 테스트하기.
// 넘겨받은 2차원 배열의 모든 요소를 이뿌게 출력
void PrintAry(int ary3[][5], int row){
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            printf("%2d ",ary3[i][j]);
        }
        printf("\n");
    }
    printf("====================\n");
}
// 넘겨받은 2차원 배열의 모든 요소를 +1
void AddOneAry(int ary3[][5], int row){
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            printf("%2d ",ary3[i][j]+1);
        }
        printf("\n");
    }
    printf("====================\n");
}
// 넘겨받은 2차원 배열의 모든 요소를 -1
void MinusOneAry(int ary3[][5], int row){
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            printf("%2d ",ary3[i][j]-1);
        }
        printf("\n");
    }
    printf("====================\n");
}
// 넘겨받은 2차원 배열의 모든 요소 중 최대값, 최소값 출력
void MaxMinAry(int ary3[][5], int row){
    int Max = -9999;
    int Min = 9999;
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            int val = ary3[i][j];
            if(val > Max){
                Max = val;
            }
        }
    }
    for(int i=0;i<row;i++){
        int col = 5;
        for(int j=0;j<col;j++){
            int val = ary3[i][j];
            if(val < Min){
                Min = val;
            }
        }
    }
    printf("Max : %d\n", Max);
    printf("Min : %d\n", Min);
}
// 넘겨받은 2차원 배열의 모든 요소를 거꾸로 저장
// 1 2 3    4 5 6 ->   6 5 4    3 2 1
// < 내가 혼자 푼 것 >
// void ReverseAry(int ary3[][5],int row){
//     for(int i=0;i<row;i++){
//         int col = 5;
//         for(int j=0;j<col;j++){
//             int rev = ary3[row-1-i][col-1-j];
//             printf("%2d ",rev);
//         }
//         printf("\n");
//     }
//     printf("====================\n");
// }
void ReverseAry(int ary3[][5], int size){
    int temp[99][5]={0};
    // ------------------------------------
    // 배열을 거꾸로 출력 -> temp에 순서대로
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            temp[i][j] = ary3[size-1-i][5-1-j];
            
        }
    }
    // ----------------------------------------
    // ary[i][j] = temp[i][j]
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            ary3[i][j] = temp[i][j];
        }

    }
}

// ===============================================================
int main(){
    srand(time(NULL));
    // -------------------------------------------------------
    int ary[2][3] = {{1,2,3},{4,5,6}};
    int (*ap)[3] = ary;
   {
    printf("%d\n", ary[1][1]);
    printf("%d\n",  ap[1][1]);

    printf("%d\n", ary[1][0]);
    printf("%d\n",  ap[1][0]);

    printf("%d\n", ary[0][1]);
    printf("%d\n",  ap[0][1]);
   }
    // ⭐ 이제부터 모든 배열은 n*5로 가정함
    int ary2[4][5] = {0};
    InitAry(ary2, 4);
    // -----------------------------------------------------------
    int ary3[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    PrintAry(ary3,2);
    AddOneAry(ary3,2);
    MinusOneAry(ary3,2);
    MaxMinAry(ary3,2);
    ReverseAry(ary3,2);

}// -=============================================================
/* ---------------------------------------------------------------
< 배열 포인터 >
⭐ 2차원 배열을 함수로 쉽게 넘기는 방법.
    단, 2차원 배열에서 몇 행이 있는지는 직접 넘겨야하며
    각, 행이 , 몇 개의 열로 이루어졌는지는 수동으로 써줘야 함.
< 만드는 방법 >
  자료형 (*이름)[열개수] = 2차원배열의 시작주소
  배열 포인터로, 원본의 2차원 배열 처럼 쓸 수 있음.
  단, 1차원 배열의 "열 개수" 꼭 써줘야 함.
-------------------------------------------------------------------*/ 
