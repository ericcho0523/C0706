// C27_SelfFunction.c
// 재귀함수
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
// ==============================
int Fact(int num){
    // 5 x 5-1 -> 4 * 4-1 -> 3 * 3-1 -> ... 1 -> 1
    printf("Num : %d\n", num);
    if(num <= 1){
        return 1;
    }
    else{
        printf("Num %d -> Else\n", num);
        Sleep(1000);
        return num * Fact(num-1) ;
    }
}
int Fibo(int num){
    // 피보나치 수열의 핵심. 1번, 2번째는 1
    if(num<=2){
        return 1;
    }
    else{
        return Fibo(num-1) + Fibo(num-2);
    }
}
// F(3) = F(0)   + F(1)   + F(2)
// F(n) = F(n-3) + F(n-2) + F(n-1)
// 단, F(0,1,2)는 1이다.
// 이때, Main에서 F에 8을 넣었을때 무엇이 나올까요. 
int F(int num){
    if(num<=3){
        return 1;
    }
    else{
        return F(num-3) + F(num-2) + F(num-1);
    }
}  

void Reverse(int num){
    if(num==0){
        return ;
    }
    else{
        printf("%d", num%10);
        Reverse(num/10);
    }
}
// 문자 뒤집기
// Hello World -> dlroW olleH
void ReverseString(char str[]){
    if(str[0] == '\0'){
        // 마지막 글자. 끝내면 됨
        printf("\n");
        return;
    }else{
        ReverseString(str+1);
        printf("%c",str[0]); 
    }
}
// 진법 변환하기 10 -> 2
void Format10_2(int num){ // 19
    int mock = num/2; // 9
    int nam  = num%2; // 1

    if(mock==0){
        printf("%d",nam);
        return;
    }
    // 아직 더 나눌게 있다는 소리
    Format10_2(mock);
    printf("%d",nam);
}
int Format2_10(int num){
    static int base = 1;
    int mock = num/10;
    int nam  = (num%10) * base ;
    base *= 2;
    // 내가 만약 마지막 숫자인가?
    if(mock==0){
        return nam;
    }
    // 아니다.
    return nam + Format2_10(mock);
}
// ============================== 
int main(){
    srand(time(NULL));
    // printf("Fact(5) : %d\n",Fact(5)); // 120
    printf("Fibo(5) : %d\n",Fibo(5)); // 8
    printf("F(8)    : %d\n",   F(8)); // 8
    Reverse(123456789);

    ReverseString("Hello World");
    printf("\n");
    Format10_2(19);

    printf("\n\n 10011 -> %d\n", Format2_10(10011));
}// --------------------------------