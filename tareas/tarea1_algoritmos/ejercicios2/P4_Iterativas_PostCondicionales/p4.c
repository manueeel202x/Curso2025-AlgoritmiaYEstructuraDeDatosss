#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 100
#define MAX_NOMBRE 50
#define TASA_BONIFICACION_ANUAL 0.02
#define DIAS_QUINCENA 15
#define DIAS_ANIO 360
#define SALARIO_MINIMO 300.00

typedef struct {
    char nombre[MAX_NOMBRE];
    double sueldo_mensual;
    int antiguedad;
    double sueldo_bruto;
    double impuesto;
    double sueldo_neto;
} Empleado;

typedef struct {
    double limite_inferior;
    double limite_superior;
    double cuota_fija;
    double porcentaje;
} TramoImpuesto;

/* Tabla de impuestos basada en el excedente del salario minimo */
const TramoImpuesto tabla_impuestos[] = {
    {0.00, 300.00, 30.00, 0.03},
    {301.00, 700.00, 50.00, 0.08},
    {701.00, 1100.00, 100.00, 0.11},
    {1101.00, 1700.00, 150.00, 0.16},
    {1701.00, 9999999.00, 20.00, 0.20} /* Se usa un limite alto para 'adelante' */
};

double calcular_bonificacion(double sueldo_mensual, int antiguedad) {
    if (antiguedad < 3) {
        return 0.0;
    }
    
    /* Bonificacion del 2% anual aplicada a la quincena */
    return sueldo_mensual * TASA_BONIFICACION_ANUAL * (double)antiguedad / (DIAS_ANIO / DIAS_QUINCENA);
}

double calcular_impuesto(double sueldo_bruto) {
    if (sueldo_bruto <= SALARIO_MINIMO) {
        return 0.0;
    }

    double excedente = sueldo_bruto - SALARIO_MINIMO;

    for (int i = 0; i < 5; i++) {
        /* Se considera el limite inferior para el rango */
        if (excedente >= tabla_impuestos[i].limite_inferior || i == 4) {
            
            /* Si el excedente es menor que el limite superior del tramo actual (no aplica para el ultimo) */
            if (excedente <= tabla_impuestos[i].limite_superior || i == 4) {
                
                double diferencia = excedente - tabla_impuestos[i].limite_inferior;
                double impuesto = tabla_impuestos[i].cuota_fija + (diferencia * tabla_impuestos[i].porcentaje);
                return impuesto;
            }
        }
    }
    return 0.0;
}


int main() {
    Empleado empleados[MAX_EMPLEADOS];
    int contador = 0;
    double total_bruto = 0.0;
    double total_impuesto = 0.0;
    double total_neto = 0.0;
    char nombre_input[MAX_NOMBRE];

    printf("--- CAPTURA DE EMPLEADOS PARA NOMINA ---\n");
    printf("Ingrese Nombre (o 'FIN' para terminar):\n");

    while (contador < MAX_EMPLEADOS) {
        double sueldo_input;
        int antiguedad_input;

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

        printf("Antiguedad (anios): ");
        if (scanf("%d", &antiguedad_input) != 1 || antiguedad_input < 0) {
            printf("Antiguedad invalida. Terminando captura.\n");
            break;
        }
        
        /* Calculos */
        double bonif = calcular_bonificacion(sueldo_input, antiguedad_input);
        double sdo_bruto_calc = (sueldo_input / 2.0) + bonif;
        double impuesto_calc = calcular_impuesto(sdo_bruto_calc);
        double sdo_neto_calc = sdo_bruto_calc - impuesto_calc;

        /* Guardar y acumular */
        strcpy(empleados[contador].nombre, nombre_input);
        empleados[contador].sueldo_mensual = sueldo_input;
        empleados[contador].antiguedad = antiguedad_input;
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
        "SDO. BRUTO", 
        "IMPUESTO", 
        "SDO. NETO");
    printf("------------------------------ --------------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-30s %15.2f %15.2f %15.2f\n", 
            empleados[i].nombre, 
            empleados[i].sueldo_bruto, 
            empleados[i].impuesto, 
            empleados[i].sueldo_neto);
    }

    printf("------------------------------ --------------- --------------- ---------------\n");
    printf("TOTAL %-24d %15.2f %15.2f %15.2f\n", 
        contador, 
        total_bruto, 
        total_impuesto, 
        total_neto);
    printf("=================================================================\n");

    return 0;
}