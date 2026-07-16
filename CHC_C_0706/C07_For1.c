// C07_For1.c
#include <stdio.h>
int main() {
    /*----------------------------------------
      반복문 ( Forever -> For )
      for(초기화 ; 조건식 ; 증감식)
      {
          실행할 놈들 싹 다 넣어
          근데 break 만나면 탈출
          continue 만나면 증감식 점프
      
      }
    */// -------------------------
    int sum = 0;
    for(int i=0; i<4; i++) {
        sum = sum + i;
    }
    printf("Sum : %d\n", sum);
    // 디버깅표 : 나오는 순서대로 그리셔
    // sum / i / i<4 / sum = sum + i / i++
    // ------------------------------------
    for(int i=3 ; i>=0; i--){
        sum = sum + i; // sum += i;
        printf("%d" , sum);
    }   printf("\nSum: %d\n", sum);
    // sum / i / i>=0  / sum = sum + i / sum출력 / i-- 
    // -----------------------------------------------------
    // 실습 > 해당 문제의 결과와 디버깅 표를 작성하세요
    
    sum = 0;
    for(int i=0; i <= 5; i=i+2){
        sum = sum + i;
        printf("%d", sum);
    }   printf("\n");
    printf("Avg : %.2lf\n", sum/3.0) ;
    // sum / i / i<=5 / sum=sum+i / 출력 / i=i+2
    // -----------------------------------------------
    int start = 5, end = 8;
    for(int i=start ; i<end; i++){
        printf("%d ",i);
    }   printf("\n");
    // start end i i<end i출력 i++
    // ------------------------------------
    start = 5, end = 12;
    for(int i=start; i<end-i; i++){
        printf("%d ", i);
    }   printf("\n");
    // start end i i<end-i 출력 i++
    // ---------------------------------------
    // continue; -> 만나는 순간, 증감식으로 점프
    // 디버깅 표 continue ------------------------- 1->2
    start = 3, end = 8;
    for(int i=start; i<end; i++){
        if(i%2==0) continue;
        printf("%d ", i);

    }   printf("\n");
    // start  end  i  i<end  i%2==0  i출력  i++
    // ---------------------------------------
    start = 4,end=8;
    int cnt = 0;
    sum = 0;
    for(int i=start; i<end - cnt; i++){
        if(i%2==0) continue;
        cnt ++; sum = sum+i;
    }   printf("%d %d\n", sum, cnt);
    // start  end  cnt  i  sum  i i<end-cnt i%2==0 cnt++ sum+=i i++
    // --------------------------------------------------------
    // vscode 글자 크기 조정방법
    // File -> Prefernece -> Setting -> 검색 -> wheel -> 위아래 두개
    // ---------------------------------------------------
    // break; -> 얘 만나는 순간 가장 가까운 반복문 와장창!
    start=1, end=10;
    for(int i=start; i<end; i++){
        if(i%2==0) continue;
        if(i%7==0) break;
        printf("%d ", i+1);
    }   printf("\n");
    printf("------------------------------\n");
    // start end i i<end i%2 i%7 출력 i++

    // <반복문을 잘 작성하는 방법 >
    // ⭐ 조건식을 어케 쓸까????? -> 시작과 끝 정해야 함.
    // 예시. 1~9754까지 출력 : 1시작 9754 스텝 : +1
    // ⭐ 반드시 앵간하면 I를 0으로 시작!!!
    // i=0 -> i<9754   i++   i+1
    for(int i=0; i<9754; i++){
        printf("%d ", i+1);
    }   printf("\n");


    // 1부터 999 까지 2의 배수만 출력해라 (2 998)
    // i=0 +1 ... 999 까지 -> <1000 : 1000번 (실행횟수)
    // i=0 +2
    // 2 4 6 8  .. 998 ... : 500번
    for(int i=0;i<998;i=i+2){ //i+=2;
        printf("%d ", i+2);
    }

    // 1부터 9999까지 홀수만 

    // i=1
    for(int i=0;i<10000;i=i+2){
        printf("%d ", i);
    }

    // i=0
    for(int i=0; i<10000; i=i+2){
        // 0 2 4 6 8 10 ... 9998
        printf("%d ", i+1);
    }
    // 1부터 10만까지 숫자를 출력하되
    // 6의 배수가 나오면 건너뛰고,
    // 3의 배수는 출력하세요.
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<100000; i=i+1){
        cnt++;
        if(i%6==0) continue;
        if(i%3==0) printf("%d ",i);
    }

    for(int i=0; i<100000; i=i+3){
        // 0 3 6 9 12 15
        cnt2++;
        if(i%6==0) continue;
        printf("%d ",i);
    }
    printf("\nCnt1 : &d,Cnt2 : %d\n", cnt1, cnt2);
    // Cnt1 : 100000,Cnt2 : 33334
    // 처음부터 최적화 신경쓰지 마라.

    // 무한반복 -> 조건식이 항상 true
    for( ; 1 ;){
        printf("fun cprogarmming");
    }
    // 교훈. 무한반복은 항상
    // 나갈수 있는 break를 고려.
    // 터미널 Ctrl + C : 종료.















}