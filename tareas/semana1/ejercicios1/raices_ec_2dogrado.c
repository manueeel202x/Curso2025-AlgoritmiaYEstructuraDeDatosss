#include<stdio.h>
#include<math.h>
int main(void){
    printf("***RAICES DE UNA ECUACION DE 2DO GRADO***\n");
    float a,b,c;
    //solicitamos la entrada de coeficientes
    printf("Ingrese el termino cuadrático (a): ");
    scanf("%f",&a);
    printf("Ingrese el termino lineal (b): ");
    scanf("%f",&b);
    printf("Ingrese el termino independiente (c): ");
    scanf("%f",&c);

    printf("\nLa ecuacion es %.2fx^2 + %.2fx + %.2f\n",a,b,c);
    
    printf("\n");
    if(a==0)
        printf("La ecuacion es lineal y tiene una única raiz x=%f",-1*b/c);
    else{
        float disc = b*b - 4*a*c; //discriminante
        if(disc>=0){
            float x1,x2;
            x1=(-1*b+sqrt(disc))/(2*a);
            x2=(-1*b-sqrt(disc))/(2*a);
            printf("Las raices reales son:\n\tx1=%.2f , x2=%.2f",x1,x2);
        }
        else{
            printf("La ecuacion no admite soluciones reales");
        }
    }
    return 0;
}
