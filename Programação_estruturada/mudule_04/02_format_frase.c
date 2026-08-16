#include <stdio.h>


int main(){

    char frase[50];

    fputs("frase:",stdout);
    fgets(frase,50,stdin);

    printf("*************************");
    fputs("\n", stdout);
    fputs(frase,stdout);
    printf("*************************");

    return 0;
}