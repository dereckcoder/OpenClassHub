#include <stdio.h>
/* Manipulacao espaçamento
1.  Nome completo
2.  Endereço
3. Telefone
Saida: Exiba todos os dados em uma única linha separados por " | ".
*/
int main(){

    char* name[50];
    char address[50];
    int telephone;

    printf("\nHELLO, main friend!");

    printf("\nname: ");
    scanf("%s", &name);
  
    printf("address: ");
    scanf("%s", &address);

    printf("telephone: ");
    scanf("%d", &telephone);

    printf("\n%s|%s|%d\n",name,address,telephone);

    return 0;
}