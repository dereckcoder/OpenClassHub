/*Exercício_04:Faça um programa que leia 10 números inteiros, armazene-os em um
vetor, solicite um valor de referência inteiro e:*/

#include <stdio.h>

int main(){
    int vetor[5];
    int maior = 0; 
    int menor = 0;
    int num_f = 10;
    int cont = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
        
        if (num_f == vetor[i]){
            cont++;
        }
    }
    printf("---------------------------\n");
    printf("A - Numeros maiores que num_F\n");

    for (int i = 0; i < 5; i++){
        maior = vetor[i];
        if (maior > num_f){
        printf("%d\n", maior);
        }
    }
    printf("---------------------------\n");
    printf("A - Numeros menores que num_F\n");

    for (int i = 0; i < 5; i++){
        menor = vetor[i];
        if (menor < num_f){
        printf("%d\n", menor);
       }
    }    
    printf("---------------------------\n");
    printf("C - num_F aparece (*vezes)vetor: %d\n", cont);
    return 0;
}