#include<stdio.h>
int main(void){
    double C,F; //centigrados y farenheit, respectivamente
    printf("Ingrese una temperatura en Centigrados: ");
    scanf("%lf",&C);
    F=(9/5)*C + 32;
    printf("La temperatura Fahrenheit equivalente es %.5lf",F);
    
    return 0;
}