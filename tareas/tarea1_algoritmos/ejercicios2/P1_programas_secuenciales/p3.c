#include<stdio.h>
int main(void){
    printf("*EQUIVALENCIAS DE MEDIDAS EN PIES*\n");
    printf("----------------------------------\n");

    float pies;
    printf("\nIngrese la medida en pies: ");
    scanf("%f",&pies);

    //equivalencias
    printf("Equivalencias");
    float yardas = 3.0*pies;
    printf("\n\tYardas: %.2f",yardas);
    float pulg = pies/12.0;
    printf("\n\tPulgadas: %.2f",pulg);
    float cent = pulg/2.54;
    printf("\n\tCentimetros: %.2f",cent);
    float met = cent/100.0;
    printf("\n\tMetros: %.2f",met);
    printf("\n");
    return 0;
}