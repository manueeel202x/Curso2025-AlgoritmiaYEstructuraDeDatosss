#include<stdio.h>

void primer_triang(int n);
void segundo_triang(int n);
void tercer_triang(int n);

int main(void){
    printf("\nTriangulo de asteriscos\n");
    printf("-----------------------\n");

    int N;
    printf("Ingrese un numero positivo: ");
    scanf("%d",&N);
    
    primer_triang(N);
    printf("\n\n");
    segundo_triang(N);
    printf("\n\n");
    tercer_triang(N);

    return 0;
}

void primer_triang(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void segundo_triang(int n){
    for(int i=0; i<n; i++){
        //bucle para generar los espacios
        for(int k=i; k<n-1; k++){
            printf(" ");
        }

        for(int j=1; j<=2*i+1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void tercer_triang(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        for(int k=1; k<=2*(n-i); k++){
            printf(" ");
        }
        for(int l=1; l<=i; l++){
            printf("*");
        }

        printf("\n");
    }
}