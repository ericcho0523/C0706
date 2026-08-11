/*문자열 작업 큐 제작 - 시스템
- 넣어야하는 작업의 개수는 정해지지 않음. - 배열 사용 X
- 넣어야 하는 데이터는 int가 아닌, 최대 100글자의 문자열
   Node의 int data가 아닌 다른걸 넣어야 한다.
- 필수 구현 기능은 아래와 같음
    1. 작업 추가하기 - 무슨작업 넣을지 키보드로 입력
                 최근에 추가한 작업은 가장 마지막에 완료
    2. 작업 완료하기 - 가장 과거에 넣었던 작업을 출력 후 삭제
    3. 작업 목록 확인하기 - 해야하는 순서대로 넘버링 해서(1,2,3)
                        한 줄당 한개의 작업목록이 나오게
    4. 엎어버리기 - 모든 작업목록을 삭제 후 "아 몰라 안해" 출력.
- 메모리 누수 조심하기!!
- 그 외 더 넣고 싶은 기능 있으면 넣기. 가능할지 궁금하면 연락주세요.
*/
// CDS06_QueueChar.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct Task{
    char task[100];
    struct Task* next;
}Task;
typedef struct TaskQueue{
    Task* front;   
    Task* rear;   
}TaskQueue;

// ===============================================================
// < 전 역 함 수 >
// ===============================================================
void InitQueueTask(TaskQueue* mainQ){
    mainQ->front = NULL;
    mainQ->rear  = NULL;
}
void EnqueueTask(TaskQueue* mainQ){
    Task* temp = (Task*)malloc(sizeof(Task));
    printf("Add a Task\n");
    scanf("%s",temp->task);
    temp->next = NULL;
    
    if(mainQ->front==NULL && mainQ->rear==NULL){
        mainQ->front = temp;
        mainQ->rear  = temp;
    }else{
        mainQ->rear->next = temp;
        mainQ->rear = temp;
    }
}
void DequeueTask(TaskQueue* mainQ){
    char result[100];
    if(mainQ->front==NULL && mainQ->rear==NULL){
        printf("[SYSTEM] Queue Empty\n");
        return;
    }
    Task* temp = mainQ->front;
    strcpy(result, temp->task);
    mainQ->front = mainQ->front->next;
    free(temp);
    if(mainQ->front==NULL){
        mainQ->rear=NULL;
    }
    printf("result : %s\n", result);
}
void PrintQueueTask(TaskQueue* mainQ){
    for(;1;){
        if(mainQ->front==NULL && mainQ->rear==NULL){
        printf("[SYSTEM] Queue Empty\n");
        return;
        }

        Task* move = mainQ->front;
        int cnt=0;

        for(;1;){
            if(move==NULL){
            printf("End\n");
            return;
            }
            printf("%d.%s\n",++cnt,move->task);
            move=move->next;
        }
    
    }
}
void ResetQueueTask(TaskQueue* mainQ){
    for(;1;){
        if(mainQ->front==NULL && mainQ->rear==NULL){
        printf("[SYSTEM] Queue Empty\n");
        return;
        }
        else{
            DequeueTask(mainQ);
        }
    }
}
void PrintUI(){
    printf("===============\n");
    printf(" 1. Reset\n");
    printf(" 2. Enqueue\n");
    printf(" 3. PrintQueue\n");
    printf(" 4. Complete Task\n");
    printf("===============\n");
    printf("Input Menu : ");
}
void Start(){
    TaskQueue t;
    InitQueueTask(&t);
    for(;1;){
        system("cls");
        PrintUI();
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            ResetQueueTask(&t);
        }
        else if(choice==2){
            EnqueueTask(&t);
        }
        else if(choice==3){
            PrintQueueTask(&t);
        }
        else if(choice==4){
            DequeueTask(&t);
        }
        else{
            printf("Wrong Input. Restart\n");
        }
        Sleep(1000);
    }
}

// ===============================================================
int main(){
    Start();
} // ===============================================================

