// C06_If1.c
// 여기선 If만 하루종일 함
#include <stdio.h>(
int main() {
    // if(조건식) { 맞을때 } 아니면? 안넣어도 됨.
    // if (조건식){맞을때}else{틀릴때}
    // 조건식 : true/false : 0아닌놈/0
    // >= <= > < == != && ||
    // ----------------------------------------
    // 여러분 통장잔액 입력.
    // 1만원 이상이면 순대국밥, 아니면 컵라면출력
    int balance=9000;
    if(balance>=10000)
    {  // 이 맞다면 ~~~ 여기 실행
        printf("gookbap\n");
    }
    else
    {
        printf("raemen\n");
    }
    // -----------------------------------------
    int korea = 3;
    int japan = 2;
    // 만약 한국어 득점이 더 높으면 "승리" 아니면
    // 패배 ㅠㅠ 를 출력하세요
    if(korea>japan)
    {
        printf("victory\n");
    }
    else
    {
        printf("lose\n");

    }

    // 근데 이걸 삼항 연산자도 곁들여서...
    korea>japan ? printf("victory\n") : printf("lose\n");
    // -----------------------------------------------
    // 아래와 같은 질문을 통해 다른 결과를 출력하세요
    // 1. 나 사랑해?
    // Y : 고마워 
    //
    int question = 0;
    printf("Do you love me? : ");
    scanf("%d", &question);
    if(question != 0) 
    {
        printf("I love you too thank you\n");
    }
    else
    {
        // 사랑하지 않다고 한 경우
        printf("Do you really not love me? : ");
        scanf("%d", &question);
        if(question != 0)
        {
            // 사랑한다고 했음...
            printf("Love you too\n");
        }
        else
        {
            printf("Bye\n");
        }

    } 
    // ------------------------------------------------
    // 마라탕(1)     // 마라샹궈(0)
    // 맵기(맵게,안맵게) 각각 설정 필요
    // 주문하신 마라탕 맵게 나왔슴다.
    int type = 0;
    printf("maratang 1, shangqua 0 : ");
    scanf("%d", &type);
    if(type == 1)
    {   // 여기는 마라탕
       int spicy = 0;
       printf("shangqua spicy?? : ");
       scanf("%d", &spicy);
       if(spicy==1)
       {
          printf("shangqua spicy delivered\n");
          
       }
       else
       {
        printf("shangqua no spicy\n");
    

       }
    }
    else 
    {   // 여기는 마라샹궈
       int spicy = 0;
       printf("maratang spicy?? : ");
       scanf("%d", &spicy);
       if(spicy==1)
       {
          printf("maratang spicy delivered\n");
          
       }
       else
       {
        printf("maratang no spicy\n");
    

       }

    }
    // ---------------------------------------------
    // 1 짜장 2 짬뽕 3 볶음밥 4 탕수육 ?: x
    int choice = 0;
    printf("Jjajang1, Jampong2, Beok3, Tang4 : ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("Jjajang is here\n");
    }
    else
    {
        if(choice == 2)
        {
            printf("Jampong is here\n");
        }
        else
        {
            if(choice == 3)
            {
                printf("Beok is here\n");
            }
            else
            {
                if(choice == 4)
                {
                    printf("Tang is here\n");

                }
                else 
                {
                    printf("X\n");
                }
            }

        }

    }
    // -----------------------------------------------------------
    // 성적이 90이상이면 A 90이상이 아니라면 , 80이상이면
    // B, 80이상이 아니라면 70이상이라면 C, 아니라면 60이상
    // 이면 D, 50이상이면 E, 이것도 아니라면 F
    int score = 0;
    printf("Enter your grade : ");
    scanf("%d", &score);
    if(score>= 90)
    {
        printf("%c\n", 'A');
    }
    else
    {
        if(score>= 80)
        {
            printf("%c\n", 'B');
        }
        else
        {
            if(score>= 70)
            {
               printf("%c\n", 'C');
            }
            else
            {
                if(score>= 60)
                {
                    printf("%c\n", 'D');
                }
                else
                {
                    if(score>= 50)
                    {
                        printf("%c\n", 'E');
                    }
                    else
                    {
                        printf("%c\n", 'F');
                    }
                }
            }



        }


    }
    

    

















} // -------------------------------------- 
// --------------------------------------
// --------------------------------------