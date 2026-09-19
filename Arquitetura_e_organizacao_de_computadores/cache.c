#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void dec_para_bi(int decimal, int binario[]) {
    for (int i = 15; decimal > 0 && i >= 0; i--) {
    binario[i] = decimal % 2;
    decimal = decimal / 2;
    }
}

int main() {
    srand(time(NULL));

    int endereco = rand() % 65535;
    int binario[16] = {0};
    bool escrita_ativa = false;


    dec_para_bi(endereco, binario);

    printf("Endereço:\t");
    for (int i = 0; i < 16; i++) {
        printf("%d", binario[i]);
    }

    printf("\n");

    return 0;
}