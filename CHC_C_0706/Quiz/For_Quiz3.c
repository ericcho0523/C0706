// Quiz 3
#include <stdio.h>
int main() {
    int row = 5;
    int col = 5;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%2d ",25-j-5*i);
        }
        printf("\n");

    }
}

