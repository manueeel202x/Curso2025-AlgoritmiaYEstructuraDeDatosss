#include<stdio.h>
int main(void){
    float x;
    printf("Ingrese x: ");
    scanf("%f",&x);

    float y;
    if(x>=0)
        y=x*x+6;
    else    
        y=3*x+6;

    printf("Y: %.2f",y);
    return 0;
}