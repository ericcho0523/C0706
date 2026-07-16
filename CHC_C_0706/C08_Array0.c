// C08_Array0.c
#include <stdio.h>
int main() {
    // 배열의 소중함을 직접 느껴보자.
    // 1. 숫자를 저장할 수 있는 변수 20개 생성.
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, 
    num12, num13, num14, num15, num16, num17, num18, num19, num20;
    // 자 , 이제 각각의 변수에 0으로 초기화하세요
    // .... 이거 맞아...? -> 당연히 아니겠지!!

    // 문자 저장을 최대 1000글자를 하려고 합니다.
    // char 변수를 1000개 만드세요.
       //이건 못함 ㅠㅠㅠㅠㅠ
    // ⭐배열을 이용하면 ??
    int num[20] = {0};
    char str[1000];
    for(int i;i<20;i++){
        printf("%d ", num[i]);
    }
    // 1~30
    // 마우스 -> 방향키 -> Insert키





}