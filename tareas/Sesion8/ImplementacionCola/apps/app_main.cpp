#include "cola_array_int.h"

int main() {
    ColaArrayInt Q(4);
    Q.push(10); Q.push(20); Q.push(30);
    Q.imprimir();

    Q.pop(); Q.imprimir();
    Q.push(40); Q.push(50); 
    Q.imprimir();


    return 0;
}
