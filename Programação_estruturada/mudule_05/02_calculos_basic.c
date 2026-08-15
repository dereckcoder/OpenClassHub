#include <stdio.h>
/*
1. A soma
2. A diferença
3. O produto
4. O quociente inteiro
5. O resto da divisão */
int main(){
    
    int num_01;
    int num_02;

    printf("\nDigita num_01:");
    scanf("%d",&num_01,"\n");

    printf("\nDigita num_02:");
    scanf("%d",&num_02,"\n");
    
    printf("\n%d",num_01+num_02);
    printf("\n%d",num_01-num_02);
    printf("\n%d",(float)num_01*num_02);
    printf("\n%d",num_01%num_02);

    return 0;
}

