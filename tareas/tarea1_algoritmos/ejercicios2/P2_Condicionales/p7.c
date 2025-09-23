#include <stdio.h>
int main(){
    double a,b,c,d,e,f,det,x,y;
    printf("Ingrese los coeficientes a b c d e f: ");
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
    det=a*e-b*d;
    if(det!=0){
        x=(c*e-b*f)/det;
        y=(a*f-c*d)/det;
        printf("Solucion: x=%.4f, y=%.4f\n",x,y);
    }else{
        printf("El sistema no tiene solucion unica.\n");
    }
    return 0;
}
