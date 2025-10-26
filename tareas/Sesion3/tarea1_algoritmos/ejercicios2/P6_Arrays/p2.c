#include <stdio.h>
#include <stdbool.h>

bool es_simetrico(int vector[], int n)
{
    int i;
    for (i = 0; i < n / 2; i++)
    {
        if (vector[i] != vector[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void problema2()
{
    int n;
    int i;
    int max_size = 100;
    int vector[max_size];
    bool resultado;

    scanf("%d", &n);

    if (n > max_size)
    {
        return;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }

    resultado = es_simetrico(vector, n);

    if (resultado)
    {
        printf("SIMETRICO\n");
    }
    else
    {
        printf("NO SIMETRICO\n");
    }
}

int main()
{
    problema2();
    return 0;
}