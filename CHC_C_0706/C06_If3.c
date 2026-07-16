// C06_If3.c
#include <stdio.h>
int main()
{
    // 조건1 && 조건2 : 둘다 만족해야 true
    // 조건1 || 조건2 : 하나라도 만족 true
    // ---------------------------------
    // 결재금액이 1800원 이상이고 쿠폰이었다면
    // 무료결제, 아니면 일반 결제 진행
    int cost = 2000;
    int coupon = 1;
    if(cost>=1800 && coupon != 0){
        // 쿠폰 쓸 건지 안 쓸건지 물어보기
        int question = 0;
        printf("Coupon 1 , No Coupon 0 : ");
        scanf("%d", &question);
        if(question==1){
            printf(" Coupon Payment\n");
        }else {
            printf(" Normal Payment\n");
        }


    }else {
        printf("Normal payment\n");
    }
    // ----------------------------------------
    // 숫자를 하나 입력받아서 2의 배수이면서 3의 배수
    // 이면, 6의 배수를 출력.
    // 2의 배수 이면서 4의 배수이면 8의 배수 출력
    // 666의 배수 또는 999의 배수라면 "Death" 출력
    // 이 모든것들에 포함되지 않았다면 X 출력.
    int num = 0;
    printf(" Input Number : ");
    scanf("%d", &num);

    if(num%2 == 0 && num%3 == 0) {
        printf(" 6 Ship Number\n");
    }
    else if(num%2 == 0 && num%4 == 0){
         printf(" 4 Ship Number\n");
    }
    else if(num%666 == 0 || num%999 == 0){
        printf("Die\n");
    }
    else {
        printf("X\n");
    }
    // -------------------------------------------------------
    // 숫자 하나가 있음.
    // 그 숫자가 1부터 1만 사이의 숫자 이면서
    // 1000이하 또는 9000 이상인 경우에 대해
    // YES 또는 NO를 출력.
    num = 5000; // -9999 500 9500 5000 999999
    // 테스트 기법 -> 경계값 분석

    if(   (num>=1 && num<=10000) &&

            (num<=1000 || num>=9000) )
    {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    // (짜장 또는 짬뽕) 그리고 (콜라 또는 사이다 먹을래)

















} // ================================================