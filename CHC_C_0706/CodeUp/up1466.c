// up1466.c
#include <stdio.h>
int main(){
int mat[100][100]={0};
int n=0, m=0;
scanf("%d %d",&n, &m);
int c = n*m ;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        mat[i][j] = c - i - n*j;
        printf("%d ",mat[i][j]);
    }
    printf("\n");
  }


}