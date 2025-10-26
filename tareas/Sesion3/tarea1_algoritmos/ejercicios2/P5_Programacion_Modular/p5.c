#include <stdio.h>
#include <math.h>

float calcular_potencia(float base, float exponente)
{
    return pow(base, exponente);
}

void problema5()
{
    float base, exponente, resultado;

    scanf("%f", &base);
    scanf("%f", &exponente);

    resultado = calcular_potencia(base, exponente);

    printf("%.2f\n", resultado);
}


int main(){
    problema5();
    return 0;
}
