// up1096.c
#include <stdio.h>
int main(){
    int mat[20][20]={0};
    int n=0;
    int x=0, y=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        mat[x][y]=1;
    }
    for(int i=1; i<=19; i++){
      for(int j=1; j<=19; j++) {
      printf("%d ", mat[i][j]); 
      }
      printf("\n"); 
    }

}
