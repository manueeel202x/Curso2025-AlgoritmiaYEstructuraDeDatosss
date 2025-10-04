#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 100
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    double sueldo_anterior;
    int tipo_empleado;
    double sueldo_actual;
} Empleado;

double calcular_aumento(double sueldo, int tipo) {
    double factor_aumento = 0.0;

    switch (tipo) {
        case 1:
            factor_aumento = 0.05;
            break;
        case 2:
            factor_aumento = 0.07;
            break;
        case 3:
            factor_aumento = 0.10;
            break;
        case 4:
            factor_aumento = 0.14;
            break;
        case 5:
            factor_aumento = 0.18;
            break;
        default:
            factor_aumento = 0.00;
            break;
    }
    
    return sueldo * (1.0 + factor_aumento);
}

int main() {
    Empleado empleados[MAX_EMPLEADOS];
    int contador = 0;
    double total_anterior = 0.0;
    double total_actual = 0.0;
    char nombre_input[MAX_NOMBRE];

    printf("--- CAPTURA DE DATOS DE EMPLEADOS ---\n");
    printf("Ingrese Nombre (o 'FIN' para terminar la captura):\n");

    while (contador < MAX_EMPLEADOS) {
        double sueldo_input;
        int tipo_input;

        printf("Nombre: ");
        if (scanf("%49s", nombre_input) != 1) {
            break;
        }

        if (strcmp(nombre_input, "FIN") == 0 || strcmp(nombre_input, "fin") == 0) {
            break;
        }

        printf("Sueldo mensual anterior: ");
        if (scanf("%lf", &sueldo_input) != 1 || sueldo_input < 0) {
            printf("Error en sueldo. Terminando captura.\n");
            break;
        }

        printf("Tipo de empleado (1-5): ");
        if (scanf("%d", &tipo_input) != 1 || tipo_input < 1 || tipo_input > 5) {
            printf("Tipo de empleado invalido. Terminando captura.\n");
            break;
        }

        strcpy(empleados[contador].nombre, nombre_input);
        empleados[contador].sueldo_anterior = sueldo_input;
        empleados[contador].tipo_empleado = tipo_input;
        empleados[contador].sueldo_actual = calcular_aumento(sueldo_input, tipo_input);
        
        total_anterior += empleados[contador].sueldo_anterior;
        total_actual += empleados[contador].sueldo_actual;

        contador++;
        printf("\n");
    }

    /* Generación del Reporte */
    printf("\n=======================================================\n");
    printf("                 AUMENTOS DE SUELDOS\n");
    printf("=======================================================\n");
    printf("%-30s %15s %15s\n", "NOMBRE", "SUELDO ANTERIOR", "SUELDO ACTUAL");
    printf("------------------------------ --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %15.2f %15.2f\n", 
            empleados[i].nombre, 
            empleados[i].sueldo_anterior, 
            empleados[i].sueldo_actual);
    }

    printf("------------------------------ --------------- ---------------\n");
    printf("%-30s %15.2f %15.2f\n", "TOTAL", total_anterior, total_actual);
    printf("=======================================================\n");

    return 0;
}