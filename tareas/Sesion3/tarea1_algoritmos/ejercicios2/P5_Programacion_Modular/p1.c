#include <stdio.h>

long long factorial(int n)
{
    long long result = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void problema1()
{
    int X, Y;
    long long numerador, denominador, resultado;

    scanf("%d", &X);
    scanf("%d", &Y);

    if (Y < 0 || Y > X)
    {
        printf("0\n");
    }
    else
    {
        numerador = factorial(X);
        denominador = factorial(Y) * factorial(X - Y);
        if (denominador == 0)
        {
            printf("Error\n");
        }
        else
        {
            resultado = numerador / denominador;
            printf("%lld\n", resultado);
        }
    }
}

int main()
{
    problema1();
    return 0;
}