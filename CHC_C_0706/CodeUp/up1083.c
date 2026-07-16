// up1083.c
#include <stdio.h>
int main(){
    int a = 0;
    scanf("%d",&a);

    for (int b=1;b<=a;b++){
        if(b%3!=0){
            printf("%d ",b);
        }
        else{
            printf("%c ",'X');
        }
        
    }


}

