#include<stdio.h>
int main(void){
    int notas[4];
    char nombre[20];
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    for(int i=0; i<4; i++){
        printf("Ingrese la calificacion %d: ",i+1);
        scanf("%d",&notas[i]);
    }

    float calif_final = notas[0]*0.3 + notas[1]*0.2 + notas[2]*0.1 + notas[3]*0.4;
    printf("Su calificacion final es %.2f",calif_final);
    return 0;
}