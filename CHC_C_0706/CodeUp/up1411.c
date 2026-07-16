// up1411.c
#include <stdio.h>
int main(){
    int arr[51]={0};
    int n=0;
    int t=0;
    scanf("%d",&n);

    for(int i=0;i<n-1;i++){
        scanf("%d",&t);
        arr[t]=1;
    }
    for(int i=1;i<n+1;i++){
        if(arr[i]!=1){
            printf("%d",i);
        }
    }

}