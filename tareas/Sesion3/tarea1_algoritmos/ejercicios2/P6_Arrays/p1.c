#include <stdio.h>

void problema1()
{
    int vector[20];
    int suma = 0;
    float media;
    int i;

    for (i = 0; i < 20; i++)
    {
        scanf("%d", &vector[i]);
    }

    for (i = 0; i < 20; i++)
    {
        suma += vector[i];
    }

    media = (float)suma / 20;

    printf("%d\n", suma);
    printf("%.2f\n", media);
}

int main()
{
    problema1();
    return 0;
}