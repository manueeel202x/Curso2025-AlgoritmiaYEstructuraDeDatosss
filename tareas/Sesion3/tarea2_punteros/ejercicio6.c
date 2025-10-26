/*
    ● Reciba 3 números como parámetros: A, B y C. 
    ● Los ordene de tal forma que, al final de la función, A contenga el menor número y 
    C el mayor. 
    ● Hacer un programa que reciba 3 números del usuario, llame a la función y 
    muestre los números ordenados
*/
#include<stdio.h>
void ordenar(int* x1,int *x2,int *x3){
    int max=*x1;
    if(*x2>max)
        max=*x2;
    if(*x3>max)
        max=*x3;
    
    int aux;
    if(*x1==max){
        aux=*x3;
        *x3=max;
        if(aux<*x2){
            *x1=aux;
        }
        else{
            *x1=*x2;
            *x2=aux;
        }
    }
    else if(*x2==max){
        aux=*x3;
        *x3=max;
        if(aux<*x1){
            *x2=*x1;
            *x1=aux;
        }
        else{
            *x2=aux;
        }
    }
    else{ //x3==max
        if(*x1>*x2){
            aux=*x1;
            *x1=*x2;
            *x2=aux;
        }
        //el otro caso es trivial: x1<x2<x3
    }    
}
int main(){
    int a,b,c;
    printf("Ingrese 3 numeros enteros (a,b,c): ");
    scanf("%d %d %d",&a,&b,&c);
    ordenar(&a,&b,&c);
    printf("Ahora, 'a' es el menor de los numeros: %d\n",a);
    printf("'b' es el numero de en medio: %d\n",b);
    printf("'c' es el mayor de los numeros: %d\n",c);
}