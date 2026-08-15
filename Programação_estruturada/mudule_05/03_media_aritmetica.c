#include <stdio.h>

//media aritmética 3 valores//

int main(){

    int num_01;
    int num_02;
    int num_03;

    printf("\n Vamos Calcular a media aritmética");
    printf("\n");   
    
    printf("\n num_01: ");
    scanf("%d", &num_01);
    
    printf("\n num_02: ");
    scanf("%d", &num_02);

    printf("\n num_03: ");
    scanf("%d", &num_03);

    printf("\n%f\n",(float)(num_01+num_02+num_03) / 3);

    return 0;
}
