// C24_Preprocessing.c
#include <stdio.h>
#define TEST 393543
#define TT
#define VERSION1_0
#define VERSION1_1
#define VERSION1_2
#define VERSION1_3
#define VERSION 2
// define이나, 전역변수 같은건, 어디서나 쓸 수 있으니까
// 전부 대문자로 표시하도록 합시다.
// define 언제써? -> 모두가 공용으로 같은 값을 사용할 때
//     예시 : API Key, DBMS ID/PS, IP Address....
// -------------------------------------------------
void A(){
    printf("Hello\n");
}
void B(){
    printf("World\n");
}


int main(){
    printf("Test : %d\n",TEST);
    // ------------------------------------------------
    // TT가 선언되어 있으면 "티티~" 아니면, "ㅠㅠ"출력
    #ifdef TT
       // 만약에 TT가 정의되어 있다면.. 여기를 실행
       printf("TT~\n");
    #else
       // 정의되어 있지 않으면 여기 실행
       printf("uu...\n");
    #endif   

    // -------------------------------------------------
    // 운영체제 따라 결과 다르게 나오게 하기
    // Window : _WIN32 또는 _WIN64
    // MAC(매킨토스) : __APPLE__
    // Linux : __linux__
    // -------------------------------------------------
    #ifdef _WIN64
        printf("Hello window\n");
    #endif

    #ifdef  __APPLE__
        printf("Hello Apple\n");  
    #endif     

    #ifdef  __linux__
        printf("Hello Linux\n"); 
    #endif    
    

    // ----------------------------------------------------

    // ------------------------------------------------------
    // VERSION이라는 이름을 define으로 정의하세요
    // 만약, VERSION이 정의되어 있다면 A함수를
    // 그렇지 않다면 B함수를 실행하세요
    // A : Hello 출력, B : World 출력
    #ifdef VERSION 
        A();
    #endif  

    #ifndef VERSION
        B();
    #endif    
    // --------------------------------------------------------
    #if VERSION >= 3
        printf("Version 3!!\n");
    #else    
        printf("Version 2\n");
    #endif

    

}