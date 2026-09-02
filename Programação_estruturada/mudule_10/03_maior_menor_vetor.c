/*Exercício_03: Implemente um programa que receba valores do usuárioe 
armazene-os em um vetor. Encontre o maior, o menor, e a média dos valores.*/

#include <stdio.h>

int main(){
    int vetor[5];
    int maior = 0; 
    int menor = 0;
    int soma = 0;
    float media = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
        soma += vetor[i]; 
        
        if (i == 0){
            maior = vetor[i];
            menor = vetor[i];
        }

        else if (vetor[i] > maior){
            maior = vetor[i];

        }
        else if(vetor[i] < menor){
            menor = vetor[i];
        } 
    }   
    for (int i = 0; i < 5; i++){// print o vetor
        printf("%d\n",vetor[i]);    
    }

    media = (soma / 5.0);

    printf("Maior num é: %d\n",maior);   
    printf("Menor num é: %d\n",menor);
    printf("Media maior e menor é: %.1f\n",media);     
    return 0;
}