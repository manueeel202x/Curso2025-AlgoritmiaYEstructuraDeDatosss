#include<stdio.h>
#include<math.h>
int main(void){
    float ang;
    printf("Ingrese la medida de un angulo en radianes (rad): ");
    scanf("%f",&ang);

    double tangente=tan(ang);
    double ctg=1/tangente;
    double secante=1/cos(ang);
    double cosecante=1/sin(ang);

    printf("\nTangente: %.5lf",tangente);
    printf("\nCotangente: %.5lf",ctg);
    printf("\nSecante: %.5lf",secante);
    printf("\nCosecante: %.5lf",cosecante);
    
    return 0;
}