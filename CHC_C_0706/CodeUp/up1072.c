// up1072.c
#include <stdio.h>
int main() {
    int a=0;
    scanf("%d",&a);

    for(int i=1;i<=a;i++){
        int b=0;
        scanf("%d",&b);
        printf("%d\n",b);

    }

     

}

// 해설
// 숫자 n개 입력 -> n번 반복
// 입력된 정수 출력
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        printf("%d ",temp);
    }


}
