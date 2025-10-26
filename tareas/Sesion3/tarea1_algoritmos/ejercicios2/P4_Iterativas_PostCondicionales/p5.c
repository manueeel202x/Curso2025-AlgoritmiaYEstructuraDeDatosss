#include <stdio.h>
#include <string.h>

#define MAX_MOVIMIENTOS 100
#define MAX_NOMBRE 50

typedef struct {
    int numero;
    double deposito;
    double retiro;
    double saldo_resultante;
} Movimiento;

int main() {
    char nombre_cuentahabiente[MAX_NOMBRE];
    double saldo_inicial;
    Movimiento movimientos[MAX_MOVIMIENTOS];
    int contador = 0;
    double saldo_actual;
    double total_depositos = 0.0;
    double total_retiros = 0.0;
    int opcion;

    /* 1. Captura de datos iniciales */
    printf("--- INICIO DE CUENTA DE CHEQUES ---\n");
    printf("Ingrese el Nombre del Cuentahabiente: ");
    scanf("%49[^\n]", nombre_cuentahabiente);

    printf("Ingrese el Saldo Inicial: ");
    if (scanf("%lf", &saldo_inicial) != 1 || saldo_inicial < 0) {
        printf("Saldo inicial invalido. Terminando programa.\n");
        return 1;
    }
    saldo_actual = saldo_inicial;

    /* 2. Captura de movimientos */
    printf("\n--- REGISTRO DE MOVIMIENTOS ---\n");
    while (contador < MAX_MOVIMIENTOS) {
        double monto;

        printf("\nTipo de movimiento (1=Deposito, 2=Retiro, 0=Terminar): ");
        if (scanf("%d", &opcion) != 1) break;

        if (opcion == 0) {
            break;
        }

        if (opcion != 1 && opcion != 2) {
            printf("Opcion invalida. Intente de nuevo.\n");
            continue;
        }

        printf("Ingrese el monto: ");
        if (scanf("%lf", &monto) != 1 || monto < 0) {
            printf("Monto invalido. Terminando registro.\n");
            break;
        }
        
        /* Inicializar el nuevo movimiento */
        Movimiento nuevo_mov = {0};
        nuevo_mov.numero = contador + 1;
        
        if (opcion == 1) { /* Depósito */
            nuevo_mov.deposito = monto;
            saldo_actual += monto;
            total_depositos += monto;
        } else { /* Retiro */
            if (monto > saldo_actual) {
                printf("Fondos insuficientes. Retiro cancelado.\n");
                continue;
            }
            nuevo_mov.retiro = monto;
            saldo_actual -= monto;
            total_retiros += monto;
        }
        
        nuevo_mov.saldo_resultante = saldo_actual;
        movimientos[contador] = nuevo_mov;
        contador++;
    }

    /* 3. Impresión del Reporte de Estado de Cuenta */
    printf("\n=================================================================================\n");
    printf("                                ESTADO DE CUENTA\n");
    printf("=================================================================================\n");
    printf("CUENTA HABIENTE: %s\n", nombre_cuentahabiente);
    printf("SALDO INICIAL : %15.2f\n", saldo_inicial);
    printf("---------------------------------------------------------------------------------\n");
    printf("%-10s %15s %15s %15s\n", 
        "MOV.", 
        "DEPOSITO", 
        "RETIRO", 
        "SALDO");
    printf("---------- --------------- --------------- ---------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-10d %15.2f %15.2f %15.2f\n", 
            movimientos[i].numero, 
            movimientos[i].deposito, 
            movimientos[i].retiro, 
            movimientos[i].saldo_resultante);
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("%-10s %15.2f %15.2f %15.2f\n", 
        "TOTALES", 
        total_depositos, 
        total_retiros, 
        saldo_actual);
    printf("=================================================================================\n");

    return 0;
}