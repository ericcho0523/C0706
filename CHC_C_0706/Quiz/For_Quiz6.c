// Quiz 6
#include <stdio.h>
int main() {
    int row = 5;
    int col = 5;
    for(int i=0;i<row;i++){
        if(i%2==0){
            for(int j=0;j<col;j++){
                printf("%2d ",i*10/2+j+1);
            }
        }
        else{
            for(int j=0;j<col;j++){
                printf("%2d ",5*(i+1)-j);
            }
        }
        printf("\n");


    }
}

