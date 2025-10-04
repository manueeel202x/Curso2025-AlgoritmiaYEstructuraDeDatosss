#include <stdio.h>
#include <string.h>

#define MAX_ARTICULOS 100
#define MAX_DESCRIPCION 30
#define UTILIDAD_FACTOR 1.20
#define IMPUESTO_FACTOR 0.15

typedef struct {
    char descripcion[MAX_DESCRIPCION];
    double costo_produccion;
    double utilidad;
    double impuesto;
    double precio_venta;
} ArticuloVenta;

double calcular_utilidad(double costo) {
    return costo * UTILIDAD_FACTOR;
}

double calcular_impuesto(double costo, double utilidad) {
    return (costo + utilidad) * IMPUESTO_FACTOR;
}

int main() {
    ArticuloVenta articulos[MAX_ARTICULOS];
    int contador = 0;
    double total_costo_produccion = 0.0;
    double total_utilidad = 0.0;
    double total_impuesto = 0.0;
    double total_precio_venta = 0.0;
    char descripcion_input[MAX_DESCRIPCION];

    printf("--- CAPTURA DE DATOS DE ARTICULOS ---\n");
    printf("Ingrese Descripcion del Articulo (o 'FIN' para terminar):\n");

    while (contador < MAX_ARTICULOS) {
        double costo_input;

        printf("Descripcion: ");
        if (scanf("%29s", descripcion_input) != 1) {
            break;
        }

        if (strcmp(descripcion_input, "FIN") == 0 || strcmp(descripcion_input, "fin") == 0) {
            break;
        }

        printf("Costo de Produccion: ");
        if (scanf("%lf", &costo_input) != 1 || costo_input < 0) {
            printf("Error en costo de produccion. Terminando captura.\n");
            break;
        }

        /* Calculos */
        double utilidad_calc = calcular_utilidad(costo_input);
        double impuesto_calc = calcular_impuesto(costo_input, utilidad_calc);
        double precio_venta_calc = costo_input + utilidad_calc + impuesto_calc;

        /* Guardar y acumular */
        strcpy(articulos[contador].descripcion, descripcion_input);
        articulos[contador].costo_produccion = costo_input;
        articulos[contador].utilidad = utilidad_calc;
        articulos[contador].impuesto = impuesto_calc;
        articulos[contador].precio_venta = precio_venta_calc;

        total_costo_produccion += costo_input;
        total_utilidad += utilidad_calc;
        total_impuesto += impuesto_calc;
        total_precio_venta += precio_venta_calc;

        contador++;
        printf("\n");
    }

    /* Generación del Reporte */
    printf("\n=================================================================================================\n");
    printf("                                         PRECIOS DE VENTA\n");
    printf("=================================================================================================\n");
    printf("%-30s %15s %15s %15s %15s\n", 
        "ARTICULO", 
        "COSTO DE", 
        "UTILIDAD", 
        "IMPUESTO", 
        "PRECIO DE VENTA");
    printf("%-30s %15s %15s %15s %15s\n", 
        "", 
        "PRODUCCION", 
        "", 
        "", 
        "");
    printf("------------------------------ --------------- --------------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %15.2f %15.2f %15.2f %15.2f\n", 
            articulos[i].descripcion, 
            articulos[i].costo_produccion, 
            articulos[i].utilidad, 
            articulos[i].impuesto, 
            articulos[i].precio_venta);
    }

    printf("------------------------------ --------------- --------------- --------------- ---------------\n");
    printf("%-30s %15.2f %15.2f %15.2f %15.2f\n", 
        "TOTAL", 
        total_costo_produccion, 
        total_utilidad, 
        total_impuesto, 
        total_precio_venta);
    printf("=================================================================================================\n");

    return 0;
}