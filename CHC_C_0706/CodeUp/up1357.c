// up1357.c
#include <stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=0;i<n-1;i++){
        for(int j=n-2-i;j>=0;j--){
            printf("*");
        }
        printf("\n");
    }
}

