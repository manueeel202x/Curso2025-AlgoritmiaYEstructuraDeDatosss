#include <stdio.h>
#include <string.h>

#define MAX_AUTOS 100
#define MAX_MARCA 30
#define MAX_ORIGEN 20

typedef struct {
    char marca[MAX_MARCA];
    char origen[MAX_ORIGEN];
    double costo;
    double impuesto;
    double precio_venta;
} Auto;

double calcular_impuesto(const char *origen, double costo) {
    if (strcmp(origen, "ALEMANIA") == 0 || strcmp(origen, "alemania") == 0) {
        return costo * 0.20;
    } else if (strcmp(origen, "JAPON") == 0 || strcmp(origen, "japon") == 0) {
        return costo * 0.30;
    } else if (strcmp(origen, "ITALIA") == 0 || strcmp(origen, "italia") == 0) {
        return costo * 0.15;
    } else if (strcmp(origen, "USA") == 0 || strcmp(origen, "usa") == 0) {
        return costo * 0.08;
    }
    return 0.0; /* Impuesto cero si el origen no está listado */
}

int main() {
    Auto autos[MAX_AUTOS];
    int contador = 0;
    char marca_input[MAX_MARCA];
    double total_costo = 0.0;
    double total_impuesto = 0.0;
    double total_precio_venta = 0.0;

    /* Contadores por país */
    int cont_alemania = 0;
    int cont_japon = 0;
    int cont_italia = 0;
    int cont_usa = 0;
    
    printf("--- REGISTRO DE AUTOS IMPORTADOS ---\n");
    printf("Ingrese Marca (o 'FIN' para terminar):\n");

    while (contador < MAX_AUTOS) {
        char origen_input[MAX_ORIGEN];
        double costo_input;

        printf("Marca: ");
        if (scanf("%29s", marca_input) != 1) {
            break;
        }

        if (strcmp(marca_input, "FIN") == 0 || strcmp(marca_input, "fin") == 0) {
            break;
        }

        printf("Origen (Alemania, Japon, Italia, USA): ");
        if (scanf("%19s", origen_input) != 1) {
            printf("Error en origen. Terminando.\n");
            break;
        }
        
        printf("Costo: ");
        if (scanf("%lf", &costo_input) != 1 || costo_input < 0) {
            printf("Costo invalido. Terminando.\n");
            break;
        }

        /* Calculos */
        double impuesto_calc = calcular_impuesto(origen_input, costo_input);
        double precio_venta_calc = costo_input + impuesto_calc;

        /* Guardar y acumular */
        strcpy(autos[contador].marca, marca_input);
        strcpy(autos[contador].origen, origen_input);
        autos[contador].costo = costo_input;
        autos[contador].impuesto = impuesto_calc;
        autos[contador].precio_venta = precio_venta_calc;

        total_costo += costo_input;
        total_impuesto += impuesto_calc;
        total_precio_venta += precio_venta_calc;

        if (strcmp(origen_input, "ALEMANIA") == 0 || strcmp(origen_input, "alemania") == 0) {
            cont_alemania++;
        } else if (strcmp(origen_input, "JAPON") == 0 || strcmp(origen_input, "japon") == 0) {
            cont_japon++;
        } else if (strcmp(origen_input, "ITALIA") == 0 || strcmp(origen_input, "italia") == 0) {
            cont_italia++;
        } else if (strcmp(origen_input, "USA") == 0 || strcmp(origen_input, "usa") == 0) {
            cont_usa++;
        }

        contador++;
        printf("\n");
    }

    /* Determinación del país con más autos */
    int max_autos = 0;
    char pais_max[MAX_ORIGEN] = "N/A";

    if (cont_alemania > max_autos) {
        max_autos = cont_alemania;
        strcpy(pais_max, "ALEMANIA");
    }
    if (cont_japon > max_autos) {
        max_autos = cont_japon;
        strcpy(pais_max, "JAPON");
    }
    if (cont_italia > max_autos) {
        max_autos = cont_italia;
        strcpy(pais_max, "ITALIA");
    }
    if (cont_usa > max_autos) {
        max_autos = cont_usa;
        strcpy(pais_max, "USA");
    }

    /* Impresión del Reporte */
    printf("\n=================================================================================\n");
    printf("                                REPORTE DE AUTOS IMPORTADOS\n");
    printf("=================================================================================\n");
    printf("%-20s %-15s %15s %15s %15s\n", 
        "MARCA", 
        "ORIGEN", 
        "COSTO", 
        "IMPUESTO", 
        "PRECIO VTA.");
    printf("-------------------- --------------- --------------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-20s %-15s %15.2f %15.2f %15.2f\n", 
            autos[i].marca, 
            autos[i].origen, 
            autos[i].costo, 
            autos[i].impuesto, 
            autos[i].precio_venta);
    }

    printf("-------------------- --------------- --------------- --------------- ---------------\n");
    printf("TOTAL AUTOS %-10d %15.2f %15.2f %15.2f\n", 
        contador, 
        total_costo, 
        total_impuesto, 
        total_precio_venta);
    printf("---------------------------------------------------------------------------------\n");
    printf("ALEMANIA: %d\n", cont_alemania);
    printf("JAPÓN:    %d\n", cont_japon);
    printf("ITALIA:   %d\n", cont_italia);
    printf("USA:      %d\n", cont_usa);
    printf("PAÍS DEL QUE SE IMPORTÓ MÁS AUTOS: %s (%d)\n", pais_max, max_autos);
    printf("=================================================================================\n");

    return 0;
}