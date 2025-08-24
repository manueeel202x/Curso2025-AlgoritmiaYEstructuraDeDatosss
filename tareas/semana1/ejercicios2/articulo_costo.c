#include<stdio.h>
int main(void){
    char articulo[500];
    printf("Ingresa el nombre del articulo: ");
    fgets(articulo,sizeof(articulo),stdin);

    float Pcosto, PcostoReal, impuesto, utilidad, Pventa;
    printf("Ingresa el precio de costo del producto: ");
    scanf("%f",&Pcosto);
    impuesto=0.19*Pcosto;
    PcostoReal=Pcosto+impuesto;
    utilidad=PcostoReal*1.5;
    Pventa=PcostoReal+utilidad;
    
    //imprimiendo datos
    printf("\nArticulo: %s",articulo);
    printf("\nUtilidad: %f", utilidad);
    printf("\nImpuesto: %f",impuesto);
    printf("\nPrecio de venta: %f",Pventa);
    return 0;
}