#include <stdio.h>

/*diga se ele está entre 10 e 50 (inclusive).*/

int main(){

    int num = 50;
    printf("Seu numero é %d",num);

    if (num >= 10 || num == 50){
        printf("\nEstá entre 10 e 50, uhuhu\n");
    }    
    else{
        printf("\nNão está entre 10 a 50\n");
    }
return 0;
}