#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 100
#define CODIGO_LONGITUD 7

typedef struct {
    char codigo[CODIGO_LONGITUD + 1];
    char telefono[11];
} RegistroPersona;

RegistroPersona base_datos[MAX_REGISTROS] = {
    {"94483*5", "5551234567"},
    {"22222*2", "5552222222"},
    {"77777*7", "5557777777"},
    {"94483*5", "5551111111"},
    {"66666*6", "5556666666"}
};

int total_registros = 5;

int main() {
    char codigo_ingresado[CODIGO_LONGITUD + 1];
    int i, coincidencias = 0;
    char telefono_encontrado[11] = "";

    scanf("%s", codigo_ingresado);

    for (i = 0; i < total_registros; i++) {
        if (strcmp(base_datos[i].codigo, codigo_ingresado) == 0) {
            coincidencias++;
            if (coincidencias == 1) {
                strcpy(telefono_encontrado, base_datos[i].telefono);
            }
        }
    }

    if (coincidencias == 1) {
        printf("%s\n", telefono_encontrado);
    }

    return 0;
}