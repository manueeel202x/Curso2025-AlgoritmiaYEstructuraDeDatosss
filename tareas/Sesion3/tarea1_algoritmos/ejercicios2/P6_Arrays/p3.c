#include <stdio.h>
#include <stdbool.h>

bool es_primo(int num)
{
    int i;
    if (num <= 1)
    {
        return false;
    }
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void problema3()
{
    int contador = 0;
    int numero = 2;

    printf("Los 10 primeros números primos:\n");
    printf("---------------------------\n");
    
    while (contador < 10)
    {
        if (es_primo(numero))
        {
            printf("%2d\n", numero);
            contador++;
        }
        numero++;
    }
}

int main()
{
    problema3();
    return 0;
}