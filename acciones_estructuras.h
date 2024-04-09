#ifndef ACCIONES_ESTRUCTURAS_H
#define ACCIONES_ESTRUCTURAS_H

#include <iostream>
#include <generacion_estructuras.h>

using namespace std;

unsigned short** devolverPunteroMatriz(int n);
void rellenarMatriz(unsigned short** p, int n);
//unsigned short** alinearmatriz(unsigned short** matriz2, unsigned short n1, unsigned short n2);
unsigned short** alinearmatriz(unsigned short** matriz2, unsigned short n1, unsigned short n2, unsigned short rotaciones);
void rotacionAntiHorario(int** matrix, int N, int rotaciones);

#endif // ACCIONES_ESTRUCTURAS_H
