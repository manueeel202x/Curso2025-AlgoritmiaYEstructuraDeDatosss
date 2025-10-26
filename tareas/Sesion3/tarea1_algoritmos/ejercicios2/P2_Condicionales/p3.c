#include<stdio.h>
int main(void){
    float A,B,C;
    printf("Ingresa la medida del angulo A: ");
    scanf("%f",&A);
    printf("Ingresa la medida del angulo B: ");
    scanf("%f",&B);
    printf("Ingresa la medida del angulo C: ");
    scanf("%f",&C);

    if(A==90||B==90||C==90)
        printf("\nEl triangulo es un triángulo rectángulo");
    else if(A<90&&B<90&&C<90)
        printf("\nEl triangulo es un triangulo acutangulo");
    else if(A<180&&B<180&&C<180)
        printf("\nEl triangulo es un triangulo obtusangulo");
    else
        printf("El triangulo no existe");
    return 0;
}