#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 100
#define MAX_NOMBRE 50
#define TASA_IMPUESTO_TRAMO1 0.05
#define TASA_IMPUESTO_TRAMO2 0.10

typedef struct {
    char nombre[MAX_NOMBRE];
    double sueldo_mensual;
    double sueldo_bruto;
    double impuesto;
    double sueldo_neto;
} Empleado;

double calcular_impuesto(double sueldo_bruto, double salario_minimo) {
    if (sueldo_bruto <= salario_minimo) {
        return 0.0;
    }

    double excedente = sueldo_bruto - salario_minimo;
    double impuesto_total = 0.0;
    double limite_tramo1 = 2.0 * salario_minimo; /* Hasta 2 salarios mínimos de excedente */

    if (excedente <= limite_tramo1) {
        /* Se aplica 5% sobre el excedente completo */
        impuesto_total = excedente * TASA_IMPUESTO_TRAMO1;
    } else {
        /* 1. Impuesto sobre el primer tramo (hasta 2 SM de excedente) */
        impuesto_total = limite_tramo1 * TASA_IMPUESTO_TRAMO1;

        /* 2. Impuesto sobre el excedente restante (mas alla de 2 SM) */
        double excedente_restante = excedente - limite_tramo1;
        impuesto_total += excedente_restante * TASA_IMPUESTO_TRAMO2;
    }

    return impuesto_total;
}

int main() {
    Empleado empleados[MAX_EMPLEADOS];
    int contador = 0;
    double salario_minimo;
    double total_bruto = 0.0;
    double total_impuesto = 0.0;
    double total_neto = 0.0;
    char nombre_input[MAX_NOMBRE];

    printf("--- CAPTURA DE NOMINA QUINCENAL ---\n");
    printf("Ingrese el Salario Minimo General: ");
    if (scanf("%lf", &salario_minimo) != 1 || salario_minimo <= 0) {
        printf("Salario minimo invalido. Terminando.\n");
        return 1;
    }
    
    printf("\nIngrese Nombre (o 'FIN' para terminar):\n");

    while (contador < MAX_EMPLEADOS) {
        double sueldo_input;

        printf("Nombre: ");
        if (scanf("%49s", nombre_input) != 1) {
            break;
        }

        if (strcmp(nombre_input, "FIN") == 0 || strcmp(nombre_input, "fin") == 0) {
            break;
        }

        printf("Sueldo mensual: ");
        if (scanf("%lf", &sueldo_input) != 1 || sueldo_input < 0) {
            printf("Sueldo invalido. Terminando captura.\n");
            break;
        }
        
        /* Calculos */
        double sdo_bruto_calc = sueldo_input / 2.0;
        double impuesto_calc = calcular_impuesto(sdo_bruto_calc, salario_minimo);
        double sdo_neto_calc = sdo_bruto_calc - impuesto_calc;

        /* Guardar y acumular */
        strcpy(empleados[contador].nombre, nombre_input);
        empleados[contador].sueldo_mensual = sueldo_input;
        empleados[contador].sueldo_bruto = sdo_bruto_calc;
        empleados[contador].impuesto = impuesto_calc;
        empleados[contador].sueldo_neto = sdo_neto_calc;

        total_bruto += sdo_bruto_calc;
        total_impuesto += impuesto_calc;
        total_neto += sdo_neto_calc;

        contador++;
        printf("\n");
    }

    /* Generación del Reporte de Nomina */
    printf("\n=================================================================\n");
    printf("                          NOMINA QUINCENAL\n");
    printf("=================================================================\n");
    printf("%-30s %15s %15s %15s\n", 
        "NOMBRE", 
        "SUELDO BRUTO", 
        "IMPUESTO", 
        "SUELDO NETO");
    printf("------------------------------ --------------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %15.2f %15.2f %15.2f\n", 
            empleados[i].nombre, 
            empleados[i].sueldo_bruto, 
            empleados[i].impuesto, 
            empleados[i].sueldo_neto);
    }

    printf("------------------------------ --------------- --------------- ---------------\n");
    printf("TOTALES %-22d %15.2f %15.2f %15.2f\n", 
        contador, 
        total_bruto, 
        total_impuesto, 
        total_neto);
    printf("=================================================================\n");

    return 0;
}