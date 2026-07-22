// up1425.c
#include <stdio.h>
int main(){
    int n,c; // 학생 수 자릿수
    scanf("%d %d",&n, &c);
    int ary[100]={0};
    for(int i=0;i<n;i++)
      scanf("%d", &ary[i]);
    
    
    // ------------------------------
    // 1.정렬
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i; j++){
            if(ary[j] > ary[j+1]){
                int temp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = temp;
            }
        }
    }
    // -------------------------------
    // 2.c개만큼 끊어서 출력
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==c){
            printf("\n");
            cnt=0;
        }
        printf("%d ", ary[i]);
        cnt++;

    }

}