// C09_String.c
#include <stdio.h>
#include <string.h> // 각종 문자열 함수
// ================================================================
void E() {
    printf("-----------------\n");
}
void EN(){
    printf("\n");
}
int main(){
    char str[100] = "Hello World Programming";
    // 널문자를 직접 삽입해서, 조작
    str[10] = '\0';
    printf("%s\n",str); // %s는, \0 나오기 전까지 모두 출력
    for(int i=0;i<100;i++){
        if(str[i]=='\0'){
            printf("End\n");
            // printf("%c %d\n", str[i+3], str[i+2]);
            break;
        }else{
            printf("%c", str[i]);
        }
    }
    // ------------------------------------------------------------
    char str2[100] = "AaBbCcDdEeFf";
    // 대문자는 출력, 소문자는 * 출력
    for(int i=0;i<100;i++){
        if(str2[i]=='\0'){
            printf("\n");
            break;
        }
        // ------------------------------
        // 널문자 아닌 경우
        // -> 대(65~90)?소?
        if(str2[i]>=65 && str2[i]<=90){
            printf("%c", str2[i]);
        }else{
            printf("*");
        }
    
    }
    // -----------------------------------------------------------
    char str3[1000] = "Hello World";
    // scanf("%s", str3); // & 쓰지마!
    for(int i=0;str3[i]!='\0';i++){
        if(str3[i]>=65 && str3[i]<=90){
            printf("%c", str3[i]);
        }else{
            printf("*");// 마스킹(Masking)
        }
    }
    // ------------------------------------------------------------
    char resi[15] = "940110-1111111";
    // 를~ 원본은 그대로 두고, 94**10-1******
    //                      012345678~    \0끝
    // 가 나오게 끔 출력하세요.
    for(int i=0;resi[i]!='\0';i++){
        if((i==2 && i==3) || i>=8){
            printf("*");
        }else{
            printf("%c",resi[i]);
        }
    }   EN();
    E(); 
    // ----------------------------------------------------------
    // 거꾸로 + 저장
    // 1~9 5개씩 작성
    char str4[100] = "111112222233333444445555566666777778888899999";
    // 1. 길이 알아내야함. -> 카운팅
    int str4Count = 0;
    for(int i=0;str4[i]!='\0';i++){
        str4Count++;
    }
    // 2. 그 길이부터 0번째까지 출력
    for(int i=str4Count-1;i>=0;i--){
        printf("%c",str4[i]);
    }   EN();E();
    // 3. 를 이제 딸깍으로 구해봅시다.
    // strlen(문자열배열) -> 길이 구해줌.
    // 원리 : \0 나오기 전까지 개수 
    for(int i=strlen(str4)-1;i>=0;i--){
        printf("%c",str4[i]);
    }   EN();E();
    // 길이
    // 문자열을 하나 입력받습니다. 그게 딱
    // 10글자면 종료, 아니면 무한 반복.
    // 1. 반복문으로 길이 구해서 수동 계산
    // 2. strlen
   //  char str5[1000]={0};
    //for(;1;)
    //{
    //    printf("Input : ");
    //    scanf("%s",str5);
    //    int str5Length = 0;
    //    for(int i=0;str5[i]!='\0';i++){
    //    str5Length++;
    //   }
    //   if(str5Length==10) break;
    //}
    //E();

    //for(;1;){
    //    printf("Input : ");
    //    scanf("%s",str5);
    //   if(strlen(str5)==10)break;
    //}   
    // -------------------------------------------------------

    // 합치기
    // char str1[100], char str2[100]
    // "AAAAA", "BBBBB" -> "AAAAABBBBB"
    // 아이디어.
    // 두개의 길이 다 구해야함. (strlen)
    // str1 뒷부분 <- str2 앞부분
    // str1[???+i] <- str2[i]
    char str5[100] = "AAAAA";
    char str6[100] = "BBBBB";
    int str5Size = strlen(str5);
    for(int i=0; i<strlen(str6);i++){
        str5[str5Size+i] = str6[i];
    }
    str5[strlen(str5)] = '\0';
    printf("Str5 : %s\n", str5);
    // AAAAABBBBB
    // -------------------------------------------------
    char str7[100] = "CCCCC";
    strcat(str5, str7);
    printf("Str5 : %s\n", str5);
    // --------------------------------------------------
    // 무한반복 이용해서, 사용자에게
    // 매번 문자열을 입력받음.
    // 특정 문자열에 입력받은 문자열을
    // 계속 누적하되, Enter 까지도 누적.
    // END이 입력이 될 경우, 종료하는 코드.
    char text[10000] = {0};
    char temp[100] = {0};
    for(;1;){
        printf("Input String : ");
        scanf("%s", temp);
        // if(temp[0]=='E' && temp[1]=='N' && temp[2]=='D') break;
        if( strcmp(temp, "END")==0) break;
        // 비교 - END
        // 방법. temp[0]==E 그리고
        // temp[1]==N 그리고 temp[2]==0
        // 이면, 종료. 아니면 strcat
        strcat(text, temp);
        strcat(text, "\n");// 엔터 조사
    }
    printf("<<<TEXT>>>\n%s\n",text);

    // 비교
    // strcmp(String Compare)
    // strcmp(문자열1, 문자열2)
    // 둘이 같으면 0. 1번이 작으면-1, 크면 1
    // 위의 문제중, END 비교하는거 이거로 교환

    // 마음속에 먹고 싶은 음식을 하나 정한 뒤
    // 무한반복을 이용해서 뭐 먹고 싶은지 질문
    // 내가 원하는것과 일치하지 않으면 계속 질문
    // 원하는 것이 입력되었다면 " 그래 가자" 출력
     char food[100] = "Burger";
     char question[100];
     for(;1;){
        printf("What do yo want to eat? : ");
        scanf("%s",&question);
        if(strcmp(question,food)==0) {
            break;
        }else{
            continue;
        }
        printf("Lets Go");

    // 복사
    // A에다 B의 내용을 붙여넣기
    // str8는 비어있고, str9에 입력받은 후
    // 그 입력받은 내용을 str8에도 저장하세요
     char str8[1000];
     char str9[1000];
     printf("Enter str9 : ");
     scanf("%s",&str9);
        // str9의 길이까지, str9[i]값을 str8[i] 넣!
        // 마지막 널문자 마무리.
        for(int i=0;i<strlen(str9);i++){
            str8[i]=str9[i];
        }
        int str8Len = strlen(str8);
        str[str8Len] = '\0';
        printf("Str8 : %s\n", str8);


    

    

        

    


    









    // ------------------------------------------------------------


    

    // 합치기
    
    // 비교

    }  
}
 // ===============================================================