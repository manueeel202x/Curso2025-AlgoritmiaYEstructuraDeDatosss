#include <stdio.h>

long long calcular_factorial()
{
    int n, i;
    long long factorial = 1;
    
    do
    {
        scanf("%d", &n);
    } while (n < 0);
    
    for (i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    
    return factorial;
}

void ordenar_vector_descendente()
{
    int vector[10];
    int i, j, temp;
    
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &vector[i]);
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (vector[j] < vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    
    printf("Vector ordenado:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void mostrar_menu()
{
    int opcion;
    long long resultado_factorial;

    do
    {
        printf("\nMENU\n");
        printf("1. Factorial de un número entero positivo.\n");
        printf("2. Cargar y ordenar en orden descendente un vector de diez elementos.\n");
        printf("3. Salir\n");
        printf("Seleccione Opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                resultado_factorial = calcular_factorial();
                printf("El factorial es: %lld\n", resultado_factorial);
                break;
            case 2:
                ordenar_vector_descendente();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}

int main()
{
    mostrar_menu();
    return 0;
}