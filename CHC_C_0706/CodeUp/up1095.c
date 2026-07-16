// up1095.c
#include <stdio.h>
int main() {
    int arr[24] = {0};
    int n=0;
    int t=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        arr[t] = 1; 
    }
    for(int i=1;i<23;i++){
        if(arr[i]== 1){
        printf("%d",i);
        break;
    }
    

  }
}