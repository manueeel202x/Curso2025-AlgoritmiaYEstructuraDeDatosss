#include<stdio.h>
#include<math.h>
int main(void){
    float a,b;
    printf("Ingresa valores para a y b, en ese orden:");
    scanf("%f %f %f %f %f",&a,&b);

    printf("\n");
    float Y=3*a*a*b*b*sqrt(2*a);
    float W=sqrt(pow(2,a)*a)*Y;
    float Z=Y/W;

    printf("Y: %.2f\nW: %.2f\nZ: %.2f\n",Y,W,Z);
    return 0;
}