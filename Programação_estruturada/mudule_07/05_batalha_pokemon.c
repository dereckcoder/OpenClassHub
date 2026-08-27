#include <stdio.h>

int main(){

    int escolha;

    printf("escolhe um Pokémon 1,2,3:\n");
    printf("1 - Charmander 🔥\n\n");
    printf("2 - Squirtle 💧\n");
    printf("3 - Bulbasaur 🌱\n");
    
    printf("Escolha: \n");
    scanf("%d", &escolha);   


    if(escolha == 1){
        printf("Se o usuário for Squirtle - Você venceu!\n");
      
    }else if(escolha == 2){
      printf("Se for Bulbasaur - Você perdeu!\n");
    }else if(escolha == 3){
        printf("Se for Charmander - Empate!\n");
    }else{
        printf("num errado\n");
    }
    return 0;
}