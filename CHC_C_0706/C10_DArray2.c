// C10_DArray2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// =============================================================
// 함수 자리
void E(){
    printf("--------------\n");
}
void EE(){
    printf("\n");
}
// 함수자리에는 여태 배운 모든 것들을 넣을 수 있음.
void Print1_25(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%2d ", 1+j+i*4);
        }   EE();
    }   E();
}
// =================================================================
int main(){
    // 2차원 배열을 가지고 놀아보자  !
    // 1. 2차원배열 4*5를 만들어서
    // 1부터 차례대로 숫자를 저장하세요
    int mat1[4][5] = {0};
    int cnt = 1;
    for(int i=0;i<4;i++)
    {
        // i: 행, 느리게 도는 반복문
        for(int j=0;j<5;j++){
            mat1[i][j] = cnt++;
            printf("%2d ",mat1[i][j]);
        }EE();
    }E();
    // -----------------------------------------------------------
    // mat1은 4x5에 순서대로 숫자 들어가있음.
    // 이름, 끝부터 처음까지 역순으로 출력. 모양유지
    // i,j를 꼭 0으로 시작할 필요 X
    for(int i=3;i>=0;i--){
        for(int j=4;j>=0;j--){
            printf("%2d ",mat1[i][j]);
        }   EE();
    }   E();
    // ------------------------------------------------------------
    // 1 2 3 -> 7 4 1 윗방향
    // 4 5 6 -> 8 5 2 윗방향
    // 7 8 9 -> 9 6 3 윗방향
    // 20 10 00 
    // 21 11 01
    // 22 12 02
    for(int i=0;i<5;i++){
        for(int j=3;j>=0;j--){
            printf("%2d ",mat1[j][i]);
        }   EE();
    }   E();
    // -------------------------------------------------
    // 8x6배열에 순서대로 1부터 저장하세요. (mat2)
    // 그리고 나서, 아래에서 위로, 왼쪽에서 오른쪽
    // 순서로 값들을 출력하세요
    int mat2[8][6] = {0};
    int cnt2 = 1;
    for(int i=0;i<8;i++){
        for(int j=0;j<6;j++){
            mat2[i][j]=cnt2++;
            printf("%2d ",mat2[i][j]);
            
        }   EE();
    }   E();

    for(int i=0;i<6;i++){
        for(int j=7;j>=0;j--){
            printf("%2d ",mat2[j][i]);
        }   EE();
    }   E();
    // ------------------------------------------------------
    // mat3에 5x5의 배열을 만들어서 모든 자리에
    // 1을 넣은 후, 아래와 같은 순서에 맞춰 작업 진행
    // 1. 홀수 행에 모든 값 + 1
    // 2. 짝수 열에 모든 값 + 1
    // 3. 모든 요소를 출력하되, 짝수는 *로 바꿔출력.
    int mat3[5][5] = {0};
    

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            mat3[i][j]=1;
        }   
    }   
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i%2==1){
                mat3[i][j] += 1;
            }
            // ------------------------------
            if(j%2==0){
               mat3[i][j] += 1;
            }
        }   
    }  
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mat3[i][j]%2==0){
                printf(" * ");
            }else{
                printf("%2d ",mat3[i][j]);
            }
        }   EE();
    }   E();
    // -------------------------------------------------------
    // 5x5 배열 만들어서 1~25 순서대로 저장 하고
    // 모든 요소 출력하되, 한줄 끝 각 줄 합계출력
    // 마지막엔 Total : ?? 까지 출력되게 하세요.
    int mat4[5][5] = {0};
    for(int i=0;i<5;i++){
        for(int j=0; j<5;j++){
            mat4[i][j] = 1+j+5*i;
        }
    }
    int total = 0;
    for(int i=0;i<5;i++)
    {   
        int sum = 0;
        for(int j=0; j<5;j++)
        {
           printf("%2d ",mat4[i][j]);
           sum = sum + mat4[i][j];
        }
        printf(" : %d\n", sum);
        total += sum;
        EE();
    }
    printf("Total : %d", total);
    E();
    // --------------------------------------------------------
    // mat5 8x8에다가 64~1 저장 후
    // 모든 요소를 출력하되, 두가지를 각 줄 뒤에 출력
    // 짝수의 합 EvenSum:
    // 홀수의 합 OddSum:
    // 마지막 줄은, 짝수들의 평균, 홀수들의 평균!
    // 8 7 6 5 4 3 2 1 EvenSum:20 OddSum:16

    int mat5[8][8] = {0};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            mat5[i][j] = 8*(8-i)-j;
        }
        EE();
    }E();
    int evenTotal = 0, evenCount=0;
    int oddTotal = 0, oddCount=0;
    for(int i=0;i<8;i++){
        int even=0;
        int odd=0;
        for(int j=0; j<8;j++){
            printf("%2d ", mat5[i][j]);
            if(mat5[i][j]%2==0){
                even += mat5[i][j];
                evenCount++;
            }
            else{
                odd += mat5[i][j];
                oddCount++;
            }
        }
        printf("EvenSum:%d,OddSum:%d\n",even,odd);
        evenTotal+=even;     oddTotal+=odd;
    }
    printf("EvenAverage : %.2lf\n", (double)evenTotal/evenCount);
    printf(" OddAverage : %.2lf\n",  (double)oddTotal/oddCount);
    // 33.00 32.00


    // ㅠㅠㅠㅠㅠ 매번마다 배열 계속 실행하는거 너무 힘들어요 ㅠㅠㅠㅠ
    // 매번 반복문 반복문 반복문.... -> 자동화 할 수 없을까??
    // ⭐ 함수(Function)로 자동화 가능.
    // E() -> ----------------\n
    // Print1_25();
    // Print1_25();
    // Print1_25();
    // Print1_25();
        
  




}//====================================================================