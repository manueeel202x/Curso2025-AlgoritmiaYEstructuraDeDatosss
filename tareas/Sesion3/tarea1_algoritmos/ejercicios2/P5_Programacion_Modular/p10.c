#include <stdio.h>

void mostrar_menu_principal()
{
    printf("*********************************\n");
    printf("1. Seleccionar producto\n");
    printf("2. Pagar y dar vuelto\n");
    printf("3. Salir\n");
    printf("Seleccione opción: ");
}

void mostrar_menu_productos(char *nombre, float *precio)
{
    char opcion;

    printf("*********************************\n");
    printf("a. Café\t\tS/. 1.00\n");
    printf("b. Café con leche\tS/. 1.50\n");
    printf("c. Leche\t\tS/. 2.00\n");
    printf("Elegir opción: ");
    scanf(" %c", &opcion);

    switch (opcion)
    {
        case 'a':
        case 'A':
            sprintf(nombre, "Café");
            *precio = 1.00;
            break;
        case 'b':
        case 'B':
            sprintf(nombre, "Café con leche");
            *precio = 1.50;
            break;
        case 'c':
        case 'C':
            sprintf(nombre, "Leche");
            *precio = 2.00;
            break;
        default:
            sprintf(nombre, "No seleccionado");
            *precio = 0.00;
            printf("Opción inválida. Volviendo al menú principal.\n");
            break;
    }
}

void procesar_pago(float precio_producto, float *monto_pagado, float *vuelto)
{
    float monto;

    printf("*********************************\n");
    printf("Precio __%.2f__\n", precio_producto);
    
    do
    {
        printf("Monto __");
        scanf("%f", &monto);
    } while (monto < precio_producto);

    *monto_pagado = monto;
    *vuelto = monto - precio_producto;
}

void imprimir_resumen(char *nombre_producto, float precio, float monto, float vuelto)
{
    printf("\nUsted compró (%s ) de precio (%.2f)\n", nombre_producto, precio);
    printf("Pagó (%.2f) y su vuelto es (%.2f)\n\n", monto, vuelto);
}

void problema10()
{
    int opcion_principal = 0;
    char nombre_producto[30] = "No seleccionado";
    float precio_producto = 0.0;
    float monto_pagado = 0.0;
    float vuelto = 0.0;

    do
    {
        mostrar_menu_principal();
        scanf("%d", &opcion_principal);

        switch (opcion_principal)
        {
            case 1:
                mostrar_menu_productos(nombre_producto, &precio_producto);
                monto_pagado = 0.0;
                vuelto = 0.0;
                break;

            case 2:
                if (precio_producto > 0.0)
                {
                    procesar_pago(precio_producto, &monto_pagado, &vuelto);
                    imprimir_resumen(nombre_producto, precio_producto, monto_pagado, vuelto);
                    
                    sprintf(nombre_producto, "No seleccionado");
                    precio_producto = 0.0;
                    monto_pagado = 0.0;
                    vuelto = 0.0;
                }
                else
                {
                    printf("\nPrimero debe seleccionar un producto (Opción 1).\n\n");
                }
                break;

            case 3:
                printf("\nSaliendo de la simulación de la máquina expendedora.\n");
                break;

            default:
                printf("\nOpción no válida. Intente de nuevo.\n\n");
                break;
        }
    } while (opcion_principal != 3);
}

int main()
{
    problema10();
    return 0;
}