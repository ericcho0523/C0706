// CDS01_ListProject.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구조체 >
// ===============================================================
typedef struct Node{ 
    int data;
    struct Node* next; 
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

    return temp;
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
        
        *mainHead = temp;
        return; // 종료.

    }
    
    Node* move = *mainHead;
    for(; move->next != NULL;){
        move = move->next;
    }
    
    move->next = temp;
}

// 🥵 노드의 중간에 때려넣는 함수 🥵
void InsertNodeMid(Node** mainHead, int data, int position){
    // 
    if(position==0 || *mainHead == NULL){
        InsertNodeFront(mainHead, data);
        return;
         
    }
    
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
void PrintUI(){
    system("cls"); // window 전용
    printf("======================\n");
    printf(" 1. List Search\n");
    printf(" 2. Add Front\n");
    printf(" 3. Add Back\n");
    printf(" 4. Add Middle\n");
    printf(" 5. Delete Specific\n");
    printf(" 6. Search Specific\n");
    printf(" -1. Program End\n");
    printf("======================\n");
    printf("> Choose Menu : ");
}

// =============================================
int main(){
    Node* head = NULL;
    for(;1;){
        // 1. UI 출력 - 뭐 할래?
        PrintUI();
        // 2. 사용자의 입력에 따른 처리
        int choice;
        scanf("%d", &choice);
        // 4. 반드시 종료하는 기능이 있어야 함.(-1)
        if(choice==-1){
            printf("Program has ended\n");
            printf("3 "); Sleep(1000);
            printf("2 "); Sleep(1000);
            printf("1 "); Sleep(1000);
            printf("Bye\n");
            return 0;
        }
        // 3. 이상한 입력은 받지 않게 처리해야 함
        if(choice<1 || choice>6){
            printf("Unneccesary Input.\n");
            printf("Starts in 3 secs.\n");
            Sleep(3000);
        }
        // ------------------------------------------------
        // 정상 처리 진행
        // ------------------------------------------------
        // 1~6 기능 실행
        if(choice==1){
            PrintNode(head);
            Sleep(3000);
        }
        //  printf(" 2. Add Front\n");
        else if(choice==2){
            printf("< InsertNodeFront >\n");
            printf("Enter the number : ");
            int input;
            scanf("%d", &input);
            InsertNodeFront(&head,input);

            printf("Adding new data finised\n");
            Sleep(3000);
        }
        // printf(" 3. Add Back\n");
        else if(choice==3){
            printf("< InsertNodeBack >\n");
            printf("Enter the number : ");
            int input;
            scanf("%d", &input);
            InsertNodeBack(&head,input);

            printf("Adding new data finised\n");
            Sleep(3000);
        }
        // printf(" 4. Add Middle\n");
        else if(choice==4){
            printf("< InsertNodeMid >\n");
            PrintNode(head); // 이거보고 입력해!!!
            printf("Enter the number : ");
            int input;
            scanf("%d", &input);

            printf("Enter the position : ");
            int position;
            scanf("%d", &position);

            InsertNodeMid(&head,input,position);

            printf("Adding new data finised\n");
            Sleep(3000);

        }
        // printf(" 5. Delete Specific\n");
        else if(choice==5){
            printf("< DeleteNode >\n");
            PrintNode(head); // 이거보고 삭제해!!!

            printf("Enter the deleting number : ");
            int input;
            scanf("%d", &input);

            DeleteNodeKey(&head,input);

            PrintNode(head);
            printf("%d Data deleted.\n", input);
            Sleep(1000);

        }
        // printf(" 6. Search Specific\n");
        else if(choice==6){
            printf("< FindNode >\n");
            PrintNode(head); // 이거보고 삭제해!!!

            printf("Enter the finding number : ");
            int input;
            scanf("%d", &input);

            FindNode(head, input);

            Sleep(1000);
        }
    }


}
// =============================================
/*
시스템(System)
시작부터 종료까지 유기적으로 연결되는 구조를 제작
하나의 전체 프로그램을 만드는 개념
사용자의 입력에 따른 UI/UX도 고려해서 화면을 출력해야 함.
다양한 안전장치들도 구현해야 함.   

< 아쉬운 점 >
1. 다양한 안전장치를 만들지 못한 것.
2. 파일 입출력으로 프로그램 종료시 현 상태를
   저장하는 기능을 구현하지 못한 것.
3. 리스트를 뒤집는 기능이 없는 것
4. 맨 앞의 값을 추출해서 돌려주고, 맨 뒤의 값을
   추출해서 돌려주는 함수가 없다는 것.  
5. CMD의 한글 문제를 해결하지 못함...ㅠ 
*/


