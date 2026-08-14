#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    float soma = 0;
    for(int i = 1; i < argc; i++)
    {
        // printf("%f\n", atof(argv[i]));
        soma = (soma + atof(argv[i]));
    }
    float media = soma / (argc - 1);
    printf("%f\n", media);
}
