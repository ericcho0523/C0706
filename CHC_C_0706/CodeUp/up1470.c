// up1470.c
#include <stdio.h>
int main(){
int mat[100][100]={0};
int n=0;
scanf("%d",&n);

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       if(j%2==0){
        mat[i][j]=j*n+i+1;
        printf("%d ",mat[i][j]);
       }
       else{
        mat[i][j]=n*(j+1)-i;
        printf("%d ",mat[i][j]);
       }
    }
    printf("\n");
 }

}