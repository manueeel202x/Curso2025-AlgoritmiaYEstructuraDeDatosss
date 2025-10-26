#include <stdio.h>

#define NUM_MATERIALES 6

const int unidades_por_producto[NUM_MATERIALES] = {3, 4, 1, 2, 3, 2}; 

void imprimir_reporte(double costos_unitarios[], long long total_unidades_requeridas[]) {
    double costo_total = 0.0;
    
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("        LISTADO DE MATERIALES REQUERIDOS\n");
    printf("------------------------------------------------------\n");
    printf("MATERIAL | CANTIDAD DE UNIDADES | COSTO ESTIMADO\n");
    printf("---------|----------------------|------------------\n");

    for (int i = 0; i < NUM_MATERIALES; i++) {
        double costo_estimado = (double)total_unidades_requeridas[i] * costos_unitarios[i];
        costo_total += costo_estimado;
        
        printf("%8d | %20lld | %16.2f\n", 
               i + 1, 
               total_unidades_requeridas[i], 
               costo_estimado);
    }
    
    printf("------------------------------------------------------\n");
    printf("                                       COSTO TOTAL %16.2f\n", costo_total);
    printf("------------------------------------------------------\n");
}

int main() {
    double costos_unitarios[NUM_MATERIALES];
    long long total_unidades_requeridas[NUM_MATERIALES] = {0};
    int unidades_pedido = -1;
    
    for (int i = 0; i < NUM_MATERIALES; i++) {
        printf("Ingrese el costo unitario para el Material %d: ", i + 1);
        if (scanf("%lf", &costos_unitarios[i]) != 1) {
            return 1;
        }
    }
    
    printf("\n--- Inicio de Lectura de Pedidos ---\n");
    
    while (1) {
        printf("Ingrese la cantidad de unidades del Producto A en el pedido (0 para terminar): ");
        if (scanf("%d", &unidades_pedido) != 1) {
            break;
        }
        
        if (unidades_pedido <= 0) {
            break;
        }
        
        for (int i = 0; i < NUM_MATERIALES; i++) {
            total_unidades_requeridas[i] += (long long)unidades_pedido * unidades_por_producto[i];
        }
    }

    imprimir_reporte(costos_unitarios, total_unidades_requeridas);
    
    return 0;
}