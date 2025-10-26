#include<stdio.h>
#include<string.h>
#include<conio.h>
int copiar_carac(char* c1, char* c2, int s, int l){
    int i=0;
    while(c1[s+i]!=' ' &&(s+i)<l){
        c2[i]=c1[s+i];
        i++;
    }
    c2[i]='\0';
    return i;    
}
int main(){
    char cadena[30];
    char caracter;
    int i=0;
    while(i<30){
        caracter=getch();
        if (caracter == '\r' || caracter == '\n') {
            break; 
        }
        cadena[i] = caracter;
        i++;
    }
    printf("\n");
    char palabra[30];
    int l=strlen(cadena);

    int s=0;
    while(s<l){
        int long_copiada=copiar_carac(cadena,palabra,s,l);
        if (long_copiada > 0) {
            printf("%s\n", palabra);
        }
        s+=long_copiada;

        while(s < l && cadena[s] == ' ') {
            s++;
        }
    }
    return 0;
}