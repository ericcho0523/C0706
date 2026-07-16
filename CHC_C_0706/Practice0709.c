#include <stdio.h>
int main() {

int col=7;
int row=10;


    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%2d ",1+j+ col*i);
        }
        printf("\n");
    
}
}

