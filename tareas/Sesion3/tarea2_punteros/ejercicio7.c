/*
    ● Reciba como parámetros dos variables enteras, X y Y. 
    ● Devuelva en X la suma de X y Y. 
    ● Devuelva en Y la resta de X y Y. 
    ● Pregunta: ¿el paso de parámetros a la función debe hacerse por valor o por 
    referencia? 
*/
#include<stdio.h>
void CALCULA(int* x,int* y){
    int suma=*x+*y;
    int resta=*x-*y;
    *x=suma;
    *y=resta;
}
int main(){
    int x,y;
    printf("Ingrese dos numeros enteros (x,y): ");
    scanf("%d %d",&x,&y);

    CALCULA(&x,&y);
    printf("Ahora, 'x' guarda la suma (x+y): %d\n",x);
    printf("y 'y' guarda la resta (x-y): %d\n",y);

    /*Pregunta: ¿el paso de parámetros a la función debe hacerse por valor o por 
    referencia?
    Rpta: El paso debe ser por referencia para poder modificar los valores de 'x' e 'y'
    */
    return 0;
}