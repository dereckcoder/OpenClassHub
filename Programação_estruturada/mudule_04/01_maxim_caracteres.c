#include <stdio.h>


int main(){

    char frase[50];

    fputs("frase:",stdout);
    fgets(frase,50,stdin);
    
    fputs("\ndigitado: ", stdout);
    fputs(frase,stdout);

    return 0;
}