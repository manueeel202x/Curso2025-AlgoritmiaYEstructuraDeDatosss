#include<stdio.h>
int raices(int a, int b, int c){
    int naturaleza;
    int disc = b*b-4*a*c;
    
    if(disc>0)
        naturaleza=1;
    else if(disc==0)
        naturaleza=0;
    else
        naturaleza=-1;
    
    return naturaleza;
}
int main(void){
    int a,b,c;
    for(int i=1; i<=7; i++){
        for(int j=7; j>=1; j--){
            printf("a:%d b:%d c:%d\n",a,b,c);
            b=i; c=j; a=b-c;
            if(a!=0){
                if(raices(a,b,c)>0)
                    printf(("La ecuacion tiene raices reales y diferentes"));
                else if(raices(a,b,c)==0)
                    printf("La ecuacion tiene raiz unica");
                else    
                    printf("La ecuacion tiene raices complejas");
            }
            else
                printf("La ecuacion no es cuadratica, es lineal");
            printf("\n\n");
        }
    }
    return 0;
}