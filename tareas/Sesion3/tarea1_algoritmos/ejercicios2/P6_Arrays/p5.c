#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50

typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

void ingresar_datos(Alumno alumnos[], int *contador)
{
    int num_alumnos, i;

    scanf("%d", &num_alumnos);

    if (*contador + num_alumnos > MAX_ALUMNOS)
    {
        num_alumnos = MAX_ALUMNOS - *contador;
    }

    for (i = 0; i < num_alumnos; i++)
    {
        scanf("%s", alumnos[*contador + i].nombre);
        scanf("%f", &alumnos[*contador + i].promedio);
    }
    
    *contador += num_alumnos;
}

void mostrar_datos(Alumno alumnos[], int contador)
{
    int i;
    
    if (contador == 0)
    {
        printf("\nNo hay datos de alumnos ingresados.\n");
        return;
    }

    printf("\nLista de Alumnos:\n");
    printf("----------------------------------------\n");
    for (i = 0; i < contador; i++)
    {
        printf("Nombre: %s, Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }
    printf("----------------------------------------\n\n");
}

void problema5()
{
    Alumno alumnos[MAX_ALUMNOS];
    int contador_alumnos = 0;
    int opcion;

    do
    {
        printf("\nMENÚ PRINCIPAL\n");
        printf("1. Ingresar datos de alumnos\n");
        printf("2. Mostrar datos de alumnos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                ingresar_datos(alumnos, &contador_alumnos);
                break;
            case 2:
                mostrar_datos(alumnos, contador_alumnos);
                break;
            case 3:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}

/*
Para ejecutar el Problema 5, el main debe ser:

int main()
{
    problema5();
    return 0;
}
*/