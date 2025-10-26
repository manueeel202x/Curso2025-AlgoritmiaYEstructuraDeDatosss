#include <stdio.h>

void leer_numeros(int *n1, int *n2, int *n3)
{
    scanf("%d", n1);
    scanf("%d", n2);
    scanf("%d", n3);
}

int obtener_mayor(int a, int b, int c)
{
    int mayor = a;
    if (b > mayor)
    {
        mayor = b;
    }
    if (c > mayor)
    {
        mayor = c;
    }
    return mayor;
}

void imprimir_mayor(int mayor)
{
    printf("%d\n", mayor);
}

void problema4()
{
    int num1, num2, num3, resultado;

    leer_numeros(&num1, &num2, &num3);

    resultado = obtener_mayor(num1, num2, num3);

    imprimir_mayor(resultado);
}


int main(){
    problema4();
    return 0;
}
