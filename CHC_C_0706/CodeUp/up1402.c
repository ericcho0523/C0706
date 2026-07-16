// up1402.c
#include <stdio.h>
int main(){
    int arr[1000]={0};
    int n=0;
    int a=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        arr[i]=a;
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }

}