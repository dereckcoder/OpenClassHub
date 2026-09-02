/*Exercício_05:Dada uma matriz A inicializada de reais, e um vetor V incializado de 
numeros reais, determine o produto de A por V*/

#include <stdio.h>
 
int main(){
    int produto_m;
    int produto_v;
    int resultados = 0 ;
    int matriz_a[4][4] = {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,99}
    };
    int vetor_v[4] = {10,20,30,40};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ",matriz_a[i][j]);
            produto_m = matriz_a[i][j];
            produto_v = vetor_v[i];
            resultados = produto_m * produto_v;

        }
        printf("\n");
        printf("vetor_V: %d\n",vetor_v[i]);
    }
    printf("esse valor produto%d\n", resultados);
 
    return 0;
}