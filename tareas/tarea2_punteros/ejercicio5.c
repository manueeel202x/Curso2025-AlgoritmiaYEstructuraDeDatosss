/*
    ● Reciba dos números enteros del usuario. 
    ● Devuelva 1 si los números son iguales, 0 si son diferentes y –1 si la suma o el 
    producto desbordan el rango de los enteros. Además, debe retornar la suma y el 
    producto de los dos números. 
    ● Hacer un programa que reciba dos números del usuario, llame a la función y 
    muestre si los números son iguales. Además, debe mostrar su suma y su 
    producto. 
*/
#include<stdio.h>
#include<limits.h>
int suma_y_producto(int x, int y){
    printf("Suma de los numeros: %d\n",x+y);
    printf("Producto de los numeros: %d\n",x*y);
    if(x==y)
        printf("Los numeros son iguales\n");
    else if(x!=y)
        printf("Los numeros son diferentes\n");
    
    if(x+y>INT_MAX||x*y>INT_MAX)
        printf("La suma o producto superaron el tamano limite de los enteros\n");
}
int main(void){
    int a,b;
    printf("Ingrese 2 enteros: ");
    scanf("%d %d",&a,&b);
    suma_y_producto(a,b);
    
    return 0;   
}