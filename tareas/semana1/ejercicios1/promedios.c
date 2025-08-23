#include<stdio.h>
void calcularProm(int *p, int t, float *prom);
void estadoAlumno(float *prom);
int main(void){
    int n;
    printf("Ingrese el numero de notas del curso: ");
    scanf("%d",&n);

    int notas[n];
    printf("\nRecordar que la suma de pesos de las notas debe ser igual a 1\n");
    float promedio=0;
    calcularProm(notas,n,&promedio);
    estadoAlumno(&promedio);
    return 0;
}

void calcularProm(int *p, int t, float *prom){
    float peso;
    for(int i=0; i<t; i++){
        printf("Ingrese la nota %d: ",i+1);
        scanf("%d",p+i);
        printf("Ingrese el peso de la nota: ");
        scanf("%f",&peso);
        *prom = *prom + p[i]*peso;
        printf("\n");
    }

    printf("\nEl promedio del curso es %.2f",*prom);
}

void estadoAlumno(float* prom){
    if(*prom>6)
        printf("Estado del alumno: Aprobado");
    else if(*prom>=4)
        printf("Estado del alumno: Verificacion suplementaria");
    else
        printf("Estado del alumno: Desaprobado");
    printf("\n");
}