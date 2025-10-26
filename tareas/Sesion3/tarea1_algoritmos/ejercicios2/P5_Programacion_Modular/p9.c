#include <stdio.h>

void problema9()
{
    int numero;
    int digitos[5];
    int multiplicadores[] = {2, 3, 4, 5, 6, 7};
    int i, suma_productos = 0;
    int residuo;
    int digito_verificador;

    scanf("%d", &numero);

    int temp_num = numero;
    for (i = 0; i < 5; i++)
    {
        digitos[i] = temp_num % 10;
        temp_num /= 10;
    }
    
    for (i = 0; i < 5; i++)
    {
        suma_productos += digitos[i] * multiplicadores[i];
    }
    
    residuo = suma_productos % 11;
    
    if (residuo == 0 || residuo == 1)
    {
        digito_verificador = residuo;
    }
    else
    {
        digito_verificador = 11 - residuo;
    }

    printf("%d\n", digito_verificador);
}

int main()
{
    problema9();
    return 0;
}