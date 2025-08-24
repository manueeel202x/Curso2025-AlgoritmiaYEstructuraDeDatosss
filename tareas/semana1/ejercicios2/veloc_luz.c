#include<stdio.h>
int main(void){
    double veloc_luz=300000; //en km
    double seg;
    printf("Ingrese un numero real de segundos: ");
    scanf("%f",&seg);

    double dist=veloc_luz*seg;
    printf("\nEn %.2lf segundos, la luz recorre %.2lf kilometros",seg,dist);
    printf("\nEn metros: %.2lf",dist*1000);
    return 0;
}