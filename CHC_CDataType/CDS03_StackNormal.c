// CDS03_StackNormal.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 10
// =======================================================
// < 구 조 체 >
// =======================================================
typedef struct{
    int data[MAXSIZE];
    int top;
}Stack;
// =======================================================
// < 전 역 함 수 >
// =======================================================

// 🎫 스택을 초기화하는 함수. 리셋의 역할도 같이 진행 🎫
void InitStack(Stack* mainStack){
    mainStack->top = -1;
    for(int i=0; i<MAXSIZE; i++){
        mainStack->data[i] = 0;
    }
    printf("[SYSTEM] Initialize Complete\n");
}
// 🎨 출력 - 간단하게 🎨
void PrintStack(Stack mainStack){
    printf("---------------\n");
    for(int i=0; i<=mainStack.top; i++){
        printf("%d ", mainStack.data[i]);
    }
    printf("\n---------------\n");

}
// 만들어봅쉬다~~!~(여러분이)
// 🎁 삽입 🎁
void Push(Stack* mainStack, int data){
    // 꽉 차지만 않았다면
    if( mainStack->top >= MAXSIZE-1 ){
        printf("[ERROR] Overflow!\n");
        return;
    }
    // top을 증가 후 data를 그자리에 넣기
    mainStack->top++;
    mainStack->data[mainStack->top] = data;

}

// 🎀 추출 🎀
int Pop(Stack* mainStack){
    // 비어있지만 않는다면
    if(mainStack->top <= -1){
        printf("[ERROR] UnerFlow\n");
    }
    int index = mainStack->top;
    int result = mainStack->data[ index ];

    mainStack->data[ index ] = 0;
    mainStack->top--;
    return result;
}
// 🧧 검색 🧧
// 해당 값이 어디에 있는지 검색(배열 리스트 기준 )
// -->  1 2 3 4 5 6 7 8 9 --> 
void SearchStack(Stack stack, int target){
    // 0~k까지, 만약 있다? -> 인덱스 출력하고 끝.
    int k = stack.top;
    for(int i=0; i<=k; i++){
        if(stack.data[i] == target){
            printf("Target %d : %d\n", target, i );
            return;
        }
    }
    // k를 벗어날 경우. -> 없다 출력하고 끝.
    printf("Target Missing...\n");
}
// 🎃 스택 거꾸로 담기 🎃
// 10 20 30 40 50
// 50 40 30 20 10 
// 임시 배열 하나 만들어서, Pop한거 순서대로 넣기
// 이후 순서대로 배열에 다시 Push할 것.(K)
void ReverseStack(Stack* stack){
    int temp[MAXSIZE] = {0};
    int k = stack->top;
    for(int i=0; i<=k; i++){
        temp[i] = Pop(stack);
    }
    for(int i=0; i<=k; i++){
        Push(stack, temp[i]);
    }
    PrintStack(*stack);
}
// =======================================================
int main(){
    Stack stack;
    InitStack(&stack);
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    Push(&stack, 40);
    Push(&stack, 50);
    PrintStack(stack);

    ReverseStack(&stack);

    SearchStack(stack, 40);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    PrintStack(stack);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    PrintStack(stack);

}// ======================================================
/*
< 종합 실습 >
스택을 이용해서 시스템을 구현하세요. 구현해야 하는
기능들의 프로세스는 아래와 같습니다.
1. 프로그램 실행 후 UI 출력
     > 스택 출력, 스택 삽입, 스택 추출, 스택 검색, 스택 뒤집기, 스택 초기화
2. 사용자가 선택한 기능에 대해, 필요하다면 입력을 받아 처리
3. 처리 후 약간의 대기 시간 필요(너무 빠르면 안됩니다)
4. 이러한 것들을 무한반복으로 처리하세요
5. 이러한 작업을 CDS02_StackNormalSystem.c에 저장.
 > 다 했으면 퇴근하세요. 복사 붙여넣기 가능. <
*/