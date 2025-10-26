#include<stdio.h>
#include<math.h>
int main(void){
    printf("*CALCULO DE LA FUERZA GRAVITACIONAL ENTRE 2 CUERPOS*\n");
    printf("----------------------------------------------------\n");

    const double G = 6.673*pow(10,-8);
    float m1, m2, d;
    printf("\nIngrese la masa 1 (en kg): ");
    scanf("%f",&m1);
    printf("Ingrese la masa 2 (en kg): ");
    scanf("%f",&m2);
    printf("Ingrese la distancia entre los cuerpos (en m): ");
    scanf("%f",&d);

    float F = (G*(m1/100.0)*(m2/100.0))/(pow(d/100.0,2));
    printf("\nLa fuerza de atraccion entre los 2 cuerpos (en dinas) es %.5f",F);
    return 0;
}