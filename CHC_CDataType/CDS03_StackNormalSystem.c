// CDS03_StackNormalSystem.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int top;
}Stack;

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

void PrintUI(){
    printf("===============\n");
    printf(" 1. Print\n");
    printf(" 2. Push\n");
    printf(" 3. Pop\n");
    printf(" 4. Search\n");
    printf(" 5. Reverse\n");
    printf(" 6. Reset\n");
    printf("===============\n");
    printf("Input Menu : ");
}
void Start(){
    Stack stack;
    for(;1;){
        system("cls");
        PrintUI();
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            PrintStack(stack);
        }
        else if(choice == 2){
            printf("Input Number : ");
            int data;
            scanf("%d", &data);
            Push (&stack,data);
            printf("Success Push\n");
        }
        else if(choice == 3){
            int t = Pop(&stack);
            if(t!=-99999){
                printf("Pop : %d\n", t);
            }
        }
        else if(choice == 4){
            printf("Input Number : ");
            int target;
            scanf("%d", &target);
            SearchStack(stack,target);
            printf("Success Search\n");
        }
        else if(choice == 5){
            ReverseStack(&stack);
        }
        else if(choice == 6){
            stack.top = -1;
        }else{
            printf("Wrong Input. Restart\n");
        }
        Sleep(2000);
    }
}
int main(){
    Start();
}