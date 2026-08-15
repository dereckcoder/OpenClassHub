#include <stdio.h>

int main(){
    
    float graus_f;

    printf("Digite o Fahrenheit:");
    scanf("%f", &graus_f);

    printf("Conversão em Celsius: %f\n",(graus_f-32)*(5.0/9.0));
    
    return 0;
}
