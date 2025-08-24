#include<stdio.h>
int main(void){
    char nombre[20];
    int tipoEmp, horasT;
    float pagoHora, sueldo;

    printf("CALCULO DEL SUELO DE UN TRABAJADOR");
    printf("\n---------------------------------");
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    printf("Ingrese el numero de tipo de trabajador (1-4)");
    scanf("%d",&tipoEmp);
    printf("Ingrese su numero de horas trabajadas: ");
    scanf("%d",&horasT);
    printf("Ingrese su pago por hora: ");
    scanf("%f",&pagoHora);

    sueldo=horasT*pagoHora;
    if(horasT>40){
        int horasExt=horasT-40;
        switch(tipoEmp){
            case 1: sueldo+=horasExt*1.5*pagoHora; break;
            case 2: sueldo+=horasExt*2.0*pagoHora; break;
            case 3: sueldo+=horasExt*2.5*pagoHora; break;
            case 4: sueldo+=horasExt*3.0*pagoHora; break;
            default: printf("Tipo de empleado no valido");
        }
    }

    printf("\nSu sueldo total es %.2f soles",sueldo);
    
    return 0;
}