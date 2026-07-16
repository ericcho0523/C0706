// up1093.c
#include <stdio.h>
int main() {
    int n=0;
    int t=0;
    int arr[24] = {0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        arr[t]=arr[t]+1;
    }
    for (int i = 1; i <= 23; i++) {
        printf("%d ", arr[i]);
    }
}

