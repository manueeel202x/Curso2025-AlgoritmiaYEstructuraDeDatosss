#include<stdio.h>
#include<math.h>
#define e 2.71828
#define PI 3.14159
int main(void){
    float w,z;
    printf("Ingrese un valor para W: ");
    scanf("%f",&w);

    z=pow(e,(-1/2)*w*w)/sqrt(2*PI);
    printf("\nEl valor de z es %.9f",z);
    return 0;
}