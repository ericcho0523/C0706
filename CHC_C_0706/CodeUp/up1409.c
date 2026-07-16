// up1409.c
#include <stdio.h>
int main(){
    int arr[10]={0};
    int n=0;
    int k=0;
    for(int i=0;i<10;i++){
        scanf("%d",&n);
        arr[i]=n;
    }
    scanf("%d",&k);
    printf("%d",arr[k-1]);

}