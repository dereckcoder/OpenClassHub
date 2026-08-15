#include <stdio.h>
/*
1. 10 + 20 * 3
2. (10 + 20) * 3
3. 10 / 3
4. (float)10 
5. 17 % 4 
*/ 
int main(){

    // Primeiro metodo em variaveis
    int num = 10;
    int num_2 = 20;
    int num_3 = 3;
    
    int result = num + num_2 * num_3;
    
    printf("\nresultado:%d \n", result);

    // metodo direto no printf
    printf("%d\n",(10+20)*2);
    printf("%d\n",10 / 3);
    printf("%f\n",10 / 3);
    printf("%f\n",10%4);

    return 0;
}


