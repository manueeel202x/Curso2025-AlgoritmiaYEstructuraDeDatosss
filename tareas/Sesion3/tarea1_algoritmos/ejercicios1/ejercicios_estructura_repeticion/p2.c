#include<stdio.h>
void n_digitos(int *num){
    int dig=0;
    while(*num>0){
        *num=*num/10;
        dig++;
    }
    printf("El numero ingresado tiene %d digitos",dig);
}
int main(void){
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d",&n);
    
    n_digitos(&n);
    return 0;
}