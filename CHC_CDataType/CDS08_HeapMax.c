// CDS08_HeapMax.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 5
#define EMPTY INT_MAX
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct HeapMax{
    int heap[MAXSIZE]; // 안전장치 필요함
    int size;
}HeapMax;
// ===============================================================
// < 전 역 함 수 >
// ===============================================================
void EmptyMessage(){
    printf("[SYSTEM] HeapMax Is Empty\n");
}

// 🥭 힙을 초기화 시킴 🥭
void InitHeapMax(HeapMax* h){
    for(int i=0;i<MAXSIZE;i++){
        h->heap[i] = EMPTY;
    }
    h->size = 0; // 길이
}

// 🍎 데이터 교환 함수 🍎
void Swap(int* x, int* y){
    int temp = *x  ;
          *x = *y  ;
          *y = temp;
}

// 포인터를 이용해 전달하는 것 vs 그냥 전달하는 것
// 성능은, 포인터를 이용하는 것이 압도적으로 효율적.
// 그냥 전달하면, 모든 내용 복사 붙여넣기 하는과정에서
// 순간 메모리를 2배를 잡아먹음 -? 메모리가 부족하면 장애터짐

// 🫐 힙의 모든 요소를 출력하는 함수 1 - 일반배열 🫐
void PrintHeapMax(HeapMax* h){
    printf("< Print HeapMax Array >\n");
    printf("-----------------------\n >");
    for(int i=0;i < (h->size);i++){
        printf("%d ", h->heap[i]);
    }
    printf("\n-----------------------\n");
}
// 🥝 힙의 모든 요소를 출력하는 함수 2 - 트리구조 🥝
// 1 2 3 4 5 6 7
// 1 > 1
// 2 > 2 3
// 3 > 4 5 6 7
// 출력개수 : 1 E 2 E 4 E 8 E 16 32 64 128 ...
void PrintHeapMaxTree(HeapMax* h){
    printf("< Print HeapMax Tree >\n");
    printf("-----------------------\n");

    int limit = 1; // 한계점. 2씩 곱하면 됨.
    int cnt = 0; // 현재 넣은 개수가 한계점까지 가면 엔터
    int level = 1; // 한계가 갱신될 때마다 1씩 증가
    // 아이디어
    // cnt가 0이면, 최초 level 출력, 숫자 출력 후 cnt 증가
    // limit와 cnt가 같아지면, cnt 0, limit*2, level+1

    for(int i=0;i < (h->size);i++){
        if(cnt==0) printf(" %d > ", level);

        printf("%d ", h->heap[i]);
        cnt++;
        if(cnt==limit){
            printf("\n");
            cnt = 0;
            limit*=2;
            level++;
        }
    }
    printf("\n-----------------------\n");
}



// 🍅 힙에 데이터를 넣는 Heapify Up🍅
void InsertHeapMax(HeapMax* h, int data){
    // 안전장치. 최대 크기를 벗어나면 막아야 함.
    if(h->size >= MAXSIZE){
        EmptyMessage();
        return;
    }
    // 일단 맨 끝에 데이터 넣기
    int insertLoc = h->size;
    h->size++; // h->size += 1;
    h->heap[insertLoc] = data;

    // insertLoc와 계산된 부모를 이용해서, 필요시 Swap
    for(;1;){
        // 종료시점 결정
        if(insertLoc == 0) break;

        int parentIndex = (insertLoc-1)/2;
        if( h->heap[insertLoc] > h->heap[parentIndex]){
            // 교환 -> Swap함수 사용
            Swap( &(h->heap[insertLoc]), &(h->heap[parentIndex]) );
            // insertLoc를 부모인덱스로 변경
            insertLoc = parentIndex;
        }else{
            break;
        }
    }
}

