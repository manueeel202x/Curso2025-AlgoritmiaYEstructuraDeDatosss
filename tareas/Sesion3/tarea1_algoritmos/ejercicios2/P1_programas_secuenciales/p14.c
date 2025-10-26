#include<stdio.h>
int main(void){
    float dolares;
    printf("Ingresa el numero de dolares a comprar: ");
    scanf("%f",&dolares);
    
    printf("\n*TIPOS DE CAMBIO*\n");
    printf("-----------------\n");

    float yenes,pesetas,librasEst,soles;
    printf("Yenes (costo de un dolar): ");
    scanf("%f",&yenes);
    printf("Pesetas (costo de un dolar): ");
    scanf("%f",&pesetas);
    printf("Libras esterlinas (costo de un dolar): ");
    scanf("%f",&librasEst);
    printf("Soles (costo de un dolar): ");
    scanf("%f",&soles);

    //equivalencias
    printf("\nCantidad a pagar (en las diferentes monedas) de %f dolares",dolares);
    printf("\nEn yenes: %.2f",dolares*yenes);
    printf("\nEn pesetas: %.2f",dolares*pesetas);
    printf("\nEn libras esterlinas: %.2f",dolares*librasEst);
    printf("\nEn soles: %.2f",dolares*soles);
    
    return 0;
}