#include <stdio.h>
#include <math.h>

void calcular_area_triangulo()
{
    float base, altura, area;
    scanf("%f", &base);
    scanf("%f", &altura);
    area = (base * altura) / 2;
    printf("El área del triángulo es: %.2f\n", area);
}

void calcular_area_cuadrado()
{
    float lado, area;
    scanf("%f", &lado);
    area = lado * lado;
    printf("El área del cuadrado es: %.2f\n", area);
}

void calcular_area_rectangulo()
{
    float largo, ancho, area;
    scanf("%f", &largo);
    scanf("%f", &ancho);
    area = largo * ancho;
    printf("El área del rectángulo es: %.2f\n", area);
}

void calcular_area_circulo()
{
    float radio, area;
    const float PI = 3.14159;
    scanf("%f", &radio);
    area = PI * radio * radio;
    printf("El área del círculo es: %.2f\n", area);
}

void problema2()
{
    int opcion;

    do
    {
        printf("AREAS\t\tFIGURAS\n");
        printf("1. TRIÁNGULO\n");
        printf("2. CUADRADO\n");
        printf("3. RECTÁNGULO\n");
        printf("4. CÍRCULO\n");
        printf("5. FIN\n");
        printf("OPCIÓN : ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                calcular_area_triangulo();
                break;
            case 2:
                calcular_area_cuadrado();
                break;
            case 3:
                calcular_area_rectangulo();
                break;
            case 4:
                calcular_area_circulo();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 5);
}

/*
Para ejecutar el Problema 2, el main debe ser:

int main()
{
    problema2();
    return 0;
}
*/