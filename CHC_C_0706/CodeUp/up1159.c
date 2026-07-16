// up1159.c
#include <stdio.h>
int main() 
{ 
    int a=0;
    scanf("%d",&a);
    if(a>=50 && a<=70) {
        printf("win");
    }
    else if(a%6 == 0) {
        printf("win");
    }
    else{
        printf("lose");
    }


}

