#include<stdio.h>
int main(void){
    double x;
    printf("Ingrese un valor real x: ");
    scanf("%lf",&x);

    double y = 3*x*x + 7*x - 15;
    printf("El resultado (Y) es: %.5lf",y);
    return 0;
}