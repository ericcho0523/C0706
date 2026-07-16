// up1088.c
#include <stdio.h>
int main() {
    int a=0;
    scanf("%d",&a);

    for(int b=0;b<=a;b++){
        if(b%3!=0){
            printf("%d ",b);
        }
    }
}

