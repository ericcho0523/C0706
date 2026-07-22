// up1370.c
#include <stdio.h>
int main() {  
    int h=0;
    int r=0;
    scanf("%d %d", &h,&r);
    for(int i=0;i<r;i++){

     for(int i=0; i<h; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }    
        printf("*\n");
        }
     for(int i=0;i<h-1;i++){
        for(int j=h-i-3;j>=0;j--){
            printf(" ");
        }
        printf("*\n");

       }

    }

}



    
