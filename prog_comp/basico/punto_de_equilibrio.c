#include<stdio.h>
int equilibrio(int A[], int n){
    int suma=0;
    for(int i=0; i<n; i++){
        suma+=A[i];
    }

    int i=1, a=0;
    while(i<n-1){
        a=a+A[i-1];
        if(suma-a-A[i]==(suma-A[i])/2)
            return i;
        i++;
    }

    return -1;
}
int main(void){
    
    int n;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d",&n);

    int v[n];
    for(int i=0; i<n; i++){
        printf("Elemento %d: ",i+1);
        scanf("%d",&v[i]);
    }

    printf("%d",equilibrio(v,n));   
    
}