// InitMultiAry  넘겨받은 이차원배열에 1부터 순서대로 값을 저장
// PrintMultiAry 넘겨받은 이차원배열의 모든 요소를 출력
// InitRandomMultiAry 넘겨받은 이차원배열에 랜덤으로 값을 저장 ( 이때 배열 최대 크기 기준으로 Max설정 )
// MakeDouble 넘겨받은 이차원배열의 모든 요소를 2배로 만들어 출력
// PrintReverseMultiAry 넘겨받은 이차원배열의 모든 요소를 거꾸로 출력
// AverageMultiAry 넘겨받은 이차원 배열의 전체 평균값을 계산해서 출력
// AverageMultiAryRow 넘겨받은 이차원 배열의 각 행의 평균값을 계산해서 각각 출력
// MergeMultiAry 넘겨받은 이차원 배열을(두 배열은 같다고 가정) 합친 결과를 출력
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void InitMultiAry(int ary[][10], int row){
   int cnt=0;
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         ary[i][j] = ++cnt;
      }
   }
}
void PrintMultiAry(int ary[][10], int row){
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         printf("%2d ",ary[i][j]);
      }
      printf("\n");
   }
}
void InitRandomMultiAry(int ary[][10], int row){
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         ary[i][j] = rand()%99+1;
      }
   }
}
void MakeDouble(int ary[][10], int row){
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         ary[i][j] *= 2;
      }
   }
}

void PrintReverseMultiAry(int ary[][10], int row){
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         int rev = ary[row-1-i][10-1-j];
         printf("%2d ",rev);
      }
   }
}
void AverageMultiAry(int ary[][10], int row){
   int aver = 0;
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         aver += ary[i][j];
      }
   }
   printf("%.2f",(double)aver/100);
}

void AverageMultiAryRow(int ary[][10], int row){
   for(int i=0;i<row;i++){
      int aver = 0;
      for(int j=0;j<10;j++){
         aver += ary[i][j];
      }
      printf("Row %d Average : %.2f\n", i, (double)aver/10);
   }
}
void MergeMultiAry(int ary[][10], int row){
   for(int i=0;i<row;i++){
      for(int j=0;j<10;j++){
         ary[i][j] = ary[i][j] + ary[i][j];
         printf("%2d ",ary[i][j]);
      }
      printf("\n");
   }

}

int main(){
   int ary[10][10] = {0};
   InitMultiAry(ary,10);
   PrintMultiAry(ary,10);
   InitRandomMultiAry(ary,10);
   MakeDouble(ary,10);
   PrintReverseMultiAry(ary,10);
   AverageMultiAry(ary,10);
   AverageMultiAryRow(ary,10);
   MergeMultiAry(ary,10);
}


























