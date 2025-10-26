#include<stdio.h>

int main(){
    float depositoMensual=1000.0;
    float tasa=0.03;
    int anos=10;
    int meses=anos*12;
    float total=0.0;

    for(int i=1; i<=meses;i++){
        total=total+depositoMensual;
        total=total+(total*tasa);
    }

    printf("Cantidad ahorrada en 10 años: %.2f\n",total);

    return 0;
}