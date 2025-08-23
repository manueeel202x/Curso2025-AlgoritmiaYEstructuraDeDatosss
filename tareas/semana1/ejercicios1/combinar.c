#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void llenar(int A[], int t);
void ordenar(int A[], int t);
void combinar(int A1[],int A2[], int A3[], int t);
void imprimir(int A[], int t);

int main(void){
    srand(time(NULL)); //para los numeros aleatorios
    int t=50; //tamaño de los arreglos desordenados
    int numeros1[50], numeros2[50]; //arreglos a usar
    int combinados[100]; //arreglo donde guardaremos los valores combinados (y ordenados) de A1 y A2

    llenar(numeros1,t); //llenamos A1 Y A2
    llenar(numeros2,t); 
    ordenar(numeros1,t); //ordenamos A1 y A2
    ordenar(numeros2,t);
    combinar(numeros1, numeros2, combinados, t); //combinamos A1 y A2
    imprimir(combinados,100);
    return 0;
}

void llenar(int A[], int t){
    for(int i=0; i<t; i++) {
        A[i]=rand()%100+1;
    }
}

void ordenar(int A[], int t){
    for(int i=1; i<t; i++){
        for(int j=0; j<t-i; j++){
            if(A[j]>A[j+1]){
                int aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
            }
        }
    }
}

void combinar(int A1[], int A2[], int A3[], int t){
    int i=0, j=0, k=0;
    while(i<t && j<t){
        if(A1[i]<A2[j]){
            A3[k]=A1[i];
            i++;
            k++;
        }
        else{
            A3[k]=A2[j];
            j++;
            k++;
        }
    }

    while(i<t){
        A3[k]=A1[i];
        i++;
        k++;
    }
    while(j<t){
        A3[k]=A2[j];
        j++;
        k++;
    }
}

void imprimir(int A[], int t){
    for(int i=0; i<t; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}