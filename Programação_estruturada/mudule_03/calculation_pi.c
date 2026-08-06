#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(){

    int raio;
    float perim, area;

    printf("Entre com o valor do raio: ");
    scanf("%d", &raio);

    perim = 2 * PI * raio;
    area = PI * pow(raio, 2);
    
    printf("O perimetro é %.2f e a área é %.2f \n", perim, area);

    return 0;
}
