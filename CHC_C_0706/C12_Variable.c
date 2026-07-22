// C12_Variable.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 함수 자리 >
// ===============================================================
void Change( int qwer, int asdf){
    qwer = 9999; // 데이터 값만 복사해서 가져옴.
    asdf = -9999; // 원본과 연결 안 되어 있음.
    // ------------------------
    // 교환 전 출력
    printf("[Change Before] %d %d\n",qwer,asdf);
    // <교환>
    int temp = qwer;
    qwer = asdf;
    asdf = temp;
    // 교환 후 출력
     printf("[Change After] %d %d\n",qwer,asdf);
}
int Calc(int x, int y){
    int result1 = x+y;
    int result2 = x-y;
    int result3 = x*y;
    int result4 = x/y;
    int result5 = x%y;
    return result1, result2, result3, 
           result4, result5;
           // 콤마 연산자?
           // 다 실행하되, 마지막꺼만 남음!
}
void WebVisit(){
    static int cnt = 0;
    cnt++;
    printf("Welcome abroad(%dvisit)\n",cnt);
    printf("Bye Bye\n");
    Sleep(300); // 0.3초
}
void Pushup(){
    static int cnt = 0;
    cnt++;
    if(cnt>=100){
        printf("Finised\n");
    }
    printf("Your push up count is %d\n",cnt);
    Sleep(200); // 0.2초
}

// ===============================================================
int main(){
    srand(time(NULL));
    int a=10, b=20;
    Change(a,b);
    printf("%d %d\n", a,b);
    
    int q,w,e,r,t = Calc(a,b); // 될 것 같니?
    printf("%d %d %d %d %d\n",q,w,e,r,t);
    // 어림도 없지.
    // ------------------------------------------------------------------
    // < 정적변수 실습 >
    // 웹사이트 방문 횟수 측정
    for(int i=0;i<10;i++){
        WebVisit();
    }
    // 푸쉬업 개수 카운트
    for(int i=0;i<110;i++){
        Pushup();
    }






}// -=============================================================
/* ---------------------------------------------------------------
외부의 함수에 변수를 그냥 넘기면?
 -> 데이터 공간의 값만 전달이 됨
   -> 원본과 연결이 되지 않음!!

한번에 리턴 여러개 가능?
  -> 절 대 불 가 능
    -> 방법이 하나 있긴한데 "구조체"

그러면 함수 안에 있는 값을 직접 사용하면?
    -> 절 대 불 가 능
    
ㅠㅠ 그럼 어떻게 하는..
   => 전역변수 또는 포인터를 이용    

*/  // --------------------------------------------------------------