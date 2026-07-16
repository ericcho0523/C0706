// C06_If2.c
#include <stdio.h>
#include <windows.h>

int main () {
    // -------------------------------------------
    // 성적이 90이상이면 A 90이상이 아니라면 , 80이상이면
    // B, 80이상이 아니라면 70이상이라면 C, 아니라면 60이상
    // 이면 D, 50이상이면 E, 이것도 아니라면 F
    // 을 Else If를 이용해 풀이할 것.
    // -------------------------------------------
    int score = 90;
    if(score>=90) {
        printf("A\n");
    }
    else if(score>=80){
        printf("B\n");
    }
    else if(score>=70){
        printf("C\n");
    }
    else if(score>=60){
        printf("D\n");
    }
    else if(score>=50){
        printf("E\n");
    }
    else {
        printf("F\n");
    }
    // -----------------------------------------------------------
    // 바나프레소 키오스크 구현
    // Recommand, All, Bundle, Milk Tea, Juice, Coffee
    // 1. 메뉴판을 구현
    // 2. 특정 숫자 입력하면, 해당 메뉴를 출력할 것.
    // ( + ) 뭔가 입력 끝나면 "삡" 소리 나게 구현
    printf("------------\n");
    printf(" > [1] : Recommand\n");
    printf(" > [2] : All\n");
    printf(" > [3] : Bundle\n");
    printf(" > [4] : Milk Tea\n");
    printf(" > [5] : Juice\n");
    printf(" > [6] : Coffee\n");
    printf("------------\n");
    int menu = 0;
    printf("Enter the menu : ");
    scanf("%d", &menu);
    // <<<<<<<<<<<<<<< 잠시후 여기에 소리 출력 >>>>>>>>>
    Beep(200,500);
    Sleep(500); // 0.5초 대기
    Beep(400,500);
    if(menu==1) {
        printf("Americano, Energy shot ade, muffin\n");
    }
    else if(menu == 2) {
        printf("a lot of things\n");
    }
    else if(menu == 3){
        printf(" coffee / sandwich\n");
    }
    else {
        printf("Error\n");
    }
    // --------------------------------------------------
    // (추가과제) 각 메뉴별로, 추가 메뉴판 만들어서
    // 입력을 받고, 입력한 메뉴에 대한 정보 아니면
    // 내용을 간단하게 출력할 것.

    // 여러 조건 한번에 처리하기
    // && ||
    
































}