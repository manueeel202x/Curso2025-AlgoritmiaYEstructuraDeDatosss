#include <stdio.h>

void ordenar_vector(int vector[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void problema6()
{
    int n;
    int i;
    int max_size = 100;
    int vector[max_size];

    scanf("%d", &n);

    if (n <= 0 || n > max_size)
    {
        return;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }

    ordenar_vector(vector, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

/*
Para ejecutar el Problema 6, el main debe ser:

int main()
{
    problema6();
    return 0;
}
*/