// up1206.c
#include <stdio.h>
int main()
{
    int a=0, b=0;
    scanf("%d %d",&a, &b);
    if(b%a == 0){
        printf("%d*%d=%d",a,b / a,b);
    }
    else if(a%b == 0){
        printf("%d*%d=%d",a,b / a,b);
    }
    else{
        printf("none");
    }
}







