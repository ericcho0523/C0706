// C13_Pointer3.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 함수 자리 >
// ===============================================================
void Change(int* a, int* b){
    int temp;
    temp = *a;
    *a= *b;
    *b = temp;
}
void PrintXY(int x, int y){
    printf("Before x:%d, y:%d\n",x,y);
}
void InitXY(int* x, int* y){
    *x = 10;
    *y = 20;
}
void Start(int *x, int* y){
    InitXY(x,y);
    PrintXY(*x,*y);
    Change(x, y);
    PrintXY(*x,*y);
    
}
// ===============================================================
int main(){
    srand(time(NULL));
    int x,y;
    InitXY(&x,&y);
    Start(&x,&y);

}// -=============================================================
/* ---------------------------------------------------------------

*/  // --------------------------------------------------------------