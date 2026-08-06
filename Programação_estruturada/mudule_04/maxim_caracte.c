#include <stdio.h>


int main(){
    
    char frase[50];
    printf("Leia a frase secreta: \n");
    fgets(frase,50,stdin);

    printf("%s\n",frase);
    return 0;
}