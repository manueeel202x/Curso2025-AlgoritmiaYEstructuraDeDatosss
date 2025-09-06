#include<stdio.h>
#include<math.h>

void leer(float *x, float *y, float *z){
    printf("x: "); scanf("%f",x);
    printf("y: "); scanf("%f",y);
    printf("z: "); scanf("%f",z);
}

float distancia(float *x1, float* y1, float *z1, float *x2, float* y2, float* z2){
    float d = sqrt(pow(*x1-*x2,2)+pow(*y1-*y2,2)+pow(*z1-*z2,2));
    return d;
}

int main(void){
    float x1,y1,z1;
    float x2,y2,z2;
    printf("*Para el primer punto*\n");
    leer(&x1,&y1,&z1);
    printf("*Para el segundo punto*\n");
    leer(&x2,&y2,&z2);

    float dist = distancia(&x1,&y1,&z1,&x2,&y2,&z2);
    printf("\nLa distancia dentre los puntos (%.1f,%.1f,%.1f) y (%.1f,%.1f,%.1f) es %.2f",x1,y1,z1,x2,y2,z2,dist);
    
    return 0;
}

