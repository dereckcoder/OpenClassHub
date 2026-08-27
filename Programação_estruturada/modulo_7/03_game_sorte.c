#include <stdio.h>


int main(){

    int num;

    printf("digite o num\n");
    scanf("%d", &num);


    if(num == 7){
        printf("Num sorte\n");
    
    } else if(num % 2 == 0){
        printf("é par\n");
    }else{
        printf("nao foi dessa vez\n");
}

return 0;        
}