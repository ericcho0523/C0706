// Quiz 12
#include <stdio.h>
int main() {
    int cnt=0;
    int size=5;
    for(int i=0;i<size;i++){
        if(i%2==0){
            for(int j=0;j<size;j++){
                if(j%2==0){
                    printf("%2d ",++cnt);
                }
                else{
                    printf("   ");
                }
            }
        }
        else{
            for(int j=0;j<size;j++){
                if(j%2!=0){
                    printf("%2d ",++cnt);
                }
                else{
                    printf("   ");
                }
            }
        }
        printf("\n");
    }
}

