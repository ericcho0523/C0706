// CDS12_HashBasic.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define SIZE 100
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct{
    int id;
    char name[100];
    int score;
    char gender;
}Student;
// ===============================================================
// < 전 역 변 수 >
// ===============================================================
Student* hashTable[SIZE]; // 포인터배열 100개
// ===============================================================
// < 전 역 함 수 >
// ===============================================================
void InitStudent(Student* s){
    static int studentNumber = 20260001;
    char nameList[10][100]={"KDS","NDS","JBY","KBM","KMJ","AEJ","KSL","AAA","BBB","CCC"};
    // 데이터 삽입
    s->gender = rand()%2==0 ? 'F' : 'M';
    s->id = studentNumber++;
    strycpy(s->name ,nameList[rand()%10]);
    s->score = rand()%101; // 0~100
}
void PrintStudent(Student* s){
    printf("--------------\n");
    printf(" > ID : %d\n",s->id);
    printf(" > NAME : %s\n",s->name);
    printf(" > GENDER : %c\n",s->gender);
    printf(" > SCORE : %d\n",s->score);
    printf("--------------\n");
}
// ===============================================================
int main(){
    srand(time(NULL));
    Student stu[10];
    for(int i=0;i<10;i++) InitStudent(&stu[i]);
} // ===============================================================

