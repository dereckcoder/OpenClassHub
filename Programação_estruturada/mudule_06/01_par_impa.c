#include <stdio.h>

/*Programa que confere
se um número é impar ou par;*/

int main(){

    int idade = 3;

    if (idade % 2 == 0){
        printf("\né par\n");
    }
    else{
        printf("\né impar\n");
    }
    return 0;
}