// C04_Scanf1.c
#include <stdio.h>
int main()
{
    // scanf : scan + format : 어떠한 형식으로 입력받기
    // 사용방법
    // scanf("%? %? ...", &변수, &변수...);
    // " " 안에 %?를 제외한 것들은, 구분 인자
    // 변수 앞에 꼭 & 붙여야함. 안붙이면 폭발함.
    // -------------------------------------------
    // 개발자는 항상 사용자를 위해 UX/UI를 신경 써야 함
    // ---------------------------------------------
    int x = 0;
    printf("Enter number : "); // UI
    scanf("%d", &x); // 배송좀요~
    printf("Entered x : %d\n", x);
    printf("-------------------\n");
    //숫자 두개를 입력받기
    int y=0, z=0;
    printf("숫자 하나 입력 : ");
    scanf("%d", &y);
    printf("숫자 하나 입력 : ");
    scanf("%d", &z);
    printf("두 숫자 : %d %d\n",y,z);
    // 숫자 두개를 "한번에" 입력받기
    printf("숫자 두개 공백구분 입력 : ");
    scanf("%d %d", &y,&z);
    printf("두 숫자 : %d %d\n", y,z);
    printf("-------------------\n");
    //전화번호 입력받기 010-2584-8343
    int front=0, mid=0, end=0;
    printf("enter phone numer : ");
    scanf("%d-%d-%d",&front, &mid, &end);
    printf("%03d-%d-%d\n",front,mid,end);


    
    
 








}