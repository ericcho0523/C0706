// up1154.c
#include <stdio.h>
int main() 
{ 
    int a=0, b=0;
    scanf("%d %d",&a, &b);
    if(a>b){
        printf("%d",a-b);
    }
    else if(a<b){
        printf("%d",b-a);
    }
    else if(a==b){
        printf("0");
    }


}
