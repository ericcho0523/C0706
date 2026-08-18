// CDS11_SearchStruct.c
// 구조체의 정렬과 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct MidSchool{
    int id;
    int score;
    char gender;
}MidSchool;
// ===============================================================
// < 전 역 함 수 >
// ===============================================================
void InitSchool(MidSchool* mid, int size){
    // x개는 1부터, y까지 500부터, z까지 1000부터, 나머지 1500
    int x = 200, y = 576, z= 843;
    for(int i=0;i<x;i++){
        mid[i].gender = 'F';
        mid[i].id = i+1;
        mid[i].score = rand()%100+1; // 1~100
    }
    for(int i=x;i<y;i++){
        mid[i].gender = 'M';
        mid[i].id = i+500-y;
        mid[i].score = rand()%100+1; // 1~100
    }
    for(int i=y;i<z;i++){
        mid[i].gender = 'F';
        mid[i].id = i+1000-y;
        mid[i].score = rand()%100+1; // 1~100
    }
    for(int i=z;i<size;i++){
        mid[i].gender = 'M';
        mid[i].id = i+1000-z;
        mid[i].score = rand()%100+1; // 1~100
    }
}

// 수동검색 - 아주 큰 문제.... 선형 검색밖에 못함 ㅠㅠ
void SimpleSearch(MidSchool* mid, int size, int targetID){
    // targetID에 대한 id, gender, score, 출력. 없으면 없다고
    for(int i=0;i<size;i++){
        if(mid[i].id == targetID){
            printf("------------------\n");
            printf("ID : %d\n",mid[i].id);
            printf("GENDER : %d\n",mid[i].gender);
            printf("SCORE : %d\n",mid[i].score);
            printf("------------------\n");
            return;
        }
    }
    printf("Target(%d) is not found\n", targetID);
}

// 수동정렬
void SimpleSort(MidSchool* mid, int size){
    // 내림차순 정렬 고정
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(mid[j].score < mid[j+1].score){
                MidSchool temp = mid[j];
                mid[j] = mid[j+1];
                mid[j+1] = temp;
            }
        }
    }

}

// 이진검색
MidSchool* BinarySearch(MidSchool* mid, int size, int target){
    int left = 0;
    int right = size-1;
    // -------------------------------------------------------
    for(;1;){
        if(right<left){
            printf("Not Found\n");
            return NULL;
        }
        int m = (left+right)/2;
        if(mid[m].score == target ){
            return &mid[m];
        }
        else if(mid[m].score > target){ // 내림차순기준
            left = m+1;
        }
        else{
            right = m-1;
        }
    }
}

// ===============================================================
int main(){
    srand(time(NULL));
    MidSchool stu[1000]={0};
    InitSchool(stu,1000);
    SimpleSearch(stu, 1000, 30);
    SimpleSort(stu,1000); // 내림차순
    for(int i=0;i<1000;i++){
        printf("%d(%d) ",stu[i].id, stu[i].score);
    }
    MidSchool* temp = BinarySearch(stu,1000,3);
    printf("TARGET ID : %d\n",temp->id);
    printf("TARGET GENDER : %d\n", temp->gender);
    printf("TARGET SCORE : %d\n", temp->score);
} // ===============================================================