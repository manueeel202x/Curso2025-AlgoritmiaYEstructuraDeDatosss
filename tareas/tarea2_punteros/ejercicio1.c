#include<stdio.h>
int esPrimo(int a){
    for(int i=2; i*i<=a; i++){
        if(a%i==0)
            return -1;
    }
    return 1;
}
int encontrarPrimos(int A[], int n, int* x){
    for(int i=2; i<=n; i++){
        if(esPrimo(i)==1){
            A[*x]=i; 
            *x=*x+1;
        }
    }

    if(*x>10){ //*x: numero de factores primos
        return 1;
    }
    return 0;
}

int main(){
    int n;
    printf("Ingrese un numero: ");
    scanf("%d",&n);

    //declaramos el arreglo y una variable que cuente el numero de factores primos 
    int arr[n]; 
    int fact_prim=0;
    
    //llamamos a la funcion encontrarPrimos
    printf("%d",encontrarPrimos(arr,n,&fact_prim));
    
    return 0;
}