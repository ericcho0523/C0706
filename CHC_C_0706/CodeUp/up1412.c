// up1412.c
#include <stdio.h>
int main(){
    char str1[90] = {0};
    int count[26] = {0};
    scanf("%[^\n]",str1);

    for(int i=0;str1[i]!='\0';i++){
        if(str1[i]>=97 && str1[i]<=122){
            count[str1[i]-'a']++;
        }
    }

    for(int i=0;i<26;i++){
        printf("%c:%d\n", 'a'+ i,count[i]);
    }
}


