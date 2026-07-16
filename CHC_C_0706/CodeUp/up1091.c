// up1091.c
#include <stdio.h>
int main() {
    long long a=0;
    int m=0;
    int d=0;
    int n=0;
    scanf("%lld %d %d %d", &a, &m, &d, &n);

    for(int i=1;i<n;i++){
        a=a*m;
        a=a+d;
    }

    printf("%lld",a);

}


