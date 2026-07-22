//ReturnEvenOdd (int n) > return Even(1) or Odd(0)
#include <stdio.h>
int ReturnEvenOdd(int n){
   if(n%2==0) return 1;
   else       return 0;;


}
int main(){
   int a=0;
   scanf("%d",&a);

   int result = ReturnEvenOdd(a);

   if(result==1){
      printf("Even");
   }
   else{
      printf("Odd");
   }
}















