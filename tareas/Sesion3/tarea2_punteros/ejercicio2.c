#include<stdio.h>
#include<string.h>
int copiar_carac(char* c1, char* c2, int x){
    int i=0;
    while(c1[i]!=' ' &&i<x-1){
        c2[i]=c1[i];
        i++;
    }
    return i;    
}
int main(){
    char cadena[100];
    printf("Escriba una frase: ");
    fgets(cadena,sizeof(cadena),stdin);

    char copia[100];
    int l = strlen(cadena);    
    printf("%d",copiar_carac(cadena,copia,l));

    return 0;
}