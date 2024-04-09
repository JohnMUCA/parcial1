#ifndef ACCIONES_ESTRUCTURAS_H
#define ACCIONES_ESTRUCTURAS_H

#include <iostream>
#include <generacion_estructuras.h>

using namespace std;

unsigned short** alinearmatriz(unsigned short n1, unsigned short n2, unsigned short rotaciones);
void rotacionAntiHorario(unsigned short** matrix, int N, int rotaciones);

#endif // ACCIONES_ESTRUCTURAS_H
