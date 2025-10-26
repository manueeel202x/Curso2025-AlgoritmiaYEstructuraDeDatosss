#include <stdio.h>
#include <string.h>

#define MONTO_POR_KM 3.00
#define MAX_INFRACCIONES 100

typedef struct {
    char placa[11];
    int zona;
    int limite_velocidad;
    int velocidad_vehiculo;
    double multa;
} Infraccion;

void imprimir_linea_reporte(char *vehiculo, char *reg, char *velocidad, char *multa) {
    printf("%-15s %-10s %-10s %10s\n", vehiculo, reg, velocidad, multa);
}

void imprimir_infraccion(const Infraccion *i) {
    printf("%-15s %-10d %-10d %10.2f\n", i->placa, i->zona, i->velocidad_vehiculo, i->multa);
}

int main() {
    Infraccion infracciones[MAX_INFRACCIONES];
    int cont_infracciones = 0;
    int zona_input = 0;
    
    int total_infracciones_zona[4] = {0, 0, 0, 0};
    double monto_recaudado_zona[4] = {0.0, 0.0, 0.0, 0.0};

    while (cont_infracciones < MAX_INFRACCIONES) {
        char placa_input[11];
        int limite_input, velocidad_input;

        if (cont_infracciones == 0) {
            printf("Ingrese Numero de Placa (o \"fin\" para terminar): ");
        } else {
            printf("Ingrese Numero de Placa: ");
        }
        scanf("%10s", placa_input);

        if (strcmp(placa_input, "fin") == 0 || strcmp(placa_input, "FIN") == 0) {
            break;
        }

        printf("Ingrese Zona (1, 2 o 3): ");
        if (scanf("%d", &zona_input) != 1 || zona_input < 1 || zona_input > 3) {
            printf("Zona invalida. Finalizando captura.\n");
            break;
        }

        printf("Ingrese Limite de Velocidad (km/h): ");
        if (scanf("%d", &limite_input) != 1) break;

        printf("Ingrese Velocidad del Vehiculo (km/h): ");
        if (scanf("%d", &velocidad_input) != 1) break;

        if (velocidad_input > limite_input) {
            Infraccion nueva;
            int exceso = velocidad_input - limite_input;
            
            strcpy(nueva.placa, placa_input);
            nueva.zona = zona_input;
            nueva.limite_velocidad = limite_input;
            nueva.velocidad_vehiculo = velocidad_input;
            nueva.multa = (double)exceso * MONTO_POR_KM;

            infracciones[cont_infracciones] = nueva;

            total_infracciones_zona[zona_input]++;
            monto_recaudado_zona[zona_input] += nueva.multa;

            cont_infracciones++;
        } else {
            printf("El vehiculo no excedio el limite de velocidad. No se registra infraccion.\n");
        }
        printf("\n");
    }

    /* Generacion del Reporte */
    printf("\n=======================================================\n");
    printf("        INFRACCIONES A LOS LIMITES DE VELOCIDAD\n");
    printf("=======================================================\n");
    
    imprimir_linea_reporte("VEHICULO", "ZONA", "VELOCIDAD", "MULTA");
    printf("--------------- ---------- ---------- ----------\n");

    for (int i = 0; i < cont_infracciones; i++) {
        imprimir_infraccion(&infracciones[i]);
    }

    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("ZONA 1 : TOTAL DE INFRACCIONES : %d\n", total_infracciones_zona[1]);
    printf("         MONTO RECAUDADO EN MULTAS : %.2f\n", monto_recaudado_zona[1]);
    printf("-------------------------------------------------------\n");
    printf("ZONA 2 : TOTAL DE INFRACCIONES : %d\n", total_infracciones_zona[2]);
    printf("         MONTO RECAUDADO EN MULTAS : %.2f\n", monto_recaudado_zona[2]);
    printf("-------------------------------------------------------\n");
    printf("ZONA 3 : TOTAL DE INFRACCIONES : %d\n", total_infracciones_zona[3]);
    printf("         MONTO RECAUDADO EN MULTAS : %.2f\n", monto_recaudado_zona[3]);
    printf("-------------------------------------------------------\n");

    return 0;
}