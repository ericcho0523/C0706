// C04_Scanf2.c
#include <stdio.h>
int main()
{
    // 세련되게 입력받기
    // x= 12345.6789에서 정수 부분과 소수 부분을
    // 분리하세요.
    int front =0, end=0;
    printf("정수.소수 입력 : ");
    scanf("%d.%d",&front, &end);
    printf("정수 : %d, 소수 : %d\n", front,end);
    //---------------------------------------

    // <실습>
    //생년월일을 입력받아 출력하고 싶습니다.
    // 입력의 경우 1994-01-10와 같이 입력되며
    // 출력의 경우 1994년 01월 10일 와 같이 출력
    int a=0, b=0, c=0;
    printf("Enter your birth : ");
    scanf("%04d-%02d-%02d",&a, &b, &c);
    printf(" %dyear %2dmonth %2dday\n",a,b,c);
    printf("-----------------\n");
    // 한 파일에서는 똑같은 변수 이름 2개 불가능






}