#include <stdio.h>

int main(){
    int n;
    int soma = 0;
    
    printf("Digite um numero positivo para ser somado ou negativo para sair: ");
    scanf("%d", &n);
    
    while( n >= 0 ){
        printf("Digite um numero positivo para ser somado ou negativo para sair: ");
        scanf("%d", &n);
        soma = soma + n;
        printf("A soma eh %d\n", soma);
    }
    
        return 0;
}