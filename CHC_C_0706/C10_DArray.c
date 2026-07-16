// C10_DArray.c
#include <stdio.h>
#include <string.h>
// =============================================================
int main(){
    char text[3][100] = {0};
    // text[0] -> 100글자 저장 가능 배열이름
    // text[1] -> 100글자 저장 가능 배열이름
    // text[2] -> 100글자 저장 가능 배열이름
    strcpy(text[0], "Hello");
    strcpy(text[1], "World");
    strcpy(text[2], "Program");
    printf("%s\n", text[0]);
    printf("%s\n", text[1]);
    printf("%s\n", text[2]);

    int matrix[3][4] = {0};
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;

    for(int i=0;i<4;i++){
        matrix[1][i]=i+5;
    }
    
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            matrix[i][j] = 1+j+i*4;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");

    }
    // ------------------------------------------------------
    // 간단한 연습문제
    // 여러분은 숙소를 운영하는 집주인입니다.
    // 아파트의 한 층당 5개의 집이 있으며
    // 1층은 101호~105호, 2층은 201호~205호
    // 와 같이 1층~3층까지 각 호에 해당하는
    // 숫자를 배열에 저장하고 싶습니다.
    // 어케 만들고 어케 저장할지를 작성하세요.

    int build[3][5]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            build[i][j] = (3-i)*100 + j+1;
            printf("%3d ", build[i][j]);
        }
        printf("\n");

    }


} // ============================================================