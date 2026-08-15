#include <stdio.h>

/*Sistema de aprovação

entradas int:
A nota: 0 a 10;
presença:0 a 100;

Condições: 
Se o aluno tiver nota 7 ou mais e frequência acima de 70 - Ele Passou
Se o aluno tiver nota 5 ou menor que 7, e frequência acima de 70 - Ele está de Exame
Se o aluno tiver nota abaixo de 5 ou frequência abaixo de 70 - Ele Reprovou
*/

int main(){

    int nota_1;
    int presenca;
    
    printf("Nota do aluno: ");
    scanf("%d",&nota_1);

    printf("\nPresenca do aluno: ");
    scanf("%d",&presenca);

    if (nota_1 <= 10 && presenca <= 100){
        
        if (nota_1 >= 7 && presenca > 70){
            printf("\nEle Passou\n");
        }
        else if (nota_1 >= 5 || nota_1 <= 7 && presenca >= 70){
            printf("\nEle está de Exame\n");
        }
        else{
            printf("Ele Reprovou\n");
        }
    } else{
        printf("\nENTRADA INVALIDA: RESERT PROGRAMA\n");
    }
    return 0;       
    } 

    
