#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

typedef struct {
    double x;
    double y;
} Punto;

typedef struct {
    double radio;
    Punto centro;
} Circun;

// Constructores
Punto crear_punto(double x, double y);
Circun crear_circunferencia(Punto centro,  double r);


// Operaciones básicas
int verificar_pertenece(Circun c, Punto px);

#endif