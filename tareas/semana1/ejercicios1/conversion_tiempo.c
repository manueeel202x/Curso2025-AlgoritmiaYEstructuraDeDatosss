#include<stdio.h>
void leer(int* T){
    printf("Ingrese el tiempo total en segundos: ");
    scanf("%d",T);
}

void nMinutos(int *T, int *M){
    while(*T>=60){
        (*M)++;
        *T=*T-60;
    }
}

void nHoras(int *H, int *M){
    while(*M>=60){
        (*H)++;
        *M=*M-60;
    }
}

void nSegundos(int *T, int *S){
    *S = *T;
}

void escritura(int H, int M, int S){
    printf("\nEl tiempo es %d horas, %d minutos y %d segundos\n",H,M,S);

}
int main(void){
    int tiempoTotal;
    leer(&tiempoTotal); //funcion para leer los datos

    int tmpHoras=0, tmpMin=0, tmpSeg=0;
    nMinutos(&tiempoTotal,&tmpMin); //actualizo tmpMin y tiempoTotal
    nHoras(&tmpHoras,&tmpMin); //actualizo tmpHoras y tmpMin

    nSegundos(&tiempoTotal,&tmpSeg); //actualizamos tmpSeg
    
    escritura(tmpHoras,tmpMin,tmpSeg);

    return 0;
}