// 🫒 힙에서 최대값을 추출하는(제거) Heapify Down - 리턴+출력 🫒
//    제거하는 이유 = 다음 최대값을 위해서  
int ExtractHeapMax(HeapMax* h){
    // 1. 사이즈가 비어있는지?
    if(h->size == 0){
        printf("[SYSTEM] HeapMax Is Empty\n");
        return;
    }
    // 2. 뭐라도 있는것. 최대값 백업
    int result = h->heap[0];
    // 3. 맨 앞에 맨 끝의 데이터 삽입
    h->heap[0] = h->heap[h->size-1];
    // 4. size도 감소시키고, EMPTY 넣기
    h->heap[ h->size-1 ] = EMPTY;
    h->size--;
    // 5. 힙을 유지하기 위해, 왼오 자식들보다 내가 젤큰지 
    // 내가 크면 끝. 아니면 둘중 더 큰놈으로 변경해야 함
    int current = 0; // 현재 위치
    for(;1;){
    // 왼오 자식놈들 인덱스를 내꺼(current)기준 계산
    int left =  (current*2) + 1;
    int right = (current*2) + 2;
    int large = current;

    // 나,왼,오 중 젤 큰놈 인덱스 찾기
    // + size를 벗어나면 안됨
    if(h->heap[left] > h->heap[current]){
        if(left<(h->size)){
            large = left;
        }
    }
    if(h->heap[right] > h->heap[current]){
        if(right<(h->size)){
            large = right;
        }
    }
    // 셋중 최대값에 해당하는 인덱스 large 구했음!! > 교환
    // 굳이, 나랑 나는 비교...X
    if(current == large) break; // 끝.
    Swap( &(h->heap[current]), &(h->heap[large]) );

    current = large;
   }
   // 6. 값도 변경했고, 인덱스도 잘 처리했음. 출력 + 리턴
   printf(" > Max : %d\n", result);
   return result;
}

//  💀 최대값 확인 💀
void CheckHeapMax(HeapMax* h){
    if(h->size != 0){
        printf("Current Max : %d\n", h->heap[0]);
    }else{
        EmptyMessage();
    }
}




// ===============================================================
int main(){
    HeapMax heapMax;
    InitHeapMax(&heapMax);
    // 잠깐 확인할 목적. 끝나고 지울 것.
    // heapMax.heap[0] = 10;
    // heapMax.heap[1] = 20;
    // heapMax.heap[2] = 30;
    // heapMax.size    =  3;
    // PrintHeapMax(&heapMax);

    // 데이터 임시로 넣어보고 확인하기
    int testAry[] = {3,1,4,5,2,34,24,234,23424,8};
    for(int i=0;i<sizeof(testAry)/4;i++){
        InsertHeapMax(&heapMax, testAry[i]);
    }
    PrintHeapMaxTree(&heapMax);
    
} // ===============================================================
/*
현재는 Int를 이용해서 힙을 만들었으나, 좀 더 응용을 해본다면
다른 구조체의 안쪽에 있는 특정 값을 이용해서, 구조체들을
중요도를 기준으로 힙에 넣을 수 있음.
typedef struct Task{
    char taskName[100];
    int important; // 중요도
}Task;
--------------------------------------------------------------------
현재 힙의 크기가 고정인데, 가변길이로도 만들 수 있음.
단, 크기를 늘리거나 줄일때는 어떠한 규칙이 필요함(맘대로 적용)
> 힙에 넣어야 하는데 모자랄 경우 -> 더 들어온단 가정하에 사이즈*2
> 힙의 크기가 현재 크기의 절반 - x만큼 작아질 경우, 절반으로 조절
    x = 현재 사이즈/2 - ?

< 7번째 숙제 >
위에 만든 것을 시스템으로 만들되, 최소 힙으로 만드세요 
아래 기능은 필수로 구현
  1. 힙 확인 ( 트리구조로. 공백 넣어서 이쁘게 할 필요없음)
  2. 힙 데이터 추가
  3. 힙 최대값 확인
  4. 힙 최소값 추출 
  5. 힙 초기화
  6. 종료
⭐ 단, 구조체를 이용해 만들어야 하며, 강의자료만 보고 구현해야 함
*/
