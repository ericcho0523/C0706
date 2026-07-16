// C07_For2.c
// 이중 반복문 ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐
// ------------------------------------------------
#include <stdio.h>
// =====================================================
void E(){
    printf("----------------------------\n");
}
// =====================================================
int main() {
    // 방금 발견한 공식 : 1 + i*5 + j
    for(int i=0; i<5; i++) {
        // i가 조건 만족할때마다 아래 다 실행
        for(int j=0;j<5;j++) {
            printf("%2d ", 1+i*5+j);
        }   printf("\n");
        // j가 5번 실행되고 한바퀴 끝 -> i++
    } E();
    // -----------------------------------
    // 1 + j + i*6
    for(int i=0; i<3; i++) // 느리게
    {
        for(int j=0;j<6;j++) // 빠르게 
        {
            printf("%2d ", 1 + j + i*6);

        } // 6번을 출력한 후..
        printf("\n");
        
    } E();
    // -----------------------------------------------
    // 공식 : 1+j+ col*i
    int row = 7;
    int col = 4; // 다음에 쓸때는 int 생략.
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",1+j+ col*i);
        }
        printf("\n");
    } 
    E();
    row = 7;
    col = 10;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",1+j+ col*i);
        }
        printf("\n");
    }
    E();

    // ------------------------------------------------
    // 공식 : 12-j-i*4
    row = 3;
    col = 4;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",row*col-j-i*col);
        }
        printf("\n");
    }
    E();
    // 유지보수가 좋은 코드 -> 바꿀 필요 없음.

    // ------------------------------
    // 공식 : col-j+i*col
    row = 4;
    col = 6;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",col-j+i*col);
        }
        printf("\n");
    }
    E();
    // ----------------------------------------
    // 짝수 공식 : 1+j+ col*i
    // 홀수 공식 : col-j+i*col
    row = 4;
    col = 6;
    
    for(int i=0; i<row; i++)
    {
        if(i%2==0){
            for(int j=0; j<col; j++)
        {
            printf("%2d ",1+j+ col*i);
        }
        }
        else{
        for(int j=0; j<col; j++)
        {
            printf("%2d ",col-j+i*col);
        }
        }
        printf("\n");
    }
    E();

    // Quiz 2
    row = 5;
    col = 5;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",2+j*2+i*col*2);
        }
        printf("\n");
    }
    E();

    // Quiz 4
    row = 5;
    col = 5;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",1+j*5+i);
        }
        printf("\n");
    }
    E();

    // Quiz 5
    row = 5;
    col = 5;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",row*col-j*5-i);
        }
        printf("\n");
    }
    E();

    // -----------------------------------------------------
    // 카운트 기법 ->  cnt=0, cnt++
    row = 6, col = 4;
    int cnt = 0;
    for(int i=0;i<row; i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%2d ", ++cnt);
        }
        printf("\n");
    }
    E();
    // 1. i 와 j 를 조합해야 하는 경우 생김.
    // 2. 실력 향상에 매우 도움이 됨.
    // 3. 자료구조에서 매우 빈번하게 사용.

    // cnt는 그럼 언제 이용할까???
    // 규칙이 없을 경우(i,j조합)
    // 단순히 횟수만 세야 하는 경우.
    // ---------------------------------------
     

    
    // Quiz 7
    int size = 5;
    cnt = 0;
    // 0으로 시작하면 앞++, 1로 시작하면 뒤++
    // 한번도 실행이 안된다면? 1인경우 문제!
    for(int i=0; i<size;i++)
    {
        // for(int j=0;j<i+1;j++)
        for(int j=0;j<=i;j++)
        {
            printf("%2d ", ++cnt);
        }
        printf("\n");

    }
    // Quiz 8
    size = 5;
    for(int i=0; i<size;i++)
    {
        
        for(int j=0;j<size-1-i;j++)
        {
            printf("* ");
        }
        printf("\n");

    }

    // Quiz 9

    size = 5;
    cnt = 0;
    for(int i=0; i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            printf(" * ");
        }
    
        for(int j=0;j<=i;j++)
        {
            printf("%2d ", ++cnt);
        }
        printf("\n");

    }
    E();

    // Quiz 10
    size = 5;
    cnt = 0;
    for(int i=0;i<size;i++)
    {
       
        if(i==0 || i==size-1){
            for(int j=0;j<size;j++){
                printf("%2d ",++cnt);
            }
        }
        else{
                for(int j=0;j<size/2;j++){
                    printf("   ");
                }
                printf("%2d ",++cnt);
        }
            printf("\n");

        }
    }

    // -------------------------------------------------
    // Flag 기법
    // Flag : 깃발 = 상태
    // Flag 0 -> 작동 x
    // Flag 1 -> 작동함
    // --------------------------------------------------
    // -1 한번 두번 연속 입력되었을때, 종료
    // -1 입력되면 flag를 1로 설정
    // 다음 반복문때 -1입력되면 flag를 2로 설정
    // 만약 2가 되면 끝.
    // -1이 아니면? flag를 0으로 세팅.
    // --------------------------------------------------
    

    




    

// ================================================ 