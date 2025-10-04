#include <stdio.h>

int main() {
    int cantidad_personas_viaje;
    double peso_viaje;
    
    int total_viajes = 0;
    int total_personas = 0;
    double total_peso = 0.0;
    
    printf("--- REGISTRO DE VIAJES DEL ELEVADOR ---\n");
    printf("Ingrese 0 personas o 0 peso para terminar la jornada.\n\n");

    /* Ciclo de lectura de viajes */
    while (1) {
        printf("Viaje %d:\n", total_viajes + 1);
        printf("  Cantidad de personas: ");
        if (scanf("%d", &cantidad_personas_viaje) != 1) {
            break;
        }

        if (cantidad_personas_viaje <= 0) {
            break;
        }

        printf("  Peso total del viaje (Kilos): ");
        if (scanf("%lf", &peso_viaje) != 1) {
            break;
        }

        if (peso_viaje <= 0.0) {
            break;
        }

        /* Acumulacion de datos */
        total_viajes++;
        total_personas += cantidad_personas_viaje;
        total_peso += peso_viaje;
        printf("\n");
    }

    /* Calculo de promedios */
    double promedio_personas_viaje = 0.0;
    double promedio_peso_viaje = 0.0;

    if (total_viajes > 0) {
        promedio_personas_viaje = (double)total_personas / total_viajes;
        promedio_peso_viaje = total_peso / total_viajes;
    }

    /* Impresion del Reporte Estadistico */
    printf("\n==============================================\n");
    printf("             ESTADÍSTICA DEL DIA\n");
    printf("==============================================\n");
    printf("%-35s : %9d\n", "CANTIDAD DE VIAJES", total_viajes);
    printf("%-35s : %9d\n", "CANTIDAD DE PERSONAS TRANSPORTADAS", total_personas);
    printf("%-35s : %9.2f\n", "PESO TRANSPORTADO (KILOS)", total_peso);
    printf("%-35s : %9.2f\n", "PROMEDIO DE PERSONAS POR VIAJE", promedio_personas_viaje);
    printf("%-35s : %9.2f\n", "PROMEDIO DE PESO POR VIAJE", promedio_peso_viaje);
    printf("==============================================\n");

    return 0;
}