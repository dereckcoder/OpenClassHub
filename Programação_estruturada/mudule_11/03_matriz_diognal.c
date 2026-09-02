/*Exercício_03:Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 
0 os demais elementos. Escreva ao final a matriz obtida.*/
 
#include <stdio.h>
 
int main(){
    int tamanho = 10;
    int matriz[tamanho][tamanho];
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if(i == j) {
                matriz[i][j] = 1;
            } else {
            matriz[i][j] = 0;
            }
            printf("%d ", matriz[i][j]);    
        }
    printf("\n");
    }
    return 0;
}