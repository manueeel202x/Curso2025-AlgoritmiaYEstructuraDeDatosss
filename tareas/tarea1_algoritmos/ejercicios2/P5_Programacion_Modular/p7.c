#include <stdio.h>

void calcular_sumatoria_cuadrados(int n, long long *resultado)
{
    int i;
    *resultado = 0;
    
    for (i = 1; i <= n; i++)
    {
        *resultado += (long long)i * i;
    }
}

void problema7()
{
    int N;
    long long suma;

    scanf("%d", &N);

    calcular_sumatoria_cuadrados(N, &suma);

    printf("%lld\n", suma);
}

int main()
{
    problema7();
    return 0;
}