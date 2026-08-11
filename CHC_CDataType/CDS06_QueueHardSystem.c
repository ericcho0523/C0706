// CDS06_QueueHardSystem.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;   // 맨 앞, 출력할 놈 -> Dequeue
    Node* rear;    // 맨 뒤, 데이터 여기까지 -> Enqueue
    // 큐가 비어있다? -> rear가 NULL -> front도 NULL
}Queue;

// ===============================================================
// < 전 역 함 수 >
// ===============================================================

// 💀큐를 초기화 💀
void InitQueue(Queue* mainQ){
    // 추후, 이 함수를 리셋처럼 쓰기 위해
    // 큐 모든 내용 삭제도 안에 나중에 탑재 
    mainQ->front = NULL;
    mainQ->rear  = NULL;
}
// 🥵데이터 넣기🥵
void Enqueue(Queue* mainQ, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    // 비어있는 경우 : front, rear 모두 NULL
    if(mainQ->front==NULL && mainQ->rear==NULL){
        // 아예 비어있었으면, f,r 모두 세팅
        mainQ->front = temp;
        mainQ->rear  = temp;
    }else{
        mainQ->rear->next = temp;
        mainQ->rear = temp;
    }
}
// ✌️비어있으면 1 아니면 0✌️
int isEmpty(Queue* mainQ){
    if(mainQ->front==NULL && mainQ->rear==NULL){
        return 1;
    }else{
        return 0;
    }

}
void PrintEmpty(){
    printf("[SYSTEM] Queue Empty\n");
}
// 😍큐에 데이터 빼기 😍
void Dequeue(Queue* mainQ){
    // 비어있으면 Empty를 출력.
    if( isEmpty(mainQ) == 1){
        PrintEmpty();
        return;
    }
    Node* temp = mainQ->front;
    // 1. 데이터 백업하기
    // 2. front를 next로 옮기기
    // 3. temp를 이용해서 free 하기
    // 4. front가 NULL이되었다? -> 아무것도X
    //    rear도 NULL로 만들기
    // 5. 백업한 데이터를 출력하기 
    int result = temp->data;
    mainQ->front = temp->next;
    free(temp);
    if(mainQ->front==NULL){
        mainQ->rear=NULL;
    }
    printf("result : %d\n", result);
}

// 😊 큐를 초기화 😊
// 구현 후, InitQueue에 탑재
void ResetQueue(Queue* mainQ){
    // front, rear 모두 NULL 이면 끝
    // 아니면 계속 Dequeue 할 것.
    for(;1;){
        if( isEmpty(mainQ) == 1){
            return;
        }
        else{
            Dequeue(mainQ);
        }
    }
}
// ⭐ Front & Rear 값 확인 ⭐
void PrintFrontRear(Queue* mainQ){
    // front와 rear의 값을 mainQ를 이용해서
    // 각각 출력
    if( isEmpty(mainQ) == 1){
        PrintEmpty();
        return;
    }
    printf("Front is %d\n", mainQ->front->data);
    printf("Rear  is %d\n", mainQ->rear ->data);
}
// ❤️ 전체 큐 리스트 출력 ❤️
void PrintQueue(Queue* mainQ){
    // front부터 시작해서 NULL될 때까지
    // 계속 이동하면서 모든 값들을 출력하기 
    for(;1;){
        if( isEmpty(mainQ) == 1){
            PrintEmpty();
            return;
        }
        Node* move = mainQ->front;
        printf("Start -> ");
        for(;1;){
            if(move==NULL){
                printf("End\n");
                return;
            }else{
                printf("%d -> ", move->data);
                move = move->next;
            }
        }
    }
}
void PrintUI(){
    printf("===============\n");
    printf(" 1. Reset\n");
    printf(" 2. Enqueue\n");
    printf(" 3. PrintQueue\n");
    printf(" 4. PrintFrontRear\n");
    printf(" 5. Dequeue\n");
    printf("===============\n");
    printf("Input Menu : ");
}

void Start(){
    Queue q;
    InitQueue(&q);
    for(;1;){
    system("cls");
    PrintUI();
    int choice;
    scanf("%d", &choice);
    if(choice==1){
        ResetQueue(&q);
    }
    else if(choice == 2){
        printf("Input Number : ");
        int data;
        scanf("%d", &data);
        Enqueue (&q,data);
    }
    else if(choice == 3){
        PrintQueue(&q);
    }
    else if(choice == 4){
        PrintFrontRear(&q);
    }
    else if(choice == 5){
        Dequeue(&q);
    }else{
        printf("Wrong Input. Restart\n");
    }
    Sleep(2000);
    }
}
// ===============================================================
int main(){
    Start();
}