// Quiz 5
#include <stdio.h>
int main() {
    int row=5, col=5;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%2d ",-5*j-i+25);
        }
        printf("\n");
    }
}