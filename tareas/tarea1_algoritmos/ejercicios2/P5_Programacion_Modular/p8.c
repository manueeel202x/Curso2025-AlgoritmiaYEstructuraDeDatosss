#include <stdio.h>
#include <math.h>

double calcular_potencia(double base, double exponente)
{
    return pow(base, exponente);
}

void problema8()
{
    int i;
    double Y, X, Z;

    for (i = 1; i <= 10; i++)
    {
        scanf("%lf", &Y);
        scanf("%lf", &X);

        Z = calcular_potencia(Y, X);

        printf("Par %d: Y=%.2f, X=%.2f, Z=%.2f\n", i, Y, X, Z);
    }
}


int main(){
    problema8();
    return 0;
}
