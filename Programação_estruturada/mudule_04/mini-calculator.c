#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    float op1, op2;
    char operador;

    printf("Entre com operações (i),(ii)e(ii)\n");

    while(scanf("%f %c %f", &op1,&operador, &op2)==3){

        switch(operador){
            case '+': printf("%f\n", op1+op2);break;
            case '-': printf("%f\n", op1-op2);break;
            case '*': printf("%f\n", op1*op2);break;
            case '/': printf("%f\n", op1/op2);break;
            default: printf("error\n");
        }
    }
    return 0;
}
