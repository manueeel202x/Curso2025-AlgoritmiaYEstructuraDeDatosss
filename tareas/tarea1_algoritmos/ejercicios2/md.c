#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void llenar(int A[], int t){
    for(int i=0; i<t; i++) {
        A[i]=(rand()%100)+1; //aleatorios entre 1 y 100
    }
}
void imprimir(int A[], int t){
    printf("\nLos valores del arreglo son:\n");
    for(int i=0; i<t; i++){
        printf("%d ",A[i]);
    }
}
float media(int A[], int t){
    float X=0;
    for(int i=0; i<t; i++){
        X+=A[i];
    }
    return X/t; //promedio
}
float desv_med(int A[], int t, float X){
    float dm=0;
    for(int i=0; i<t; i++){
        dm+=abs(A[i]-X);
    }
    dm/=t;
    return dm;
}
float desv_tip(int A[], int t, float X){
    float dt=0;
    for(int i=0; i<t; i++){
        dt+=pow(A[i]-X,2);
    }
    dt/=t;
    return dt;
}
int main() {
    srand(time(NULL)); 
    int n;
    printf("Ingrese el numero de elementos: ");
    scanf("%d",&n);
    int datos[n];

    llenar(datos,n);
    imprimir(datos,n);
    float promedio = media(datos,n);
    float dm=desv_med(datos,n,promedio);
    float dt=desv_tip(datos,n,promedio);

    //imprimiendo resultados
    printf("\nMedia de los datos: %.4f",promedio);
    printf("\nDesviacion media: %.4f",dm);
    printf("\nDesviacion estandar: %.4f",dt);
    printf("\n");

    return 0;
}