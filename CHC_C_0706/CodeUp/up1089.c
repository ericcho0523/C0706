// up1089.c
#include <stdio.h>
int main() {
    int sum=0;
    int a=0;
    int d=0;
    int n=0;

    scanf("%d %d %d", &a, &d, &n);

    for(int i=1;i<n;i++){
        sum = d*i+a;
    }
    printf("%d",sum);
}

