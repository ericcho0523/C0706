// CPP00_Random.cpp
#include <iostream>
#include <stdio.h>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    // 1. random 모듈 : C++11이상
    // 하드웨어 기반, 정밀한 랜덤
    random_device rd; // 하드웨어 시드 생성기
    mt19937 gen(rd()); // 난수 엔진에 시드 생성기 넣기.
    uniform_int_distribution<int> cppRand(1,10);
    for(int i=0; i<10; i++){
        cout << cppRand(gen) << " ";
    }   cout << endl;



    
    // ---------------
    // stdlib의 rand 모듈(0~32767)
    srand(time(NULL)); // 매번마다 랜덤 섞기
    printf("\n------------\n");
    for(int i=0;i<10;i++){
        // 1~10
        printf("%d ", rand()%10+1);
    }   printf("\n");
    // -------------------
    // 기존보다 더 좋은 옵션 뜨는 경우 많았음
    // 


}