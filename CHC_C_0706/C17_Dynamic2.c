// C17_Dynamic2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구조체 자리 >
// ===============================================================

// ===============================================================
// < 함수 자리 >
// ===============================================================
// 숫자 넘겨주면, 배열 만들어주는 MakeAry 함수를 제작
// 이후, 해당 숫자만큼 배열에 랜덤값 1~9 넣어주기
int* MakeAry(int size){
    int* temp = (int*)malloc(size * sizeof(int));
    for(int i=0;i<size;i++){
        temp[i] = rand()%9+1;
    }
    return temp;
}

// 배열과 숫자 넘겨받아 모든 배열요소를 출력하는 PrintAry 함수 제작
void PrintAry(int ary[], int size){
    printf("----------------\n");
    for(int i=0;i<size;i++){
        printf("%d", ary[i]);
    }   printf("\n");
    printf("----------------\n");
}

// GetRandAry10은, size가 10인 int형 배열의 랜덤값이
// 10칸에 모두 1~9가 들어가있는 배열을 리턴하는 함수
int* GetRandAry10(){
    int* temp = (int*)malloc(10 * sizeof(int));
    for(int i=0;i<10;i++){
        temp[i] = rand()%9+1;
    }
    return temp;
}
// InitAry는 넘겨받은 포인터 변수와 사이즈를 이용해
// 새로운 배열을 만들어 메인의 원본에 넣어주는 함수
void InitAry(int** dptr, int size){
    // 누군가의 데이터 공간을 제어하고싶으면
    // 그녀석의 집주소가 필요함.
    int* temp = (int*)malloc(size* sizeof(int));
    for(int i=0;i<size;i++){
        temp[i] = rand()%9+1;
    }
    // 이제 메인에 있는 왼본자리에 새로 만든 배열의
    // 주소를 때려 넣어야 함.
    *dptr = temp;

}
// 메인의 포변의 주소와 사이즈를 받아서, 해당 원본에
// size만큼의 배열을 만들어 1부터 숫자를 채워주는
// InitAry2 함수를 만드세요.
// 이중포인터변수는, 포인터변수의 집주소 저장가능
// 포인터변수는, 일반 변수의 집주소를 저장가능.
void InitAry2(int** ary, int size){
    int* temp = (int*)malloc(size* sizeof(int));
    for(int i=0;i<size;i++){
        temp[i] = i+1;
    }
    *ary = temp;
    PrintAry(*ary,size);
}

// SetAry는 넘겨받은 포인터 변수와 사이즈를 이용해
// 새로운 배열을 만들어 메인의 원본에 넣어주는 함수
// 단, 이미 해당 배열에 이미 다른 배열이 있다면
// 없애버린 후 새로 할당하도록 하세요.
void SetAry(int** dptr, int size){
    
    // 만약, 아무것도 없었다면, NULL이 있을거임
    if(*dptr == NULL){
        
        // 배열을 만들어서 
    }
    else{
        // 이미 누수가 있는 상황
        // 그냥 넣어버리면 누수 생김 -> 소멸시킴 

       free( (*dptr));
       (*dptr) = NULL;
    }
    // 만약 비어있으면? 바로 대입
    // 비어있지 않다면?
    // 해당 주소를 free에 넣고
    // 새로 대입
    int* temp = (int*)malloc(size* sizeof(int));
    for(int i=0;i<size;i++){
        temp[i] = i+1;
    }

    *dptr = temp;
}
// ------------------------------------------------------
// 1. 함수에서 내꺼 데이터 

// 랠럭 
// ===============================================================
int main(){
    srand(time(NULL));
    // --------------------------------------------------------
    // 외부에서 배열 만들어 넘겨주기 
    int size = 10;
    int* ary = MakeAry(size);
    PrintAry(ary,size);
    GetRandAry10();
    int* ary2;
    InitAry(&ary2,10);
    PrintAry(ary2,10);

    InitAry2(&ary2,20);
    // --------------------------------

    int array[5] = {1,2,3,4,5};
    printf("%d %d %d\n", array[0],array[1],array[2]);
    int* temp = array;
    printf("%d %d %d\n", temp[0],temp[1],temp[2]);
    int* temp2 = temp;
    printf("%d %d %d\n", temp2[0],temp2[1],temp2[2] );
    // --------------------------------------------------
    // 동적 할당 배열 -> 언제든지 크기 자유조절 가변길이배열
    size = 15;
    int* dy = (int*)malloc(size*sizeof(int)); // int(4) * 10 = ary[10]
    for(int i=0;i<size;i++){
        dy[i] = i+1;
        printf("%d", dy[i]);
    }


}// -=============================================================
/* ---------------------------------------------------------------
1. 함수에서 내꺼 데이터공간 사용할 수 있게(대입,변경)
   -> 내꺼 주소 보내야 함.
2. 함수에서 내꺼 데이터공간 값만 사용할거다 (대입X)
   -> 내꺼 그냥 보내면 값 복사되서 전달됨
3. 포인터 왜 써요?
   -> 외부에서 니꺼 데이터 공간 변경할 수 있게 하려고.
4. 변수의 주소는 "포인터 변수"가 저장할 수 있음
   배열의 첫 주소만 가지고 있으면, 누구나 사용 가능
   포인터 변수의 주소는 " 이중 포인터 변수"가 저장가능
   이중 포인터 변수의 주소는 " 삼중 포인터 변수" 가 저장가능   
5. 배열을 사용하고 싶으면, 걔네 첫 집 주소가 필요
  왜 포인터변수가, 배열처럼 쓸 수 있을지???
  배열은 첫 주소에서 점프방식 ( a[0] = a + 0, a[1] = a + 1)      
-------------------------------------------------------------------*/