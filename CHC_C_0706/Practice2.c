// Practice2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

// 숫자 넘겨주면, 배열 만들어주는 MakeAry 함수를 제작
// 이후, 해당 숫자만큼 배열에 랜덤값 1~9 넣어주기
int* MakeAry(int size){
   int* temp = (int*)malloc(size *sizeof(int));
   for(int i=0;i<size;i++){
      temp[i] = rand()%9+1;
   }
   return temp;

}

// 배열과 숫자 넘겨받아 모든 배열요소를 출력하는 PrintAry 함수 제작
void PrintAry(int ary[], int size){
   printf("------------------\n");
   for(int i=0;i<size;i++){
      printf("%d ", ary[i]);
   }  printf("\n");
   printf("------------------\n");
}
//  GetRandAry10은, size가 10인 int형 배열의 랜덤값이
// 10칸에 모두 1~9가 들어가있는 배열을 리턴하는 함수
int* GetRandAry10(){
   int* ary2 = (int*)malloc(10 * sizeof(int));
   for(int i=0;i<10;i++){
      ary2[i]=rand()%9+1;
   }  
   return ary2;
}
// InitAry는 넘겨받은 포인터 변수와 사이즈를 이용해
// 새로운 배열을 만들어 메인의 원본에 넣어주는 함수
void InitAry(int** dptr,int size){
   int* temp = (int*)malloc(size*sizeof(int));
   for(int i=0;i<size;i++){
      temp[i]=rand()%9+1;
   }
   *dptr = temp;
}
// 메인의 포변의 주소와 사이즈를 받아서, 해당 원본에
// size만큼의 배열을 만들어 1부터 숫자를 채워주는
// InitAry2 함수를 만드세요.
void InitAry2(int** dptr, int size){
   int* temp = (int*)malloc(size*sizeof(int));
   for(int i=0;i<size;i++){
      temp[i] = i+1;
   }
   *dptr = temp;
   PrintAry(*dptr,20);
}

// SetAry는 넘겨받은 포인터 변수와 사이즈를 이용해
// 새로운 배열을 만들어 메인의 원본에 넣어주는 함수
// 단, 이미 해당 배열에 이미 다른 배열이 있다면
// 없애버린 후 새로 할당하도록 하세요.
void SetAry(int** dptr, int size){
   // 만약, 아무것도 없었다면, NULL이 있을거임
   if(*dptr==NULL){
      int* temp = (int*)malloc(size*sizeof(int));
      for(int i=0;i<size;i++){
      temp[i] = i+1;
     }
     *dptr = temp;
   }
   else{
      free((*dptr));
      *dptr = NULL;
      int* temp = (int*)malloc(size*sizeof(int));
      for(int i=0;i<size;i++){
      temp[i] = i+1;
     }
     *dptr = temp;

   }

}

int main(){
   srand(time(NULL));
   // ----------------------------------------------
   // 외부에서 배열 만들어 넘겨주기 
   int size = 10;
   int* ary = MakeAry(size);
   PrintAry(ary,size);

   GetRandAry10();

   int* ary2;
   InitAry(&ary2,10);
   PrintAry(ary2,10);

   InitAry2(&ary2,20);


   



    
}