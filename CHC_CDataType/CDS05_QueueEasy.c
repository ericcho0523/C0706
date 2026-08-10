// CDS05_QueueEasy.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 5
#define FAIL -7777;
// =======================================================
// < 전 역 함 수 >
// =======================================================

// 😈 큐를 초기화 하는 함수 😈
void InitQueue(int q[], int* front, int* rear){
    for(int i=0; i<MAXSIZE; i++){
        q[i] = FAIL;
    }
    *front =  0;
    *rear  = -1;
}

// 🤢 큐에 데이터를 넣어주는 함수 🤢
void Enqueue(int q[], int* front, int* rear, int data){
    // 1. 가득 찼니?? -> 넣는건 rear담당, 빼는건 front담당
    if(*rear == MAXSIZE-1){
        printf("[FAIL] Queue Overflow\n");
        return;
    }
    // 2. 가득 차지 않았으니, rear 하나 증가 후 데이터 넣기
    // 2.1 이지 버전
    *rear += 1;
    q[*rear] = data;
    // 2.2 하드 버전
    // q[++(*rear)] = data;
}

//🧐 큐의 모든 데이터를 출력하기 🧐
//  데이터가 어디에 있을까? -> front~rear
//  비어있으면 X 0 -1, 0 0, 0 1, 0 2, 1 2
void PrintQueue(int q[], int front, int rear){
    // 비어있는지 확인, front > rear 빈 거임! -> Empty 출력
    // 아니면, front ~ rear까지 q의 인덱스로 값 모두 출력
    if(front>rear){
        printf("[FAIL] Queue Empty!\n");
        return;
    }
    // for(int i=front;i<=rear;i++){
    //         printf("%d ",q[i]);
    //     }이것도 가능한가요?
    // i<=rear-front 이 방법도 있음
    for(; front<=rear; ){
        printf("%d ",q[front]);
        front++; // 어차피 원본이랑 연결 안 되어있음
    }   printf("\n");
}

// 🥳 큐에서 한놈 빼기. front 증가필요🥳
int Dequeue(int q[], int* front, int* rear){
    // 비어있으면 안됨
    // 비어있지 않다면 front를의 값을 백업 후
    // 한칸 증가 시킨 후 리턴.
    if(*front>*rear){
        printf("[FAIL] Queue Underflow\n");
        return FAIL;
    }
    
    int result = q[*front];
    *front += 1;
    return result;
    // 한줄 버전
    return q[(*front)++];
}



// 🤧🤧😠😠😨😨

// =======================================================
int main(){
    int queue[MAXSIZE] = {0};
    int front, rear;
    // -------------------------
    InitQueue(queue, &front, &rear);
    Enqueue(queue, &front, &rear, 10);
    Enqueue(queue, &front, &rear, 20);
    Enqueue(queue, &front, &rear, 30);
    Enqueue(queue, &front, &rear, 40);
    Enqueue(queue, &front, &rear, 50);
    PrintQueue(queue, front, rear);
    Dequeue(queue, &front, &rear);
    PrintQueue(queue, front, rear);
    Enqueue(queue, &front, &rear, 60);
    PrintQueue(queue, front, rear);
}// ======================================================
/*
해당 내용에 알맞은 시스템을 작성하세요
1. 매번마다 큐를 보여준다.
2. 사용자에게 메뉴를 보여주고 물어본다
3. 질문에 맞는 작업 진행
   -> 삽입, 삭제, 리셋


*/