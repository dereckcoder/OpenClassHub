#include <stdio.h>

int main(){

    int num;
    int teste;

    printf("Escreve o num: \n");
    scanf("%d", &num);
    teste = 10 - num;
    printf("teste: %d\n",teste);



    for (int i = 0; i <= teste; i++) {
        
        for (int j = 0; j <= 10; j++){
            printf("tabuada: %d\n", num*j);
            
            
        }
        printf("\n");   
        num++;
    }

    return 0;
}



