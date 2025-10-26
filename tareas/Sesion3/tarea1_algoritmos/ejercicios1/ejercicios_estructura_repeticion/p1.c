#include<stdio.h>
int main(void){
    printf("TABLA DE MULTIPLICACION DE NUMERO DEL 1 AL 10\n");
    printf("--------------------------------------------\n");
    for(int i=1; i<=10; i++){
        printf("\t---Tabla del %d---\n",i);
        for(int j=1; j<=10; j++){
            printf("\t%d*%d=%d\n",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}