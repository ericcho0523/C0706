// up1090.c
#include <stdio.h>
int main() {
    
    long long a=0;
    int r=0;
    int n=0;
    

    scanf("%lld %d %d", &a, &r, &n);

    for(int d=1;d<n;d++){
        
        a = a*r;

    }
    printf("%lld",a);
}


