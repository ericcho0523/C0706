// CDS01_List.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구조체 >
// ===============================================================
typedef struct Node{ // 나 자신의 자료형 사용하기에...
    int data;
    struct Node* next; // 또다른 내 자료형의 주소 저장
}Node;
// ===============================================================
// < 전 역 함 수 >
// ===============================================================

// 🎈 새로운 노드를 만드는 함수 🎈
Node* CreateNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    // 안전장치 생략 
    temp->data = data;
    temp->next = NULL;
}

// 🎈 모든 요소를 출력하기 + 원본 변경 안함 🎈
void PrintNode(Node* start){
    Node* temp = start;
    printf("Start->");
    for(; temp != NULL ;){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("End\n");
    // Start->100->200->300->End
}

// 😊 새로운 노드를 맨 앞에 삽입하는 함수 😊
void InsertNodeFront(Node** mainHead, int data){
    Node* temp = CreateNode(data);
    temp->next = *mainHead;
    *mainHead = temp;


}

// 😒 새로운 노드를 맨 "뒤"에 삽입하는 함수 😒
void InsertNodeBack(Node** mainHead, int data){
    Node* temp = CreateNode(data);
    if(*mainHead == NULL){
        // 진짜 아무것도 없는 상황. 넣으면 끄읏
        // 1. InsertNodeFront 호출
        // InsertNodeBack(mainHead,data);
        // 2. 맨 앞에 새 노드 삽입(노드필요)
        *mainHead = temp;
        return; // 종료.

    }
    // 만약, main의 head가 비어있지 않은 경우
    // 진짜 맨 뒤를 찾아야 함.(Next가 NULL 인 놈)
    Node* move = *mainHead;
    for(; move->next != NULL;){
        move = move->next;
    }
    // 마지막위치에 move가 대기하고 있음
    move->next = temp;
}

// 🥵 노드의 중간에 때려넣는 함수 🥵
void InsertNodeMid(Node** mainHead, int data, int position){
    // 1. position이 0이면 => 맨 앞
    if(position==0 || *mainHead == NULL){
        InsertNodeFront(mainHead, data);
        return;
        // 책임연쇄 
    }
    // ------------ 여기서 부터 position이 0은 아님 ------------
    // ------------ main의 head안에 NULL도 아님 ---------------
    // 움 직 여 !
    // 2. position이 0이 아니면 => 범위탈출
    // 3. position이 0이 아니면 => 중간
    Node* move = *mainHead;
    for(int i=0; i<position-1;i++){
        if(move->next==NULL){
            // 4. 범위를 탈출할 것 같다면, 끝에 삽입
            // InsertNodeBack(mainHead, data);
            // 실행시, 다시 똑같이 검색 수행 -> 손해
            // --------------------------------
            // < 여기서 끝내야 함 >
            break;

        }

        move=move->next;
        // move안에 NULL있는데, 이동하면??
        // 프로그램이 멈추는 에러 발생.

    }
    
    // 5. 중간에 멈췄다면, 그대로 삽입
    Node* temp = CreateNode(data);
    temp->next = move->next;
    move->next = temp;
}

// -------------------------------------------------------------
// 2026-08-05
// 해야하는거 : 삭제, 탐색, 새 파일에 시스템으로 만들기

// 🍕 특정 노드를 삭제하는 함수 🍕
// 1. Main의 head가 비어있는 경우 -> 즉시 종료 
// 2. 삭제하고자 하는 놈이 중간에 있을 때 
//       100 101 102 103 104
//                2 - Index로 삭제
//               102 삭제! 
// 3. 삭제하려는 놈이 없는 경우 -> 응 없어 ~
// 4. 삭제하려는 놈이 맨 첫번째인 경우 -> main의 head 변경
void DeleteNodeKey(Node** mainHead, int target){
    // head가 비어있으면? 입뺀
    if(*mainHead == NULL){
        printf("Be Stronger.\n");
        return;
    }
    // 삭제해야하는 데이터가 첫 노드일 때
    if( (*mainHead)->data == target ){
        Node* temp = *mainHead; // 삭제할놈
        *mainHead = (*mainHead)->next ;
        free(temp);
        return;
    }
    // 검색 해야 함.
    Node* move = *mainHead;
    Node* pred = NULL;
    for(; move != NULL ;){
        if(move->data == target){
            // -------------
            // 데이터를 찾은 경우
            pred->next = move->next;
            free(move);
            printf("Deleted Normally\n");
            return;
        }
        // --------------
        // 데이터를 찾지 못한 경우 
        pred = move;
        move = move->next;
    }
    // 그냥 밖으로 나온 경우 -> 찾는거 없음
    // 삭제할거 없다고 출력하면 끝. 
    printf("No things to delete\n");
    return;
}

// 검색하기 실습
void FindNode(Node* mainHead, int target){
    // 200->100->100->200-?300->888
    //  0    1    2    3    4    5
    // 888은 5번째 인덱스에 있습니다. 
    int cnt=0;
    Node* move = mainHead;
    // for(;move != NULL)
    // move->next==NULL이면 break -> 가능.
    for(;1;){
        if(move==NULL){
            break;
        }
        if(move->data == target){
            // 찾았다!
            printf("Location of %d : %d\n", target, cnt);
            return;
        }else{
            cnt++;
            move = move->next;
        }
    }
    // 밖으로 나왔다??? 없는거임
    printf("No things found\n");


}
// < 숙제 >
// void DeleteNodeIndex(){
    
// }


// ===============================================================
int main(){
    // Node* head = NULL;
    // Node A = {100, NULL};
    // Node B = {200, NULL};
    // head = &A;
    // A.next = &B;
    // // -------------------------
    // // K로 100과 200을 출력하기 
    // printf("%d %d",head->data, head->next->data );

    // Node* head = NULL;
    // head = CreateNode(100);
    // printf("Head->%d\n",head->data);
    // head->next = CreateNode(200);
    // head->next->next = CreateNode(300);
    // head->next->next->next = CreateNode(400);
    // head->next->next->next->next = CreateNode(500);
    // head->next->next->next->next->next = CreateNode(600);
    // head->next->next->next->next->next->next = CreateNode(700);
    // head->next->next->next->next->next->next->next = CreateNode(800);
    // head->next->next->next->next->next->next->next->next = CreateNode(900);
    // 그 이후로도 400 500 600.. 900 까지   
    // 새로운 놈들을 계속 연결하세요.
    // 💀💀💀💀💀💀이건좀 아니잖아!!!!💀💀💀💀💀💀💀
    // 100부터 900 까지 모든 요소를 출력하세요
    // < 반복문 이용하기 > -> Next 자리가 NULL이면 출력하고 끝.
    // Node* move = head;
    // for(;1;){
    //     if(move->next == NULL){
    //         printf("%d\n", move->data);
    //         break;
    //     }else{
    //         printf("%d->", move->data);
    //         move = move->next;
    //     }
    // }
    
    // 🎈함수를 이용해서 head에 새로운 요소 붙이기  
    Node* head = NULL;
    for(int i=0;i<3;i++){
        InsertNodeFront(&head, (i+1)*100);
        InsertNodeBack(&head, (i+1)*100);
        PrintNode(head);
    }



    // 함수를 이용해서, 모든 요소 출력하기
    // PrintNode(head);

    // 중간에 실행하도록 합시다.
    printf("---------------------------------------\n\n");
    PrintNode(head);
    InsertNodeMid(&head, 999, 0);
    InsertNodeMid(&head, 888, 99);
    InsertNodeMid(&head, 777, 4);
    PrintNode(head);
    // ---------------------------------------------------
    // 삭제하기 실습
    // 777, 300, 999, 12345
    DeleteNodeKey(&head,777);
    PrintNode(head);
    DeleteNodeKey(&head,300);
    PrintNode(head);
    DeleteNodeKey(&head,999);
    PrintNode(head);
    DeleteNodeKey(&head,12345);
    PrintNode(head);
    // -----------------------------------------------
    // 검색하기 실습
    FindNode(head, 888);
    // 200->100->100->200-?300->888
    //  0    1    2    3    4    5
    // 888은 5번째 인덱스에 있습니다.   





} // ===============================================================
// 시스템 만들기.
// 연결하기, 연결 끊기, 확인하기
// 검색 함수, 삭제 함수 구현시, 건너뛰기 
// 재귀함수 진도 -> C1
