    // Practice4.c
    // C20_StructProject.c

    // - - - o - 0 
    // - - - - - 1
    // - - ○ - - 2
    // - - - - - 3 
    // - - - - - 4
    // 0 1 2 3 4 x
    // 2 2 입력 -> 2.2자리에 O
    // 또다시 입력 -> 입력받은 자리에 o 위치
    // Rock : x, y좌표 가지고 있음 + 출력을 뭐로 할지 저장 ( o )
    // Board : 25개 2차원 배열. Rock 여러개 최대 25개.

    // 모든 Rock은 순서대로 00, 01, 02, .... 좌표를 가지며 -를 가짐
    // 사용자가 입력한 좌표에 해당하는 Rock의 - -> o / 안전장치
    // 보드를 다시 출력 + 화면 초기화(검색)
    // 이후 다시 입력받기
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
        int y;
        char marker; // 기본값 -, 입력받을시 o
    };
    struct Board{
        struct Rock board[5][5];
        int sizeRock; // 25개가 되면 강제 종료

    };

    // ===============================================================
    // < 함수 자리 >
    // ===============================================================
    void InitBoard(struct Board* board){
        // 25개의 Board안의 board에 x,y 세팅, - 세팅
        board->sizeRock=0;
        // (*board).sizeRock 이게 어려워서 쉽게 만들어 줌.
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                (*board).board[i][j].x = i;
                (*board).board[i][j].y = j;
                (*board).board[i][j].marker = '-';
            }
        }


    }
    void PrintUI(struct Board board){
        // 5x5 Rock의 모든 marker 출력 + 1칸 공백
        // - - - o - 0 
        // - - - - - 1
        // - - ○ - - 2
        // - - - - - 3 
        // - - - - - 4
        // 0 1 2 3 4 x
        // ---------------------------------
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                printf("%c ",board.board[i][j].marker );
            }
            printf("%d\n",i);
        }
        // 0 1 2 3 4 x
        printf("0 1 2 3 4 x\n");

    }
    void Start(struct Board* board){
        // Init -> 함수
        InitBoard(board);
        // UI 출력 함수
        // PrintUI(*board);
        // 무한반복 -> 출력 - 입력 - 변경 -> , sizeRock 5(25) 되면 끝.
        int x=0,y=0;
        for(; board->sizeRock<5 ;){ // 5->10->25    
            // 화면 초기화 하기
            // UI 출력
            printf("Input X Y : ");
            scanf("%d %d", &x, &y);
            if((x>=0 && x<=4) && (y>=0 && y<=4) ) break;
            system("cls");
            PrintUI(*board);
            printf("Wrong Index!!!\n");
            // 사용자에게 입력 받기 (무한반복)
            // 해당 좌표의 Rock marker 수정하기
            // RockSize 하나 증가 
            if( (*board).board[x][y].marker == 'o' ){
            (*board).board[x][y].marker = '-';
            }else if( (*board).board[x][y].marker == '-' ){
            (*board).board[x][y].marker = 'o';
            }else{
            // 알수 없는 오류에 의해 o - 아닌 값이 들어옴
            for(int i=0; i<99; i++){
                printf("[ERROR]\n");
            }
            }
            (*board).sizeRock++;

        }
        system("cls");
        PrintUI(*board);
        printf("<GAME END>\n");
    }
    // ===============================================================
    int main(){
        srand(time(NULL));
        // --------------------------------------------------------
        struct Board board;
        Start(&board);
        

    }// ==============================================================
    /* ---------------------------------------------------------------

    -------------------------------------------------------------------*/