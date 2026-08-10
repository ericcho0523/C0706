// up1714.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 100000
char stack[MAXSIZE];
int top = -1; 

void Push(char data){
    if (top >= MAXSIZE - 1){
        return;
    }
    stack[++top] = data;
}
int main(){
    char str[MAXSIZE];
    if (scanf("%99999s", str) != 1) {
        return 0;
    }
    int len = strlen(str);

    for(int i=0;i<len;i++){
        Push(str[i]);
    }
    for(int i=0;i<len;i++){
        printf("%c", stack[top--]);
    }
    printf("\n");
    return 0;
} 