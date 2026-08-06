#include <stdio.h>

int main(){

    int num;
    int test;

    printf("Escreve o num: \n");
    scanf("%d", &num);
    test = 10 - num;

    printf("teste: %d\n",test);
    
    for (int i = 0; i <= test; i++) {

        for (int j = 0; j <= 10; j++){
            printf("tabuada: %d\n", num*j);
        }
        printf("\n");   
        num++;
    }
    return 0;
}



