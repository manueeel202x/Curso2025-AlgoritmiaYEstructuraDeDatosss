#include<stdio.h>
#include<string.h>

char*unidades[]={"","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
char*especiales[]={"diez","once","doce","trece","catorce","quince","dieciseis","diecisiete","dieciocho","diecinueve"};
char*decenas[]={"","","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
char*centenas[]={"","ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};
char*miles[]={"","mil","millones"};

void leerNumero(long numero);
void leerGrupo(int grupo);

int main(){
    long numero;
    printf("Ingrese un numero de hasta 9 digitos: ");
    scanf("%ld",&numero);

    if(numero==0){
        printf("cero\n");
        return 0;
    }

    leerNumero(numero);
    return 0;
}

void leerNumero(long numero){
    int grupo[3]={0};
    int i=0;

    if(numero>999999999){
        printf("Numero fuera de rango.\n");
        return;
    }

    if(numero<0){
        printf("negativo ");
        numero=-numero;
    }

    if(numero>=1000000){
        grupo[2]=numero/1000000;
        leerGrupo(grupo[2]);
        printf("millones ");
        numero%=1000000;
    }

    if(numero>=1000){
        grupo[1]=numero/1000;
        if(grupo[1]!=1){
            leerGrupo(grupo[1]);
        }
        printf("mil ");
        numero%=1000;
    }
    
    grupo[0]=numero;
    if(grupo[0]!=0){
        leerGrupo(grupo[0]);
    }
}

void leerGrupo(int grupo){
    if(grupo>=100){
        int c=grupo/100;
        if(c==1 && grupo!=100){
            printf("cien ");
        }else{
            printf("%s ",centenas[c]);
        }
        grupo%=100;
    }

    if(grupo>=20||(grupo>1&&grupo<10)){
        int d=grupo/10;
        int u=grupo%10;
        printf("%s",decenas[d]);
        if(u!=0){
            printf(" y ");
            printf("%s",unidades[u]);
        }
    }else if(grupo>=10){
        printf("%s",especiales[grupo-10]);
    }else if(grupo>0){
        printf("%s",unidades[grupo]);
    }
}