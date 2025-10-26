#include <stdio.h>
#include <string.h>

#define MAX_ARTICULOS 100
#define MAX_DESCRIPCION 30

typedef struct {
    char descripcion[MAX_DESCRIPCION];
    int unidades;
    double factor_costo;
    double costo_fijo;
    double costo_produccion;
} Articulo;

double calcular_costo_produccion(int unidades, double factor, double fijo) {
    return (double)unidades * factor + fijo;
}

int main() {
    Articulo articulos[MAX_ARTICULOS];
    int contador = 0;
    double costo_total_general = 0.0;
    char descripcion_input[MAX_DESCRIPCION];

    printf("--- CAPTURA DE DATOS DE ARTICULOS ---\n");
    printf("Ingrese Descripcion del Articulo (o 'FIN' para terminar la captura):\n");

    while (contador < MAX_ARTICULOS) {
        int unidades_input;
        double factor_input, fijo_input;

        printf("Descripcion: ");
        if (scanf("%29s", descripcion_input) != 1) {
            break;
        }

        if (strcmp(descripcion_input, "FIN") == 0 || strcmp(descripcion_input, "fin") == 0) {
            break;
        }

        printf("Unidades Producidas: ");
        if (scanf("%d", &unidades_input) != 1 || unidades_input < 0) {
            printf("Error en unidades. Terminando captura.\n");
            break;
        }

        printf("Factor de costo de materiales: ");
        if (scanf("%lf", &factor_input) != 1 || factor_input < 0) {
            printf("Error en factor de costo. Terminando captura.\n");
            break;
        }

        printf("Costo fijo: ");
        if (scanf("%lf", &fijo_input) != 1 || fijo_input < 0) {
            printf("Error en costo fijo. Terminando captura.\n");
            break;
        }

        strcpy(articulos[contador].descripcion, descripcion_input);
        articulos[contador].unidades = unidades_input;
        articulos[contador].factor_costo = factor_input;
        articulos[contador].costo_fijo = fijo_input;
        
        articulos[contador].costo_produccion = calcular_costo_produccion(unidades_input, factor_input, fijo_input);
        
        costo_total_general += articulos[contador].costo_produccion;

        contador++;
        printf("\n");
    }

    /* Generación del Reporte */
    printf("\n=================================================================================\n");
    printf("                               COSTO DE PRODUCCIÓN\n");
    printf("=================================================================================\n");
    printf("%-30s %-10s %-10s %-10s %15s\n", 
        "ARTICULO", 
        "UNIDADES", 
        "FACTOR", 
        "COSTO FIJO", 
        "COSTO DE PRODUCCION");
    printf("------------------------------ ---------- ---------- ---------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %-10d %-10.2f %-10.2f %15.2f\n", 
            articulos[i].descripcion, 
            articulos[i].unidades, 
            articulos[i].factor_costo, 
            articulos[i].costo_fijo, 
            articulos[i].costo_produccion);
    }

    printf("------------------------------ ---------- ---------- ---------- ---------------\n");
    printf("TOTAL %-24d %48.2f\n", contador, costo_total_general);
    printf("=================================================================================\n");

    return 0;
}