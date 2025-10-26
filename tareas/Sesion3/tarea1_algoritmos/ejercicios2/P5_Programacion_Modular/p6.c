#include <stdio.h>
#include <math.h>

double calcular_sumatoria()
{
    int i;
    double suma = 0.0;
    
    for (i = 2; i <= 1500; i += 2)
    {
        suma += sqrt(i);
    }
    
    return suma;
}

void problema6()
{
    double resultado;
    
    resultado = calcular_sumatoria();
    
    printf("%.4f\n", resultado);
}

int main()
{
    problema6();
    return 0;
}