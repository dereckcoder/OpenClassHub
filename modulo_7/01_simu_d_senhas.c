#include <stdio.h>

int main(void){

    int password =1234;
    int password_teste;


    printf("Digite password: \n");
    scanf("%d", &password_teste);

    if(password == password_teste){
        printf("acerto men");
    }else{
        printf("error");
    }

    return 0;

}