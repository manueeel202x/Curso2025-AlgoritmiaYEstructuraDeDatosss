#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main(void){
    
    float x=-1.0;
    printf("x\tTangente(x)\tSecante(x)\tCosecante(x)\n");
    printf("----------------------------------------------------\n");
    
    while(x<=1){
        if(!(cos(x)==0 || sin(x)==0)){
            printf("%.1f\t%.2f\t\t%.2f\t\t%.2f\n",x,tan(x),1/cos(x),1/sin(x));
        }
        x+=0.1;
    }
    
    return 0;
}