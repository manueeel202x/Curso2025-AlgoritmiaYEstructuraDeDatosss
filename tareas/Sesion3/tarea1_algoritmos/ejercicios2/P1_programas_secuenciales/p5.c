#include<stdio.h>
int main(void){
    printf("*Calculo del costo de un terro rectangular\n*");
    printf("-------------------------------------------\n");
    printf("\n");

    float ancho,largo,costo_u,costo_t;
    printf("Ingresa el ancho del terreno: ");
    scanf("%f",&ancho);
    printf("Ingresa el largo del terreno: ");
    scanf("%f",&largo);
    printf("Ingresa el costo unitario (por m2) del terreno: ");
    scanf(" %f",&costo_u);

    costo_t=(ancho*largo)*costo_u;
    printf("El costo total del terreno es %.2f soles",costo_t);

    return 0;
}