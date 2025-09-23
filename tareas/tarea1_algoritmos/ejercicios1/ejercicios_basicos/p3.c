#include<stdio.h>
#include<string.h>

int main(){
    char nombreProducto[50];
    float precio;
    int cantidad;
    float total;

    printf("Ingrese el nombre del producto: ");
    scanf("%s",nombreProducto);
    printf("Ingrese el precio del producto: ");
    scanf("%f",&precio);
    printf("Ingrese la cantidad comprada: ");
    scanf("%d",&cantidad);

    if(cantidad>=1&&cantidad<=10){
        total=precio*cantidad;
    }else if(cantidad>=11&&cantidad<=20){
        total=(precio*cantidad)*0.90;
    }else if(cantidad>=21&&cantidad<=50){
        total=(precio*cantidad)*0.80;
    }else if(cantidad>50){
        total=(precio*cantidad)*0.75;
    }else{
        printf("Cantidad invalida\n");
        return 0;
    }
    printf("Producto: %s\n",nombreProducto);
    printf("Valor total a pagar: %.2f\n",total);

    return 0;
}