#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); 
    int numeros[10];

    for(int i=0; i<10; i++) {
        numeros[i]=rand()%10+1;
    }

    int n=10;
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(numeros[j]>numeros[j+1]){
                int aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux;
            }
        }
    }
    
    for(int i=0;i<10;i++){
        printf("%d ",numeros[i]);
    }
    printf("\n");
    return 0;
}