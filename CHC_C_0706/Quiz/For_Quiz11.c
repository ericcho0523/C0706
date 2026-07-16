// Quiz11
#include <stdio.h>
int main() {
    int cnt=0;
    int size=5;
    for(int i=0;i<size;i++){
        if(i%4==0){
            for(int j=0;j<size;j++){
                printf("%2d ",++cnt);
            }
        }
        else{
            for(int j=0;j<size-i-1;j++){
                printf("   ");
            }
            printf("%2d ",++cnt);

        }
        printf("\n");
    }
}

