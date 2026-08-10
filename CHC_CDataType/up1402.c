// up1402.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 1000

int stack[MAXSIZE]; 
int top = -1; 

void Push(int data) {
    if (top >= MAXSIZE - 1) {
        return;
    }
    stack[++top] = data;
}

int main() {
    int a = 0, b = 0;
    if (scanf("%d", &a) != 1) {
        return 0;
    }
    if (a > MAXSIZE) {
        a = MAXSIZE;
    }
    for (int i = 0; i < a; i++) {
        scanf("%d", &b);
        Push(b);
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[top - i]);
    }
    printf("\n");
    return 0;
} // ===============================================================
