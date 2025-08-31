#include<stdio.h>
int main(void){
    int n;
    printf("Tamano del arreglo: ");
    scanf("%d",&n);

    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    int i=0, aux;
    while(i<n/2){
        aux=A[i];
        A[i]=A[n-1-i];
        A[n-1-i]=aux;
        i++;
    }

    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    return 0;
}