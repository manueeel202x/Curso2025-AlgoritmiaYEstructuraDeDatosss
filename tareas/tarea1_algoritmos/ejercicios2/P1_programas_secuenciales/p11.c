#include<stdio.h>
#include<math.h>
int main(void){
    float W,X,Y,Z,b;
    printf("Ingresa valores para W,X,Y,Z,b en ese orden: ");
    scanf("%f %f %f %f %f",&W,&X,&Y,&Z,&b);
    float resultado = (pow(4*X*X*Y*Y*sqrt(2*Z*W),2))/(4*(pow(X,0.5)))/pow(b,0.75);
    printf("\nEl resultado de la operacion es %.5f",resultado);
    
    return 0;
}