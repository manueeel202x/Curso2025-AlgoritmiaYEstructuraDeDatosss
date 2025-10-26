#include<stdio.h>
#include<math.h>
int main(void){
    printf("*CONVERSION DE MASA EN ENERGIA: ECUACION DE EINSTEIN*\n");
    printf("----------------------------------------------------\n");

    const double c = 2.99792458*pow(10,10);
    double m; 
    printf("\nIngrese la masa (en gramos): ");
    scanf("%f",&m);

    double E = m*pow(c,2);
    printf("\nLa masa convertida en energia es %10lf ergios",E);
    return 0;
}