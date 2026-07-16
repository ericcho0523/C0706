// up1094.c
#include <stdio.h>
int main(){
    int arr[10000]= {0} ;
    int t=0;
    int n=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        arr[i]=t;
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }  
}