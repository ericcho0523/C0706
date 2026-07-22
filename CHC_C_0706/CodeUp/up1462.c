// up1462.c
#include <stdio.h>
int main(){
int mat[100][100]={0};
int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        mat[i][j]= i+1+n*j;
        printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
}
