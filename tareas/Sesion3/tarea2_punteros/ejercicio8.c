/*
    ● Reciba como parámetro un número entero n por valor y dos números enteros 
    max y min por referencia. 
    ● Devuelva 0 si el número n es primo y 1 en caso contrario. Si el número no es 
    primo, las variables max y min deben asumir los valores del menor y el mayor 
    divisor entero del número, respectivamente, sin considerar el número 1 ni el 
    propio n. 
*/
#include<stdio.h>

int DIVS(int n, int* min, int* max){
    int primo=1; 
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            primo=0;
            break;
        }
    }
    if(primo==0){
        int i=2;
        while(n%i!=0){
            i++;
        }
        *min=i;

        int j=n/2;
        while(n%j!=0){
            j--;
        }
        *max=j;
        return 1;
    }

    else{//es primo
        return 0;
    }
}

int main(){
    int max, min, n;
    printf("Ingrese un numero entero: ");
    scanf("%d",&n);
    
    if(DIVS(n,&min,&max)==1){
        printf("El menor divisor de %d (diferente de 1) es %d\n",n,min);
        printf("El mayor divisor de %d (diferente de 1 y si mismo) es %d\n",n,max);
    }
    else{
        printf("El numero %d es primo\n",n);
    }
    
    return 0;
}