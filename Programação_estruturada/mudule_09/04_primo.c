#include <stdio.h>

int main() {
    int numero, primo = 1;

    printf("Insira um numero: ");
    scanf("%d", &numero);

    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            primo = 0;
        }
    }

    if (primo == 1) {
        printf("%d e um numero primo\n", numero);
    } else {
        printf("%d nao e um numero primo\n", numero);
    }

    return 0;
}