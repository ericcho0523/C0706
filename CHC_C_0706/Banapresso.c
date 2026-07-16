// Banapresso ex
#include <stdio.h>
int main ()
{
    printf("------------\n");
    printf(" > [1] : Recommand\n");
    printf(" > [2] : All\n");
    printf(" > [3] : Bundle\n");
    printf("------------\n");
    int menu = 0;
    printf("Enter the menu : ");
    scanf("%d", &menu);
   
    if(menu==1) {
        printf(" > [1] : Americano\n");
        printf(" > [2] : Cookie\n");
        printf(" > [3] : Muffin\n");

        int menu1 = 0;
        printf("Enter the menu number : ");
        scanf("%d", &menu1);
        if(menu1 == 1){
            printf("Your menu is Americano\n");
        }
        else if(menu1 == 2){
            printf("Your menu is Cookie\n");
        }
        else if(menu1 == 3){
            printf("Your menu is Muffin\n");
        }
        
    }
    else if(menu == 2) {
         printf(" > [1] : Smoothie\n");
         printf(" > [2] : Yogurt\n");
         printf(" > [3] : Ice tea\n");

         int menu2 = 0;
        printf("Enter the menu number : ");
        scanf("%d", &menu2);
        if(menu2 == 1){
            printf("Your menu is Smoothie\n");
        }
        else if(menu2 == 2){
            printf("Your menu is Yogurt\n");
        }
        else if(menu2 == 3){
            printf("Your menu is Ice tea\n");
        }


    }
    else if(menu == 3){
        printf(" > [1] : Sandwich\n");
        printf(" > [2] : Ham sandwich\n");
        printf(" > [3] : Bacon sandwich\n");

        int menu3 = 0;
        printf("Enter the menu number : ");
        scanf("%d", &menu3);
        if(menu3 == 1){
            printf("Your menu is Sandwich\n");
        }
        else if(menu3 == 2){
            printf("Your menu is Ham sandwich\n");
        }
        else if(menu3 == 3){
            printf("Your menu is Bacon sandwich\n");
        }


    }
    else {
        printf("Error\n");
    }


}


