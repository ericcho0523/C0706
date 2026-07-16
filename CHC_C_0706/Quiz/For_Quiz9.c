// Quiz 9
#include <stdio.h>
int main() {
    int cnt = 0;
    int size = 5;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            printf(" * ");
        }
        for(int j=0;j<=i;j++){
            printf("%2d ",++cnt);
        }
        
        printf("\n");
   
    }
    
}


