// C13_Pointer5.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 함수 자리 >
// ===============================================================
void InitAry(int* ptr, int size){
    for(int i=0;i<size;i++){
        *(ptr+i) = i+1;
    }

}
void PrintAry(int* ptr, int size){
    printf("------------------\n");
    for(int i=0;i<size;i++){
        printf("%d ",*(ptr+i) ); // ptr[i]
    }   printf("\n");
    printf("------------------\n");
}
// InitAryRandom은, 배열과 사이즈를 넘겨받아, 0부터 모든
// 요소에 1~9 랜덤 숫자를 넣어주는 함수입니다.
void InitAryRandom(int* ptr, int size){
    for(int i=0;i<size;i++){
        *(ptr+i) = rand()%9 + 1; 
    }
}

// InitArySE는 배열과 시작, 끝 인덱스를 넘겨받아, 해당
// 인덱스들에 차례대로 1부터 숫자를 넣어주는 함수입니다.
void InitArySE(int* ptr, int start, int end , int size){
    if(end>=size){
        printf("Over Index\n");
        return;
    }
    for(int i=start; i<=end;i++){
        *(ptr+i) = i-start +1;
    }
}
// InitTotalAry의 함수는, 배열과 사이즈를 넘겨받아
// 1부터 순서대로 데이터를 초기화 한 후, 값을 출력하고
// 다시 1~9까지의 랜덤 숫자들을 넣은 후 출력한 이후
// 모든 값을 0으로 만들어버리는 함수입니다.
// int ary3[30]을 메인에 만든 후 실습해주세요.
void InitTotalAry(int* ptr, int size){
     InitAry(ptr,size);
     PrintAry(ptr,size);
     InitAryRandom(ptr,size);
     PrintAry(ptr,size);
     for(int i=0;i<size;i++){
        *(ptr+i) = 0;
    }

}
// -----------------------------------------------
// GetSumAry 함수는, 배열과 시이즈를 넘겨받아, 배열 내 모든
// 요소의 값의 합을 돌려주는 함수입니다.
int GetSumAry(int* ptr,int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += *(ptr+i);
    }
    return sum;
}

// GetAvgAry 함수는, 배열과 시이즈를 넘겨받아, 배열 내 모든
// 요소의 값의 평균을 돌려주는 함수입니다.
double GetAvgAry(int* ptr,int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += *(ptr+i);
    }
    return (double)sum/size;
}



// GetEvenCount, GetOddCount, SetEvenZero, SetOddZero
// 배열과 사이즈 받아 짝수 개수 리턴
// 배열과 사이즈 받아 홀수 개수 리턴
// 배열과 사이즈 받아 짝수를 0으로 만든 후 출력
// 배열과 사이즈 받아 홀수를 0으로 만든 후 출력
int GetEvenCount(int* ptr, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(*(ptr+i)%2==0){
            count++;
        }
    }
    return count;
}
int GetOddCount(int* ptr, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(*(ptr+i)%2!=0){
            count++;
        }
    }
    return count;
}
int SetEvenZero(int* ptr, int size){
    for(int i=0;i<size;i++){
        if(*(ptr+i)%2==0){
            *(ptr+i) = 0;
        }
        printf("%d ",*(ptr+i));
    }
    
}
int SetOddZero(int* ptr, int size){
    for(int i=0;i<size;i++){
        if(*(ptr+i)%2!=0){
            *(ptr+i) = 0;
        }
        printf("%d ",*(ptr+i));
    }
}
// ===============================================================
int main(){
    srand(time(NULL));
    // -----------------------------------------------------------
    int ary[20] = {0};
    InitAry(ary,20);
    PrintAry(ary,20);

    int ary2[40] = {0};
    InitAry(ary2, 20); // 일부
    PrintAry(ary2,40); 

    InitAryRandom(ary2, 40);
    PrintAry(ary2, 40);
    InitArySE(ary2, 10, 20, 40);
    PrintAry(ary2, 40);

    int ary3[30] = {0};
    InitTotalAry(ary3, 30);
    PrintAry(ary3, 30);
    // ===============================================
    printf("============================\n");

    int ary4[30] = {0};






}// -=============================================================