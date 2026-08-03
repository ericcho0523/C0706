/*  - - - - - -> board , Rock
    숫자 0~4사이에 입력 받아서, 해당 자리에 -라면 o변경
    o있었다면, - 변경.
    모든 - 이 ㅇ 되면 종료.
    조건. 최소 2개이상의 구조체 사용
          Main은, 구조체 생성 및 Start 하나만 있어야 함. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구조체 자리 >
// ===============================================================
struct Rock{
    int x;
    char marker;
};
struct Board{
    struct Rock rc[5] ;
    int sizeRock;
};

// ===============================================================
// < 함수 자리 >
// ===============================================================
void InitBoard(struct Board* bd){
    bd->sizeRock = 0;
    for(int i=0;i<5;i++){
        (*bd).rc[i].x = i;
        (*bd).rc[i].marker = '-';
    }
}
void PrintUI(struct Board bd){
    for(int i=0;i<5;i++){
        printf("%c ",bd.rc[i].marker);
    }
    printf("\n");
}

void Start(struct Board* bd){
    InitBoard(bd);
    for( ; (*bd).sizeRock < 5; ){
        system("cls");
        PrintUI(*bd);
        int x=0;
        for(;1;){
            printf("Input Number : ");
            scanf("%d", &x);
            if((x>=0 && x<=4)) break;
            system("cls");
            PrintUI(*bd);
            printf("Wrong Index!!!\n");
        }
        if( (*bd).rc[x].marker == 'o' ){
            (*bd).rc[x].marker = '-';
            (*bd).sizeRock--;
        }else if( (*bd).rc[x].marker == '-' ){
            (*bd).rc[x].marker = 'o';
             (*bd).sizeRock++;
        }else{
            for(int i=0; i<99; i++){
                printf("[ERROR]\n");
            }
        }
        
    }
    system("cls");
    PrintUI(*bd);
    printf("<GAME END>\n");

}

// ===============================================================
int main(){
    srand(time(NULL));
    // --------------------------------------------------------
    struct Board bd;
    Start(&bd);
    

}// ==============================================================
