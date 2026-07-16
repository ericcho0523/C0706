// up1078.c
#include <stdio.h>
int main() {
    int sum = 0;
    int a = 0;
    scanf("%d",&a);

    for(int b=1;b<=a;b++){
        if(b%2==0){
            sum = sum + b;
        } 
    }
    printf("%d", sum);   
}

