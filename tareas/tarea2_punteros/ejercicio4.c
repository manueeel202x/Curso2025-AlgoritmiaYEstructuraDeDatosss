/*
    ● Declare variables a, b, c, d del tipo int. 
    ● Declare variables e, f, g, h del tipo float. 
    ● Declare un vector v de 10 elementos del tipo char. 
    ● Declare una variable x del tipo int. 
    ● Cree un puntero que apunte a la dirección de a. 
    ● Incremente el puntero mostrando el contenido de la dirección apuntada (en 
    forma de número). En caso de que la dirección coincida con la dirección de 
    alguna otra variable, informar el hecho.
*/
#include<stdio.h>
int main(void){
    int a=2,b,c,d;
    float e,f,g,h;
    char v[10];
    int x;
    int *p=&a;
    //18
    for(int i=0; i<5; i++){
        p=p+1;
        printf("Direccion actual de p: %p\n",p);
        if(p==&b) printf("La direccion de p es igual a la de 'b'\n");
        if(p==&c) printf("La direccion de p es igual a la de 'c'\n");
        if(p==&d) printf("La direccion de p es igual a la de 'd'\n");
        if(p==(int*)&e) printf("La direccion de p es igual a la de 'e'\n");
        if(p==(int*)&f) printf("La direccion de p es igual a la de 'f'\n");
        if(p==(int*)&g) printf("La direccion de p es igual a la de 'g'\n");
        if(p==(int*)&h) printf("La direccion de p es igual a la de 'h'\n");
        for(int i=0; i<10; i++){
            if(p==(int*)&v[i]) printf("La direccion de p es igual a la de v[%d]\n",i);
        }
        if(p==&x) printf("La direccion de p es igual a la de 'x'\n");
    }
    

    return 0;
}