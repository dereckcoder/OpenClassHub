/*1 - Exercício 01) Implemente um programa em C que tenha uma matriz e imprima o valores dela na tela*/
 
#include <stdio.h>
 
int main(){

 
    int matriz[3][3] = {
        {9, 8, 1},  
        {7, 8, 2},  
        {6, 7, 3}
    };
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }printf("\n"); 
    }

    return 0;
}