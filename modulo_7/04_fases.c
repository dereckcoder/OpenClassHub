#include <stdio.h>

int main(void){

    int idade;

    scanf("%d", &idade);
    printf("%d",idade);

    if(idade <= 12){
        printf("KIDS\n");
    }if(idade >= 13){
        printf("-jovem\n");
    }
             
    return 0;
}