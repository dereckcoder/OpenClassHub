#include <stdio.h>

int main() {

    int numero = 1;
    int soma = 0;
    int cont = 0;

    while (numero != 0) {

        printf("Digite: ");
        scanf("%d", &numero);

        if (numero % 2 == 0 && numero != 0) {
            soma += numero;
            cont++;
        }
    }

    if (cont > 0)
        printf("Media: %.2f\n", (float)soma / cont);

    return 0;
}