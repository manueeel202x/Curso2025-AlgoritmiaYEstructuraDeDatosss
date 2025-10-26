#include <stdio.h>

char tablero[3][3];

int main(){
    int i,j,vacio_i=-1,vacio_j=-1;

    printf("Ingrese el tablero 3x3 (X,O,.):\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf(" %c",&tablero[i][j]);
        }
    }

    for(i=0;i<3;i++){
        int x=0,o=0,v=0;
        for(j=0;j<3;j++){
            if(tablero[i][j]=='X') x++;
            else if(tablero[i][j]=='O') o++;
            else{ v++; vacio_i=i; vacio_j=j; }
        }
        if(x==2 && v==1){
            printf("Jugar en (%d,%d) para ganar.\n",vacio_i,vacio_j);
            return 0;
        }
    }

    for(j=0;j<3;j++){
        int x=0,o=0,v=0;
        for(i=0;i<3;i++){
            if(tablero[i][j]=='X') x++;
            else if(tablero[i][j]=='O') o++;
            else{ v++; vacio_i=i; vacio_j=j; }
        }
        if(x==2 && v==1){
            printf("Jugar en (%d,%d) para ganar.\n",vacio_i,vacio_j);
            return 0;
        }
    }

    int x=0,o=0,v=0;
    for(i=0;i<3;i++){
        if(tablero[i][i]=='X') x++;
        else if(tablero[i][i]=='O') o++;
        else{ v++; vacio_i=i; vacio_j=i; }
    }
    if(x==2 && v==1){
        printf("Jugar en (%d,%d) para ganar.\n",vacio_i,vacio_j);
        return 0;
    }

    x=o=v=0;
    for(i=0;i<3;i++){
        if(tablero[i][2-i]=='X') x++;
        else if(tablero[i][2-i]=='O') o++;
        else{ v++; vacio_i=i; vacio_j=2-i; }
    }
    if(x==2 && v==1){
        printf("Jugar en (%d,%d) para ganar.\n",vacio_i,vacio_j);
        return 0;
    }

    for(i=0;i<3;i++){
        int xx=0,oo=0,v=0;
        for(j=0;j<3;j++){
            if(tablero[i][j]=='X') xx++;
            else if(tablero[i][j]=='O') oo++;
            else{ v++; vacio_i=i; vacio_j=j; }
        }
        if(oo==2 && v==1){
            printf("Jugar en (%d,%d) para bloquear.\n",vacio_i,vacio_j);
            return 0;
        }
    }

    for(j=0;j<3;j++){
        int xx=0,oo=0,v=0;
        for(i=0;i<3;i++){
            if(tablero[i][j]=='X') xx++;
            else if(tablero[i][j]=='O') oo++;
            else{ v++; vacio_i=i; vacio_j=j; }
        }
        if(oo==2 && v==1){
            printf("Jugar en (%d,%d) para bloquear.\n",vacio_i,vacio_j);
            return 0;
        }
    }

    int xx=0,oo=0;
    v=0;
    for(i=0;i<3;i++){
        if(tablero[i][i]=='X') xx++;
        else if(tablero[i][i]=='O') oo++;
        else{ v++; vacio_i=i; vacio_j=i; }
    }
    if(oo==2 && v==1){
        printf("Jugar en (%d,%d) para bloquear.\n",vacio_i,vacio_j);
        return 0;
    }

    xx=oo=v=0;
    for(i=0;i<3;i++){
        if(tablero[i][2-i]=='X') xx++;
        else if(tablero[i][2-i]=='O') oo++;
        else{ v++; vacio_i=i; vacio_j=2-i; }
    }
    if(oo==2 && v==1){
        printf("Jugar en (%d,%d) para bloquear.\n",vacio_i,vacio_j);
        return 0;
    }

    printf("No hay jugada inmediata para ganar o bloquear.\n");
    return 0;
}
