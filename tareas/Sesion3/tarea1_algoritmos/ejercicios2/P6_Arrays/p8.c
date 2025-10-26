#include <stdio.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

void cargar_matrices(int A[MAX_FILAS][MAX_COLUMNAS], int B[MAX_FILAS][MAX_COLUMNAS], int *m, int *n)
{
    int i, j;
    
    do
    {
        scanf("%d", m);
        scanf("%d", n);
    } while (*m <= 0 || *n <= 0 || *m > MAX_FILAS || *n > MAX_COLUMNAS);
    
    for (i = 0; i < *m; i++)
    {
        for (j = 0; j < *n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < *m; i++)
    {
        for (j = 0; j < *n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
}

void diferencia_matrices(int A[MAX_FILAS][MAX_COLUMNAS], int B[MAX_FILAS][MAX_COLUMNAS], int C[MAX_FILAS][MAX_COLUMNAS], int m, int n)
{
    int i, j;
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mostrar_matriz(int C[MAX_FILAS][MAX_COLUMNAS], int m, int n)
{
    int i, j;
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

void procesar_diferencia()
{
    int A[MAX_FILAS][MAX_COLUMNAS];
    int B[MAX_FILAS][MAX_COLUMNAS];
    int C[MAX_FILAS][MAX_COLUMNAS];
    int m = 0, n = 0;

    cargar_matrices(A, B, &m, &n);
    diferencia_matrices(A, B, C, m, n);
    mostrar_matriz(C, m, n);
}

void mostrar_menu()
{
    int opcion;

    do
    {
        printf("\nMENU\n");
        printf("1. Cargar y realizar la diferencia de dos matrices del mismo orden A(mxn) - B(mxn)\n");
        printf("2. Salir\n");
        printf("Seleccione Opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                procesar_diferencia();
                break;
            case 2:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 2);
}

int main()
{
    mostrar_menu();
    return 0;
}