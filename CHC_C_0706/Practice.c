// 두개의 문자열을 입력받은 후, 다른 문자열 배열에 두 문자열을 합친 후 출력하세요.
#include <stdio.h>
#include <string.h>
int main()
{
   char str1[100] = {0};
   char str2[100] = {0};
   printf("Enter String1 : ");
   scanf("%s",&str1);
   printf("Enter String2 : ");
   scanf("%s",&str2);

   int str1Size = strlen(str1);
   for(int i=0;i<strlen(str2);i++){
        str1[str1Size+i] = str2[i];
   }
   printf("%s",str1);
   
}













