#include <stdio.h>

int main() {
    int num;
    int maior = 0; 
    

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &num);


        if (maior < num) {
            printf("foi\n");
            maior = num; 
            printf("%d foigente\n", maior);
        }

        if (menor < maior){

            menor = num;

        }
    }

    printf("O maior numero digitado foi: %d\n", maior);
    return 0;
}
