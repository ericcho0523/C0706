// up1358.c
#include <stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n/2+1;i++){
        for(int j = 0; j < n / 2 - i; j++) {
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        printf("\n");
    }

}