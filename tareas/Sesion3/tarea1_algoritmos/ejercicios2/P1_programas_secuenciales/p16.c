#include<stdio.h>
#include<math.h>
#define PI 3.14159

int main(void){
    double ang,n; 
    printf("Ingresar el angulo en grados sexagesimales: ");
    scanf("%lf",&ang);
    print("Ingresa un numero para calcular su arcotangente: ");
    scanf("%lf",&n);

    ang=ang*(PI/180); //conversion a radianes
    double seno=sin(ang);
    double coseno=cos(ang);
    double arctan=atan(n);

    printf("\nSeno del angulo: ",seno);
    printf("\nCoseno del angulo: ",coseno);
    printf("\nArcotangente del numero: ", arctan);
    
    
    return 0;
}