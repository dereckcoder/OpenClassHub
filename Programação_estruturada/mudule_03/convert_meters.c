#include <stdio.h>

int main(){
    
    float metros;

    printf("Diga o valor em metros: \n");

    scanf("%f", &metros);
    printf("Valor recebido: %.0f",metros);

    printf("\n\ndecimetros: %.0f\n",metros * 10);
    printf("centímetros: %.0f\n",metros * 100);
    printf("milimetros: %.0f\n",metros * 1000);

    return 0;
}