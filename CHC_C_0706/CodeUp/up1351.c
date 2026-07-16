// up1351.c
#include <stdio.h>
int main(){
    int a=0;
    int b=0;
    int mul=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<b+1;i++){
        for(int j=1;j<10;j++){
            mul=i*j;
            printf("%d*%d=%d\n",i,j,mul);
        }
    }


}