#include <stdio.h>

int main() {
    int linhas;

    printf("Numero de linhas de entrada: ");
    scanf("%d", &linhas);

    for (int i = 0; i < linhas; i++) {
        int valor = 1;

        for (int j = 0; j <= i; j++) {
            printf("%d ", valor);

            valor = valor * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}