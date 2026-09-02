/*Exercício_02:Implemente um programa que imprima ao contrário um vetor preenchido*/

#include <stdio.h>

int main(){

    int num[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d",&num[i]);
    }
    printf("imprima na tela\n");
    
    for (int i = 5; i >= 0; i--){
        printf("%d\n",num[i]);
    }

    return 0;

}