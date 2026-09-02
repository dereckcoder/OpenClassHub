/*Exercício_1:Escreva um programa em C para calcular a soma dos 10 primeiros números
naturais*/



#include <stdio.h>

int main(){

    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int adic;
    int soma;

    for (int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
        soma += num[i];

    }printf("soma: %d\n", soma);
return 0;
}
