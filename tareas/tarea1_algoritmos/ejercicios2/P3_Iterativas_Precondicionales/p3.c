#include<stdio.h>
void leer(float T[], int t){
    for(int i=0; i<t; i++){
        printf("Temperatura [%d]: ",i);
        scanf("%f",&T[i]);
    }
}

void conversion(float T[], int t){
    printf("Fahrenheit\t\tCentigrados\n");
    printf("-----------------------------------\n");

    for(int i=0; i<t; i++){
        float C=(T[i]-32)*5/9; //equivalencia farenheit-centigrados
        printf("%.2f\t\t\t%.2f\n",T[i],C);
    }
}

int main(void){
    printf("CONVERSION GRADOS FARENHEIT A GRADOS CELSIUS\n");
    printf("--------------------------------------------\n");

    int n;
    printf("Digite el numero de temperaturas (en F) a ingresar: ");
    scanf("%d",&n);
    float temps[n];

    printf("\n");
    leer(temps,n);    
    conversion(temps,n);

    return 0;
}