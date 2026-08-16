#include <stdio.h>
/*Leia nome e três notas de um aluno e exiba uma tabela como:
Nome N1 N2 N3 Média
João 8.0 7.5 9.0 8.1.
*/
int main(){

    char* name = "Mario";
    float n1=8.0,n2=7.5,n3=9.0,result;

    result = (n1 + n2 + n3) / 3; 

    printf("\nname:  N1  N2  N3 MEDIA\n");
    printf("%s %.1f %.1f %.1f %.2f\n",name,n1,n2,n3,result);

    return 0;
}