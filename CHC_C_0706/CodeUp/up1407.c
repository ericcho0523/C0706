// up1407.c
#include <stdio.h>
int main(){
    char str[100]={0};
    gets(str);
    for(int i=0;i<100;i++){
        if(str[i]=='\0') break;
        if(str[i] != ' ') {
        printf("%c", str[i]);
        }
        
    }
}

