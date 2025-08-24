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

    if(largo*ancho>400){
        costo_t=costo_t*0.9; //descuento del 10%, paga el resto (90%)
        printf("El costo total del terreno es %.2f soles (con descuento de 10%)",costo_t);
    }
    else{
        printf("El costo total del terreno es %.2f soles",costo_t);
    }
    
    return 0;
}