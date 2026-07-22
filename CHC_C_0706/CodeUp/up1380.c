// up1380.c
#include <stdio.h>
int main(){
    int k=0;
    scanf("%d",&k);
    for(int i=1;i<k&&i<=6;i++){
        for(int j=k-i;j>=1&&j<=6;j--){
            printf("%d %d\n", i,j);
            break;
        }
    }
}
