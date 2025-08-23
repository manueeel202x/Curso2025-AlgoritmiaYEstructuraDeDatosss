#include<stdio.h>

int main(){
    int numero;
    double errorMaximo;
    double raiz;

    printf("Ingrese el numero para calcular la raiz cuadrada: ");
    scanf("%d", &numero);
    printf("Ingrese el error maximo permitido: ");
    scanf("%lf", &errorMaximo);

    if(numero==0){
        raiz=0.0;
    }else{
        raiz=numero/2.0; 
        while((raiz*raiz-numero)>errorMaximo||(numero-raiz*raiz)>errorMaximo){
            raiz=(raiz+(double)numero/raiz)/2.0;
        }
    }

    printf("La raiz cuadrada aproximada de %d es: %.10f\n", numero, raiz);

    return 0;
}