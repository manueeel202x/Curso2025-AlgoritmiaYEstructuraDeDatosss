#include <stdio.h>
int main() {
    double inversionMensual,tasa,saldo=0;
    char opcion='S';

    printf("Ingrese la inversion mensual: ");
    scanf("%lf",&inversionMensual);

    printf("Ingrese la tasa de interes mensual (en %%): ");
    scanf("%lf",&tasa);

    tasa=tasa/100;

    int anio=1;

    while(opcion=='S') {
        for(int mes=1; mes<=12;mes++){
            saldo+=inversionMensual; 
            saldo+=saldo*tasa;     
        }

        printf("Saldo tras el año %d: %.3f\n",anio,saldo);
        printf("¿Desea procesar un año mas? (S/N): ");
        scanf("%c",&opcion);
        anio++;
    }
    return 0;
}
