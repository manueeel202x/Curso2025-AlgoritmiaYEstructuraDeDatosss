#include <stdio.h>

void intercambiar(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void problema3()
{
    float num1, num2;

    scanf("%f", &num1);
    scanf("%f", &num2);

    intercambiar(&num1, &num2);

    printf("%.2f\n", num1);
    printf("%.2f\n", num2);
}

int main()
{
    problema3();
    return 0;
}