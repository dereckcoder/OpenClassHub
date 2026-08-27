#include <stdio.h>
#include <string.h>


int main(void){

    char escolha[20];

    printf("escolha, agua coca-cola ou guarana\n");
    scanf("%s", &escolha);
    printf("%s",escolha);

    if(strcmp("agua",escolha) == 0){
        printf("parabens,{escolha}");
    }
    else{
        printf("escolha errada\n");
    }
    return 0;
}
