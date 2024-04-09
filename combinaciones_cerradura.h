#ifndef COMBINACIONES_CERRADURA_H
#define COMBINACIONES_CERRADURA_H

#include <iostream>
#include <generacion_estructuras.h>
#include <acciones_estructuras.h>

using namespace std;

unsigned short*** crearCerraduraX(int* K, unsigned short N, unsigned short* x, unsigned short* R);
unsigned short hallar_DimensionPrimeraM(int *K);
bool compararValores(unsigned short** matriz1, unsigned short** matriz2, int fil, int col, int comparacion);

#endif // COMBINACIONES_CERRADURA_H
