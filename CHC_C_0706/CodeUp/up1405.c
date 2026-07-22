// up1405.c
#include <stdio.h>
int main(){
    int mat[100][100]={0};
    int n=0;
    int k=0;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        scanf("%d",&k);
        mat[0][j]=k;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            mat[i+1][j]=mat[i][j+1];
        }
        mat[i+1][n-1]=mat[i][0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}




