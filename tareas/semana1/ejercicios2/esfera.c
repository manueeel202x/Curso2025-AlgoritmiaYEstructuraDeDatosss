#include<stdio.h>
#define PI 3.14159
int main(void){
    float radio;
    printf("Ingrese el valor del radio de la esfera: ");
    scanf("%f",radio);

    float area=4*PI*radio*radio;
    float vol=(4/3)*PI*radio*radio*radio;

    printf("\nEl area total de la esfera es %.2f u2",area);
    printf("\nEl volumen total de la esfera es %.2f u2",vol);
    
    return 0;
}
