#include<stdio.h>
int main(void){
    int N;
    printf("Digite un numero par: ");
    scanf("%d",&N);

    int suma=0;

    if(N<2)
        printf("Error. Ingrese un numero par mayor a 2");
    else{
        int i=2;
        while(i<=N){
        suma+=i;
        i+=2;
        }
    }

    printf("\nLa suma de los numeros pares desde 2 hasta %d es %d\n",N,suma);

    return 0;
}