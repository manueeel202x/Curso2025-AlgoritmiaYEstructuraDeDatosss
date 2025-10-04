#include <stdio.h>
#include <string.h>

#define MAX_ARTICULOS 50
#define MAX_DESCRIPCION 30
#define TASA_IMPUESTO 0.19

typedef struct {
    char descripcion[MAX_DESCRIPCION];
    int cantidad;
    double precio_unitario;
    double precio_total;
} ItemFactura;

int main() {
    ItemFactura items[MAX_ARTICULOS];
    char nombre_cliente[50];
    char descripcion_input[MAX_DESCRIPCION];
    int contador = 0;
    double subtotal = 0.0;
    double impuesto = 0.0;
    double total = 0.0;

    /* Captura del nombre del cliente */
    printf("Ingrese el Nombre del Cliente: ");
    scanf("%49[^\n]", nombre_cliente);
    
    printf("\n--- INGRESO DE ARTICULOS (Escriba 'FIN' para terminar) ---\n");

    /* Captura de los items de la factura */
    while (contador < MAX_ARTICULOS) {
        int cantidad_input;
        double precio_input;

        printf("Descripcion del Articulo: ");
        /* Limpiar buffer y leer la descripcion */
        while (getchar() != '\n');
        if (scanf("%29s", descripcion_input) != 1) {
            break;
        }

        if (strcmp(descripcion_input, "FIN") == 0 || strcmp(descripcion_input, "fin") == 0) {
            break;
        }

        printf("Cantidad: ");
        if (scanf("%d", &cantidad_input) != 1 || cantidad_input <= 0) {
            printf("Cantidad invalida. Terminando.\n");
            break;
        }

        printf("Precio Unitario: ");
        if (scanf("%lf", &precio_input) != 1 || precio_input < 0) {
            printf("Precio invalido. Terminando.\n");
            break;
        }

        /* Calculo del Precio Total del item */
        double precio_total_item = (double)cantidad_input * precio_input;

        /* Guardar y acumular */
        strcpy(items[contador].descripcion, descripcion_input);
        items[contador].cantidad = cantidad_input;
        items[contador].precio_unitario = precio_input;
        items[contador].precio_total = precio_total_item;

        subtotal += precio_total_item;
        contador++;
        printf("\n");
    }

    /* Calculos finales */
    impuesto = subtotal * TASA_IMPUESTO;
    total = subtotal + impuesto;

    /* Impresion de la Factura */
    printf("\n=================================================================\n");
    printf("                                FACTURA\n");
    printf("NOMBRE DEL CLIENTE: %s\n", nombre_cliente);
    printf("=================================================================\n");
    printf("%-30s %-10s %-15s %15s\n", 
        "ARTICULO", 
        "CANTIDAD", 
        "PRECIO UNITARIO", 
        "PRECIO TOTAL");
    printf("------------------------------ ---------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %-10d %-15.2f %15.2f\n", 
            items[i].descripcion, 
            items[i].cantidad, 
            items[i].precio_unitario, 
            items[i].precio_total);
    }
    
    printf("------------------------------ ---------- --------------- ---------------\n");
    printf("%57s %15.2f\n", "SUBTOTAL", subtotal);
    printf("%57s %15.2f\n", "IMPUESTO 19%", impuesto);
    printf("%57s %15.2f\n", "TOTAL", total);
    printf("=================================================================\n");

    return 0;
}