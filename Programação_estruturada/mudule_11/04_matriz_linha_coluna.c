/*Exercício_04:Leia uma matriz 4 x 4, imprima a matriz e retorne a localização (linha e 
coluna) do maior valor.*/
 
#include <stdio.h>

int main(){
    int linha;
    int coluna;
    int maior = 0;
    int matriz[4][4] = {
        {1, 8, 1, 20},  
        {1, 8, 2, 30},  
        {6, 70, 3, 40},
        {6, 7, 3, 0}
    };
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
                coluna = j;
                linha = i;
            }
        }
        printf("\n"); 
    }
    printf("%d\n", maior);
    printf("%d\n", coluna);
    printf("%d\n", linha);
    return 0;
}