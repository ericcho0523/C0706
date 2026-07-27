// C13_Pointer6.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
int alpha[26] = {0};
// =========================================================
// < 함수 자리 >
// =========================================================
void InitString(char* str, const char* target){
    // const : 상수 -> 변경 불가능
    // 문자열 함수 사용 금지
    // \0 나오기 전까지 그냥 넣고, 널문자 나오면 넣고끝
    for(int i=0; 1; i++ ){
        if(target[i] == '\0'){
            *(str+i) = *(target+i);
            return;    
        }
        *(str+i) = *(target+i);
    }
}
void PrintString(char* str){
    printf("%s\n", str);
    // %s : 넘겨받은 주소부터 널문자 나오기전까지 출력

}
void CountAlpha(char* str){
    // 전역변수 alpha를 선언. 문자열을 함수에 전달해서 
    // 대문자 알파벳 각각 몇개인지 저장( 26개 )
    for(int i=0; *(str+i) != '\0' ; i++ ){
        if( *(str+i)>=65 && *(str+i)<=90 ){
            int index = *(str+i) - 'A';
            alpha[index]++;
        }
    }
}
void PrintAlpha(){
    // 각 알파벳이 몇개씩 있는지 궁금.
    // 알파벳 : 횟수   를 개수가 있는 것만 모두 출력
    for(int i=0; i<26; i++){
        if( *(alpha+i)==0 ) continue;
        printf("%c : %d\n", i+65, *(alpha+i) );
    }
}
// 문자열을 전달받아 소문자를 대문자, 
// 대문자를 소문자로 변환하세요
void ChangeAlpha(char* str){
    printf("Before : %s\n", str);
    for(int i=0; *(str+i) != '\0'; i++){

        if( *(str+i)>=65 && *(str+i) <=90 )
            // 대->소 변환
            *(str+i) += 32;
        else if(*(str+i)>=97 && *(str+i) <=122)
            // 소->대 변환
            *(str+i) -= 32;
        else
            // 그 외의 경우
            continue;
    }
    printf("After  : %s\n", str);
}
// =========================================================
int main(){
    srand(time(NULL));
    // -----------------------------------------
    char str[100];
    InitString(str, "Hello");
    PrintString(str);
    CountAlpha("AAAAaaaaB@#$@#BBBbbb@#$@&&_))^(@##bSLKJEBPIUS@#Y$(LDMVSOWEJG");
    PrintAlpha();
    char str2[999] = "asWksjdhvIWE#hjubfc#UhbxdC*&Weclj!O78hxs78fWj";
    ChangeAlpha(str2);


}// ========================================================
/*----------------------------------------------------------

----------------------------------------------------------*/