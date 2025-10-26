/*
    Elaborar un programa que permita hacer conversiones de temperaturas entre grados Fahrenheit, Celsius, Kelvin y Rankine. Primero debe preguntar qué tipo de grados quiere convertir. Por ejemplo; si se le indica que se desea convertir una temperatura en grados Fahrenheit, debe leer la cantidad de grados, y luego calcular e imprimir su equivalente en grados Celsius, kelvin y Rankine, y así, debe hacer lo mismo para cada uno de los otros tipos. Para convertir a Celsius la temperatura Fahrenheit se le resta 32 y se multiplica por 5/9. para convertir a Kelvin, se le suma 273 a los grados Celsius. Para convertir a Rankine a los grados Fahrenheit se le suma 460.
*/

#include <stdio.h>
int main() {
    int opcion;
    double temp,celsius,fahrenheit,kelvin,rankine;

    printf("Conversor de temperaturas\n");
    printf("Seleccione el tipo de grados que quiere convertir:\n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    printf("4. Rankine\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: 
            printf("Ingrese la temperatura en Fahrenheit: ");
            scanf("%lf", &temp);
            fahrenheit=temp;
            celsius=(fahrenheit-32)*5.0/9.0;
            kelvin=celsius+273;
            rankine=fahrenheit+460;
            printf("\n%.2f °F equivalen a:\n", fahrenheit);
            printf("%.2f °C\n",celsius);
            printf("%.2f K\n",kelvin);
            printf("%.2f °R\n",rankine);
            break;

        case 2:
            printf("Ingrese la temperatura en Celsius: ");
            scanf("%lf", &temp);
            celsius=temp;
            fahrenheit=(celsius*9.0/5.0)+32;
            kelvin=celsius+273;
            rankine=fahrenheit+460;
            printf("\n%.2f °C equivalen a:\n", celsius);
            printf("%.2f °F\n",fahrenheit);
            printf("%.2f K\n",kelvin);
            printf("%.2f °R\n",rankine);
            break;

        case 3: 
            printf("Ingrese la temperatura en Kelvin: ");
            scanf("%lf", &temp);
            kelvin=temp;
            celsius=kelvin-273.15;
            fahrenheit=(celsius*9.0/5.0)+32;
            rankine=fahrenheit+460;
            printf("\n%.2f K equivalen a:\n", kelvin);
            printf("%.2f °C\n", celsius);
            printf("%.2f °F\n", fahrenheit);
            printf("%.2f °R\n", rankine);
            break;

        case 4: 
            printf("Ingrese la temperatura en Rankine: ");
            scanf("%lf", &temp);
            rankine=temp;
            fahrenheit=rankine-460;
            celsius=(fahrenheit-32)*5.0/9.0;
            kelvin=celsius+273;
            printf("\n%.2f °R equivalen a:\n",rankine);
            printf("%.2f °F\n",fahrenheit);
            printf("%.2f °C\n",celsius);
            printf("%.2f K\n",kelvin);
            break;

        default:
            printf("Opción no válida.\n");
    }
    return 0;
}
