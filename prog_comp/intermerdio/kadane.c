#include<stdio.h>
int main(void){
    int n;
    printf("Tamano del arreglo: ");
    scanf("%d",&n);

    //cremos  y llenaomso el arreglo
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    int suma=A[0]; int suma_max=A[0];
    int i=0, j=1;

    while(j<n){
        suma+=A[j];
        if(suma>suma_max)
            suma_max=suma;
        
        if(A[j]>suma){
            suma=A[j];
            i=j;
            if(suma>suma_max){
                suma_max=suma;
            }
        }
        j++;
    }

    printf("%d",suma_max);
    
    return 0;
}